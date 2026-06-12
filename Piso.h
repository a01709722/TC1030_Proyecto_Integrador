/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/* 
* Clase Piso 
* Clase que representa un piso de un hospital. Tiene un número de piso y una 
* lista(vector) de cuartos.
*/

#ifndef PISO_H
#define PISO_H

#include "Cuarto.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Clase Piso que tiene un número de piso y una lista de cuartos.
class Piso{
    // Declaro las variables de instancia privadas
    private:
        int numeroPiso;
        vector<Cuarto> cuartos; // Lista de cuartos en el piso
    
    // Declaro los métodos públicos del objeto 
    public: 
        //Constructor vacío 
        Piso() {
            numeroPiso = 0;
        }
        //Constructor con parámetros
        Piso(int numPiso, int numCuartos);

        //Getter
        int getNumeroPiso() {
            return numeroPiso;
        }

        //Devuelve la lista de cuartos para que el hospital pueda revisarlos y modificarlos 
        vector <Cuarto>& getCuartos() {
            return cuartos;
        }
};

/**
 * Constructor con parámetros de Piso
 * 
 * Asigna el número de piso y crea los cuartos indicados, numerándolos desde 1
 * 
 * @param numPiso número del piso 
 * @param numCuartos cantidad de cuartos que tendrá el piso 
 * @return 
 */
Piso::Piso(int numPiso, int numCuartos){
    numeroPiso = numPiso;
    //Crear los cuartos para el piso
    for(int i = 1; i <= numCuartos; i++){
        cuartos.push_back(Cuarto(i)); //Agregar un nuevo cuarto con su número
    }
}
#endif