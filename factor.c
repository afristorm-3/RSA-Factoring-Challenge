#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: factors <file>\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  int n;
  while (fscanf(fp, "%d", &n) == 1) {
    // Check if n is divisible by 2
    if (n % 2 == 0) {
      int x = n / 2;
      printf("%d=2*%d\n", n, x);
      continue;
    }

    // Check if n is divisible by odd numbers
    for (int i = 3; i <= n; i += 2) {
      if (n % i == 0) {
        int x = n / i;
        printf("%d=%d*%d\n", n, i, x);
        break;
      }
    }
  }

  fclose(fp);
  return 0;
}

