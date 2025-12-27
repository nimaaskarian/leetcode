// @leet start
#include <stdckdint.h>

int reverse(int x){
  int out = 0;
  while (x) {
    if (ckd_mul(&out, out, 10)) {
      return 0;
    }
    if (ckd_add(&out, out, x%10)) {
      return 0;
    }
    x/=10;
  }
  return out;
}
// @leet end
