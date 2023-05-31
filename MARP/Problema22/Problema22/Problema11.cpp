// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/

void dfs(GrafoValorado<int> const& g,int v,vector<bool>&marked) {
	marked[v] = true;
	for (auto w : g.ady(v)) {
		if (!marked[w.otro(w.uno())]) {
			dfs(g, w.otro(w.uno()),marked);
		}
	}
}

void kruskal(GrafoValorado<int> const& g, int& coste,vector<Arista<int>>& mst) {
	PriorityQueue<Arista<int>>pq(g.aristas());
	ConjuntosDisjuntos cjtos(g.V());
	while (!pq.empty() && mst.size() < g.V() - 1) {
		auto e = pq.top();
		pq.pop();
		int v = e.uno();
		int w = e.otro(v);
		if (!cjtos.unidos(v, w)) {
			cjtos.unir(v, w);
			mst.push_back(e);
			coste += e.valor();
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
	int coste = 0;
	vector<Arista<int>> mst;
	
	bool esconexo = false;
	
	kruskal(g,coste,mst);
	if (mst.size() < N - 1) {
		esconexo = true;
	}
	if (esconexo) {
		cout << "No hay puentes suficientes";
	}
	else {
		cout << coste;
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