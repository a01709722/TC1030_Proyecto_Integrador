#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
using namespace std;

//Clase Paciente que guarda la información de cada persona internado en el hospital

class Paciente {
    private:
        string nombre;
        int edad; 
        string diagnostico; 
        string fechaIngreso;
        int idPaciente; 
    
    public: 
        // Constructor vacío
        Paciente(){
            nombre = "";
            edad = 0; 
            diagnostico = "";
            fechaIngreso = "";
            idPaciente = 0;
        }
        //Constructor con parámetros
        Paciente(string nom, int ed, string diag, string fechaIn){
            nombre = nom; 
            edad = ed; 
            diagnostico = diag; 
            fechaIngreso = fechaIn;
            idPaciente = 0; //El ID empieza en 0 porque se le asignará automáticamente cuando lo internen en un cuarto 
        }
        //Getters y Setters
        string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        string getDiagnostico() {
            return diagnostico;
        }
        string getFechaIngreso() {
            return fechaIngreso;
        }
        int getIdPaciente() {
            return idPaciente;
        }

        void setNombre(string nom) {
            nombre = nom;
        }
        void setEdad(int ed) {
            edad = ed;
        }
        void setDiagnostico(string diag) {
            diagnostico = diag;
        }
        void setFechaIngreso(string fechaIn) {
            fechaIngreso = fechaIn;
        }
        void setIdPaciente(int id) {
            idPaciente = id;
        }

        //Muestra en pantalla todos los datos del paciente 
        void mostrarInfo(){
            cout << "ID: " << idPaciente << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Diagnostico: " << diagnostico << endl;
            cout << "Fecha de ingreso: " << fechaIngreso << endl;
        }
};
#endif