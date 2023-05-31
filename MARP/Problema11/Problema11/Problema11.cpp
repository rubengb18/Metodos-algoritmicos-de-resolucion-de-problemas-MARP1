// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/


void caminoMasLargo(int& visitados, Grafo& g, int &inicio, vector<bool>& marcados) {
	visitados++;
	marcados[inicio-1] = true;
	for (int elem : g.ady(inicio))
		if (!marcados[elem-1]) caminoMasLargo(visitados, g, elem, marcados);
}


void resuelveCaso() {
	int N, M,a,b;
	cin >> N >> M;
	Grafo g(N+1);
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		g.ponArista(a,b);
	}
	vector <bool> marcados;
	for (int i = 0; i < N + 1; ++i) {
		marcados.push_back(false);
	}
	int max = 0, visitados;
	for (int i = 1; i < N+1; ++i) {
		visitados = 0;
		caminoMasLargo(visitados, g, i, marcados);
		if (visitados > max) max = visitados;
	}
	cout << max << '\n';
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int num;
	cin >> num;
	cin.ignore(1);
	for (int i = 0; i < num; i++)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}