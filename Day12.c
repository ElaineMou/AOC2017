//
// Created by Elaine Mou on 11/13/19.
//

#include "Day12.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_program(program_t *program, unsigned id) {
  program->program_id = id;
  program->connection_count = 0;
  for (int i = 0; i < MAX_CONNECTION_COUNT; i++) {
    program->connections[i] = 0;
  }
  program->visited = false;
}

int connected_nodes(program_t programs[NUM_PROGRAMS], unsigned index) {
  if (programs[index].visited) {
    return 0;
  }
  int connections = 1;
  programs[index].visited = true;
  for (int i = 0; i < programs[index].connection_count; i++) {
    connections += connected_nodes(programs, programs[index].connections[i]);
  }

  return connections;
}

void day_12(void) {
  FILE *fp;
  fp = fopen("../input.txt", "r");
  int node = 0;
  program_t programs[NUM_PROGRAMS];

  for (int i = 0; i < NUM_PROGRAMS; i++) {
    initialize_program(&programs[i], i);
  }

  fscanf(fp, "%d <-> ", &node);
  char line[1024];
  while (fgets(line, 1024, fp)) {
    const char *tok;
    for (tok = strtok(line, ", "); tok != NULL; tok = strtok(NULL, ",\n")) {
      int connection = 0;
      sscanf(tok, "%d", &connection);

      programs[node].connections[programs[node].connection_count] =
          (unsigned)connection;
      programs[node].connection_count++;
    }

    fscanf(fp, "%d <-> ", &node);
  }

  fclose(fp);

  // printf("Connected to node 0: %d\n", connected_nodes(programs, 0));

  int groups = 0;
  for (int i = 0; i < NUM_PROGRAMS; i++) {
    if (connected_nodes(programs, i) > 0) {
      groups++;
    }
  }
  printf("Groups: %d\n", groups);
}