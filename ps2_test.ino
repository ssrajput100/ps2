/*tri omni wheel
                                 M1
                               _ _ _   
                                / \
                               /   \
                             \/_\/
                              \     /
                             M2      M3

+ve-in1 -ve-in2 -- clockwise

*/                           
#include <stdlib.h>
#include <PS2X_lib.h>   
PS2X ps2x;

#define m1pin1 A1 
#define m1pin2 A2
#define m1pwm 3

#define m2pin1 4
#define m2pin2 A0
#define m2pwm 6

#define m3pin1 7
#define m3pin2 11
#define m3pwm 5

int psclock=9;
int pscommand=8;
int psattention=10;
int psdata=12;

int error=0;
byte type=0;

int m1speed=56;
int m2speed=62;
int m3speed=80;

int xin=0,yin=0,speedx=0,speedy=0,pos1=0,pos2=0;

void setup() 
{
  pinMode(m1pin1,OUTPUT);
  pinMode(m1pin2,OUTPUT);
  pinMode(m1pwm,OUTPUT);
  
  pinMode(m2pin1,OUTPUT);
  pinMode(m2pin2,OUTPUT);
  pinMode(m2pwm,OUTPUT);
  
  pinMode(m3pin1,OUTPUT);
  pinMode(m3pin2,OUTPUT);
  pinMode(m3pwm,OUTPUT);

  Serial.begin(57600);
 
  error=ps2x.config_gamepad(psclock,pscommand,psattention,psdata, true, true);   //GamePad(clock, command, attention, data, Pressures?, Rumble?) 
  if(error==0)
    Serial.println("Found Controller, configured successful");
  
  type=ps2x.readType();
  if(type==1)
    Serial.println("DualShock Controller Found");
}
 
void loop() 
{
  ps2x.read_gamepad();
  if(ps2x.Button(PSB_PAD_UP))
    {
      digitalWrite(m2pin1,HIGH);
      digitalWrite(m2pin2,LOW);
      analogWrite(m2pwm,m2speed);
   
      digitalWrite(m3pin1,LOW);
      digitalWrite(m3pin2,HIGH);
      analogWrite(m3pwm,m3speed);
      
      digitalWrite(m1pin1,LOW);
      digitalWrite(m1pin2,LOW);
      
      Serial.println("Going Front");
    }
    else if(ps2x.Button(PSB_PAD_DOWN))
    {
      digitalWrite(m2pin1,LOW);
      digitalWrite(m2pin2,HIGH);
      analogWrite(m2pwm,m2speed);
      
      digitalWrite(m3pin1,HIGH);
      digitalWrite(m3pin2,LOW);
      analogWrite(m3pwm,m3speed);
      
      digitalWrite(m1pin1,LOW);
      digitalWrite(m1pin2,LOW);
      
      Serial.println("Going Back");
    }
    else if(ps2x.Button(PSB_PAD_LEFT))
    {
      digitalWrite(m2pin1,LOW);
      digitalWrite(m2pin2,HIGH);
      analogWrite(m2pwm,m2speed/2);
      
      digitalWrite(m3pin1,LOW);
      digitalWrite(m3pin2,HIGH);
      analogWrite(m3pwm,m3speed/2);
      
      digitalWrite(m1pin1,HIGH);
      digitalWrite(m1pin2,LOW);
      analogWrite(m1pwm,m1speed);
      
      Serial.println("Going Left");
    }
    else if(ps2x.Button(PSB_PAD_RIGHT))
    {
      digitalWrite(m2pin1,HIGH);
      digitalWrite(m2pin2,LOW);
      analogWrite(m2pwm,m2speed/2);
      
      digitalWrite(m3pin1,HIGH);
      digitalWrite(m3pin2,LOW);
      analogWrite(m3pwm,m3speed/2);
      
      digitalWrite(m1pin1,LOW);
      digitalWrite(m1pin2,HIGH);
      analogWrite(m1pwm,m1speed);
      
      Serial.println("Going Right");
    }
    else if(ps2x.Button(PSB_L3))
    {
      digitalWrite(m2pin1,HIGH);
      digitalWrite(m2pin2,LOW);
      analogWrite(m2pwm,m2speed/2);
      
      digitalWrite(m3pin1,HIGH);
      digitalWrite(m3pin2,LOW);
      analogWrite(m3pwm,m3speed/2);
      
      digitalWrite(m1pin1,HIGH);
      digitalWrite(m1pin2,LOW);
      analogWrite(m1pwm,m1speed/2);
      
    }
    else if(ps2x.Button(PSB_R3))
    {
      digitalWrite(m2pin1,LOW);
      digitalWrite(m2pin2,HIGH);
      analogWrite(m2pwm,m2speed/2);
      
      digitalWrite(m3pin1,LOW);
      digitalWrite(m3pin2,HIGH);
      analogWrite(m3pwm,m3speed/2);
      
      digitalWrite(m1pin1,LOW);
      digitalWrite(m1pin2,HIGH);
      analogWrite(m1pwm,m1speed/2);
      
    }
    else
    {
      digitalWrite(m2pin1,HIGH);
      digitalWrite(m2pin2,HIGH);
      analogWrite(m2pwm,m2speed);
      
      digitalWrite(m3pin1,HIGH);
      digitalWrite(m3pin2,HIGH);

      digitalWrite(m1pin1,HIGH);
      digitalWrite(m1pin2,HIGH);
      

      Serial.println("stop");
    }
    delay(50);
}
