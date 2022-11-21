#include <stdlib.h>
#include <graph.h>

void ChargerMainMenu() {
    couleur c;
    int apple;
    int mainMenu=1;
    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    ChargerImageFond("./images/casinotable.png");
    EcrireTexte(587,60,"Match Pairs",2);
    DessinerRectangle(460,135,400,110);
    EcrireTexte(588,200,"Easy : 4x4",2);
    DessinerRectangle(460,315,400,110);
    EcrireTexte(583,380,"Medium : 5x4",2);
    DessinerRectangle(460,505,400,110);
    EcrireTexte(588,570,"Hard : 6x6",2);
    ChoisirCouleurDessin(CouleurParNom("red"));
    RemplirRectangle(1260,17,25,25);
    ChoisirCouleurDessin(CouleurParNom("white"));
    DessinerRectangle(1260,17,25,25);
    DessinerSegment(1260,17,1260+25,17+25);
    DessinerSegment(1260,17+25,1260+25,17);
    ChoisirEcran(1);
    EffacerEcran(CouleurParNom("orange"));
    ChoisirEcran(0);
}