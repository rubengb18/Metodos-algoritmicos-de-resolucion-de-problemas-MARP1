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

void resuelveCaso() {
	int N, min;
	deque<int> d; // Tambien se podria usar un vector e ir contando por la izquierda y por la derecha, pero de esta forma es menos lioso a la hora de salir del bucle
	int a, cont = 0;
	cin >> N >> min;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		d.push_back(a);
	}
	sort(d.begin(), d.end());
	while (d.size() > 1) {
		if (d.front() + d.back()>=min) {
			d.pop_back();
			cont++;
		}
			d.pop_front();	//Siempre hay que o bien descartar el primero, o usarlo y pasar al siguiente, descartando el ultimo
	}
	cout << cont << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		resuelveCaso();
	}
		

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}