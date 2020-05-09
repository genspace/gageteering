int resval = 0; //holds value
int respin = A5; //sensor pin
char resval_char[] = "";
 
void setup() {
  // initialize serial communications:
  Serial.begin(9600);
}
 
void loop() {
 
  resval = analogRead(respin); // read data from analog
 if (resval<=100) {
  resval_char = "water level empty";
 }
 else if (resval>100 && resval <=300) {
  resval_char = "water level low";
 }
  else if (resval>300 && resval <=330) {
  resval_char = "water level medium";
 }
  else if (resval>330) {
  resval_char = "water level high";
 }

  Serial.println(resval_char); 
  delay(1000);
}
