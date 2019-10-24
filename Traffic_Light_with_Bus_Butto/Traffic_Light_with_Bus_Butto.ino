

      int LEDRed = 9; // was 9
      int LEDYellow = 11;
      int LEDGreen = 13;
      int button =  7;
const int state_LED_Red = 0;
const int state_LED_Yellow = 1;
const int state_LED_Green = 2;
      int current_State = 0;
      int buttonPressed = 0;
      

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDRed, OUTPUT);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDGreen, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
    // turn LED on
  
   switch (current_State){

    case state_LED_Red : //'state_LED_Red'
      digitalWrite(LEDRed, HIGH);
     
            for(int i=0; i<5; i++ ){ // basically delays for 30 seconds in total
        //Serial.println("debug 02");
        delay(1000);
        buttonPressed =digitalRead(button);
        
        if(buttonPressed == HIGH){
          current_State = 1;
          digitalWrite(LEDRed, LOW);
          break;
        } //END OF IF STATEMENT
      } // END OF FOR LOOP
      current_State = 1;
      digitalWrite(LEDRed, LOW);
      break;
      
     case state_LED_Yellow : //'state_LED_Yellow'
        digitalWrite(LEDYellow, HIGH);
        delay(2000); // wait  for 2 seconds
       current_State = 2;
        digitalWrite(LEDYellow, LOW);
       break;

     case state_LED_Green : //'state_LED_Green'
        digitalWrite(LEDGreen, HIGH);
        delay(5000);// wait for 30 seconds
          if(digitalRead(button) == HIGH){
            delay(30000); //wait 30 more seconds
          } //  END OF IF FUNCTION
        current_State = 0;
        digitalWrite(LEDGreen, LOW);
       break;
  } // END 0F SWITCH CASE
  
} // END OF MAIN LOOP
