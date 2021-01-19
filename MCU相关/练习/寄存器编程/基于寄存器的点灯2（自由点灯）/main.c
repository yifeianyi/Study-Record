#include"stm32f10x.h"

uint LED[3]={0x00000020,0x00000001,0x00000002};
uint ans=0;
char a[3]={0,0,0};
void delay(){
	int i=1000,j;
	while(i--){
		j=500;
		while(j--);
	}
	
	return;
}

void dfs(int u){
	int i;
	if(u==3){
			for(i=0;i<3;i++){
				if(a[i])ans+=LED[i];
			}		
			GPIOB_ODR = ans;
			delay();
			ans = 0;
			return ;
	}
	dfs(u+1);
	a[u]=1;
	dfs(u+1);
	a[u]=0;
	return ;
}

int main(void){
	
	/***********初始化*************/
	/*
			1、开启GPIO端口时钟 
			2、端口清零
			3、配置输入/输出模式、输出速率
	*/
	//开启端口时钟
	RCC_APB2ENR |= (1<<3);
	
	
	//清零控制PB0的端口位
	GPIOB_CRL &= ~( 0x00f000ff );
	//配置PB0为通用推挽输出，速度为10M
	GPIOB_CRL |= (0x00200022);

	
	while(1){
		dfs(0);
	}

}
