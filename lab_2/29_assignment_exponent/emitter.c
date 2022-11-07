/* emitter.c */

#include "global.h"

int stack[10][2]; //ten entries containing val and type. 
int head = -1;

void append(int token_type, int token_value)
{   
    head++;
    stack[head][0] = token_value;
    stack[head][1] = token_type; 
}

int pop()
{
    int temp;
    if(head == -1)
    {
        printf("stack empty\n");
    }
    else if(stack[head][1] == NUM)
    {
        temp = stack[head][0];
        head--;
        return temp;
    }
    else if(stack[head][1] == ID)
    {
        temp = symtable[stack[head][0]].value;
        head--;
        return temp;
    }
    else
    {
        printf("strange type");
    }
    return EXIT_FAILURE;
}

void print_stack()
{
    printf("here is stack: %d, %d, %d, %d\n",stack[0][0],stack[1][0],stack[2][0], stack[3][0]);

}

void emit (int token_type, int token_value)  /*  generates output  */
{
    int temp1, temp2;
    switch(token_type) {
    case '^' : 
        temp1 = pop();
        temp2 = pop();
        int tot = temp2;
        for (int i = 0; i<temp1-1; i++)
        {
            tot = tot * temp2;
        }
        append(NUM, tot);
        printf("%c\n", token_type); break;
    case '+' : 
        append(NUM, pop() + pop());
        printf("%c\n", token_type); break;

    case '-' : 
        temp1 = pop();
        append(NUM, pop() - temp1);
        printf("%c\n", token_type); break;
    
    case '*' : 
        append(NUM, pop() * pop());
        printf("%c\n", token_type); break;
    
    case '/': 
        temp1 = pop();
        append(NUM, pop() / temp1);
        printf("%c\n", token_type); break;
    case '=':
        symtable[stack[head-1][0]].value = pop(); printf("%c\n", token_type);
        printf("Here is the value of the newly assigned var: %s = %d\n",symtable[stack[head][0]].lexeme, symtable[stack[head][0]].value); 
         head = -1;
        break;
    case DIV:
        //same as division.
        printf("DIV\n"); break; 
    case MOD:
        temp1 = pop();
        temp2 = pop();
        int rest = temp2;
        while (rest >= temp1)
        {
            rest = rest - temp1;
        }
        append(NUM, rest);
        printf("MOD\n"); break;

    case NUM:
        append(token_type, token_value); printf("%d\n", token_value); break;
    case ID:
        append(token_type, token_value); printf("%s\n", symtable[token_value].lexeme); break; 
    default:     
        printf("[Unknown token %d, with value %d]\n", token_type, token_value);
    }
}

