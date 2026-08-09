#include "student.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_list_init(StudentList *list) {
  list->data = (Student *)malloc(sizeof(Student));
  if (list->data == NULL) {
    raise(SIGABRT);
  }
  list->size = 0;
  list->capacity = 1;
}

int student_list_add(StudentList *list, const Student *student) {
  // if size < capacity, just add normally
  //  else, capacity * 2, then add
  if (list->size >= list->capacity) {
    Student *new_data =
        (Student *)realloc(list->data, sizeof(Student) * list->capacity * 2);

    if (new_data == NULL) {
      return -1;
    }
    list->data = new_data;
    list->capacity *= 2;
  }
  list->data[list->size] = *student;
  list->size += 1;
  return 0;
}

void student_list_print(const StudentList *list) {
  for (int i = 0; i < list->size; ++i) {
    const Student *target = &list->data[i];
    printf("id: %s, name: %s, age: %d, score: %.2f", target->id, target->name,
           target->age, target->score);
    switch (target->s_class) {
    case CLASS_A:
      printf(" class: CLASS_A\n");
      break;
    case CLASS_B:
      printf(" class: CLASS_B\n");
      break;
    case CLASS_C:
      printf(" class: CLASS_C\n");
      break;
    default:
      printf(" class Unknown, probably bug");
    }
  }
}

void student_list_free(StudentList *list) {
  free(list->data);
  list->data = NULL;
  list->size = 0;
  list->capacity = 0;
}

Student *student_list_find_by_id(StudentList *list, const char *id) {
  for (int i = 0; i < list->size; ++i) {
    if (strcmp(list->data[i].id, id) == 0) {
      return &(list->data[i]);
    }
  }
  return NULL;
}

int student_list_delete_by_id(StudentList *list, const char *id) {
  int target = -1;
  for (int i = 0; i < list->size; ++i) {
    if (strcmp(list->data[i].id, id) == 0) {
      // move everything from right of i to left.
      target = i;
      break;
    }
  }
  if (target == -1) {
    return -1;
  }
  memmove(&list->data[target], &list->data[target + 1],
          (list->size - target - 1) * sizeof(Student));

  list->size--;
  return 0;
}

int student_list_modify_by_id(StudentList *list, const char *id,
                              const Student *new_student) {
  Student *target = student_list_find_by_id(list, id);
  if (target == NULL) {
    return -1;
  }
  *target = *new_student;
  return 0;
}

int save_to_file(const char *filename, const StudentList *list) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Failed to open the file");
    return -1;
  }

  // Write the student into the file
  fwrite(&list->size, sizeof(list->size), 1, file);
  fwrite(list->data, sizeof(Student), list->size, file);

  fclose(file);
  return 0;
}

int load_from_file(const char *filename, StudentList *list) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Failed to open the file");
    return -1;
  }
  int size = 0;
  if (fread(&size, sizeof(size), 1, file) != 1) {
    fclose(file);
    return -1;
  }
  if (size > list->capacity) {
    Student *new_data = (Student *)realloc(list->data, sizeof(Student) * size);
    if (new_data == NULL) {
      fclose(file);
      return -1;
    }
    list->data = new_data;
    list->capacity = size;
  }
  if (size > 0) {
    if (fread(list->data, sizeof(Student), size, file) != (size_t)size) {
      fclose(file);
      return -1;
    }
  }
  list->size = size;
  fclose(file);
  return 0;
}
