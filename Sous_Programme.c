//
// Created by Ce PC on 14/12/2022.
//

#include "Sous_Programme.h"
static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;

////////////////////////////////////////////////MISE EN FORME///////////////////////////////////////////////////////////
///mise en forme affichage
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
///cartes en L
void carte_L_bas_droite(int matriceEnLBasDroite[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnLBasDroite[i][0] = 1;
        matriceEnLBasDroite[2][i] = 1;
    }
    matriceEnLBasDroite[0][2] = 1;
}

void carte_L_bas_gauche(int matriceEnLBasGauche[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnLBasGauche[i][2] = 1;
        matriceEnLBasGauche[2][i] = 1;
    }
    matriceEnLBasGauche[0][0] = 1;
}

void carte_L_haut_droite(int matriceEnLHautDroite[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnLHautDroite[0][i] = 1;
        matriceEnLHautDroite[i][0] = 1;
    }
    matriceEnLHautDroite[2][2] = 1;
}

void carte_L_haut_gauche(int matriceEnLHautGauche[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnLHautGauche[0][i] = 1;
        matriceEnLHautGauche[i][2] = 1;
    }
    matriceEnLHautGauche[2][0] = 1;
}

///cartes en T
void carte_T_droite(int matriceEnTDroite[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnTDroite[i][0] = 1;
    }
    matriceEnTDroite[0][2] = 1;
    matriceEnTDroite[2][2] = 1;
}

void carte_T_gauche(int matriceEnTGauche[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnTGauche[i][2] = 1;
    }
    matriceEnTGauche[0][0] = 1;
    matriceEnTGauche[2][0] = 1;
}

void carte_T_bas(int matriceEnTBas[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnTBas[0][i] = 1;
    }
    matriceEnTBas[2][0] = 1;
    matriceEnTBas[2][2] = 1;
}

void carte_T_haut(int matriceEnTHaut[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnTHaut[2][i] = 1;
    }
    matriceEnTHaut[0][0] = 1;
    matriceEnTHaut[0][2] = 1;
}

///cartes en ligne droite
void carte_I_haut_bas(int matriceEnIHautBas[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnIHautBas[i][0] = 1;
        matriceEnIHautBas[i][2] = 1;
    }
}

void carte_I_droite_gauche(int matriceEnIDroiteGauche[][3]){
    for (int i = 0; i < 3; i++) {
        matriceEnIDroiteGauche[0][i] = 1;
        matriceEnIDroiteGauche[2][i] = 1;

    }
}

///affichage une carte si besoin
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

void mise_en_place_cartes(int matriceEnLBasDroite[3][3], int matriceEnIHautBas[3][3], int matriceEnTDroite[3][3],
                          int matriceEnIDroiteGauche[3][3], int matriceEnLBasGauche[][3],int matriceEnLHautDroite[3][3],
                          int matriceEnLHautGauche[3][3], int matriceEnTBas[3][3], int matriceEnTGauche[3][3],
                          int matriceEnTHaut[3][3]){

    carte_I_droite_gauche(matriceEnIDroiteGauche);
    carte_I_haut_bas(matriceEnIHautBas);

    carte_T_bas(matriceEnTBas);
    carte_T_haut(matriceEnTHaut);
    carte_T_droite(matriceEnTDroite);
    carte_T_gauche(matriceEnTGauche);

    carte_L_bas_droite(matriceEnLBasDroite);
    carte_L_bas_gauche(matriceEnLBasGauche);
    carte_L_haut_droite(matriceEnLHautDroite);
    carte_L_haut_gauche(matriceEnLHautGauche);
}

void tableau_de_carte(t_cartes tableauCarte[10], int matriceEnLBasDroite[3][3], int matriceEnIHautBas[3][3],
                      int matriceEnTDroite[3][3], int matriceEnIDroiteGauche[3][3], int matriceEnLBasGauche[][3],
                      int matriceEnLHautDroite[3][3], int matriceEnLHautGauche[3][3], int matriceEnTBas[3][3],
                      int matriceEnTGauche[3][3], int matriceEnTHaut[3][3]){
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


//////////////////////////////////////////////////PLATEAU///////////////////////////////////////////////////////////////

void plateau_cartes_fixes(t_plateau matricePlateau[7][7], t_cartes tableauCarte[10]){
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


void plateau_toutes_carte(t_plateau matricePlateau[][7], t_cartes tableauCarte[], int *nbAlea, int *nbCarteT, int *nbCarteL, int *nbCarteI){
    srand(time(NULL));
    int liste[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 7; i += 2) {
        for (int j = 1; j < 7; j += 2) {
            do {
                *nbAlea = 1 + rand() % 9;
            } while (liste[*nbAlea] == -1);
            comptage_carte(nbAlea, nbCarteL, nbCarteI, nbCarteT, liste);
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[*nbAlea].matrice[k][l];
                }
            }
        }
    }

    for (int i = 1; i < 7; i += 2) {
        for (int j = 0; j < 7; j += 1) {
            do {
                *nbAlea = 1 + rand() % 9;
            } while (liste[*nbAlea] == -1);
            comptage_carte(nbAlea, nbCarteL, nbCarteI, nbCarteT, liste);
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[*nbAlea].matrice[k][l];
                }
            }
        }
    }
}

/////////////////////////////////////////////////AFFICHAGE//////////////////////////////////////////////////////////////

int comptage_carte(int *nbAlea, int *nbCarteL, int *nbCarteI, int *nbCarteT, int liste[]) {
    while (liste[*nbAlea] == -1){
        *nbAlea = 1 + rand() % 11;
    }

    if ((liste[*nbAlea] <= 5) && (liste[*nbAlea] >= 2) && (*nbCarteL < 16)){
        *nbCarteL += 1;
    }
    if ((liste[*nbAlea] <= 5) && (liste[*nbAlea] >= 2) && (*nbCarteL == 16)){
        for (int i=2; i<6; i++){
            liste[i] = -1;
        }
    }
    if (((liste[*nbAlea] == 0) || (liste[*nbAlea] == 1)) && (*nbCarteI < 12)){
        *nbCarteI += 1;
    }
    if (((liste[*nbAlea] == 0) || (liste[*nbAlea] == 1)) && (*nbCarteI == 12)){
        liste[0] = -1;
        liste[1] = -1;
        liste[2] = -1;
        liste[3] = -1;
    }
    if ((liste[*nbAlea] <= 9) && (liste[*nbAlea] >= 6) && (*nbCarteT < 6)){
        *nbCarteT += 1;
    }
    if ((liste[*nbAlea] <= 9) && (liste[*nbAlea] >= 6) && (*nbCarteT == 6)){
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

void enregistrement_matrice(t_plateau matricePlateau[7][7], FILE *fp){
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
void enregistrement_joueur(t_joueurs TousLesJoueurs[], FILE *fichier, int nbJoueurs){
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

void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, int nbAlea, int nbCarteT, int nbCarteI, int nbCarteL, t_joueurs TousLesJoueurs[], int *nbJoueur, int matriceCarteEnRab[][3]){
    int choixMenu = 0;
    for (int i = 0; i < 7; i += 6) {
        for (int j = 0; j < 7; j += 6) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = 0;
                }
            }
        }
    }

    printf("Bienvenu(e) dans le jeu du Labyrinthe ! Voici le menu :\n1 - Nouvelle partie\n2 - Charger une partie\n3 - Quitter\n");
    scanf("%d", &choixMenu);
    switch (choixMenu) {
        case 1:
            plateau_cartes_fixes(matricePlateau, tableauCarte);
            plateau_toutes_carte(matricePlateau, tableauCarte, &nbAlea, &nbCarteT, &nbCarteL, &nbCarteI);
            jeu_nouvelle_partie(TousLesJoueurs,matricePlateau, nbJoueur, fp, matriceCarteEnRab);
            break;
        case 2:
            lecture_matrice_fichier(fp, matricePlateau);
            break;
        case 3:
            system("cls");
            printf("A bientot !");
            break;
    }
}


void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int *nbJoueur, FILE *fp){
    int matriceCarteEnRab[3][3] = {0};
    matriceCarteEnRab[1][1] = 1;
    system("cls");
    printf("Veuillez entrer le nombre de joueur :\n");
    scanf("%d", nbJoueur);
    for (int i = 0; i < *nbJoueur; i++) {
        system("cls");
        printf("Joueur %d, veuillez entrer votre nom ou pseudo :\n", i + 1);
        scanf("%s", TousLesJoueurs[i].prenom);
    }
    while(kbhit() != 27) {
        for (int i = 0; i < *nbJoueur; i++) {
            system("cls");
            set_color(WHITE, BLACK);
            printf("A votre tour, voici le plateau :\n");
            affichage_matrice(matricePlateau);
            enregistrement_matrice(matricePlateau, fp);
            set_color(WHITE, BLACK);
            printf("\n%s, voici votre carte :", TousLesJoueurs[i].prenom);
            affichage_1_carte(matriceCarteEnRab);
            decalage(matricePlateau,matriceCarteEnRab);
        }
    }
}