//
// Created by Evan Smith on 11/9/2019.
//

#include <iostream>
#include "buffer.h"

/* the buffer */
buffer_item circular_buffer[BUFFER_SIZE] = {};
int write_position = 0;
int read_position = 0;
int buffer_count = 0;


int buffer::insert_item(buffer_item item) {

    /* insert item into buffer

   return 0 if successful, otherwise

   return -1 indicating an error condition */

    if (buffer_count <= BUFFER_SIZE) {
        circular_buffer[write_position] = item;
        write_position = (write_position + 1) % BUFFER_SIZE; //wrap
        ++buffer_count;
        return 0;
    } else {
        return -1;
    }
}


int buffer::remove_item(buffer_item *item) {

    /* remove an object from buffer

   placing it in item

   return 0 if successful, otherwise

   return -1 indicating an error condition */

    if (buffer_count > 1) {
        // ok to remove
        *item = circular_buffer[read_position];
        read_position = (read_position + 1) % BUFFER_SIZE;
        --buffer_count;
        return 0;
    } else {
        return -1;
    }

}


void buffer::display_buffer() {
    int temp_counter = buffer_count;
    if (buffer_count > 0) {
        std::cout << "The current content of the buffer is [";
        for (buffer_item x : circular_buffer) {
            --temp_counter;
            if (temp_counter == 0) {
                std::cout << x << "]" << std::endl;
            } else {
                std::cout << x << ", ";
            }
        }
    } else {
        std::cout << "]" << std::endl;
    }
}