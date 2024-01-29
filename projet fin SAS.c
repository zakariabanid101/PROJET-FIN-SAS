#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
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
int i;
// déf de fonction d'ajouter une tache.

void Addtache(){
	
	int i;
	for(i=taille ; i < taille+1 ; i++){

	printf("veuillez entrer le nom du Tache numero %d: ", i+1);
	scanf(" %[^\n]s", &t[i].name);
	printf("veuillez ajouter une dsicription : ");
	scanf(" %[^\n]s", &t[i].details);
	printf("veuilez entrer la date d'echeance : \n");
	printf("entrer le jour : ");
	scanf("%d", &t[i].d.jour);
	printf("entrer le mois : ");
	scanf("%d", &t[i].d.mois);
	printf("entrer l'annee : ");
	scanf("%d", &t[i].d.annee);
	printf("ajouter la priorite : ");
	scanf("%d", &t[i].priorite);
	printf("tache ajouter. \n");
	
	}
	taille++;
	
	printf("______________________________________________________ \n\n");
	menu();
}

//fonction d'afficher.
void Afficher(){
	for(int i=0 ; i<taille ; i++){
		printf("->Les taches enregistrer sont : \n\n");
		printf("\t -nom de la tache : %s \n", t[i].name);
		printf("\t -discription : %s \n", t[i].details);
		printf("\t -date d'echeance : %d %d %d \n", t[i].d.jour, t[i].d.mois, t[i].d.annee);
		printf("\t -pritorite : %d \n", t[i].priorite);
	}
	menu();
}
//Fonction de la recherche.
int recherche(char mod[20]){
	for(i=0 ; i<taille ; i++){
		int res = strcmp (t[i].name, mod);
		if(res == 0){
			return i;
		}
	
	}
	return -1;
}

//Déf de la Fonction Modifier.
void Modifier(){
	char mod[20];
	printf("entrer le nom du tache que vous voullez modifier : ");
	scanf("%s", mod);
	int res = recherche(mod);
		if(res != -1 ){
			printf("donner le nouveau nom du tache : ");
			scanf(" %[^\n]s", &t[res].name);
			printf("donner la nouvelle description : ");
			scanf(" %[^\n]s", &t[res].details);
			printf("veuilez entrer la nouvelle date d'echeance : \n");
			printf("entrer le jour : ");
			scanf("%d", &t[res].d.jour);
			printf("entrer le mois : ");
			scanf("%d", &t[res].d.mois);
			printf("entrer l'annee : ");
			scanf("%d", &t[res].d.annee);
			printf("ajouter la priorite : ");
			scanf("%d", &t[res].priorite);
			printf("tache a ete modifier. ");
		}
		else
		printf("Erreur, cette tache n'existe pas \n");
		
	menu();
	}
	
//Fonction supprimer.
void supprimer(){
	char sup[20];
		printf("Entrer le nom du tache que vous voullez suprimer : ");
		scanf("%s", sup);
		int res = recherche(sup);
		if(res != -1 ){
		for(i=res ; i<taille ; i++){
			t[res] = t[res+1];
		}
		printf("la tache %s a ete suprimmer. \n", sup);
		
		taille--;
			
		}
		else{
		printf("Erreur, cette tache n'existe pas");
		}
		menu();
}


// fonction "MENU".
void menu(){
	int x;
	printf("\n\n*****************MENU PRINCIPAL : *******************\n\n");
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
		case 3:
			Modifier();
		break;
		case 4:
			supprimer();
		break;
	}
}

// debut du main
int main() {
	
	menu();
	
return 0;
}
// fin du main