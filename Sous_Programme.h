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

#define SIZE1 12
#define SIZE2 16
#define SIZE3 6
#define NEW_SIZE (SIZE1 + SIZE2 + SIZE3)

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
void plateau_toutes_carte(t_plateau matricePlateau[][7], t_plateau tableauCarte[],int matriceCarteEnRab[3][3],int *numMatriceEnRab);
int decalage(t_plateau matricePlateau[][7], int matriceCarteEnRab[][3], t_joueurs TousLesJoueurs[], int nbJoueur, FILE *fichierTresors);
void rotationCarteEnRab(t_plateau matricePlateau[][7], t_plateau tableauCarte[], int matriceCarteEnRab[3][3], int numMatriceEnRab);
void pause(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[], char liste_tresor[], FILE *fichierTresors);


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


void menu(t_plateau matricePlateau[][7], t_plateau tableauCarte[], FILE *fp, t_joueurs TousLesJoueurs[],FILE *fichierTresors);
void jeu_nouvelle_partie(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], t_plateau tableauCarte[],FILE *fichierTresors);
void deplacement_jouer(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int i,int nbJoueur,int numeroTresor,FILE *fichierTresors);
void afficher_joueur(t_joueurs TousLesJoueurs[], t_plateau matricePlateau[][7], int nbJoueur);
void affichage_tresor(FILE *fichierTresors);
void generation_tresor();
void recuperation_tresor(FILE *fichierTresors, t_joueurs TousLesJoueurs[],int nbJoueur, int *numeroTresor,int i);
void distribution_tresor(int nbJoueur, t_joueurs TousLesJoueurs[], char liste_tresor[]);

#endif //PROJET_ALGORITHMIQUE_LABYRINTHE_SOUS_PROGRAMME_H