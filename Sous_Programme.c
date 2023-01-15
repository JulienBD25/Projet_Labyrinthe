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
            "\t\t\t\t$$\\                $$\\                           $$\\            $$\\     $$\\                 \n"
            "\t\t\t\t$$ |               $$ |                          \\__|           $$ |    $$ |                \n"
            "\t\t\t\t$$ |      $$$$$$\\  $$$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\ $$$$$$$\\ $$$$$$\\   $$$$$$$\\   $$$$$$\\  \n"
            "\t\t\t\t$$ |      \\____$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\ $$ |$$  __$$\\\\_$$  _|  $$  __$$\\ $$  __$$\\ \n"
            "\t\t\t\t$$ |      $$$$$$$ |$$ |  $$ |$$ |  $$ |$$ |  \\__|$$ |$$ |  $$ | $$ |    $$ |  $$ |$$$$$$$$ |\n"
            "\t\t\t\t$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$ |      $$ |$$ |  $$ | $$ |$$\\ $$ |  $$ |$$   ____|\n"
            "\t\t\t\t$$$$$$$$\\\\$$$$$$$ |$$$$$$$  |\\$$$$$$$ |$$ |      $$ |$$ |  $$ | \\$$$$  |$$ |  $$ |\\$$$$$$$\\ \n"
            "\t\t\t\t\\________|\\_______|\\_______/  \\____$$ |\\__|      \\__|\\__|  \\__|  \\____/ \\__|  \\__| \\_______|\n"
            "\t\t\t\t                             $$\\   $$ |                                                     \n"
            "\t\t\t\t                             \\$$$$$$  |                                                     \n"
            "\t\t\t\t                             \\_______/                                                      ");
}
//Ce sous programme permet de pouvoir aller à des endroits grâce à des positions
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
//Changer la couleur du texte
void text_color(int color)
{
    __FOREGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}
//changer la couleur du fond
void bg_color(int color){
    __BACKGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}
//Choisir la couleur des lettres et du fond
void set_color(int colorT,int colorBg){
    __FOREGROUND=colorT;
    __BACKGROUND=colorBg;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}

//////////////////////////////////////////////////////CARTES////////////////////////////////////////////////////////////

//Cette fonction permet d'avoir toutes les cartes que nous utiliseront sous forme de matrice
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
            tableauCarte[3].matrice[i][j] = matriceEnLBasDroite[i][j];
            tableauCarte[4].matrice[i][j] = matriceEnLBasGauche[i][j];
            tableauCarte[5].matrice[i][j] = matriceEnLHautGauche[i][j];

            tableauCarte[6].matrice[i][j] = matriceEnTBas[i][j];
            tableauCarte[7].matrice[i][j] = matriceEnTGauche[i][j];
            tableauCarte[8].matrice[i][j] = matriceEnTHaut[i][j];
            tableauCarte[9].matrice[i][j] = matriceEnTDroite[i][j];
        }
    }
}
//Ce sous programme permet de generer des tresors dans le labyrinthe
void distribution_tresor(int nbJoueur, t_joueurs TousLesJoueurs[], char liste_tresor[]){
    srand(time(NULL));// fonction pour que les tresors soit mise au hazard sur le labyrinthe
    int nbAlea;
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

///affichage carte en rab, la carte restante apres mise en place des cartes sur le plateau
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
//Il permet d'afficher les cartes fixes, afin qu'il soit plus facile a mettre sur la version finale du labyrinthe, et de pouvoir manipuler seuelement c'est carte pour les testes
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

// Dans la continuité de dessus, ce sous programme permet de placer toutes les cartes qui forme le labyrinthe
void plateau_toutes_carte(t_plateau matricePlateau[][7], t_plateau tableauCarte[],int matriceCarteEnRab[3][3],int *numMatriceEnRab){
    // initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    // déclaration des trois listes et de leur nouvelle liste
    int liste1[SIZE1];
    int liste2[SIZE2];
    int liste3[SIZE3];
    int new_liste[NEW_SIZE];

    // remplissage de la première liste avec des nombres aléatoires compris entre 0 et 1
    for (int i = 0; i < SIZE1; i++) {
        liste1[i] = rand() % 2;
    }

    // remplissage de la deuxième liste avec des nombres aléatoires compris entre 2 et 5
    for (int i = 0; i < 16; i++) {
        liste2[i] = (rand() % 4) + 2;
    }
    //Remplissage de la troisième liste avec des nombres aléatoires compris entre 6 et 9
    for (int i = 0; i < 6; i++) {
        liste3[i] = (rand() % 4) + 6;
    }

    // regroupement des trois listes dans la nouvelle liste de manière aléatoire
    for (int i = 0; i < NEW_SIZE; i++) {
        if (i < SIZE1) {
            new_liste[i] = liste1[i];
        } else if (i < SIZE1 + SIZE2) {
            new_liste[i] = liste2[i - SIZE1];
        } else {
            new_liste[i] = liste3[i - SIZE1 - SIZE2];
        }
    }

    // mélange aléatoire des éléments de la nouvelle liste
    for (int i = 0; i < NEW_SIZE; i++) {
        int j = rand() % NEW_SIZE;
        int temp = new_liste[i];
        new_liste[i] = new_liste[j];
        new_liste[j] = temp;
    }

    // déclaration des deux nouvelles listes
    int liste_12[12];
    int liste_22[22];

    // séparation de la nouvelle liste en deux listes de tailles différentes
    for (int i = 0; i < 12; i++) {
        liste_12[i] = new_liste[i];
    }
    for (int i = 0; i < 22; i++) {
        liste_22[i] = new_liste[i + 12];
    }

    *numMatriceEnRab = new_liste[33];

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            matriceCarteEnRab[k][l] = tableauCarte[*numMatriceEnRab].matrice[k][l];
        }
    }
    int m = 0;
    int n = 0;

    for (int i = 0; i < 7; i += 2) {
        for (int j = 1; j < 7; j += 2) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[liste_12[m]].matrice[k][l];
                }
            }
            m += 1;
        }
    }
    for (int i = 1; i < 7; i += 2) {
        for (int j = 0; j < 7; j += 1) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    matricePlateau[i][j].matrice[k][l] = tableauCarte[liste_22[n]].matrice[k][l];
                }
            }
            n += 1;
        }
    }
}

/////////////////////////////////////////////////AFFICHAGE//////////////////////////////////////////////////////////////
//Ce sous programme permet de se reperer dans le labyrinthe, il affiche sur les cotés de A à G et de 1 à 7
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
// Cela permet d'afficher les cartes que l'on avait définit plutot
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
                        bg_color(CYAN); // colore les murs en cyan
                        text_color(CYAN);
                        fflush(stdin);
                        printf("%d ", matricePlateau[i][j].matrice[k][l]);
                        fflush(stdin);
                        set_color(BLACK, BLACK);
                    }
                    else{
                        bg_color(YELLOW); //colore les cases non mures en jaune
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
// Ce sous programme permet d'afficher les tresors sur la map. Il prend des coordonées des cartes fixes et les print sur le labyrinthe
void generation_tresor() {
    int choixCoord, choixTresor;
    FILE *fichierTresors;
    int num = 0;
    fichierTresors = fopen("sauv_tresor.txt", "w");
    char liste_tresor[24] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x2A, 0x2B, 0x7D, 0x2D,
                             0x2E, 0x2F, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
                             0x40, 0x5B, 0x5D, 0x5E, 0x5F, 0x7B};
    int coordonneeX[12] = {0, 0, 2, 2, 2, 2, 4, 4, 4, 4, 6, 6};
    int coordonneeY[12] = {2, 4, 0, 2, 4, 6, 0, 2, 4, 6, 2, 4};
    int compteur = 0;
    int coordCursorX, coordCursorY = 0;
    while (compteur != 12) {
        set_color(BLACK, YELLOW);
        do {
            choixCoord = rand() % 12;// choisit aléatoirement le caractère à afficher
        } while ((coordonneeY[choixCoord] == -1) && (coordonneeX[choixCoord] == -1));
        do {
            choixTresor = rand() % 24;
        } while (liste_tresor[choixTresor] == -1);
        set_color(GREEN, YELLOW);
        coordCursorX = (6 * coordonneeY[choixCoord]) + 8;// il se place aux coordonées x et y correcte
        coordCursorY = (3 * coordonneeX[choixCoord]) + 4;
        coordonneeY[choixCoord] = -1;
        coordonneeX[choixCoord] = -1;
        fprintf(fichierTresors, "%d %d %c\n", coordCursorX, coordCursorY, liste_tresor[choixTresor]);
        liste_tresor[choixTresor] = -1;
        compteur += 1;
    }
    fclose(fichierTresors);
}

void affichage_tresor(FILE *fichierTresors){
    fichierTresors = fopen("sauv_tresor.txt", "r");
    int compteur = 0;
    int coordX = 0, coordY = 0;
    char tresor = 0;
    while (compteur!=12){
        fscanf(fichierTresors, "%d %d %c", &coordX, &coordY, &tresor);
        gotoxy(coordX, coordY);
        set_color(GREEN, YELLOW);
        printf("%c", tresor);
        set_color(BLACK, BLACK);
        compteur += 1;
    }
    fclose(fichierTresors);
}

/////////////////////////////////////////////////////DECALAGE///////////////////////////////////////////////////////////
//Ce sous programme sert au decalage de la carte au debut des tours de chaque joueur
int decalage(t_plateau matricePlateau[][7], int matriceCarteEnRab[][3], t_joueurs TousLesJoueurs[], int nbJoueur, FILE *fichierTresors){
    int matriceCarteEnRabTempo[3][3] = {0};
    char lettreRentree;
    int nombreRentree;
    set_color(WHITE, BLACK);
    afficher_joueur(TousLesJoueurs,matricePlateau,nbJoueur);
    set_color(GREEN, YELLOW);
    affichage_tresor(fichierTresors);
    set_color(WHITE, BLACK);
    gotoxy(0,30);
    printf("\nRentrez une colonne et une ligne ou vous souhaitez rentrer votre carte :\n");
    scanf("%c %d", &lettreRentree, &nombreRentree);
    while (((lettreRentree > 96) && (lettreRentree < 103)) || ((lettreRentree < 65) || (lettreRentree > 71)) ||
           ((nombreRentree < 1) || (nombreRentree > 7)) || (((lettreRentree %2 == 0) && ((lettreRentree >= 65) &&
                                                                                         (lettreRentree <= 71))) && ((nombreRentree >= 2) && (nombreRentree <= 6))) || (((lettreRentree %2 == 1) &&
                                                                                                                                                                         ((lettreRentree >= 65) && (lettreRentree <= 71))) && (nombreRentree % 2 == 1) && ((1 <= nombreRentree) &&
                                                                                                                                                                                                                                                           (nombreRentree <= 7)))){// blindage afin d'etre sur que les valeurs entree sont correcte

        ///transforme minuscule en majuscule
        if ((lettreRentree > 96) && (lettreRentree < 103)) {
            lettreRentree -= 32;
        }

        ///si la case choisie est fixe
        if (((lettreRentree %2 == 1) && ((lettreRentree >= 65) && (lettreRentree <= 71))) && (nombreRentree % 2 == 1)
            && ((1 <= nombreRentree) && (nombreRentree <= 7))) {
            printf("\nNon cette case est fixe et ne peut etre bouge, entrer une lettre et un nombre valable :\n");
        }

        ///si la case choisie est à l'intérieur du labyrinthe
        if (((lettreRentree %2 == 0) && ((lettreRentree >= 65) && (lettreRentree <= 71))) && ((nombreRentree >= 2) &&
                                                                                              (nombreRentree <= 6))) {
            printf("\nCette case est dans le labyrinthe, entrer une lettre et un nombre valable :\n");
        }

        if (((lettreRentree < 65) || (lettreRentree > 71)) && ((1 <= nombreRentree) && (nombreRentree <= 7))) {
            printf("\nEntrez une lettre entre A et G avant votre chiffre :\n");
        }
        if (((lettreRentree >= 65) && (lettreRentree <= 71)) && ((nombreRentree < 1) || (nombreRentree > 7))) {
            printf("\nEntrer un nombre entre 0 et 7 apres votre lettre. Veuillez reessayer :\n");
        }
        if (((lettreRentree < 65) || (lettreRentree > 71)) && ((nombreRentree < 1) || (nombreRentree > 7))){
            printf("\nLa combinaison ne correspond à aucune case du tableau. Veuillez reessayer :\n");
        }

        printf("\nReessayez :\n");
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
}

// Ce programme permet à l'utilisateur de pouvoir tourner la carte que l'on a en main
void rotationCarteEnRab(t_plateau matricePlateau[][7], t_plateau tableauCarte[], int matriceCarteEnRab[3][3], int numMatriceEnRab){
    char reponseBinaire;
    char rotation;
    gotoxy(0,32);
    set_color(WHITE, BLACK);
    printf("\nVoulez-vous tourner votre carte ? (o = oui // n = non)\n");
    while (1) {
        scanf("%c", &reponseBinaire);
        if (reponseBinaire == 'O' || reponseBinaire == 'o' || reponseBinaire == 'N' || reponseBinaire == 'n') {
            break; // sortie de la boucle
        }
        while (getchar() != '\n'); // vide le tampon
        printf("Reessayez :\n");
    }
    do {
        if (reponseBinaire == 'O' || reponseBinaire == 'o') {
            set_color(WHITE, BLACK);
            printf("\nDans quel sens voulez vous tourner votre carte : (g = gauche // d = droite) (v == Valide)\n");
            while (1) {
                scanf("%c", &rotation);
                if (rotation == 'G' || rotation == 'g' || rotation == 'D' || rotation == 'd' ||
                    rotation == 'v') {
                    break; // sortie de la boucle
                }
                while (getchar() != '\n'); // vide le tampon
                printf("Reessayez :\n");
            }
        }
        else{
            break;
        }
        //rotation droite
        if (rotation == 'G' || rotation == 'g') {
            //rotation carte I
            if (numMatriceEnRab == 0 || numMatriceEnRab == 1) {
                numMatriceEnRab = (numMatriceEnRab == 1) ? 0 : 1;
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab].matrice[j][k];
                    }
                }
            }
            //rotation carte en L
            if (numMatriceEnRab >= 2 && numMatriceEnRab <= 5) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab + 1].matrice[j][k];
                        if (numMatriceEnRab == 5) {
                            numMatriceEnRab = 2;
                        }
                    }
                }
            }
            //rotation carte en T
            if (numMatriceEnRab >= 6 && numMatriceEnRab <= 9) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab + 1].matrice[j][k];
                        if (numMatriceEnRab == 9) {
                            numMatriceEnRab = 6;
                        }
                    }
                }
            }
        }
        //Rotation droite
        if (rotation == 'D' || rotation == 'd'){
            //rotation carte I
            if (numMatriceEnRab == 0 || numMatriceEnRab == 1) {
                numMatriceEnRab = (numMatriceEnRab == 1) ? 0 : 1;
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab].matrice[j][k];
                    }
                }
            }
            //rotation carte en L
            if (numMatriceEnRab >= 2 && numMatriceEnRab <= 5) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab - 1].matrice[j][k];
                        if (numMatriceEnRab == 2){
                            numMatriceEnRab = 5;
                        }
                    }
                }
            }
            //rotation carte en T
            if (numMatriceEnRab >= 6 && numMatriceEnRab <= 9) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        matriceCarteEnRab[j][k] = tableauCarte[numMatriceEnRab - 1].matrice[j][k];
                        if (numMatriceEnRab == 6){
                            numMatriceEnRab = 9;
                        }
                    }
                }
            }
        }

    } while (rotation != 'v');

    system("cls");
    mise_en_forme();
    affichage_matrice(matricePlateau);
    set_color(WHITE, BLACK);
    printf("\nVoici votre carte :");
    affichage_1_carte(matriceCarteEnRab);
    set_color(WHITE, BLACK);
}

////////////////////////////////////////////////ENREGISTREMENT MATRICE//////////////////////////////////////////////////
// Comme dit dans le non, il permet d'enregistrer le labyrinthe
void enregistrement_matrice(t_plateau matricePlateau[7][7]){
    FILE *fp;
    fp = fopen("sauv_matrice.txt", "w");
    if (fp != NULL){
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        fprintf(fp, "%d ", matricePlateau[i][j].matrice[k][l]);
                        // print dans le fichier
                    }
                    fprintf(fp, "\n");
                }
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        // ferme le fichier
    }
    else{
        printf("erreur");
        exit(1);
    }
}
// permet de print le labyrinthe à partir du fichier sauvegarder (juste au dessus)
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
// Comme dit dans le non, il permet d'enregistrer les données des joueurs
void enregistrement_joueur(int nbJoueurs, t_joueurs TousLesJoueurs[]){
    FILE *fichier;
    fichier = fopen("sauv_joeuur.txt", "w");
    // ouverture du fichier
    if (fichier != NULL){
        for (int i = 0; i<nbJoueurs; i++) {
            fprintf(fichier, "%s ", TousLesJoueurs[i].prenom);// print dans le fichier
            fprintf(fichier, "%d ", TousLesJoueurs[i].xcoord);
            fprintf(fichier, "%d ", TousLesJoueurs[i].ycoord);
            for (int j = 0; j<(24/nbJoueurs); j++) {
                fprintf(fichier, "%s", TousLesJoueurs[i].carteTresorsaChercher);
            }
        }
        fclose(fichier);// fermeture
    }
    else{
        printf("erreur");
        exit(1);
    }
}
// permet de print les données des joueurs à partir du fichier sauvegarder (juste au dessus)
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

// notre menu permettant de :
void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[],FILE *fichierTresors){
    system("cls");
    int choixMenu = 0;
    char entrer;
    set_color(CYAN, BLACK);
    swag();
    printf("\n\n\t\t\t\t\t\tBienvenu(e) dans le jeu du Labyrinthe ! Voici le menu :\n\n\t\t\t\t\t\t\t\t1 - Nouvelle partie\n\t\t\t\t\t\t\t\t2 - Charger une partie\n\t\t\t\t\t\t\t\t3 - Les regles du jeu\n\t\t\t\t\t\t\t\t4 - Quitter\n");
    scanf("%d", &choixMenu);
    while ((choixMenu < 1) || (choixMenu > 4)){
        printf("\t\t\t\t\t\tVeuillez choisir parmi les options proposees. Reessayez :\n");
        scanf("%d",&choixMenu);
    }
    switch (choixMenu) {
        case 1: // jouer une nouvelle partie
            TousLesJoueurs[0].xcoord = 8;TousLesJoueurs[0].ycoord=4;
            TousLesJoueurs[1].xcoord = 44;TousLesJoueurs[1].ycoord=4;
            TousLesJoueurs[2].xcoord = 8;TousLesJoueurs[2].ycoord=22;
            TousLesJoueurs[3].xcoord = 44;TousLesJoueurs[3].ycoord=22;
            jeu_nouvelle_partie(TousLesJoueurs, matricePlateau, tableauCarte,fichierTresors);
            break;
        case 2:// reprendre une partie
            system("cls");
            lecture_matrice_fichier(fp, matricePlateau);
            affichage_matrice(matricePlateau);
            break;
        case 3:// les regles
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
            menu (matricePlateau, tableauCarte, fp, TousLesJoueurs,fichierTresors);
            break;
        case 4:// quitter
            system("cls");
            printf("A bientot !");
            break;
    }
}

// pareil que le menu mais en partie, afin de pouvoir mettre pause à tout moment
void pause(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[], char liste_tresor[], FILE *fichierTresors){
    system("cls");
    int choixMenu = 0;
    char entrer;
    carte(tableauCarte);
    set_color(CYAN, BLACK);
    swag();
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tPause :\n\n\t\t\t\t\t\t\t\t\t1 - Reprendre Partie\n\t\t\t\t\t\t\t\t\t2 - Nouvelle Partie\n\t\t\t\t\t\t\t\t\t3 - Les regles du jeu\n\t\t\t\t\t\t\t\t\t\t\t4 - Quitter le jeu\n\n\n\n\t\t\t\t\t\t\t\t\t");
    scanf("%d", &choixMenu);
    while ((choixMenu !=1) &&  (choixMenu!=2) && (choixMenu!=3) && (choixMenu!=4)){
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\tveuillez choisir parmi les options proposees:\n\n\n\n\t\t\t\t\t\t\t\t\t");
        scanf("%d",&choixMenu);
    }
    switch (choixMenu) {
        case 1:
            lecture_matrice_fichier(fp, matricePlateau);
            break;
        case 2:
            TousLesJoueurs[0].xcoord = 8;TousLesJoueurs[0].ycoord=4;
            TousLesJoueurs[1].xcoord = 44;TousLesJoueurs[1].ycoord=4;
            TousLesJoueurs[2].xcoord = 8;TousLesJoueurs[2].ycoord=22;
            TousLesJoueurs[3].xcoord = 44;TousLesJoueurs[3].ycoord=22;
            jeu_nouvelle_partie(TousLesJoueurs, matricePlateau,tableauCarte, fichierTresors);
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
            pause(matricePlateau, tableauCarte, fp, TousLesJoueurs,liste_tresor, fichierTresors);
            break;
        case 4:
            system("cls");
            printf("A bientot !");
            break;
    }
}

//Notre programme regroupant tout nos sous programme permettant de lancer une partie
void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[7][7], t_plateau tableauCarte[],FILE *fichierTresors){
    int nbJoueur;
    int matriceCarteEnRab[3][3] = {0};
    int numMatriceEnRab;
    int numeroTresor = 0;
    int num = 0;
    int p = 1;
    char liste_tresor[24] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x2A, 0x2B, 0x7D, 0x2D,
                             0x2E, 0x2F,0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
                             0x40, 0x5B, 0x5D, 0x5E,0x5F, 0x7B};
    carte(tableauCarte);
    plateau_cartes_fixes(matricePlateau, tableauCarte);
    plateau_toutes_carte(matricePlateau, tableauCarte, matriceCarteEnRab, &numMatriceEnRab);
    system("cls");
    swag();
    printf("\n\t\t\t\t\t\t\tVeuillez entrer le nombre de joueur :\n");
    scanf("%d", &nbJoueur);
    while((nbJoueur<2) || (nbJoueur>4)){// blindage permettant d'avoir un nombre de joueur cohérant
        printf("\n\t\t\t\t\t\tLe nombre de joueur doit etre compris entre 2 et 4:\n");
        scanf("%d",&nbJoueur);
    }
    for (int i = 0; i < nbJoueur; i++) {
        system("cls");
        swag();
        fflush(stdin);
        printf("\n\t\t\t\t\t\t\tJoueur %d, veuillez entrer votre nom ou pseudo :\n", i + 1);
        scanf("%s", TousLesJoueurs[i].prenom);// permet au joueur de mettre son nom
        system("cls");
        fflush(stdin);
        swag();
        printf("\n\t\t\t\t\t\t\tVeuillez entrer la lettre qui vous representera :\n");
        scanf("%s", TousLesJoueurs[i].lettresurplateau);//permet au joueur d'afficher la lettre qu'il veut sur le labyrinthe
    }
    distribution_tresor(nbJoueur, TousLesJoueurs, liste_tresor);
    generation_tresor();
    set_color(BLACK, BLACK);
    while (p != 0) {
        for (int i = 0; i < nbJoueur; i++) {// Permet de faire toute la partie, avec les programmes déjà expliqué
            system("cls");
            set_color(WHITE, BLACK);
            printf("A votre tour, voici le plateau :\n");
            set_color(BLACK, BLACK);
            affichage_matrice(matricePlateau);
            set_color(BLACK, BLACK);
            afficher_joueur(TousLesJoueurs, matricePlateau, nbJoueur);
            enregistrement_matrice(matricePlateau);
            set_color(WHITE, BLACK);
            printf("\n%s, Voici votre carte :", TousLesJoueurs[i].prenom);
            affichage_1_carte(matriceCarteEnRab);
            set_color(WHITE, BLACK);
            printf("\nVoici vos tresors a aller chercher :\n");
            printf("%c", TousLesJoueurs[i].carteTresorsaChercher[numeroTresor]);
            set_color(BLACK, BLACK);
            affichage_tresor(fichierTresors);
            rotationCarteEnRab(matricePlateau, tableauCarte, matriceCarteEnRab, numMatriceEnRab);
            decalage(matricePlateau, matriceCarteEnRab, TousLesJoueurs, nbJoueur, fichierTresors);
            system("cls");
            affichage_matrice(matricePlateau);
            affichage_tresor(fichierTresors);
            afficher_joueur(TousLesJoueurs, matricePlateau, nbJoueur);
            deplacement_jouer(TousLesJoueurs, matricePlateau, i, nbJoueur, numeroTresor, fichierTresors);
        }
    }
}


// Ce sous programme permet d'afficher les joueurs dans le labyrinthe grace à ces coordonées x et y ( fonction gotoxy)
void afficher_joueur(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int nbJoueur){
    for (int i=0;i<nbJoueur;i++){
        set_color(BLACK, YELLOW);
        gotoxy(TousLesJoueurs[i].xcoord,TousLesJoueurs[i].ycoord);
        printf("%s",TousLesJoueurs[i].lettresurplateau);
    }
    gotoxy(28, 24);
}

// permet au joueur de se déplacer dans le labyrinthe
void deplacement_jouer(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int i,int nbJoueur,int numeroTresor,FILE *fichierTresors ){
    char mouvement;
    int Xcoord;int Ycoord;
    set_color(WHITE, BLACK);
    printf("\nAvancez ou vous voulez, pour valider votre emplacement, appuyer sur v :\n");
    do {
        Xcoord = (TousLesJoueurs[i].xcoord - 8) / 6;// transformer les coordonnées afin de les transformer en chiffre entre 0 et 6 pour notre grande matrice
        Ycoord = (TousLesJoueurs[i].ycoord - 4) / 3;
        gotoxy(0, 26);
        set_color(WHITE, BLACK);
        scanf("\n%c", &mouvement);
        printf("  ");

        if (mouvement == 's') {// aller en bas
            //if ((matricePlateau[Xcoord][Ycoord].matrice[2][1] != 1) && (matricePlateau[Xcoord + 1][Ycoord].matrice[0][1] != 1)){
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].ycoord += 3;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
            //}
            //else{
            //  printf("\nVous ne pouvez pas traverser un mur!");
            //}
        }
        if (mouvement == 'z') {// aller en haut
            //if ((matricePlateau[Xcoord][Ycoord].matrice[0][1] != 1) && (matricePlateau[Xcoord-1][Ycoord].matrice[2][1] != 1)){
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].ycoord -= 3;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
            //}
            //else{
            //     printf("\nVous ne pouvez pas traverser un mur!");
            //}
        }
        if (mouvement == 'q') {// aller à gauche
            //if ((matricePlateau[Xcoord][Ycoord].matrice[1][0] != 1) && (matricePlateau[Xcoord][Ycoord - 1].matrice[1][2] != 1)) {
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].xcoord -= 6;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
            //}
            //else{
            //    printf("\nVous ne pouvez pas traverser un mur!");
            //}
        }
        if (mouvement == 'd') {// aller à droite
            //if ((matricePlateau[Xcoord][Ycoord].matrice[1][2] != 1) && (matricePlateau[Xcoord][Ycoord + 1].matrice[1][0] != 1)){
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            bg_color(YELLOW);
            text_color(YELLOW);
            fflush(stdin);
            printf("0");
            set_color(BLACK, YELLOW);
            TousLesJoueurs[i].xcoord += 6;
            gotoxy(TousLesJoueurs[i].xcoord, TousLesJoueurs[i].ycoord);
            printf("%s", TousLesJoueurs[i].lettresurplateau);
            //}
        }
        recuperation_tresor(fichierTresors,TousLesJoueurs, nbJoueur,&numeroTresor,i);// regarder si le joueur a recuperer en trésor
    } while (mouvement != 'v');// quitter le sous programme
}

// Ce sous programme permet au joueur de savoir si il a pris un trésor et de lui donner le trésor suivant à aller chercher
void recuperation_tresor(FILE *fichierTresors, t_joueurs TousLesJoueurs[],int nbJoueur,int *numeroTresor,int i){
    int listeCoordX[12] = {0}, listeCoordY[12] = {0};
    char tresorPresent[12] = {0};
    fichierTresors = fopen("sauv_tresor.txt", "r");// ouvre le fichier pour récupérer ses données
    for (int j = 0; j<12; j++) {
        fscanf(fichierTresors, "%d %d %c", &listeCoordX[i], &listeCoordY[i], &tresorPresent[i]);
    }
    for (int j=0;j<12;j++){
        if ((TousLesJoueurs[i].xcoord == listeCoordX[j]) && (TousLesJoueurs[i].ycoord == listeCoordY[j])){
            if (TousLesJoueurs[i].carteTresorsaChercher[*numeroTresor] == tresorPresent[j]){
                printf("\nVous avez recupérer votre trésor, Bravo ! En voici un nouveau :\n");
                *numeroTresor += 1;
            }
        }
    }
}