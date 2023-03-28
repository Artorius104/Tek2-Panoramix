/*
** EPITECH PROJECT, 2022
** temp_panoramix
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
#define PANORAMIX_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <semaphore.h>
    #include <pthread.h>

static const int ERROR = 84;
static const int FALSE = -1;
static const int SUCCESS = 0;

typedef struct s_data t_data;
typedef struct s_druid t_druid;
typedef struct s_villager t_villager;

enum VSTATUS {
    INACTIVE,
    UNREADY,
    READY,
};

enum DSTATUS {
    SLEEPING,
    AWAKE,
};

enum TSTAUS {
    INGOING,
    FINISHED,
};

struct s_villager {
    int id;
    int fight;
    int status;
    t_druid *druid;
};

struct s_druid {
    int status;
    int p_content;
    int p_size;
    int nb_refills;
    sem_t sema;
};

struct s_data {
    int nb_vlg;
    int nb_fight;
    t_druid druid;
    t_villager *vlg;
};

int checkInput(int ac, char const **av);
void getData(t_data *data, char const **av);
void engine(t_data *data);
int checkThread(int fight, t_druid *druid);
void *druidAction(void *arg);

#endif /* !PANORAMIX_H_ */
