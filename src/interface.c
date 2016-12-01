#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/new_fonctions.h"

#define couleur(param) printf("\033[%sm",param)

/**
*\file interface.c
*\brief Interface du Puissance 4

*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/


/**
*\fn int menu()
*\brief Menu pour commencer la partie

*\fn int fin_jeux()
*\brief Menu pour la fin de la partie

*\fn void pseudo_classique(char pseudo1[L], char pseudo2[L])
*\brief Demande les pseudos des joueurs
*/

int menu(){
	int choix;

	system("clear");

	printf("\n ------------------------------- ");
	printf("\n|	        Menu            |");
	printf("\n|				|");
	printf("\n|  1 - Puissance 4 classique	|");
	printf("\n|  2 - Puissance 4 avance	|");
	printf("\n|  3 - Quitter			|");
	printf("\n|				|");
	printf("\n ------------------------------- ");
	
	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;
			case 2: puissance_avance(); return choix;
			case 3: return choix;
			default: printf("\nErreur: votre choix doit etre compris entre 1 et 3\n");
			}
	}while(choix < 1 || choix > 3);

	return 0;
}

int fin_jeux(){
	int choix;

	printf("\n ------------------------------- ");
	printf("\n|	        FIN             |");
	printf("\n|				|");
	printf("\n| 	 1 - Rejouer		|");
	printf("\n|  	 2 - Retour au menu	|");
	printf("\n|  	 3 - Quitter		|");
	printf("\n|				|");
	printf("\n ------------------------------- ");
	
	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;;
			case 2: menu(); return choix;;
			case 3: return choix;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix < 1 || choix > 3);
}

void pseudo_classique(char pseudo1[L], char pseudo2[L]){
	system("clear");
	printf("\nVeuillez choisir vos pseudos sachant qu'ils ne doivent pas depasser 5 caracteres \n \n");
	
	do{
		couleur("31");
		printf("\nJoueur 1: ");
		scanf("%s", pseudo1);
		couleur("0");
		if(strlen(pseudo1) > 5)
			printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
	}while(strlen(pseudo1) > 5);
	couleur("0");

	do{
		couleur("34");
		printf("\nJoueur 2: ");
		scanf("%s", pseudo2);
		couleur("0");
		if(strlen(pseudo2) > 5)
			printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
	}while(strlen(pseudo2) > 5);
}

int quitter(){
	int choix;
	system("clear");

	printf("\n ------------------------------- ");
	printf("\n|	       Quitter          |");
	printf("\n|				|");
	printf("\n|  1 - Quitter sans sauvegarder	|");
	printf("\n|  2 - Quitter et sauvegarder	|");
	printf("\n|				|");
	printf("\n ------------------------------- ");

	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		if(choix < 1 || choix > 2)
			printf("\nErreur: votre choix doit etre 1 ou 2\n");
	}while(choix < 1 || choix > 2);
	
	return choix;
}

int begin(){
	int choix;
	system("clear");

	printf("\n ------------------------------------- ");
	printf("\n|    		  Début          	|");
	printf("\n|					|");
	printf("\n|  1 - Commenecer une nouvelle partie	|");
	printf("\n|  2 - Charger la partie precedente	|");
	printf("\n|					|");
	printf("\n ------------------------------------- ");

	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		if(choix < 1 || choix > 2)
			printf("\nErreur: votre choix doit etre 1 ou 2\n");
	}while(choix < 1 || choix > 2);
	
	return choix;
}