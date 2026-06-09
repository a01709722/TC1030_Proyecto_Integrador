#ifndef PERSONALHOSPITAL_H
#define PERSONALHOSPITAL_H

#include <iostream>
#include <string>
using namespace std;

// Clase base abstracta para el personal del hospital.
// Tiene un método virtual puro para mostrar la información del personal, por lo que no se 
// pueden crear objetos de esta clase directamente. De ella heredan las clases Doctor y Enfermero.

class PersonalHospital {
    protected: 
        string nombre; 
        int edad; 
        string cedula; 

    public:
    //Constructor vacío
        PersonalHospital() {
            nombre = "";
            edad = 0; 
            cedula = "";
        }
    //Constructor con parámetros
        PersonalHospital(string nom, int ed, string ced) {
            nombre = nom; 
            edad = ed; 
            cedula = ced;
        }
    //Destructor virtual para borrar correctamente a un Doctor o un Enfermero a través de un puntero a PersonalHospital
        virtual ~PersonalHospital() {}
    
    //Getters y Setters
        string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        string getCedula() {
            return cedula;
        }

        void setNombre(string nom) {
            nombre = nom;
        }
        void setEdad(int ed) {
            edad = ed;
        }
        void setCedula(string ced) {
            cedula = ced;
        }

    //Método virtual con respuesta por defecto. Las clases hijas lo cambian para decir "Doctor"
    //o "Enfermero" y sirve para mostrar al personal agrupado por tipo en el menú de mostrar personal
        virtual string getTipo(){
            return "Personal";
        }
    
    //Método virtual puro que obliga a las clases hijas a escribir su propia versión de mostrar información
        virtual void mostrarInfo() = 0;
};
#endif