#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// @leet start
static unsigned long pow10[11] = {
    1,       10,       100,       1000,       10000,       100000,
    1000000, 10000000, 100000000, 1000000000, 10000000000,
};
inline unsigned int getnthdigit(int x, int n) {
  return (x % (pow10[n]))/pow10[n-1];
}

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  unsigned int i = 1;
  // length
  unsigned int j = 1;
  int xtmp = x;
  while (xtmp/=10) {
    j+=1;
  }
  while (i < j) {
    if (getnthdigit(x, i) != getnthdigit(x,j)) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
// @leet end
