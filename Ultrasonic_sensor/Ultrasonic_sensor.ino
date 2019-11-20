const int trigPin = 12;
const int echoPin = 5;

long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
  
// Calculating the distance
distance= duration*0.034/2;
  
// Prints the distance on the Serial Monitor
Serial.print("Distance in cm: ");
Serial.println(distance);
//Serial.print("cm");

}

