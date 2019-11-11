/*
main.cpp
Programmers Name: Evan Smith, Andrew Tse
Date Written: 11/8/19
Course: CS 433 Assignment 4
Summary:
Assumptions:

How To Run Program:
*/

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include "buffer.h"

using namespace std;

#define NEC_ARG_COUNT 4
#define MIN_SLEEP_DIST 1
#define MAX_SLEEP_DIST 2000
#define MIN_ITEM_DIST 1
#define MAX_ITEM_DIST 99

pthread_mutex_t mutex;
sem_t full_sem;
sem_t empty_sem;

//some tools to generate random numbers inside our threads
random_device device;
mt19937 generator(device());
uniform_int_distribution<int> sleep_dist(MIN_SLEEP_DIST, MAX_SLEEP_DIST);
uniform_int_distribution<int> item_dist(MIN_ITEM_DIST, MAX_ITEM_DIST);


void *producer(void *param) {

    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(sleep_dist(generator));
        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);
        /* generate a random number and enter critical section */
        if (buffer().insert_item(item_dist(generator)) == 1) {
            printf("PRODUCER THREAD: report error condition\n");
        } else {
            printf("\nitem %d inserted by a producer.\n", item);
            buffer().display_buffer();
        }
        /* end of critical section */
        pthread_mutex_unlock(&mutex);
        sem_post(&full_sem);
    }
}

void *consumer(void *param) {

    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(sleep_dist(generator));
        sem_wait(&full_sem);
        pthread_mutex_lock(&mutex);
        /* enter critcal section */
        if (buffer().remove_item(&item) == 1) {
            printf("CONSUMER THREAD: report error condition\n");
        } else {
            printf("\nitem %d removed by a consumer.\n", item);
            buffer().display_buffer();
        }
        /* end critical section */
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
}


int main(int argc, char **argv) {

    //beginning output
    printf("============================================================================ \n");
    printf("CS 433: Assignment 4 \n");
    printf("Authors: Evan Smith & Andrew Tse \n");
    printf("Date: 11/8/19 \n");
    printf("Course: CS 433 (Operating Systems) \n");
    printf("Description: Producer Consumer problem\n");
    printf("============================================================================ \n");
    cout << endl;

    // Checks if the user provided the correct command line inputs
    if (argc != NEC_ARG_COUNT) {
        cout << "three command-line arguments:\n";
        cout << "- how long main thread should run before sleeping (in seconds, positive integer that is nonzero)\n";
        cout << "- number of producer threads to create (positive integer or zero)\n";
        cout << "- number of consumer threads to create (positive integer or zero)\n\n";
        cout << "usage: ./assignment4 <time(s)> <#producer_threads> <#consumer_threads>\n";
    }

    //comment out when done (testing purposes)
    unsigned int main_thread_sleep_time = 1;
    unsigned int producer_thread_count = 0;
    unsigned int consumer_thread_count = 0;

    if (argc <= 1) {
        cout << "\n\n";
        cout << "Enter time: ";
        cin >> main_thread_sleep_time;
        cout << "Producer threads: ";
        cin >> producer_thread_count;
        cout << "Consumer  threads: ";
        cin >> consumer_thread_count;
    } else {
        main_thread_sleep_time = atoi(argv[1]);
        producer_thread_count = atoi(argv[2]);
        consumer_thread_count = atoi(argv[3]);
    }

    pthread_t producer_threads[producer_thread_count];
    pthread_t consumer_threads[consumer_thread_count];
    sem_init(&empty_sem, 0, BUFFER_SIZE);
    sem_init(&full_sem, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    for (pthread_t producer_thread : producer_threads) {
        pthread_create(&producer_thread, nullptr, producer, nullptr);
    }

    for (pthread_t consumer_thread : consumer_threads) {
        pthread_create(&consumer_thread, nullptr, consumer, nullptr);
    }

    sleep(main_thread_sleep_time);

    return 0;
}



