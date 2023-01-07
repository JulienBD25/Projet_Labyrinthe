//
// Created by Ce PC on 14/12/2022.
//

#include "Sous_Programme.h"
static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;

////////////////////////////////////////////////MISE EN FORME///////////////////////////////////////////////////////////
///mise en forme affichage
void swag(){
    set_color(CYAN, BLACK);
    printf(
            "\t\t$$\\                $$\\                           $$\\            $$\\     $$\\                 \n"
            "\t\t$$ |               $$ |                          \\__|           $$ |    $$ |                \n"
            "\t\t$$ |      $$$$$$\\  $$$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\ $$$$$$$\\ $$$$$$\\   $$$$$$$\\   $$$$$$\\  \n"
            "\t\t$$ |      \\____$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\ $$ |$$  __$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ \n"
            "\t\t$$ |      $$$$$$$ |$$ |  $$ |$$ |  $$ |$$ |  \\__|$$ |$$ |  $$ | $$ |    $$ |  $$ |$$$$$$$$ |\n"
            "\t\t$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |$$ |  $$ | $$ |$$\\ $$ |  $$ |$$   ____|\n"
            "\t\t$$$$$$$$\\\\$$$$$$$ |$$$$$$$  |\\$$$$$$$ |$$ |      $$ |$$ |  $$ | \\$$$$  |$$ |  $$ |\\$$$$$$$\\ \n"
            "\t\t\\________|\\_______|\\_______/  \\____$$ |\\__|      \\__|\\__|  \\__|  \\____/ \\__|  \\__| \\_______|\n"
            "\t\t                             $$\\   $$ |                                                     \n"
            "\t\t                             \\$$$$$$  |                                                     \n"
            "\t\t                              \\______/                                                      ");
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void getCursorPosition(int *x, int *y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdout, &csbi)) {
        *x = csbi.dwCursorPosition.X;
        *y = csbi.dwCursorPosition.Y;
    }
}

void text_color(int color)
{
    __FOREGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}

void bg_color(int color){
    __BACKGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}

void set_color(int colorT,int colorBg){
    __FOREGROUND=colorT;
    __BACKGROUND=colorBg;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}

//////////////////////////////////////////////////////CARTES////////////////////////////////////////////////////////////
void carte (t_plateau tableauCarte[10]){
    ///cartes en L
    int matriceEnLBasDroite[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnLBasDroite[i][0] = 1;
        matriceEnLBasDroite[2][i] = 1;
    }
    matriceEnLBasDroite[0][2] = 1;

    int matriceEnLBasGauche[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnLBasGauche[i][2] = 1;
        matriceEnLBasGauche[2][i] = 1;
    }
    matriceEnLBasGauche[0][0] = 1;

    int matriceEnLHautDroite[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnLHautDroite[0][i] = 1;
        matriceEnLHautDroite[i][0] = 1;
    }
    matriceEnLHautDroite[2][2] = 1;

    int matriceEnLHautGauche[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnLHautGauche[0][i] = 1;
        matriceEnLHautGauche[i][2] = 1;
    }
    matriceEnLHautGauche[2][0] = 1;

    ///cartes en T
    int matriceEnTDroite[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnTDroite[i][0] = 1;
    }
    matriceEnTDroite[0][2] = 1;
    matriceEnTDroite[2][2] = 1;

    int matriceEnTGauche[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnTGauche[i][2] = 1;
    }
    matriceEnTGauche[0][0] = 1;
    matriceEnTGauche[2][0] = 1;

    int matriceEnTBas[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnTBas[0][i] = 1;
    }
    matriceEnTBas[2][0] = 1;
    matriceEnTBas[2][2] = 1;

    int matriceEnTHaut[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnTHaut[2][i] = 1;
    }
    matriceEnTHaut[0][0] = 1;
    matriceEnTHaut[0][2] = 1;

    ///cartes en ligne droite
    int matriceEnIHautBas[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnIHautBas[i][0] = 1;
        matriceEnIHautBas[i][2] = 1;
    }

    int matriceEnIDroiteGauche[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        matriceEnIDroiteGauche[0][i] = 1;
        matriceEnIDroiteGauche[2][i] = 1;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            tableauCarte[0].matrice[i][j] = matriceEnIDroiteGauche[i][j];
            tableauCarte[1].matrice[i][j] = matriceEnIHautBas[i][j];

            tableauCarte[2].matrice[i][j] = matriceEnLHautDroite[i][j];
            tableauCarte[3].matrice[i][j] = matriceEnLHautGauche[i][j];
            tableauCarte[4].matrice[i][j] = matriceEnLBasDroite[i][j];
            tableauCarte[5].matrice[i][j] = matriceEnLBasGauche[i][j];

            tableauCarte[6].matrice[i][j] = matriceEnTBas[i][j];
            tableauCarte[7].matrice[i][j] = matriceEnTHaut[i][j];
            tableauCarte[8].matrice[i][j] = matriceEnTDroite[i][j];
            tableauCarte[9].matrice[i][j] = matriceEnTGauche[i][j];
        }
    }
}

void generation_tresor(int nbJoueur, t_joueurs TousLesJoueurs[]){
    srand(time(NULL));
    int nbAlea;
    char liste_tresor[24] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x2A, 0x2B, 0x7D, 0x2D,
                             0x2E, 0x2F,0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
                             0x40, 0x5B, 0x5D, 0x5E,0x5F, 0x7B};
    for (int i=0; i<nbJoueur; i++) {
        for (int j = 0; j < 24 / nbJoueur; j++) {
            do {
                nbAlea = rand() % 24;
            } while (liste_tresor[nbAlea] == -1);
            TousLesJoueurs[i].carteTresorsaChercher[j] = liste_tresor[nbAlea];
            liste_tresor[nbAlea] = -1;
        }
    }
}

///affichage carte en rab
void affichage_1_carte(int matrice[3][3]){
    int positionEnX, positionEnY;
    getCursorPosition(&positionEnX,&positionEnY);
    for(int k=0; k<3; k++) {
        gotoxy(positionEnX, positionEnY);
        for (int l=0; l<3; l++) {
            if (matrice[k][l] == 1) {
                bg_color(CYAN);
                text_color(CYAN);
                fflush(stdin);
                printf("%d ", matrice[k][l]);
                fflush(stdin);
                set_color(BLACK, BLACK);
            }
            else{
                bg_color(YELLOW);
                text_color(YELLOW);
                fflush(stdin);
                printf("%d ", matrice[k][l]);
                fflush(stdin);
                set_color(BLACK, BLACK);
            }
        }
        positionEnY += 1;
    }
}

//////////////////////////////////////////////////PLATEAU///////////////////////////////////////////////////////////////

void plateau_cartes_fixes(t_plateau matricePlateau[7][7], t_plateau tableauCarte[10]){
    int emplacementMatriceLDansTableau = 2;
    for (int i = 0; i < 7; i += 6) {
        for (int j = 0; j < 7; j += 6) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[emplacementMatriceLDansTableau].matrice[k][l];
                }
            }
            emplacementMatriceLDansTableau += 1;
        }
    }

    int emplacementMatriceTDansTableau = 6;
    for (int i = 0; i < 7; i += 6) {
        for (int j = 2; j < 6; j += 2) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[emplacementMatriceTDansTableau].matrice[k][l];
                }
            }
        }
        emplacementMatriceTDansTableau += 1;
    }

    for (int i = 0; i < 7; i+=6){
        for (int j = 2; j < 6; j += 2){
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[j][i].matrice[k][l] = tableauCarte[emplacementMatriceTDansTableau].matrice[k][l];
                }
            }
        }
        emplacementMatriceTDansTableau += 1;
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            matricePlateau[2][2].matrice[k][l] = tableauCarte[8].matrice[k][l];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            matricePlateau[2][4].matrice[k][l] = tableauCarte[6].matrice[k][l];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            matricePlateau[4][2].matrice[k][l] = tableauCarte[7].matrice[k][l];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            matricePlateau[4][4].matrice[k][l] = tableauCarte[9].matrice[k][l];
        }
    }
}


void plateau_toutes_carte(t_plateau matricePlateau[][7], t_plateau tableauCarte[]){
    srand(time(NULL));
    int nbCarteL = 0, nbCarteT = 0, nbCarteI = 0;
    int nbAlea = 0;
    int liste[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 7; i += 2) {
        for (int j = 1; j < 7; j += 2) {
            do {
                nbAlea = rand() % 10;
            } while (liste[nbAlea] == -1);
            comptage_carte(nbAlea, &nbCarteL, &nbCarteI, &nbCarteT, liste);
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[nbAlea].matrice[k][l];
                }
            }
        }
    }

    for (int i = 1; i < 7; i += 2) {
        for (int j = 0; j < 7; j += 1) {
            do {
                nbAlea = rand() % 10;
            } while (liste[nbAlea] == -1);
            comptage_carte(nbAlea, &nbCarteL, &nbCarteI, &nbCarteT, liste);
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[nbAlea].matrice[k][l];
                }
            }
        }
    }
}

/////////////////////////////////////////////////AFFICHAGE//////////////////////////////////////////////////////////////

int comptage_carte(int nbAlea, int *nbCarteL, int *nbCarteI, int *nbCarteT, int liste[]) {
    if ((liste[nbAlea] <= 5) && (liste[nbAlea] >= 2) && (*nbCarteL < 16)){
        *nbCarteL += 1;
    }
    if ((liste[nbAlea] <= 5) && (liste[nbAlea] >= 2) && (*nbCarteL == 16)){
        for (int i=2; i<6; i++){
            liste[i] = -1;
        }
    }
    if (((liste[nbAlea] == 0) || (liste[nbAlea] == 1)) && (*nbCarteI < 12)){
        *nbCarteI += 1;
    }
    if (((liste[nbAlea] == 0) || (liste[nbAlea] == 1)) && (*nbCarteI == 12)){
        liste[0] = -1;
        liste[1] = -1;
    }
    if ((liste[nbAlea] <= 9) && (liste[nbAlea] >= 6) && (*nbCarteT < 6)){
        *nbCarteT += 1;
    }
    if ((liste[nbAlea] <= 9) && (liste[nbAlea] >= 6) && (*nbCarteT == 6)){
        for (int i=6; i<10; i++){
            liste[i] = -1;
        }
    }
}

void mise_en_forme(){
    int positionEnX = 0, positionEnY = 2;
    int positionEnXTexte = 7, positionEnYTexte = 1;
    char lettreAfficher = 'A';
    for (int i = 0; i < 7; i++){
        gotoxy(positionEnXTexte, positionEnYTexte);
        bg_color(RED);
        text_color(WHITE);
        printf(" %c ", lettreAfficher);
        lettreAfficher += 1;
        positionEnXTexte += 6;
        bg_color(BLACK);
    }

    for (int i = 0; i < 48; i++){
        text_color(WHITE);
        gotoxy(positionEnX, positionEnY);
        printf("-");
        positionEnX += 1;
    }

    positionEnXTexte = 1;
    positionEnYTexte = 4;
    int nombreAfficher = 1;
    for (int i = 0; i < 7; i++){
        gotoxy(positionEnXTexte, positionEnYTexte);
        bg_color(RED);
        printf(" %d ", nombreAfficher);
        positionEnYTexte += 3;
        nombreAfficher += 1;
        bg_color(BLACK);
    }
    positionEnX = 5;
    positionEnY = 1;
    for (int i = 0; i<24; i++){
        gotoxy(positionEnX, positionEnY);
        text_color(WHITE);
        printf("|");
        positionEnY += 1;
    }
}

void affichage_matrice(t_plateau matricePlateau[7][7]){
    mise_en_forme();
    int positionEnX = 6, positionEnY = 4;
    set_color(BLACK, WHITE);
    for (int i=0; i<7;i++){
        for(int j=0; j<7; j++){
            positionEnY = 3 + (i * 3);
            for(int k=0; k<3; k++) {
                gotoxy(positionEnX, positionEnY);
                for (int l=0; l<3; l++) {
                    if (matricePlateau[i][j].matrice[k][l] == 1) {
                        bg_color(CYAN);
                        text_color(CYAN);
                        fflush(stdin);
                        printf("%d ", matricePlateau[i][j].matrice[k][l]);
                        fflush(stdin);
                        set_color(BLACK, BLACK);
                    }
                    else{
                        bg_color(YELLOW);
                        text_color(YELLOW);
                        fflush(stdin);
                        printf("%d ", matricePlateau[i][j].matrice[k][l]);
                        fflush(stdin);
                        set_color(BLACK, BLACK);
                    }
                }
                positionEnY += 1;
            }
            positionEnX += 6;
        }
        positionEnX = 6;
    }
}

void affichage_tresor(int liste_tresor[]){
    int coordonneeX[24] = {0};
}
/////////////////////////////////////////////////////DECALAGE///////////////////////////////////////////////////////////

int decalage(t_plateau matricePlateau[][7], int matriceCarteEnRab[][3]){
    int matriceCarteEnRabTempo[3][3] = {0};
    char lettreRentree;
    int nombreRentree;
    set_color(WHITE, BLACK);
    printf("\nRentrez une colonne et une ligne ou vous souhaitez rentré votre carte :\n");
    scanf("%c %d", &lettreRentree, &nombreRentree);
    while (((lettreRentree > 96) && (lettreRentree < 103)) || ((lettreRentree < 65) || (lettreRentree > 71)) ||
           ((nombreRentree < 1) || (nombreRentree > 7)) || (((lettreRentree %2 == 0) && ((lettreRentree >= 65) &&
                                                                                         (lettreRentree <= 71))) && ((nombreRentree >= 2) && (nombreRentree <= 6))) || (((lettreRentree %2 == 1) &&
                                                                                                                                                                         ((lettreRentree >= 65) && (lettreRentree <= 71))) && (nombreRentree % 2 == 1) && ((1 <= nombreRentree) &&
                                                                                                                                                                                                                                                           (nombreRentree <= 7)))){

        ///transforme minuscule en majuscule
        if ((lettreRentree > 96) && (lettreRentree < 103)) {
            lettreRentree -= 32;
        }

        ///si la case choisie est fixe
        if (((lettreRentree %2 == 1) && ((lettreRentree >= 65) && (lettreRentree <= 71))) && (nombreRentree % 2 == 1)
            && ((1 <= nombreRentree) && (nombreRentree <= 7))) {
            printf("Non cette case est fixe et ne peut etre bouge, entrer une lettre et un nombre valable :\n");
        }

        ///si la case choisie est à l'intérieur du labyrinthe
        if (((lettreRentree %2 == 0) && ((lettreRentree >= 65) && (lettreRentree <= 71))) && ((nombreRentree >= 2) &&
                                                                                              (nombreRentree <= 6))) {
            printf("Cette case est dans le labyrinthe, entrer une lettre et un nombre valable :\n");
        }

        if (((lettreRentree < 65) || (lettreRentree > 71)) && ((1 <= nombreRentree) && (nombreRentree <= 7))) {
            printf("Entrez une lettre entre A et G avant votre chiffre :\n");
        }
        if (((lettreRentree >= 65) && (lettreRentree <= 71)) && ((nombreRentree < 1) || (nombreRentree > 7))) {
            printf("Entrer un nombre entre 0 et 7 apres votre lettre. Veuillez reessayer :\n");
        }
        if (((lettreRentree < 65) || (lettreRentree > 71)) && ((nombreRentree < 1) || (nombreRentree > 7))){
            printf("La combinaison ne correspond à aucune case du tableau. Veuillez reessayer :\n");
        }

        printf("Reessayez :\n");
        scanf("\n%c%d", &lettreRentree, &nombreRentree);
    }
    lettreRentree -= 65;
    nombreRentree -= 1;
    ///décalage gauche vers droite
    if ((lettreRentree == 0) && (nombreRentree == 1 || nombreRentree == 3 || nombreRentree == 5)) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRabTempo[j][k] = matriceCarteEnRab[j][k];
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRab[j][k] = matricePlateau[nombreRentree][6].matrice[j][k];
            }
        }
        for (int i = 5; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    matricePlateau[nombreRentree][i + 1].matrice[j][k] = matricePlateau[nombreRentree][i].matrice[j][k];
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matricePlateau[nombreRentree][0].matrice[j][k] = matriceCarteEnRabTempo[j][k];
            }
        }
    }

        ///décalage droite vers gauche
    else if ((lettreRentree == 6) && (nombreRentree == 1 || nombreRentree == 3 || nombreRentree == 5)) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRabTempo[j][k] = matriceCarteEnRab[j][k];
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRab[j][k] = matricePlateau[nombreRentree][0].matrice[j][k];
            }
        }
        for (int i = 0; i <= 5 ; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    matricePlateau[nombreRentree][i].matrice[j][k] = matricePlateau[nombreRentree][i + 1].matrice[j][k];
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matricePlateau[nombreRentree][6].matrice[j][k] = matriceCarteEnRabTempo[j][k];
            }
        }
    }

        ///décalage haut vers bas
    else if ((nombreRentree == 0) && (lettreRentree == 1 || lettreRentree == 3 || lettreRentree == 5)){
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRabTempo[j][k] = matriceCarteEnRab[j][k];
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRab[j][k] = matricePlateau[6][lettreRentree].matrice[j][k];
            }
        }
        for (int i = 5; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    matricePlateau[i + 1][lettreRentree].matrice[j][k] = matricePlateau[i][lettreRentree].matrice[j][k];
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matricePlateau[0][lettreRentree].matrice[j][k] = matriceCarteEnRabTempo[j][k];
            }
        }
    }

        ///décalage haut vers bas
    else if ((nombreRentree == 6) && (lettreRentree == 1 || lettreRentree == 3 || lettreRentree == 5)) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRabTempo[j][k] = matriceCarteEnRab[j][k];
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matriceCarteEnRab[j][k] = matricePlateau[0][lettreRentree].matrice[j][k];
            }
        }
        for (int i = 0; i <= 5 ; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    matricePlateau[i][lettreRentree].matrice[j][k] = matricePlateau[i + 1][lettreRentree].matrice[j][k];
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                matricePlateau[6][lettreRentree].matrice[j][k] = matriceCarteEnRabTempo[j][k];
            }
        }
    }
    system("cls");
    mise_en_forme();
    affichage_matrice(matricePlateau);
}

////////////////////////////////////////////////ENREGISTREMENT MATRICE//////////////////////////////////////////////////

void enregistrement_matrice(t_plateau matricePlateau[7][7]){
    FILE *fp;
    fp = fopen("sauv_matrice.txt", "w");
    if (fp != NULL){
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        fprintf(fp, "%d ", matricePlateau[i][j].matrice[k][l]);
                    }
                    fprintf(fp, "\n");
                }
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
    }
    else{
        printf("erreur");
        exit(1);
    }
}

void lecture_matrice_fichier(FILE *fp, t_plateau matricePlateau[7][7]){
    fp = fopen("sauv_matrice.txt", "r");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    fscanf(fp, "%d ",&matricePlateau[i][j].matrice[k][l]);
                }
            }
        }
    }
}

///////////////////////////////////////////////ENREGISTREMENT DONNEE JOUEURS////////////////////////////////////////////
void enregistrement_joueur(int nbJoueurs, t_joueurs TousLesJoueurs[]){
    FILE *fichier;
    fichier = fopen("sauv_joeuur.txt", "w");
    if (fichier != NULL){
        for (int i = 0; i<nbJoueurs; i++) {
            fprintf(fichier, "%s ", TousLesJoueurs[i].prenom);
            fprintf(fichier, "%d ", TousLesJoueurs[i].xcoord);
            fprintf(fichier, "%d ", TousLesJoueurs[i].ycoord);
            for (int j = 0; j<(24/nbJoueurs); j++) {
                fprintf(fichier, "%s", TousLesJoueurs[i].carteTresorsaChercher);
            }
        }
        fclose(fichier);
    }
    else{
        printf("erreur");
        exit(1);
    }
}

void lecture_joueur(t_joueurs TousLesJoueurs[], FILE *fichier, int nbJoueurs){
    fichier = fopen("sauv_joeuur.txt", "r");
    if (fichier != NULL) {
        for (int i = 0; i < nbJoueurs; i++) {
            fscanf(fichier, "%s ", TousLesJoueurs[i].prenom);
            fscanf(fichier, "%d ", &TousLesJoueurs[i].xcoord);
            fscanf(fichier, "%d ", &TousLesJoueurs[i].ycoord);
            for (int j = 0; j < (24 / nbJoueurs); j++) {
                fscanf(fichier, "%s", TousLesJoueurs[i].carteTresorsaChercher);
            }
        }
    }
}

void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[]){
    system("cls");
    int choixMenu = 0;
    char entrer;
    carte(tableauCarte);
    set_color(CYAN, BLACK);
    swag();
    printf("\n\t\t\tBienvenu(e) dans le jeu du Labyrinthe ! Voici le menu :\n\t\t\t\t\t1 - Nouvelle partie\n\t\t\t\t\t2 - Charger une partie\n\t\t\t\t\t3 - Les regles du jeu\n\t\t\t\t\t4 - Quitter\n");
    scanf("%d", &choixMenu);
    while ((choixMenu !=1) &&  (choixMenu!=2) && (choixMenu!=3) && (choixMenu!=4)){
        printf("veuillez choisir parmi les options proposees\n");
        scanf("%d",&choixMenu);
    }
    switch (choixMenu) {
        case 1:
            TousLesJoueurs[0].xcoord = 8;TousLesJoueurs[0].ycoord=4;
            TousLesJoueurs[1].xcoord = 44;TousLesJoueurs[1].ycoord=4;
            TousLesJoueurs[2].xcoord = 8;TousLesJoueurs[2].ycoord=22;
            TousLesJoueurs[3].xcoord = 44;TousLesJoueurs[3].ycoord=22;
            plateau_cartes_fixes(matricePlateau, tableauCarte);
            plateau_toutes_carte(matricePlateau, tableauCarte);
            jeu_nouvelle_partie(TousLesJoueurs, matricePlateau);
            break;
        case 2:
            lecture_matrice_fichier(fp, matricePlateau);
            break;
        case 3:
            system("cls");
            while (entrer != 'v'){
                printf("Chaque joueur commence par regarder secretement "
                       "la carte superieure de sa pile ; elle indique le premier tresor "
                       "qu il doit trouver.\n"
                       "Le dernier joueur a avoir participe a une chasse "
                       "tresors entame la partie. Le jeu se poursuit dans le sens "
                       "des aiguilles d une montre.\n"
                       "Le tour d un joueur se decompose en deux etapes :\n"
                       "1. Modifier les couloirs ;\n"
                       "2. Deplacer son pion.\n\n"
                       "1. Modification des couloirs\n"
                       "Quand vient son tour, le joueur choisit une rangee et "
                       "y pousse la plaque supplementaire vers l interieur du "
                       "plateau jusqu a ce qu une et une seule plaque a l oppose "
                       "soit expulsee.\n"
                       "Contrainte : Une plaque ne peut jamais etre reintroduite "
                       "a l endroit meme d ou elle vient d etre expulsee par le "
                       "joueur precedent.\n"
                       "Si, en faisant coulisser les couloirs, un joueur expulse "
                       "son pion ou un pion adverse du plateau, celui-ci est alors "
                       "place a l oppose, sur la plaque qui vient d etre introduite. "
                       "Ceci ne compte pas comme deplacement du pion!\n\n 2. Deplacement du pion\n"
                       "Apres avoir modifie le labyrinthe, le joueur peut deplacer "
                       "son pion jusqu a n importe quelle case en suivant un "
                       "couloir ininterrompu. Il peut se deplacer aussi loin qu il "
                       "veut. Il est aussi permis de rester sur place.\n"
                       "Si un joueur atteint le tresor recherche, il l a trouve ! Il peut alors "
                       "immediatement regarder la carte suivante de "
                       "sa pile ; elle lui indique son prochain objectif.\n\n"
                       "Fin de la partie\n"
                       "Le vainqueur est le premier joueur a avoir retourne toutes "
                       "ses cartes et a ramener son pion a son point de depart.\n\n");
                printf("Pour quitter les regles, appuyer sur v\n");
                fflush(stdin);
                scanf("%c", &entrer);
            }
            menu (matricePlateau, tableauCarte, fp, TousLesJoueurs);
            break;
        case 4:
            system("cls");
            printf("A bientot !");
            break;
    }
}


void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[7][7]){
    int nbJoueur;
    int matriceCarteEnRab[3][3] = {0};
    matriceCarteEnRab[1][1] = 1;
    system("cls");
    swag();
    printf("\nVeuillez entrer le nombre de joueur :\n");
    scanf("%d", &nbJoueur);
    for (int i = 0; i < nbJoueur; i++) {
        system("cls");
        swag();
        printf("\nJoueur %d, veuillez entrer votre nom ou pseudo :\n", i + 1);
        scanf("%s", TousLesJoueurs[i].prenom);
        system("cls");
        swag();
        printf("\nVeuillez entrer la lettre qui vous representera :\n");
        scanf("%s", TousLesJoueurs[i].lettresurplateau);
    }
    generation_tresor(nbJoueur, TousLesJoueurs);
    while(kbhit() != 27) {
        for (int i = 0; i < nbJoueur; i++) {
            system("cls");
            set_color(WHITE, BLACK);
            printf("A votre tour, voici le plateau :\n");
            affichage_matrice(matricePlateau);
            afficher_joueur(TousLesJoueurs,matricePlateau,nbJoueur);
            enregistrement_matrice(matricePlateau);
            set_color(WHITE, BLACK);
            printf("\n%s, voici votre carte :", TousLesJoueurs[i].prenom);
            affichage_1_carte(matriceCarteEnRab);
            set_color(WHITE, BLACK);
            printf("\nVoici vos trésors à aller chercher \n");
            for (int j=0; j<24/nbJoueur; j++){
                printf("%c ", TousLesJoueurs[i].carteTresorsaChercher[j]);
            }
            decalage(matricePlateau,matriceCarteEnRab);
            afficher_joueur(TousLesJoueurs,matricePlateau,nbJoueur);
            deplacement_jouer(TousLesJoueurs,matricePlateau,i);
        }
    }
}



void afficher_joueur(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int nbJoueur){
    for (int i=0;i<nbJoueur;i++){
        set_color(BLACK, YELLOW);
        gotoxy(TousLesJoueurs[i].xcoord,TousLesJoueurs[i].ycoord);
        printf("%s",TousLesJoueurs[i].lettresurplateau);
    }
    gotoxy(28, 24);
}


void deplacement_jouer(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int i) {
    char mouvement;
    set_color(WHITE, BLACK);
    printf("\nAvancez ou vous voulez, pour valider votre emplacement, appuyer sur v :\n");
    do {
        gotoxy(0, 27);
        set_color(WHITE, BLACK);
        scanf("\n%c", &mouvement);
        if (mouvement == 's') {
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].ycoord += 3;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
        }
        if (mouvement == 'z') {
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].ycoord -= 3;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
        }
        if (mouvement == 'q') {
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].xcoord -= 6;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
        }
        if (mouvement == 'd') {
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].xcoord += 6;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
        }
    } while (mouvement != 'v');
}