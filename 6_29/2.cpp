#include <stdio.h>
#include <string.h>

struct student {
  char name[20];
  int age;
};

int main() {
  student targets[]{student{"Jake", 20}, {"Tom", 15}, {"Peter", 30}};

  FILE *fp = fopen("students.dat", "w");

  if (fp == NULL) {
    perror("Failed to open the file");
    return 1;
  }

  fwrite()
}
