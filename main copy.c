#include <stdlib.h> //pour maloc
#include <stdio.h> 
#include <stdbool.h> //pour les boolean
#define MEDAILLE	"\U0001F947" //emoji médaille

struct Plateau
{
    int L;
    int C;
    int tab[9][9];
};


//------------------------------------Initialiser plateau----------------------------------------//
void initialiserPlateau(struct Plateau *pl, int L, int C){
pl->L=L;
pl->C=C;
int i,j;

//initialisation
for (i = 0; i < 9; i++)
{
    for (j = 0; j < 9; j++)
    {
        pl->tab[i][j] = 0;
    }
}
}


//------------------------------------Afficher Plateau----------------------------------------//
void afficherPlateau(struct Plateau *pl, int L, int C){

int i, j;
char *text = "PLATEAU DE JEU";

printf("\e[1;37m %19s \e[0m\n", text);
printf("\e[1;37m ======================== \e[0m\n");
printf("\n");
// afficher le plateau avec une boucle qui le parcours en entier et le print avec les bonnes couleurs si elle sont négative ou positives
for (i = 1; i < L+1; i++)
{
    printf("       ");
    printf("|");
    for (j = 1; j < C+1; j++)
    {
        if (pl->tab[i][j] < 0)
        {
            printf("\e[0;31m%2d\e[0m", abs(pl->tab[i][j]));
            printf("|");
        }else if (pl->tab[i][j] > 0)
        {
            printf("\e[0;34m%2d\e[0m", pl->tab[i][j]);
            printf("|");
        }else{
            printf("%2d", pl->tab[i][j]);
            printf("|");
        }
        
    }
    printf("\n");
}



}


//------------------------------------Ajouter pion Joueur 1----------------------------------------//
void ajouterPionJ1(struct Plateau *pl, int L, int C, int jeton1){
    int ligne;
    int colonne;
    printf("Joueur 1 c'est a votre tour\n");

    
    // Récuperer ligne/colone

    printf("Sur quelle ligne voulez vous placez le pion ? : ");
    scanf("%d", &ligne);
    printf("Dans quelle colonne voulez vous placer le pion ? : ");
    scanf("%d", &colonne);


// Vérifier que la case est dans le tableau
while (true)
{
    while (true)
    {
        if ((ligne >= 1 && ligne < L+1) && (colonne >= 1 && colonne < C+1)){
            break;
        }else{
            printf("\e[1;33m Case non valide ! \e[0m\n");
            printf("Sur quelle ligne voulez vous placez le pion ? : ");
            scanf("%d", &ligne);
            printf("Dans quelle colonne voulez vous placer le pion ? : ");
            scanf("%d", &colonne);

        }
    } 
    
//vérifier que la case n'est pas utiliser, et la print si elle ne l'est pas 
    if (pl->tab[ligne][colonne] == 0)
    {
        pl->tab[ligne][colonne] = jeton1;
        printf("pion placé !\n");
        break;
    }else{
        printf("\e[1;33m Case déjà prise ! \e[0m\n");
        printf("Sur quelle ligne voulez vous placez le pion ? : ");
        scanf("%d", &ligne);
        printf("Dans quelle colonne voulez vous placer le pion ? : ");
        scanf("%d", &colonne);

    }
}
}


//------------------------------------Ajouter pion Joueur 2----------------------------------------//
//pareil que AjouterPionJ1
void ajouterPionJ2(struct Plateau *pl, int L, int C, int jeton2){
    int ligne;
    int colonne;
    printf("Joueur 2 c'est a votre tour\n");
    printf("Sur quelle ligne voulez vous placez le pion ? : ");
    scanf("%d", &ligne);
    printf("Dans quelle colonne voulez vous placer le pion ? : ");
    scanf("%d", &colonne);


while (true)
{
    while (true)
    {
        if ((ligne >= 1 && ligne < L+1) && (colonne >= 1 && colonne < C+1)){
            break;
        }else{
            printf("\e[1;33m Case non valide ! \e[0m\n");
            printf("Sur quelle ligne voulez vous placez le pion ? : ");
            scanf("%d", &ligne);
            printf("Dans quelle colonne voulez vous placer le pion ? : ");
            scanf("%d", &colonne);

        }
    } 
    

    if (pl->tab[ligne][colonne] == 0)
    {
        pl->tab[ligne][colonne] = jeton2;
        printf("pion placé !\n");
        break;
    }else{
        printf("\e[1;33m Case déjà prise ! \e[0m\n");
        printf("Sur quelle ligne voulez vous placez le pion ? : ");
        scanf("%d", &ligne);
        printf("Dans quelle colonne voulez vous placer le pion ? : ");
        scanf("%d", &colonne);

    }
}
}


//------------------------------------VerifierVainqueur----------------------------------------//
int verifierVainqueur(struct Plateau *pl, int L, int C, int nb_partie, int scorePartieJ1, int scorePartieJ2){
int i, j, k, l, scorejoueur1 = 0, scorejoueur2 = 0;
int somme;
//parcourir le tableau en cherchant le 0
//quand le 0 est trouver on cherche les case +1 -1 pour faire le tours et calculer le score 
  for (i = 1; i < L+1; i++)
    for (j = 1; j < C+1; j++)
      if (pl->tab[i][j] == 0) {
        for (k =i -1; k <=i+1;k++){
          for (l=j-1;l<=j+1;l++){  
            if (pl->tab[k][l] != abs(pl->tab[k][l])){
                scorejoueur1+=pl->tab[k][l];
            }else {
            scorejoueur2+=pl->tab[k][l];
            somme=scorejoueur1+scorejoueur2;
            }
          }
        } 
      }

//print le score des joueurs eet annoncer le gagnant 

  printf("Le score du Joueur 1 est : %d ", abs(scorejoueur1));
  printf("\n");
  printf("Le score du Joueur 2 est : %d ", abs(scorejoueur2));
  printf("\n\n");
  if (abs(scorejoueur1) > abs(scorejoueur2))
  {
    printf("Le joueur 2 à gagné cette partie %s\n", MEDAILLE);
    scorePartieJ2++;
  }else if (abs(scorejoueur2) > abs(scorejoueur1))
  {
    printf("Le joueur 1 à gagné cette partie %s\n", MEDAILLE);
    scorePartieJ1++;
  }else if (abs(scorejoueur1) == abs(scorejoueur2))
  {
    printf("Il ya eu égalité entre les deux joueurs, personne ne gagne\n");
  }

printf("Le joueur 1 à gagner %d partie\n", scorePartieJ1);
printf("Le joueur 2 à gagner %d partie\n", scorePartieJ2);
nb_partie++;

  
  

}


//------------------------------------JouerPartie----------------------------------------//
void jouerPartie(struct Plateau *pl, int L, int C, bool continuer, int q, char *joueur1, char *joueur2, int nb_partie, int scorePartieJ1, int scorePartieJ2){
    int nombre_tours = ((L*C-1)/2);
    int i;
    int jeton2 = -1;
    int jeton1 = 1;
    for(i = 1; i <= nombre_tours; i++)
    {   
        if (nb_partie % 2 == 0)
        {
            printf("Joueur 1 : %s\n", &joueur1);
            printf("Joueur 2 : %s\n", &joueur2);
            printf("\n");
            afficherPlateau(pl, L, C);
            printf("\n");
            ajouterPionJ1(pl, L, C, jeton1); //ajouter au plateau pour le joueur 1 et le ième pion
            jeton1++;
            printf("Joueur 1 : %s\n", &joueur1);
            printf("Joueur 2 : %s\n", &joueur2);
            printf("\n");
            afficherPlateau(pl, L, C);
            printf("\n");
            ajouterPionJ2(pl, L, C, jeton2); //ajouter au plateau pour le joueur 2 et ième pion
            jeton2--;
        }else if (nb_partie % 2 == 1)
        
        {
            printf("Joueur 1 : %s\n", &joueur1);
            printf("Joueur 2 : %s\n", &joueur2);
            printf("\n");
            afficherPlateau(pl, L, C);
            printf("\n");
            ajouterPionJ2(pl, L, C, jeton2); //ajouter au plateau pour le joueur 1 et le ième pion
            jeton2++;
            printf("Joueur 1 : %s\n", &joueur1);
            printf("Joueur 2 : %s\n", &joueur2);
            printf("\n");
            afficherPlateau(pl, L, C);
            printf("\n");
            ajouterPionJ1(pl, L, C, jeton1); //ajouter au plateau pour le joueur 2 et ième pion
            jeton1--;
        }
        

    }
    afficherPlateau(pl, L, C);
    printf("\n");
    verifierVainqueur(pl, L, C, nb_partie, scorePartieJ1, scorePartieJ2);
    printf("Voulez vous continuer de jouer (1 ou 2)"); // o pour oui, n pour non
    nb_partie++;
    scanf("%d", &q); 
    printf("\n");
    if (q == 1)
    {
      continuer = 1;
    }else
    {
       continuer = 0;
       printf("Merci d'avoir jouer\n");
       exit(EXIT_SUCCESS);
    }
nb_partie++;
}
            


//------------------------------------MAIN----------------------------------------//
int main()
{
    struct Plateau pl;
    int L, C; // Ligne (L) et Colone (C)
    int q;
    char *joueur1;
    char *joueur2;
    bool continuer = 1;
    int nb_partie = 0;
    int scorePartieJ1 = 0, scorePartieJ2 = 0;

    printf("\t\t\t\t\t\t\t\t\e[0;35m JEU X \e[0m\n");
    // Vérfier L et C sont impaires et compris entre 3 et 7
    printf("Entrez un nombre de lignes (impaire entre 3 et 7) :");
    scanf("%d", &L);
    while (true)
    {
        if (L % 2 == 0)
        {
            printf("Mauvaise nombre entrez un nombre de ligne impaire :");
            scanf("%d", &L);
        }else if (L <= 2)
        {
            printf("Nombre trop petit veuillez entrez un nombre entre 3 et 7 :");
            scanf("%d", &L);
        }else if (L >= 8)
        {
            printf("Nombre trop grand  veuillez entrez un nombre entre 3 et 7 :");
            scanf("%d", &L);
        }else
        {
            break;
        }
    }

    printf("Entrez un nombre de colones (impaire entre 3 et 7) :");
    scanf("%d", &C);
    while (true)
    {
        if (C % 2 == 0)
        {
            printf("Mauvaise nombre entrez un nombre de ligne impaire :");
            scanf("%d", &C);
        }else if (C <= 2)
        {
            printf("Nombre trop petit veuillez entrez un nombre entre 3 et 7 :");
            scanf("%d", &C);
        }else if (C >= 8)
        {
            printf("Nombre trop grand  veuillez entrez un nombre entre 3 et 7 :");
            scanf("%d", &C);
        }else
        {
            break;
        }
    }

    printf("Entrez le nom du \e[0;34m joueur 1\e[0m : ");
    scanf("%s", &joueur1);
    getchar();
    printf("Entrez le nom du \e[0;31m joueur 2\e[0m : ");
    scanf("%s", &joueur2);
    printf("Voulez vous jouer ? Si oui, tapez 1 sinon taper 2 : "); // 1 pour oui, 2 pour non
    scanf("%d", &q); 
        if (q == 1)
    {
        continuer = 1;
    }else
    {
       continuer = 0;
       printf("A bientôt\n");
       exit(EXIT_SUCCESS);
    }

    while (continuer == 1)
    {
        initialiserPlateau(&pl, L, C);
        jouerPartie(&pl, L, C, continuer, q, joueur1, joueur2, nb_partie, scorePartieJ1, scorePartieJ2);
    }
    

    printf("fin de partie, merci d'avoir jouer");
}
