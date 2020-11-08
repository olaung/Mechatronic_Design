#define SW1 11
#define SW2 10
#define SW3 9
#define tyl 5
#define przod 4
#define PWM 3
int a=0; 



void setup() {
pinMode(SW3,INPUT_PULLUP);        //Przyciski
pinMode(SW2,INPUT_PULLUP);
pinMode(SW1,INPUT_PULLUP);
pinMode(tyl, OUTPUT);
pinMode(przod, OUTPUT);
pinMode(PWM, OUTPUT);  
Serial.begin(9600);
digitalWrite(SW1, HIGH);
digitalWrite(SW2, HIGH);
digitalWrite(SW3, HIGH);

}

void loop() {
 
  
  if(digitalRead(SW1)==LOW)          //przycisk SW1 wciśnięty
  {
    delay(20);
    a++;
    while(digitalRead(SW1)==LOW);
    delay(20);
    Serial.print("Ilość naciśnięć przycisku SW1: ");
    Serial.println(a);

     if (a%2==1)
     {
      Serial.print("Włączenie programu\n");
     }

     else
     {
      Serial.print("Wyłączenie programu\n");
     }
  } 

  if(digitalRead(SW2)==LOW && a%2==1)       //Ruch w przód
  {
     digitalWrite(przod,HIGH);
  }

  else if(digitalRead(SW2)==HIGH) 
  {
   digitalWrite(przod,LOW);
  }


  if(digitalRead(SW3)==LOW && a%2==1)         //Ruch w tył
  {
     digitalWrite(tyl,HIGH);
  }

  else if(digitalRead(SW3)==HIGH) 
  {
   digitalWrite(tyl,LOW);
  }
  

}
