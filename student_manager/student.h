#pragma once

#define MAX_NAME_LEN 50

typedef enum { CLASS_A, CLASS_B, CLASS_C } Class;

typedef struct {
  char id[10];
  char name[MAX_NAME_LEN];
  int age;
  float score;
  Class class;
} Student;

typedef int (*CompareFunc)(const Student *, const Student *);

void sort_students(Student *students, int count, CompareFunc compare);

int save_to_file(const char *filename, Student *students, int count);
