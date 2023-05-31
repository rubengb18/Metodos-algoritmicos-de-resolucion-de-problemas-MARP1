// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	int valor;
	vector <int> v1, v2;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		v1.push_back(valor);
	}
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		v2.push_back(valor);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int suma = 0;
	for (int i = 0; i < n; ++i) {
		suma += abs(v2[i] - v1[i]);
	}
	cout << suma << '\n';
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