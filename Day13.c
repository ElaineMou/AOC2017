//
// Created by Elaine Mou on 11/17/19.
//

#include "Day13.h"
#include <stdio.h>
#include <string.h>

void day_13(void) {
  FILE *fp;
  fp = fopen("../input.txt", "r");

  layer_t layers[NUM_LAYERS];
  layer_t layers_copy[NUM_LAYERS];
  for (int i = 0; i < NUM_LAYERS; i++) {
    layers[i].depth = i;
    layers[i].range = 0;
    layers[i].scanner_position = 0;
    layers[i].scanner_pos_increasing = true;
  }

  int depth;
  int range;

  while (!feof(fp)) {
    fscanf(fp, "%d : %d ", &depth, &range);
    layers[depth].range = range;
  }
  fclose(fp);

  int delay = 0;
  bool success = false;
  memcpy(layers_copy, layers, sizeof(layers_copy));

  while (!success) {
    delay++;

    // bump everything in the starting layer by 1
    for (int j = 0; j < NUM_LAYERS; j++) {
      if (layers_copy[j].range == 0) {
        continue;
      }
      if (layers_copy[j].scanner_pos_increasing) {
        layers_copy[j].scanner_position++;
        if (layers_copy[j].scanner_position == layers_copy[j].range) {
          layers_copy[j].scanner_position -= 2;
          layers_copy[j].scanner_pos_increasing = false;
        }
      } else {
        layers_copy[j].scanner_position--;
        if (layers_copy[j].scanner_position == -1) {
          layers_copy[j].scanner_position += 2;
          layers_copy[j].scanner_pos_increasing = true;
        }
      }
    }

    success = true;
    memcpy(&layers, &layers_copy, sizeof(layers));
    for (int i = 0; i < NUM_LAYERS; i++) {
      if (layers[i].range > 0 && layers[i].scanner_position == 0) {
        success = false;
        // severity += i * layers[i].range;
        break;
      }

      for (int j = i; j < NUM_LAYERS; j++) {
        if (layers[j].range == 0) {
          continue;
        }
        if (layers[j].scanner_pos_increasing) {
          layers[j].scanner_position++;
          if (layers[j].scanner_position == layers[j].range) {
            layers[j].scanner_position -= 2;
            layers[j].scanner_pos_increasing = false;
          }
        } else {
          layers[j].scanner_position--;
          if (layers[j].scanner_position == -1) {
            layers[j].scanner_position += 2;
            layers[j].scanner_pos_increasing = true;
          }
        }
      }
    }
  }
  printf("Delay: %d", delay);
}