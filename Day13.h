//
// Created by Elaine Mou on 11/17/19.
//

#ifndef ADVENTOFCODE2017_DAY13_H
#define ADVENTOFCODE2017_DAY13_H

#include <stdbool.h>

enum { NUM_LAYERS = 99 };

typedef struct {
  int depth;
  int range;
  int scanner_position;
  bool scanner_pos_increasing;
} layer_t;

void day_13(void);

#endif // ADVENTOFCODE2017_DAY13_H
