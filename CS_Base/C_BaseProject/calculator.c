#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
/******************************��ؽṹ�嶨��***************************************/
typedef struct Data_Stack
{
    int size;
    double *data;
    int top;
}Data_Stack;

typedef struct Op_Stack
{   
    int size;
    char *op;
    
    int top;

}Op_Stack;


/*******************************���ݽṹ��ز�������***********************************/

Data_Stack* InitDataStack(int size);
Op_Stack* InitOpStack(int size);
int (*PushData)(Data_Stack *exp,double x);
int PushOp(Op_Stack *exp,char x);
int PopData(Data_Stack *exp);
int PopOp(Op_Stack *exp);
double TopData(Data_Stack *exp);
char TopOp(Op_Stack *exp);
int IsFullDataStack(Data_Stack *exp);
int IsFullOpStack(Op_Stack *exp);
int IsEmptyDataStack(Data_Stack *exp);
int IsEmptyOpStack(Data_Stack *exp);

/*******************************��������ز�������***********************************/
char* input(int mode);
void Work(char *exp);
void Calc(char *exp);
double GetData(char *Exp,int index);


int main (){
	printf("Please choose a mode:\n");
	int mode;
	scanf("%d",&mode);
	
    char *test = input(mode);
    printf("%s",test);
    return 0;
}







/*******************************��ջ��ز���ʵ��***********************************/
//˫ջ��ʼ��
Data_Stack* InitDataStack(int size){
    Data_Stack* NewExp = (Data_Stack*) malloc (sizeof(Data_Stack));
    NewExp->size = size;
    NewExp->data = (double *)malloc (sizeof(double)*size);
    NewExp->top = -1;
    return NewExp;
}
Op_Stack* InitOpStack(int size){
    Op_Stack* NewExp = (Op_Stack*) malloc (sizeof(Op_Stack));
    NewExp->size = size;
    NewExp->op = (char *)malloc (sizeof(char)*size);
    NewExp->top = -1;
    return NewExp;
}

int PushData(Data_Stack *exp,double x){
    if(IsFullDataStack(exp))return false;//�жϲ����Ƿ�Ϸ�
    exp->data[++exp->top] = x;
    return true;
}
int PushOp(Op_Stack *exp,char x){
    if (IsFullOpStack(exp))return false;//�жϲ����Ƿ�Ϸ�
    exp->op[++exp->top] = x;
    return true;
}

int PopData(Data_Stack *exp){
    if(IsEmptyDataStack(exp))return false;
    exp->top--;
    return true;
}
int PopOp(Op_Stack *exp){
    if(IsEmptyOpStack(exp))return false;
    exp->top--;
    return true;
}
double TopData(Data_Stack *exp){
    return exp->data[exp->top];
}
char TopOp(Op_Stack *exp){
    return exp->op[exp->top];
}

int IsFullDataStack(Data_Stack *exp){
    return exp->top==exp->size-1;
}
int IsFullOpStack(Op_Stack *exp){
    return exp->top==exp->size-1;
}
int IsEmptyDataStack(Data_Stack *exp){
    return exp->top==-1;
}
int IsEmptyOpStack(Data_Stack *exp){
    return exp->top==-1;
}


/*******************************��������ز���ʵ��***********************************/
char* input(int mode){
    /******************�Ƿ����봦��**************************/
    while(!((mode!=0 && mode==1)||(mode!=1 && mode==0)))
	{
        printf("please input the mode again:\n");
        scanf("%d",&mode);
    }
	
    char *exp = (char*)malloc(sizeof(char)*100);
    if(mode){
        printf("This is mode 1,please input an expression:\n");
        scanf("%s",exp);
        printf("Finished!!!\n");
        return exp;
    }
    else{
    	//�ļ����ݶ��봦�� 
        int offset = 0,sum = 0;
        char temp;
        char ans[100]={0}; 
		FILE *fin = fopen("test.txt","r");
        while(fscanf(fin,"%c",&temp)!=EOF){
            if(temp=='\n')sum++;
            offset += sprintf(ans+offset,"%c",temp);
        }
        sprintf(exp,"sum:%d\n%s",sum,ans);
        fclose(fin);
    
        printf("Read from test.txt ,finish!!!\n") ;
        return exp;
    }
    return NULL;
}

void Calc(char *exp){
    /*********************************************************
     * 
     *      ˼·��
     *          0�����ʽ��ʽ����+����+��
     *          1����ȡData����ѹջ
     *          2�����������
     *          3�������Ƿ�����������ʾ��ʽ�����˳�
     * 
     * *******************************************************/
    
    Data_Stack *Data = InitDataStack(100);
    Op_Stack *Op = InitOpStack(100);

    int len = strlen(exp);
    for(int i = 0; i<len ; i++){
        double data = GetData(exp,len);//index ��������
        
    }

}
void Work(char *exp){
    /*********************************************************
     * 
     *      ˼·��
     *          1����ȡ��һ���ַ����ж����ַ�����ʽ��
     *              1����׼����
     *              2���ļ�����
     *              3���Ƿ�����
     *          2������ǺϷ���������ĸ�Ϸ�����
     *              1��ѭ������Calc����
     *              2������쳣������Ϣ
     * 
     *********************************************************/
    int n = 0;
    if(exp[0]=='s')n = (int)GetData(exp,4);
    else if(exp[0]=='-' || IsDigital(exp[0])) n = 1;
    else {
        printf("The expression is error!\n");
        return ;
    }

    //��ȡ���ʽ�ĸ���
    if(exp[0]=='s'){
        while()
        int FirstIndex = 4,LastIndex = 4;
    }
    
    while(n--){
        char OneExp[100]={0};
        Calc(exp);
    }
}

double GetData(char *Exp,int index);
