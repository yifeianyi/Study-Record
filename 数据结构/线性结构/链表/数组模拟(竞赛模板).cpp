#include<isotream>
using namespace std;
const int N = 1e7;
//head头结点，e[]节点的值，ne[]节点的next指针数组
int head,e[N],ne[N];
int idx //节点编号

void init(){
    head = -1;
    idx = 0;
}

void insertHead(int a){
    e[idx]=a;
    ne[idx]=head;
    head = idx++;
}

void insert(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void remove(int k){
    //删除k后面的一个节点
    ne[k]=ne[ne[k]];
}