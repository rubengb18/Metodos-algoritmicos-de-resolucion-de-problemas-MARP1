// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>
using namespace std;
/*
  
*/

struct intervalo {
	long long int ini, fin,periodo=0;
	bool periodica = false;
};

bool operator<(intervalo const& a, intervalo const& b) {
	return (a.ini < b.ini||a.ini==b.ini && a.fin<b.fin);
}

bool resolver(PriorityQueue<intervalo>&cola,int t) {
	long long int aux = -1;
	intervalo primer_intervalo;
	while (!cola.empty()) {
		primer_intervalo = cola.top();
		cola.pop();
		if (primer_intervalo.ini >= aux) {
			aux = primer_intervalo.fin;
		}
		else {
			return true;
		}
		
		if (primer_intervalo.periodica) {
			primer_intervalo.ini += primer_intervalo.periodo;
			primer_intervalo.fin += primer_intervalo.periodo;
			if (primer_intervalo.ini < t) {
				cola.push(primer_intervalo);
			}
		}
	}
	return false;
}



bool resuelveCaso() {
	long long int n,m,t,periodo;
	bool conectado;
	cin >> n>>m>>t;
	if (!cin) {
		return false;
	}
	PriorityQueue<intervalo>cola;
	intervalo aux;
	for (int i = 0;i < n;i++) {
		cin >> aux.ini >> aux.fin;
		if (aux.ini < t)
			cola.push(aux);
	}
	for (int i = 0;i < m;i++) {
		intervalo aux;
		cin >> aux.ini >> aux.fin>>aux.periodo;
		aux.periodica = true;
		if(aux.ini<t)
			cola.push(aux);
	}
	bool res = resolver(cola,t);

	if (res) {
		cout << "SI" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
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