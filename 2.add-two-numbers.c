#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

// @leet start
typedef u_int8_t u8;
typedef struct ListNode llnode;

#define FIX_PTR(ptr) while (ptr != NULL) {\
      ptr->val += extra;\
      extra = ptr->val/10;\
      ptr->val%=10;\
      last = ptr;\
      ptr = ptr->next;\
    }

llnode* addTwoNumbers(llnode* l1, llnode* l2) {
  llnode* l1_cur = l1;
  llnode* l2_cur = l2;
  u8 extra = 0;
  llnode* l1_parent = l1;
  while (l1_cur != NULL && l2_cur != NULL) {
    l1_cur->val += l2_cur->val+extra;
    extra = l1_cur->val/10;
    l1_cur->val %= 10;
    l1_parent = l1_cur;
    l1_cur = l1_cur->next;
    l2_cur = l2_cur->next;
  }
  llnode* last = l1_cur;
  FIX_PTR(l1_cur);
  if (l2_cur != NULL) {
    llnode* l2_tmp = l2_cur;
    FIX_PTR(l2_tmp);
    l1_parent->next = l2_cur;
  }
  if (extra) {
    llnode * new = malloc(sizeof(llnode));
    new->next = NULL;
    new->val = extra;
    if (last)
      last->next = new;
    else
      l1_parent->next = new;
  }
  return l1;
}
// @leet end

#define arr2llnode(arr, node) { node = malloc(sizeof(llnode));\
llnode * cur = node;\
for (int i =0; ; i++) {\
  cur->val = arr[i];\
  if (i+1 < (sizeof(arr)/sizeof(int))) { \
    cur->next=malloc(sizeof(llnode));\
    cur = cur->next;\
  } else {\
    cur->next = NULL;\
    break;\
  }\
} }\

void print_listnode(llnode * head) {
  while (head != NULL) {
    printf("(%d) -> ", head->val);
    head = head->next;
  }
  puts("");
}

int main(int argc, char *argv[])
{
  llnode* node1;
  llnode* node2;
  static int nums1[] = {2,4,9};
  static int nums2[] = {5,6,4,9};
  arr2llnode(nums1, node1);
  arr2llnode(nums2, node2);
  print_listnode(node1);
  print_listnode(node2);
  llnode* out = addTwoNumbers(node1, node2);
  print_listnode(out);
  return EXIT_SUCCESS;
}
