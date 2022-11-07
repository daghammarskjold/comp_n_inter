//calculating the expressions and assigns values 
#include "global.h"

int stack[10];
int head = -1;

void append(int entry)
{
    stack[head] = entry;
    head++;
}

int pop()
{
    if(head == -1)
    {
        printf("Error, stack emprty can not pop!\n");
    }
    else
    {
        int temp = stack[head];
        head--;
        return temp;
    }
}


void calculator()
{
    
}

int main()
{
    int wtf = 5;
    append(wtf);

}