//
// Created by Evan Smith on 11/9/2019.
//

#include <iostream>
#include "buffer.h"

buffer_item circular_buffer[BUFFER_SIZE];
int write_position = 0;
int read_position = 0;
int buffer_count = 0;

int buffer::insert_item(buffer_item item) {
    if (buffer_count < BUFFER_SIZE) {
        circular_buffer[write_position] = item;
        write_position = (write_position + 1) % BUFFER_SIZE; //wrap
        ++buffer_count;
        return 0;
    } else {
        return -1;
    }
}

int buffer::remove_item(buffer_item *item) {
    if (buffer_count > 0) {
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
    std::cout << "The current content of the buffer is [";
    int j = 0;
    for (int i = read_position; j < buffer_count; i = (i + 1) % BUFFER_SIZE, j++) {
        if (j == buffer_count - 1) {
            std::cout << circular_buffer[i] << "";
            break;
        } else {
            std::cout << circular_buffer[i] << ", ";
        }
    }
    std::cout << "] \n";
}
