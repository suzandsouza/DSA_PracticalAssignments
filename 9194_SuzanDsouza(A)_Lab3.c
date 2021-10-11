//NAME:Suzan Dsouza
//Class: SE COMP A
//R.NO:9194
//infix to postfix


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
typedef struct 
{
    int tos;
    char a[SIZE];             //create an array to store the expression
    
}Stack;

void push(Stack *s,char ele)   //method to push the expression into the stack
{
    if(s->tos==SIZE-1)
    {
        printf("Stack overflow");
        return;
    }else
    {
        s->tos++;           //increment the value of tos
        s->a[s->tos]=ele;   //store the value of the element 
        
    }
    
}


char pop(Stack *s)
{
    int x=s->a[s->tos];            //pop an element present at this position
    s->tos--;                      //decrement the value of s
    return x;                     //return x means pop the variable x
} 

int isEmpty(Stack s)
{
    if(s.tos==-1)                       //When the tos value becomes -1 it means that the stack is empty
    return 1;
    else
    return 0;
    
}
int precedence(char c)    //precedence check 
{
    if(c=='(')
    return 0;
    else if(c=='+' || c=='-')
    return 1;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='^'|| c=='$')
    return 3;
}


int main()
{
   Stack s1;   //creating a variable s1 of type Stack
   char str[SIZE],post[SIZE];
   int i,j=0;
   char x;
   s1.tos=-1;
   printf("\nEnter the infix operation: ");
   gets(str);
   for(i=0;i<strlen(str);i++)
   {
       if (isalnum(str[i]))                  //isalnum checks for a character is alphanumeric or not
       {
           post[j]=str[i];                   //is yes then all this character to the postfix output
           j++;
           
       }
       else 
       {
           if(str[i]==')')
           {
               x=pop(&s1);
               while(x!='(')           //while parenthesis does not match
               {
                   post[j]=x;
                   j++;
                   x=pop(&s1);
                   
               }
           }else if(isEmpty(s1)|| str[i]=='(' || (precedence(str[i])>precedence(s1.a[s1.tos])))
           {
               //stack is empty push
               //ifstr[i]=(  then push it
               //if str[i] is an operator having precedence than stack top operator then push it
               push(&s1,str[i]);
               
           }else
           {
               while((!isEmpty(s1)) && (precedence(str[i])<= precedence(s1.a[s1.tos])))
               {
                   //if str[i] is operator having less or equal precedence to the STO 
                   //This means that the stack top operator has higher precedence or equal
                   //now go on popping such elements
                   //While popping ensure that the stack is not empty
                   post[j]=pop(&s1);
                   j++;
                   
                   
               }
               push(&s1,str[i]);
           }
           
       }
   }
   
   while(!isEmpty(s1))
   {
       post[j]=pop(&s1);
       j++;
   }
   
   post[j]='\0';
   printf("\nPostfix expression is %s",post);
   return(0);
   
   
   
}

//SAMPLE OUTPUTS
// Enter the infix operation: A*B+C*D
// Postfix expression is AB*CD*+

// Enter the infix operation: (a+((b*c)/(d-e)))

// Postfix expression is abc*de-/+


