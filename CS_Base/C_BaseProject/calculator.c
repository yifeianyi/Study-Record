#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
/******************************相关结构体定义***************************************/
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


/*******************************数据结构相关操作定义***********************************/

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

/*******************************计算器相关操作定义***********************************/
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







/*******************************堆栈相关操作实现***********************************/
//双栈初始化
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
    if(IsFullDataStack(exp))return false;//判断插入是否合法
    exp->data[++exp->top] = x;
    return true;
}
int PushOp(Op_Stack *exp,char x){
    if (IsFullOpStack(exp))return false;//判断插入是否合法
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


/*******************************计算器相关操作实现***********************************/
char* input(int mode){
    /******************非法输入处理**************************/
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
    	//文件数据读入处理 
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
     *      思路：
     *          0、表达式格式：数+符号+数
     *          1、获取Data，并压栈
     *          2、处理运算符
     *          3、遇到非法情况，输出提示形式，并退出
     * 
     * *******************************************************/
    
    Data_Stack *Data = InitDataStack(100);
    Op_Stack *Op = InitOpStack(100);

    int len = strlen(exp);
    for(int i = 0; i<len ; i++){
        double data = GetData(exp,len);//index 参数待定
        
    }

}
void Work(char *exp){
    /*********************************************************
     * 
     *      思路：
     *          1、读取第一个字符，判断是字符串格式：
     *              1）标准输入
     *              2）文件读入
     *              3）非法输入
     *          2、如果是合法串（首字母合法）：
     *              1）循环调用Calc函数
     *              2）输出异常提醒信息
     * 
     *********************************************************/
    int n = 0;
    if(exp[0]=='s')n = (int)GetData(exp,4);
    else if(exp[0]=='-' || IsDigital(exp[0])) n = 1;
    else {
        printf("The expression is error!\n");
        return ;
    }

    //提取表达式的个数
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
