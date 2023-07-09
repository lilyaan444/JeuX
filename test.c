struct Plateau
{
    int L;
    int C;
    int tab[9][9];
};

int main(){
    int L,C;
    do
    {
        initialiserPlateau(L, C, &pl)
        jouerPartie(&pl)
    } while (continuer);
    
}

void initialiserPlateau(struct Plateau* pl, int L, int C){
pl -> L=L;
pl -> C=C;

//initialisation
for (i = 0; i < L; i++)
{
    for (j = 0; i < C; j++)
    {
        pl -> tab[i][j] = 0;
    }
}
}

void afficherTableau(struct Plateau* pl, int L, int C){

for (i = 0; i < L; i++)
{
    for (j = 0; i < C; j++)
    {
        printf(tab[i][j]);
    }
}
}











//------------------------------------JouerPartie----------------------------------------//


void jouerPartie(struct Plateau* pl, int L, int C){
    int nombre_tours = (L*C-1)/2;
    int i;
    for(i=1; i <= nombre_tours; i++)
    {
        clear();
        afficherPl(pl);
        ajouterPion(pl, 1, i); //ajouter au plateau pour le joueur 1 et le ième pion
        afficherPl(pl);
        ajouterPion(pl, 1, i); //ajouter au plateau pour le joueur 2 et ième pion
    }
    int j = verifierVainqueur(pl);
}


//------------------------------------Ajouter pion----------------------------------------//


void ajouterPion(struct Plateau* pl, int joueur, int i){
		// déclarer 2 variables (int ligne = 2, int colonne = 4)
    // 2 scanf quelle ligne qu'elle colone
    // vérifier que la case exite et qu'elle n'est pas utiliser
	 // Plateau : 3 lignes x 5 colonnes => pl.L <= lignes
	// Case(2,4) 
	//if( pl.tab[2][4] === 0) === false (case vide)
	//if( pl.tab[2][4] === 0) === true (case vide)
// pl.tab[2][4] = i
	// printf("pion placé!"); wait / sleep(10)
	}

//------------------------------------VerifierVainqueur----------------------------------------//


int verifierVainqueur(struct Plateau* pl) {
	int ligne, colonne;
	int i, j;
	for (i = 0; i < pl -> L; i++) {
		for (j = 0; j < pl -> C; j++) {
			if(pl -> tab[i][j] == 0) {
				ligne = i;
				colonne = j;
			}
		} 
	}

	// la case vide est à la position (ligne, colonne)

	int scoreJoueur1 = 0 , scoreJoueur2 = 0;

	for (i=0; i <= ligne +1; i++) {
		for (j=0; j <= colonne +1; j++) {

		// pl.tab[i][j]  => couleur ?
		if (couleur = "la couleur du joueur 1") {
			scorejoueur1 = scoreJoueur1 + pl -> tab[i][j];
		}
		else (couleur = "la couleur du joueur 2"){
				scorejoueur2 = scorejoueur2 + pl -> tab[i][j];
		}
		
			
		}
	}

	if (scoreJoueur1 > scoreJoueur2) {
		return 1;
	}
	else if (scoreJoueur2 < scoreJoueur1) {
		return 2;
	}
	else {
		return 0;
	}
}