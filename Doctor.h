#ifndef DOCTOR_H
#define DOCTOR_H

#include "PersonalHospital.h"
#include <iostream>
#include <string>
using namespace std;

//Clase Doctor que hereda de PersonalHospital

class Doctor: public PersonalHospital {
    private: 
        string especialidad;
        double precioConsulta;
    
    public:
    //Constructor vacío
        Doctor() : PersonalHospital() {
            especialidad = "";
            precioConsulta = 0.0;
        }
    //Constructor con parámetros
        Doctor(string nom, int ed, string ced, string esp, double precio) : PersonalHospital(nom, ed, ced) {
            especialidad = esp;
            precioConsulta = precio;
        }
    //Getters y Setters
    string getEspecialidad() {
        return especialidad;
    }
    double getPrecioConsulta() {
        return precioConsulta;
    }

    void setEspecialidad(string esp) {
        especialidad = esp;
    }
    void setPrecioConsulta(double precio) {
        precioConsulta = precio;
    }
    //Cambia la respuesta del método de la clase base 
    string getTipo(){
        return "Doctor";
    }
    //Se escribe la versión propia del método virtual puro de la clase base para mostrar la información del doctor
    void mostrarInfo() {
        cout << "Doctor: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Precio de Consulta: $" << precioConsulta << endl;
    }
};
#endif
