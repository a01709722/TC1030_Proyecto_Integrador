#ifndef PISO_H
#define PISO_H

#include "Cuarto.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Clase Piso que tiene un número de piso y una lista de cuartos.

class Piso{
    private:
        int numeroPiso;
        vector<Cuarto> cuartos; //Lista de cuartos en el piso

    public: 
        //Constructor vacío 
        Piso() {
            numeroPiso = 0;
        }
        //Constructor con parámetros
        Piso(int numPiso, int numCuartos){
            numeroPiso = numPiso;
            //Crear los cuartos para el piso
            for(int i = 1; i <= numCuartos; i++){
                cuartos.push_back(Cuarto(i)); //Agregar un nuevo cuarto con su número
            }
        }
        //Getter
        int getNumeroPiso() {
            return numeroPiso;
        }
        //Devuelve la lista de cuartos para que el hospital pueda revisarlos y modificarlos 
        vector <Cuarto>& getCuartos() {
            return cuartos;
        }
};
#endif