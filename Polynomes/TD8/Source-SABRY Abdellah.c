#include <stdlib.h>
#include <stdio.h>
#include "Polynome-Abdellah.h"

/*int main()
{
	printf("Test du fonctionnement des fonctions \n"); 
	printf("Inserer les valeurs avec affichage\n"); 
	polynome P1 = NULL; 
	P1 = InsereMonome(P1, 12, 0);
	P1 = InsereMonome(P1, 12, 2);
	P1 = InsereMonome(P1, 12, 5);
	P1 = InsereMonome(P1, 12, 3);
	P1 = InsereMonome(P1, 12, 3);
	P1 = InsereMonome(P1, 1, 1);
	P1 = InsereMonome(P1, 12, 5);
	P1 = InsereMonome(P1, 1, 5);
	P1 = InsereMonome(P1, 1, 1);
	P1 = InsereMonome(P1, 10, 1);
	P1 = InsereMonome(P1, 1, 5);
	P1 = InsereMonome(P1, 10, 1);
	AffichagePolynome(P1); 
	printf("\n");
	printf("\n");

	// teste tous les cas possible pour ajouter un monome
	
	printf("Un autre polynome \n");
	polynome PPtest = NULL;
	PPtest = InsereMonome(PPtest, 0, 2); 
	PPtest = InsereMonome(PPtest, 2, 0);
	AffichagePolynome(PPtest); 
	printf("\n"); 
	printf("\n");
	// Autre genre de polynome

	printf("Un autre polynome \n");
	polynome PPtestbis = NULL; 
	PPtestbis = InsereMonome(PPtestbis, 0, 2);
	PPtestbis = InsereMonome(PPtestbis, 2, 0);
	PPtestbis = InsereMonome(PPtestbis, 1, 5);
	PPtestbis = InsereMonome(PPtestbis, 2, 5);
	PPtestbis = InsereMonome(PPtestbis, 1, 7);
	PPtestbis = InsereMonome(PPtestbis, 0, 8);
	PPtestbis = InsereMonome(PPtestbis, 10, 1);
	AffichagePolynome(PPtestbis);
	printf("\n");
	printf("\n");



	printf("Saisir les valeurs avec affichage \n");
	polynome P2 = NULL; 
	P2=SaisiePolynome(); 
	AffichagePolynome(P2);
	printf("\n");
	printf("\n");
	// test des saisie d'un polynome


	printf("Copier un polynome avec affichage \n");
	polynome P3 = NULL;
	P3 = CopiePolynome(P1); 
	AffichagePolynome(P3); 
	printf("\n");
	printf("\n");

	// degré du polynome
	printf("le degre du polynome P1 == %d \n", DegrePolynome(P1)); 
	printf("le degre du polynome P2 == %d \n", DegrePolynome(P2));
	printf("le degre du polynome P3 == %d \n", DegrePolynome(P3));
	printf("\n");
	printf("\n");

	//Dérivé du polynome 
	polynome PDerivee = NULL; 
	PDerivee = DerivePolynome(P2); 
	printf("Derivee\n");
	AffichagePolynome(PDerivee); 
	printf("\n");
	printf("\n");

	//Addition de deux polynomes
	polynome PAddition = NULL;
	PAddition = AdditionPolynome(P1, P2); 
	printf("Addition \n");
	AffichagePolynome(PAddition); 
	printf("\n");
	printf("\n");

	//Mulitplier par un monome 
	monome M; 
	M.coef = 2.0; 
	M.degre = 1; 
	M.suivant = NULL; 
	
	polynome P4 = NULL; 
	P4 = MultiplicationMonome(P3, M); 
	printf("Multiplication \n"); 
	AffichagePolynome(P4); 
	printf("\n");
	printf("\n");

	 //Multiplication de deux polynomes
	polynome PMulti = NULL;
	polynome PP = NULL; 
	polynome PPbis = NULL; 
	PP = InsereMonome(PP, 1, 1); 
	PP = InsereMonome(PP, 1, 2);
	PPbis = InsereMonome(PPbis, 1, 1); 
	PPbis = InsereMonome(PPbis, 1, 2);
	PPbis = InsereMonome(PPbis, 1, 3); 
	printf("Polynome 1 : \n"); 
	AffichagePolynome(PP);
	printf("Polynome 2 : \n");
	AffichagePolynome(PPbis); 
	PMulti = MultiplicationPolynomes(PP, PPbis);
	printf("Polynome 1 * Polynome 2 : \n");
	AffichagePolynome(PMulti); 
	printf("\n");
	printf("\n");
	////Destruction des polynomes
	
	DetruitPolynome(&P1);
	DetruitPolynome(&P2);
	DetruitPolynome(&P3);
	DetruitPolynome(&PDerivee); 
	DetruitPolynome(&PAddition); 
	DetruitPolynome(&P4); 
	DetruitPolynome(&PP); 
	DetruitPolynome(&PPbis); 
	DetruitPolynome(&PMulti); 
	DetruitPolynome(&PPtest);
	DetruitPolynome(&PPtestbis);
	
	getchar(); 
	getchar(); 

}
*/

	int main()
	{
		//Creation d'un polynome nul 
		//Par convention
		polynome p;
		p = NULL;

		//Insertion (ordre correct)
		p = InsereMonome(p, 2, 1);
		p = InsereMonome(p, 5, 10);
		p = InsereMonome(p, -10, 12);

		//Affichage du polynome
		printf("p=");
		AffichagePolynome(p);

		//Creation d'un polynome (ordre incorrect)
		polynome pBis;
		pBis = NULL;

		pBis = InsereMonome(pBis, -4, 5);
		pBis = InsereMonome(pBis, 2, 2);
		pBis = InsereMonome(pBis, 3, 4);
		//Affichage du polynome
		printf("pBis=");
		AffichagePolynome(pBis);

		//Copie d'un polynome
		polynome p2 = CopiePolynome(p);
		printf("p2 = ");
		AffichagePolynome(p2);

		//Destruction d'un polynome
		DetruitPolynome(&p);
		printf("p = ");
		AffichagePolynome(p);

		//Degré d'un polynome
		printf("Degre de p2 -> %d\n", DegrePolynome(p2));

		//Par convention degré d'un polynome nul = -1
		printf("Degre de p -> %d\n", DegrePolynome(p));

		//Derivee d'un polynome
		polynome p3 = DerivePolynome(p2);
		printf("p2' = p3 = ");
		AffichagePolynome(p3);

		printf("p3' = ");
		AffichagePolynome(DerivePolynome(p3));

		//Addidion de 2 polynomes
		polynome p4 = AdditionPolynome(p2, p3);
		printf("p4 = p2 + p3 = ");
		AffichagePolynome(p4);

		polynome p4Bis = AdditionPolynome(p3, p2);
		printf("p4bis = p3 + p2 = ");
		AffichagePolynome(p4Bis);

		printf("p2 + p =");
		AffichagePolynome(AdditionPolynome(p2, p));

		//Multiplication d'un polynome par un monome
		monome m;
		m.coef = 2;
		m.degre = 2;
		m.suivant = NULL;

		polynome p5 = MultiplicationMonome(p4, m);
		printf("p5 = p4 * 2x^2 = ");
		AffichagePolynome(p5);

		//Multiplication de 2 polynomes
		polynome p6 = MultiplicationPolynomes(p5, p4);
		printf("p6 = p5 * p4 = ");
		AffichagePolynome(p6);

		polynome p6Bis = MultiplicationPolynomes(p4, p5);
		printf("p6Bis = p4 * p5 = ");
		AffichagePolynome(p6Bis);

		printf("p4 * p = ");
		AffichagePolynome(MultiplicationPolynomes(p4, p));

		printf("fin du programme");
		getchar();

		return 0;
	}

	
