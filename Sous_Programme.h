//
// Created by Ce PC on 14/12/2022.
//

#ifndef PROJET_ALGORITHMIQUE_LABYRINTHE_SOUS_PROGRAMME_H
#define PROJET_ALGORITHMIQUE_LABYRINTHE_SOUS_PROGRAMME_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef enum{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE,
    DARK
} COLORS;

typedef struct t_plateau{
    int matrice[3][3];
} t_plateau;

typedef struct t_cartes{
    int matrice[3][3];
}t_cartes;


//Structure Joueur
typedef struct t_joueurs{
    char prenom[15];
    int xcoord,ycoord;
    char carteTresorsaChercher[12];
}t_joueurs;


//sous programmes cartes
void mise_en_place_cartes(int matriceEnLBasDroite[3][3], int matriceEnIHautBas[3][3], int matriceEnTDroite[3][3],
                          int matriceEnIDroiteGauche[3][3], int matriceEnLBasGauche[][3], int matriceEnLHautDroite[3][3],
                          int matriceEnLHautGauche[3][3], int matriceEnTBas[3][3],int matriceEnTGauche[3][3],
                          int matriceEnTHaut[3][3]);

void tableau_de_carte(t_cartes tableauCarte[10], int matriceEnLBasDroite[3][3], int matriceEnIHautBas[3][3],
                      int matriceEnTDroite[3][3], int matriceEnIDroiteGauche[3][3], int matriceEnLBasGauche[][3],
                      int matriceEnLHautDroite[3][3], int matriceEnLHautGauche[3][3], int matriceEnTBas[3][3],
                      int matriceEnTGauche[3][3], int matriceEnTHaut[3][3]);

//cartes en I
void carte_I_haut_bas(int matriceEnIHautBas[][3]);
void carte_I_droite_gauche(int matriceEnIDroiteGauche[][3]);

//cartes en T
void carte_T_droite(int matriceEnTDroite[][3]);
void carte_T_bas(int matriceEnTBas[][3]);
void carte_T_gauche(int matriceEnTGauche[][3]);
void carte_T_haut(int matriceEnTHaut[][3]);

//cartes en L
void carte_L_bas_droite(int matriceEnLBasDroite[][3]);
void carte_L_bas_gauche(int matriceEnLBasGauche[][3]);
void carte_L_haut_droite(int matriceEnLHautDroite[][3]);
void carte_L_haut_gauche(int matriceEnLHautGauche[][3]);


//sous programmes plateau
void plateau_cartes_fixes(t_plateau matricePlateau[7][7], t_cartes tableauCarte[10]);
void plateau_toutes_carte(t_plateau matricePlateau[][7], t_cartes tableauCarte[], int *nbAlea, int *nbCarteT, int *nbCarteL, int *nbCarteI);
int decalage(t_plateau matricePlateau[][7],int matriceCarteEnRab[][3]);


//affichage
void affichage_1_carte(int matrice[3][3]);
void affichage_matrice(t_plateau matricePlateau[][7]);

//mise en forme affichage
void mise_en_forme();
void gotoxy(short x, short y);
void getCursorPosition(int *x, int *y);
void set_color(int colorT,int colorBg);
void text_color(int color);
void bg_color(int color);

void enregistrement_matrice(t_plateau matricePlateau[][7], FILE *fp);
void lecture_matrice_fichier(FILE *fp, t_plateau matricePlateau[7][7]);


int comptage_carte(int *nbAlea, int *nbCarteL, int *nbCarteI, int *nbCarteT, int liste[]);
void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, int nbAlea, int nbCarteT, int nbCarteI, int nbCarteL, t_joueurs TousLesJoueurs[], int *nbJoueur, int matriceCarteEnRab[][3]);
void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int *nbJoueur, FILE *fp);

#endif //PROJET_ALGORITHMIQUE_LABYRINTHE_SOUS_PROGRAMME_H