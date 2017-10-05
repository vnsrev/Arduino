
/* Pour plus de clarté et de praticité dans le code on associe à une variable le numéro de la broche à laquelle le composant est branché. Ce sont des constantes car le branchement ne changera pas */

const int buzzerPin=8;  // indique que la broche dbuzzer est la broche 8.
const int lightSensorPin=A2;    // indique que la broche de la photorésistance est la broche A2 (broche analogique).

// Ces variables ont des valeurs qui evoluent.

int sensorValue=0;  // indique la valeur mesuré par la photorésistance.
int frequenceValue=0;   // indique la valeur de la fréquence sonore après conversion de la valeur de la photorésistance.

void setup() {  // le code dans cette fonction est exécuté une fois au début.
        Serial.begin(9600);
        pinMode(buzzerPin, OUTPUT);   // indique que la broche du buzzer est une sortie. On va modifier sa tension
        pinMode(lightSensorPin, INPUT);    // indique que la broche du bouton est une entrée.
}

void loop() {   // loop est une fonction qui va exécuter les instructions encore et encore.

        sensorValue=analogRead(lightSensorPin);     // la variable sensorValue prend la valeur donnée par la photorésistance.
        frequenceValue=map(sensorValue,0,1023,50,30000);    // La fonction fait passer une valeur appartenant au domaine de 0 à 1023 à un domaine allant de 50 à 30000.
        tone(buzzerPin, frequenceValue);    // le buzzer emet un son de la valeur de la frequence obtenue grace à la fonction map().

        Serial.print("sensor =");   // on affiche "sensor =" sur le moniteur serie.
        Serial.print(sensorValue);  // on affiche la valeur mesurée en face de "sensor =" (sur la meme ligne) sur le moniteur serie.
        Serial.print("\t Frequence =");   // on affiche sur une deuxieme colone, "Fréquence =" sur le moniteur serie.
        Serial.println(frequenceValue); // on affiche en face de "frequence =" la valeur obtenue grace à la fonction map().
}
