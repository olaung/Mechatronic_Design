float a; 
float b; // second number sent through the SM
char typ_dzialania; // create a char variable to store the calcuation signal.
float wynik; // wynik of the calculation
bool policzono=0;
bool zerowdzieleniu=0;

void setup() {
  Serial.begin(9600); // begins serial communications
  Serial.println("Co Ci policzyć przyjacielu :>?");
  Serial.println();
}

void loop() {
  while(Serial.available() > 0) {     
    a = Serial.parseFloat();    
    typ_dzialania = Serial.read();     
    b = Serial.parseFloat();    
    calculate();  

  
  }
}

void calculate() { 
  if (typ_dzialania == '+') {
    wynik = a + b;
     zerowdzieleniu=0;
  }
  else if (typ_dzialania == '-')  {
    wynik = a - b; 
     zerowdzieleniu=0;
  }
  else if (typ_dzialania == '*')  {
    wynik = a * b; 
    zerowdzieleniu=0;
  }
  else if (typ_dzialania == '/')  {
    if(b!=0){
      
    
    wynik = a / b; 
    zerowdzieleniu=0;}
    
    else if(b==0){
      Serial.println("Pamiętaj cholero nie dziel przez zero");
      wynik=0;
      zerowdzieleniu=1;
    }
    
  }
   else {
      
        
        if(zerowdzieleniu==0){
        Serial.print("wynik = ");
        Serial.println(wynik);
        }
        Serial.println("Możesz podać następne działanie "); 
        Serial.println(); 
      }
     
   }
