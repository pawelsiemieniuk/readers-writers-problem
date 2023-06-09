#include "../var.h"


void* reader(int* id){
    int thread_id = *id;
    unsigned int reading_time;

    while(1){
        pthread_mutex_lock(&lock);
        if(!lib.writers){
            {
                que.readers--;
                lib.readers++;
                printStatus();

                logEntryTime(thread_id);
            }
            pthread_mutex_unlock(&lock);
            
            reading_time = rand() % MAX_TIME + 1;
            sleep(reading_time);
            
            pthread_mutex_lock(&lock);
            {
                lib.readers--;
                printStatus();
            }
            pthread_mutex_unlock(&lock);

            sleep(REST_TIME); 

            pthread_mutex_lock(&lock);
            {
                que.readers++;
                printStatus();
            }
            pthread_mutex_unlock(&lock);
        }
        else{
            pthread_mutex_unlock(&lock);
        }
    }
    
}