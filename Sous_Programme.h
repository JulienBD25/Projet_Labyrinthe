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

//Structure Joueur
typedef struct t_joueurs{
    char prenom[15];
    int xcoord,ycoord;
    char carteTresorsaChercher[24];
    char lettresurplateau[1];
}t_joueurs;

//sous programmes plateau
void plateau_cartes_fixes(t_plateau matricePlateau[7][7], t_plateau tableauCarte[10]);
void plateau_toutes_carte(t_plateau matricePlateau[][7], t_plateau tableauCarte[],int matriceCarteEnRab[][3]);
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

void enregistrement_matrice(t_plateau matricePlateau[][7]);
void lecture_matrice_fichier(FILE *fp, t_plateau matricePlateau[7][7]);


int comptage_carte(int nbAlea, int *nbCarteL, int *nbCarteI, int *nbCarteT, int liste[]);
void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[]);
void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7]);
void deplacement_jouer(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int i);
void afficher_joueur(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int nbJoueur);

#endif //PROJET_ALGORITHMIQUE_LABYRINTHE_SOUS_PROGRAMME_H