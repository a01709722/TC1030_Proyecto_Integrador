#ifndef PISOOBSERVACION_H
#define PISOOBSERVACION_H

#include <iostream>
#include <string>
#include "Piso.h"
using namespace std;

class PisoObservacion : public Piso {
private:
    int horasObservacion;

public:
    PisoObservacion() : Piso() {
        horasObservacion = 0;
    }

    PisoObservacion(int num) : Piso(num) {
        horasObservacion = 24;
    }

    void ingresarPaciente(Paciente p) {
        cout << "Ingresando paciente a Observacion" << endl;
        Piso::ingresarPaciente(p);
    }

    void liberarPaciente(int c) {
        cout << "Liberando paciente de Observacion" << endl;
        Piso::liberarPaciente(c);
    }

    bool verificarAlta(Paciente p) {
        if (p.get_estatus() == "estable") {
            return true;
        } else {
            return false;
        }
    }

    void mostrarInfo() {
        cout << "Piso de Observacion" << endl;
        cout << "Numero: " << numero << endl;
        cout << "Horas de observacion: " << horasObservacion << endl;
    }

    void mostrarInfo(bool detalle) {
        mostrarInfo();

        if (detalle == true) {
            cout << "Informacion detallada del piso de observacion" << endl;
        }
    }

    int get_horasObservacion() {
        return horasObservacion;
    }

    void set_horasObservacion(int h) {
        horasObservacion = h;
    }
};

#endif