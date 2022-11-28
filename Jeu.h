#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "ChargerMode.h"

void DevoilerCarte(int carte,int f, int i) {
    int visible=1;
    time_t suivant;
    AfficherSprite(carte,432+(124*f),162+(124*i));
    suivant = time(NULL)+1;
    while (visible) {
        if (time(NULL)==suivant)
        {
            /* une periode s'est écoulé */
            /* prochaine date */
            break;
        }
    }
    carte=ChargerSprite("./images/wood2.png");
    AfficherSprite(carte,422+(124*f),152+(124*i));
}
void jeu(int** grille, int difficulte) {
    int tricher=0;
    int i, f;
    int carte;
    char str[50];
    if (difficulte==1) {
        while(!tricher) {
            if (SourisCliquee()) {
                SourisPosition();
                for (i=0; i<4; i++) {
                    for (f=0; f<4; f++) {
                        if (_X>422+(124*f) && _X <422+(124*f)+84 && _Y>152+(124*i) && _Y < 152+(124*i)+84) {
                            sprintf(str,"./images/%i.png",grille[i][f]);
                            carte=ChargerSprite(str);
                            AfficherSprite(carte,432+(124*f),162+(124*i));
                            
                            DevoilerCarte(carte,f,i);
                        }
                    }
                }
            }
        }
    }
}

void ChargerDifficulte(int difficulte) {
    /*Charge la difficulté choisi au menu principal*/
    if (difficulte==1) {
        jeu(ChargerFacile(), 1);
    }
    else if (difficulte=2) {
        jeu(ChargerMoyen(), 2);
    }
}