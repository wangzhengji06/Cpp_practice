#include "logger.h"
#include <stdio.h>
#include <time.h>

int log_message(const char *message) {
  time_t now;
  time(&now);

  struct tm *time_info = localtime(&now);

  char time_buffer[64];

  strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);

  FILE *file = fopen("system.log", "a");
  if (file == NULL) {
    return -1;
  }
  fprintf(file, "[%s] %s\n", time_buffer, message);
  fclose(file);
  return 0;
}
