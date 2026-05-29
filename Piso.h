#ifndef PISO_H
#define PISO_H

#include "Cuarto.h"
#include <vector>
#include <iostream>
using namespace std;

class Piso {
    private: 
        int numeroPiso;
        vector <Cuarto> cuartos;

    public: 
        Piso(){
            this->numeroPiso = 0;
        }

        Piso(int numeroPiso, int numCuartos){
            this->numeroPiso = numeroPiso;
            for (int i = 1; i <= numCuartos; i++) {
                cuartos.push_back(Cuarto(i));
            }
        }

        int getNumeroPiso() {
            return numeroPiso;
        }

        void setNumeroPiso(int numeroPiso) {
            this->numeroPiso = numeroPiso;
        }

        int getTotalCuartos() {
            return cuartos.size();
        }

        int getCuartosOcupados() {
            int count = 0;
            for (int i=0; i<cuartos.size(); i++) {
                if (cuartos[i].isOcupado()) {
                    count++;
                }
            }
            return count;
        }

        Cuarto* buscarCuartoDisponible() {
            for (int i=0; i<cuartos.size(); i++) {
                if (!cuartos[i].isOcupado()) {
                    return &cuartos[i];
                }
            }
            return nullptr;
        }

        bool liberarCuarto(int idPaciente) {
            for (int i =0; i<cuartos.size(); i++) {
                if (cuartos[i].isOcupado()){
                    if (cuartos[i].getPaciente()->getIdPaciente() == idPaciente) {
                        cuartos[i].liberarCuarto();
                        return true;
                    }
                }
            }
            return false;
        }

        void mostrarCuartos() {
            cout << "\nPiso " << numeroPiso << ": " << getCuartosOcupados() << "/" << getTotalCuartos() << " cuartos ocupados." << (getTotalCuartos() - getCuartosOcupados()) << " cuartos disponibles." << endl;
        }

        void mostrarPacientes() {
            bool hayPacientes = false;
            for (int i=0; i<cuartos.size(); i++) {
                if (cuartos[i].isOcupado()) {
                    if (!hayPacientes) {
                        cout << "Pacientes en Piso " << numeroPiso << ":" << endl;
                        hayPacientes = true;
                    }
                    cout << "\nCuarto " << cuartos[i].getNumeroCuarto() << ": \n"; cuartos[i].getPaciente()->mostrarInfo();
                }
            }
        }
};
#endif