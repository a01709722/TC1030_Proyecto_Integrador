#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
using namespace std;

class Doctor {
private:
    string nombre;
    string area;
    bool disponible;

public:
    Doctor() {
        nombre = "";
        area = "";
        disponible = true;
    }

    Doctor(string n, string a) {
        nombre = n;
        area = a;
        disponible = true;
    }

    void mostrarInfo() {
        cout << "Doctor: " << nombre << endl;
        cout << "Area: " << area << endl;
        cout << "Disponible: " << disponible << endl;
    }

    bool estaDisponible() {
        return disponible;
    }

    void set_disponible(bool d) {
        disponible = d;
    }

    string get_nombre() {
        return nombre;
    }

    string get_area() {
        return area;
    }
};

#endif