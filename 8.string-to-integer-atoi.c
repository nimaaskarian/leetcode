// #!/usr/bin/tcc -std=c23 -run
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
// @leet start
#include <stdckdint.h>
typedef int8_t i8;

int myAtoi(char* s) {
  while (s[0] == ' ') {
    s++;
  }
  i8 coefficient = 1;
  switch (s[0]) {
    case '+':
      s++;
    break;
    case '-':
      coefficient = -1;
      s++;
    break;
  }
  while (s[0] == '0') {
    s++;
  }
  if (!isdigit(s[0])) {
    return 0;
  }
  int output = 0;
  for (; s != NULL; s++) {
    if (!isdigit(s[0])) {
      break;
    }
    if (ckd_mul(&output, output, 10) || ckd_add(&output, output, coefficient * (s[0]-'0'))) {
      if (coefficient == 1) 
        return INT_MAX;
      else 
        return INT_MIN;
    }
  }
  return output;
}
// @leet end
int main(int argc, char *argv[])
{

  printf("%d\n", myAtoi("2147483648"));
  return EXIT_SUCCESS;
}
