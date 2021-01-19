#if 0
	typedef unsigned int uint;
	#define RCC_APB2ENR *(uint*)0x40021018
	#define GPIOB_CRL  *(uint*)0x40010C00
	#define GPIOB_ODR *(uint*)0x40010C0C
#endif

typedef unsigned int uint;

//外设宏定义 peripheral
#define PERIPH_BASE  			(uint)0x40000000
#define APB2PERIPH_BASE  		PERIPH_BASE+(0x10000)

	//时钟控制
#define AHBPERIPH_BASE  		PERIPH_BASE+(0x20000)	

//定义时钟复位寄存器和GPIOB的基地址
#define RCC_BASE 		(AHBPERIPH_BASE+0X1000)
#define GPIOB_BASE		(APB2PERIPH_BASE + 0X0C00)
#define GPIOA_BASE		(APB2PERIPH_BASE + 0X0800)

//apb2总线使能地址
#define RCC_APB2ENR		*(uint*)(RCC_BASE + 0X18)	

//GPIOB配置
#define GPIOB_CRL		*(uint*)(GPIOB_BASE + 0X00)
#define	GPIOB_CRH		*(uint*)(GPIOB_BASE + 0X04)
#define GPIOB_ODR		*(uint*)(GPIOB_BASE + 0X0C)
#define GPIOB_BSRR	*(uint*)(GPIOB_BASE + 0X10)

//GPIOA配置
#define GPIOA_CRL		*(uint*)(GPIOA_BASE + 0X00)
#define	GPIOA_CRH		*(uint*)(GPIOA_BASE + 0X04)
#define GPIOA_IDR		*(uint*)(GPIOA_BASE + 0X08)
#define GPIOA_ODR		*(uint*)(GPIOA_BASE + 0X0C)
#define GPIOA_BSRR	*(uint*)(GPIOA_BASE + 0X10)

//LED灯颜色
#define LED_R 0x00000002
#define LED_G 0x00000020
#define LED_B 0x00200000
