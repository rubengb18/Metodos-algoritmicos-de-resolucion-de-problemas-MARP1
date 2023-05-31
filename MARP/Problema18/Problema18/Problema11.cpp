// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Digrafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/

struct elem {
	int ent=0, sal=0;
};

bool resuelveCaso() {
	int N, C,a,b;
	cin >> N >> C;
	if (!cin) {
		return false;
	}
	Digrafo g(N);
	vector<elem>lista(N);
	for (int i = 0; i < C; ++i) {
		cin >> a >> b;
		g.ponArista(a,b);
		lista[a].sal++;
		lista[b].ent++;
	}
	bool imposible = false;
	bool sal = false;
	for (int i = 0; i < N; ++i) {
		if (lista[i].ent == N - 1 && lista[i].sal == 0) {
			cout << "SI " << i;
			sal = true;
		}
		
	}
	if (!sal) {
		cout << "NO";
	}
	cout << '\n';
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