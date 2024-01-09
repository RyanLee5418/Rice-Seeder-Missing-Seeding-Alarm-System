

#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "tftlcd.h"
#include "key.h"
#include "nrf24l01.h"

void data_pros()	//数据处理函数
{
	int  cha = 0;
	unsigned int th;
	u8 miss[33];
	u8 rx_buf[33];
	unsigned int temp = 3;//不要超过一个得数
	int temp1 = 48;
	static u16 t=0;
	//临时定义数值
	u8 a='2';
	int b=2;
	u8 zero='0';
	u8 c='Y';
	u8 d='V';
	u8 e='3';
	u8 zz[2];
	zz[0]=zero;
  zz[1]='\0';
	
			LCD_ShowString(10,140,tftlcd_data.width,tftlcd_data.height,16,"Target Number: 3");
			LCD_ShowString(10,160,tftlcd_data.width,tftlcd_data.height,16,"Detected Number:");
			LCD_ShowString(150,160,tftlcd_data.width,tftlcd_data.height,16,"                ");
		  LCD_ShowString(10,180,tftlcd_data.width,tftlcd_data.height,16,"Miss-seeding Number:");
      LCD_ShowString(180,180,tftlcd_data.width,tftlcd_data.height,16,"                ");
	    LCD_ShowString(10,200,tftlcd_data.width,tftlcd_data.height,16,"Excess-seeding Number:");
      LCD_ShowString(190,200,tftlcd_data.width,tftlcd_data.height,16,"                ");
			
		NRF24L01_RX_Mode();	
		while(1)
		{
			if(NRF24L01_RxPacket(rx_buf)==0) //接收到数据显示
			{  	
				rx_buf[32]='\0';
				LCD_ShowString(150,160,tftlcd_data.width,tftlcd_data.height,16,rx_buf);
				//delay_ms(50);
				//a =rx_buf[0];
				if(rx_buf[0]<=e)
				{
					th = rx_buf[0] - zero;//收到的字符和0的差值，转化成int类型,th的值不对，rx_buf的值是对的
				  cha = temp - th;
				  miss[0] = cha + zero;
				  miss[32] ='\0';
				  if(miss[0]!=c&&miss[0]!=d)
				   { 
					  LCD_ShowString(180,180,tftlcd_data.width,tftlcd_data.height,16,miss);
						LCD_ShowString(190,200,tftlcd_data.width,tftlcd_data.height,16,zz);
				   }
				}
				else
				{  
					th = rx_buf[0] - zero;//收到的字符和0的差值，转化成int类型,th的值不对，rx_buf的值是对的
				  cha = th - temp;
				  miss[0] = cha + zero;
				  miss[32] ='\0'; 
					if(miss[0]!=c&&miss[0]!=d)
					{
					 LCD_ShowString(180,180,tftlcd_data.width,tftlcd_data.height,16,zz);
					 LCD_ShowString(190,200,tftlcd_data.width,tftlcd_data.height,16,miss);
					}	
				}
				//miss[0] = cha + temp1;
				//miss[0] = '3' - rx_buf[0];
				//miss[0] = cha;
	
				
				//printf("%u",th);
        //printf("%c",rx_buf[0]);
				//printf("%c",miss[0]);
				if(rx_buf[0] == '9')
				{ 
					led1 = 0;
					led2 = 0;
					led3 = 0;
					led4 = 1;
					led5 = 1;
					led6 = 0;
					led7 = 0;
					beep1 = 0;
          delay_ms(800);		
				}
				else if(rx_buf[0] == '8')
				{ 
					led1 = 0;
					led2 = 0;
					led3 = 0;
					led4 = 0;
					led5 = 0;
					led6 = 0;
					led7 = 0;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '7')
				{ 
					led1 = 0;
					led2 = 0;
					led3 = 0;
					led4 = 1;
					led5 = 1;
					led6 = 1;
					led7 = 1;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '6')
				{ 
					led1 = 0;
					led2 = 1;
					led3 = 0;
					led4 = 0;
					led5 = 0;
					led6 = 0;
					led7 = 0;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '5')
				{ 
					led1 = 0;
					led2 = 1;
					led3 = 0;
					led4 = 0;
					led5 = 1;
					led6 = 0;
					led7 = 0;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '4')
				{ 
					led1 = 1;
					led2 = 0;
					led3 = 0;
					led4 = 1;
					led5 = 1;
					led6 = 0;
					led7 = 0;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '3')
				{ 
					led1 = 0;
					led2 = 0;
					led3 = 0;
					led4 = 0;
					led5 = 1;
					led6 = 1;
					led7 = 0;
					beep1 = 1; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '2')
				{
					led1 = 0;
					led2 = 0;
					led3 = 1;
					led4 = 0;
					led5 = 0;
					led6 = 1;
					led7 = 0;
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '1')
				{
					led1 = 1;
					led2 = 0;
					led3 = 0;
					led4 = 1;
					led5 = 1;
					led6 = 1;
					led7 = 1;	
					beep1 = 0; 
					delay_ms(800);
				}
				else if(rx_buf[0] == '0')
				{
					led1 = 0;
					led2 = 0;
					led3 = 0;
					led4 = 0;
					led5 = 0;
					led6 = 0;
					led7 = 1;
					beep1 = 0; 
					delay_ms(800);
			
				}
				
	      /*if(rx_buf[0] != e)
				{ 
					beep1 = 0;
				}
				else 
				{
					beep1 = 1;
				}*/
			}
			else
			{
				delay_ms(1);
			}
			t++;
			if(t==1000)
			{
				t=0;
				led8=~led8; //一秒钟改变一次状态
			}	
		}	
	

}

int main()
{
	u8 i=0;
	u16 rd=0;
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	beep_Init();
	USART1_Init(9600);
	TFTLCD_Init();			//LCD初始化
	KEY_Init();
	NRF24L01_Init();
	

	
	FRONT_COLOR=BLACK;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,16,"Miss-seeding Alarm System");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"Li Ruowei");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,16,"NRF24L01 Status");
	//LCD_ShowString(10,70,tftlcd_data.width,tftlcd_data.height,16,"K_UP:RX_Mode  K_DOWN:TX_Mode");
	FRONT_COLOR=RED;
	
	while(NRF24L01_Check())	 //检测NRF24L01是否存在
	{
		LCD_ShowString(140,50,tftlcd_data.width,tftlcd_data.height,16,"Error   ");			
	}
	LCD_ShowString(140,50,tftlcd_data.width,tftlcd_data.height,16,"Success");
	
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
