
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

int counter=0;
byte ended=false;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(); 
   
  MFS.initialize(); // Inicializa la biblioteca multi-function shield
  
  MFS.write("Hi");      
  delay(2000);
  MFS.write(-273);      
  delay(2000);
 
  MFS.write("push");  
  delay(2000);
  MFS.write("uwu");
}

void loop() {
    if(Serial.available()){
    int dato=Serial.read();
    if(dato=='A'){
      
   if (counter<15){
    MFS.write((int)counter);//void write(int integer);
    counter++;
  }
 
  }
  
    else if(dato=='B'){
  
    MFS.write("End");
    /* Parpadea los dígitos en la pantalla de dígitos LED.*/    
     
    MFS.blinkDisplay(DIGIT_ALL,OFF); 
  }   

    else if(dato=='C'){
  
    
    counter=0;
  }    
}
  
  
  delay(50);
}
