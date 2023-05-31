// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/


void alcance( Grafo const& g, int& s, int& TTL, vector<bool>& visit, int& visitados, vector <int>& dist) {
	queue<int>q;
	visit[s] = true;
	dist[s] = 0;
	int dist_actual = dist[s];
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int w : g.ady(v)) {
			if (!visit[w] && dist[v] < TTL) {
				visit[w] = true;
				visitados++;
				dist[w] = dist[v] + 1;
				dist_actual = dist[w];
				q.push(w);
			}
		}
	}
}


bool resuelveCaso() {
	int N, C,a,b,K,TTL,nodo;
	cin >> N >> C;
	if (!cin) {
		return false;
	}
	Grafo g(N+1);
	for (int i = 0; i < C; ++i) {
		cin >> a >> b;
		g.ponArista(a,b);
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> nodo >> TTL;
		vector <int> dist(N+1);
		vector<bool>visit(N + 1, false);
		int visitados=1;
		alcance(g, nodo,TTL,visit,visitados,dist);
		cout << N - visitados << '\n';
	}
	cout << "---\n";
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