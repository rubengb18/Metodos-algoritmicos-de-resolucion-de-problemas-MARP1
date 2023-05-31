// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>
using namespace std;
/*
  
*/

bool estaConectadoPorCiclos(Grafo g,int s, int V, vector<bool> &visited) {
	vector<int> parent(V,-1);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {

		int u = q.front();

		for (int v : g.ady(u)) {
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				parent[v] = u;
			}
			else if (parent[u] != v)
				return true;
		}
		q.pop();
	}
	return false;
}


bool resuelveCaso() {
	int V;
	bool conectado;
	cin >> V;
	if (!cin) {
		return false;
	}
	Grafo g= Grafo(V);
	int E, v, w;
	cin >> E;
	while (E--) {
		cin >> v >> w;
		g.ponArista(v, w);
	}
	vector<bool>visited(V);
	if (!estaConectadoPorCiclos(g,0, V, visited)) {
		conectado = true;
		for (int i = 0; i < V && conectado; i++)
			conectado = visited[i];
		if (conectado) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	}
	else {
		cout << "NO\n";
	}
	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}