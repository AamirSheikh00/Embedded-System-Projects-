#include <Servo.h> //Servo library
#include <SoftwareSerial.h> // Library for serial communication
#include <LiquidCrystal.h> //Load Liquid Crystal Library

const int RS = 10, EN = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);  //Create Liquid Crystal Object called LCD

String res = "";
Servo servo; // Declaration of servos
char serial_type = 0; // Here we store the font
int angle;

const int led = 13; // LED connected to port 13 of arduino UNO
const int buz = 8;
String code = "";
int len = 0;
char ch;
char new_char;
int unit_delay = 250;     // Delay in millisecond

char arr[40] = {};
int count = 0;

void append(char val){
  if(count < 40){
      arr[count] = val; 
      count++;
    }
 }
 
void dot(){
  lcd.print(res + ".");
  digitalWrite(led, HIGH);
  digitalWrite(buz, HIGH);
  delay(unit_delay);
  digitalWrite(led, LOW);
  digitalWrite(buz, LOW);
  delay(unit_delay);
}

void dash(){
  lcd.print(res + "-");
  digitalWrite(led, HIGH);
  digitalWrite(buz, HIGH);
  delay(unit_delay * 3);
  digitalWrite(led, LOW);
  digitalWrite(buz, LOW);
  delay(unit_delay * 3);
}

void A() {
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}

void B()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void C()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void D()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void E()
{
  dot();
  delay(unit_delay);
}
void f()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void G()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void H()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void I()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void J()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void K()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void L()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void M()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void N()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void O()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void P()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
}
void Q()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void R()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void S()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void T()
{
  dash();
  delay(unit_delay);
}
void U()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void V()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void W()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void X()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Y()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Z()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void one()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void two()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void three()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void four()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void five()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void six()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void seven()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void eight()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void nine()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void zero()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}


void morse() {
  if (ch == 'A' || ch == 'a') {
    A();
    lcd.print(res + " ");
  }
  else if (ch == 'B' || ch == 'b')
  {
    B();
    lcd.print(res + " ");
  }
  else if (ch == 'C' || ch == 'c')
  {
    C();
    lcd.print(res + " ");
  }
  else if (ch == 'D' || ch == 'd')
  {
    D();
    lcd.print(res + " ");
  }
  else if (ch == 'E' || ch == 'e')
  {
    E();
    lcd.print(res + " ");
  }
  else if (ch == 'f' || ch == 'f')
  {
    f();
    lcd.print(res + " ");
  }
  else if (ch == 'G' || ch == 'g')
  {
    G();
    lcd.print(res + " ");
  }
  else if (ch == 'H' || ch == 'h')
  {
    H();
    lcd.print(res + " ");
  }
  else if (ch == 'I' || ch == 'i')
  {
    I();
    lcd.print(res + " ");
  }
  else if (ch == 'J' || ch == 'j')
  {
    J();
    lcd.print(res + " ");
  }
  else if (ch == 'K' || ch == 'k')
  {
    K();
    lcd.print(res + " ");
  }
  else if (ch == 'L' || ch == 'l')
  {
    L();
    lcd.print(res + " ");
  }
  else if (ch == 'M' || ch == 'm')
  {
    M();
    lcd.print(res + " ");
  }
  else if (ch == 'N' || ch == 'n')
  {
    N();
    lcd.print(res + " ");
  }
  else if (ch == 'O' || ch == 'o')
  {
    O();
    lcd.print(res + " ");
  }
  else if (ch == 'P' || ch == 'p')
  {
    P();
    lcd.print(res + " ");
  }
  else if (ch == 'Q' || ch == 'q')
  {
    Q();
    lcd.print(res + " ");
  }
  else if (ch == 'R' || ch == 'r')
  {
    R();
    lcd.print(res + " ");
  }
  else if (ch == 'S' || ch == 's')
  {
    S();
    lcd.print(res + " ");
  }
  else if (ch == 'T' || ch == 't')
  {
    T();
    lcd.print(res + " ");
  }
  else if (ch == 'U' || ch == 'u')
  {
    U();
    lcd.print(res + " ");
  }
  else if (ch == 'V' || ch == 'v')
  {
    V();
    lcd.print(res + " ");
  }
  else if (ch == 'W' || ch == 'w')
  {
    W();
    lcd.print(res + " ");
  }
  else if (ch == 'X' || ch == 'x')
  {
    X();
    lcd.print(res + " ");
  }
  else if (ch == 'Y' || ch == 'y')
  {
    Y();
    lcd.print(res + " ");
  }
  else if (ch == 'Z' || ch == 'z')
  {
    Z();
    lcd.print(res + " ");
  }
  else if (ch == '0')
  {
    zero();
    lcd.print(res + " ");
  }
  else if (ch == '1')
  {
    one();
    lcd.print(res + " ");
  }
  else if (ch == '2')
  {
    two();
    lcd.print(res + " ");
  }
  else if (ch == '3')
  {
    three();
    lcd.print(res + " ");
  }
  else if (ch == '4')
  {
    four();
    lcd.print(res + " ");
  }
  else if (ch == '5')
  {
    five();
    lcd.print(res + " ");
  }
  else if (ch == '6')
  {
    six();
    lcd.print(res + " ");
  }
  else if (ch == '7')
  {
    seven();
    lcd.print(res + " ");
  }
  else if (ch == '8')
  {
    eight();
    lcd.print(res + " ");
  }
  else if (ch == '9')
  {
    nine();
    lcd.print(res + " ");
  }

  else if (ch == ' ') {
    delay(unit_delay * 7);
    lcd.print(res + "/ ");
  }
  else if (ch == '\n') {
    lcd.print(res + "");
  }
  else {
    lcd.print(res + "Unknown Character!");
  }

}


void String2Morse() {
  len = code.length();
  for (int i = 0; i < len; i++) {
    ch = code.charAt(i);
    morse();
  }
}


void setup() {
  Serial.begin (9600);  // Communication speed
  Serial.setTimeout(10); // The wait time between serial data

  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
  
  pinMode (13, OUTPUT); // Set pin 8 for LEDs as output
  pinMode (6, OUTPUT); // Configuration of pin 9 as output
  
  servo.attach(6); // We call the servo
  servo.write (0); // We initialize the servo at angle 0
}

void loop() {
  while (Serial.available ()) {// We ask the serial port is available. 
    serial_type = Serial.read (); // If available, read the serial port
    delay(10);
    switch(serial_type){
      case 'e': // Let's see if we want to turn on the led
      digitalWrite (13, HIGH);
      break;
      
      case 'p': // Let's see if we want to turn off the led:
      digitalWrite (13, LOW);
      break;   

      case 'a':
      {
        if(Serial.available()){  // We ask again if the serial port is available
        angle = Serial.read();
        servo.write(angle);
        //digitalWrite(8,HIGH);
      }
      break;

      case 'c':
      {
        while (Serial.available()){
          code = Serial.readString();
          //lcd.print(res + " = ");
          String2Morse();
          //lcd.print(res + ); 
          Serial.print(res);
        }
        
        delay(1000);
      }
      break;
      
      }
    }
  }
}
