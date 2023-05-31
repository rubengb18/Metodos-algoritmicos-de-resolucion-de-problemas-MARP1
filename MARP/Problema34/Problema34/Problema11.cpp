// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <stack>
#include "PriorityQueue.h"
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
*/

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n==0) {
		return false;
	}
	int a,b;
	PriorityQueue <int> ini, fin;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		ini.push(a);
		fin.push(b);
	}
	int max = -1;
	int cont = -1; 
	while (!ini.empty()) {
		if (ini.top() >= fin.top()) {
			cont--;
			fin.pop();
		}
		else {
			ini.pop();
			cont++;
		}
		if (cont > max) {
			max = cont;
		}
	}
	cout << max << '\n';		//No se debe contar a si mismo
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()) {
		
	}
		

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}