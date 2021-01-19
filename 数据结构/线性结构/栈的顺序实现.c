/*
    栈的顺序存储
*/
#include<stdlib.h>

#define MaxSize 1000
typedef struct SNode *Stack;
typedef Stack NewNode;
struct DStack{
    int Data[MaxSize];
    int Top;
};

DStack CreateStack(){
    Stack s;
    s=(NewNode)malloc(sizeof(struct SNode));
    s->Top = -1;
}

void Push(int x, Stack s){
    if(s->Top ==MaxSize-1){
        printf("stack is full！\n");
        return ;
    }
    else{
        s->Data[++(S->Top)] = x;
        return ;
    }
}

int Pop(Stack s){
    if(s->Top == -1){
        printf("stack is empty!\n");
        return ERROR;
    }
    else return (s->Data[(s->Data)--]);
}


