// vim:foldmethod=marker
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// [2,7,11,15]
int* twoSum(int* nums, int n, int target, int* returnSize) {
  int min = nums[0], max = nums[0];
  // T(2n) = O(n) {{{
  for (int i = 1; i < n; i++) {
    if (nums[i] > max) {
      max = nums[i];
    } else 
    if (nums[i] < min) {
      min = nums[i];
    }
  }
  // }}}
  int* output = malloc(sizeof(int)*2);
  *returnSize = 2;
  // space complexity O(2*10^9+1)
  int* helper = malloc(sizeof(int)*abs(target-min));
  memset(helper, -1, target);
  // T(n) = O(n) {{{
  for (int i = 0; i < n; i++) {
    if (nums[i] > target) {
      continue;
    }
    if (helper[nums[i]-min] != -1) {
      output[0] = helper[nums[i]];
      output[1] = i;
      return output;
    }
    helper[target-i] = i;
  }
  // }}}
  return output;
}
// @leet end
//
int main(int argc, char *argv[])
{
  static int nums[] = {2,7,11,15};
  const int target = 9;
  int output_size;
  int* output = twoSum(nums, sizeof(nums)/sizeof(int), target, &output_size);
  for (int i =0; i< output_size; i++) {
    printf("output[%d] = %d\n", i, output[i]);
  }
  return EXIT_SUCCESS;
}
