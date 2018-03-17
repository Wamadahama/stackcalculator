
typedef struct stack {
  double data; 
  struct stack* next; 
} stack; 


int stack_len(stack*);
stack* stack_push(stack*, double);
stack* stack_pop(stack*, double*);
void print_stack(stack*);
