#include <stdio.h>

int main(){
//    char str[100] = {0};
//    scanf("%[^\n]s",str);
//    scanf("%s",str);
    
    /***********************************************
     *
     *  %s:���ܶ���ո񣬿ո�ᱻ��Ϊ�ָ���
     *  []:�ַ�ƥ�伯
     *      [^\n]:���˻��У������Ϸ��������
     *      ��������\n,\n���ǻᱣ������������
     * 
     ***********************************************/
    

    /***********************************************
     * 
     *  �ļ�������
     *      w:
     *      w+
     *      r
     * 
     * *********************************************/
//     �ļ�д���� 
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
