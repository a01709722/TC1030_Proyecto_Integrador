#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
    protected:
        string nombre;
        int edad;

    public:
        Persona() {
            nombre = "";
            edad = 0;
        }

        Persona(string nombre, int edad) {
            this->nombre = nombre;
            this->edad = edad;
        }
        
        string getNombre() {
            return nombre;
        }

        int getEdad() {
            return edad;
        }

        void setNombre(string nombre) {
            this->nombre = nombre;
        }

        void setEdad(int edad) {
            this->edad = edad;
        }

        virtual void mostrarInfo() = 0;

};

#endif