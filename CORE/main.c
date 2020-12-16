/*-------------------------------------------------------------------/
*	 ����ģ��ϵͳ
*
*�汾��1.0
*���ߣ����� 
* 
*�ص㣺�ӱ����̴�ѧ ����ʵ����
*ʱ�䣺2018��12��30��
*˵����ʹ��оƬSTM32F103VCT6
*���ܣ�1.  
*      2.  
*      3.  
*      4.  
*      5.  
*      6. 
*      7.  
*-------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include "nvic.h"
#include "bsp_adc.h"
#include "bsp_dac.h"
#include "bsp_usart1.h"
#include "bsp_key.h" 
#include "delay.h"
#include "bsp_timer.h"
#include "stmflash.h"
extern uint8_t USART2_RXdata;
uint8_t VoiceMFlag=0;
uint8_t VoicePlay=0;
int main(void)
{
	delay_init();
	USART1_Config();
  nvic_cfg();
	ADC1_Init();
	DAC1_Init();
	Key_GPIO_Config();
	printf("��ʼ�����\r\n");
  /* Infinite loop */
  while (1)
  {

	if(KEY1==0x01)
	{
	   delay_ms(20);
		if(KEY1==0x01)
		{
		
		while (KEY1 == 0x01 )
				; 

					printf("����1�ѱ�����\r\n");					
          VoiceMFlag=1;

		}
	}
		if(KEY2==0x01)
	{
	   delay_ms(20);
		if(KEY2==0x01)
		{
		
		while (KEY2 == 0x01 )
				; 
	
					printf("����2�ѱ�����\r\n");	
    		VoicePlay=1;

		}
	}
	 
	if(VoicePlay==1)
	{
	        VoicePlay=0;
	         TIM_Cmd(TIM2, ENABLE);	
		      printf("��ʼ����Flash������\r\n");
	}
	
	if(VoiceMFlag==1)
	{
	    VoiceMFlag=0;
//		  erase_flash(addressFlash,79);
//		  printf("Flash�����ɹ�\r\n");
		  TIM_Cmd(TIM3, ENABLE);  //������ʱ��3
		  printf("��ʼ¼��\r\n");
	}
		
  }
}

