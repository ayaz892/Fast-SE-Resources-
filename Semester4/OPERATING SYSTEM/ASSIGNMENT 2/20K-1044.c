
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define Cars_Max 10

void *northsouth(void *total);

void *eastwest(void *total);

sem_t waiting;

sem_t intersection;

int main(int argc, char *argv[])

{
    
    pthread_t tidn[Cars_Max];
    pthread_t tide[Cars_Max];
    int i, wn, we, totalcars;
    
    int nown[Cars_Max];
    int nowe[Cars_Max];
    
    printf("Enter the no of cars entering from north region : ");
    scanf("%d", &wn);
    
    printf("Enter the no of cars entering from east region : ");
    scanf("%d", &we);
    
    totalcars = wn + we;
    
    if (totalcars > Cars_Max)
    {
        printf("the limit of cars exceded");
        return 0;
    }
    
    printf("A solution to traffic intersection problem using semaphores \n");
    
    for (i = 0; i < wn; i++)
    {
        nown[i] = i;
    }
    
    for (i = 0; i < we; i++)
    {
        nowe[i] = i;
    }
    
    sem_init(&waiting, 1, totalcars);
    sem_init(&intersection, 1, 3);
    
    for (i = 0; i < wn; i++)
    {
        pthread_create(&tidn[i], NULL, northsouth, (void *)&nown[i]);
    }
    
    for (i = 0; i < we; i++)
    {
        pthread_create(&tide[i], NULL, eastwest, (void *)&nowe[i]);
    }
    
    for (i = 0; i < wn; i++)
    {
        pthread_join(tidn[i], NULL);
    }

    for (i = 0; i < we; i++)
    {
        pthread_join(tide[i], NULL);
    }
    
    printf("Area has been cleared \n");
    return 0;
}

void *northsouth(void *no)
{
    int total = *(int *)no;
    printf("Car %d from north leaving from home \n", total + 1);
    
    sem_wait(&waiting);
    int n;
    
    n = rand() % 10;
    sleep(n);
    
    printf("Car %d from north approached intersection area at teen talwar\n", total + 1);
    sem_wait(&intersection);
    
    sem_post(&waiting);
    printf("Car %d from north entered intersection area at teen talwar \n", total + 1);
    
    sem_post(&intersection);
    
    printf("Car %d has exited towards south \n", total + 1);
}

void *eastwest(void *no)
{
    int total = *(int *)no;
    printf("Car %d from east leaving from home \n", total + 1);
    
    sem_wait(&waiting);
    
    int k;
    
    k = rand() % 10;
    
    sleep(k);
    
    printf("Car %d from east approached intersection area at teen talwar \n", total + 1);
    
    sem_wait(&intersection);
    
    sem_post(&waiting);
    
    printf("Car %d from east entered intersection area at teen talwar \n", total + 1);
    
    sem_post(&intersection);
    
    printf("Car %d has exited towards west \n", total + 1);
    
    
}
