#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// @leet start

typedef uint16_t u16;

typedef struct llnode {
  struct llnode* next;
  u16 val;
} llnode_t;

int findTheWinner(int n, int k) {
  llnode_t* arena = malloc(sizeof(llnode_t) * n);
  llnode_t* head = arena;
  head->val = 1;
  llnode_t* tail = head;
  // T(n - 1)
  for (int i = 2; i <= n; i++) {
    tail->next = arena+(i-1);
    tail = tail->next;
    tail->val = i;
  }
  tail->next = head;

  llnode_t* current = tail;
  // T(k(n(n+1)/2))
  while (current != current->next) {
    for (int i = 1; i < k; i++) {
      current = current->next;
    }
    llnode_t* tmp = current->next->next;
    current->next = tmp;
  }
  u16 output = current->val;
  free(arena);
  return output;
}
// @leet end

#define PRINT_NODE_SINGLE(node) printf("(%d [%p]) -> ", node->val, node);
void print_llnode(llnode_t *);

void print_llnode(llnode_t* head) {
  PRINT_NODE_SINGLE(head);
  llnode_t* current = head->next;
  while (current != head) {
    PRINT_NODE_SINGLE(current);
    current = current->next;
  }
  PRINT_NODE_SINGLE(head);
  puts("");
}
int main(int argc, char *argv[])
{
  printf("findTheWinner(100000,20) = %d\n", findTheWinner(100000,20));
  return EXIT_SUCCESS;
}
