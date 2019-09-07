//LED pins 2 - 10
const int startLED = 2;
const int endLED = 10;

//Button pins 12 and 13
const int btnSet = 12;
const int btnGo = 13;

int timerSetting = 1;

int setState = 0;
int goState = 0;

bool setPushed = false;

void setup() {
  Serial.begin(9600);
    
  for(int i=startLED; i<=endLED; i++)
  {
    pinMode(i, OUTPUT);    
  }

  pinMode(btnSet, INPUT);
  pinMode(btnGo, INPUT);
  
  LedTest();

}

void loop() {
  //Check the set state

  setState = digitalRead(btnSet);

  Serial.print("setState: ");
  Serial.print(setState);
  Serial.println();
  Serial.print("setPsuhed: ");
  Serial.print(setPushed);
  Serial.println();

  if(setState == HIGH && setPushed == false){
    Serial.println("SETTING To TRUE");
    setPushed = true;
    setStatePushed();
  }
  
  if(setState == LOW && setPushed == true){
    Serial.println("SETTING To FALSE");
    setPushed = false;
  }  
}

void setStatePushed(){

  if(timerSetting==9){
    timerSetting = 1;     
  }
  else{
    timerSetting++;
  }

  SetLeds(timerSetting);
}

void SetLeds(int onLED){

  Serial.print("SetLeds: ");
  Serial.print(onLED);
  Serial.println();

  onLED++;

  for(int i=startLED;i<=endLED;i++){
    if(i<=onLED){
      digitalWrite(i,HIGH);
    }
    else{
      digitalWrite(i,LOW);
    }
  }
}

void LedTest(){

  Serial.println("Starting Led Test");

  Serial.println("going up");
  
  for(int i=1;i<=9;i++){
    SetLeds(i);
    delay(50);
  }

  delay(50);

  Serial.println("going down");

  for(int i=9;i>=1;i--){
    SetLeds(i);
    delay(50);
  }

  Serial.println("Led Test finished");
}
