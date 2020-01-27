//
// Created by Elaine Mou on 11/24/19.
//

#ifndef ADVENTOFCODE2017_DAY16_H
#define ADVENTOFCODE2017_DAY16_H

enum {
  NUM_PROGRAMS = 16,
  NUM_DANCES = 1000000000,
};

void day_16(void);

void shuffle_from_file(char programs[NUM_PROGRAMS + 1]);

void print_programs(char programs[NUM_PROGRAMS + 1], int spin);

#endif // ADVENTOFCODE2017_DAY16_H