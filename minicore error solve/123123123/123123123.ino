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
  FND:     TM1650
  오존센서:  MQ-131-03
  IR :     tsop34438
  먼지센서:  AM1008W-K

 */ 
#define  AUTO_LED     26    //ADC7 = 26
#define  PLASMA_LED     A0    //PC0
#define  FAN_RLED     A1    //PC1
#define  FAN_BLED     A2    //PC2
#define  ERROR_LED      A3    //PC3
#define  PWR_LED      13    //PB5

#define  SDA        A4    //PC4     먼지센서 Data
#define  SCL        A5    //PC5     먼지센서 clock
#define  SDA_FND      11    //PB3     7segment fnd data
#define  SCL_FND      12    //PB4     7segment fnd clock

#define  OZONE        A6    //ADC6, PE2(25)
#define  IR         20    //PB6 

#define  DC18_EN      3   //PD3
#define  PLASMA1_EN     5   //PD5
#define  PLASMA2_EN     6   //PD6
#define  FAN1_EN      9   //PB1
#define  UV_EN        21    //PB7

#define  PLASMA1_CH     7   //PD7
#define  FAN1_CH      10    //PB2 
#define  PLASMA2_CH     8   //PB0
#define  UV_CH        4   //PD4

//IR 리모콘
//
// 1          2           3(2690629695) 0.3초
// 4          5(2690621535)ON/OFF 6
// 7          8         9
// 10(2690601135)4초   11(2690633775)0.3초  12(2690592975)풍향
// 13(2690625615)1초    14         15(2690641935)4초
// 16(2690615415)6초   17          18(2690631735)8초

#define IR_Button_1     2690613375
#define IR_Button_2     2690597055
#define IR_Button_3     2690629695 // 0.3초 for test
#define IR_Button_4     2690588895
#define IR_Button_5     2690621535// ON/OFF
#define IR_Button_6     2690605215
#define IR_Button_7     2690637855
#define IR_Button_8     2690584815
#define IR_Button_9     2690617455
#define IR_Button_10    2690601135 // 4초 
#define IR_Button_11    2690633775 // 0.3초(살균)
#define IR_Button_12    2690592975 // 풍향 설정
#define IR_Button_13    2690625615  // 1초 for test
#define IR_Button_14    2690609295 
#define IR_Button_15    2690641935 // 4초 for test
#define IR_Button_16    2690615415 // 6초 for test
#define IR_Button_17    2690599095
#define IR_Button_18    2690631735 // 8초 for test
#define IR_PRESSN       4294967295

enum plasma {plasma_on, plasma_off }; 
enum WindDirection {wind_off, low, mid, hi};
  
#define N_PLASMA_ZEORTHR_PERIOD     300 // 300ms = 0.3sec
#define N_PLASMA_ZEORTHR_DUTY     20   // 20ms
#define N_PLASMA_ONE_PERIOD       1000 // 1000ms = 1sec
#define N_PLASMA_ONE_DUTY       20
#define N_PLASMA_FOUR_PERIOD      4000 // 4000ms = 4sec
#define N_PLASMA_FOUR_DUTY        20  
#define N_PLASMA_SIX_PERIOD       6000 // 6000ms = 6sec
#define N_PLASMA_SIX_DUTY       20
#define N_PLASMA_EIGHT_PERIOD     8000 // 8000ms = 8sec
#define N_PLASMA_EIGHT_DUTY       20

#define N_SEGMENT_PERIOD        2000 // 2000ms = 2sec
#define N_SEGMENT_DUTY          1000 // 1000ms = 1sec

#define N_3MIN_PUSHING          20 // test result = 20 is 3sec

#define N_FAN_OFF           0
#define N_FAN_LOW           220
#define N_FAN_HIGH            180
#define N_FAN_MIDDLE          255

#define N_ONE             1000 //  1000ms  1 2ms
#define N_FIVE            5000 //  5000ms  
#define N_1M              60000 // 1분

// #define IR_Button_1      1150994816
// #define IR_Button_2      1315868256
// #define IR_Button_3      1429348068 // 0.3초 for test
// #define IR_Button_4      988954368
// #define IR_Button_5      2860379396// ON/OFF
// #define IR_Button_6      2162454172
// #define IR_Button_7      2275933984
// #define IR_Button_8      1330509664
// #define IR_Button_9      3201934692
// #define IR_Button_10   2247725380 // 4초
// #define IR_Button_11   1183266304 // 0.3초(살균)
// #define IR_Button_12   2672248356 // 풍향 설정
// #define IR_Button_13   248706088  // 1초 for test
// #define IR_Button_14   3845748160
// #define IR_Button_15   3959227972 // 4초 for test
// #define IR_Button_16   3789392900 // 6초 for test
// #define IR_Button_17   3100069276
// #define IR_Button_18   1770724512 // 8초 for test

#define  OZON_SENSOR_OFF_VALUE    0.03f // 0.03 ppm 이상일 경우,  플라즈마 Off
#define  OZON_SENSOR_ONN_VALUE    0.02f // 0.02 ppm 이하일 경우,  플라즈마 On....

#include <IRremote.h>
#include "MQ131.h"
#include "am1008w_k_i2c.h"
#include "TM16xx.h"
#include "TM1650.h"


volatile bool Power = false;
volatile unsigned char plasma_flag = plasma_off;
volatile unsigned char wind_flag = wind_off;
volatile unsigned char segement_flag = 0;

volatile uint16_t plasma_period = 0;
volatile uint16_t plasma_duty = 0;
volatile uint16_t plasma_cnt = 0;

volatile uint16_t segment_cnt = 0;
volatile uint16_t O3_cnt = 0;

volatile int  p1dot0;
volatile int  p2dot5;
volatile int  p10;
volatile float humidity;
volatile float temperature;
volatile uint16_t dust_cnt = 2499;

volatile int tmp;
volatile bool TimePush = false;
volatile uint16_t push_cnt = 0;

float ozSensorRdValue = 0.001;

TM1650 module(SDA_FND, SCL_FND);  // SDA=A4, SCL=A5
AM1008W_K_I2C am1008w_k_i2c;
IRrecv irrecv(IR);  // 적외선 센서
decode_results results; // 적외선 수신번호를 저장할 값입니다.

void Read_dust_value()
{
  if(++dust_cnt == 2 * N_FIVE)
  {
    dust_cnt = 0;
    uint8_t ret = am1008w_k_i2c.read_data_command();
    if (ret == 0)
    {
      p1dot0 = am1008w_k_i2c.get_pm1p0();
      p2dot5 = am1008w_k_i2c.get_pm2p5();
      p10 = am1008w_k_i2c.get_pm10();
      humidity = am1008w_k_i2c.get_humidity()*10;
      temperature = am1008w_k_i2c.get_temperature()*10;
    }
  }
}

void setSegmentFloat(float input,bool sign){
  module.clearDisplay();
  int tmp = (int)input;
  module.setDisplayToDecNumber(tmp%100,2); // 값, 위치
  tmp = tmp/10;
  module.setDisplayDigit(tmp%10,1,true);// 원하는 값, 위치, dot 찍을거임?
  tmp = tmp/10;
  module.setDisplayDigit(tmp,0,false); // 3번 자리에 숫자 2설정, 퍼센트
  
  if(sign) module.setDisplayDigit(1,3,false); // 퍼센트
  else module.setDisplayDigit(5,3,false); // 온도
}

void setSegmentInt(int input){
  module.clearDisplay();
  Serial.print("setsegmentInt: ");
  Serial.println(tmp);
  tmp = input;
  module.setDisplayDigit(tmp % 10,2,false); // 값, 위치
  if(input > 9)
  {
    tmp = tmp/10;
    Serial.print("setsegmentInt: ");
    Serial.println(tmp);
    module.setDisplayDigit(tmp%10,1,false);// 원하는 값, 위치, dot 찍을거임?
    if(input > 99)
    {
      tmp = tmp/10;
      Serial.print("setsegmentInt: ");
      Serial.println(tmp);
      module.setDisplayDigit(tmp,0,false);
    }
  }
  
}
void SegmentControl()
{
  if(N_SEGMENT_PERIOD == ++segment_cnt){
    segement_flag++;
    segment_cnt = 0;
    if(segement_flag > 4) segement_flag = 0;
  }
  
  if(segement_flag == 0){ // PM1.0
    if(1 == segment_cnt)
    {
      module.clearDisplay();
      module.setDisplayToString("P10");
      module.setDisplayDigit(1,1,true); // digit, pos, dot 0 1 2순서
    }
    if(N_SEGMENT_DUTY == segment_cnt) {
      Serial.print("pm1.0: ");
      Serial.println(p1dot0);
      setSegmentInt(p1dot0);
    }
    }else if(segement_flag == 1){ // PM2.5
    if(0 == segment_cnt){
      module.clearDisplay();
      module.setDisplayToString("P25");
      module.setDisplayDigit(2,1,true);
    }
    if(N_SEGMENT_DUTY == segment_cnt) {
      Serial.print("pm2.5: ");
      Serial.println(p2dot5);
      setSegmentInt(p2dot5);
    }
    }else if(segement_flag == 2){ // PM10
    if(0 == segment_cnt){
      module.clearDisplay();
      module.setDisplayToString("P10");
    }
    if(N_SEGMENT_DUTY == segment_cnt) {
      Serial.print("pm10: ");
      Serial.println(p10);
      setSegmentInt(p10);
    }
    }else if(segement_flag == 3){ // 습도
    if(segment_cnt == 0){
      Serial.print("humidity: ");
      Serial.println(humidity);
      
      setSegmentFloat(humidity,1); // 1-> 퍼센트 나타내기 2
    }
    }else if(segement_flag == 4){ // 온도
    if(segment_cnt == 0){
      Serial.print("temperature: ");
      Serial.println(temperature);
      
      setSegmentFloat(temperature,0); //0-> 섭씨온도 기호 나타내기
    }
    
  }
}

void ReceiveIR(){
  if(irrecv.decode(&results)){ //적외선 신호 해석합니다.
    Serial.println(results.value); // 적외선 신호값을 출력
    if(results.value == IR_PRESSN && TimePush)
    {
      Serial.print("push_cnt : ");
      Serial.println(push_cnt);
      if(++push_cnt == N_3MIN_PUSHING){
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_ZEORTHR_DUTY;
        plasma_period = N_PLASMA_ZEORTHR_PERIOD;
        if(Power){
        digitalWrite(AUTO_LED,0);
        digitalWrite(PLASMA_LED,1);
        }
      }
    }else if(push_cnt) push_cnt = 0;
    switch(results.value)
    {
      case IR_Button_3:  // 0.3초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_ZEORTHR_DUTY;
        plasma_period = N_PLASMA_ZEORTHR_PERIOD;
        if(Power){
          digitalWrite(AUTO_LED,0);
          digitalWrite(PLASMA_LED,1);
        }
      break;
      case IR_Button_5:  // on/off
        Power = !Power;
        if(Power){
          plasma_flag = plasma_on;
          digitalWrite(PWR_LED,1);
          digitalWrite(AUTO_LED,1);
          digitalWrite(UV_EN,1);
          wind_flag = low;
          plasma_cnt = 0;
          plasma_duty = N_PLASMA_FOUR_DUTY;
          plasma_period = N_PLASMA_FOUR_PERIOD;
          segement_flag = 0;
          segment_cnt = 0;
          }else{
          plasma_flag = plasma_off;
          digitalWrite(AUTO_LED,0);
          digitalWrite(UV_EN,0);
          digitalWrite(FAN1_EN,0);
          digitalWrite(DC18_EN,0);
          digitalWrite(PWR_LED,0);
          digitalWrite(PLASMA_LED,0);
          wind_flag = wind_off;
          module.clearDisplay();
        }
        WindDirectionControl();
      break;
      case IR_Button_10:  // 4초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_FOUR_DUTY;
        plasma_period = N_PLASMA_FOUR_PERIOD;
        if(Power){
          digitalWrite(AUTO_LED,1);
          digitalWrite(PLASMA_LED,0);
        }
      break;
      case IR_Button_11:  // 0.3초(살균)
        TimePush = true;
      break;
      case IR_Button_12:  // 풍향 설정
        if(Power){
          if(++wind_flag > 3) wind_flag = 1;
          WindDirectionControl();
        }
      break;
      case IR_Button_13:  // 1초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_ONE_DUTY;
        plasma_period = N_PLASMA_ONE_PERIOD;
      break;
      case IR_Button_15:  // 4초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_FOUR_DUTY;
        plasma_period = N_PLASMA_FOUR_PERIOD;
      break;
      case IR_Button_16:  // 6초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_SIX_DUTY;
        plasma_period = N_PLASMA_SIX_PERIOD;
      break;
      case IR_Button_18:  // 8초
        plasma_cnt = 0;
        plasma_duty = N_PLASMA_EIGHT_DUTY;
        plasma_period = N_PLASMA_EIGHT_PERIOD;
      break;
    }
    irrecv.resume();        //계속해서 다음 신호 받기
  }
}

void WindDirectionControl(){
  switch(wind_flag){
    case wind_off:
      digitalWrite(FAN_BLED,0);
      digitalWrite(FAN_RLED,0);
      analogWrite(FAN1_EN,N_FAN_OFF);
    break;
    case low:
      digitalWrite(FAN_BLED,1);
      digitalWrite(FAN_RLED,1);
      analogWrite(FAN1_EN,N_FAN_LOW);
    break;
    case mid:
      digitalWrite(FAN_RLED,0);
      analogWrite(FAN1_EN,N_FAN_MIDDLE);
    break;
    case hi:
      digitalWrite(FAN_BLED,0);
      digitalWrite(FAN_RLED,1);
      analogWrite(FAN1_EN,N_FAN_HIGH);
    break;
  }
}

void PlasmaControl(){
  switch(plasma_flag)
  {
    case plasma_on:
    digitalWrite(DC18_EN,1);
    plasma_cnt++;
    if(plasma_duty == plasma_cnt) {
      digitalWrite(PLASMA1_EN,0);
      digitalWrite(PLASMA2_EN,0);
    }
    if(plasma_period == plasma_cnt){
      digitalWrite(PLASMA1_EN,1);
      digitalWrite(PLASMA2_EN,1);
      plasma_cnt = 0;
    }
    break;
    case plasma_off:
    digitalWrite(DC18_EN,0);
    digitalWrite(PLASMA1_EN,0);
    digitalWrite(PLASMA2_EN,0);
    break;
  }
}

void CheckO3(){
  if(++O3_cnt > N_1M)
  {
    O3_cnt = 0;
    Serial.println("Reading...");
    MQ131.sample();

    Serial.print("O3 Value:"); // oz 신호값을 출력
    ozSensorRdValue = MQ131.getO3(PPM);
    Serial.print(ozSensorRdValue); // oz 신호값을 출력
    Serial.print("Concentration O3 : ");
    Serial.print(MQ131.getO3(PPB));
    Serial.println(" ppb");
    Serial.print("Concentration O3 : ");
    Serial.print(MQ131.getO3(MG_M3));
    Serial.println(" mg/m3");
    Serial.print("Concentration O3 : ");
    Serial.print(MQ131.getO3(UG_M3));
    Serial.println(" ug/m3");
    if(MQ131.getR0() >= 10000.00f){
      plasma_flag = plasma_off;
      }else{
      if (ozSensorRdValue >= 0)
      {
        if (ozSensorRdValue >= OZON_SENSOR_OFF_VALUE)
        {
          plasma_flag = plasma_off;
          Serial.println("Plazma Off...");
        }
        else
        {
          plasma_flag = plasma_on;
        }
      }
    }
  }
  
}

void setup()
{
  Serial.begin(19200);   //시리얼 프린트를 시작합니다
  Serial.println("motor speed...");
  TCCR1B = TCCR1B & B11111000 | B00000010; // for PWM frequency of 3921.16 Hz
  
  Serial.println("am1008w start...");
  am1008w_k_i2c.begin(); // 0x50
  //am1008w_k_i2c.pm_sensor_mode_cotinuously_measurement();
  Serial.println("ir start...");
  irrecv.enableIRIn();  //적외선 센서 활성화
  Serial.println("mq131 start...");
  MQ131.begin(DC18_EN, OZONE, LOW_CONCENTRATION, 1000000);
  MQ131.setR0(977.52);
  MQ131.setTimeToRead(0);
  
  Serial.println("pin config start...");
  pinMode(FAN1_EN,OUTPUT);
  pinMode(DC18_EN, OUTPUT);
  pinMode(PLASMA1_EN,OUTPUT);
  pinMode(PLASMA2_EN,OUTPUT);
  pinMode(AUTO_LED,OUTPUT);
  pinMode(FAN1_EN, OUTPUT);
  pinMode(PWR_LED, OUTPUT);
  pinMode(FAN_RLED,OUTPUT);
  pinMode(FAN_BLED,OUTPUT);
  pinMode(PLASMA_LED,OUTPUT);
  pinMode(UV_EN,OUTPUT);
  module.clearDisplay();
  
  pinMode(PLASMA1_CH,INPUT);
  pinMode(FAN1_CH,INPUT);
  pinMode(PLASMA2_CH,INPUT);
  pinMode(UV_CH,INPUT);
  Serial.println("end...");
}

void loop()
{
  ReceiveIR();
  if(Power){
    PlasmaControl();
    SegmentControl();
    Read_dust_value();
    CheckO3();
  }
  delay(1);
}
