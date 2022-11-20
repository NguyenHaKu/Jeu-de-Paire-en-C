#include<graph.h>
#include<stdio.h>
 
#define tx 300
#define ty 300
 
int main(void)
{
	char t[50];
	int x,y;   
	couleur c;
 
	InitialiserGraphique();
	CreerFenetre(100,100,tx,ty);
	c=CouleurParNom("red"); 
    ChoisirCouleurDessin(c);
	SourisPosition();
	x=_X;
	y=_Y;
	sprintf(t,"x=%3d:y=%3d",_X,_Y);
	EffacerEcran(CouleurParNom("white"));
	EcrireTexte((tx-TailleChaineEcran(t,0))/2,
			ty/2,t,0);
 
	while(!SourisCliquee())
	{
		SourisPosition();
		if (_X!=x||_Y!=y)
		{
			sprintf(t,"x=%3d:y=%3d",_X,_Y);
			EffacerEcran(CouleurParNom("white"));
			EcrireTexte((tx-TailleChaineEcran(t,0))/2,
					ty/2,t,0);
			x=_X;
			y=_Y;
		}
	}
	FermerGraphique();
}