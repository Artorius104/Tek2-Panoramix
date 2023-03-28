/*
** EPITECH PROJECT, 2022
** temp_panoramix
** File description:
** check
*/

#include "../include/panoramix.h"

int checkInput(int ac, char const **av)
{
    if (ac != 5)
        return ERROR;
    for (int i = 1; i < ac; i++) {
        if (atoi(av[i]) < 0) {
            printf("Values must be >0.\n");
            return ERROR;
        }
    }
    return SUCCESS;    
}

int checkThread(int fight, t_druid *druid)
{
    if (fight == 0)
        return FINISHED;
    if (druid->p_size == 0 && druid->status == SLEEPING)
        return FINISHED;
    return INGOING;
}