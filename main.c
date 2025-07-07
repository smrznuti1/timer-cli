#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sleep_time = 0;
  if (argc == 1) {
    sleep_time = 60;
  } else if (argc == 2) {
    sscanf(argv[1], "%d", &sleep_time);
  } else if (argc == 3) {
    int seconds;
    int minutes;
    sscanf(argv[1], "%d", &minutes);
    sscanf(argv[2], "%d", &seconds);
    sleep_time = 60 * minutes + seconds;
  } else if (argc == 3) {
    int seconds;
    int minutes;
    int hours;
    sscanf(argv[1], "%d", &hours);
    sscanf(argv[2], "%d", &minutes);
    sscanf(argv[3], "%d", &seconds);
    sleep_time = 3600 * hours + 60 * minutes + seconds;
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
