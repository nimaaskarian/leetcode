#include <stdlib.h>
// @leet start
int romanToInt(char* s) {
  int out = 0;
  while (s[0]) {
    switch (s[0]) {
      case 'I':
        switch (s[1]) {
          case 'V':
            out += 4;
            s++;
          break;
          case 'X':
            out += 9;
            s++;
          break;
          default:
            out += 1;
          break;
        }
      break;
      case 'V':
        out += 5;
      break;
      case 'X':
        switch (s[1]) {
          case 'L':
            out += 40;
            s++;
          break;
          case 'C':
            out += 90;
            s++;
          break;
          default:
            out += 10;
          break;
        }
      break;
      case 'L':
        out += 50;
      break;
      case 'C':
        switch (s[1]) {
          case 'D':
            out += 400;
            s++;
          break;
          case 'M':
            out += 900;
            s++;
          break;
          default:
            out += 100;
          break;
        }
      case 'D':

        out += 500;
      break;
      case 'M':
        out += 1000;
      break;
    }
    s++;
  }
  return out;
}
// @leet end
