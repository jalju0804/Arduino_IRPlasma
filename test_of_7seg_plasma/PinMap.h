/*
 * PinMap.h
 *
 * Created: 2023-01-27 오후 11:57:55
 *  Author: dlcks
 
	ERROR_LED: pan 불량, plasma, uvc
	AUTO_LED: 기본 동작(4초) 전원 led랑 같이 켜지는 led
	OZONE: 오존 인풋
	UV_CH: ERROR 받는 곳

	미세먼지: P10, P2.5, P1.0 -> 잠깐 깜빡(2초)

	모델명
	FND:		 TM1650
	오존센서:	 MQ-131-03
	IR :		 tsop34438
	먼지센서:	 AM1008W-K

 */ 
#define  AUTO_LED			2	  //PD2
#define	 PLASMA_LED			A0	  //PC0
#define  FAN_RLED			A1	  //PC1
#define  FAN_BLED			A2	  //PC2
#define  ERROR_LED			A3	  //PC3
#define  PWR_LED			13	  //PB5

#define  SDA				A4	  //PC4			먼지센서 Data
#define  SCL				A5	  //PC5			먼지센서 clock
#define  SDA_FND			11	  //PB3			7segment fnd data
#define  SCL_FND			12	  //PB4			7segment fnd clock

#define  OZONE				A6	  //ADC6
#define  IR					14	  //PB6

#define  DC18_EN			3	  //PD3
#define  PLASMA1_EN			5	  //PD5
#define  PLASMA2_EN			6	  //PD6
#define  FAN1_EN			9	  //PB1
#define  UV_EN				15	  //PB7

#define  PLASMA1_CH			7	  //PD7
#define  FAN1_CH			10	  //PB2 
#define  PLASMA2_CH			8	  //PB0
#define  UV_CH				4	  //PD4

#define dust_address        0x50  // 쓰기시에 해당하는 data

//0x24 // command
//0x34 - 0x37	 //display	

//#define  RXD			    0     // PD0
//#define  TXD				1     // PD1
//#define  RESET				2	  // PD2


//IR 리모콘
//
// 1					2				    3(2690629695) 0.3초
// 4					5(2690621535)ON/OFF 6
// 7					8					9
// 10(?)				11(?)				12(?)
// 13(2690625615)1초    14					15(2690641935)4초
// 16(2690615415)6초		17					18(2690631735)8초
