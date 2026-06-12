/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/* 
*
* Clase PersonalHospital 
* Clase base abstracta para el personal del hospital. Tiene un método virtual 
* puro(mostrarInfo), por lo que no se pueden crear objetos de esta clase directamente. 
* De ella heredan las clases Doctor y Enfermero
*/

#ifndef PERSONALHOSPITAL_H
#define PERSONALHOSPITAL_H

#include <iostream>
#include <string>
using namespace std;

// Clase base abstracta para el personal del hospital.

class PersonalHospital {
    // Declaro las variables de instancia protegidas (las heredan las clases hijas)
    protected: 
        string nombre; 
        int edad; 
        string cedula; 
    
    // Declaro los métodos públicos del objeto
    public:
    // Constructor vacío
        PersonalHospital() {
            nombre = "";
            edad = 0; 
            cedula = "";
        }
    // Constructor con parámetros
        PersonalHospital(string nom, int ed, string ced) {
            nombre = nom; 
            edad = ed; 
            cedula = ced;
        }
    // Destructor virtual para borrar correctamente a un Doctor o un Enfermero a través de un puntero a PersonalHospital
        virtual ~PersonalHospital() {}
    
    // Getters
        string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        string getCedula() {
            return cedula;
        }
        // Setters
        void setNombre(string nom) {
            nombre = nom;
        }
        void setEdad(int ed) {
            edad = ed;
        }
        void setCedula(string ced) {
            cedula = ced;
        }

    //Método virtual con respuesta por defecto; las clases hijas lo sobreescriben. 
        virtual string getTipo();

    //Método virtual puro que obliga a las clases hijas a escribir su propia versión de mostrar información
        virtual void mostrarInfo() = 0;
};

/**
 * getTipo regresa el tipo de personal como texto. 
 * 
 * Devuelve "Personal" por defecto. Las clases hijas (Doctor, Enfermero) lo sobreescriben para mostrar 
 * al personal agrupado por tipo en el menú. 
 * 
 * @param
 * @return string con el tipo de personal.
 */
string PersonalHospital::getTipo(){
    return "Personal";
}

#endif