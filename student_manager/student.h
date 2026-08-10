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

Student *student_list_find_by_id(StudentList *list, const char *id);

int student_list_delete_by_id(StudentList *list, const char *id);

int student_list_modify_by_id(StudentList *list, const char *id,
                              const Student *new_student);

int save_to_file(const char *filename, const StudentList *list);

int load_from_file(const char *filename, StudentList *list);

int student_list_contains_id(const StudentList *list, const char *id);

int student_is_valid(const Student *student);

int student_list_find_by_name(const StudentList *list, const char *name,
                              Student *results, int max_results);

int student_list_find_by_score_range(const StudentList *list, float min_score,
                                     float max_score, Student *results,
                                     int max_results);

typedef int (*CompareFunc)(const Student *a, const Student *b);

int compare_student_by_score_asc(const Student *a, const Student *b);

int compare_student_by_age_asc(const Student *a, const Student *b);

void student_list_sort(StudentList *list, CompareFunc compare);

float student_list_average_score(const StudentList *list);

const Student *student_list_highest_score(const StudentList *list);

const Student *student_list_lowest_score(const StudentList *list);
