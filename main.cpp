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

    return 0;
}
