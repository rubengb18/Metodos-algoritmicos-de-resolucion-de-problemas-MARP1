// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "DigrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <queue>
#include "IndexPQ.h"
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/


bool hayCamino(int v, vector<int>dist) {
	return dist[v] != 99999;
}


void relajar(AristaDirigida<int>& a, vector<int>& dist, vector<AristaDirigida<int>>& ulti, IndexPQ<int>& pq, vector<int>& cargas) {
	int v = a.desde(), w = a.hasta();
	if (dist[w] > dist[v] + a.valor() + cargas[v]) {
		dist[w] = dist[v] + a.valor() + cargas[v];
		ulti[w] = a;
		pq.update(w, dist[w]);
	}
}

	void Dijkstra(DigrafoValorado<int> const& g, int orig, vector<int>&dist, vector<AristaDirigida<int>> &ulti, IndexPQ<int>&pq,vector<int>&cargas) {
		dist[orig] = 0;
		pq.push(orig, 0);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (auto a : g.ady(v)) {
				relajar(a,dist,ulti,pq,cargas);
			}
		}
	}




bool resuelveCaso() {
	int N, E,a,b,valor,K;
	cin >> N;

	if (N==0) {
		return false;
	}
	DigrafoValorado<int> g(N+1);
	vector<int>cargas(N + 1);
	vector<int>dist(N+1, 99999);
	IndexPQ<int>pq(N+1);
	vector<AristaDirigida<int>> ulti(N+1);
	cargas[0] = 0;
	for (int i = 1; i < N+1; ++i) {
		cin >> a;
		cargas[i]=(a);
	}
	cin >> E;
	for (int i = 0; i < E; ++i) {
		cin >> a >> b>>valor;
		g.ponArista({ a,b,valor });
	}
	int orig = 1;
	Dijkstra(g, orig, dist, ulti, pq, cargas);
	int coste = 0;
	
	
	if (hayCamino(N,dist)) {
		cout << dist[N]+cargas[N];
	}
	else {
		cout << "IMPOSIBLE";
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