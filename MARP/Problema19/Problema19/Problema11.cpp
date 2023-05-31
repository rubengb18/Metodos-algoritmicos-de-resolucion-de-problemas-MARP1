// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Digrafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/

struct tElem {
	int orig=0, dest =0 ;
};

void bfs(Digrafo const& g,int s,vector<int>&dist, vector<int> &ant, vector<bool> &visit) {
	queue < int>q;
	dist[s] = 0;
	visit[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dist[w] = dist[v] + 1;
				visit[w] = true;
				q.push(w);
			}
		}
	}
}

bool resuelveCaso() {
	int N, K,S,E,a,b;
	int cont = 0;
	cin >> N >> K >> S >> E;
	if (N==0 && K==0 && S==0 && E==0) {
		return false;
	}
	Digrafo g(N*N+1);
	
	vector<tElem>aux(N * N + 1);
	for (int i = 0;i < S;i++) {
		cin >> a >> b;
		aux[a].orig = a;
		aux[a].dest = b;
	}
	for (int i = 0;i < E;i++) {
		cin >> a >> b;
		aux[a].orig = a;
		aux[a].dest = b;
	}
	for (int i = 1;i <N * N;i++) {
		int dado=1;
		while (dado <= K && dado+i<=N*N) {
			if (aux[i+dado].orig!=0) {
				g.ponArista(i, aux[i + dado].dest);
			}
			else {
				g.ponArista(i, i + dado);
			}
			dado++;
		}
	}

	
	vector<bool>visit(N * N + 1, false);
	vector<int>ant(N * N + 1, 0);
	vector<int>dist(N * N + 1, 0);
	bfs(g, 1, dist, ant, visit);
		
	cout << dist[100]<<'\n';
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