/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-panoramix-gilbert.badiabo
** File description:
** druid
*/

#include "../include/panoramix.h"

void *druidAction(void *arg)
{
    t_druid *druid = (t_druid *)arg;

    druid->status = AWAKE;
    while (druid->nb_refills > 0) {
        sem_wait(&druid->sema);
        druid->p_content = druid->p_size;
        druid->nb_refills -= 1;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only");
        printf(" make %d more refills after this one.\n", druid->nb_refills);
    }
    druid->status = SLEEPING;
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_exit(NULL);
}