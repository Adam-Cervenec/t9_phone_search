#include <stdbool.h> //odstranit !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>

#define MAX_VALUE 102 // 100 char + \n + \1

void write_name_and_phone(char name[], char phone[]);
void remove_newline(char text[]);
void convert_to_t9(char text[]);
void convert_to_lowercase(char text[]);
bool is_contact_found(char text[], char filter[]);
void duplicate_array(char arrayInput[], char arrayOutput[]);
bool has_newline(char text[]);

int main(int argc, char *argv[]) {
  char name[MAX_VALUE];
  char phone[MAX_VALUE];
  if (argc == 1) {
    while (fgets(name, sizeof(name), stdin) != NULL &&
           fgets(phone, sizeof(phone), stdin) != NULL) {
      remove_newline(name);
      remove_newline(phone);
      write_name_and_phone(name, phone);
    }
    return 0;
  }
  if (argc > 2) {
    fprintf(stderr, "Invalid number of arguments");
    return 1;
  }
  if (argc == 2) {
    // Todo:
    // Validovat vstup
    // prevest na t9
    // porovnat s hledanym
    // vypsat

    for (int i = 0; argv[1][i] != '\0'; i++) {
      if (argv[1][i] < '0' || argv[1][i] > '9') {
        fprintf(stderr, "Invalid character %s", argv[1]);
        return 1;
      }
    }
    bool isFound = false;

    if (argv[1][0] == '\0') {
      fprintf(stderr, "Invalid argument\n");
      return 1;
    }
    while (fgets(name, sizeof(name), stdin) != NULL) {
      if (fgets(phone, sizeof(phone), stdin) == NULL) {
        fprintf(stderr, "Name doesnt have coresponding phone in the list");
        return 1;
      }
      if (!has_newline(name)) {
        fprintf(stderr, "Too long name");
        return 1;
      }
      if (!has_newline(phone)) {
        fprintf(stderr, "Too long phone");
        return 1;
      }
      char convertedName[MAX_VALUE];
      char convertedPhone[MAX_VALUE];
      duplicate_array(name, convertedName);
      duplicate_array(phone, convertedPhone);
      convert_to_lowercase(convertedName);
      convert_to_t9(convertedName);
      convert_to_t9(convertedPhone);
      if (is_contact_found(convertedName, argv[1]) ||
          is_contact_found(convertedPhone, argv[1])) {
        isFound = true;
        remove_newline(name);
        remove_newline(phone);
        write_name_and_phone(name, phone);
      }
    }
    if (!isFound) {
      printf("Not found\n");
      return 0;
    }
  }
  return 0;
}

bool is_contact_found(char text[], char filter[]) {
  int i = 0;
  int j;

  while (text[i] != '\0') {
    j = 0;
    while (filter[j] != '\0' && text[i + j] == filter[j]) {
      j++;
    }

    if (filter[j] == '\0') {
      return true;
    }
    i++;
  }
  return false;
}

bool has_newline(char text[]) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == '\n') {
      return true;
    }
  }
  return false;
}

void write_name_and_phone(char name[], char phone[]) {
  printf("%s, %s\n", name, phone);
}

void remove_newline(char text[]) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == '\n') {
      text[i] = '\0';
      return;
    }
  }
}

void convert_to_lowercase(char text[]) {
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = text[i] - 'A' + 'a';
    }
  }
}

void duplicate_array(char arrayInput[], char arrayOutput[]) {
  int i = 0;
  while (arrayInput[i] != '\0') {
    arrayOutput[i] = arrayInput[i];
    i++;
  }

  arrayOutput[i] = '\0';
}
void convert_to_t9(char text[]) {
  for (int i = 0; text[i] != '\0'; i++) {
    switch (text[i]) {
      // case ' ':
      //  text[i] = '1';
      //  break;

    case 'a':
    case 'b':
    case 'c':
      text[i] = '2';
      break;

    case 'd':
    case 'e':
    case 'f':
      text[i] = '3';
      break;

    case 'g':
    case 'h':
    case 'i':
      text[i] = '4';
      break;

    case 'j':
    case 'k':
    case 'l':
      text[i] = '5';
      break;

    case 'm':
    case 'n':
    case 'o':
      text[i] = '6';
      break;

    case 'p':
    case 'q':
    case 'r':
    case 's':
      text[i] = '7';
      break;

    case 't':
    case 'u':
    case 'v':
      text[i] = '8';
      break;

    case 'w':
    case 'x':
    case 'y':
    case 'z':
      text[i] = '9';
      break;

    case '+':
      text[i] = '0';
      break;

    default:
      break;
    }
  }
}
