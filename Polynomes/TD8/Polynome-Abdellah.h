#pragma once


typedef struct monome monome; 
struct monome
{
	double coef;
	int degre;
    monome* suivant;
};

typedef monome* polynome;


polynome InsereMonome(polynome P, double coef, int degre);
// insere le monome "coef?x^degre" ds polynome P

polynome SaisiePolynome();
//Saisi d'un polynome au clavier

void AffichagePolynome(polynome P);
//Affichage du polynome P

void DetruitPolynome(polynome *p_P);
// Destruction d'un polynome

polynome CopiePolynome(polynome P);
// Copie d'un polynome

int DegrePolynome(polynome P);
// Degre du polynome P

polynome DerivePolynome(polynome P);
// Derivee d'un polynome

polynome AdditionPolynome(polynome P1, polynome P2);
// Somme de 2 polynomes

polynome MultiplicationMonome(polynome P, monome M);
// Multiplication d'un polynome par un monome

polynome MultiplicationPolynomes(polynome P1, polynome P2);
//Multiplication des polynomes P1 et P2
