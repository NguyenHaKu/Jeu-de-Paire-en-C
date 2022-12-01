#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include "ChargerMode.h"
#define delta 1000000L

int jeutourne=1;

int compteur(int seconde) {
    char temps[4];
    unsigned long timer=Microsecondes()+delta;
    if (Microsecondes()>=timer){
        timer=Microsecondes()+delta;
        seconde++;
    }
    return seconde;
}

int tricher(int** grille, int difficulte) {
    int touche;
    int tempsdetriche;
    if (ToucheEnAttente()) {
        touche= Touche();
        if (touche== 84 || 114) {
            while (1) {
                tempsdetriche=compteur(tempsdetriche);
                CacherGrille(difficulte);
                AfficherGrille(grille, difficulte);
                touche=Touche();
                if (touche== 84 || 114){
                    CacherGrille(difficulte);
                    printf("%i", tempsdetriche);
                    return tempsdetriche;
                }
            }
        }
    }
}

int GrilleComplete(int** grille, int l, int c) {
    int i, f;
    for (i=0; i<l; i++) {
        for (f=0; f<c; f++) {
            if (grille[i][f]!=0) {
                return 0;
            }
        }
    }
    return 1;
}

int ComparerCartes(int carte1, int carte2) {
    if (carte1==carte2) {
        return 1;
    }
    else {
        return 0;
    }
}

int** DeuxiemeCarte(int ** grille, int carte,int nomCarte, int f, int i, int difficulte, int tempsdepart) {
    int ligne, colonne;
    int carte1=nomCarte, carte2;
    int asec=1, seconde=0, tempsdetriche;
    int deuxiemecarte=0;
    unsigned long suivant;
    unsigned long timer=time(NULL)+1;
    char str[50], temps[4];
    if (difficulte==1) {
        while (!deuxiemecarte) {
            tempsdetriche=tricher(grille, difficulte);
            if (time(NULL)>=timer){
                timer=time(NULL)+1;
                seconde=time(NULL)-tempsdepart-tempsdetriche;
                sprintf(temps,"%i",seconde);
                ChoisirCouleurDessin(CouleurParNom("white"));
                RemplirRectangle(1225,30,40,40);
                ChoisirCouleurDessin(CouleurParNom("black"));
                EcrireTexte(1230,70,temps, 2);
            }

            if (SourisCliquee()) {
                SourisPosition();
                for (ligne=0; ligne<4; ligne++) {
                    for (colonne=0; colonne<4; colonne++) {
                        if (_X>422+(124*colonne) && _X<422+(124*colonne)+84 
                        && _Y>152+(124*ligne) && _Y < 152+(124*ligne)+84 
                        &&(ligne!=i || colonne!=f)
                        && grille[ligne][colonne]!=0) 
                        {   
                            carte2=grille[ligne][colonne];
                            sprintf(str,"./images/%i.png",grille[ligne][colonne]);
                            carte=ChargerSprite(str);
                            AfficherSprite(carte,432+(124*colonne),162+(124*ligne));
                            suivant=Microsecondes()+delta;
                            if (!ComparerCartes(carte1,carte2)){
                                while(asec){
                                    tempsdetriche=tricher(grille, difficulte);
                                    if (time(NULL)>=timer){
                                        timer=time(NULL)+1;
                                        seconde=time(NULL)-tempsdepart-tempsdetriche;
                                        sprintf(temps,"%i",seconde);
                                        ChoisirCouleurDessin(CouleurParNom("white"));
                                        RemplirRectangle(1225,30,40,40);
                                        ChoisirCouleurDessin(CouleurParNom("black"));
                                        EcrireTexte(1230,70,temps, 2);
                                    }
                                    if (Microsecondes()>=suivant) {
                                        carte=ChargerSprite("./images/wood2.png");
                                        AfficherSprite(carte,422+(124*f),152+(124*i));
                                        AfficherSprite(carte,422+(124*colonne),152+(124*ligne));
                                        asec=0;
                                    }
                                }
                            }
                            else {
                                grille[ligne][colonne]=0;
                                grille[i][f]=0;
                            }
                            deuxiemecarte=1;
                        }
                    }
                }
            }
        }
    }
    return grille;
}

void * PremiereCarte(int** grille, int difficulte){
    int i, f, carte, tempsdetriche=0, seconde=0;
    unsigned long tempsdepart=time(NULL);
    unsigned long timer=time(NULL)+1;
    char str[50], temps[4];
    if (difficulte==1) {
        while (jeutourne) {
            tempsdetriche=tricher(grille, difficulte);
            if (time(NULL)>=timer){
                timer=time(NULL)+1;
                seconde=time(NULL)-tempsdepart-tempsdetriche;
                sprintf(temps,"%i",seconde);
                ChoisirCouleurDessin(CouleurParNom("white"));
                RemplirRectangle(1225,30,40,40);
                ChoisirCouleurDessin(CouleurParNom("black"));
                EcrireTexte(1230,70,temps, 2);
            }
            if (SourisCliquee()) {
                SourisPosition();
                for (i=0; i<4; i++) {
                    for (f=0; f<4; f++) {
                        if (_X>422+(124*f) && _X <422+(124*f)+84 
                        && _Y>152+(124*i) && _Y < 152+(124*i)+84
                        && grille[i][f]!=0) 
                        {
                            sprintf(str,"./images/%i.png",grille[i][f]);
                            carte=ChargerSprite(str);
                            AfficherSprite(carte,432+(124*f),162+(124*i));
                            grille=DeuxiemeCarte(grille, carte, grille[i][f], f, i, difficulte, tempsdepart);
                            f=3;
                            i=3;
                        }
                    }
                }
            }
            if (GrilleComplete(grille, 4, 4)) {
                puts("Félicitation!");
                jeutourne=0;
            }
        }
    }
}
void jeu(int** grille, int difficulte) {
    PremiereCarte(grille, difficulte);
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