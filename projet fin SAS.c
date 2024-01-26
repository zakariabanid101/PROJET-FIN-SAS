#include <stdio.h>
#include <stdlib.h>
// fonction d'affichage "menu"
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
	
// structure des taches.
typedef struct{
	char name[20];
	char details[50];
	int date;
	int priorite;
	
}Taches;
Taches t[100];
// déf de fonction d'ajouter une tache.

void Addtache(){
	
	int i;
	for(i=0 ; i < 100 ; i++);
	printf("veuillez entrer le nom du Tache : \n");
	scanf(" %[^\n]s", &t[i].name);
	printf("veuillez ajouter une dsicription : \n");
	scanf(" %[^\n]s", &t[i].details);
	printf("veuilez entrer la date d'echeance : \n");
	scanf("%d", &t[i].date);
	printf("ajouter la priorite : \n");
	scanf("%d", &t[i].priorite);
	
	menu();
	
}


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
	}

}



// debut du main
int main() { 
	
	menu();
	
	return 0;
}
// fin du main