// OcurrenciaCaracteres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int registro[54][2];
double contadorG = 0;

void CrearRegistro() {
	for (int i = 0; i < 54;i++) {
		if (i == 14) {
			registro[i][0] = 165;
			continue;
		}
		if (i < 27) {
			if (i > 14) {
				registro[i][0] = i + 64;
			}
			else {
				registro[i][0] = i + 65;
			}
			continue;
		}


		if (i == 41) {
			registro[i][0] = 164;
			continue;
		}

		if (i > 41) {
			registro[i][0] = i + 69;
		}
		else {
			registro[i][0] = i + 70;
		}
		registro[i][1] = 0;
	}
}

bool Buscar(int ascii, string line) {

	char c = char(ascii);
	for (int j = 0; j < line.length(); j++) {
		if (line[j] == c) {
			return true;
		}
	}

	return false;
}

void Contar(string line) {

	for (int i = 0; i < sizeof(registro)/sizeof(registro[0]); i++) {
		if (Buscar(registro[i][0], line)) {
			char c = char(registro[i][0]);
			int contador = count(line.begin(), line.end(), c);
			registro[i][1] += contador;
		}
	}


}

string Leer(string texto) {
	ifstream archivo;

	archivo.open("texto.txt", ios::in); //abrir en modo lectura
	if (archivo.fail()) {
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	while (!archivo.eof()) {
		getline(archivo, texto);
		Contar(texto);
		contadorG += texto.length();
	}

	return texto;
}

int main()
{
	CrearRegistro();


	string texto;
	texto = Leer(texto);

	cout << "{" << endl;

	for (int i = 0; i < 54; i++) {
		cout << "{";
		double porcentaje = (registro[i][1] / contadorG) * 100;
		cout << char(registro[i][0]) << " ";
		cout << porcentaje << "% ";

		cout << "}" << endl;
	}
}
