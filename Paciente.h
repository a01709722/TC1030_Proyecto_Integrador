#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"
#include <string>
#include <iostream>
using namespace std;

class Paciente : public Persona {
    private:
        string diagnostico;
        string fechaIngreso;
        int idPaciente;

        public:
        Paciente () : Persona() {
            idPaciente = 0;
            diagnostico = "";
            fechaIngreso = "";
        }

        Paciente(int idP, string nombre, int edad, string diag, string fechaIn) : Persona(nombre, edad) {
            idPaciente = idP;
            diagnostico = diag;
            fechaIngreso = fechaIn;
        }

        int getIdPaciente() {
            return idPaciente;
        }

        string getDiagnostico() {
            return diagnostico;
        }

        string getFechaIngreso() {
            return fechaIngreso;
        }

        void setIdPaciente(int idP) {
            idPaciente = idP;
        }

        void setDiagnostico(string diag) {
            diagnostico = diag;
        }

        void setFechaIngreso(string fechaIn) {
            fechaIngreso = fechaIn;
        }

        void mostrarInfo() {
            cout << "ID Paciente: " << idPaciente << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Diagnostico: " << diagnostico << endl;
            cout << "Fecha de Ingreso: " << fechaIngreso << endl;
        }

};
#endif