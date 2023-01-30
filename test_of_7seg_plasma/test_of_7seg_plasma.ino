#include <IRremote.h>
#include <EEPROM.h>
#include <TM1650.h>
#include "PinMap.h"

IRrecv  irrecv(99);

//IRrecv irrecv(PB6);  // ���ܼ� ���� �� D7�� ����
decode_results results; // ���ܼ� ���Ź�ȣ�� ������ ���Դϴ�.


TM1650 module(SDA_FND, SCL_FND);  // SDA=A4, SCL=A5

void p1dot0(){
	module.clearDisplay();
	module.setDisplayToString("P10");
	module.setDisplayDigit(1,1,true); // digit, pos, dot 0 1 2����
}

void p2dot5(){
	module.clearDisplay();
	module.setDisplayToString("P10");
	module.setDisplayDigit(2,1,true);
}

void receiveIR(){
	if(irrecv.decode(&results)){ //���ܼ� ��ȣ �ؼ��մϴ�.
		Serial.println(results.value); // ���ܼ� ��ȣ���� ���
		irrecv.resume();        //����ؼ� ���� ��ȣ �ޱ�
	}
}

void setup()
{
	 irrecv.enableIRIn();  //���ܼ� ���� Ȱ��ȭ
	  Serial.begin(14400);   //�ø��� ����Ʈ�� �����մϴ�
	  Serial.println("Connect!");
}

void loop()
{
	Serial.println("Connect!");
	if(irrecv.decode(&results)){ //���ܼ� ��ȣ �ؼ��մϴ�.
		Serial.println(results.value); // ���ܼ� ��ȣ���� ���
		irrecv.resume();        //����ؼ� ���� ��ȣ �ޱ�
	}
}