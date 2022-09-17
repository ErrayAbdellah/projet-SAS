#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



typedef struct Produit 
	{
		int code ;
		char nom[20] ;
		int quantite ;
		int prix ;
	}produit;

	int Affichage()
	{
		int choix ,ch ;
		//affichage le menu
		
		printf("\n\n\n\n");
		printf("\t*********************************************************\n");
		printf("\t*	1  - Ajouter un nouveau produit \t\t*\n");
		printf("\t*	2  - Ajouter plusieurs nouveaux produits \t*\n");
		printf("\t*	3  - Lister tous les produits\t\t\t*\n");//***?????????
		printf("\t*	4  - Acheter produit\t\t\t\t*\n");
		printf("\t*	5  - Rechercher les produits Par\t\t*\n");
		printf("\t*	6  - Etat du stock\t\t\t\t*\n");
		printf("\t*	7  - Alimenter le stock\t\t\t\t*\n");
		printf("\t*	8  - Supprimer les produits\t\t\t*\n");
		printf("\t*	9  - Statistique de vente\t\t\t*\n");
		printf("\t*********************************************************\n");		
		//sleep(1);
		
		do
		{	
		printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
		scanf("%d",&choix);
		
		}while(choix<1 || choix>9);
		
		if(choix == 3 )//Lister tous les produits par :
			{
				do
				{
					printf("Lister tous les produits par :\n");
					printf("1 - lister tous les produits selon l’ordre alphabétique  croissant du nom.\n");
					printf("2 - lister tous les produits selon l’ordre  décroissant du prix.\n");
					printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
					scanf("%d",&ch);
					if(ch==1) return 31;
					else if (ch == 2) return 32;
					
				}while(ch!=1 || ch!=2);
				
			}
		else if (choix == 5) //Rechercher les produits Par 
			{
				
				do
				{
					printf("Rechercher les produits Par : \n");
					printf("1 - Code.\n");
					printf("2 - Quantité.\n");
					printf("0 - Accueil\n");
					printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
					scanf("%d",&ch);
					if(ch==1) return 51;
					else if (ch == 2) return 52;
					else if (ch==0) Affichage();
					
				}while(ch!=1 || ch!=2 || ch!=0);
			}
			
	
		return choix;
	}
	void AjouterUnProduit() //son code, son nom, sa quantité, et son prix.
	{
		int n ;
		produit p1;
		printf("Entrer le code : ");
		scanf("%d",&p1.code);
		
		printf("Entrer le nom : ");
		scanf("%s",p1.nom);
		
		printf("Entrer le quantite : ");
		scanf("%d",&p1.quantite);
		
		printf("Entrer le prix : ");
		scanf("%d",&p1.prix);
		
		printf("%d %s %d %d",p1.code,p1.nom,p1.quantite,p1.prix);
		
	}
	
	int AjouterPlusieursProduits()
	{
		produit p[20];
		int n=0;
		while(n!=1000000)
		{
		printf("Entrez 0 dans le code lorsque vous avez termine\n");
		printf("Entrer le code : ");
		scanf("%d",&p[n].code);
		if(p[n].code==0) break ;
		printf("Entrer le nom : ");
		scanf("%s",p[n].nom);
		
		printf("Entrer le quantite : ");
		scanf("%d",&p[n].quantite);
		
		printf("Entrer le prix : ");
		scanf("%d",&p[n].prix);
		n++;
		printf("****************************\n");
		}
		return n;
		
	}
int main()
	{
//		produit p[20]={	(1,"abdellah",12,55),(2,"rray",33,189)};
//		produit p1 = {1,"abdellah",12,55};
		
		
		//printf("%d",Affichage());
		//AjouterUnProduit();
		
		AjouterPlusieursProduits();
		
		getch();
		return 0;

	}
