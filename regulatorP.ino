#define echo 11
#define trig 10
#define tyl 5
#define przod 4
#define PWM 3
float zadana, odleglosc, czas, kp, uchyb, regulator;

 
void setup() {
  
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(PWM, OUTPUT);
digitalWrite(tyl, LOW);
digitalWrite(przod, LOW);

zadana = 6.0;                          //ustawienie zadanej wartości
kp = 8.5;
}

void loop() {
  
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);

 czas = pulseIn(echo, HIGH);
 odleglosc = czas/58;                     //obliczenie odległości od czujnika w cm
 Serial.println(odleglosc );              //wyświetlenie odległości od czujnika
  
uchyb = zadana - odleglosc;               //obliczenie uchybu
regulator = kp * uchyb;                   //wzor na regulagtor P


if(uchyb==0)
{
  digitalWrite(przod, LOW);
  digitalWrite(tyl, LOW);
}

else if(uchyb>=0)
{
  
  digitalWrite(przod, LOW);
  digitalWrite(tyl, HIGH);
}

else
{
  
  digitalWrite(przod, HIGH);
  digitalWrite(tyl, LOW);
}


if(abs(regulator)<255)
{
  digitalWrite(PWM, abs(regulator));
}

else
{
  digitalWrite(PWM, 255);
}
}
