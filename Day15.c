//
// Created by Elaine Mou on 11/19/19.
//

#include "Day15.h"
#include <stdbool.h>
#include <stdio.h>

enum {
  NUM_PAIRS = 5000000,
};
void day_15(void) {
  const int64_t start_a = 873;
  const int64_t start_b = 583;
  const int64_t factor_a = 16807;
  const int64_t factor_b = 48271;
  const int64_t divisor = 2147483647;

  int64_t previous_a = start_a;
  int64_t previous_b = start_b;
  int matches = 0;
  int64_t value_a;
  int64_t value_b;
  int pairs = 0;

  while (pairs < NUM_PAIRS) {
    do {
      value_a = (previous_a * factor_a) % divisor;
      previous_a = value_a;
    } while (value_a % 4 != 0);

    do {
      value_b = (previous_b * factor_b) % divisor;
      previous_b = value_b;
    } while (value_b % 8 != 0);

    pairs++;
    int64_t a = value_a & 0xFFFF;
    int64_t b = value_b & 0xFFFF;
    if (a == b) {
      matches++;
      printf("%d -- %d\n", value_a, value_b);
    }

    // value_a &= 0xFFFF;
    // value_b &= 0xFFFF;
    // matches += value_a == value_b;
  }
  printf("Matches: %d\n", matches);
}