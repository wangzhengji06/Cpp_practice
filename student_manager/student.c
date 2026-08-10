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
  if (!student_is_valid(student) ||
      student_list_contains_id(list, student->id)) {
    return 0;
  }

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
  return 1;
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
  return 1;
}

int student_list_modify_by_id(StudentList *list, const char *id,
                              const Student *new_student) {
  Student *target = student_list_find_by_id(list, id);
  if (target == NULL) {
    return -1;
  }
  *target = *new_student;
  return 1;
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
  return 1;
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
  return 1;
}

int student_list_contains_id(const StudentList *list, const char *id) {
  for (int i = 0; i < list->size; ++i) {
    if (strcmp(list->data[i].id, id) == 0) {
      return 1;
    }
  }
  return 0;
}

int student_is_valid(const Student *student) {
  if (student->id[0] == '\0') {
    return 0;
  } else if (student->name[0] == '\0') {
    return 0;
  } else if (student->age < 1 || student->age > 120) {
    return 0;
  } else if (student->score < 0 || student->score > 100) {
    return 0;
  } else if (student->s_class != CLASS_A && student->s_class != CLASS_B &&
             student->s_class != CLASS_C) {
    return 0;
  } else {
    return 1;
  }
}

int student_list_find_by_name(const StudentList *list, const char *name,
                              Student *results, int max_results) {
  int count = 0;
  for (int i = 0; i < list->size; ++i) {
    if (strstr(list->data[i].name, name) != NULL) {
      if (count < max_results) {
        results[count] = list->data[i];
        count++;
      } else {
        return count;
      }
    }
  }
  return count;
}

int student_list_find_by_score_range(const StudentList *list, float min_score,
                                     float max_score, Student *results,
                                     int max_results) {
  int count = 0;
  for (int i = 0; i < list->size; ++i) {
    if (list->data[i].score <= max_score && list->data[i].score >= min_score) {
      if (count < max_results) {
        results[count] = list->data[i];
        count++;
      } else {
        return count;
      }
    }
  }
  return count;
}

int compare_student_by_score_asc(const Student *a, const Student *b) {
  if (a->score < b->score) {
    return -1;
  } else if (a->score > b->score) {
    return 1;
  } else {
    return 0;
  }
}

int compare_student_by_age_asc(const Student *a, const Student *b) {
  if (a->age < b->age) {
    return -1;
  } else if (a->age > b->age) {
    return 1;
  } else {
    return 0;
  }
}

void student_list_sort(StudentList *list, CompareFunc compare) {
  // I will just use Bubble Sort
  // iterate through every student in list->data, from 0 to i - 1 as always
  for (int i = list->size - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (compare(&(list->data[j]), &(list->data[j + 1])) > 0) {
        Student temp = list->data[j];
        list->data[j] = list->data[j + 1];
        list->data[j + 1] = temp;
      }
    }
  }
}

float student_list_average_score(const StudentList *list) {
  float average = 0.0f;
  if (list->size == 0) {
    return 0.0f;
  }
  for (int i = 0; i < list->size; ++i) {
    average += list->data[i].score;
  }
  return average / list->size;
}

const Student *student_list_highest_score(const StudentList *list) {
  const Student *ptr;
  float max;
  if (list->size == 0) {
    return NULL;
  } else {
    max = list->data[0].score;
    ptr = &list->data[0];
  }
  for (int i = 1; i < list->size; ++i) {
    if (max < list->data[i].score) {
      max = list->data[i].score;
      ptr = &list->data[i];
    }
  }
  return ptr;
}

const Student *student_list_lowest_score(const StudentList *list) {
  const Student *ptr;
  float min;
  if (list->size == 0) {
    return NULL;
  } else {
    min = list->data[0].score;
    ptr = &list->data[0];
  }
  for (int i = 1; i < list->size; ++i) {
    if (min > list->data[i].score) {
      min = list->data[i].score;
      ptr = &list->data[i];
    }
  }
  return ptr;
}
