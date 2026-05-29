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

        Paciente(int idPaciente, string nombre, int edad, string diagnostico, string fechaIngreso) : Persona(nombre, edad) {
            this->idPaciente = idPaciente;
            this->diagnostico = diagnostico;
            this->fechaIngreso = fechaIngreso;
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

        void setIdPaciente(int idPaciente) {
            this->idPaciente = idPaciente;
        }

        void setDiagnostico(string diagnostico) {
            this->diagnostico = diagnostico;
        }

        void setFechaIngreso(string fechaIngreso) {
            this->fechaIngreso = fechaIngreso;
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