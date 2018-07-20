#include<Arduino.h>
#include<String.h>
#define totsym 8

typedef struct symbol sym;
void manualCalibrate();
void autoCalibrate();
void lookupsym(String& input);

struct symbol{
  String vr;  //voltage reading
  String text;

  symbol():text(""),vr(""){}
};

sym symbol [totsym];
String input=String("00000");
   
void setup() {
Serial.begin(9600);
toAndroid(String("Now Starting..."));

//manualCalibrate(symbol);
autoCalibrate();
//toAndroid(String("End of Calibration"));
toAndroid(String("Waiting for the signal now "));
delay(3500);
}

void loop() {
     bool flag=0;
  
    lbl:
    
    for(int i=2;i<=6;i++){
    input[i-2]= char( digitalRead(i)+'0' );
    }
    delay(500);
  
    if(input=="00000"){
    if (flag!=1){ //toAndroid("Now in Sleep Mode Press Anything to begin");
      }

    delay(10);
    flag=1;
    goto lbl;  
    }else{
      flag=0;
    }
   
    lookupsym(input);  
}
