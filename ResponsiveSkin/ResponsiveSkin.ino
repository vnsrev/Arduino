
#include <Servo.h> // chargement de la bibliotheque servo

Servo arm1;

const int SensorPin=A2;
const int arm1Pin=9;

int sensorValue=0;
int currentPosition=0;
int newPosition=0;
int servoSpeed=20;
int refresh=5000;
int sensorSensibility=2;

int initialise(){
        arm1.write(0);
        delay(3000);
}

int displayData(){
        Serial.print("sensor =");
        Serial.print(sensorValue);
        Serial.print("\t Angle d'ouverture =");
        Serial.println(currentPosition);
}

void setup() {
        Serial.begin(9600);
        pinMode(SensorPin, INPUT);
        arm1.attach(arm1Pin);
        initialise();
}

void loop() {
        sensorValue=analogRead(SensorPin);
        newPosition=map(sensorValue,0,1023,120,0);
        if(currentPosition<newPosition+sensorSensibility && currentPosition>newPosition-sensorSensibility) {
                Serial.println("don't move");
        }
        else {
                if(currentPosition<newPosition) {
                        for(currentPosition; currentPosition<=newPosition; currentPosition +=1) {
                                arm1.write(currentPosition);
                                delay(servoSpeed);
                        }
                }
                else{
                        for(currentPosition; currentPosition>=newPosition; currentPosition -=1) {
                                arm1.write(currentPosition);
                                delay(servoSpeed);
                        }
                }
        }
        displayData();
        delay(refresh);
}
