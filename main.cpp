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
#include "buffer.h"
using namespace std;


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
        cout << "- amount of time to run the program (in seconds, positive integer that is nonzero)\n";
        cout << "- number of producer threads to create (positive integer or zero)\n";
        cout << "- number of consumer threads to create (positive integer or zero)\n";
    }


    /* 1. Get command line arguments argv[1],argv[2],argv[3] */

    /* 2. Initialize buffer */

    /* 3. Create producer thread(s) */

    /* 4. Create consumer thread(s) */

    /* 5. Sleep */

    /* 6. Exit */

    return 0;
}


void *producer(void *param) {

    buffer_item item;

    while (true) {
        /* sleep for a random period of time */

        sleep(...);

        /* generate a random number */

        item = rand();

        if (buffer().insert_item(item)) {
            printf("report error condition");
        } else {
            printf("producer produced %d\n", item);
        }

    }
}

void *consumer(void *param) {

    buffer_item item;

    while (true) {

        /* sleep for a random period of time */

        sleep(...);

        if (buffer().remove_item(&item)) {
            fprintf("report error condition");
        } else {
            printf("consumer consumed %d\n",item);
        }
    }

}
