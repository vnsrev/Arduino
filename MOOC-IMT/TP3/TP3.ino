
/* Pour plus de clarté dans le code on associe à une variable le numéro de la broche à laquelle le composant est branché.
Ce sont des constantes car le branchement ne changera pas */

const int buzzerPin=8;
// indique que la broche dbuzzer est la broche 8.
const int lightSensorPin=A2;
// indique que la broche de la photorésistance est la broche A2 (broche analogique).

int sensorValue=0;
// indique la valeur mesuré par la photorésistance.
int frequenceValue=0;
// indique la valeur de la fréquence sonore après conversion de la valeur de la photorésistance.

void setup() {

  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);
}

void loop() {
  sensorValue=analogRead(lightSensorPin);
  frequenceValue=map(sensorValue,0,1023,30000,50);
  // tone(buzzerPin, frequenceValue, 200);

  Serial.print("sensor =");
  Serial.print(sensorValue);
  Serial.print("\t Frequence =");
  Serial.println(frequenceValue);
}
