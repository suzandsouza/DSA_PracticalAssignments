#include<stdio.h>
#include<stdlib.h>
#define SIZE 3              //Here we define the maximum size of our Stack

typedef struct
{
  float a[SIZE];
  int tos;
}Stack;

//checks whether stack is empty or not
int isEmpty(Stack *p)
{
  if(p->tos == -1)
    return 1;
   else
    return 0;
}
//checks whether the stack is full or not
int isFull(Stack *p)
{
  if(p->tos == SIZE-1)
    return 1;
   else
    return 0;
}

//pushes the element into stack
void push(Stack *ph, float x)
{
  if(isFull(ph)==1)
    printf("Stack overflow\n");
  else
  {
    ph->tos++;
    printf("The pushed element is %0.3f ",x);
    ph->a[ph->tos] = x;
  }
}

//pops the tos from the stack
float pop(Stack *pp)
{
  if(isEmpty(pp)==1)
    printf("Stack Overflow\n");
  else
    return pp->a[pp->tos--];
}

//returns the peek element
float peek(Stack s)
{
  if(s.tos == -1)
    printf("Stack empty");
  else
    return s.a[s.tos];
}

//displays the elements
void display(Stack s)
{
	int i;
   for(i = s.tos; i>=0; i--)
    printf("%0.3f\t", s.a[i]);
}

int size(Stack s)
{
  return (s.tos+1);
}

 int main()
 {
   Stack s;          //create any variable ofthe type stack
   s.tos = -1;
   int option=0;
   float x,data;
   char choice = 'y';

   while(choice =='Y' || choice == 'y')
   {
     choice = 'n';
     printf("Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size\n");
     scanf("%d",&option);
     switch(option)
     {
       case 1:
        printf("Enter the element to push: ");
        scanf("%f",&x);
        push(&s,x);
       break;
       case 2:
        data = pop(&s);
        printf("The poped element is %0.3f",data);
       break;
       case 3:
        printf("The elements of the Stack are ");
        display(s);
        break;
       case 4:
        printf("\nThe current top of stack element is %0.3f", peek(s));
       break;
       case 5:
        printf("The size of the stack is %d", size(s));
       break;
     }
      printf("\nDo you want to continue?(Y/N): ");  //before exiting the while loop check if the user wants to continue
      scanf("%s",&choice);
   };
 }
 

 //*****************SAMPLE OUTPUTS*****************************

// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 1
// Enter the element to push: 7
// The pushed element is 7.000 
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 9

// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 1
// Enter the element to push: 56
// The pushed element is 56.000 
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 1
// Enter the element to push: 45
// The pushed element is 45.000 
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 1
// Enter the element to push: 20
// Stack overflow

// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 3
// The elements of the Stack are 45.000    56.000  7.000
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 4

// The current top of stack element is 45.000
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 5
// The size of the stack is 3
// Do you want to continue?(Y/N): y
// Enter your choice: 1)Push  2)Pop  3)Display  4)Peek  5)Size
// 2
// The poped element is 45.000
// Do you want to continue?(Y/N): n
// PS C:\Users\dsouza\OneDrive\Desktop\New folder (3)\c c++> 