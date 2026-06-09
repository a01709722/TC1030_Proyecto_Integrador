#ifndef CUARTO_H
#define CUARTO_H

#include "Paciente.h"
#include <iostream>
#include <string>
using namespace std;

//Clase Cuarto que puede estar libre o tener un solo paciente internado.

class Cuarto {
    private: 
        int numeroCuarto;
        bool ocupado;
        Paciente* pacienteActual;
    
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
        //El paciente entra a un cuarto y lo marca como ocupado 
        void asignarPaciente(Paciente* p){
            pacienteActual = p;
            ocupado = true;
        }
        //El paciente sale del cuarto y lo marca como libre
        void liberarCuarto(){
            pacienteActual = nullptr;
            ocupado = false;
        }
};
#endif