#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include "PisoEmergencia.h"
#include "PisoObservacion.h"
#include "PisoConsulta.h"
#include "Paciente.h"
#include "Doctor.h"
using namespace std;

class Hospital {
private:
    string nombre;
    PisoEmergencia emergencia;
    PisoObservacion observacion;
    PisoConsulta consulta;

public:
    Hospital() {
        nombre = "";
        emergencia = PisoEmergencia(1);
        observacion = PisoObservacion(2);
        consulta = PisoConsulta(3);
    }

    Hospital(string n) {
        nombre = n;
        emergencia = PisoEmergencia(1);
        observacion = PisoObservacion(2);
        consulta = PisoConsulta(3);
    }

    void ingresarPaciente(Paciente p) {
        if (p.get_estatus() == "emergencia") {
            emergencia.ingresarPaciente(p);
        } else if (p.get_estatus() == "observacion") {
            observacion.ingresarPaciente(p);
        } else if (p.get_estatus() == "consulta") {
            consulta.ingresarPaciente(p);
        } else {
            cout << "Estatus no valido" << endl;
        }
    }

    void asignarDoctor(int piso, Doctor d) {
        if (piso == 1) {
            emergencia.asignarDoctor(d);
        } else if (piso == 2) {
            observacion.asignarDoctor(d);
        } else if (piso == 3) {
            consulta.asignarDoctor(d);
        } else {
            cout << "Piso no valido" << endl;
        }
    }

    void mostrarInfo() {
        cout << "Hospital: " << nombre << endl;
        cout << endl;

        emergencia.mostrarInfo();
        cout << endl;

        observacion.mostrarInfo();
        cout << endl;

        consulta.mostrarInfo();
        cout << endl;
    }
};

#endif