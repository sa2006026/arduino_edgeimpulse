#include "uFire_SHT20.h"
uFire_SHT20 sht20;
double currentT, previousT;
double elapsedT[65536];
double starttime;
double realtime;
int count = 0;
int times = 0;
int timerMode = 0;
double timertime = 0;
double trigger = 1.50;
int i = 0 ;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  sht20.begin();
}

void loop()
{
  //currentT = sht20.humidity();
  //Serial.print("currentT : "); Serial.println(currentT);
  elapsedT[i] = currentT - previousT; 
  //Serial.print("previousT : "); Serial.println(previousT);
  previousT = currentT; // 1000;//Second in unit
  //Serial.print("Correct T : "); Serial.println(elapsedT);
  Serial.print((String)sht20.humidity());
  Serial.print(" , ");
  Serial.println(elapsedT[i]);
  i++;
  if ( times > 0 ){ 
      if ( elapsedT[i+50]-elapsedT[i] >= trigger){
        count++;
        }
  }

  if ( count == 1){
    starttime = millis();
    timerMode++;
  }
  
  if (timerMode > 0){
    timertime = (millis()- starttime)/1000;
  }
  //Serial.print(" , ");
  //Serial.println(timertime);
  times++;
  delay(10);
}
