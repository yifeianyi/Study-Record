#include <stdio.h>

int main(){
//    char str[100] = {0};
//    scanf("%[^\n]s",str);
//    scanf("%s",str);
    
    /***********************************************
     *
     *  %s:不能读入空格，空格会被当为分隔符
     *  []:字符匹配集
     *      [^\n]:除了换行，都当合法输入读入
     *      若不处理\n,\n还是会保留在输入流中
     * 
     ***********************************************/
    

    /***********************************************
     * 
     *  文件操作：
     *      w:
     *      w+
     *      r
     * 
     * *********************************************/
//     文件写操作 
//     FILE *fp = fopen("test.txt","a+");
//     fprintf(fp,"hello world\n");


   	
   	char ans[100] = {0};
   	int offset = 0;
   	char temp;
   	FILE  *fin = fopen("test.txt","r");
   	while(fscanf(fin,"%c",&temp)!=EOF){
   		offset+= sprintf(ans+ offset,"%c",temp);  
	}
	fclose(fin);
	printf("%s",ans);
   	
    return 0;
}
