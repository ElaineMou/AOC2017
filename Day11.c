//
// Created by Elaine Mou on 11/13/19.
//

#include "Day11.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void day_11(void) {
  FILE *fp;
  char next_word[3];
  for (int i = 0; i < 3; i++) {
    next_word[i] = '\0';
  }
  int x = 0;
  int y = 0;
  int max_distance = 0;
  fp = fopen("../input.txt", "r");

  fscanf(fp, "%[^,],", next_word);
  while (!feof(fp)) {
    printf("%s\n", next_word);
    if (strcmp(next_word, "n") == 0) {
      y += 2;
    } else if (strcmp(next_word, "ne") == 0) {
      y += 1;
      x += 1;
    } else if (strcmp(next_word, "se") == 0) {
      y -= 1;
      x += 1;
    } else if (strcmp(next_word, "s") == 0) {
      y -= 2;
    } else if (strcmp(next_word, "sw") == 0) {
      y -= 1;
      x -= 1;
    } else if (strcmp(next_word, "nw") == 0) {
      y += 1;
      x -= 1;
    }
    int current_distance = abs(x) + abs(y);
    if (current_distance > max_distance) {
      max_distance = current_distance;
    }
    fscanf(fp, "%[^,],", next_word);
  }
  printf("x, y: %d, %d\n", x, y);
  x = abs(x);
  y = abs(y);
  printf("Steps: %d\n", (x + y) / 2);
  printf("Max steps: %d\n", (max_distance / 2));

  fclose(fp);
}