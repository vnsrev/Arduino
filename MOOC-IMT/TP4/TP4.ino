
#include <Servo.h>   // Chargement de la bibliothèque servo.

Servo barrier;  // Creation de l'objet barrier servant à controler le servo.

const int greenLedPin=2;    // indique que la broche de la LED verte du feu bicolore est la broche 2.
const int redLedPin=3;  // indique que la broche de la LED rouge du feu bicolore est la broche 3.
const int buttonPin=4;  // indique que la broche du bouton est la broche 4.
const int servoPin=9;  // indique que la broche du servo est la broche 9.

int buttonState=0;  // Indiquera par la suite l'état du bouton : HIGH (lorsqu'il est préssé), LOW (lorsqu'il ne l'est pas). Ce n'est pas une constante car l'état variera.
int pos=0;  // Variable servant à conserver la position du servo.
int servoSpeed=30; // Reglage de la vitesse de rotation du servo.
int transitTime=5000; // Temps de passage lorsque la barriere est ouverte.


void setup() {
        Serial.begin(9600); // Initialisation du moniteur serie.
        pinMode(greenLedPin, OUTPUT);   // indique que la broche de la LED verte du feu bicolore est une sortie.
        pinMode(redLedPin, OUTPUT);     // indique que la broche de la LED rouge du feu bicolore est une sortie.
        pinMode(buttonPin, INPUT);      // indique que la broche du bouton est une entrée. On va mesurer sa tension (HIGH ou LOW).
        barrier.attach(servoPin);  // Connection du servo en broche 9 à l'objet barrier.
        digitalWrite(redLedPin, HIGH);  // Allumer la LED rouge du feu bicolore (tension 5V sur la broche).
        barrier.write(0); // Initialisation. Quelque soit la position du servo elle revient à 0.
        Serial.println("La barrière est fermée");   // on affiche "La barrière est fermée" sur le moniteur serie puis on revient à la ligne.

}

void loop() {
        buttonState=digitalRead(buttonPin); // lecture de l'état du bouton : HIGH (lorsqu'il est préssé), LOW (lorsqu'il ne l'est pas).
        if(buttonState==HIGH) { // Cette fonction verifie une condition. Dans ce cas : si l'état du bouton est HIGH le code ci-dessous sera exécuté. Dans le cas inverse (LOW) la boucle (loop) recommencera.
                digitalWrite(redLedPin, LOW);
                digitalWrite(greenLedPin, HIGH);
                for (pos = 0; pos <= 90; pos += 1) { // Rotation de 0 degrees à 90 degrees.
                        barrier.write(pos);  // On demande au servo d'aller à la position "pos".
                        delay(servoSpeed);  // On donne "servoSpeed" (30ms) au servo pour arriver à la position.
                }
                Serial.println("La barrière est ouverte");  // on affiche "La barrière est ouverte" sur le moniteur serie puis on revient à la ligne.
                delay(transitTime); // On attend la valeur de "transitTime" en ms (ici 5s)
                digitalWrite(greenLedPin, LOW); // Eteindre la LED verte du feu bicolore (tension 0V sur la broche).
                digitalWrite(redLedPin, HIGH);  // Allumer la LED rouge du feu bicolore (tension 5V sur la broche).
                Serial.println("La barrière est fermée");   // on affiche "La barrière est fermée" sur le moniteur serie puis on revient à la ligne.
                for (pos = 90; pos >= 0; pos -= 1) { // Rotation de 90 degrees à 0 degrees.
                        barrier.write(pos); // On demande au servo d'aller à la position "pos".
                        delay(servoSpeed);  // On donne la valeur "servoSpeed" (ici 30ms) au servo pour arriver à la position.
                }


        }
}
