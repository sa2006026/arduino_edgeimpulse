#include "uFire_SHT20.h"
uFire_SHT20 sht20;
float currentH[122], perviousH[122];
int i = 0;
float trigger = 0.2;
int sTime, timer;
float startTime, timerTime;
float derivative = 0;
float dT ;
int endPt = 10;
float start = 0;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  sht20.begin();
}

void loop()
{
  for(i=0; i < endPt; i++){
    currentH[i] = sht20.humidity();
    Serial.print( currentH[i]);
    Serial.print(" , ");
    if(i == 0){
      start = millis();
    }
    if(i == (endPt-1)){
      dT = (millis()-start)/1000;
      Serial.print(millis());
    }
  }
   derivative = (currentH[i-1] - currentH[0])/dT ;
   Serial.print(start);
   Serial.print(dT); ////(show the dT)
   Serial.print(",");
   Serial.print(derivative);
   
   if (derivative >= trigger) {
    sTime++;
  }
   if(sTime == 1){
    startTime = millis();
    timer++;
  }
  if(timer >0){
    timerTime = (millis()- startTime)/1000;
  }

  Serial.print(" , ");
  Serial.println(timerTime);

}
