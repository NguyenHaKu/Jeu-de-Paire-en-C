#ifndef _JEU_H
#define _JEU_H
#define delta 1000000L

int ToucheT();

int compteur(int seconde);

int tricher(int** grille, int difficulte, int i, int f);

int GrilleComplete(int** grille, int l, int c);

int ComparerCartes(int carte1, int carte2);

int** DeuxiemeCarte(int ** grille, int carte,int nomCarte, int f, int i, int difficulte, int tempsdepart);

void * PremiereCarte(int** grille, int difficulte);

void jeu(int** grille, int difficulte);

void ChargerDifficulte(int difficulte);

#endif