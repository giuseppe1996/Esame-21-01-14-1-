#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

//dichiarazioni
const int DIM = 50;
const int dim_str = 25;
typedef int vettore[DIM];
typedef vettore matrice[DIM]; // essendo la matrice quadrata ha un solo riempimento 
typedef char stringa[dim_str];//non ha senso avere un file con nome più lungo di 25 caratteri credo ma si può sempre cambiare ahaha

//definisco la struttura punto sella
struct tipo_punto_sella {
	bool sella;
	int val;
};

tipo_punto_sella struct_punto_sella;


//prototipi funzioni

//legge una matrice da file
void leggi_mat(const stringa nome_file, int & riemp, matrice M);
//controllo interi positivi
bool controllo_mat(int riemp, const matrice M);
//calcolo dove si trova il valore più piccolo della matrice
int calc_ind_min(const vettore V,int riemp);
//aggiungo la funzione che calcola il massimo della colonna
int calc_max_col(const vettore V, int riemp);
/*in questo modo posso sfruttare queste due funzioni per calcolare il punto di sella, se infatti entrambe le funzioni
indirizzano nella stessa posizione allora è il punto di sella */
tipo_punto_sella trova_punto_sella(const matrice M, int riemp);
