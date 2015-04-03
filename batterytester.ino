#define newLED 2 // blue LED 'new'
#define okLED 4 // peach-ish LED 'ok'
#define oldLED 6 // red LED 'old'
int analogValue = 0;
float voltage = 0;
int ledDelay = 2000;
void setup()
{
  pinMode(newLED, OUTPUT);
  pinMode(okLED, OUTPUT);
  pinMode(oldLED, OUTPUT);
}
void loop()
{
  analogValue = analogRead(0);
  voltage = 0.0048*analogValue;
/*
because analogRead return a value between 0 and 1023.
1023 = 5V
0 = 0V
so to convert the analogRead's value to volt 
you need to multiply analogValue by 5/1023 (0.00488)
*/
  if ( voltage >= 1.6 )  // NEW BLUE LED
 {
   digitalWrite(newLED, HIGH);
   delay(ledDelay);
   digitalWrite(newLED, LOW);
 }
 else if ( voltage < 1.6 && voltage > 1.4 ) // OK PEACHISH LED
 {
   digitalWrite(okLED, HIGH);
   delay(ledDelay);
   digitalWrite(okLED, LOW);
 }
 else if ( voltage <= 1.4 ) // OLD RED LED
 {
   digitalWrite(oldLED, HIGH);
   delay(ledDelay);
   digitalWrite(oldLED, LOW);
 }
}
