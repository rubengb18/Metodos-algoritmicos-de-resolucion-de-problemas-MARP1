// Grupo DG, Ruben Gomez Blanco

#include <iostream>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"
#include <algorithm>
#include <math.h>
using namespace std;
/*
  
*/

int resolver(PriorityQueue<int>&q_a, PriorityQueue<int>& q_d) {
	int cont=0;
	
	while (!q_a.empty()) {
		bool sal = false;
		int prim_at = q_a.top();
		q_a.pop();
		int N = q_d.size();
		for (int i = 0;i < N & !sal;i++) {
			int prim_def = q_d.top();
			if (prim_at <= prim_def) {
				cont++;
				sal = true;
			}
			q_d.pop();
			
		}
	}
	return cont;
}


bool resuelveCaso() {
	int N, a;
	vector<int>ataques,defensas;
	PriorityQueue<int>q_a,q_d;
	cin >> N;

	if (!cin) {
		return false;
	}
	for (int i = 0;i < N;i++) {
		cin >> a;
		q_a.push(a);
	}
	for (int i = 0;i < N;i++) {
		cin >> a;
		q_d.push(a);
	}
	int cont=resolver(q_a,q_d);
	cout <<cont<< '\n';
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