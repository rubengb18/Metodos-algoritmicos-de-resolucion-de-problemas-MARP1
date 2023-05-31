// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Digrafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*
  
*/


void dfs(Digrafo& g, int& inicio,  vector<bool>& visited, vector<bool>& apilado, deque<int>& orden,bool &imposible) {
	visited[inicio] = true;
	apilado[inicio] = true;
	int i = 0;
	while (i < g.ady(inicio).size() && !imposible) {
		auto elem = g.ady(inicio).at(i);
		if (!visited[elem]) {
			dfs(g, elem, visited,apilado, orden,imposible);
		}
		else {
			if (apilado[elem]) {
				imposible = true;
			}
		}
		
		i++;
	}
	apilado[inicio] = false;
	orden.push_front(inicio);
}


bool resuelveCaso() {
	int N, C,a,b;
	cin >> N >> C;
	if (!cin) {
		return false;
	}
	Digrafo g(N+1);
	for (int i = 0; i < C; ++i) {
		cin >> a >> b;
		g.ponArista(a,b);
	}
	bool imposible = false;
	deque<int>orden;
	vector<bool>visited(N + 1, false);
	vector<bool>apilado(N + 1, false);
	int i = N;
	while (i >0 && !imposible) {
		if (!visited[i]) {
			dfs(g, i, visited, apilado, orden, imposible);
		}
		i--;
	}
	if(imposible)
		cout << "Imposible";
	else {
		for (auto elem : orden) {
			cout << elem << " ";
		}
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