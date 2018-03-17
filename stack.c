#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int stack_len(stack* s) {

  stack* trav = s;
  int n = 1; // Including the head  

  while((trav = trav->next) != NULL) {
    //trav = trav->next;
    ++n; 
  }
  
  return n;
}

void print_stack(stack* s) {
  stack* trav = s;
  int n = 1; // Including the head  
  printf("{");
  while(trav != NULL) {
    printf("%f, ", trav->data);
    ++n; 
    trav = trav->next;
  }
  printf("}\n");
}

stack* stack_push(stack* s, double data) {
  /*
  if(s == NULL) {

    stack* node = malloc(sizeof *s);
    node->data = data;
    node->next = s;
    return node; 
  } else {
    stack* node = malloc(sizeof *s);
    node->data = data;
    stack* tmp = s->next;
    s->next = node;
    node->next = tmp; 
    return s;
    }*/
  stack* tmp = malloc(sizeof*tmp);
  tmp->data = data;
  tmp->next = s;
  s = tmp;
  //printf("%f", s->data);
  //print_stack(s);
  return s;
}

stack* stack_pop(stack* s, double* r) {
  *r = s->data;
  stack* tmp = s;
  s = tmp->next;
  //free(tmp);
  return s; 
}

/*
int main(void) {

  stack* s = malloc(sizeof *s);
  s = NULL;

  s = stack_push(s, 3);
  s = stack_push(s, 2);

  double a,b,c;
  a=b;
  s = stack_pop(s, &a);
  s = stack_pop(s, &b);

  printf("%f %f\n", a,b);
}
*/
