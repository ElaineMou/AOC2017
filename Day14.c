//
// Created by Elaine Mou on 11/18/19.
//

#include "Day14.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void day_14(void) {
  const char input[] = "vbqugkhl";
  bool grid[128][128];
  fill_grid(grid, input);

  printf("Groups: %d\n", groups_in_grid(grid));
}

int groups_in_grid(bool grid[128][128]) {
  int groups = 0;
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 128; j++) {
      if (grid[i][j]) {
        groups++;
        erase_group(grid, i, j);
      }
    }
  }
  return groups;
}

void erase_group(bool grid[128][128], int x, int y) {
  if (!grid[x][y]) {
    return;
  }
  grid[x][y] = false;

  int diffs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (int i = 0; i < 4; i++) {
    int next_x = x + diffs[i][0];
    int next_y = y + diffs[i][1];
    if (next_x >= 0 && next_x < 128 && next_y >= 0 && next_y < 128) {
      erase_group(grid, next_x, next_y);
    }
  }
}

void fill_grid(bool grid[128][128], const char input[]) {
  char next_input[100];
  unsigned char hash[16];

  int num_ones = 0;
  for (int i = 0; i < 128; i++) {
    sprintf(next_input, "%s-%d", input, i);
    knot_hash(next_input, hash);
    num_ones += load_line(grid[i], hash);
  }

  printf("Num ones: %d\n", num_ones);
  print_grid(grid);
}

void print_line(bool grid[128]) {
  for (int j = 0; j < 128; j++) {
    printf("%c", grid[j] ? '#' : '.');
  }
  printf("\n");
}

void print_grid(bool grid[128][128]) {
  for (int i = 0; i < 128; i++) {
    print_line(grid[i]);
  }
  printf("\n");
}

void knot_hash(const char input[], unsigned char output[16]) {
  int knots[256];
  for (int i = 0; i < 256; i++) {
    knots[i] = i;
  }
  int lengths[99 + 5];
  const int additional_lengths[] = {17, 31, 73, 47, 23};
  const int num_lengths = strlen(input) + 5;
  for (int i = 0; i < num_lengths - 5; i++) {
    lengths[i] = (int)input[i];
  }
  for (int i = 0; i < 5; i++) {
    lengths[num_lengths - 5 + i] = additional_lengths[i];
  }

  int current_position = 0;
  int skip_size = 0;
  for (int j = 0; j < 64; j++) {
    for (int i = 0; i < num_lengths; i++) {
      knot_hash_flip_in_circular_array(knots, current_position, lengths[i]);
      current_position += lengths[i] + skip_size;
      current_position = current_position % 256;
      skip_size++;
    }
  }

  for (int i = 0; i < 16; i++) {
    int xor_result = knots[i * 16];
    for (int j = 1; j < 16; j++) {
      xor_result ^= knots[i * 16 + j];
    }
    output[i] = (unsigned char)xor_result;
  }
}

void knot_hash_flip_in_circular_array(int array[256], int start_index,
                                      int length) {
  int left = start_index;
  int right = (start_index + length - 1) % 256;
  int temp = 0;
  int swaps = length / 2;
  for (int i = 0; i < swaps; i++) {
    temp = array[left];
    array[left] = array[right];
    array[right] = temp;

    left = (left + 1) % 256;
    right = (right == 0) ? (256 - 1) : (right - 1);
  }
}

int load_line(bool line[128], unsigned char values[16]) {
  int set_bits = 0;
  for (int i = 0; i < 16; i++) {
    unsigned char value = values[i];
    for (int j = 0; j < 8; j++) {
      if (value & 0x01) {
        line[i * 8 + 7 - j] = true;
        set_bits++;
      } else {
        line[i * 8 + 7 - j] = false;
      }
      value = value >> 1;
    }
  }
  return set_bits;
}

int get_bits_in_num(unsigned char value) {
  int set_bits = 0;
  for (int i = 0; i < 8; i++) {
    if (value & 0x01) {
      set_bits++;
    }
    value = value >> 1;
  }
  return set_bits;
}