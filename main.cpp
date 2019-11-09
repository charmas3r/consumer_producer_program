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
#include <sys/wait.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <pthread.h>
#include <semaphore.h>
#include <algorithm>
#include "buffer.h"
using namespace std;


pthread_mutex_t mutex;
sem_t full;
sem_t empty;


void *producer(void *param) {

//    buffer_item item;
//
//    while (true) {
//        /* sleep for a random period of time */
//
////        sleep();
//
//        /* generate a random number */
//
//        item = rand();
//
//        if (buffer().insert_item(item)) {
//            printf("report error condition");
//        } else {
//            printf("producer produced %d\n", item);
//            break;
//        }
//
//    }
}

void *consumer(void *param) {
//
//    buffer_item item;
//
//    while (true) {
//
//        /* sleep for a random period of time */
//
////        sleep(...);
//
//        if (buffer().remove_item(&item)) {
//            printf("report error condition");
//        } else {
//            printf("consumer consumed %d\n",item);
//            break; //delete
//        }
//    }

}



int main(int argc, char** argv) {

    //begining output
    printf("============================================================================ \n");
    printf("CS 433: Assignment 4 \n");
    printf("Authors: Evan Smith & Andrew Tse \n");
    printf("Date: 11/8/19 \n");
    printf("Course: CS 433 (Operating Systems) \n");
    printf("Description: Producer Consumer problem\n");
    printf("============================================================================ \n");
    cout << endl;

    // Checks if the user provided the correct command line inputs
    if(argc <= 3 || argc >5)
    {
        cout << "three command-line arguments:\n";
        cout << "- how long main thread should run before sleeping (in seconds, positive integer that is nonzero)\n";
        cout << "- number of producer threads to create (positive integer or zero)\n";
        cout << "- number of consumer threads to create (positive integer or zero)\n\n";
        cout << "usage: ./assignment4 <time(s)> <#producer_threads> <#consumer_threads>\n";
    }

    int main_thread_time;
    int producer_thread_count;
    int consumer_thread_count;

    //comment out when done (testing purposes)
    if(argc <= 1) {
        cout << "\n\n";
        cout << "Enter time: ";
        cin >> main_thread_time;
        cout << "Producer threads: ";
        cin >> producer_thread_count;
        cout << "Consumer  threads: ";
        cin >> consumer_thread_count;
    }

    /* 1. Get command line arguments argv[1],argv[2],argv[3] */

    //uncomment later
//    int main_thread_time = atoi(argv[1]);
//    int producter_thread_count = atoi(argv[2]);
//    int consumer_thread_count = atoi(argv[3]);

    /* 2. Initialization */

    pthread_t producer_threads[producer_thread_count];
    pthread_t consumer_threads[consumer_thread_count];
    sem_init(&empty, 0, BUFFER_SIZE);

    /* 3. Create producer thread(s) */

    for (pthread_t producer_thread : producer_threads) {
        pthread_create(&producer_thread, nullptr, producer, nullptr);
        cout << "produced a producer thread" << endl;
    }

    for (pthread_t consumer_thread : consumer_threads) {
        pthread_create(&consumer_thread, nullptr, consumer, nullptr);
        cout << "produced a consumer thread" << endl;
    }


    /* 4. Create consumer thread(s) */

    /* 5. Sleep */

    /* 6. Exit */

    return 0;
}



