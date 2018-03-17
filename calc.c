#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "stack.h"

// Type enum
enum {
  TYPE_NUM,
  TYPE_OP
};

// Operations enum 
enum {
  OPP_ADD,
  OPP_SUB,
  OPP_MULT,
  OPP_DIV,
  OPP_CLR,
  OPP_STR, // Not implemented 
  OPP_ERR
};

stack* evaluate_operand(stack* s, int op) {
  double a,b, result;
  switch(op) {
  case OPP_ADD:
    a=b=0.0;
    s = stack_pop(s, &a);
    s = stack_pop(s, &b);
    result = a+b;
    s = stack_push(s, result); // Its not storing the result properly 
    printf("->%f\n", result);
    return s;
    break;
  case OPP_SUB:
    a=b=0.0;
    s = stack_pop(s, &a);
    s = stack_pop(s, &b);
    result = b-a;
    s = stack_push(s, result); // Its not storing the result properly 
    printf("->%f\n", result);
    return s;
    break;
  case OPP_MULT:
    a=b=0.0;
    s = stack_pop(s, &a);
    s = stack_pop(s, &b);
    result = a*b;
    s = stack_push(s, result); // Its not storing the result properly 
    printf("->%f\n", result);
    break;
  case OPP_DIV:
    a=b=0.0;
    s = stack_pop(s, &a);
    s = stack_pop(s, &b);
    result = b / a;
    s = stack_push(s, result); // Its not storing the result properly 
    printf("->%f\n", result);
    break;
  case OPP_CLR:
    s = NULL;
    return s; 
    break;
  case OPP_ERR:
    printf("Error");
    break;
  }
}

int parse_operand(char* input) {
  if(strcmp(input, "ADD") == 0) {
    return OPP_ADD;
  } else if(strcmp(input, "SUB") == 0) {
    return OPP_SUB;
  } else if(strcmp(input, "MULT") == 0) {
    return OPP_MULT;
  } else if(strcmp(input, "DIV") == 0) {
    return OPP_DIV;
  } else if(strcmp(input, "STR") == 0) {
    return OPP_STR;
  } else if(strcmp(input, "CLR") == 0) {
    return OPP_CLR;
  } else {
    return OPP_ERR;
  }
}

int parse_type(char* input, double* num) {
  char* check; 
  double n = strtod(input, &check); // try to convert it 

  if(input == check) { // Not a number must be an operand
    return TYPE_OP;
  } else { // is a number, set num and return type
    *num = n; 
    return TYPE_NUM;
  }
}

stack* parse_input(char* input, stack* s) {
  double num; // Potential num
  int type = parse_type(input, &num);

  if(type == TYPE_NUM) {
    s = stack_push(s, num);
    return s;
  } else {
    int op = parse_operand(input);
    s = evaluate_operand(s, op);
    return s;
  }
}

int main(void) {

  // Initialize the stack 
  stack* s = malloc(sizeof(*s));
  s = NULL;

  // Read in input 
  char* input;
  while(1) {
    printf(": ");
    scanf("%s", input);

    // See if they want to exit
    if(strcmp(input, "exit") == 0) {
      exit(1);
    }

    // Parse input 
    s = parse_input(input, s);

  }
}
