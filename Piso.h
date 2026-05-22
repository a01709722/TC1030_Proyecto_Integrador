#ifndef PISO_H
#define PISO_H

#include <iostream>
#include <string>
#include "Paciente.h"
#include "Doctor.h"
using namespace std;

class Piso {
protected:
    int numero;
    int cuartos[5];
    Doctor doctor;
    bool doctorAsignado;

public:
    Piso() {
        numero = 0;
        doctorAsignado = false;

        for (int i = 0; i < 5; i++) {
            cuartos[i] = 0;
        }
    }

    Piso(int num) {
        numero = num;
        doctorAsignado = false;

        for (int i = 0; i < 5; i++) {
            cuartos[i] = 0;
        }
    }

    int obtenerCuartoLibre() {
        for (int i = 0; i < 5; i++) {
            if (cuartos[i] == 0) {
                return i;
            }
        }

        return -1;
    }

    void asignarDoctor(Doctor d) {
        doctor = d;
        doctorAsignado = true;
    }

    bool tieneDoctorAsignado() {
        return doctorAsignado;
    }

    void mostrarInfo() {
        cout << "Piso numero: " << numero << endl;
    }

    void mostrarInfo(bool detalle) {
        cout << "Piso numero: " << numero << endl;

        if (detalle == true) {
            cout << "Cuartos: " << endl;

            for (int i = 0; i < 5; i++) {
                cout << "Cuarto " << i << ": " << cuartos[i] << endl;
            }

            if (doctorAsignado == true) {
                doctor.mostrarInfo();
            }
        }
    }

    void ingresarPaciente(Paciente p) {
        int cuartoLibre = obtenerCuartoLibre();

        if (cuartoLibre != -1) {
            cuartos[cuartoLibre] = 1;
            cout << "Paciente ingresado en cuarto " << cuartoLibre << endl;
        } else {
            cout << "No hay cuartos libres" << endl;
        }
    }

    void liberarPaciente(int cuarto) {
        if (cuarto >= 0 && cuarto < 5) {
            cuartos[cuarto] = 0;
            cout << "Cuarto liberado" << endl;
        }
    }

    int get_numero() {
        return numero;
    }
};

#endif