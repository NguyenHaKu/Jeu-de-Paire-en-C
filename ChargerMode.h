#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <time.h>


void AfficherGrille(int* tab,int nbcolonne, int nbligne) {
    int colonne;
    int ligne;
    int image;
    int taille=15;
    int i;
    int sprite;
    char str[50];
    srand(time(NULL));
    for (ligne=0;ligne<nbligne;ligne++) {
        for (colonne=0;colonne<nbcolonne;colonne++) {
            if (taille>=1) {
                image=rand() % taille;
            }
            else {
                image=0;
            }
            printf("%i\n",taille);
            sprintf(str,"./images/%i.png", tab[image]);
            for (i=image;i<taille;i++) {
                tab[i]=tab[i+1];
            }
            sprite=ChargerSprite(str);
            AfficherSprite(sprite,64*colonne,64*ligne);
            taille--;
            Touche();
        }
    }
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
    AfficherGrille(tab,4,4);
}

void ChargerMode(int mode) {
    if (mode==1) {
        ChargerModeFacile();
    }
}