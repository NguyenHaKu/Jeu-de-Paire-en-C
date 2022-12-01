#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

int** CreerGrille(int* tab, int nbligne, int nbcolonne) {
    /*Fonction qui permet de mélanger les cartes de façon aléatoire et les stocker dans un tableau 2D
    Prend en argument un tableau, le nombre de ligne et colonne (nbligne*nbcolonne=longeur du tableau)
    Renvoie un tableau 2D*/
    srand(time(NULL));
    int** grille = calloc(nbligne, sizeof(int*));
    for (int c = 0; c < nbcolonne; c++) {
      grille[c] = calloc(nbcolonne, sizeof(int));
    }
    int i;
    int image;
    int ligne;
    int colonne;
    int taille =(nbcolonne*nbligne)-1;
    for (ligne=0;ligne<nbligne;ligne++) {
        for (colonne=0;colonne<nbcolonne;colonne++) {
            if (taille>=1) {
                image=rand() % taille;
            }
            else {
                image=0;
            }
            grille[ligne][colonne]=tab[image];
            for (i=image;i<taille;i++) {
                tab[i]=tab[i+1];
            }
            taille--;
        }
    }
    return grille;
}

void CacherGrille(int difficulte) {
    /*Fonction qui dessine une grille de cartes de dos*/
    int ligne;
    int colonne;
    int sprite;
    if (difficulte==1) {
        sprite=ChargerSprite("./images/wood3.png");
        AfficherSprite(sprite,380,110);
        sprite=ChargerSprite("./images/wood2.png");
        for (ligne=0;ligne<4;ligne++) {
            for (colonne=0;colonne<4;colonne++) {
                AfficherSprite(sprite,422+(124*colonne),152+(124*ligne));
            }
        }
    }
    else if (difficulte==2) {
        sprite=ChargerSprite("./images/wood4.png");
        AfficherSprite(sprite,265,10);
        sprite=ChargerSprite("./images/wood2.png");
        for (ligne=0;ligne<6;ligne++) {
            for (colonne=0;colonne<6;colonne++) {
                AfficherSprite(sprite,308+(114*colonne),38+(114*ligne));
            }
        }
    }
}

void AfficherGrille(int** grille, int difficulte) {
    /*Fonction qui dévoile tous les cartes, utile en mode tricheur*/
    int ligne;
    int colonne;
    int image;
    int sprite;
    char str[50];
    AfficherSprite(sprite,380,110);
    if (difficulte==1) {
        for (ligne=0;ligne<4;ligne++) {
            for (colonne=0;colonne<4;colonne++) {
                sprintf(str,"./images/%i.png", grille[ligne][colonne]);
                sprite=ChargerSprite(str);
                AfficherSprite(sprite,432+(124*colonne),162+(124*ligne));
            }
        }
    }
    else if (difficulte==2) {
        for (ligne=0;ligne<6;ligne++) {
            for (colonne=0;colonne<6;colonne++) {
                sprintf(str,"./images/%i.png", grille[ligne][colonne]);
                sprite=ChargerSprite(str);
                AfficherSprite(sprite,308+(114*colonne),38+(114*ligne));
            }
        }
    }
}

int** ChargerFacile() {
    /*Afficher la fenêtre de jeu facile*/
    ChargerImageFond("./images/japanbg.png");
    int i;
    int f;
    int cpt=1;
    char str[50];
    int tab[16];
    int** grille;
    for (i=0; i<16; i=i+2) {
        tab[i]=cpt;
        tab[i+1]=cpt;
        cpt+=1;
    }
    grille=CreerGrille(tab,4,4);
    CacherGrille(1);
    return grille;
}

int** ChargerMoyen() {
    /*Afficher la fenêtre de jeu moyen*/
    ChargerImageFond("./images/japanbg3.png");
    int i;
    int f;
    int cpt=1;
    char str[50];
    int tab[36];
    int** grille;
    for (i=0; i<36; i=i+2) {
        tab[i]=cpt;
        tab[i+1]=cpt;
        cpt+=1;
    }
    grille=CreerGrille(tab,6,6);
    CacherGrille(2);
    return grille;
}
