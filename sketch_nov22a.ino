#include <math.h>
void setup(){
  Serial.begin(9600);
}

void loop()
{
  Serial.println("~~~~~~To find angle between hypotenusa and base of triangle~~~~~~");
  Serial.println("\nBase?");
  float x = getFloatFromSerialMonitor();
  Serial.println(x);
  Serial.println("Height?");
  float y = getFloatFromSerialMonitor();
  Serial.println(y);
  Serial.println("Hypotenusa is : ");
  Serial.println(sqrt(x*x+y*y));
  Serial.println("~~~~~~~~~~~");
  Serial.println("Angle is : ");
  Serial.println(asin(y/(sqrt(x*x+y*y)))*(180/3.14));
  Serial.println("~~~~~~~~~~~\n\n");
}

float getFloatFromSerialMonitor(){
  char inData[20];
  float f=0;
  int x=0;
  while(x<1){
    String str;
    if(Serial.available()){
      delay(10);
      int i=0;
      while(Serial.available()>0){
        char inByte = Serial.read();
        str=str+inByte;
        inData[i]=inByte;
        i+=1;
        x=2;
      }
      f = atof(inData);
      memset(inData, 0, sizeof(inData));
    }
  }
  return f;
}
