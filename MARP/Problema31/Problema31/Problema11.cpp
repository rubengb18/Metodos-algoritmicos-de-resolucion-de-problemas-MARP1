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
struct pasadizo {
	int east, west;
};

bool operator<(const pasadizo& a, const pasadizo& b) {
	return a.east < b.east || (a.east == b.east && a.west < b.west);
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	vector <pasadizo> v;
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int ini = v[0].east, fin = v[0].west;
	int cont = 1,N= v.size();

	for (int i = 1; i < N; ++i) {
		if (v[i].east >= fin) {
			ini = v[i].east;
			fin = v[i].west;
			cont++;
		}
		else {
			ini = v[i].east;
			if (v[i].west <= fin) {
				fin = v[i].west;
			}
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