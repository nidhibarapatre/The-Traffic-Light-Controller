const int TrigPin = 14; 
const int echoPin = 15;
const int g1=21;
const int y1=20;
const int r1=19;
const int g2=18;
const int y2=17;
const int r2=16;
const int g3=A4;
const int y3=3;
const int r3=4;
const int g4=5;
const int y4=10 ;
const int r4=11;
const int pRed = A2;
const int pgreen = A3;
const int pIN = 2;

long microsecondsToInches(long microseconds){
     return microseconds / 74 / 2;
}
long microsecondsToCentimeters (long microseconds){
    return microseconds / 29 / 2;
}

void setup() {
  // put your setup code here, to run once:
    pinMode (r1, OUTPUT);
    pinMode (y1, OUTPUT);
    pinMode (g1, OUTPUT);
    pinMode (r2, OUTPUT);
    pinMode (y2, OUTPUT);
    pinMode (g2, OUTPUT);
    pinMode (r3, OUTPUT);
    pinMode (y3, OUTPUT);
    pinMode (g3, OUTPUT);
    pinMode (r4, OUTPUT);
    pinMode (y4, OUTPUT);
    pinMode (g4, OUTPUT);
    pinMode (pRed, OUTPUT);
    pinMode (pgreen, OUTPUT);
    pinMode (pIN, INPUT);
    digitalWrite (r1,HIGH);
    digitalWrite (r2,HIGH);
    digitalWrite (r3,HIGH);
    digitalWrite (r4,HIGH);
    digitalWrite (pRed,HIGH);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    long duration, inches, cm;
    pinMode(TrigPin, OUTPUT);
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, HIGH);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    Serial.print("Distance = ");
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.println();
    if(inches <= 200){
        int crossIn = digitalRead(pIN);
        if(crossIn == HIGH){
            WalkCycle();
        }
        else{
            delay(100);
            digitalWrite (r1, LOW);
            digitalWrite (g1, HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4,HIGH);
            delay(400);
        }
        int crossIn2 = digitalRead(pIN);
        if(crossIn2 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(g1,LOW);
            digitalWrite(y1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4,HIGH);
            delay(200);
        }
        int crossIn3 = digitalRead(pIN);
        if(crossIn3 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(y1,LOW);
            digitalWrite(r2,LOW);

            digitalWrite(r1,HIGH);
            digitalWrite(g2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4,HIGH);
            delay(400);
        }
        
        int crossIn4 = digitalRead (pIN);
        if(crossIn4 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(g2,LOW);

            digitalWrite(y2,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4,HIGH);
            delay(200);
        }

        int crossIn5 = digitalRead (pIN);
        if(crossIn5 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(y2,LOW);
            digitalWrite(r3,LOW);

            digitalWrite(g3,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r4,HIGH);
            delay(400);
        }

        int crossIn6 = digitalRead (pIN);
        if(crossIn6 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(g3,LOW);

            digitalWrite(y3,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r4,HIGH);
            delay(200);
        }

        int crossIn7 = digitalRead (pIN);
        if(crossIn7 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(y3,LOW);
            digitalWrite(r3,LOW);
            digitalWrite(r4,LOW);

            digitalWrite(g4,HIGH);
            digitalWrite(r1,HIGH);
            // digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            delay(400);
        }

        int crossIn8 = digitalRead (pIN);
        if(crossIn8 == HIGH)
        {
            WalkCycle();
        }
        else{
            digitalWrite(g4,LOW);
            digitalWrite(r4,LOW);

            digitalWrite(y4,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            delay(200);
        }
        digitalWrite(y4,LOW);
        digitalWrite(r4,HIGH);
        digitalWrite(g1,HIGH);
        digitalWrite(r1,LOW);
        
    }
    else if(inches >=200){
        int crossIn = digitalRead(pIN);
        if(crossIn == HIGH){
            WalkCycle();
        }
        else{
            delay(100);
            digitalWrite(r1,LOW);
            digitalWrite(g1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4, HIGH);
            delay(600);
        }

        int crossIn2 = digitalRead(pIN);
        if(crossIn2 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(g1,LOW);
            digitalWrite(y1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4, HIGH);
            delay(200);
        }

        int crossIn3 = digitalRead(pIN);
        if(crossIn3 == HIGH){
            WalkCycle();
        }
        else{
            delay(100);
            digitalWrite(y1,LOW);
            digitalWrite(r2,LOW);

            digitalWrite(r1,HIGH);
            digitalWrite(g2,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4, HIGH);
            delay(600);
        }

        int crossIn4 = digitalRead(pIN);
        if(crossIn4 == HIGH){
            WalkCycle();
        }
        else{
           
            digitalWrite(g2,LOW);

            digitalWrite(y2,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r3,HIGH);
            digitalWrite(r4, HIGH);
            delay(200);
        }

        int crossIn5 = digitalRead(pIN);
        if(crossIn5 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(y2,LOW);
            digitalWrite(r3, LOW);

            digitalWrite(g3,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r4, HIGH);
            delay(600);
        }

        int crossIn6 = digitalRead(pIN);
        if(crossIn6 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(g3,LOW);
            digitalWrite(y3,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r4, HIGH);
            delay(200);
            // doubt in this crossIn
        }

        int crossIn7 = digitalRead(pIN);
        if(crossIn7 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(y3,LOW);
            digitalWrite(r3,LOW);
            digitalWrite(r4,LOW);

            digitalWrite(g4,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3,HIGH);
            delay(600);
        }

        int crossIn8 = digitalRead(pIN);
        if(crossIn8 == HIGH){
            WalkCycle();
        }
        else{
            digitalWrite(g4,LOW);
            digitalWrite(r4,LOW);

            digitalWrite(y4,HIGH);
            digitalWrite(r1,HIGH);
            digitalWrite(r2,HIGH);
            digitalWrite(r3, HIGH);
            delay(200);
        }
        digitalWrite(y4,LOW);
        digitalWrite(r4,HIGH);
        digitalWrite(g1,HIGH);
        digitalWrite(r1,LOW);
       
    }

}

void WalkCycle(){
    delay(100);
    digitalWrite(g1,LOW);
    digitalWrite(g2,LOW);
    digitalWrite(g3,LOW);
    digitalWrite(g4,LOW);
    digitalWrite(y1,LOW);
    digitalWrite(y2,LOW);
    digitalWrite(y3,LOW);
    digitalWrite(y4,LOW);
    digitalWrite(r1,HIGH);
    digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);
    digitalWrite(r4,HIGH);

    digitalWrite(pgreen, HIGH);
    digitalWrite(pRed, LOW);
    delay(500);
    digitalWrite(pgreen, LOW);
    delay(250);

    for(int x=0; x<5; x++){
        digitalWrite(pgreen, HIGH);
        delay(250);
        digitalWrite(pgreen,LOW);
        delay(250);
    }
    digitalWrite(pRed, HIGH);
}
