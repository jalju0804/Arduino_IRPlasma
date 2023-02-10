/*
 * PinMap.h
 *
 * Created: 2023-01-27 오후 11:57:55
 *  Author: dev
 
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

#define  OZONE				A6	  //ADC6, PE2(25)
#define  IR					20	  //PB6 PB7(21)

#define  DC18_EN			3	  //PD3
#define  PLASMA1_EN			5	  //PD5
#define  PLASMA2_EN			6	  //PD6
#define  FAN1_EN			9	  //PB1
#define  UV_EN				21	  //PB7

#define  PLASMA1_CH			7	  //PD7
#define  FAN1_CH			10	  //PB2 
#define  PLASMA2_CH			8	  //PB0
#define  UV_CH				4	  //PD4

//IR 리모콘
//
// 1					2				    3(2690629695) 0.3초
// 4					5(2690621535)ON/OFF 6
// 7					8					9
// 10(2690601135)4초		11(2690633775)0.3초	12(2690592975)풍향
// 13(2690625615)1초    14					15(2690641935)4초
// 16(2690615415)6초		17					18(2690631735)8초

#define IR_Button_1			2690613375
#define IR_Button_2			2690597055
#define IR_Button_3			2690629695 // 0.3초 for test
#define IR_Button_4			2690588895
#define IR_Button_5			2690621535// ON/OFF
#define IR_Button_6			2690605215
#define IR_Button_7			2690637855
#define IR_Button_8			2690584815
#define IR_Button_9			2690617455
#define IR_Button_10		2690601135 // 4초 
#define IR_Button_11		2690633775 // 0.3초(살균)
#define IR_Button_12		2690592975 // 풍향 설정
#define IR_Button_13		2690625615  // 1초 for test
#define IR_Button_14		2690609295 
#define IR_Button_15		2690641935 // 4초 for test
#define IR_Button_16		2690615415 // 6초 for test
#define IR_Button_17		2690599095
#define IR_Button_18		2690631735 // 8초 for test

enum plasma {plasma_on, plasma_off }; 
enum WindDirection {wind_off, low, mid, hi};
	
#define N_PLASMA_ZEORTHR_PERIOD			150 // 300ms = 0.3sec
#define N_PLASMA_ZEORTHR_DUTY			10   // 20ms
#define N_PLASMA_ONE_PERIOD				500 // 1000ms = 1sec
#define N_PLASMA_ONE_DUTY				10
#define N_PLASMA_FOUR_PERIOD			2000 // 4000ms = 4sec
#define N_PLASMA_FOUR_DUTY				10	
#define N_PLASMA_SIX_PERIOD				3000 // 6000ms = 6sec
#define N_PLASMA_SIX_DUTY				10
#define N_PLASMA_EIGHT_PERIOD			4000 // 6000ms = 6sec
#define N_PLASMA_EIGHT_DUTY				10

#define N_SEGMENT_PERIOD				1000 // 2000ms = 2sec
#define N_SEGMENT_DUTY					500 // 1000ms = 1sec

#define N_FAN_OFF						0
#define N_FAN_LOW						220
#define N_FAN_HIGH						180
#define N_FAN_MIDDLE					255

#define N_ONE							500 //  1000ms  1 2ms
#define N_FIVE						   2500 //  5000ms  
#define N_1M						  30000 // 1분

// #define IR_Button_1			1150994816
// #define IR_Button_2			1315868256
// #define IR_Button_3			1429348068 // 0.3초 for test
// #define IR_Button_4			988954368
// #define IR_Button_5			2860379396// ON/OFF
// #define IR_Button_6			2162454172
// #define IR_Button_7			2275933984
// #define IR_Button_8			1330509664
// #define IR_Button_9			3201934692
// #define IR_Button_10		2247725380 // 4초
// #define IR_Button_11		1183266304 // 0.3초(살균)
// #define IR_Button_12		2672248356 // 풍향 설정
// #define IR_Button_13		248706088  // 1초 for test
// #define IR_Button_14		3845748160
// #define IR_Button_15		3959227972 // 4초 for test
// #define IR_Button_16		3789392900 // 6초 for test
// #define IR_Button_17		3100069276
// #define IR_Button_18		1770724512 // 8초 for test

#define  OZON_SENSOR_OFF_VALUE		0.03f	// 0.03 ppm 이상일 경우,  플라즈마 Off
#define  OZON_SENSOR_ONN_VALUE		0.02	// 0.02 ppm 이하일 경우,  플라즈마 On....
