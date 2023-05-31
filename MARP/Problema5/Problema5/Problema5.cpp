// Grupo DG, Ruben Gomez Blanco

#include <fstream>
#include "PriorityQueue.h"
#include <queue>
#include <algorithm>
using namespace std;
/*
Definimos el comparador < para que al principio de la cola estn los usuarios con mayor gravedad. Ademas, si tienen la misma, lo pondra despues segun la antiguedad, que sera el numero de instrucciones
en el que estemos del bucle. Es decir, el mas antiguo es el del numero antiguedad mas bajo.
Por tanto, leemos la instruccion, si es I añadimos a la cola; si es A, escribimos el nombre del primero y lo eliminamos de la lista 
*/


struct usuario {
	string nombre;
	int gravedad;
	int antiguedad;
};

struct comp {
	bool operator()(usuario const& a, usuario const& b) {
		return a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.antiguedad<b.antiguedad);
	}
};




bool resuelveCaso() {
	int N,gravedad;
	string nombre;
	char instruccion;
	PriorityQueue<usuario, comp>cola;
	cin >> N;
	if (N == 0) {
		return false;
	}
	for (int i = 0;i < N;i++) { // O(N log N) ya que tanto push como pop tienen coste logaritmico
		cin >> instruccion;
		if (instruccion == 'I') {
			cin>> nombre >> gravedad;
			cola.push({ nombre,gravedad,i });
		}
		else {
			cout << cola.top().nombre << '\n';
			cola.pop();
		}
	}
	cout << "---\n";
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