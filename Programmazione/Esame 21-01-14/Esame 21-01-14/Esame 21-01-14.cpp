// Esame 21-01-14.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "Intestazione1.h"


int main()
{
	//dichiaro le variabili all'interno del main perchè in genere non è buona cosa usare variabil globali
	stringa nome_file;
	int riemp;
	matrice M;


	cout << "Inserisci il nome del file : ";
	cin >> nome_file;

	leggi_mat(nome_file, riemp, M);
	controllo_mat(riemp, M);
	trova_punto_sella(M, riemp);

	cout << struct_punto_sella.val;
	

    return 0;
}

//risolvere errori di collegamento non ci sono errori di codice, credo funzioni sono incerto sul punto di sella, ma non riesco a provare xk non riesce a collegare le funzioni...

//domani provo a rifarlo con codeblocs su mac... 