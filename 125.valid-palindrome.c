#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// @leet start
bool isPalindrome(char* s) {
  short left = 0;
  short right = strlen(s)-1;
  while (left < right) {
    while(left < right && !isalnum((unsigned char)s[left])) {
      left++;
    } 
    while (left < right && !isalnum((unsigned char)s[right])) {
      right--;
    }
    if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}
// @leet end
