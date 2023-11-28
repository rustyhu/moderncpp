#include <stdio.h>
#include <stdlib.h>

int countlines(const char *filename) {
  // count the number of lines in the file called filename
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) return 0;

  // take care of `feof()`!
  // https://stackoverflow.com/questions/5431941/why-is-while-feof-file-always-wrong
  int ch = 0;
  int lines = 1;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') lines++;

    if ((ch = ferror(fp))) {
      printf("File read error! ret: %d\n", ch);
    }
  }

  fclose(fp);
  return lines;
}

int main(int argc, char *argv[]) { printf("LINES: %d\n", countlines("oop.c")); }
