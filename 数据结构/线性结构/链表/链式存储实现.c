/*
	基本操作实现：
	1、List MakeEmpty();					//建一个空链表	
	2、int FindKth(int K,List L );			//返回第k个元素
	3、int Find(int x,List L); 				//查找x第一次出现的位置
	4、void Insert(int x,int i,List L);		//在位置i前插入一个元素x
	5、void Delete(int i,List L);			//删除第i个元素
	6、int Length(List L);					//返回链表长度
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode*List;

struct LNode{
	int Data;
	List Next;
};

/*
	头结点优点：空链表和有节结点的链表操作统一
*/
List MakeEmpty(){
	List Ptrl;
	Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl->Next = NULL;
	return Ptrl;
}
int Length(List Ptrl){
	//含头结点版本
	List p = Ptrl->Next;
	int len = 0;
	while(p){
		len++;
		p=p->Next;
	}
	return len;
}

List FindKth(int K , List Ptrl){
	//从1开始计数
	List p = Ptrl;
	int i =1;
	while (p!=NULL && i<K)
	{
		p=p->Next;
		i++;
	}
	if(i==K)return p;
	else return NULL;
}

List Find(int x,List Ptrl){
	List p = Ptrl;
	while (p!=NULL && p->Data!=x) p=p->Next;
	return p;
}


/*
	在第i个位置插结点：
		创建新节点

		if 插在第一个位置：
			1、新节点后继为头结点后继
			2、头结点后继为新节点
		else：
			1、找到第i-1个结点的位置
				ps:需要判断i-1个位置的结点是否存在
			2、新节点s连接i-1的后继
			3、i-1后继设置成s


*/
void Insert(int x,int i,List Ptrl){
	List p,s;
	if(i==1){
		s = (List)malloc(sizeof(struct LNode));
		s->Data=x;
		s->Next=Ptrl;
		return ;
	}
	
	p=FindKth(i-1,Ptrl);
	if(p==NULL) printf("error!\n");
	else {
		s=(List)malloc(sizeof(struct LNode));
		s->Data=x;
		s->Next=p->Next;
		p->Next=s;
	}
	return ;
}

/*
	删除结点注意事项：
	1、先找到待删结点的前驱——判断前驱是否存在
	2、通过前驱判断待删结点是否存在
*/
void Delete(int i,List Ptrl){
    if(i==1){
        List p = Ptrl->Next;
        Ptrl->Next=p->Next;
        free(p);
        return ;
    }

    List p=FindKth(i-1,Ptrl);
    if(!p || !p->Next) printf("error");
    else{
        List t = p->Next;
        p->Next=t->Next;
        free(t);
    }
    return ;
}
/*
	小结：
		1、头结点作用：空链表和非空链表操作统一。
		2、每次进行链表相关操作时，都先p=p->NULL，再进行相关判断操作。

*/