#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define couleur(param) printf("\033[%sm",param)
#define N 6
#define M 7

//Initialise à vide la grille du Puissance 4
void init_matrice(int matrice[N][M]){
	int i,j;

	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			matrice[i][j] = 0;
		}
	}
}

//Affiche la grille du Puissance 4 du jeu en cours
void afficher_matrice(int matrice[N][M]){
	int i,j;

	printf("\n|					|\n");
	for(i = 0; i < N; i++){
		printf("|	  ");
		for(j = 0; j < M; j++){
			if(matrice[i][j] == 0)printf(" . ");
			if(matrice[i][j] == 1){
				couleur("34");
				printf(" @ ");
				couleur("0");
			}
			if(matrice[i][j] == 2){
				couleur("31");
				printf(" @ ");
				couleur("0");
			}
		}
		printf("  	|\n");
	}
	printf("|					|");
	printf("\n|	   1  2  3  4  5  6  7  	|");
	printf("\n ---------------------------------------");
	printf("\n");
}

//Retourne la bonne ligne
int choix_ligne(int matrice[N][M], int colonne){
	int i;
	int ligne = N-1;

	//Car l'utilisateur choisi une colonne entre 1 et 7 or la matrice est entre 0 et 6
	colonne--;
	
	//Boucle permettant de chercher la premiere la ligne sans pion
	for(i = 1; i <= N; i++){
		if(matrice[N-i][colonne] != 0)ligne--;
	}
	return ligne;
}

//Place le pion du joueur à la colonne qu'il veut et à la bonne ligne
void placer_pions(int matrice[N][M], int colonne, int ligne, int num_joueur){
	//Car l'utilisateur choisi une colonne entre 1 et 7 or la matrice est entre 0 et 6
	colonne--;
	
	if(num_joueur == 1)
		matrice[ligne][colonne] = 1;
	else if(num_joueur == 2)
		matrice[ligne][colonne] = 2;
}

//Parcours la grille du Puissance 4 pour savoir si un joueur a gagné ou non
int gagne(int grille[N][M]){
	int player1 = 0;
	int player2 = 0;
	int i, j, k;

	//Test en ligne
	for(i = 0; i < N; i++){
		player1 = 0;
		player2 = 0;
		for(j = 0; j < M; j++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
		}
	}

	//Test colonne
	for(j = 0; j < M; j++){
		player1 = 0;
		player2 = 0;
		for(i = 0; i < N; i++){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			
			else{
				player1 = 0;
				player2 = 0;
			}
		}
	}

	//Test diagonale droite
	for(k = 3; k <= 5; k++){
		player1 = 0;
		player2 = 0;
		i = 0;

		j = k;
		while(i <= k && j >= 0){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}
	}
		

	for(k = 0; k <= 2; k++){
		player1 = 0;
		player2 = 0;
		j = 6;

		i = k;
		while(i <= 5 && j >= k+1){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j--;	
		}	
	}	
	
	//Test diagonale gauche
	for(k = 3; k >= 1; k--){
		player1 = 0;
		player2 = 0;
		i = 0;

		j = k;
		while(i <= 6-k && j <= 6){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}
	}

	for(k = 0; k <= 2; k++){
		player1 = 0;
		player2 = 0;
		j = 0;

		i = k;
		while(i <= 6-k && j <= 5-k){
			if(grille[i][j] == 1){
				player1++;
				player2 = 0;
				if(player1 == 4)
					return 1;
			}
			else if(grille[i][j] == 2){
				player2++;
				player1 = 0;
				if(player2 == 4)
					return 2;
			}
			else{
				player1 = 0;
				player2 = 0;
			}
			i++;
			j++;	
		}
	}

	return 0;
}
