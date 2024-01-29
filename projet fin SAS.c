#include <stdio.h>
#include <stdlib.h>	
//les fonctions.
void menu();

// structure des taches.
typedef struct{
	int jour;
	int mois;
	int annee;
}date;

typedef struct{
	char name[20];
	char details[50];
	date d;
	int priorite;
	
}Taches;
Taches t[100];
int taille = 0;
// déf de fonction d'ajouter une tache.

void Addtache(){
	
	int i;
	for(i=taille ; i < taille+1 ; i++){

	printf("veuillez entrer le nom du Tache numero %d: \n", i+1);
	scanf(" %[^\n]s", &t[i].name);
	printf("veuillez ajouter une dsicription : \n");
	scanf(" %[^\n]s", &t[i].details);
	printf("veuilez entrer la date d'echeance : \n");
	printf("entrer le jour : \n");
	scanf("%d", &t[i].d.jour);
	printf("entrer le mois : \n");
	scanf("%d", &t[i].d.mois);
	printf("entrer l'annee : \n");
	scanf("%d", &t[i].d.annee);
	printf("ajouter la priorite : \n");
	scanf("%d", &t[i].priorite);
	printf("tache ajouter. \n");
	
	}
	taille++;
	menu();
}

//fonction d'afficher.
void Afficher(){
	for(int i=0 ; i<taille ; i++){
		printf("\t -nom de la tache : %s \n", t[i].name);
		printf("\t -discription : %s \n", t[i].details);
		printf("\t -date d'echeance : %d %d %d \n", t[i].d.jour, t[i].d.mois, t[i].d.annee);
		printf("\t -pritorite : %d \n", t[i].priorite);
	}
	menu();
}
	

// fonction "MENU".
void menu(){
	int x;
	printf("\n\n\t\t*****************MENU*******************\n\n");
	printf("1-Ajouter une Tache.\n");
	printf("2-Afficher la liste des Taches.\n");
	printf("3-Modifier une Tache.\n");
	printf("4-Supprimer une Tache.\n");
	printf("5-Ordonner les Taches.\n");
	printf("6-Flitrer les Taches.\n");
	printf("0-QUITTER.\n");
	
	do{
		printf("Entrer votre choix :\n");
		scanf("%d", &x);
		if(x<0 || x>6)
		printf("votre choix doit etre compris entre 0 et 6. \n");
	
	}while(x<0 || x>6);
	
	
	switch(x){
		case 1:
			Addtache();
		break;
		case 2:
			Afficher();
		break;
	}
}

// debut du main
int main() {
	
	menu();
	
return 0;
}
// fin du main