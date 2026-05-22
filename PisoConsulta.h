#ifndef PISOCONSULTA_H
#define PISOCONSULTA_H

#include <iostream>
#include <string>
#include "Piso.h"
using namespace std;

class PisoConsulta : public Piso {
private:
    int turno;

public:
    PisoConsulta() : Piso() {
        turno = 0;
    }

    PisoConsulta(int num) : Piso(num) {
        turno = 1;
    }

    void ingresarPaciente(Paciente p) {
        cout << "Ingresando paciente a Consulta" << endl;
        Piso::ingresarPaciente(p);
    }

    void liberarPaciente(int c) {
        cout << "Liberando paciente de Consulta" << endl;
        Piso::liberarPaciente(c);
    }

    void agendarCita(Paciente p) {
        cout << "Cita agendada para: " << p.get_nombre() << endl;
    }

    void siguienteTurno() {
        turno++;
    }

    void mostrarInfo() {
        cout << "Piso de Consulta" << endl;
        cout << "Numero: " << numero << endl;
        cout << "Turno actual: " << turno << endl;
    }

    void mostrarInfo(bool detalle) {
        mostrarInfo();

        if (detalle == true) {
            cout << "Informacion detallada del piso de consulta" << endl;
        }
    }

    int get_turno() {
        return turno;
    }
};

#endif