#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Paciente {
private:
    string nombre;
    int edad;
    string estatus;

public:
    Paciente() {
        nombre = "";
        edad = 0;
        estatus = "";
    }

    Paciente(string n, int e, string s) {
        nombre = n;
        edad = e;
        estatus = s;
    }

    void mostrarInfo() {
        cout << "Paciente: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Estatus: " << estatus << endl;
    }

    string get_nombre() {
        return nombre;
    }

    string get_estatus() {
        return estatus;
    }

    void set_estatus(string est) {
        estatus = est;
    }
};

#endif