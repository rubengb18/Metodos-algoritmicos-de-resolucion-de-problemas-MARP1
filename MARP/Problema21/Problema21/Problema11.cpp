// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "GrafoValorado.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/

void dfs(GrafoValorado<int> const& g, vector<bool>& visit, int& v, int valor) {
	visit[v] = true;
	for (auto a : g.ady(v)) {
		if (a.valor() >= valor) {
			int w = a.otro(v);
			if(!visit[w])
				dfs(g, visit, w, valor);
		}
	}
}

bool resuelveCaso() {
	int N, E,a,b,valor,K;
	cin >> N >> E;

	if (!cin) {
		return false;
	}
	GrafoValorado<int> g(N+1);
	

	for (int i = 0; i < E; ++i) {
		cin >> a >> b>>valor;
		g.ponArista({ a,b,valor });
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		vector<bool>visit(N + 1, false);
		cin >> a >> b >> valor;
		dfs(g,visit,a,valor);
		if (visit[b]) {
			cout << "SI";
		}
		else {
			cout << "NO";
		}
		cout << '\n';
	}
	
	
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