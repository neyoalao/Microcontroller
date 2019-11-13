  int led_Red = 9;
  int led_Green =13;
  int button = 2;
  volatile bool button_Pressed = false;

  const int state_Red = 0;
  const int state_Green = 1;
  int current_State = 0;

void setup() {
  pinMode(led_Red,OUTPUT);
  pinMode(led_Green, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), iSR_button_Pressed, RISING);
  

}

void loop() {
  switch(current_State){
    case state_Red:
      digitalWrite(led_Red,HIGH);
      delay(50000);
      current_State = 1;
      digitalWrite(led_Red,LOW);
      break;
    case state_Green:
      digitalWrite(led_Green, HIGH);
      delay(1000);
      current_State = 0;
      digitalWrite(led_Green, LOW);
      break;
    }

}
void iSR_button_Pressed(){
  digitalWrite(led_Red,LOW);
  digitalWrite(led_Green, HIGH );
  delayMicroseconds(3000000);
  current_State = 0;
  //digitalWrite(led_Green, LOW );
 
  }
