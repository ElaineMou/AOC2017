#include "Day10.h"
#include <stdio.h>

void day_10(void) {
  FILE *fp;
  char next_char = 0;
  fp = fopen("../input.txt", "r");

  int current_position = 0;
  int skip_size = 0;
  int knots[ARRAY_SIZE];
  int lengths[MAX_LENGTHS_COUNT];
  const int additional_lengths[] = {17, 31, 73, 47, 23};
  int lengths_count = 0;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    knots[i] = i;
  }
  fscanf(fp, "%c", &next_char);
  while (!feof(fp)) {
    lengths[lengths_count++] = (int)next_char;
    fscanf(fp, "%c", &next_char);
  }
  for (int i = 0; i < 5; i++) {
    lengths[lengths_count++] = additional_lengths[i];
  }

  for (int j = 0; j < NUM_ROUNDS; j++) {
    for (int i = 0; i < lengths_count; i++) {
      flip_in_circular_array(knots, current_position, lengths[i]);
      current_position += lengths[i] + skip_size;
      current_position = current_position % ARRAY_SIZE;
      skip_size++;
    }
  }

  print_array(knots);

  int dense_hash[16];
  for (int i = 0; i < 16; i++) {
    int xor_result = knots[i * 16];
    for (int j = 1; j < 16; j++) {
      xor_result ^= knots[i * 16 + j];
    }
    dense_hash[i] = xor_result;
  }
  for (int i = 0; i < 16; i++) {
    printf("%d ", dense_hash[i]);
  }
  printf("\n");
  for (int i = 0; i < 16; i++) {
    printf("%02x", dense_hash[i]);
  }

  fclose(fp);
}

void print_array(int array[ARRAY_SIZE]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void flip_in_circular_array(int array[ARRAY_SIZE], int start_index,
                            int length) {
  int left = start_index;
  int right = (start_index + length - 1) % ARRAY_SIZE;
  int temp = 0;
  int swaps = length / 2;
  for (int i = 0; i < swaps; i++) {
    temp = array[left];
    array[left] = array[right];
    array[right] = temp;

    left = (left + 1) % ARRAY_SIZE;
    right = (right == 0) ? (ARRAY_SIZE - 1) : (right - 1);
  }
}