#include <stdlib.h>
#include <graph.h>
#include <stdio.h>
#include <string.h>
#include "Jeu.h"
#include "ChargerMode.h"

int main() {
    int mainMenu=1;
    InitialiserGraphique();
    CreerFenetre(10,10,1300,760);
    int i;
    ChargerMainMenu();
    while(mainMenu) {
        if (SourisCliquee()) {
            SourisPosition();
            if (_X>1250 && _X <1260+30 && _Y>15 && _Y < 15+30) {
                mainMenu=0;
            }
            else if (_X>445 && _X<445+441 && _Y>230 && _Y<230+129) { /*Joueur choisit le mode facile, charger le mode facile*/
                mainMenu=0;
                ChargerDifficulte(1);
            }
            else if (_X>445 && _X<445+441 && _Y>400 && _Y<400+129) {
                ChargerDifficulte(2);
            }
        }
    }
    FermerGraphique();
    return EXIT_SUCCESS;
}
