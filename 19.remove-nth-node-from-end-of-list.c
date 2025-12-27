
#include <stdint.h>
struct ListNode {
   int val;
   struct ListNode *next;
};
// @leet start
typedef struct ListNode llnode;
typedef uint8_t u8;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
llnode* removeNthFromEnd(llnode* head, int n) {
  llnode* nitems = malloc(sizeof(llnode) * n);
  u8 nitems_size = 0;
  llnode* current = head;
  while (1) {
    if (current->next == NULL) {
      if (n-2 < 0) {
        current->next
      }
      nitems_size[n-2]
    }
    current = current->next;
  }
}
// @leet end
