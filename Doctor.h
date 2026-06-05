#ifndef DOCTOR_H
#define DOCTOR_H

#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

class Doctor : public Persona {
    private: 
    string especialidad;
    string cedula;
    double PrecioConsulta;

    public:
    Doctor() : Persona() {
        especialidad = "";
        cedula = "";
        PrecioConsulta = 0.0;
    }

    Doctor(string nombre, int edad, string especialidad, string cedula, double PrecioConsulta) : Persona(nombre, edad) {
        this->especialidad = especialidad;
        this->cedula = cedula;
        this->PrecioConsulta = PrecioConsulta;
    }

    string getEspecialidad() {
        return especialidad;
    }

    string getCedula() {
        return cedula;
    }

    double getPrecioConsulta() {
        return PrecioConsulta;
    }

    void setEspecialidad(string especialidad) {
        this->especialidad = especialidad;
    }

    void setCedula(string cedula) {
        this->cedula = cedula;
    }

    void setPrecioConsulta(double PrecioConsulta) {
        this->PrecioConsulta = PrecioConsulta;
    }

    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Precio de Consulta: $" << PrecioConsulta << endl;
    }

};
#endif