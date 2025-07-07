#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SECONDS_IN_MINUTE 60
#define SECONDS_IN_HOUR 3600
#define DEFAULT_TIMER_VALUE 30

int main(int argc, char *argv[]) {
  int sleep_time;
  if (argc == 1) {
    sleep_time = DEFAULT_TIMER_VALUE * SECONDS_IN_MINUTE;
  } else if (argc == 2) {
    sscanf(argv[1], "%d", &sleep_time);
  } else if (argc == 3) {
    int seconds;
    int minutes;
    sscanf(argv[1], "%d", &minutes);
    sscanf(argv[2], "%d", &seconds);
    sleep_time = SECONDS_IN_MINUTE * minutes + seconds;
  } else if (argc == 3) {
    int seconds;
    int minutes;
    int hours;
    sscanf(argv[1], "%d", &hours);
    sscanf(argv[2], "%d", &minutes);
    sscanf(argv[3], "%d", &seconds);
    sleep_time =
        SECONDS_IN_HOUR * hours + SECONDS_IN_MINUTE * minutes + seconds;
  } else {
    exit(-1);
  }

  for (int i = 0, step = sleep_time / 10; i < sleep_time; i += step) {
    sleep(step);
    float percentage = (float)i / sleep_time * 100;
    printf("%.0f%% \n", percentage);
  }
  int status = system("play /usr/share/sounds/freedesktop/stereo/complete.oga");
  return status;
}
