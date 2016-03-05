#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

const int DIM =50;
typedef int vettore[DIM];
typedef vettore matrice [DIM];	

struct tipo_punto_sella{
	bool sella;
	int val;
};

tipo_punto_sella struct_punto_sella;

int calc_ind_min(const vettore V,int riemp)/*essendo la matrice quadrata il riempimento sarà quello */{
	int min, ind_min;
	min = V[0]; //inizializzo il minimo al primo elemento del vettore
	for (int i = 0;i < riemp;i++) {
		if (V[i] < min) {
			min = V[i];
			ind_min = i;
		}

	}

	return ind_min;
}

//questa funzione è come quella precedente solo che calcola il massimo e non il minimo
int calc_ind_max(const vettore V, int riemp) {
	int max, ind_max;
	max = V[0];
	for (int i = 0;i < riemp;i++) {
		if (V[i] > max) {
			max = V[i];
			ind_max = i;
		}
	}
	return ind_max;
}

tipo_punto_sella trova_punto_sella(const matrice M, int riemp,tipo_punto_sella struct_punto_sella) {
	int i, j, sella, z = 0;
		vettore min, max;
	for (i = 0;i < riemp;i++){
		for (j = 0;j < riemp;j++) {
			min[z] = calc_ind_min(M[i], riemp);
			z++;
		}
	
	}
	z = 0;
	for (j = 0;j < riemp;j++){
		for (i = 0;i < riemp;i++){
			max[z] = calc_ind_max(M[j], riemp);
			
		}
	}

	for (z = 0;z < riemp;z++) {
		if (min[z] == max[z]) {
			sella = max[z];
			struct_punto_sella.sella = true;
			struct_punto_sella.val = sella;
		}
		else struct_punto_sella.sella = false;
	}


	
	return struct_punto_sella;
}






/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	matrice M;
	int riemp;
	
	cout << "inserisci il riempimento della matrice ";
	cin >> riemp;
	
	
	for(int i=0;i<riemp;i++){
		for(int j=0;j<riemp;j++){
			cin >> M[i][j];
		}
	}
	
	trova_punto_sella(M,riemp,struct_punto_sella);
	
	cout<<struct_punto_sella.val;
	
}
	


