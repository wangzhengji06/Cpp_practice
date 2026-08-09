#include "student.h"
#include <stdio.h>

static void print_menu(void) {
  printf("1. Add student\n2. List students\n3. Find student\n4. Delete "
         "student\n5. Modify student\n0. Exit\n");
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
