#define pinRightPwn 5
#define pinLeftPwn 6

const byte pinLeftM1 = 8;
const byte pinLeftM2 = 9;


const byte pinRightM1 = 12;
const byte pinRightM2 = 13;


int pwnL = 0;
int ch1 = 2;
int ch2 = 3;
int ch3 = 7;
int relay1 = 4;

unsigned int speeder = 0;
unsigned long dura;
unsigned long dura2;
unsigned long dura3;

void setup() {
pinMode(ch1,INPUT);
pinMode(ch2,INPUT);
pinMode(pinLeftPwn , OUTPUT);
pinMode(pinRightPwn , OUTPUT);

pinMode(relay1 , OUTPUT);

pinMode(pinLeftM1,OUTPUT);
pinMode(pinLeftM2,OUTPUT);
pinMode(pinRightM1 , OUTPUT);
pinMode(pinRightM2 , OUTPUT);
Serial.begin(9600);

analogWrite(pinLeftPwn,0);
analogWrite(pinRightPwn,0);
  
}

void loop() {

 dura2 = pulseIn(ch2,HIGH);
 dura = pulseIn(ch1,HIGH);

 dura3 = pulseIn(ch3,HIGH);

 Serial.println(dura3);

 if(dura3 > 1901){
  
  digitalWrite(relay1,HIGH);
  
  
  }


  if(dura3 < 1600){
  
  digitalWrite(relay1,LOW);
  
  
  }



  
//FORWARD

//G1
if(dura > 1500 && dura < 1700){
  
  pwnL = 50;
analogWrite(pinLeftPwn,20);
analogWrite(pinRightPwn,20);

digitalWrite(pinRightM1,HIGH);
digitalWrite(pinRightM2,LOW);

digitalWrite(pinLeftM1,LOW);
digitalWrite(pinLeftM2,HIGH);
  
  
  }
//G2

  if(dura > 1701 && dura < 1800){
  
  pwnL = 50;
analogWrite(pinLeftPwn,40);
analogWrite(pinRightPwn,40);

digitalWrite(pinRightM1,HIGH);
digitalWrite(pinRightM2,LOW);

digitalWrite(pinLeftM1,LOW);
digitalWrite(pinLeftM2,HIGH);
  
  
  }
//G3
   if(dura > 1801){
  
  pwnL = 50;
analogWrite(pinLeftPwn,90);
analogWrite(pinRightPwn,90);

digitalWrite(pinRightM1,HIGH);
digitalWrite(pinRightM2,LOW);

digitalWrite(pinLeftM1,LOW);
digitalWrite(pinLeftM2,HIGH);
  
  
  }



 //BACKWARD 
if(dura < 1380){
  
  pwnL = 50;
analogWrite(pinLeftPwn,60);
analogWrite(pinRightPwn,60);

digitalWrite(pinRightM1,LOW);
digitalWrite(pinRightM2,HIGH);

digitalWrite(pinLeftM1,HIGH);
digitalWrite(pinLeftM2,LOW);
  
  
  }

//turnLeft
  if(dura2 < 1380){
  
  
analogWrite(pinLeftPwn,80);
analogWrite(pinRightPwn,80);

digitalWrite(pinRightM1,HIGH);
digitalWrite(pinRightM2,LOW);

digitalWrite(pinLeftM1,LOW);
digitalWrite(pinLeftM2,LOW);
  
  
  }

//turnrigth
  if(dura2> 1500){
  
  pwnL = 50;
analogWrite(pinLeftPwn,80);
analogWrite(pinRightPwn,80);

digitalWrite(pinRightM1,LOW);
digitalWrite(pinRightM2,LOW);

digitalWrite(pinLeftM1,LOW);
digitalWrite(pinLeftM2,HIGH);
  
  
  }



  //stop
if(dura < 1500 && dura >1400&&dura2 < 1500 && dura2 >1400){
  
  pwnL = 0;
analogWrite(pinLeftPwn,0);
analogWrite(pinRightPwn,0);

digitalWrite(pinRightM1,LOW);
digitalWrite(pinRightM2,HIGH);

digitalWrite(pinLeftM1,HIGH);
digitalWrite(pinLeftM2,LOW);
  
  
  }


  
 
}
