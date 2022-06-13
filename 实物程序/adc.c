/*------------------------------------------------------------------*/
/* --- STC MCU Limited ---------------------------------------------*/
/* --- STC12C5Axx Series MCU A/D Conversion Demo -------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966----------------------*/
/* --- Web: www.STCMCU.com -----------------------------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/


#include "intrins.h"

#define FOSC    11059200L
#define BAUD    9600

typedef unsigned char BYTE;
typedef unsigned int WORD;

///*Declare SFR associated with the ADC */
//sfr ADC_CONTR   =   0xBC;           //ADC control register
//sfr ADC_RES     =   0xBD;           //ADC high 8-bit result register
//sfr ADC_LOW2    =   0xBE;           //ADC low 2-bit result register
//sfr P1ASF       =   0x9D;           //P1 secondary function control register


/*Define ADC operation const for ADC_CONTR*/
#define ADC_POWER   0x80            //ADC power control bit
#define ADC_FLAG    0x10            //ADC complete flag
#define ADC_START   0x08            //ADC start control bit
#define ADC_SPEEDLL 0x00            //420 clocks
#define ADC_SPEEDL  0x20            //280 clocks
#define ADC_SPEEDH  0x40            //140 clocks
#define ADC_SPEEDHH 0x60            //70 clocks


void InitADC();

BYTE GetADCResult(BYTE ch);
void Delay(WORD n);




/*----------------------------
Get ADC result
----------------------------*/
BYTE GetADCResult(BYTE ch)
{
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        //Must wait before inquiry
    _nop_();
    _nop_();
    _nop_();
    while (!(ADC_CONTR & ADC_FLAG));//Wait complete flag
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC

    return ADC_RES;                 //Return ADC result
}



/*----------------------------
Initial ADC sfr
----------------------------*/
void InitADC()
{
    P1ASF = 0x40;                   //Open 8 channels ADC function
    ADC_RES = 0;                    //Clear previous result
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
    Delay(2);                       //ADC power-on and delay
}





