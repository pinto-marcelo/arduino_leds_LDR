#define KEY_PRESSED HIGH //state of key being pressed
#define KEY_NO_PRESS 0 //key not pressed
#define KEY_SHORT_PRESS 1 //key pressed short
#define KEY_LONG_PRESS 2 //key pressed long


int vermelho = 10; //translate: vermelho = red;
int amarelo = 9; //translate: amarelo = yellow;
int verde = 8;  //translate: verde = green;
int botao = 12; //translate: botao = button;
int advertencia = 2; //translate: advertencia = warning (it works to represent a counter);
int azul = 7; //translate: azul = blue;
int branco = 6; //translate: branco = white;
int vermelho2 = 5;
int amarelo2 = 4;
int verde2 = 3;
int botao2 = 2;
int i;
int count;
int pinoLed = 13;  //translate: pino = pin;
int pinoLDR = A5;
int warning_y = A4;
int testLed = A3;
int LDRblueLed2 = A2;
int LDRblueLed1 = A1; 
void setup() {

  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(branco, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(advertencia, OUTPUT);
  pinMode(warning_y, OUTPUT);
  pinMode(testLed, OUTPUT);
  pinMode(LDRblueLed2, OUTPUT);
  pinMode(LDRblueLed1, OUTPUT);
  
  // Turning on...
  
  // .. Turning off:
   digitalWrite(verde2, LOW);
   digitalWrite(verde, LOW);
  digitalWrite(amarelo2, LOW);  
  digitalWrite(vermelho2, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(branco, LOW);
digitalWrite(pinoLed, LOW);
   digitalWrite(advertencia, LOW);
  digitalWrite(warning_y, LOW);
  digitalWrite(testLed, LOW);
}

void loop() 
{
   opencount();
      
  evenAndOdd();
   
   longpress();
   
   pin();
   
}//close loop();

void evenAndOdd()//this one has to be a switch of even and odd with these two leds: 
{
   if(count%2==0)
   {    
   digitalWrite(warning_y, HIGH); //yellow = even;
   digitalWrite(advertencia, LOW);//green = odd;
      
      if(count%2==0&&count%3==0)
      {
      digitalWrite(warning_y, HIGH); //yellow = even;
      digitalWrite(advertencia, HIGH);//green = odd; 
      }
   }
   else
   {
  digitalWrite(advertencia, HIGH);
    digitalWrite(warning_y, LOW);
   }
}
        
void longpress()
{
   if(KEY_LONG_PRESS)
   {
    while (digitalRead(botao) == HIGH)
    {
          speed3();
    }
   }
}

void opencount()
{
 if (digitalRead(botao) == HIGH) 
    { 
      for(i=0; i<1; i++)
          {
          speed1();
          }
      
      /* You may switch to these speeds (faster), i did increased the number of loops on for you can see this running better:
      for(i=0; i<2; i++)
          {
          speed2();
          }
           
      for(i=0; i<4; i++)
          {
          speed3();
          }
          */ 
    count++;
    } 
}

void pin()//this function may not works well in illuminated places; 
{
  while(analogRead(pinoLDR) > 100)
  {
   digitalWrite(warning_y, LOW); 
   digitalWrite(advertencia, LOW);
    if(analogRead(pinoLDR) > 100)
    { 
      for(i=0; i<3; i++)
      {
      digitalWrite(pinoLed, HIGH);
      digitalWrite(testLed, HIGH);
      delay(800);
      digitalWrite(pinoLed, LOW);
      digitalWrite(testLed, LOW);  
      digitalWrite(LDRblueLed1, HIGH);
      digitalWrite(LDRblueLed2, HIGH);
      delay(800);
      digitalWrite(LDRblueLed1, LOW);
      digitalWrite(LDRblueLed2, LOW); 
      }
    }else{ 
      digitalWrite(pinoLed, LOW);
      digitalWrite(testLed, LOW); 
         }  
  }
}
void speed1() {
    
  digitalWrite(amarelo2, HIGH);
  digitalWrite(vermelho2, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(branco, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  delay(100);
  
  digitalWrite(vermelho2, HIGH);
  digitalWrite(amarelo2, LOW);
  delay(100);

  digitalWrite(vermelho2, LOW);
  digitalWrite(branco, HIGH);
  delay(100);

  digitalWrite(azul, HIGH);
  digitalWrite(branco, LOW);
  delay(100);

  digitalWrite(verde, HIGH);
  digitalWrite(azul, LOW);
  delay(100);

  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
  delay(100);

  digitalWrite(vermelho, HIGH);
  digitalWrite(amarelo, LOW);
  delay(100);

  digitalWrite(amarelo, HIGH);
  digitalWrite(vermelho, LOW);
   delay(100);

  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH); delay(100);

  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH); delay(100);
    
  digitalWrite(azul, LOW);
  digitalWrite(branco, HIGH); delay(100);
  
  digitalWrite(branco, LOW);
  digitalWrite(vermelho2, HIGH); delay(100);

  digitalWrite(amarelo2, HIGH); delay(100);
  digitalWrite(vermelho2, LOW);

  digitalWrite(amarelo2, LOW);
  digitalWrite(verde2, HIGH); 
  delay(100);
  digitalWrite(verde2, LOW); 
  return;
}
void speed2() {
   
  digitalWrite(amarelo2, HIGH);
  digitalWrite(vermelho2, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(branco, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  delay(50);
 
  digitalWrite(vermelho2, HIGH);
  digitalWrite(amarelo2, LOW);
  delay(50);

  digitalWrite(vermelho2, LOW);
  digitalWrite(branco, HIGH);
  delay(50);

  digitalWrite(azul, HIGH);
  digitalWrite(branco, LOW);
  delay(50);

  digitalWrite(verde, HIGH);
  digitalWrite(azul, LOW);
  delay(50);

  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
  delay(50);

  digitalWrite(vermelho, HIGH);
  digitalWrite(amarelo, LOW);
  delay(50);

  digitalWrite(amarelo, HIGH);
  digitalWrite(vermelho, LOW);
   delay(50);

  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH); delay(50);

  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH); delay(50);

  digitalWrite(azul, LOW);
  digitalWrite(branco, HIGH); delay(50);
  
        digitalWrite(branco, LOW);
  digitalWrite(vermelho2, HIGH); delay(50);

  digitalWrite(amarelo2, HIGH); delay(50);
  digitalWrite(vermelho2, LOW);

  digitalWrite(amarelo2, LOW);
  digitalWrite(verde2, HIGH); 
  delay(50);
  digitalWrite(verde2, LOW); 
  return;
}
void speed3() {
    
  digitalWrite(amarelo2, HIGH);
  digitalWrite(vermelho2, LOW);
  digitalWrite(verde2, LOW);
  digitalWrite(branco, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  delay(25);

  digitalWrite(vermelho2, HIGH);
  digitalWrite(amarelo2, LOW);
  delay(25);

  digitalWrite(vermelho2, LOW);
  digitalWrite(branco, HIGH);
  delay(25);

  digitalWrite(azul, HIGH);
  digitalWrite(branco, LOW);
  delay(25);

  digitalWrite(verde, HIGH);
  digitalWrite(azul, LOW);
  delay(25);

  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
  delay(25);

  digitalWrite(vermelho, HIGH);
  digitalWrite(amarelo, LOW);
  delay(25);

  digitalWrite(amarelo, HIGH);
  digitalWrite(vermelho, LOW);
   delay(25);

  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH); delay(25);

  digitalWrite(verde, LOW);
  digitalWrite(azul, HIGH); delay(25);

  digitalWrite(azul, LOW);
  digitalWrite(branco, HIGH); delay(25);
  
        digitalWrite(branco, LOW);
  digitalWrite(vermelho2, HIGH); delay(25);

  digitalWrite(amarelo2, HIGH); delay(25);
  digitalWrite(vermelho2, LOW);

  digitalWrite(amarelo2, LOW);
  digitalWrite(verde2, HIGH); 
  delay(25);
  digitalWrite(verde2, LOW);

  return;
}
