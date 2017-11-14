#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  int i;
  struct node *next;
};

void print_list(struct node *n){
    while (n){
      printf("%d\n", (*n).i);
      n = n->next; //(*n).next
    }
}

struct node * insert_front(struct node *current, int newint){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  (*new).next = current;
  (*new).i = newint;
  return new;
}

struct node * free_list(struct node *n){
  struct node *temp;
  while(n){
      temp = n;
      n = n->next;
      free(temp);
  }
  return n;
}

int main() {
  struct node * front;
  front = (struct node *)malloc( sizeof(struct node) );
  printf("\nAdding nodes of increasing even numbers\n");
  for (int i = 0; i < 18; i += 2) {
    front = insert_front(front, i);
  }
  print_list(front);
  //front = free_list(front);
  printf("\nFree at last!:\n");
  print_list(front);
  return 0;
}
