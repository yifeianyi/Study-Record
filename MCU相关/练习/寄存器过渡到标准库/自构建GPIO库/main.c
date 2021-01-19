#include"stm32f10x.h"
#include"stm32f10x_gpio.h"
int main(void){
    /**************开启时钟*****************/
  
    RCC->RCC_APB2ENR = (0x8);  //PA and PB

    /**************GPIO端口配置******************
     * 
     *        1、选择引脚（CRL、CRH）
     *        2、配速       
     *        3、选择IO模式（8种模式）
     *        
     *        ps：在2、3中，每个引脚配置占四位
     * 
     ********************************************/
    GPIOB->CRL &= ~(0x00f000ff); //控制端口清零
    GPIOB->CRL |= (0x200022);  //0、1、5口 2MHz速率推挽输出

    GPIOB->BSRR = GPIO_PIN_ALL;     //默认引脚输出高电平
		GPIOB->ODR  &= ~GPIO_PIN_5 ;		
		//GPIOB->ODR  =0xfff0 ;
		
    while(1){
        
    }
}
