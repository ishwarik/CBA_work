#include <Servo.h> 

Servo myservo1; 

Servo myservo2; 

int ping = 8; 

int buzzer = 3; 

int ledpin2 = 2; 

int ledpin1 = 7; 

int motor = 13;   

int potpin = A1;  // analog pin used to connect the potentiometer 

int val;    // variable to read the value from the analog pin 

int sensorPin = A2;    // select the input pin for the potentiometer 

int ledPin = 10;  // select the pin for the LED 

const int pingPin = 4; 

int pirr = 11; 

int pirl = 12; 

int LED_1 = 6;                                       // Initializing the first LED to output 6 

int LED_2 = 5;                                          // Initializing the second LED to output 5 

int sensorValue_1;                                      // Initializing the potentiometer  

int sensorPin_1 = A0;                                 // Initializing the first sensor pin at input A0 

int bright_1; 

int bright_2; 

int pt=0; 

int rs=0; 

void setup() 

{ 

  //Automatic obstacle detection 

  Serial.begin(9600); 

  pinMode(buzzer, OUTPUT); 

  pinMode(ledpin2, OUTPUT); 

  pinMode(ledpin1, OUTPUT); 

  pinMode(motor, OUTPUT); 

  pinMode(ping, INPUT); 

  //lane detection 

  pinMode(ledPin, OUTPUT); 

  pinMode(LED_1, OUTPUT); 

  pinMode(LED_2, OUTPUT); 

  pinMode(pirr, INPUT); 

  pinMode(pirl, INPUT); 

   

  //Adaptive headlight 

   myservo1.attach(9); 

   myservo2.attach(7); 

 

  

} 

 

void obstacledetection() 

{ 

  long duration,cm,inches; 

  //digitalWrite(motor,HIGH); 

  pinMode(ping, OUTPUT);  

  digitalWrite(ping, LOW);  

  delayMicroseconds(2);  

  digitalWrite(ping, HIGH);  

  delayMicroseconds(5);  

  digitalWrite(ping, LOW);  

  pinMode(ping, INPUT);  

  duration=pulseIn(ping,HIGH); 

  inches=microsecondsToInches(duration); 

  cm=microsecondsToCentimeters(duration); 

  Serial.print(inches); 

  Serial.print("in, "); 

  Serial.print(cm); 

  Serial.print("cm"); 

  Serial.println(); 

  delay(100); 

      if(cm>=15) 

       { 

          digitalWrite(motor,HIGH); 

          digitalWrite(ledpin1,LOW); 

          digitalWrite(buzzer,LOW); 

          digitalWrite(ledpin2,LOW); 

       }  

      else if(cm>10&&cm<15) 

       { 

          digitalWrite(motor,HIGH); 

          digitalWrite(ledpin2,HIGH);   

          digitalWrite(buzzer,LOW); 

          digitalWrite(ledpin1,LOW); 

          int r1 = digitalRead(pirr); 

          int l1 = digitalRead(pirl); 

           if (r1 == 1) 

           { 

            // r1 = map(r1, 1023,0 , 0, 180);  

             myservo2.write(90); 

             myservo1.write(120);       

           } 

         

            

           if (l1 == 1) 

           { 

            // l1 = map(l1, 1023,0 , 0, 180);  

             myservo1.write(90); 

             myservo2.write(70); 

           } 

       }  

      else if(cm<=10) 

       { 

          digitalWrite(motor,LOW); 

          digitalWrite(ledpin1,HIGH); 

          digitalWrite(ledpin2,LOW); 

          digitalWrite(buzzer,HIGH); 

       } 

        

           

   

   

} 

void lanedetection() 

{ 

  // establish variables for duration of the ping, 

  // and the distance result in inches and centimeters: 

  long duration1,cm1; 

 

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds. 

  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: 

  pinMode(pingPin, OUTPUT); 

  digitalWrite(pingPin, LOW); 

  delayMicroseconds(2); 

  digitalWrite(pingPin, HIGH); 

  delayMicroseconds(5); 

  digitalWrite(pingPin, LOW); 

 

  // The same pin is used to read the signal from the PING))): a HIGH 

  // pulse whose duration is the time (in microseconds) from the sending 

  // of the ping to the reception of its echo off of an object. 

  pinMode(pingPin, INPUT); 

  duration1 = pulseIn(pingPin, HIGH); 

 

  // convert the time into a distance 

  cm1 = microsecondsToCentimeters(duration1); 

  Serial.println(cm1); 

  delay(100); 

   

  if(cm1<=150) 

  { 

  // digitalWrite(9, LOW); 

  // digitalWrite(greenPin,LOW); 

  // digitalWrite(redPin,HIGH);  // red 

  sensorValue_1 = analogRead(sensorPin_1); 

  //  digitalWrite(LED_1,HIGH );// Reading the first sensor value 

 Serial.print("sensor 1 reading  = ");     // Printing the value of the sensor   

 Serial.println(sensorValue_1);       

  bright_1 = map(sensorValue_1, 0,1023,0,255);     // Remapping the values 

  bright_2 = map(sensorValue_1, 0 ,1023, 0 ,255); 

  

 if (sensorValue_1>550)                              // Condition for first sensor value 

 { 

       int r = digitalRead(pirl); 

        if (r == 1) 

        {   

  digitalWrite(LED_1,LOW );// Writing the value to the LED 

        digitalWrite(motor,LOW ); 

        delay(500);   

        } 

         if (r == 0) 

        {   

  digitalWrite(LED_1,HIGH );// Writing the value to the LED 

        } 

       delay(100); 

 } 

 else 

 { 

  digitalWrite(LED_1,LOW);                       // Else the LED is off 

 } 

   

 if (sensorValue_1<550)                               // Condition for first sensor value 

 {   

        int l = digitalRead(pirr); 

        if (l == 1) 

        {   

  digitalWrite(LED_2,LOW );// Writing the value to the LED 

        digitalWrite(motor,LOW ); 

        delay(500); 

        } 

         if (l == 0) 

        {   

  digitalWrite(LED_2,HIGH );// Writing the value to the LED 

        } 

        delay(100); 

    } 

   

 else 

 { 

   digitalWrite(LED_2, LOW);               // Else the LED is off 

 } 

 

 

  } 

   

} 

void adaptiveheadlight() 

{ 

   

  int sensorValue=0; 

  // read the value from the sensor: 

  sensorValue = analogRead(sensorPin); 

  // turn the ledPin on 

  Serial.println(sensorValue); 

  if(sensorValue==0) 

  { 

   digitalWrite(ledPin, HIGH); 

  // stop the program for <sensorValue> milliseconds: 

  } 

  else{ 

    digitalWrite(ledPin, LOW); 

  // stop the program for for <sensorValue> milliseconds: // val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 

  //  val = map(val, 1023,0 , 0, 180);     // scale it to use it with the servo (value between 0 and 180) 

  // myservo.write(val);       

 // sets the servo position according to the scaled value 

  delay(15);   

   

} 

    

 

long microsecondsToInches(long microseconds) 

{ 

return microseconds / 74 / 2; 

} 

long microsecondsToCentimeters(long microseconds) 

{ 

return microseconds / 29 / 2; 

} 

 

void loop() 

{ 

   

       obstacledetection();  

        lanedetection();  

        adaptiveheadlight(); 

       

} 

 

 

 

   
