#include "logger.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

static void print_menu(void) {
  printf("1. Add student\n"
         "2. List students\n"
         "3. Find student by ID\n"
         "4. Delete student\n"
         "5. Modify student\n"
         "6. Search by name\n"
         "7. Search by score range\n"
         "8. Sort students\n"
         "9. Statistics\n"
         "10. Import students form file\n"
         "0. Exit\n");
}

static void print_one_student(const Student *student) {
  printf("id: %s, name: %s, age: %d, score: %.2f", student->id, student->name,
         student->age, student->score);

  switch (student->s_class) {
  case CLASS_A:
    printf(", class: CLASS_A\n");
    break;
  case CLASS_B:
    printf(", class: CLASS_B\n");
    break;
  case CLASS_C:
    printf(", class: CLASS_C\n");
    break;
  default:
    printf(", class: UNKNOWN\n");
    break;
  }
}

static void print_students_array(const Student *students, int count) {
  for (int i = 0; i < count; ++i) {
    print_one_student(&students[i]);
  }
}

static int input_student(Student *student) {
  printf("ID: ");
  if (scanf("%9s", student->id) != 1) {
    return -1;
  }

  printf("Name: ");
  if (scanf("%49s", student->name) != 1) {
    return -1;
  }

  printf("Age: ");
  if (scanf("%d", &student->age) != 1) {
    return -1;
  }

  printf("Score: ");
  if (scanf("%f", &student->score) != 1) {
    return -1;
  }

  int class_choice;

  printf("Class (0=A, 1=B, 2=C): ");
  if (scanf("%d", &class_choice) != 1) {
    return -1;
  }

  switch (class_choice) {
  case 0:
    student->s_class = CLASS_A;
    break;
  case 1:
    student->s_class = CLASS_B;
    break;
  case 2:
    student->s_class = CLASS_C;
    break;
  default:
    return -1;
  }

  return 0;
}

static void handle_add(StudentList *list) {
  Student student;

  if (input_student(&student) != 0) {
    printf("Invalid student information.\n");
    return;
  }

  if (student_list_add(list, &student) != 0) {
    printf("Failed to add student.\n");
    return;
  }

  printf("Student added successfully.\n");
  log_message("Student added");
}

static void handle_find(StudentList *list) {
  char id[10];

  printf("Enter student ID: ");

  if (scanf("%9s", id) != 1) {
    printf("Invalid ID.\n");
    return;
  }

  Student *student = student_list_find_by_id(list, id);

  if (student == NULL) {
    printf("Student not found.\n");
    return;
  }

  print_one_student(student);
}

static void handle_delete(StudentList *list) {
  char id[10];

  printf("Enter student ID to delete: ");

  if (scanf("%9s", id) != 1) {
    printf("Invalid ID.\n");
    return;
  }

  if (student_list_delete_by_id(list, id) != 0) {
    printf("Student not found.\n");
    return;
  }

  printf("Student deleted successfully.\n");
  log_message("Student deleted");
}

static void handle_modify(StudentList *list) {
  char id[10];

  printf("Enter student ID to modify: ");

  if (scanf("%9s", id) != 1) {
    printf("Invalid ID.\n");
    return;
  }

  if (student_list_find_by_id(list, id) == NULL) {
    printf("Student not found.\n");
    return;
  }

  printf("Enter new student information:\n");

  Student new_student;

  if (input_student(&new_student) != 0) {
    printf("Invalid student information.\n");
    return;
  }

  if (student_list_modify_by_id(list, id, &new_student) != 0) {
    printf("Failed to modify student.\n");
    return;
  }

  printf("Student modified successfully.\n");
  log_message("Student modified");
}

static void handle_search_by_name(const StudentList *list) {
  char name[MAX_NAME_LEN];

  printf("Enter name keyword: ");

  if (scanf("%49s", name) != 1) {
    printf("Invalid name.\n");
    return;
  }

  Student *results = (Student *)malloc(sizeof(Student) * list->size);

  if (results == NULL && list->size > 0) {
    printf("Memory allocation failed.\n");
    return;
  }

  int count = student_list_find_by_name(list, name, results, list->size);

  if (count == 0) {
    printf("No students found.\n");
  } else {
    printf("Found %d student(s):\n", count);
    print_students_array(results, count);
  }

  free(results);
}

static void handle_search_by_score(const StudentList *list) {
  float min_score;
  float max_score;

  printf("Minimum score: ");
  if (scanf("%f", &min_score) != 1) {
    printf("Invalid score.\n");
    return;
  }

  printf("Maximum score: ");
  if (scanf("%f", &max_score) != 1) {
    printf("Invalid score.\n");
    return;
  }

  if (min_score > max_score) {
    printf("Minimum score cannot be greater than maximum score.\n");
    return;
  }

  Student *results = (Student *)malloc(sizeof(Student) * list->size);

  if (results == NULL && list->size > 0) {
    printf("Memory allocation failed.\n");
    return;
  }

  int count = student_list_find_by_score_range(list, min_score, max_score,
                                               results, list->size);

  if (count == 0) {
    printf("No students found.\n");
  } else {
    printf("Found %d student(s):\n", count);
    print_students_array(results, count);
  }

  free(results);
}

static void handle_sort(StudentList *list) {
  int choice;

  printf("1. Score ascending\n"
         "2. Age ascending\n"
         "0. Cancel\n"
         "Choice: ");

  if (scanf("%d", &choice) != 1) {
    printf("Invalid choice.\n");
    return;
  }

  switch (choice) {
  case 1:
    student_list_sort(list, compare_student_by_score_asc);
    printf("Sorted by score ascending.\n");
    break;

  case 2:
    student_list_sort(list, compare_student_by_age_asc);
    printf("Sorted by age ascending.\n");
    break;

  case 0:
    return;

  default:
    printf("Unknown choice.\n");
    return;
  }

  student_list_print(list);
}

static void handle_statistics(const StudentList *list) {
  if (list->size == 0) {
    printf("No students available.\n");
    return;
  }

  float average = student_list_average_score(list);

  const Student *highest = student_list_highest_score(list);

  const Student *lowest = student_list_lowest_score(list);

  printf("Average score: %.2f\n", average);

  printf("Highest score student:\n");
  print_one_student(highest);

  printf("Lowest score student:\n");
  print_one_student(lowest);
}

static void handle_import(StudentList *list) {
  char filename[256];
  printf("What will be the file name?\n");
  if (scanf("%255s", filename) != 1) {
    printf("Invalid filename.\n");
    return;
  }
  int count = student_list_import_from_file(list, filename);
  if (count == -1) {
    printf("Failed to import file.\n");
    return;
  }

  printf("Imported %d student(s).\n", count);
}

int main(void) {
  StudentList list;
  student_list_init(&list);

  load_from_file("students.dat", &list);

  int running = 1;

  while (running) {
    print_menu();

    int choice;

    printf("Choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid choice.\n");
      break;
    }

    switch (choice) {
    case 1:
      handle_add(&list);
      break;

    case 2:
      student_list_print(&list);
      break;

    case 3:
      handle_find(&list);
      break;

    case 4:
      handle_delete(&list);
      break;

    case 5:
      handle_modify(&list);
      break;

    case 6:
      handle_search_by_name(&list);
      break;

    case 7:
      handle_search_by_score(&list);
      break;

    case 8:
      handle_sort(&list);
      break;

    case 9:
      handle_statistics(&list);
      break;

    case 10:
      handle_import(&list);
      break;

    case 0:
      running = 0;
      break;

    default:
      printf("Unknown choice.\n");
      break;
    }
  }

  save_to_file("students.dat", &list);
  student_list_free(&list);

  return 0;
}
