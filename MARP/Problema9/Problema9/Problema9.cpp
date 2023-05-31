// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*

*/

struct instrumento {
	long long int partituras=1,num,prom;
};

void prom(instrumento& a) {
	if (a.num % a.partituras == 0) {
		a.prom= a.num / a.partituras;
	}
	else {
		a.prom= a.num / a.partituras+1;
	}
}

bool operator<(instrumento const& a, instrumento const& b) {
	if (a.prom > b.prom) {
		return true;
	}
	return false;
}

void resolver(PriorityQueue<instrumento>& cola,long long int& part_sobran) {
	while (part_sobran > 0) {
		instrumento mayor = cola.top();
		cola.pop();
		mayor.partituras++;
		prom(mayor);
		cola.push(mayor);
		part_sobran--;
	}
}



bool resuelveCaso() {
	long long int p,n,part_sobran;
	bool conectado;
	cin >> p >> n;
	if (!cin) {
		return false;
	}
	PriorityQueue<instrumento>cola;
	for (int i = 0;i < n;i++) {
		instrumento aux;
		cin >> aux.num;
		prom(aux);
		cola.push(aux);
	}
	part_sobran = p - n;
	resolver(cola, part_sobran);

	
	cout << cola.top().prom << '\n';
	
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