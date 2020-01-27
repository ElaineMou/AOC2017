#ifndef ADVENTOFCODE2017_LIBRARY_H
#define ADVENTOFCODE2017_LIBRARY_H

enum {
  ARRAY_SIZE = 256,
  MAX_LENGTHS_COUNT = 100,
  NUM_ROUNDS = 64,
};

void day_10(void);

void print_array(int array[ARRAY_SIZE]);

void flip_in_circular_array(int array[ARRAY_SIZE], int start_index, int length);

#endif