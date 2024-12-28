// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// #define MAX 100

// // Stack and its associated variables
// char stack[MAX];
// int top = -1;

// // Function to push an element onto the stack
// void push(char value) {
//     if (top == MAX - 1) {
//         printf("Stack overflow\n");
//         return;
//     }
//     stack[++top] = value;
// }

// // Function to pop an element from the stack
// char pop() {
//     if (top == -1) {
//         printf("Stack underflow\n");
//         return '\0';
//     }
//     return stack[top--];
// }

// // Function to get the top element of the stack without popping it
// char peek() {
//     if (top == -1) {
//         return '\0';
//     }
//     return stack[top];
// }

// // Function to check operator precedence
// int precedence(char op) {
//     switch (op) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         case '^':
//             return 3;
//         default:
//             return 0;
//     }
// }

// // Function to check if a character is an operator
// int isOperator(char ch) {
//     return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
// }

// // Function to convert infix to postfix
// void infixToPostfix(char *infix, char *postfix) {
//     int i = 0, j = 0;

//     while (infix[i] != '\0') {
//         char ch = infix[i];

//         if (isalnum(ch)) {  // Operand
//             postfix[j++] = ch;
//         } else if (ch == '(') {  // Opening parenthesis
//             push(ch);
//         } else if (ch == ')') {  // Closing parenthesis
//             while (top != -1 && peek() != '(') {
//                 postfix[j++] = pop();
//             }
//             if (top != -1 && peek() == '(') {
//                 pop();  // Pop the '('
//             }
//         } else if (isOperator(ch)) {  // Operator
//             while (top != -1 && precedence(peek()) >= precedence(ch)) {
//                 postfix[j++] = pop();
//             }
//             push(ch);
//         }

//         i++;
//     }

//     // Pop remaining operators from the stack
//     while (top != -1) {
//         postfix[j++] = pop();
//     }

//     postfix[j] = '\0';  // Null-terminate the postfix expression
// }

// // Main function
// int main() {
//     char infix[MAX], postfix[MAX];

//     printf("Enter an infix expression: ");
//     scanf("%s", infix);

//     infixToPostfix(infix, postfix);

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 20

char infix[max], postfix[max];
int top = -1;
char stack[max];

void push(char val)
{
    if (top == max - 1)
    {
        printf("\nStack overflow");
        return;
    }
    stack[++top] = val;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
         return 1;
    case '*':
    case '/':
         return 2;
    case '^':
         return 3;
    default:
         return 0;
    }
}

int isOperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}

void inTOpost()
{
    int ch, i=0, j=0;
    while(infix[i]!='\0'){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && peek()!='('){
                postfix[j++] = pop();
            }
            if(top!=-1 && peek()=='(')
            {
                pop();
            }
        }
        else if(isOperator(ch)){
            while(top!=-1 && precedence(ch)<=precedence(peek())){
                postfix[i++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main(){
    printf("\nEnter the infix expression : ");
    scanf("%s", &infix);

    inTOpost();

    printf("\nPostfix expression : %s\n", postfix);

    return 0;

}