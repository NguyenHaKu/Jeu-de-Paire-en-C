#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "ChargerMode.h"


int ComparerCartes(int carte1, int carte2) {
    if (carte1==carte2) {
        return 1;
    }
    else {
        return 0;
    }
}

void DeuxiemeCarte(int carte,int f, int i) {
    AfficherSprite(carte,432+(124*f),162+(124*i));
}

void PremiereCarte(int ** grille, int carte,int nomCarte, int f, int i) {
    int ligne, colonne;
    int carte1=nomCarte;
    int carte2;
    int visible=1;
    time_t suivant;
    int asec=1;
    char str[50];
    int deuxiemecarte=0;
    AfficherSprite(carte,432+(124*f),162+(124*i));
    while (!deuxiemecarte) {
        if (SourisCliquee()) {
            SourisPosition();
            for (ligne=0; ligne<4; ligne++) {
                for (colonne=0; colonne<4; colonne++) {
                    if (_X>422+(124*colonne) && _X <422+(124*colonne)+84 && _Y>152+(124*ligne) && _Y < 152+(124*ligne)+84 &&(ligne!=i || colonne!=f)) {
                        carte2=grille[ligne][colonne];
                        sprintf(str,"./images/%i.png",grille[ligne][colonne]);
                        carte=ChargerSprite(str);
                        DeuxiemeCarte(carte,colonne,ligne);
                        suivant=time(NULL);
                        if (!ComparerCartes(carte1,carte2)){
                            while(asec){
                                if (time(NULL)==suivant+1) {
                                    carte=ChargerSprite("./images/wood2.png");
                                    AfficherSprite(carte,422+(124*f),152+(124*i));
                                    AfficherSprite(carte,422+(124*colonne),152+(124*ligne));
                                    asec=0;
                                }
                            }
                        }
                        deuxiemecarte=1;
                    }
                }
            }
        }
    }
}

void jeu(int** grille, int difficulte) {
    int tricheur=0;
    int i, f;
    int carte;
    char str[50];
    if (difficulte==1) {
        while(!tricheur) {
            if (SourisCliquee()) {
                SourisPosition();
                for (i=0; i<4; i++) {
                    for (f=0; f<4; f++) {
                        if (_X>422+(124*f) && _X <422+(124*f)+84 && _Y>152+(124*i) && _Y < 152+(124*i)+84) {
                            sprintf(str,"./images/%i.png",grille[i][f]);
                            carte=ChargerSprite(str);
                            AfficherSprite(carte,432+(124*f),162+(124*i));
                            PremiereCarte(grille, carte, grille[i][f], f,i);
                            f=3;
                            i=3;
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