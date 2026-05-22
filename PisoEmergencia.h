#ifndef PISOEMERGENCIA_H
#define PISOEMERGENCIA_H

#include <iostream>
#include <string>
#include "Piso.h"
using namespace std;

class PisoEmergencia : public Piso {
private:
    string nivelAlerta;

public:
    PisoEmergencia() : Piso() {
        nivelAlerta = "";
    }

    PisoEmergencia(int num) : Piso(num) {
        nivelAlerta = "Normal";
    }

    void ingresarPaciente(Paciente p) {
        cout << "Ingresando paciente a Emergencia" << endl;
        Piso::ingresarPaciente(p);
    }

    void liberarPaciente(int c) {
        cout << "Liberando paciente de Emergencia" << endl;
        Piso::liberarPaciente(c);
    }

    void atenderUrgencia(Paciente p) {
        cout << "Atendiendo urgencia de: " << p.get_nombre() << endl;
    }

    void cambiarAlerta(string n) {
        nivelAlerta = n;
    }

    void mostrarInfo() {
        cout << "Piso de Emergencia" << endl;
        cout << "Numero: " << numero << endl;
        cout << "Nivel de alerta: " << nivelAlerta << endl;
    }

    void mostrarInfo(bool detalle) {
        mostrarInfo();

        if (detalle == true) {
            cout << "Informacion detallada del piso de emergencia" << endl;
        }
    }

    string get_nivelAlerta() {
        return nivelAlerta;
    }
};

#endif