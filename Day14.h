//
// Created by Elaine Mou on 11/18/19.
//

#ifndef ADVENTOFCODE2017_DAY14_H
#define ADVENTOFCODE2017_DAY14_H

#include <cxxabi.h>
#include <ntsid.h>
#include <stdbool.h>

void day_14(void);

void fill_grid(bool grid[128][128], const char input[]);

int groups_in_grid(bool grid[128][128]);

void erase_group(bool grid[128][128], int x, int y);

int load_line(bool line[128], unsigned char values[16]);

void print_line(bool grid[128]);

void print_grid(bool grid[128][128]);

void knot_hash(const char input[], unsigned char output[16]);

void knot_hash_flip_in_circular_array(int array[256], int start_index,
                                      int length);

int get_bits_in_num(unsigned char value);

#endif // ADVENTOFCODE2017_DAY14_H
