// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>

using namespace std;
/*

*/

struct elem{
	char ch;
	int val;
};

void dfs(Grafo& G, int& v, vector<bool>& marked, vector<int>& id, int& count,int &cuenta_manchas) {
	marked[v] = true;
	cuenta_manchas++;
	id[v] = count;
	for (int w : G.ady(v))
		if (!marked[w])
			dfs(G, w, marked, id, count, cuenta_manchas);
}

void CC(Grafo& G, vector<bool>& marked, vector<int>& id, int& count, int& max) {
	for (int v = 0; v < G.V(); v++){
		if (!marked[v])
		{
			int cuenta_manchas = 0;
			dfs(G, v,marked,id,count, cuenta_manchas);
			count++;
			if (cuenta_manchas > max) {
				max = cuenta_manchas;
			}
		}
	}
}





bool resuelveCaso() {
	int N, M, count = 0, cuenta_manchas = 0;
	char a, b;
	elem a_e, b_e,c;
	cin >> N >> M;
	
	if (!cin) {
		return false;
	}
	cin.ignore(1);
	
	
	vector<vector<elem>>m;
	for (int i = 0;i < N;i++) {
		vector<elem>v;
		for (int j = 0; j < M; j++) {
			cin.get(a);
			if (a == '#') {
				cuenta_manchas++;
			}
			c.ch = a;
			c.val = cuenta_manchas-1;
			v.push_back(c);
		}
		m.push_back(v);
		cin.ignore(1);
	}
	Grafo g(cuenta_manchas);
	vector<bool> marked(g.V()+1);
	vector<int> id(g.V()+1);
	for (int i = 0;i < N;i++) {
		for (int j = 0; j < M; j++) {
			if (i == N - 1 && j == M - 1) {
				
			}
			
			else if ( j == M - 1) {
				if (m[i][j].ch == '#' && m[i + 1][j].ch == '#') {
					g.ponArista(m[i][j].val, m[i + 1][j].val);
				}
			}

			else if(i==N-1) {
				if (m[i][j].ch == '#' && m[i][j + 1].ch == '#') {
					g.ponArista(m[i][j].val, m[i][j + 1].val);
				}
				
			}
			else {
				if (m[i][j].ch == '#' && m[i][j + 1].ch == '#') {
					g.ponArista(m[i][j].val, m[i][j + 1].val);
				}
				if (m[i][j].ch == '#' && m[i + 1][j].ch == '#') {
					g.ponArista(m[i][j].val, m[i + 1][j].val);
				}
			}
		}
	}
	int max = 0;
	CC(g, marked, id, count,max);
	cout << count<<" "<<max<<'\n';
	
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