#include"LED.H"

void LED_Color_Conf(uint16_t Pin){
	GPIO_InitTypeDef GPIO_INIT;
	

    //时钟配置
	RCC_APB2PeriphClockCmd(LED_CLK,ENABLE);

    //配置选择pin口、io模式、速度
    GPIO_INIT.GPIO_Pin 	 = Pin;
		GPIO_INIT.GPIO_Mode	 = GPIO_Mode_Out_PP;
		GPIO_INIT.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED_PORT,&GPIO_INIT);

}
