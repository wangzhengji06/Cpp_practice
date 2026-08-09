#pragma once
#define MAX_NAME_LEN 50

typedef enum { CLASS_A, CLASS_B, CLASS_C } Class;

typedef struct {
  char id[10];
  char name[MAX_NAME_LEN];
  int age;
  float score;
  Class s_class;
} Student;

typedef struct {
  Student *data;
  int size;
  int capacity;
} StudentList;

void student_list_init(StudentList *list);

int student_list_add(StudentList *list, const Student *student);

void student_list_print(const StudentList *list);

void student_list_free(StudentList *list);

typedef int (*CompareFunc)(const Student *, const Student *);

void sort_students(Student *students, int count, CompareFunc compare);

Student *student_list_find_by_id(StudentList *list, const char *id);

int student_list_delete_by_id(StudentList *list, const char *id);

int student_list_modify_by_id(StudentList *list, const char *id,
                              const Student *new_student);

int save_to_file(const char *filename, const StudentList *list);

int load_from_file(const char *filename, StudentList *list);
