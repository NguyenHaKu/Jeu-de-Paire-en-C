#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>
#include <stdio.h>


void AfficherGrille(int** tab, int nbligne, int nbcolonne) {
    int ligne;
    int colonne;
    int image;
    int taille=15;
    int i;
    int sprite;
    char str[50];
    for (ligne=0;ligne<nbligne;ligne++) {
        for (colonne=0;colonne<nbcolonne;colonne++) {
            sprintf(str,"./images/%i.png", tab[ligne][colonne]);
            sprite=ChargerSprite(str);
            AfficherSprite(sprite,64*colonne,64*ligne);
            taille--;
        }
    }
    Touche();
}


int** CreerGrille(int* tab, int nbligne, int nbcolonne) {
    srand(time(NULL));
    int** grille = calloc(nbligne, sizeof(int*));
    for (int c = 0; c < nbcolonne; c++) {
      grille[c] = calloc(nbcolonne, sizeof(int));
    }
    int i;
    int image;
    int ligne;
    int colonne;
    int taille =15;
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


void ChargerModeFacile() {
    ChargerImageFond("./images/casinotable.png");
    int i;
    int f;
    int cpt=1;
    char str[50];
    int tab[16];
    for (i=0; i<16; i=i+2) {
        tab[i]=cpt;
        tab[i+1]=cpt;
        cpt+=1;
    }
    AfficherGrille(CreerGrille(tab,4,4),4,4); /**/
}

void ChargerMode(int mode) {
    if (mode==1) {
        ChargerModeFacile();
    }
}