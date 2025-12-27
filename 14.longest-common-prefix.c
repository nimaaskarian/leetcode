#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @leet start
char* longestCommonPrefix(char** strs, int strsSize) {
  char * out = malloc(201);
  unsigned char j = 0;
  unsigned char i = 1;
  for (;j < strsSize; j++) {
    char ch = strs[0][j];
    for (; i < strlen(strs[j]); i++) {
      if (!strs[j][i]) {
        goto exit;
      }
      if (ch != strs[j][i]) {
        out[i] = 0;
        return out;
      }
    }
    out[i] = ch;
  }
  exit:
  out[j] = 0;
  return out;
}
// @leet end
