

      int LED_Red = 9; // was 9
      int LED_Yellow = 11;
      int LED_Green = 13;
      int pedestrian_LED_Red = 2;
      int pedestrian_LED_Green = 4;
      int pedestrian_Button = 8;
      int bus_Button =  7;

      int i = 0;
      
const int state_LED_Red = 0;
const int state_LED_Yellow = 1;
const int state_LED_Green = 2;
const int state_Pedestrian_Red = 3;
const int state_Pedestrian_Green = 4;
      int current_State = 0;

    
      

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(bus_Button, INPUT);
  pinMode(pedestrian_Button, INPUT);
  pinMode(pedestrian_LED_Red, OUTPUT);
  pinMode(pedestrian_LED_Green, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
      int bus_Button_Pressed = 0; 
      int pedestrian_Button_Pressed = 0;
      digitalWrite(pedestrian_LED_Red, HIGH); //pedestrian light is always on untill further notice
      //digitalWrite(pedestrian_LED_Green, HIGH);
  
   switch (current_State){

    case state_LED_Red : //'state_LED_Red'
      digitalWrite(LED_Red, HIGH);
     
     for(i=0; i<=200; i++){ // basically delays for 10 seconds in total
        
        delay(50); //the delay was reduced so as to enable more time to check if the button has BEEN PRESSED
        bus_Button_Pressed =digitalRead(bus_Button);
       //Serial.print(bus_Button);
        pedestrian_Button_Pressed =digitalRead(pedestrian_Button);

        
        
        if(pedestrian_Button_Pressed == 1 && bus_Button_Pressed == 1){
          current_State = 4;
          Serial.println("THis was Read");
          digitalWrite(pedestrian_LED_Green, HIGH);
          break;
        } else if(pedestrian_Button_Pressed == 1 && bus_Button_Pressed == 0){
          current_State = 4;
          Serial.println("Be happy");
          digitalWrite(pedestrian_LED_Green, HIGH);
          break;
        } else if(i == 200){
          current_State = 1;
          Serial.println("jumped here");
          digitalWrite(LED_Red, LOW);
          break;
          }else if(bus_Button_Pressed == 1  && pedestrian_Button_Pressed == 0){
          current_State = 1;
          //digitalWrite(LED_Red, LOW);
          break;
          }
      
      } // END OF FOR LOOP
      //current_State = 1;
      //Serial.println("jumped here");
      digitalWrite(LED_Red, LOW);
      break;
      
     case state_LED_Yellow : //'state_LED_Yellow'
        digitalWrite(LED_Yellow, HIGH);
        delay(1000); // wait  for 1 second
       current_State = 2;
        digitalWrite(LED_Yellow, LOW);
       break;

     case state_LED_Green : //'state_LED_Green'
        digitalWrite(LED_Green, HIGH);
          for(int j = 0; j<= 200; j++){
            delay(50);
            if(digitalRead(pedestrian_Button)== 1){
              digitalWrite(LED_Green, LOW);
              current_State = 4;
              Serial.println("I was read");
              break;
              } else if(j  == 200){
                current_State = 0;
                digitalWrite(LED_Green, LOW);
                digitalWrite(pedestrian_LED_Green, LOW);
                Serial.println("I think This was read");
                break;
                }
            }
            break;
     case state_Pedestrian_Green ://'state_LED_Green'
     Serial.println("Then i cAME HERE");
        digitalWrite(LED_Red, HIGH);
        digitalWrite(pedestrian_LED_Red, LOW);
        digitalWrite(pedestrian_LED_Green, HIGH);
        delay(5000);// wait for 5 seconds
         current_State = 0;
        digitalWrite(pedestrian_LED_Green, LOW);
        digitalWrite(pedestrian_LED_Red, HIGH);
       break;
  } // END 0F SWITCH CASE
  
} // END OF MAIN LOOP  "$(ProjectDir)Debug\$(TargetName).hex":i
