// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*

*/


void dfs(Grafo& G, int& v, vector<bool>& marked, int& count,bool colorea, vector<bool>& coloreados) {
	marked[v] = true;
	for (int w : G.ady(v))
		if (!marked[w]) {
			if (colorea) {
				coloreados[v] = true;
			}
			dfs(G, w, marked, count, !colorea, coloreados);
		}
}







bool resuelveCaso() {
	int N, M;
	vector<bool>coloreados(N, false);
	cin >> N >> M;
	
	if (!cin) {
		return false;
	}
	
	
	
	
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {	}
		

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}