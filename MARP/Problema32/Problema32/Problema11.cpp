// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/
struct intervalo {
	int c, f;
};

bool operator<(const intervalo& a, const intervalo& b) {
	return a.c < b.c || (a.c == b.c && a.f < b.f);
}

bool resuelveCaso() {
	int C, F, n;
	cin >> C >> F >> n;
	if (C == 0 && F == 0 && n == 0) {
		return false;
	}
	int a,b;
	bool imposible = false, sal = false;
	stack <intervalo> pila;
	vector <intervalo> v;
	for (int i = 0; i < n; ++i) {
		cin >> a>>b;
		v.push_back({ a,b });
	}
	
	sort(v.begin(), v.end());
	int minimo = 0;
	int fin = C;
	for (int i = 0;i < n & !imposible && !sal;i++) {
		if (v[i].c > fin && !pila.empty()) {
			if (pila.top().c <= fin) {
				minimo++;
				fin = pila.top().f;
				pila.pop();
			}
			else {
				imposible = true;
			}
		}
		if (fin >= F) {
			sal = true;
		}
		if (v[i].c <= fin && !sal) {
			if (pila.empty() || v[i].f >= pila.top().f) {
				pila.push(v[i]);
			}
		}
	}

	if (!pila.empty() && !sal) {
		if (pila.top().c <= fin) {
			fin = pila.top().f;
			pila.pop();
			minimo++;
		}
		else {
			imposible = true;
		}
	}

	if (fin < F) {
		imposible = true;
	}

	if (imposible) {
		cout << "Imposible\n";
	}
	else {
		cout << minimo << '\n';
	}
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