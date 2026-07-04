#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
  FILE *fp = fopen("log.txt", "a");

  if (fp == NULL) {
    perror("Failed to open log.txt");
    return 1;
  }
  time_t now = time(NULL);

  tm *local = localtime(&now);
  char buffer[100];

  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S\n", local);

  fputs(buffer, fp);

  fclose(fp);

  return 0;

  

}
