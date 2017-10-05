// constantes globales
const int LedRouteVert = 10; // Défini la broche pour le route vert
const int LedRouteOrange = 11; // Défini la broche pour le route orange
const int LedRouteRouge = 12; // Défini la broche pour le route orange
const int LedPietonVert = 8; // Défini la broche pour le piéton vert
const int LedPietonRouge = 9; // Défini la broche pour le piéton orange
const int BoutonAppelPieton = 2; // Défini la broche pour le bouton appel piéton
const int UneSeconde = 1000; // défini la durée d'une seconde
const int AttenteStandardFeuOrange = 1 * UneSeconde; // défini la durée d'attente standard du feu de route orange
const int AttenteStandardFeuRouge = 3 * UneSeconde; // défini la durée d'attente standard du feu de route rouge
const int AttenteStandardFeuVert = 3 * UneSeconde; // défini la durée d'attente standard du feu de route vert
const int AttenteLongueFeuRouge = 5 * UneSeconde; // défini la durée d'attente longue du feu de route rouge
// variables globales
int DureeFeuRouge = AttenteStandardFeuRouge; // défini la durée du feu rouge
int EtatBoutonBoutonAppelPieton = LOW; // l'état courant du bouton appel piéton

void setup() { // Init en sortie
        pinMode(LedRouteVert, OUTPUT); // défini en sortie le route vert
        pinMode(LedRouteOrange, OUTPUT); // défini en sortie le route orange
        pinMode(LedRouteRouge, OUTPUT); // défini en sortie le route rouge
        pinMode(LedPietonVert, OUTPUT); // défini en sortie le piéton vert
        pinMode(LedPietonRouge, OUTPUT); // défini en sortie le piéton rouge
// init en entrée
        pinMode(BoutonAppelPieton, INPUT); // Défini en entrée le bouton appel piéton
} // void setup()
void loop() { // La boucle
        FeuRouteOrange();// effectue toutes les opérations pour que le feu pour les voitures soit orange
        FeuRouteRouge(DureeFeuRouge);// effectue toutes les opérations pour que le feu pour les voitures soit rouge
        FeuRouteVert();// effectue toutes les opérations pour que le feu pour les voitures soit vert
} // La boucle
void FeuRouteVert() { // effectue toutes les opérations pour que le feu pour les voitures soit vert
        digitalWrite(LedPietonVert, LOW); // éteint le piéton vert
        digitalWrite(LedPietonRouge, HIGH); // allume le piéton rouge
        digitalWrite(LedRouteOrange, LOW); // éteint le route orange
        digitalWrite(LedRouteRouge, LOW); // éteint le route rouge
        digitalWrite(LedRouteVert, HIGH); // allume le route vert
        AttenteFeuRouteVert();
} // void FeuRouteVert()
void FeuRouteOrange() {// effectue toutes les opérations pour que le feu pour les voitures soit orange
        digitalWrite(LedPietonRouge, HIGH); // allume le piéton rouge
        digitalWrite(LedPietonVert, LOW); // éteint le piéton vert
        digitalWrite(LedRouteRouge, LOW); // éteint le route rouge
        digitalWrite(LedRouteOrange, HIGH); // allume le route orange
        digitalWrite(LedRouteVert, LOW); // éteint le route vert
        delay(AttenteStandardFeuOrange); // attente 1 seconde
} // void FeuRouteOrange()
void FeuRouteRouge(int MaDuree) { // effectue toutes les opérations pour que le feu pour les voitures soit rouge
        digitalWrite(LedRouteRouge, HIGH); // allume le route rouge
        digitalWrite(LedRouteOrange, LOW); // éteint le route orange
        digitalWrite(LedRouteVert, LOW); // éteint le route vert
        digitalWrite(LedPietonRouge, LOW); // éteint le piéton rouge
        digitalWrite(LedPietonVert, HIGH); // allume le piéton vert
        delay(MaDuree); // attente MaDuree en secondes
} // void FeuRouteRouge(int MaDuree)
void AttenteFeuRouteVert() { // Attends sauf si appui boutton
        int CompteurBoutonAppelPieton = 0; // un compteur d'impulsion du bouton appel piéton
        int IncrementAttente = 10; // pas d'incrément
        DureeFeuRouge = AttenteStandardFeuRouge; // défini la durée du feu rouge
        EtatBoutonBoutonAppelPieton = LOW; // Remet l'état courant du bouton appel piéton
        while (CompteurBoutonAppelPieton<AttenteStandardFeuVert) { // Tant que pas temps du feu vert ni du bouton appel piéton
                delay(IncrementAttente); // attente
                EtatBoutonBoutonAppelPieton = digitalRead(BoutonAppelPieton); // Lit le bouton
                if (EtatBoutonBoutonAppelPieton == HIGH) // Test si le bouton appel piéton a été sollicité
                { // Appel pieton on sort
                        DureeFeuRouge = AttenteLongueFeuRouge; // la durée est mise à attente longue
// L'information n'étant pas précisée, donc on suppose qu'à l'appui du bouton le vert s'éteind de suite.
                        CompteurBoutonAppelPieton = AttenteStandardFeuVert; // Met au maxi pour sortir
                } // Appel pieton on sort
                CompteurBoutonAppelPieton = CompteurBoutonAppelPieton + IncrementAttente;
        } // while (CompteurBoutonAppelPieton<AttenteStandardFeuVert)
} // Tant que pas temps du feu vert ni du bouton appel piéton
