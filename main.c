#include "Sous_Programme.h"

int main() {
    int nbAlea = 0;
    t_plateau matricePlateau[7][7] = {0};
    FILE *fp;
    int nbCarteL = 0, nbCarteT = 0, nbCarteI = 0;
    int nbJoueurs;
    t_plateau tableauCarte[12] = {0};
    t_joueurs TousLesJoueurs[20];

    int matriceEnLBasDroite[3][3] = {0}, matriceEnLBasGauche[3][3] = {0}, matriceEnTDroite[3][3] = {0},
            matriceEnIDroiteGauche[3][3] = {0}, matriceEnIHautBas[3][3] = {0},
            matriceEnLHautDroite[3][3] = {0}, matriceEnLHautGauche[3][3] = {0}, matriceEnTBas[3][3] = {0},
            matriceEnTGauche[3][3] = {0}, matriceEnTHaut[3][3] = {0}, matriceCarteEnRab[][3] = {0};

    mise_en_place_cartes(matriceEnLBasDroite, matriceEnIHautBas, matriceEnTDroite, matriceEnIDroiteGauche,
                         matriceEnLBasGauche, matriceEnLHautDroite, matriceEnLHautGauche, matriceEnTBas,
                         matriceEnTGauche, matriceEnTHaut);
    tableau_de_carte(tableauCarte, matriceEnLBasDroite, matriceEnIHautBas, matriceEnTDroite, matriceEnIDroiteGauche,
                     matriceEnLBasGauche, matriceEnLHautDroite, matriceEnLHautGauche, matriceEnTBas, matriceEnTGauche,
                     matriceEnTHaut);

    menu(matricePlateau, tableauCarte, fp, nbAlea, nbCarteT, nbCarteI, nbCarteL, TousLesJoueurs, &nbJoueurs, matriceCarteEnRab);
    set_color(BLACK, BLACK);
    system("PAUSE");
    return 0;
}