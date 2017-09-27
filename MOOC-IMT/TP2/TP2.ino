/* Pour plus de clarté dans le code on associe à une variable le numéro de la broche à laquelle le composant est branché.
Ce sont des constantes car le branchement ne changera pas */

const int triGreen=10;
// indique que la broche de la LED verte du feu tricolore est la broche 10
const int triOrange=11;
// indique que la broche de la LED orange du feu tricolore est la broche 11
const int triRed=12;
// indique que la broche de la LED rouge du feu tricolore est la broche 12

const int biGreen=8;
// indique que la broche de la LED verte du feu bicolore est la broche 8
const int biRed=9;
// indique que la broche de la LED rouge du feu bicolore est la broche 9

const int buttonPin=2;
// indique que la broche du bouton est la broche 2.

int buttonState=0;
// indiquera par la suite l'état du bouton : HIGH (lorsqu'il est préssé), LOW (lorsqu'il ne l'est pas). Ce n'est pas une constante car l'état variera.

void setup() {
  // le code dans cette fonction est exécuté une fois au début.

  pinMode(triGreen, OUTPUT);
  // indique que la broche de la LED verte du feu tricolore est une sortie.   // on va modifier sa tension
  pinMode(triOrange, OUTPUT);
  // indique que la broche de la LED orange du feu tricolore est une sortie.
  pinMode(triRed, OUTPUT);
  // indique que la broche de la LED rouge du feu tricolore est une sortie.
  pinMode(biGreen, OUTPUT);
  // indique que la broche de la LED verte du feu bicolore est une sortie.
  pinMode(biRed, OUTPUT);
  // indique que la broche de la LED rouge du feu bicolore est une sortie.
  pinMode(buttonPin, INPUT);
  // indique que la broche du bouton est une entrée.
  // on va mesurer sa tension (HIGH ou LOW)
}

void loop() {
  // loop est une fonction qui va exécuter les instructions encore et encore.

  digitalWrite(biRed, HIGH);
  // allumer la LED rouge du feu bicolore (tension 5V sur la broche).
  digitalWrite(triOrange, HIGH);
  // allumer la LED orange du feu tricolore (tension 5V sur la broche).
  delay(1000);
  // attendre 1000ms = 1s
  digitalWrite(triOrange, LOW);
  // éteindre la LED orange du feu tricolore (tension 0V sur la broche).
  digitalWrite(triRed, HIGH);
  // allumer la LED rouge du feu tricolore (tension 5V sur la broche).
  delay(3000);
  // attendre 3000ms = 3s
  digitalWrite(triRed, LOW);
  // éteindre la LED rouge du feu tricolore (tension 0V sur la broche).
  digitalWrite(triGreen, HIGH);
  // allumer la LED verte du feu tricolore (tension 5V sur la broche).
  delay(3000);
  // attendre 3000ms = 3s
  digitalWrite(triGreen, LOW);
  // éteindre la LED verte du feu tricolore (tension 0V sur la broche).

  buttonState=digitalRead(buttonPin);
  // lecture de l'état du bouton : HIGH (lorsqu'il est préssé), LOW (lorsqu'il ne l'est pas)

    if(buttonState==HIGH){
      /* Cette fonction verifie une condition.
      Dans ce cas : si l'état du bouton est HIGH le code ci-dessous sera exécuté.
      Dans le cas inverse (LOW) la boucle (loop) recommencera */

      digitalWrite(triOrange, HIGH);
      // allumer la LED orange du feu tricolore (tension 5V sur la broche).
      delay(1000);
      // attendre 1000ms = 1s
      digitalWrite(triOrange, LOW);
      // éteindre la LED orange du feu tricolore (tension 0V sur la broche).
      digitalWrite(triRed, HIGH);
      // allumer la LED rouge du feu tricolore (tension 5V sur la broche).
      digitalWrite(biRed, LOW);
      // éteindre la LED rouge du feu tricolore (tension 0V sur la broche).
      digitalWrite(biGreen, HIGH);
      // allumer la LED rouge du feu bicolore (tension 5V sur la broche).
      delay(5000);
      // attendre 5000ms = 5s
      digitalWrite(triRed, LOW);
      // éteindre la LED rouge du feu bicolore (tension 0V sur la broche).
      digitalWrite(biGreen, LOW);
      // éteindre la LED verte du feu bicolore (tension 0V sur la broche).
    }
// Retour au départ de la boucle (loop)
}
