//
// Created by Elaine Mou on 11/24/19.
//

#include "Day16.h"

#include <stdio.h>
#include <string.h>
void day_16() {
  char programs[NUM_PROGRAMS + 1];
  for (int i = 0; i < NUM_PROGRAMS; i++) {
    programs[i] = 'a' + i;
  }
  programs[NUM_PROGRAMS] = '\0';
  char original[NUM_PROGRAMS + 1];
  memcpy(original, programs, sizeof(original));
  int shuffles = 0;

  do {
    shuffle_from_file(programs);
    shuffles++;
  } while (strcmp(original, programs) != 0);

  printf("Shuffles: %d\n", shuffles);
  const int remainder = NUM_DANCES % shuffles;
  printf("Remainder: %d\n", remainder);
  for (int i = 0; i < remainder; i++) {
    shuffle_from_file(original);
  }
  print_programs(original, 0);
}

void shuffle_from_file(char programs[NUM_PROGRAMS + 1]) {
  FILE *fp;
  fp = fopen("../input.txt", "r");
  char next_command;
  int swap_A;
  int swap_B;
  char partner_A;
  char partner_B;
  char tmp;
  int index_A;
  int index_B;
  int spin = 0;
  int unspun_A;
  int unspun_B;
  int offset = 0;

  while (!feof(fp)) {
    fscanf(fp, "%c", &next_command);
    switch (next_command) {
    case 'x':
      fscanf(fp, "%d/%d,", &swap_A, &swap_B);
      unspun_A = (swap_A + NUM_PROGRAMS - offset) % NUM_PROGRAMS;
      unspun_B = (swap_B + NUM_PROGRAMS - offset) % NUM_PROGRAMS;
      tmp = programs[unspun_A];
      programs[unspun_A] = programs[unspun_B];
      programs[unspun_B] = tmp;
      break;
    case 'p':
      fscanf(fp, "%c/%c,", &partner_A, &partner_B);
      for (int i = 0; i < NUM_PROGRAMS; i++) {
        if (programs[i] == partner_A) {
          index_A = i;
        }
        if (programs[i] == partner_B) {
          index_B = i;
        }
      }
      programs[index_A] = partner_B;
      programs[index_B] = partner_A;
      break;
    case 's':
      fscanf(fp, "%d,", &spin);
      offset += spin;
      offset %= NUM_PROGRAMS;
      break;
    }
  }
  fclose(fp);

  print_programs(programs, 0);
}

void print_programs(char programs[NUM_PROGRAMS + 1], int spin) {
  for (int i = 0; i < NUM_PROGRAMS; i++) {
    const int index = (i + NUM_PROGRAMS - spin) % NUM_PROGRAMS;
    printf("%c", programs[index]);
  }
  printf("\n");
}