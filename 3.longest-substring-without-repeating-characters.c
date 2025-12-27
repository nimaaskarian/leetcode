#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// @leet start
#define DEBUG 1
#define MIN(a,b) ((a) < (b) ? (a) : (b))
int lengthOfLongestSubstring(char* s) {
  unsigned int start = 0;  
  unsigned int max = 0;
  unsigned int n = strlen(s);
  unsigned int end = 0;
  for (; end <= n; end++) {
    unsigned int size = MIN(end-start, n);
    if (memchr(s, s[end], size) != NULL) {
      #if DEBUG
      printf("%s: %c([%d]) was in %.*s\n",s, s[end], end, size, s+start);
      printf("end=%d, start=%d\n", end, start);
      #endif
      if (end-start > max) {
        #if DEBUG
        printf("setting max %d->%d\n", max, end-start);
        #endif
        max = end-start;
      }
      #if DEBUG
      printf("setting start %d->%d\n", start, end);
      #endif
      start = end-1;
    } 
    #if DEBUG
    else {
      printf("%s: %c([%d]) wasn't in %.*s\n",s, s[end], end, size, s+start);
    }
    #endif
  }
  // printf("end-start=%d\n",end-start);
  if (end-start-1 > max)
    return end-start-1;
  return max;
}
// @leet end

int main(int argc, char *argv[])
{
  // printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
  // printf("%d\n", lengthOfLongestSubstring("bbbbb"));
  // printf("%d\n", lengthOfLongestSubstring("pwwkew"));
  // printf("%d\n", lengthOfLongestSubstring("abc"));
  // printf("%d\n", lengthOfLongestSubstring("aab"));
  printf("%d\n", lengthOfLongestSubstring("dvdf"));
  return EXIT_SUCCESS;
}
