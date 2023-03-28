/*
** EPITECH PROJECT, 2022
** temp_panoramix
** File description:
** engine
*/

#include "../include/panoramix.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int getADrink(t_villager *vlg)
{
    if (vlg->status == UNREADY) {
        pthread_mutex_lock(&mutex);
        if (vlg->druid->p_content == 0) {
            printf("Villager %d: I need a drink... I see %d servings left.\n",
            vlg->id, vlg->druid->p_content);
            if (vlg->druid->nb_refills > 0) {
                printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                vlg->id);
                sem_post(&vlg->druid->sema);
                sleep(1);
            } else if (vlg->druid->nb_refills == 0 && vlg->druid->p_content == 0)
                return 1;
        } else
            printf("Villager %d: I need a drink... I see %d servings left.\n",
            vlg->id, vlg->druid->p_content);
        vlg->druid->p_content -= 1;
        pthread_mutex_unlock(&mutex);
        vlg->status = READY;
    }
    return 0;
}

void attack(t_villager *vlg)
{
    if (vlg->status == READY) {
        vlg->fight -= 1;
        printf("Villager %d: Take that roman scum! Only %d left.\n",
        vlg->id, vlg->fight);
        vlg->status = UNREADY;
    }
}

void getActive(t_villager *vlg)
{
    if (vlg->status == INACTIVE) {
        printf("Villager %d: Going into battle !\n", vlg->id);
        vlg->status = UNREADY;
        sleep(1);
    }
}

void *loop(void *arg)
{
    t_villager *vlg = (t_villager *)arg;


    while (checkThread(vlg->fight, vlg->druid) != FINISHED) {
        getActive(vlg);
        if (getADrink(vlg) == 1)
            break;
        attack(vlg);
    }
    printf("Villager %d: I'm going to sleep now.\n", vlg->id);
    free(vlg);
    pthread_exit(NULL);
}

void engine(t_data *data)
{
    pthread_t thr[data->nb_vlg + 1];
    t_villager *save;

    sem_init(&data->druid.sema, 0, 0);
    pthread_create(&thr[data->nb_vlg], NULL, druidAction, &data->druid);
    for (int i = 0; i < data->nb_vlg; i++) {
        save = malloc(sizeof(t_villager));
        *save = data->vlg[i];
        if (pthread_create(&thr[i], NULL, &loop, save) != 0)
            perror("Failed to create thread\n");
    }
    for (int i = 0; i < data->nb_vlg; i++)
        pthread_join(thr[i], NULL);
    sem_destroy(&data->druid.sema);
    pthread_mutex_destroy(&mutex);
    free(data->vlg);
}