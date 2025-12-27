#!/usr/bin/tcc -run
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define STR_FMT(str8) (u16)str8.size, (u8 *)str8.buff
#define STR_FMT_PTR(str8) (u16)str8->size, (u8 *)str8->buff
// @leet start
typedef u_int8_t u8;
typedef u_int16_t u16;

typedef struct str {
  u16 capacity;
  u16 size;
  u8 * buff;
} str_t;

str_t str_new(u16 capacity) {
  return (str_t){
    .capacity = capacity,
    .buff = malloc(capacity),
    .size = 0,
  };
}

void str_push(str_t* s, char ch) {
  if (s->size < s->capacity) {
    s->buff[s->size++] = ch;
  } else {
    fprintf(stderr, "%s:%d: error: capacity (%d) full\n", __FILE__, __LINE__, s->capacity);
    exit(1);
  }
}

void str_push_front(str_t* s, char ch) {
  if (s->size >= s->capacity) {
    fprintf(stderr, "%s:%d: error: capacity (%d) full\n", __FILE__, __LINE__, s->capacity);
    exit(1);
  }
  s->size++;
  for (u16 i = s->size-1; i >= 1; i--) {
    s->buff[i] = s->buff[i-1];
  }
  s->buff[0] = ch;
}

void str_terminate(str_t* s) {
  s->buff[s->size] = 0;
}

str_t big_int_multiply(const str_t* a, char b, int offset) {
  str_t output = str_new(a->size+offset+1);
  for (u8 i = 0; i< offset; i++) {
    str_push(&output, '0');
  }
  u8 extra = 0;
  for (int i = a->size-1; i >= 0; i--) {
    u8 value = (a->buff[i]-'0')*(b-'0') + extra;
    extra = value/10;
    value%=10;
    str_push_front(&output, value+'0');
  }
  if (extra) {
    str_push_front(&output, extra+'0');
  }
  return output;
}

void big_int_addeq(str_t* a, const str_t* b) {
  u8 extra = 0;
  for (int i = a->size-1; i>= 0; i--) {
    int index =i-(a->size - b->size);
    if (index >= 0) {
      u16 value = a->buff[i] + b->buff[index]- 2*'0' + extra;
      extra = value/10;
      value %= 10;
      a->buff[i] = value + '0';
    } else {
      u16 value = a->buff[i] - '0' + extra;
      extra = value/10;
      value %= 10;
      a->buff[i] = value + '0';
    }
  }
  for (int i = b->size-a->size-1; i>= 0; i--) {
    u16 value = b->buff[i] - '0' + extra;
    extra = value/10;
    value %= 10;
    str_push_front(a, value + '0');
  }
  if (extra) {
    str_push_front(a, extra+'0');
  }
}

char* multiply(char* num1, char* num2) {
  if (num1[0] == '0' || num2[0] == '0') {
    return "0";
  }
  u8 sizeof1 = strlen(num1);
  u8 sizeof2 = strlen(num2);
  str_t output = str_new(sizeof1+sizeof2+1);
  str_t num1_str;
  num1_str.capacity = sizeof1+1;
  num1_str.size = sizeof1;
  num1_str.buff = num1;
  for (int i = sizeof2-1; i >= 0; i--) {
    str_t multipllied = big_int_multiply(&num1_str, num2[i], sizeof2-i-1);
    big_int_addeq(&output, &multipllied);
  }
  str_terminate(&output);
  return output.buff;
}
// @leet end
//
int main(int argc, char *argv[])
{
  str_t s = str_new(3);
  str_push(&s, '4');
  str_push(&s, '5');
  str_push(&s, '6');
  str_t b = str_new(5);
  str_push(&b, '1');
  str_push(&b, '2');
  str_push(&b, '3');
  
  printf("%s\n",multiply("123", "456"));
}
