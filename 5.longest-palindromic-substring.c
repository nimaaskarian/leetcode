#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
// @leet start
char* longestPalindrome(char* s) {
  char* head = s;
  char* tail = s;
  while (tail[1] != '\0') {
    tail++;
  }
  char* current_tail = tail;
  char* current_head = head;
  while (current_head < current_tail) {
    while (current_head[0] != current_tail[0]) {
      current_tail--;
    }
    printf("current_head[0] = %c\n", current_head[0]);
    printf("current_tail[0] = %c\n", current_tail[0]);
    printf("current_head (%p), current_tail (%p)\n", current_head, current_tail);
    if (current_head == current_tail) {
      current_tail = tail;
      current_head++;
    } else {
      char* tmp_head = current_head;
      char* tmp_tail = current_tail;
      bool not_palindrome = false;
      while (current_head < current_tail) {
        if (current_head[0] != current_tail[0]) {
          puts("not palindrome");
          not_palindrome = true;
          break;
        }
        current_tail--;
        current_head++;
      }
      if (!not_palindrome) {
        // tmp_tail[1] = 'd';
        // (tmp_tail+1)[0] = 'd';
        puts(tmp_tail);
        return tmp_head;
      }
    }
    current_tail--;
  }
}
// @leet end
int main(int argc, char *argv[])
{
  puts(longestPalindrome("babad"));
  puts(longestPalindrome("cbbd"));
  return EXIT_SUCCESS;
}
