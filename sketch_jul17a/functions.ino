void manualCalibrate(){
//manual calibration not complete 

toAndroid(String("Calibration Starting..."));
delay(1500);

for(int i=1;i<=26;i++){

toAndroid(String("Now Calibrating"));
delay(1500);
toAndroid(String(char('A'+i-1))); 

int ttemp=millis();


while(  ( millis()-ttemp)<2000 ){
  for(int i=2;i<=6;i++){
      if( digitalRead(i)==0){
//        octr[i]++;
        }
     
    }  
}
  
  toAndroid("Calibrated");
  delay(1000);
  toAndroid(String(char('A'  +i))); 
}

}



void PinAssign(){
pinMode(A0,INPUT);   
for(int i=2;i<=6;i++){
      pinMode(i,INPUT);
    }
 pinMode(13,OUTPUT);
 digitalWrite(13,HIGH);     
}

void toAndroid( const String& txt){
  /*  String acc="";

for(int i=0;i<txt.length();i++){

if( txt[i]==' '){
  Serial.println(acc);
  delay(500);
  acc="";
}
acc=acc+txt[i];
}
  Serial.println(acc); */
  Serial.println(txt);
  delay(2500);
}


void autoCalibrate(){
  String input[]={"Hello","10000","How are you","01000","I am good","00110","What's your name","00111","Call me","01110","Love you too","00111","All the Best","01111","Where is the toilet","11110"};
  int ctr=0;
  for(int i=0;i<15;i+=2){
  symbol[ctr].text=input[i];
  symbol[ctr].vr=input[i+1];
  ctr++;
  }
 
}

void lookupsym(String& input){
  for(int i=0;i<totsym;i++){
    if(symbol[i].vr==input){
      toAndroid(symbol[i].text);
      return;
      }  
  }
 toAndroid(String("Sorry No Symbol Match")); 
 delay(1000);
}  

