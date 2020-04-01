#include <Servo.h>

const int sensorPin = A0;
  const float baselineTemp = 20.0;
const int ledpin = 4;

int echoPin=6; 
int trigPin=7; 
long duration; 
int distanceCm; 
Servo servo_9; 
void setup()
{
  servo_9.attach(9);
  
  Serial.begin(9600); 
  for (int pinNumber = 2; pinNumber < 5; pinNumber++){
       pinMode(pinNumber, OUTPUT);
       digitalWrite(pinNumber, LOW);
       }
       }
void loop()
{
  long duration, cm;
   int sensorVal = analogRead(sensorPin);
         Serial.print("Sensor Value:: ");
         Serial.print (sensorVal);
      //convert the ADC reading to voltage
         float voltage = (sensorVal/1024.0)*5.0;
         Serial.print(", Volts: ");
         Serial.print(voltage);
         Serial.print(", degress C: ");
  float celcius = (voltage - .5)*100;
  Serial.println(celcius);
                      
  digitalWrite(echoPin,HIGH); 
  delayMicroseconds(2); 
  digitalWrite(trigPin,LOW); 
  delayMicroseconds(10); 
  digitalWrite(trigPin,HIGH); 
  
  duration = pulseIn(echoPin,HIGH); 
  distanceCm=duration*0.034/2; 
  if (distanceCm <= 20){ 
   servo_9.write(90); 
  }
    else{
    servo_9.write(0); 
}
  //convert the voltage to temperature in degrees
                      if (celcius > 37) {
    digitalWrite(ledpin, HIGH);
    }
  else if (celcius < 37) {
    digitalWrite(ledpin, LOW);
      }
}
                 