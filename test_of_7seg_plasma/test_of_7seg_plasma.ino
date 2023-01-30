#include <IRremote.h>
#include <EEPROM.h>
#include <TM1650.h>
#include "PinMap.h"

IRrecv  irrecv(99);

//IRrecv irrecv(PB6);  // 적외선 센서 핀 D7에 연결
decode_results results; // 적외선 수신번호를 저장할 값입니다.


TM1650 module(SDA_FND, SCL_FND);  // SDA=A4, SCL=A5

void p1dot0(){
	module.clearDisplay();
	module.setDisplayToString("P10");
	module.setDisplayDigit(1,1,true); // digit, pos, dot 0 1 2순서
}

void p2dot5(){
	module.clearDisplay();
	module.setDisplayToString("P10");
	module.setDisplayDigit(2,1,true);
}

void receiveIR(){
	if(irrecv.decode(&results)){ //적외선 신호 해석합니다.
		Serial.println(results.value); // 적외선 신호값을 출력
		irrecv.resume();        //계속해서 다음 신호 받기
	}
}

void setup()
{
	 irrecv.enableIRIn();  //적외선 센서 활성화
	  Serial.begin(14400);   //시리얼 프린트를 시작합니다
	  Serial.println("Connect!");
}

void loop()
{
	Serial.println("Connect!");
	if(irrecv.decode(&results)){ //적외선 신호 해석합니다.
		Serial.println(results.value); // 적외선 신호값을 출력
		irrecv.resume();        //계속해서 다음 신호 받기
	}
}