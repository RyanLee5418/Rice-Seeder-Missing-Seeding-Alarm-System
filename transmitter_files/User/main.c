

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "nrf24l01.h"


void data_pros()	//数据处理函数
{
	u8 rx_buf[33]="";
	static u16 t=0;			
		NRF24L01_TX_Mode();
		while(1)
		{

		}	
	}


int main()
{ 
	u8 i=0;
	u16 rd=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD初始化
	KEY_Init();
	NRF24L01_Init();
	
	
	/*FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"PRECHIN STM32F1");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"www.prechin.net");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"NRF24L01 Test");
	LCD_ShowString(10,70,tftlcd_data.width,tftlcd_data.height,16,"K_UP:RX_Mode  K_DOWN:TX_Mode");
	FRONT_COLOR=RED;*/

	/*while(NRF24L01_Check())	 //检测NRF24L01是否存在
	{
		LCD_ShowString(140,50,tftlcd_data.width,tftlcd_data.height,16,"Error   ");			
	}
	LCD_ShowString(140,50,tftlcd_data.width,tftlcd_data.height,16,"Success");*/
	
	while(1)
	{ 
		data_pros(); 
		i++;
		if(i%20==0)
		{
			led1=!led1;
		}
		
		delay_ms(10);
			
	}
}

