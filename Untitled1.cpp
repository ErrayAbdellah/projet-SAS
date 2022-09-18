#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

	time_t tt = time(NULL);
	struct tm* dt = localtime(&tt);

typedef struct Date
	{
		int day;
		int mont;
		int year;
	}date;

typedef struct Produit 
	{
		int code ;
		char nom[40] ;
		int quantite ;
		float prix ;
		date dat;
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
		printf("\t*	6  - Alimenter le stock\t\t\t\t*\n");
		printf("\t*	7  - Supprimer les produits\t\t\t*\n");
		printf("\t*	8  - Statistique de vente\t\t\t*\n");
		printf("\t*	0  - Statistique de vente\t\t\t*\n");
		printf("\t*********************************************************\n");	
		printf("\n\n\n\n");	
		//sleep(1);
		
		do
		{	
		printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
		scanf("%d",&choix);
		if(choix<0 && choix>9) Affichage();
		}while(choix<0 && choix>9);
		
		if(choix==0)
		return 0;
		
		if(choix == 3 )//Lister tous les produits par :
			{
				do
				{
					printf("Lister tous les produits par :\n");
					printf("1 - lister tous les produits selon l’ordre alphabétique  croissant du nom.\n");
					printf("2 - lister tous les produits selon l’ordre  décroissant du prix.\n");
					printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
					scanf("%d",&ch);
					switch(ch)
					{
						case 0:
							Affichage();
							break;
						case 1:
							return 31;
							break;
						case 2:
							return 32;
							break;
					}
											
				}while(ch!=1 || ch!=2 || ch!=0);
				
			}
		else if (choix == 5) //Rechercher les produits Par 
			{
				
				do
				{
					printf("Rechercher les produits Par : \n");
					printf("1 - Code.\n");
					printf("2 - Quantité.\n");
					printf("3 - Etat du stock: permet d’afficher les produits dont la quantité est inférieure à 3.\n");
					printf("0 - Accueil\n");
					printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
					scanf("%d",&ch);
					switch(ch)
					{
						case 0:
							Affichage();
							break;
						case 1:
							return 51;
							break;
						case 2:
							return 52;
							break;
						case 3:
							return 53;
							break;
					}
				}while(ch!=1 || ch!=2 || ch!=3 || ch!=0);
			}
			
	
		return choix;
	}
	void AjouterUnProduit()//1  - Ajouter un nouveau produit//son code, son nom, sa quantité, et son prix.
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
	
	int AjouterPlusieursProduits()//2  - Ajouter plusieurs nouveaux produits
	{
		produit p[20];
		int n=0;
		while(n!=1000000)
		{
		printf("Entrez 0 dans le code lorsque vous avez termine\n");
		printf("Entrer le code : ");
		scanf("%d",&p[n].code);
		//if(p[n].code==0) break ;
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
	
	void ListerProduitNom(produit T[])// 3  - Lister pour le nom
	{
		produit tmp;
		
		for(int i=0; i<10; i++)
		    {
		        for(int j=0; j<10; j++)
		        {
		            if(strcmp(T[i].nom, T[j].nom )< 0)
		            {
		                tmp=T[i];
		                T[i]=T[j];
		                T[j]=tmp;
		            }
		        }
		    }
		
		for(int i=0 ;i<=9;i++)
		{
				
			printf("%d   |\t%s    \t|\t Prix = %.2fDH   |  \tprix TTC = %.2fDH  \n",T[i].code,T[i].nom,T[i].prix,T[i].prix+0.15 );
		}
	}
	///***********************************************
	void ListerProduitPrix(produit T[]) //3  - Lister pour le prix 
	{
		produit tmp;
 	
		for(int i=0; i<10; i++)
	    {
	        for(int j=0; j<10; j++)
	        {
	            if(T[i].prix > T[j].prix )
	            {
	                tmp=T[i];
	                T[i]=T[j];
	                T[j]=tmp;
	            }
	        }
	    }
 		
		
		for(int i=0 ;i<=9;i++)
		{
				
			printf("%d   |\t%s    \t|\t Prix = %.2fDH   |  \tprix TTC = %.2fDH  \n",T[i].code,T[i].nom,T[i].prix,T[i].prix+0.15 );
		}
	}
	
	float AcheterProduit(produit T[])//4  - Acheter produit
	{
		cass:
			int code,qnt;
			int index = -1;
			
			printf("Entrez le code que vous souhaitez acheter : ");
			scanf("%d",&code);
			
			for(int i=0;i<10;i++)
			{
				if(T[i].code==code)
				{
					index = i;
					break;
				}
			}
			
			if(index == -1)
			goto cass;
			
			printf("%d   |\t%s    \t|\t Prix = %.2fDH   |  \Qnt  = %d  \n",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
			
			printf("Entrez la quantité que vous souhaitez acheter : ");
			scanf("%d",&qnt);
			
			for(int i=0;i<10;i++)
			{
				if(T[i].code==code)
				{
					T[i].quantite -= qnt;
					index = i;
					break;
				}
			}
				
			printf("%d   |\t%s    \t|\t Prix TTC = %.2fDH   |  \Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
			printf("la date acheter %.2d/%.2d/%.4d ",dt->tm_mday,dt->tm_mon+1,dt->tm_year+1900);
			T[index].dat.day  = dt->tm_mday;
			T[index].dat.mont = dt->tm_mon+1;
			T[index].dat.year = dt->tm_year+1900;
			
			return (T[index].prix+0.15)*qnt;
		
	}

	void RechercherProduits(produit T[] ,int a)//5  - Rechercher les produits 
	{
		int code;
		int index = -1;
		if(a==51)//RACHERCHE AVEC UN CODE 
		{
			printf("Entrez le code rechercher : ");
			scanf("%d",&code);
			for(int i=0;i<=9;i++) 
			{
				if(T[i].code==code)
					{
						index = i;
						break;
					}
			}
			
		printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
		}
		else if (a==52) //RACHERCHE AVEC UNE QUANTITE
		{
			printf("Entrez la quantite rechercher : ");
			scanf("%d",&code);
			for(int i=0;i<=9;i++)
			{
				if(T[i].quantite==code)
					{
						index = i;
						printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
					}
			}
			
		}
		else if (a==53)//Etat du stock: permet d’afficher les produits dont la quantité est inférieure à 3
		{
			
			for(int i=0;i<=9;i++)
			{
				if(T[i].quantite<3)
					{
						index = i;
						printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
					}
			}
		}
	}
	
	void AlimenterStock(produit T[])//	6  - Alimenter le stock
	{
		int code ,index =-1,qnt;
		c1:
		printf("Entrez le code modifie : ");
		scanf("%d",&code);
		for(int i=0;i<=9;i++) 
		{
			if(T[i].code==code)
				{
					index = i;
					break;
				}
		}
		if(index==-1) goto c1;
		else
		{
			printf("\nLe code = %d | Qnt  = %d \t\n",T[index].code,T[index].quantite );
			
			printf("\nEntrer le quantite : ");
			scanf("%d",&T[index].quantite);
			
		
			printf("\nLe code = %d | Qnt  = %d \t\n",T[index].code,T[index].quantite );
			
		}
	}

	void SupprimerProduits(produit T[])//7  - Supprimer les produits
	{
		c2:
		int code , index=-1;
		
		printf("\nEntrez le code de medicament Supprimer : ");
		scanf("%d",&code);
		for(int i=0;i<=9;i++) 
		{
			if(T[i].code==code)
				{
					index = i;
					break;
				}
		}
		if(index==-1) goto c2;
		else
		{
			for(int i = index;i<9;i++)	
			{
				T[i] = T[i+1];
			}		
		}
	}
int main()
	{
			produit T[10];
			int totalPrix; 
		 {		 
		//DATA
			strcpy(T[0].nom,"ABDELLAH");
			strcpy(T[1].nom,"MAHDI");
			strcpy(T[2].nom,"ASMAE");
			strcpy(T[3].nom,"ERRAY");
			strcpy(T[4].nom,"MALAK");
			strcpy(T[5].nom,"YASSIN");
			strcpy(T[6].nom,"CHRIF");
			strcpy(T[7].nom,"AHMAD");
			strcpy(T[8].nom,"AICHA");
			strcpy(T[9].nom,"ABDELLAH");
			
			T[0].code = 1 ;
			T[1].code = 2 ;
			T[2].code = 3 ;
			T[3].code = 4 ;
			T[4].code = 5 ;
			T[5].code = 9 ;
			T[6].code = 7 ;
			T[7].code = 6 ;
			T[8].code = 8 ;
			T[9].code = 10 ;
			
			T[0].quantite = 133 ;
			T[1].quantite = 243 ;
			T[2].quantite = 32 ;
			T[3].quantite = 2 ;
			T[4].quantite = 1 ;
			T[5].quantite = 54 ;
			T[6].quantite = 7 ;
			T[7].quantite = 32 ;
			T[8].quantite = 52 ;
			T[9].quantite = 2 ;
			
			T[0].prix = 19 ;
			T[1].prix = 25 ;
			T[2].prix = 33 ;
			T[3].prix = 45 ;
			T[4].prix = 54 ;
			T[5].prix = 52 ;
			T[6].prix = 70 ;
			T[7].prix = 61 ;
			T[8].prix = 52 ;
			T[9].prix = 21 ;
		
}
		
		int choix ;
		ret:
		choix = Affichage();
		
		switch(choix)
		{
			case 1://1  - Ajouter un nouveau produit
					AjouterUnProduit();			
				break;
			case 2://2  - Ajouter plusieurs nouveaux produits
					AjouterPlusieursProduits();
				break;
			case 3://3  - Lister tous les produits
					ListerProduitNom(T);		
				break;
			case 4://4  - Acheter produit
					AcheterProduit(T);
				break;
			case 5://5  - Rechercher les produits Par
							
				break;
			case 6://	6  - Alimenter le stock
							
				break;
			case 7://7  - Supprimer les produits
							
				break;
			case 8://8  - Statistique de vente
							
				break;

		}
		
		goto ret;
		
		getch();
		return 0;
	}
