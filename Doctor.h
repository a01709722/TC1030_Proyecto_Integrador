/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/* 
*
* Clase Doctor 
* Clase que hereda de PersonalHospital. Representa a un doctor del hospital 
* con su especialidad y el precio de su consulta.
*/

#ifndef DOCTOR_H
#define DOCTOR_H

#include "PersonalHospital.h"
#include <iostream>
#include <string>
using namespace std;

// Clase Doctor que hereda de PersonalHospital

class Doctor: public PersonalHospital {
    // Declaro las variables de instancia privadas
    private: 
        string especialidad;
        double precioConsulta;
    
    // Declaro los métodos públicos al objeto
    public:
    // Constructor vacío
        Doctor() : PersonalHospital() {
            especialidad = "";
            precioConsulta = 0.0;
        }
    // Constructor con parámetros
        Doctor(string nom, int ed, string ced, string esp, double precio) : PersonalHospital(nom, ed, ced) {
            especialidad = esp;
            precioConsulta = precio;
        }
    // Getters
    string getEspecialidad() {
        return especialidad;
    }
    double getPrecioConsulta() {
        return precioConsulta;
    }
    // Setters
    void setEspecialidad(string esp) {
        especialidad = esp;
    }
    void setPrecioConsulta(double precio) {
        precioConsulta = precio;
    }
    
    // Métodos heredados de la clase base
    string getTipo();
    void mostrarInfo();
};

/** 
 * getTipo regresa el tipo de personal como texto 
 * 
 * Sobreescribe el método de la clase base para devolver "Doctor"
 * 
 * @param 
 * @return string con el tipo de personal
 */
string Doctor::getTipo(){
    return "Doctor";
}

/** 
 * mostrarInfo muestra en pantalla todos los datos del doctor 
 * 
 * Es la versión propia del método virtual puro de la clase base e imprime 
 * nombre, edad, cédula, especialidad y precio de consulta del doctor.
 * 
 * @param 
 * @return void
 */
void Doctor::mostrarInfo() {
    cout << "Doctor: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Especialidad: " << especialidad << endl;
    cout << "Precio de Consulta: $" << precioConsulta << endl;
}

#endif
