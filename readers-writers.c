#define _XOPEN_SOURCE 700

#include "src/var.h"
#include "src/wstarv/wstarv.h"
#include "src/rstarv/rstarv.h"
#include "src/exclude/exclude.h"



int main(int argc, char** argv){

    start_time = time(NULL);

    que.readers = readers_num = atoi(argv[1]);
    que.writers = writers_num = atoi(argv[2]);

    pthread_t readers_thr_id[readers_num];
    pthread_t writers_thr_id[writers_num];

    threads_last_entry = calloc(readers_num + writers_num, sizeof(time_t));
    threads_max_wait_time = calloc(readers_num + writers_num, sizeof(time_t));

    struct sigaction *act = calloc(1, sizeof(struct sigaction));
    act->sa_sigaction = signalHandler;

    sigaction(SIGINT, act, NULL);

    srand(time(NULL));

    printStatus(0); // Wypisanie poczatkowego stanu

    for(int i = 0; i < readers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i;

        pthread_create(&(readers_thr_id[i]), NULL, reader, id);

        threads_last_entry[*id] = time(NULL);
    }

    for(int i = 0; i < writers_num; i++){
        int *id = calloc(1, sizeof(int));
        *id = i + readers_num;

        threads_last_entry[*id] = time(NULL);

        pthread_create(&(writers_thr_id[i]), NULL, writer, id);
    }


    for(int i = 0; i < readers_num; i++){
        pthread_join(readers_thr_id[i], NULL);
    }
    for(int i = 0; i < writers_num; i++){
        pthread_join(writers_thr_id[i], NULL);
    }


    return 0;
}