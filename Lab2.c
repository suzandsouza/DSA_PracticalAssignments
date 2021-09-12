
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
typedef struct
{
  char a[SIZE];
  int tos;
}Stack;

//pushes the element into the stack
void push(Stack *ph, char x)
{
    ph->tos++;               //Increment tos by 1
    ph->a[ph->tos] = x;     //Store the entered value in the tos and then in variable x
}

//pops the element from the stack
char pop(Stack *pp)
{
    return pp->a[pp->tos--]; //pop the element and decrement tos by 1
}

int main() {
  Stack s;
  s.tos = -1;
  char exp[SIZE];
  char data;
  int i;

    printf("\nEnter the expression: ");
    gets(exp);
    for(i=0;i<strlen(exp);i++)                // iterate throughout the length of the expression
    {
      if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
      {
        push(&s,exp[i]);
      }
      if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
      {
      if(s.tos!=-1)
        {
          data = pop(&s);
          switch(exp[i])
          {
            case ')':
              if(data!='(')
              {
                printf("Corresponding '(' missing.");
                exit(0);
              }
            break;
            case '}':
              if(data!='{')
              {
                printf("Corresponding '{' missing.");
                exit(0);
              }
            break;
            case ']':
              if(data!='[')
              {
                printf("Corresponding '[' missing.");
                exit(0);
              }
             break;
          }
        }
      else
        {
          printf("Corresponding '(' or '{' or '[' missing.");
          exit(0);
        }
      }
      else
        
        continue;
    }
     if(s.tos!=-1)
      printf("Corresponding ')' or '}' or ']' missing.");
     else
      printf("\nParenthesis Matched!! \nBalanced expression.");

  return 0;
}


// **************Sample Test Cases******************

// Enter the expression: a+f-a)=(a+c)
// Corresponding '(' or '{' or '[' missing.

// Enter the expression: (a+{b-c}/d])
// Corresponding '[' missing.

// Enter the expression: (a+{b+c})

// Parenthesis Matched!! 
// Balanced expression.  