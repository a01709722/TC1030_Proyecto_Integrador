#ifndef CUARTO_H
#define CUARTO_H

#include "Paciente.h"
#include <iostream>
using namespace std;

class Cuarto {
    private:
        int numeroCuarto;
        bool ocupado;
        Paciente* paciente;
    
    public:
        Cuarto(){
            numeroCuarto = 0;
            ocupado = false;
            paciente= nullptr;
        }
    
        Cuarto(int numeroCuarto) {
            this->numeroCuarto = numeroCuarto;
            ocupado = false;
            paciente = nullptr;
        }

        int getNumeroCuarto() {
            return numeroCuarto;
        }

        bool isOcupado() {
            return ocupado;
        }

        Paciente* getPaciente() {
            return paciente;
        }

        void setNumeroCuarto(int numeroCuarto) {
            this->numeroCuarto = numeroCuarto;
        }

        void setOcupado(bool ocupado) {
            this->ocupado = ocupado;
        }

        void asignarPaciente(Paciente* p) {
            paciente = p;
            ocupado = true;
        }

        void liberarCuarto() {
            paciente = nullptr;
            ocupado = false;
        }
};
#endif