// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "PriorityQueue.h"
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/
struct peli {
	int inicio, fin;
};

bool operator<(const peli& a, const peli& b) {
	return a.inicio < b.inicio || (a.inicio == b.inicio && a.fin < b.fin);
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	int h, m;
	char aux;
	vector <peli> v;
	int duracion;
	for (int i = 0; i < n; ++i) {
		cin >> h >> aux >> m >> duracion;
		int mins = h * 60 + m;
		v.push_back({ mins, mins + duracion });
	}
	sort(v.begin(), v.end());

	int inicio = v[0].inicio, fin = v[0].fin;
	int cont = 1,N= v.size();

	for (int i = 1; i < N; ++i) {
		if (v[i].inicio < fin) {
			if (v[i].fin < fin) fin = v[i].fin;
		}
		else if (v[i].inicio >= fin + 10) {
			cont++;
			fin = v[i].fin;
		}
	}
	cout << cont << '\n';

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()){}
		

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}