// Grupo DG, Ruben Gomez Blanco
/*

*/
#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*

*/

struct clientes {
	int num;
	int pos;
};

bool operator<(clientes const& a, clientes const& b) {

}



bool resuelveCaso() {
	long long int N,c;
	PriorityQueue<long long int>cola;
	cin >> N;
	if (!cin) {
		return false;
	}
	for (int i = 0;i < N;i++) {
		cin >> c;
		if (c == 0) {
			if (!cola.empty()) {
				auto aux = cola.top();
				cola.pop();
				cout << aux << " ";
			}
			else {
				cout << "ECSE ";
			}
		}
		cola.push(c);
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


	while (resuelveCaso()) {}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}