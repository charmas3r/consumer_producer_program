//
// Created by User on 11/9/2019.
//

#ifndef ASSIGNMENT4_BUFFER_H
#define ASSIGNMENT4_BUFFER_H

typedef int buffer_item;
#define BUFFER_SIZE 5

class buffer {
public:
    int insert_item(buffer_item item);
    int remove_item(buffer_item *item);
};


#endif //ASSIGNMENT4_BUFFER_H
