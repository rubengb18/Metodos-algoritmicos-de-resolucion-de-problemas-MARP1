// Grupo DG, Ruben Gomez Blanco
/*

*/
#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*

*/

struct caja {
	int tiempo;
	int ind;
};

bool operator<(caja const& a, caja const& b) {
	if (a.tiempo == b.tiempo) {
		return a.ind < b.ind;
	}
	else {
		return a.tiempo < b.tiempo;
	}
}


int resolver(PriorityQueue<caja>& cola, int &C,int N) {
	for (int i = 0;i < N;i++) {
		int tarda;
		cin>>tarda;
		auto aux = cola.top();
		cola.pop();
		aux.tiempo += tarda;
		cola.push(aux);
	}
	return cola.top().ind;
}

bool resuelveCaso() {
	int N, C, res,c;
	PriorityQueue<caja>cola;
	cin >> C>>N;
	if (N == 0 && C==0) {
		return false;
	}
	for (int i = 0;i < C;i++) {
		cola.push({0, i+1});
	}
	res = resolver(cola,C, N);
	cout << res << '\n';
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