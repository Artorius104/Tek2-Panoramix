/*
** EPITECH PROJECT, 2022
** temp_panoramix
** File description:
** main
*/

#include "../include/panoramix.h"

void help()
{
    printf("USAGE: ");
    printf("./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n");
}

int main(int ac, char const *av[])
{
    t_data data;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' 
        && av[1][2] == '\0') {
        help();
        return SUCCESS;
    }
    if (checkInput(ac, av) == ERROR) {
        help();
        return ERROR;
    }
    getData(&data, av);
    engine(&data);
    return SUCCESS;
}