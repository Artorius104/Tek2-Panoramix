/*
** EPITECH PROJECT, 2022
** temp_panoramix
** File description:
** getArg
*/

#include "../include/panoramix.h"

t_druid initDruid(char const **av)
{
    t_druid druid;

    druid.p_content = atoi(av[2]);
    druid.p_size = atoi(av[2]);
    druid.nb_refills = atoi(av[4]);
    druid.status = SLEEPING;
    printf("Druid: I'm ready... but sleepy...\n");
    return druid;
}

t_villager *initVillagers(t_data *data)
{
    t_villager *allVlg = malloc(sizeof(t_villager) * data->nb_vlg);

    for (int i = 0; i < data->nb_vlg; i++) {
        allVlg[i].id = i;
        allVlg[i].fight = data->nb_fight;
        allVlg[i].status = INACTIVE;
        allVlg[i].druid = &data->druid;
    }
    return allVlg;
}

void getData(t_data *data, char const **av)
{
    data->nb_vlg = atoi(av[1]);
    data->nb_fight = atoi(av[3]);
    data->druid = initDruid(av);
    data->vlg = initVillagers(data);
}