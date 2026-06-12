/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/*
* Clase Enfermero 
* Clase que hereda de PersonalHospital. Representa a un enfermero del hospital 
* con su turno y el área en la que trabaja.
*/

#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "PersonalHospital.h"
#include <iostream>
#include <string>
using namespace std;

//Clase Enfermero que hereda de PersonalHospital

class Enfermero : public PersonalHospital {
    // Declaro las variables de instancia privadas
    private: 
        string turno;
        string area; 
    // Declaro los métodos públicos del objeto
    public:
        //Constructor vacío
        Enfermero() : PersonalHospital() {
            turno = "";
            area = "";
        }
        //Constructor con parámetros
        Enfermero(string nom, int ed, string ced, string tur, string ar) : PersonalHospital(nom, ed, ced) {
            turno = tur;
            area = ar;
        }
        // Getters
        string getTurno() {
            return turno;
        }
        string getArea() {
            return area;
        }
        // Setters 
        void setTurno(string tur) {
            turno = tur;
        }
        void setArea(string ar) {
            area = ar;
        }
    // Métodos heredados de la clase base
        string getTipo();
        void mostrarInfo();
};

/** 
 * getTipo regresa el tipo de personal como texto 
 * 
 * Sobreescribe el método de la clase base para devolver "Enfermero"
 * 
 * @param 
 * @return string con el tipo de personal 
 */
string Enfermero::getTipo(){
    return "Enfermero";
}

/** 
 * mostrarInfo muestra en pantalla todos los datos del enfermero.'
 * 
 * Es la versión propia del método virtual puro de la clase base e imprime 
 * nombre, edad, cédula, turno y área del enfermero
 * 
 * @param 
 * @return void
 */
void Enfermero::mostrarInfo() {
    cout << "Enfermero: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Turno: " << turno << endl;
    cout << "Area: " << area << endl;
}
#endif