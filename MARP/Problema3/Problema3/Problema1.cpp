// Grupo DG, Ruben Gomez Blanco
/*

*/
#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*

*/



long long int resolver(PriorityQueue<long long int>&cola, long long int N) {
	long long int esfuerzo = 0;
	if (N > 1) {
		while (!cola.empty()) {
			long long int suma = 0;
			suma += cola.top();
			cola.pop();
			suma += cola.top();
			cola.pop();
			esfuerzo += suma;
			if (!cola.empty()) {
				cola.push(suma);
			}
		}
	}
	return esfuerzo;
}

bool resuelveCaso() {
	long long int N,c,res;
	PriorityQueue<long long int>cola;
	cin >> N;
	if (N == 0) {
		return false;
	}
	for (int i = 0;i < N;i++) {
		cin >> c;
		cola.push(c);
	}
	res = resolver(cola,N);
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