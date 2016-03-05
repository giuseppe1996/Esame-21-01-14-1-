#include "Intestazione1.h"

void leggi_mat(const stringa nome_file, int & riemp, matrice M) {
	ifstream input;
	input.open(nome_file); // apro il file
	//verifico una corretta apertura del file
	if (input.fail()) {
		cout << "Errore nell'apertura del file! ";
		input.close(); // è sempre buono chiudere il file se si verifica un errore!
		exit(5); //esco dalla funzione
	}
	/*poichè so che il primo elemento del file mi indica il riempimento, allora leggo quello e poi con un for
	posso leggere il resto della matrice.*/
	input >> riemp;
	for (int i = 0;i < riemp;i++) {
		for (int j = 0;j < riemp;j++) { //essendo la matrice quadrata utilizzo lo stesso riempimento per b e h
			input >> M[i][j];
		}
	}
}

//controllo che la matrice sia efettivamente formata da numeri positivi, se il tipo è int sarà per forza formata da interi.
bool controllo_mat(int riemp, const matrice M) {
	for (int i = 0;i < riemp;i++) {
		for (int j = 0;j < riemp;j++) {
			if (M[i][j] < 0) {
				cout << "La matrice deve essere formata necessariamente da interi positivi! " << endl;
				return false;
			}
		}
	}
}

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