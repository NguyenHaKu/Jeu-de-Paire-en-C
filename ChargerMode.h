#ifndef _CHARGERMODE_H
#define _CHARGERMODE_H

int** CreerGrille(int* tab, int nbligne, int nbcolonne);

void CacherGrille(int** grille, int difficulte, int i, int f);

void AfficherGrille(int** grille, int difficulte);

int** ChargerFacile();

int** ChargerMoyen();

void ChargerMainMenu();

#endif