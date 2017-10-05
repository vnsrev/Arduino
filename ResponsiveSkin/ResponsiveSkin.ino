
#include <Servo.h> // chargement de la bibliotheque servo

Servo arm1;

const int SensorPin=A2;
const int arm1Pin=9;

int sensorValue=0;
int currentPosition=0;
int newPosition=0;
int pos=0;
int servoSpeed=20;
int refresh=1000;
int sensorSensibility=2;


int displayData(){
        Serial.print("sensor =");
        Serial.print(sensorValue);
        Serial.print("\t Angle d'ouverture =");
        Serial.print(currentPosition);
        Serial.print("\t Angle mesuré =");
        Serial.println(pos);
}

int initialise(){
        arm1.write(50);
        delay(3000);
}

void setup() {
        Serial.begin(9600);
        pinMode(SensorPin, INPUT);
        arm1.attach(arm1Pin);
        initialise();
}

void loop() {
        currentPosition=arm1.read();
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
        pos=arm1.read();
        displayData();
        delay(refresh);
}
