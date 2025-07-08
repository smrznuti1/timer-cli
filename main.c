#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define DEFAULT_TIMER_VALUE_IN_MINUTES 30

int parse_arguments2(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Too many arguments.\n");
    exit(-1);
  }

  char *time = argv[1];
  int hours = 0, minutes = 0, seconds = 0;
  printf("%s\n", time);

  while (*time) {
    int value = 0;
    while (isdigit(*time)) {
      value = value * 10 + (*time - '0');
      time++;
    }
    if (*time == 'h') {
      hours = value;
    }
    if (*time == 'm') {
      minutes = value;
    }
    if (*time == 's') {
      seconds = value;
    }
    time++;
  }

  printf("%d %d %d\n", hours, minutes, seconds);

  return hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

int parse_arguments(int argc, char *argv[]) {
  if (argc == 2) {
    int sleep_time;
    sscanf(argv[1], "%d", &sleep_time);
    return sleep_time;
  }

  if (argc == 3) {
    int seconds;
    int minutes;
    sscanf(argv[1], "%d", &minutes);
    sscanf(argv[2], "%d", &seconds);
    return SECONDS_IN_MINUTE * minutes + seconds;
  }

  if (argc == 4) {
    int seconds;
    int minutes;
    int hours;
    sscanf(argv[1], "%d", &hours);
    sscanf(argv[2], "%d", &minutes);
    sscanf(argv[3], "%d", &seconds);
    return SECONDS_IN_HOUR * hours + SECONDS_IN_MINUTE * minutes + seconds;
  }
  exit(-1);
}

int check_format(char *input) {
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == 's' || input[i] == 'm' || input[i] == 'h') {
      return 2;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int sleep_time;
  if (argc == 1) {
    sleep_time = DEFAULT_TIMER_VALUE_IN_MINUTES * SECONDS_IN_MINUTE;
  } else {
    if (check_format(argv[1]) == 2) {
      sleep_time = parse_arguments2(argc, argv);
    } else {
      sleep_time = parse_arguments(argc, argv);
    }
  }

  for (int i = 0, step = ceil((double)sleep_time / 10); i < sleep_time;
       i += step) {
    sleep(step);
    float percentage = (float)(i + step) / sleep_time * 100;
    printf("%.0f%% \n", percentage);
  }
  int status = system("play /usr/share/sounds/freedesktop/stereo/complete.oga");
  return status;
}
