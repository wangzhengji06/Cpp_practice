#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("example.txt", "w");

  if (fp == NULL) {
    perror("Failed to open file for writing");
    return 1;
  }

  fputs("Hello World!\n", fp);

  fclose(fp);

  fp = fopen("example.txt", "r");

  if (fp == NULL) {
    perror("Failed to open file for reading");
    return 1;
  }

  char buffer[100];

  if (fgets(buffer, 100, fp) != NULL) {
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }

    printf("The input is: ");
    fputs(buffer, stdout);
    putchar('\n');
  } else {
    if (ferror(fp)) {
      perror("Failed to read file");
    } else {
      printf("End of file reached.\n");
    }
  }
  fclose(fp);
}
