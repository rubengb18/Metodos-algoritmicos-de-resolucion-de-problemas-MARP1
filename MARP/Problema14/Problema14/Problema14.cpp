// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>

using namespace std;

void caminoMasLargo(int& visitados, Grafo& g, int& inicio, vector<bool>& marcados) {
	visitados++;
	marcados[inicio - 1] = true;
	for (int elem : g.ady(inicio))
		if (!marcados[elem - 1]) caminoMasLargo(visitados, g, elem, marcados);
}


bool resuelveCaso() {
	int N, M,a,b,num;
	cin >> N >> M;
	
	if (!cin) {
		return false;
	}
	Grafo g(N+1);
	vector<int>res(N + 1, 0);
	for (int i = 0;i <M;i++) {
		cin >> num;
		if (num > 0) {
			cin >> a;
			for (int j = 0;j < num-1;j++) {
				cin >>b;
				g.ponArista(a, b);
				a = b;
			}
		}
	}
	int  visitados;
	
	for (int i = 1; i < N + 1; ++i) {
		if (res[i] == 0) {
			vector<bool>marcados(N + 1, false);
			visitados = 0;
			caminoMasLargo(visitados, g, i, marcados);
			for (int i = 1; i < N + 1; ++i) {
				if (marcados[i-1] == true) {
					res[i] = visitados;
				}
			}
		}
	}
	for (int i = 1; i < N + 1; ++i) {
		cout << res[i]<<" ";
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

	while (resuelveCaso()) {

	}


		// para dejar todo como estaba al principio
#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}