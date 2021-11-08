#include "encoder.h"


void TIM4_Mode_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef TIM_ICInitStructure;   
	//	NVIC_InitTypeDef NVIC_InitStructure;	

    //PB6 ch1  A,PB7 ch2 
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//Ê¹ÄÜTIM4Ê±ÖÓ  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//Ê¹ÄÜGPIOBÊ±ÖÓ

    GPIO_StructInit(&GPIO_InitStructure);//½«GPIO_InitStructÖÐµÄ²ÎÊý°´È±Ê¡Ö..........................................ÊäÈë
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;         
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//PA6 PA7¸¡¿ÕÊäÈë  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);                           

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = 65535;  //Éè¶¨¼ÆÊýÆ÷ÖØ×°Öµ   TIMx_ARR = 1024*4-1 ÕâÊÇ360ÏßµÄ
    TIM_TimeBaseStructure.TIM_Prescaler = 0; //TIM4Ê±ÖÓÔ¤·ÖÆµÖµ
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;//ÉèÖÃÊ±ÖÓ·Ö¸î T_dts = T_ck_int    
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIMÏòÉÏ¼ÆÊý 
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);              

    TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge ,TIM_ICPolarity_BothEdge);//Ê¹ÓÃ±àÂëÆ÷Ä£Ê½3£¬ÉÏÉýÏÂ½µ¶¼¼ÆÊý
    TIM_ICStructInit(&TIM_ICInitStructure);//½«½á¹¹ÌåÖÐµÄÄÚÈÝÈ±Ê¡ÊäÈë
    TIM_ICInitStructure.TIM_ICFilter = 0;  //Ñ¡ÔñÊäÈë±È½ÏÂË²¨Æ÷ 
    TIM_ICInit(TIM4, &TIM_ICInitStructure);//½«TIM_ICInitStructureÖÐµÄÖ¸¶¨²ÎÊý³õÊ¼»¯TIM3


//		//Òç³öÖÐ¶ÏÉèÖÃ
//    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //ÔÊÐíTIM4Òç³öÖÐ¶Ï
// 
//    NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn; 
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; 
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; 
//    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
 
 
  TIM_SetCounter(TIM4,0); //TIM4->CNT=0
  TIM_Cmd(TIM4, ENABLE); 
}

//Õâ¸öÏëÓÃµÄ»°ÐèÒªÖØ×°ÔØÖµºÍÂëÅÌ×ªÒ»È¦¼ÆµÃÊýÒ»Ñù£¬ÒòÎªÕâ¸öÊÇ¼ÆÍêÖÐ¶ÏÒ»´Î¡£
int circle_count=0;//È¦Êý
//void TIM4_IRQHandler(void)
//{
//    if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET)
//    {       
//        if((TIM4->CR1>>4 & 0x01)==0) //DIR==0
//            circle_count++;
//        else if((TIM4->CR1>>4 & 0x01)==1)//DIR==1
//            circle_count--;
//    }
//    TIM_ClearITPendingBit(TIM4,TIM_IT_Update); 
//}
