#include <stdlib.h>
#include <graph.h>
#include <stdio.h>

int main()
{
    char quit;
    couleur c;
    InitialiserGraphique();
    CreerFenetre(10,10,1300,760);
    c=CouleurParComposante(31, 31, 96);
    EffacerEcran(c);
    c=CouleurParNom("white");
    ChoisirCouleurDessin(c);
    ChargerImage("./images/fondaccueil.jpg",300,240,1300,760,0,0);
    EcrireTexte(587,60,"Match Pairs",2);
    DessinerRectangle(460,135,400,110);
    EcrireTexte(588,200,"Easy : 4x4",2);
    DessinerRectangle(460,315,400,110);
    EcrireTexte(583,380,"Medium : 6x5",2);
    DessinerRectangle(460,505,400,110);
    EcrireTexte(588,570,"Hard : 8x6",2);
    EcrireTexte(12,748,"Press Q to quit the game",1);
    while(quit!='q' | quit!='Q') {
        quit=Touche();
        if (quit=='q' | quit=='Q') {
            FermerGraphique();
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}
