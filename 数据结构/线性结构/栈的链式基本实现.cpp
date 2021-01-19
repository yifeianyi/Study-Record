/*
    鏍堢殑閾惧紡瀛樺偍
*/
#include<stdlib.h>
#include<stdio.h>
typedef struct SNode *Stack;
typedef Stack NewNode;
struct SNode{
    int Data;
    struct SNode*Next;
};

Stack CreateStack(){
    //鍚ご缁撶偣
    Stack s;
    s = (NewNode)malloc(sizeof(struct SNode));
    //s = new Stack;
    s->Next = NULL;
        return s;
}

char IsEmpty(Stack S){
    return (S->Next == NULL);
}

void push(int x, Stack s){
    //鏍堢殑push绛変环浜庡崟閾捐〃鍦ㄥご缁撶偣鎻掑叆涓€涓柊缁撶偣
    NewNode t;
    t=(Stack)malloc(sizeof(struct SNode));
    t->Next=s->Next;
    t->Data=x;
    s->Next = t;
}

int Pop(Stack s){
    if(IsEmpty(s)){
        printf("stack is NULL!\n");
        return NULL;
    }
    else {
        NewNode t = s->Next;
        s->Next = s->Next->Next;
        int Top = t->Data;
        free(t);
        //delete t;
        return Top;
    }
}

int main(){
	
	return 0;
}