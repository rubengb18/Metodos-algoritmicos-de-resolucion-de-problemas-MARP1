// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "DigrafoValorado.h"
#include <queue>
#include<vector>
#include "IndexPQ.h"
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/


bool hayCamino(int v, vector<int>dist) {
	return dist[v] != 99999;
}


void relajar(AristaDirigida<int>& a, vector<int>& dist,  IndexPQ<int>& pq) {
	long long int v = a.desde(), w = a.hasta();
	if (dist[w] > dist[v] + a.valor()) {
		dist[w] = dist[v] + a.valor();
		pq.update(w, dist[w]);
	}
}

	void Dijkstra(DigrafoValorado<int> const& g,int orig, vector<int>&dist, IndexPQ<int>&pq) {
		dist[orig] = 0;
		pq.push(orig, 0);
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			for (auto a : g.ady(v)) {
				relajar(a, dist, pq);
			}
			
		}
	}




bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) {
		return false;
	}
	DigrafoValorado<int> g1(n), g2(n);
	int c;
	cin >> c;
	int ini, fin, val;
	for (int j = 0; j < c; ++j) {
		cin >> ini >> fin >> val;
		g1.ponArista(AristaDirigida<int>(ini - 1, fin - 1, val)); //uno para ir y otro para volver
		g2.ponArista(AristaDirigida<int>(fin - 1, ini - 1, val));
	}
	int o, p, cont = 0;
	cin >> o >> p;
	vector<int> dist(n, 99999);
	IndexPQ <int> pq(n);
	vector<int> dist_vuelta(n, 99999);
	IndexPQ <int> pq_vuelta(n);

	Dijkstra(g1, o - 1, dist, pq);
	Dijkstra(g2, o - 1, dist_vuelta, pq_vuelta);
	
	bool imposible = false;
	for (int i = 0; i < p; ++i) {
		cin >> ini;
		if (!imposible) {
			if (!hayCamino(ini-1,dist) || !hayCamino(ini - 1, dist_vuelta)) {
				imposible = true;
			}
			else {
				cont += dist[ini - 1] + dist_vuelta[ini - 1];
			}
		}
	}
	if (imposible) {
		cout << "Imposible" << endl;
	}
	else {
		cout << cont << endl;
	}
	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()){
	}
		

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}