#include < stdlib.h>
#include < stdbool.h>
#include < stdio.h>
#include "Polynome-Abdellah.h"

polynome InsereMonome(polynome P, double coef, int degre)
{
	monome *aRetourner = NULL;
	monome *temp = NULL;
	monome *nouveau = malloc(sizeof(monome));

	nouveau->coef = coef;
	nouveau->degre = degre;

	 
	if (P == NULL)//Le polynome est nul
	{
		aRetourner = nouveau;
		aRetourner->suivant = NULL;
	}

	else //le polynome n'est pas nul, on parcourt la liste
	{
		temp = P;
		bool j = false; // pour g�rer le cas ou degr� existe d�ja dans le polynome
		
		{
			if (temp->degre >= degre) // g�rer le cas ou on doit ins�rer "nouveau" au d�but du polynome,  ajouter X au polynome (X^2 + 3X^3) par exemple
			{
				if (temp->degre == degre)// Cas ou le degr� existe d�ja au d�but du polynome , ajouter X^2 au polynome (X^2 + 3X^3) par exemple
				{
					temp->coef += coef;
					j = true; // j=true pour g�rer le fait d'�tre rentr� dans ce if (que le degr� existait d�j�)
					aRetourner = temp; // on retourne le temp dont on a modifi� son coeff
					free(nouveau); // on lib�re l'espace utilis� par nouveau car nous l'avions jamais utilis� (si on est dans ce cas pr�cis)
				}
				else // cas ou je veux ajouter X au polynome (X^2 + 3X^3) par exemple
				{
					nouveau->suivant = temp;
					aRetourner = nouveau;
				}
			}
			else // le Nouveau n'est pas a inserer au debut du polynome
			{
				while (temp->suivant != NULL &&  degre >= temp->suivant->degre) //tant qu'on est pas a la fin de la liste et que le degr� de l'element a ajouter > degr� du temp
				{
					if (temp->suivant->degre == degre)// Cas ou le degr� existe d�ja
					{
						temp->suivant->coef += coef;
						j = true; // j=true pour g�rer le fait d'�tre rentr� dans ce if (que le degr� existait d�j�)
					}
					temp = temp->suivant; // incr�mentation
				}
				nouveau->suivant = temp->suivant; // le monome cr�e va toujours point� sur l'(ancien) suivant de temp
				if (j == false) temp->suivant = nouveau; // si le degr� n'existait pas avant, au cas contraire on n'a pas besoin de cette ligne de code.
				aRetourner = P;
			}
		}

	}


	
	return aRetourner;
}
polynome SaisiePolynome()
{
	double coeff = 1.0; 
	int degre = 1;
	polynome P = NULL;
	printf("Veuillez saisir les coeff de votre polynome avec leur degre \n");
	printf("Exemple : pour construire le polynome x^2 + x^3, vous devez ins�rer \n");
	printf("Coeff : 1  degre : 2 \n");
	printf("Coeff : 1  degre : 3 \n");
	printf("Pour quittez la saisie, mettez le coeff et le degre a 0 \n\n");
	// on laisse le choix a l'utilisateur pour ajouter le nombre de monomes qui veut 
	// Quand le coeff et le degr� seront �gale � 0 , on va sortir de la boucle 
	while (coeff != 0 || degre != 0)
	{
		printf("Coeff :");
		scanf_s("%lf", &coeff);
		printf("                                 Degre :");
		scanf_s("%d", &degre);
		printf("\n");
		if (coeff != 0 || degre != 0) // on ajoute le monome dans le polynome cr�e si le coeff et le degr� sont diff de 0, 0
		{
			P = InsereMonome(P, coeff, degre);
		}

	}
	return P; // retourner le polynome qu'on a cr�e 
}
void AffichagePolynome(polynome P) // a modifier %.0lf
{
	if (P == NULL)
	{
		// si le polynome est nul, on n'affiche rien du tout 
		printf("0  \n");
	}
	else
	{
		// sinon 
		monome *temp = P;
		while (temp->suivant != NULL)
		{
			if(temp->suivant->coef >0) // si le coeff du suivant >0 , j'affiche le plus, sinon je n'ai pas beosin d'afficher le X
			{
				if (temp->coef == 1) // Le cas ou le coeff est �gale � 1, on ne l'affiche pas 
				{
					if (temp->degre == 1) // le cas ou le degr� est �gale � 1, on n'affiche pas la puissance
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("X ");//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("X + ");
					}
					if (temp->degre == 0) // le cas ou le degr� est �gale � 0, on n'affiche pas le X mais juste la constante qui est �gale � 1 ici
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("1 "); //si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("1 + ");
					}
					else
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("X^(%d) ", temp->degre);//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("X^(%d) + ", temp->degre); // sinon on affiche la valeur normal
					}
				}
				else if (temp->coef != 0 && temp->coef != 1)
				{   // si le coef est diff de 1 et de 0 (j'aurais besoin d'afficher le coeff normalement
					if (temp->degre == 1)
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lfX  ", temp->coef);//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lfX + ", temp->coef); // si le degr� est �gale � 1, on n'affiche pas la puissance
					}
					else if (temp->degre == 0)
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lf ", temp->coef); //si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lf + ", temp->coef); // si le degr� est �gale � 0, on n'affiche pas le X
					}
					else
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lfX^(%d) ", temp->coef, temp->degre); // si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lfX^(%d) + ", temp->coef, temp->degre); // sinon on affiche tout normalement
					}
				}
			}
			else
			{
				if (temp->coef == 1) // Le cas ou le coeff est �gale � 1, on ne l'affiche pas 
				{
					if (temp->degre == 1) // le cas ou le degr� est �gale � 1, on n'affiche pas la puissance
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("X ");//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("X ");
					}
					if (temp->degre == 0) // le cas ou le degr� est �gale � 0, on n'affiche pas le X mais juste la constante qui est �gale � 1 ici
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("1 "); //si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("1 ");
					}
					else
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("X^(%d) ", temp->degre);//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("X^(%d) ", temp->degre); // sinon on affiche la valeur normal
					}
				}
				else if (temp->coef != 0 && temp->coef != 1)
				{   // si le coef est diff de 1 et de 0
					if (temp->degre == 1)
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lfX  ", temp->coef);//si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lfX ", temp->coef); // si le degr� est �gale � 1, on n'affiche pas la puissance
					}
					else if (temp->degre == 0)
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lf ", temp->coef); //si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lf ", temp->coef); // si le degr� est �gale � 0, on n'affiche pas le X
					}
					else
					{
						if (temp->suivant->coef == 0 && temp->suivant->suivant == NULL) printf("%lfX^(%d) ", temp->coef, temp->degre); // si l'element suivant n'a pas de coeff ET que l'element suivant soit le dernier du polynome, on n'affiche pas le +
						else printf("%0.lfX^(%d) ", temp->coef, temp->degre); // sinon on affiche tout normalement
					}
				}
			}
			temp = temp->suivant; // incr�menter
		}


		// ger�r le dernier element, exactement comme dans le while sauf qu'il n'y a plus de + apr�s l'affichage
		if (temp->coef == 1) // g�rer le coeff = 1  
		{
			if (temp->degre == 1)
			{
				printf("X \n"); 
			}
			else if (temp->degre == 0)
			{
				printf("1 \n"); 
			}
			else
			{
				printf("%0.lfX^(%d) \n", temp->coef, temp->degre);
			}
		}
		else if(temp->coef !=0) // gerer le coeff != 0, (si il est �gale � 0 on ne l'affiche pas)  
		{
			if (temp->degre == 1) // si degr� == 1 
			{
				printf("%0.lfX \n", temp->coef);
			}
			else if (temp->degre == 0)
			{
				printf("%0.lf \n", temp->coef);
			}
			else
			{
				printf("%0.lfX^(%d) \n", temp->coef, temp->degre);
			}
		}
	}
	printf("\n");
}
void DetruitPolynome(polynome *p_P)
{
	monome *temp = NULL; // temporaire
	temp = *p_P; // temp est la valeur du polynome ( le premier monome)
	monome *Supp = NULL;
	while (temp != NULL)
	{
		Supp = temp; // on garde la valeur de temp
		temp = temp->suivant;// on incr�mente
		free(Supp); // on libere supp (qui est �gale temp au d�but de la fonction) 
		Supp = NULL; // on force pour que Supp = NULL
	}
	*p_P = NULL; // on force que le premier monome soit �gale a NULL
} 
polynome CopiePolynome(polynome P)
{
	polynome P1 = NULL;
	if (P == NULL) // si le polynome est nul , la copie est nul
	{
		P1 = NULL;
	}
	else
	{
		monome *temp = P; // un monome temporaire
		while (temp != NULL)
		{
			P1 = InsereMonome(P1, temp->coef, temp->degre); // on inserer dans P1, le monome du P  avec le m�me coef,et le m�me degr� 
			temp = temp->suivant; // incr�mentation
		}
	}

	return P1; // retourner le polynome copi�
}
int DegrePolynome(polynome P)
{
	int resultat = 0;
	if (P == NULL) // si polynome est null , le degr� = -1
	{
		resultat = -1;
	}
	else
	{
		monome *temp = P; //temporaire
		while (temp != NULL)
		{
			if (temp->degre > resultat) //si le degr� du temporaire > que le degr� de "resultat" gard�
			{
				resultat = temp->degre; // resultat est maintenant �gale au degr� du temp
			}
			temp = temp->suivant; // incr�mentation
		}
	}
	return resultat;// retourner le resultat
}
polynome DerivePolynome(polynome P)
{
	polynome P2 = NULL;
	if (P == NULL) // si le polynome est nul
	{
		P2 = NULL;
	}
	else 
	{
		monome *temp = P; // monome temporaire
		while (temp != NULL)
		{
			if (temp->degre == 0) // le cas ou le degr� = 0
			{
				P2 = InsereMonome(P2, (temp->coef) *(temp->degre), 0); // on insere le monome avec le degr� 0 et pas -1 (coeff sera =0 aussi car le produit (temp->coef) *(temp->degre) =0 ) 
			}
			else
			{
				P2 = InsereMonome(P2, (temp->coef) *(temp->degre), (temp->degre) - 1); // on inserer le monome avec le degr� -1 et le coeff*degr�
			}
			temp = temp->suivant;// incr�mentation
		}
	}

	return P2; // retourner le polynome
}
polynome AdditionPolynome(polynome P1, polynome P2)
{
	polynome P3 = NULL; // polynome a retourner 
	monome *temp1 = P1; // monome temporaire qui parcourt le premier polynome
	monome *temp2 = P2; // monome temporaire qui parcourt le deuxieme polynome
	
	if (temp1 == NULL && temp2 == NULL)  // si les deux sont nulls 
	{
		P3 = NULL; 
	}
	else
	{
		if (temp1 == NULL)  // si P1 est null et P2 ne l'est pas, on �change les monomes qui parcourt les polynomes pour que la boucle fonctionne
		{
			monome *temp3 = NULL;
			temp3 = temp1;
			temp1 = temp2;
			temp2 = temp3;
		}

		bool entrer = false; // g�rer le cas ou le degr� existe dans les deux polyomes 
		while (temp1 != NULL) // parcourt p1 (boucle 2) 
		{
			while (temp2 != NULL) // parcourt p2 (boucle 1)
			{

				if (temp2->degre == temp1->degre) // g�rer le cas ou le degr� existe d�j� 
				{
					P3 = InsereMonome(P3, temp1->coef + temp2->coef, temp1->degre); // on insere dans le polynome a renvoyer si le degr� existe d�j�
					entrer = true; // si le degr� existe d�j�, on change ce boolean pour ne pas l'ajouter en sortant de la premiere boucle
				}
				else
				{
					P3 = InsereMonome(P3, temp2->coef, temp2->degre); // on insere dans le polynome a renvoyer, le monome du 2eme polynome si le degr� n'existait pas
				}
				temp2 = temp2->suivant; // incr�menter dans la premiere boucle 
			}

			// on sort de la premiere boucle 
			if (entrer == false) // si on n'a pas fait la somme, on ajoute le monome du premier polynome
			{
				P3 = InsereMonome(P3, temp1->coef, temp1->degre); // si le degr� n'existait pas, on l'ajoute en sortant, on ajoute pas celui qui a d�ja �t� ajout� 
			}
			entrer = false; // on remet entrer a false
			temp1 = temp1->suivant; // incrementer la boucle 
		}
	}
	return P3; // return p3

}
polynome MultiplicationMonome(polynome P, monome M)
{
	polynome P1 = NULL; // polynome a retourner 
	if (P == NULL) // le cas ou le polynome est null
	{
		P1 = NULL;
	}
	else 
	{
		monome *temp = P; //monome temporaire qui parcourt le polynome P
		while (temp != NULL) 
		{
			P1 = InsereMonome(P1, (temp->coef) * (M.coef), (temp->degre) + (M.degre)); // On ins�re dans le polynome a retourner P1 avec le coef = ancien coef * coef du monome, l'ancien degr� + le degr� du monome
			temp = temp->suivant; // incr�mentation
		}
	}
	return P1; 
}
polynome MultiplicationPolynomes(polynome P1, polynome P2)
{
	polynome P = NULL; // le polynome a retourner 
	polynome tempP = NULL; //polynome temporaire
	monome *temp1 = P1; // monome temporaire
	while (temp1 != NULL)  // on parcours le premier polynome seulement
	{
		tempP = MultiplicationMonome(P2, *temp1); // polynome temporaire = multiplication du premier monome ET polynome 2
		P = AdditionPolynome(P, tempP); // j'additionne le polynome temporaire au polynome a retourner (si le degr� existe d�ja, ce cas est g�rer dans la fonction additionPolynome
		DetruitPolynome(&tempP);// on detruit le polynome temporaire pour le re utilis� dans la prochaine itt�rarion (si c'est la derniere itteration on n'en a plus besoin)  
		temp1 = temp1->suivant; // incr�mentation
	}
	return P;
}
