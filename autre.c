#include <stdio.h>
#include <stdlib.h>
int NB_LIG, NB_COL;
typedef enum { VIDE, J1, J2 } ValeurGrille;
typedef enum { FALSE, TRUE } Boolean;
ValeurGrille grille[8][8];
static int prochainJoueur = J1;
int scorej1=0;
int scorej2=0;
char j1[50];
char j2[50];
#define MEDAILLE	"\U0001F947"
void demandepseudo(){
printf("Entrez le nom du \e[0;34m joueur 1\e[0m : ");
  scanf("%s",&j1);
  printf("Entrez le nom du \e[0;31mjoueur 2\e[0m : ");
  scanf("%s",&j2);
  }
void demandeLC() {

 
  do {

    printf("Choisir la dimension de la table de jeu avec L nombres impairs de "
           "lignes et C nombres impairs de colonnes sachant que vous devez "
           "avoir au mininum 3 comme valeur et au maximum 7: \n ");
    printf("Ligne du plateau = : ");
    scanf("%d", &NB_LIG);

    printf("Colonne du plateau = : ");
    scanf("%d", &NB_COL);

  } while ((NB_LIG > 7) || (NB_LIG < 3) || (NB_COL > 7) || (NB_COL < 3) ||
           (NB_LIG == 4) || (NB_LIG == 6) || (NB_COL == 4) || (NB_COL == 6));

}
void initialiseGrille() { //initialise un tableau vide remplis de 0. 
  int i, j;
  for (i = 0; i < NB_LIG; i++) {
    for (j = 0; j < NB_COL; j++) {
      grille[i][j] = VIDE;
    }
  }
}

void afficheGrille() {
  int i, j;
  for (i = 0; i < NB_LIG; i++) {
    for (j = 0; j < NB_COL; j++) {
      if (grille[i][j] != abs(grille[i][j]))
      {

        printf("\e[0;31m%4d\e[0m",abs(grille[i][j]));
       printf("|");
      }
      else if ( (grille[i][j]) > 0 ) {

        printf("\e[0;34m%4d\e[0m", grille[i][j]);
        printf("|");
      } 
      
      if (grille[i][j] == VIDE) {

        printf("%4d", VIDE);
        printf("|");
      } 
        
    }
    printf("\n");
  }
  printf("\n");
}
void choixjoueur1(j1, j2){
  if(prochainJoueur == J1)
    printf("\e[0;34m %s \e[0m c'est votre tour \n",j1);
  else if(prochainJoueur == J2)
    printf("\e[0;31m %s \e[0m c'est votre tour \n",j2);
}

void metUnPionSurLaGrille(nombrejetonjoue) {
  int ligne, col, nombrejeton = ligne * col - 1;
  Boolean saisieCorrecte = FALSE;

  printf("Veuillez saisir la ligne et la colonne\n");

  while (saisieCorrecte = TRUE) {

    printf("LIGNE: ");
    scanf("%d", &ligne);
    printf("COLONNE: ");
    scanf("%d", &col);
    printf("\n");
    printf("\a");
    if (prochainJoueur == J1)
      prochainJoueur = J2;
    else
      prochainJoueur = J1;

    if ((ligne > 0) && (ligne <= NB_LIG) && (col > 0) && (col <= NB_COL)) {
      ligne--;
      col--;
      if (grille[ligne][col] != VIDE){
        printf("Cette case a déjà été remplie. Veuillez recommencer: \n");
        if (prochainJoueur == J1)
        prochainJoueur = J2;
        else
        prochainJoueur = J1;
        
        }
      else {
        saisieCorrecte = TRUE;
        if (prochainJoueur == J2) {
          grille[ligne][col] = nombrejetonjoue / 2;
          break;
        } else {
          grille[ligne][col] = -(nombrejetonjoue / 2);
          if (grille[ligne][col] < 0)
            printf("\e[0;31m %4d \e[0m",grille[ligne][col]);
          break;
        }
      }

    } else {
      printf(
          "Indice de ligne ou de colonne incorrect. Veuillez recommencer:\n");
          if (prochainJoueur == J1)
          prochainJoueur = J2;
          else
      prochainJoueur = J1;
      saisieCorrecte = FALSE;
    }
  }
}
void somme() {
  
  int i = 0, j = 0,k,l,scorepartie1=0,scorepartie2=0;
  int somme;
  
  for (i = 0; i < NB_LIG; i++)
    for (j = 0; j < NB_COL; j++)
      if (grille[i][j] == VIDE) {
        for (k =i -1; k <=i+1;k++){
          for (l=j-1;l<=j+1;l++){  
            if ( grille[k][l] != abs(grille[k][l]))scorepartie1+=grille[k][l];
            else scorepartie2+=grille[k][l];
            somme=scorepartie1+scorepartie2;
          }
        } 
      }
  printf("Le score de \e[0;31m %s \e[0m est : %d ",j2,abs(scorepartie1));
  printf("\n");
  printf("Le score de \e[0;34m %s \e[0m est : %d ",j1,abs(scorepartie2));
  printf("\n");
  if (somme < 0){
    printf(" \e[0;34m %s \e[0m a gagné \U0001F947\n",j1);
    scorej1++;
    printf("Point(s) de \e[0;34m %s \e[0m : %d \n",j1,scorej1);
    printf("Point(s) \e[0;31m %s \e[0m : %d \n",j2,scorej2);
    printf("\n");
    }
  else if (somme >= 1){
    printf("\e[0;31m %s \e[0m a gagné \U0001F947\n",j2);
    scorej2++;
    printf("Point(s) de \e[0;34m %s \e[0m : %d \n",j1,scorej1);
    printf("Point(s) de \e[0;31m %s \e[0m : %d \n",j2,scorej2);
    printf("\n");
    }
  else if (somme == 0)
    printf("Il y a égalité");
 
}

int main(void) {
  int jeton, i, j, rejouer;
  int nombrejetonjoue = 2;
  static int scorej1,scorej2;
  int nbpartie;
  nbpartie=0;
 printf("\t\t\t\t\t\t\t\t\e[0;35m JEU X \e[0m\n");
  printf("\b");
 printf("\e[0;36m=================================================================\e[0m\n");
  printf("\e[0;35m Les règles sont simples. Le jeu se fait avec deux joueurs. Chacun votre tour vous allez devoir poser un jeton sur le plateau, ce dernier va augmenter de valeur au début de votre prochain tour. A la fin, il restera une case vide et c'est celui qui a la plus petite somme autour du 0 qui gagne. \e[0m\n");
  printf("\e[0;36m=================================================================\e[0m\n");
  
  demandepseudo();

    printf("\n");

  
  do {initialiseGrille();
    demandeLC();
  do {
    choixjoueur1(j1,j2);
    metUnPionSurLaGrille(nombrejetonjoue);
    afficheGrille();
nombrejetonjoue= nombrejetonjoue+1;
  } 
    while (nombrejetonjoue <= (NB_COL*NB_LIG));
  somme();
  nombrejetonjoue = 2;
     if (prochainJoueur == J1)
          prochainJoueur = J2;
          else
      prochainJoueur = J1;
    printf("Souhaitez vous rejouer ? Si oui, tapez 1 sinon tapez une autre touche.\n");
    scanf("%d",&rejouer);
    }while (rejouer==1);
}