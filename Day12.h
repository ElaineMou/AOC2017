//
// Created by Elaine Mou on 11/13/19.
//

#ifndef ADVENTOFCODE2017_DAY12_H
#define ADVENTOFCODE2017_DAY12_H

#include <stdbool.h>
enum {
  MAX_CONNECTION_COUNT = 8,
  NUM_PROGRAMS = 2000,
};

typedef struct {
  unsigned program_id;
  unsigned connection_count;
  unsigned connections[MAX_CONNECTION_COUNT];
  bool visited;
} program_t;

void day_12(void);

void initialize_program(program_t *program, unsigned id);

int connected_nodes(program_t programs[NUM_PROGRAMS], unsigned index);

#endif // ADVENTOFCODE2017_DAY12_H
