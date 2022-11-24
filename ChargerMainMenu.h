#include <stdlib.h>
#include <graph.h>

void ChargerMainMenu() {
    int mainMenu=1;
    int panneau;
    panneau=ChargerSprite("./images/scroll2.png");
    ChargerImageFond("./images/japanbg4.jpg");
    ChargerImage("./images/scroll.png",242,15,-0,-0,817,300);
    ChargerImage("./images/matchpairs.png",350,77,-0,-0,598,54);
    AfficherSprite(panneau,445,230);
    ChargerImage("./images/easy.png",520,273,-0,-0,318,54);
    AfficherSprite(panneau,445,400);
    ChargerImage("./images/medium.png",503,446,-0,-0,334,54);
    AfficherSprite(panneau,445,570);
    ChargerImage("./images/hard.png",522,615,-0,-0,318,54);
    ChargerImage("./images/boutonquitter.png",1250,15,-0,-0,30,30);
}