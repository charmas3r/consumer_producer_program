//
// Created by Evan Smith on 11/9/2019.
//

#ifndef ASSIGNMENT4_BUFFER_H
#define ASSIGNMENT4_BUFFER_H

#define BUFFER_SIZE 5
typedef int buffer_item;

class buffer {
public:
    int insert_item(buffer_item item);

    int remove_item(buffer_item *item);

    void display_buffer();
};

#endif //ASSIGNMENT4_BUFFER_H
