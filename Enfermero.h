#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "PersonalHospital.h"
#include <iostream>
#include <string>
using namespace std;

//Clase Enfermero que hereda de PersonalHospital

class Enfermero : public PersonalHospital {
    private: 
        string turno;
        string area; 

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
    //Getters y Setters
        string getTurno() {
            return turno;
        }
        string getArea() {
            return area;
        }

        void setTurno(string tur) {
            turno = tur;
        }
        void setArea(string ar) {
            area = ar;
        }
    //Cambia la respuesta del método de la clase base
        string getTipo(){
            return "Enfermero";
        }
    //Se escribe la versión propia del método virtual puro de la clase base para mostrar la información del enfermero
        void mostrarInfo() {
            cout << "Enfermero: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Cedula: " << cedula << endl;
            cout << "Turno: " << turno << endl;
            cout << "Area: " << area << endl;
        }
};
#endif