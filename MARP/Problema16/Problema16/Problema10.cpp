// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "Grafo.h"
#include <queue>
#include <algorithm>
using namespace std;
/*
  
*/

 int bfs(int& origen,int& final){
	if (origen == final) return 0;
	queue<int> q;
	vector<int>distancia(10000, -1);
	distancia[origen] = 0;
	q.push(origen);
	while (!q.empty()){
		int aux = q.front();
		q.pop();
		for (int i = 0;i < 3;i++) {
			int ady;
			if (i == 0) {
				ady = (aux + 1) % 10000;
			}
			else if (i == 1) {
				ady = (aux *2) % 10000;
			}
			else if (i == 2) {
				ady = (aux /3) % 10000;
			}
			if (distancia[ady] == -1) {
				distancia[ady] = distancia[aux] + 1;
				if (ady == final) {
					return distancia[ady];
				}
				else {
					q.push(ady);
				}
			}
		}
	}
}





bool resuelveCaso() {
	int origen,final;
	cin >> origen >> final;
	if (!cin) {
		return false;
	}
	cout << bfs(origen, final) << '\n';
	
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