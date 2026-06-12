/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/* 
* Clase Cuarto 
* Clase que representa un cuarto de hospital. Puede estar libre o tener
* un solo paciente internado
*/

#ifndef CUARTO_H
#define CUARTO_H

#include "Paciente.h"
#include <iostream>
#include <string>
using namespace std;

//Clase Cuarto que puede estar libre o tener un solo paciente internado.
class Cuarto {
    // Declaro las variables de instancia privadas 
    private: 
        int numeroCuarto;
        bool ocupado;
        Paciente* pacienteActual;
    // Declaro los métodos públicos del objeto 
    public:
        //Constructor vacío
        Cuarto() {
            numeroCuarto = 0;
            ocupado = false;
            pacienteActual = nullptr; //El cuarto empieza sin paciente
        }
        //Constructor con parámetros
        Cuarto(int numCuarto) {
            numeroCuarto = numCuarto;
            ocupado = false;
            pacienteActual = nullptr; //El cuarto empieza sin paciente
        }
        //Getters
        int getNumeroCuarto() {
            return numeroCuarto;
        }
        Paciente* getPacienteActual() {
            return pacienteActual;
        }
        //Dice si el cuarto está ocupado o no
            bool EstaOcupado() {
            return ocupado;
        }
        
        void asignarPaciente(Paciente* p);
        void liberarCuarto();
};

/**
 * asignarPaciente interna a un paciente en el cuarto.
 * 
 * Guarda el paciente recibido y marca el cuarto como ocupado
 * 
 * @param p apuntador al paciente que entra al cuarto 
 * @return void 
 */
void Cuarto::asignarPaciente(Paciente* p){
    pacienteActual = p;
    ocupado = true;
}

/**
 * liberarCuarto deja el cuarto libre
 * 
 * Quita al paciente actual y marca el cuarto como desocupado 
 * 
 * @param 
 * @return void
 */
void Cuarto::liberarCuarto(){
    pacienteActual = nullptr;
    ocupado = false;
}
#endif