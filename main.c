#include "Sous_Programme.h"

int main() {
    t_plateau matricePlateau[7][7] = {0};
    t_plateau tableauCarte[10] = {0};
    FILE *fp;
    t_joueurs TousLesJoueurs[4];

    menu(matricePlateau, tableauCarte, fp, TousLesJoueurs);
    set_color(BLACK, BLACK);
    system("PAUSE");
    return 0;
}