/*****************************************************************************
 *   GT_adc.c:  Header file for GORGETEK G32F
 *
 *   Copyright(C) 2015, GORGE Technology
 *   All rights reserved.
 *
 *   History
 *   2015.07.21  ver 1.01    Prelimnary version
 *
******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "g32f1xx.h"
#include "gt_sys.h"
#include "gt_adc.h"
#include "gt_rcc.h"

extern uint32_t SystemCoreClock;
extern uint32_t APB2Clock;
/*****************************************************************************
Function Name	ADC_Init
Function Definition	void ADC_Init(uint32_t conversionrate)
Function Description	Initial ADC module
Input Parameters	Conversionrate: conversion rate, must less 1000000 (1MHz)
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_Init(G32F_ADC_TypeDef *ADC, uint32_t conversionrate)
//{

//	uint32_t temp,div;
//	if(APB2Clock<20000000)
//		(*SYSCON).ADCCLKDIV.bit.DIV=1;	//
//	else if(APB2Clock<40000000)
//		(*SYSCON).ADCCLKDIV.bit.DIV=2;	//
//	else if(APB2Clock<60000000)
//		(*SYSCON).ADCCLKDIV.bit.DIV=3;	//
//	else
//		(*SYSCON).ADCCLKDIV.bit.DIV=4;
//	
//	if(ADC==ADC1)
//	{
//		(*SYSCON).SYSAPB2CLKCTRL.bit.ADC1CLK = 1;
//	}
//	else if(ADC==ADC2)
//	{
//		(*SYSCON).SYSAPB2CLKCTRL.bit.ADC2CLK = 1;
//	}
//	else if(ADC==ADC3)
//	{
//		(*SYSCON).SYSAPB2CLKCTRL.bit.ADC3CLK = 1;
//	}
//	//Power up ADC
//	(*ADC).CR.bit.PD = 0;
//	//enable clock of ADC digital

//	//reset ADC digital
//	if(ADC==ADC1)
//	{
//		(*SYSCON).APB2RESET.bit.ADC1RSTN = 1;
//		(*SYSCON).APB2RESET.bit.ADC1RSTN = 0;
//	}
//	else if(ADC==ADC2)
//	{
//		(*SYSCON).APB2RESET.bit.ADC2RSTN = 1;
//		(*SYSCON).APB2RESET.bit.ADC2RSTN = 0;
//	}
//	else if(ADC==ADC3)
//	{
//		(*SYSCON).APB2RESET.bit.ADC3RSTN = 1;
//		(*SYSCON).APB2RESET.bit.ADC3RSTN = 0;
//	}
//	
//	//limit convertion rate to 1M/s
//	if (conversionrate>1000000)
//		conversionrate = 1000000;
//	conversionrate=conversionrate<<4;
//	
//	//caculate clk divider
//	div = APB2Clock/conversionrate/(*SYSCON).ADCCLKDIV.bit.DIV;

//	if (((div*conversionrate)!=APB2Clock)&&(APB2Clock>16000000*div))
//		div++;
//	
//	//set up divider
//	(*ADC).CR.bit.CLKDIV = div;

//	//insert a delay
//	temp=0xff;
//	while (temp--);
//	(*ADC).CR.bit.BURST = BURSTMODE;	
//	//select external sample clk
//	(*ADC).CR.bit.SCMODE=1;
//	(*ADC).CR.bit.CNVEN=0x1;

//	//wait untile adc ready
//	while((*ADC).STAT.bit.ADCRDY ==0);

//	return;
//}
/*****************************************************************************
Function Name	ADC_DeInit
Function Definition	Void ADC_DeInit(viod)
Function Description	De_Initial ADC module. Disable interrupt generated by module and stop any conversion.
Input Parameters	No
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_DeInit(G32F_ADC_TypeDef *ADC)
//{
//	
//	(*ADC).INTEN.all=0;
//	(*ADC).STAT.all = 0xFFFFFFFF;
//	
//	//Power down ADC
//	(*ADC).CR.bit.PD = 1;
//	//Disable ADC clock divider
//  (*SYSCON).ADCCLKDIV.all = 0;	

//	return;
//}
/*****************************************************************************
Function Name	ADC_SetupChannels
Function Definition	Void ADC_SetupChannels (uint32_t channelassign, uint32_t triggermode)
Function Description	Select AD channels to be converted and AD conversion trigger mode
Input Parameters		channelassign: AD channel and DR assignment. Ref CHSEL register description. 
										Example (AD1<<ADC_DR0SEL)|(AD2<<ADC_DR0SEL), channel AD1 conversion value will be in DR1, and channel AD2 conversion value will be in DR4. DRncan not be duplicated.
										triggermode;	BURSTMODE/TRIGGERMODE
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetupChannels (G32F_ADC_TypeDef *ADC,uint32_t channelassign, uint32_t triggermode)
//{
//	uint32_t i;
//	uint32_t temp;
//	uint32_t adcchannel=0;
//	
//	//setup DR conversion enable
//	for (i=0;i<32;i=i+4)
//	{
//		temp = (channelassign & (0xF<<i))>>i;
//		if (temp!=0)
//		{
//			if (temp==0xF)
//				temp=0;

//			if (temp<8)
//			adcchannel |= temp<<i;
//			
//			ADC->CR.bit.CNVEN |= 1<<(i/4);								
//		}		
//	}
//	
//	//Setup channel
//	(*ADC).CHSEL.all = adcchannel;
//	(*ADC).CR.bit.SCMODE=0;		
//	//Select burst mode or triggermode
//	if (triggermode == BURSTMODE)
//		(*ADC).CR.bit.START=0;
//	(*ADC).CR.bit.BURST = triggermode;
//	(*ADC).CR.bit.SCMODE=1;		
//	if (triggermode==TRIGGERMODE)
//	{
//		//wait untile adc ready
//		while(!ADC->STAT.bit.ADCRDY );		
//	}
//	return;
//}
/*****************************************************************************
Function Name	ADC_SetTrigger
Function Definition	Void ADC_SetTrigger(uint8_t triggersrc, uint8_t edge)
Function Description	Setup trigger source signal if ADC is in trigger mode
Input Parameters	Triggersrc: select one option
										ADC_TRIGGER_SOFTWAER, 
										ADC_TRIGGER_CT16B2_CAP0, 
										ADC_TRIGGER_CT16B2_CAP1, 
										ADC_TRIGGER_CT16B2_MAT0,
										ADC_TRIGGER_CT16B2_MAT1,
										ADC_TRIGGER_CT16B3_MAT0,
										ADC_TRIGGER_CT16B3_MAT1,
										ADC_TRIGGER_PWM
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetTrigger(G32F_ADC_TypeDef *ADC,uint8_t triggersrc, uint8_t edge)
//{
//	//set up ADC start mode 
//	(*ADC).CR.bit.START = triggersrc;
//	(*ADC).CR.bit.EDGE	= edge;
//	
//	while(!ADC->STAT.bit.ADCRDY );	
//	
//	return;
//}
/*****************************************************************************
Function Name	ADC_SetHighCmp0
Function Definition	void ADC_SetHighCmp0(uint32_t val, uint8_t selchannel)
Function Description	Setup high limit register 0 value and channel to be compare
Input Parameters	val: 	high limit value
									selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetHighCmp0(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel)
//{
//	(*ADC).HILMT.bit.HILMT0 = val;
//	if (selchannel==CHN0)
//		selchannel=0;
//	(*ADC).HILMT.bit.CHNSEL0 = selchannel;
//	return;
//}
/*****************************************************************************
Function Name	ADC_SetHighCmp1
Function Definition	void ADC_SetHighCmp1(uint32_t val, uint8_t selchannel)
Function Description	Setup high limit register 1 value and channel to be compare
Input Parameters		val: high limit value
										selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetHighCmp1(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel)
//{
//	(*ADC).HILMT.bit.HILMT1 = val;
//	if (selchannel==CHN0)
//		selchannel=0;
//	(*ADC).HILMT.bit.CHNSEL1 = selchannel;
//	return;
//}
	
/*****************************************************************************
Function Name	ADC_SetLowCmp0
Function Definition	void ADC_SetLowCmp0(uint32_t val, uint8_t selchannel)
Function Description	Setup low limit register 0 value and channel to be compare
Input Parameters		val: high limit value
										selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetLowCmp0(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel)
//{
//	(*ADC).LOLMT.bit.LOLMT0 = val;
//	if (selchannel==CHN0)
//		selchannel=0;
//	(*ADC).LOLMT.bit.CHNSEL0 = selchannel;
//	return;
//}
/*****************************************************************************
Function Name	ADC_SetLowCmp1
Function Definition	void ADC_SetLowCmp1(uint32_t val, uint8_t selchannel)
Function Description	Setup low limit register 1 value and channel to be compare
Input Parameters			val: high limit value
											selchannel: one of AD0~AD7
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_SetLowCmp1(G32F_ADC_TypeDef *ADC,uint32_t val, uint8_t selchannel)
//{
//	(*ADC).LOLMT.bit.LOLMT1 = val;
//	if (selchannel==CHN0)
//		selchannel=0;
//	(*ADC).LOLMT.bit.CHNSEL1 = selchannel;
//	return;
//}
/*****************************************************************************
Function Name	ADC_EnableConversionInt
Function Definition	Void ADC_EnableConversionInt(uint32_t inttype)
Function Description	Setup conversion completed interrupt
Input Parameters		inttype: combination of interrupt source-
										bit 0~7 related to ADC_DR0~ ADC_DR7 value updated
										bit 8 related ADC global register updated
Return Value	No
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//void ADC_EnableConversionInt(G32F_ADC_TypeDef *ADC,uint32_t inttype)
//{
//	(*ADC).INTEN.all =  inttype;
//	return;
//}
/*****************************************************************************
Function Name	ADC_GetConversionData
Function Definition	uint32_t ADC_GetConversionData(uint8_t dr)
Function Description	Read conversion data 
Input Parameters	dr: data register ADC_DR0~ ADC_DR7
Return Value	Conversion value. If no new value, return 0xFFFF FFFF. GDR value bit 14:12 value represent ADC channel 0~7
Condition	No
Function called	-

Last Chang Date: 2015/09/12	
*****************************************************************************/
//uint32_t ADC_GetConversionData(G32F_ADC_TypeDef *ADC,uint8_t dr)
//{
//	uint32_t DRvalue;
//	do
//	{
//		DRvalue = (*ADC).DR[dr].all;
//	}while(( DRvalue & 0x80000000) == 0);
//		
//	return DRvalue&0xFFF;
//}
void ADC_DeInit(G32F_ADC_TypeDef* ADCx)
{
	if(ADCx == ADC1)
	{
		/* Enable ADC1 reset state */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, ENABLE);
    /* Release ADC1 from reset state */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, DISABLE);
	}
	else if (ADCx == ADC2)
  {
    /* Enable ADC2 reset state */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2, ENABLE);
    /* Release ADC2 from reset state */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2, DISABLE);
  }
  else
  {
    if (ADCx == ADC3)
    {
      /* Enable ADC3 reset state */
      RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3, ENABLE);
      /* Release ADC3 from reset state */
      RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3, DISABLE);
    }
  }
}

void ADC_Init(G32F_ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
{
	switch(ADC_InitStruct->ADC_Mode)
	{
		case ADC_Mode_Independent:
			if(ADC_InitStruct->ADC_ScanConvMode == ENABLE)
			{
				ADCx->CR.bit.BURST = BURSTMODE;
			}
			else
			{
				ADCx->CR.bit.BURST = TRIGGERMODE;
			}
			
			if(ADC_InitStruct->ADC_ContinuousConvMode == ENABLE)
			{
				ADCx->CR.bit.BURST = BURSTMODE;
			}
			else
			{
				ADCx->CR.bit.BURST = TRIGGERMODE;
			}
			
			switch (ADC_InitStruct->ADC_ExternalTrigConv)
			{
//				case ADC_ExternalTrigConv_T1_CC1:
//					
//				break;
//				case ADC_ExternalTrigConv_T1_CC2:
//					
//				break;
//				case ADC_ExternalTrigConv_T2_CC2:
//					
//				break;
//				case ADC_ExternalTrigConv_T3_TRGO:
//					
//				break;
//				case ADC_ExternalTrigConv_T4_CC4:
//					
//				break;
//				case ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO:
//					
//				break;
//				case ADC_ExternalTrigConv_T1_CC3:
//					
//				break;
				case ADC_ExternalTrigConv_None:
					ADCx->CR.bit.START = 1;
				break;
//				case ADC_ExternalTrigConv_T3_CC1:
//					
//				break;
//				case ADC_ExternalTrigConv_T2_CC3:
//					
//				break;
//				case ADC_ExternalTrigConv_T8_CC1:
//					
//				break;
//				case ADC_ExternalTrigConv_T8_TRGO:
//					
//				break;
//				case ADC_ExternalTrigConv_T5_CC1:
//					
//				break;
//				case ADC_ExternalTrigConv_T5_CC3:
//					
//				break;
				default:
					ADCx->CR.bit.START = 0;
			}
			
			
//			ADCx->CR.bit.BURST = BURSTMODE;	
			//select external sample clk
			ADCx->CR.bit.SCMODE=1;
			ADCx->CR.bit.CNVEN=0x1;

			//wait untile adc ready
			while(ADCx->STAT.bit.ADCRDY ==0);
		break;
		case ADC_Mode_RegInjecSimult:
			
		break;
		case ADC_Mode_RegSimult_AlterTrig:
			
		break;
		case ADC_Mode_InjecSimult_FastInterl:
			
		break;
		case ADC_Mode_InjecSimult_SlowInterl:
			
		break;
		case ADC_Mode_InjecSimult:
			
		break;
		case ADC_Mode_RegSimult:
			
		break;
		case ADC_Mode_FastInterl:
			
		break;
		case ADC_Mode_SlowInterl:
			
		break;
		case ADC_Mode_AlterTrig:
			
		break;
	}
}
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(G32F_ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(G32F_ADC_TypeDef* ADCx);
void ADC_StartCalibration(G32F_ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(G32F_ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(G32F_ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(G32F_ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(G32F_ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(G32F_ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(G32F_ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(G32F_ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(G32F_ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(G32F_ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
uint16_t ADC_GetInjectedConversionValue(G32F_ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(G32F_ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(G32F_ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(G32F_ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(G32F_ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(G32F_ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(G32F_ADC_TypeDef* ADCx, uint16_t ADC_IT);


/******************************************************************************
**                            End Of File
******************************************************************************/
