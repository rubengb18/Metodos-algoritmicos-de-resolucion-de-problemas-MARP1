// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/

int resolver(vector<int>& v,int E) {
	int N = v.size();
	int cont = 1;
	int lim = E;
	for (int i = 0;i < N-1;i++) {
		if (v[i + 1] - v[i] >lim) {
			cont++;
			lim = E;
		}
		else {
			lim -= v[i + 1]- v[i];
		}
	}
	return cont;
}


bool resuelveCaso() {
	int N, E,a;
	vector<int>v;
	cin >> N>>E;

	if (!cin) {
		return false;
	}
	for (int i = 0;i < N;i++) {
		cin >> a;
		v.push_back(a);
	}
	int cont=resolver(v,E);
	cout <<cont<< '\n';
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