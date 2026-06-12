/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/*
* Clase Hospital 
* Clase principal del proyecto. Administra los pisos (con sus cuartos), el personal
* (doctores y enfermeros) y los paciente internados del hospital 
*/

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include "Paciente.h"
#include "PersonalHospital.h"
#include "Piso.h"

// Clase Hospital, clase principal del proyecto 
class Hospital{ 
    // Declaro las variables de instancia privadas 
    private:
        string nombre; 
        vector<Piso> pisos;
        vector<PersonalHospital*> personal;
        int contadorId; //Contador para asignar IDs únicos a los pacientes

    // Declaro los métodos públicos del objeto 
    public:
        // Constructor vacío 
        Hospital(){
            nombre = "";
            contadorId = 1;
        }

        Hospital(string nom, int numPisos, int cuartos);    // constructor con parámetros
        void agregarPersonal(PersonalHospital* p);
        void eliminarPersonal(string cedula);
        void mostrarPersonal();
        void agregarPaciente(Paciente* p);
        void liberarPaciente(int id);
        void buscarPaciente(int id);                       // sobrecarga: busca por ID
        void buscarPaciente(string nombreBuscado);         // sobrecarga: busca por nombre
        void mostrarPacientes();
        void mostrarOcupacion();

        // Getter 
        string getNombre() {
            return nombre;
        }
};

/** 
 * Constructor con parámetros de Hospital
 * 
 * Asigna el nombre, inicia el contador de IDs y crea los pisos del hospital 
 * cada uno con la cantidad de cuartos indicada 
 * 
 * @param nom nombre del hospital 
 * @param numPisos cantidad pisos de pisos del hospital
 * @param cuartos cantidad de cuartos por piso 
 * @return
 */
Hospital::Hospital(string nom, int numPisos, int cuartos) {
    nombre = nom;
    contadorId = 1;
    for (int i = 0; i < numPisos; i++) {
        pisos.push_back(Piso(i, cuartos)); //Crear pisos con número y cantidad de cuartos
    }
}

/**
 * agergarPersonal agrega un miembro del personal al hospital 
 * 
 * El mismo método sirve para doctores y enfermeros porque ambos son tipos de PersonalHospital.
 * 
 * @param p apuntador al personal que se va a agregar 
 * @return void
 */
void Hospital::agregarPersonal(PersonalHospital* p){
    personal.push_back(p);
    cout << "Personal agregado correctamente " << endl;
}

/**
 * eliminarPersonal elimina personal buscándolo por su cédula 
 * 
 * No importa si es doctor o enfermero, porque la cédula se encuentra en la 
 * clase base PersonalHospital
 * 
 * @param cedula cédula del personal que se quiere eliminar 
 * @return void 
 */
void Hospital::eliminarPersonal(string cedula){
    for(int i =0; i<personal.size(); i++){
        if(personal[i] -> getCedula() == cedula){
            delete personal[i];
            personal.erase(personal.begin()+ i);
            cout << "Personal con cedula " << cedula << " eliminado." << endl;
            return; 
        }
    }
    cout << "No se encontro personal con esa cedula." << endl;
}

/**
 * mostrarPersonal muestra el personal agrupado por tipo 
 * 
 * Recorre el personal y usa getTipo() para imprimir primero a los doctores y después a los enfermeros
 * 
 * @param 
 * @return void 
 */
void Hospital::mostrarPersonal(){
    cout << endl << "--- Doctores ---" << endl;
    for(int i = 0; i < personal.size(); i++){
        if (personal[i]-> getTipo() =="Doctor"){
            personal[i]->mostrarInfo();
        }
    }
    cout << endl << "--- Enfermeros ---" << endl;
    for(int i = 0; i < personal.size(); i++){
        if (personal[i]-> getTipo() =="Enfermero"){
            personal[i]-> mostrarInfo();
        }
    }
}

/**
 * agregarPaciente interna a un paciente en el primer cuarto libre
 * 
 * Recorre los pisos y cuartos buscando el primero que esté libre, 
 * mete ahí al paciente y le asigna un ID único.
 * 
 * @param p apuntador al paciente que se requiere internar 
 * @return void
 */
void Hospital::agregarPaciente(Paciente* p) {
    for (int i = 0; i < pisos.size(); i++) {
        vector<Cuarto> &cuartos = pisos[i].getCuartos();   
        for (int j = 0; j < cuartos.size(); j++) {
            if (cuartos[j].EstaOcupado() == false) {       
                p->setIdPaciente(contadorId);              
                contadorId = contadorId + 1;               
                cuartos[j].asignarPaciente(p);            
                cout << "Paciente asignado en piso " << pisos[i].getNumeroPiso();
                cout << ", cuarto " << cuartos[j].getNumeroCuarto();
                cout << " (ID " << p->getIdPaciente() << ")." << endl;
                return;                                   
            }
        }
    }
    // Si recorrio todo y no encontro lugar
    cout << "No hay cuartos disponibles. No se pudo admitir al paciente." << endl;
}

/**
 * liberarPaciente da de alta a un paciente y libera su cuarto 
 * 
 * Busca al paciente con el ID indicado, libera el cuarto y borra al paciente 
 * 
 * @param id ID del paciente que se quiere dar de alta 
 * @return void
 */
void Hospital::liberarPaciente(int id){
    for(int i = 0; i < pisos.size(); i++){
        vector<Cuarto> &cuartos = pisos[i].getCuartos();
        for(int j=0; j<cuartos.size(); j++){
            if (cuartos[j].EstaOcupado() == true && cuartos[j].getPacienteActual()->getIdPaciente() == id){
                Paciente* p = cuartos[j].getPacienteActual();
                cuartos[j].liberarCuarto();
                delete p; 
                cout << "Paciente con ID" << id << " dado de alta. Cuarto liberado" << endl;
                return;
            }
        }
    }
    cout << "No se encontro un paciente con ese ID." << endl;
}

/**
 * buscarPaciente busca a un paciente por su ID y muestra su información 
 * 
 * @param id ID del paciente que se quiere buscar 
 * @return void 
 */
void Hospital::buscarPaciente(int id){
    for(int i=0; i<pisos.size(); i++){
        vector<Cuarto> &cuartos = pisos[i].getCuartos();
        for(int j=0; j < cuartos.size(); j++){
            if (cuartos[j].EstaOcupado() == true && cuartos[j].getPacienteActual()-> getIdPaciente() == id){
                cuartos[j].getPacienteActual()->mostrarInfo();
                return;
            }
        }
    }
    cout << "No se econtro un paciente con ese ID." << endl;
}

/** 
 * buscarPaciente busca a un paciente por su nombre y muestra su información 
 * 
 * Es una sobrecarga del método anterior; recorre todos los cuartos y puede 
 * mostrar a más de un paciente si coinciden en el nombre 
 * 
 * @param nombreBuscado nombre del paciente que se quiere buscar 
 * @return void 
 */
void Hospital::buscarPaciente(string nombreBuscado) {
    bool encontrado = false;
    for (int i = 0; i < pisos.size(); i++) {
        vector<Cuarto> &cuartos = pisos[i].getCuartos();
        for (int j = 0; j < cuartos.size(); j++) {
            if (cuartos[j].EstaOcupado() == true && cuartos[j].getPacienteActual()->getNombre() == nombreBuscado) {
                cuartos[j].getPacienteActual()->mostrarInfo();
                encontrado = true;
            }
        }
    }
    if (encontrado == false) {
        cout << "No se encontro un paciente con ese nombre." << endl;
    }
}

/**
 * mostrarPacientes muestra los pacientes internados 
 * 
 * Recorre los pisos y cuartos e imprime la información de cada paciente, 
 * organizada por piso y cuarto 
 * 
 * @param 
 * @return void
 */
void Hospital::mostrarPacientes(){
    for(int i = 0; i <pisos.size(); i++){
        cout << endl << "Piso " << pisos[i].getNumeroPiso() << ":" << endl;
        vector<Cuarto> &cuartos = pisos[i].getCuartos();
        for(int j =0; j < cuartos.size(); j++){
            if(cuartos[j].EstaOcupado()==true){
                cout << " Cuarto " << cuartos[j].getNumeroCuarto() << " -> ";
                cuartos[j].getPacienteActual()->mostrarInfo(); 
            }
        }
    }
}

/** 
 * mostrarOcupacion cuenta y muestra los cuartos ocupados y libres por piso
 * 
 * @param 
 * @return void 
 */
void Hospital::mostrarOcupacion() {
    for (int i = 0; i < pisos.size(); i++) {
        vector<Cuarto> &cuartos = pisos[i].getCuartos();
        int ocupados = 0;
        for (int j = 0; j < cuartos.size(); j++) {
            if (cuartos[j].EstaOcupado() == true) {
                ocupados = ocupados + 1;
            }
        }
        int libres = cuartos.size() - ocupados;
        cout << "Piso " << pisos[i].getNumeroPiso() << ": " << ocupados << " ocupados, " << libres << " disponibles." << endl;
    }
}
 #endif