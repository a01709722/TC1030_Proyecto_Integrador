#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include "Paciente.h"
#include "PersonalHospital.h"
#include "Piso.h"

//Hospital es la clase principal del proyecto 

class Hospital{ 
    private:
        string nombre; 
        vector<Piso> pisos;
        vector<PersonalHospital*> personal;
        int contadorId; //Contador para asignar IDs únicos a los pacientes

    public:
        //Constructor vacío 
        Hospital(){
            nombre = "";
            contadorId = 1;
        }
        //Constructor con parámetros
        Hospital(string nom, int numPisos, int cuartos) {
            nombre = nom;
            contadorId = 1;
            for (int i = 0; i < numPisos; i++) {
                pisos.push_back(Piso(i, cuartos)); //Crear pisos con número y cantidad de cuartos
            }
        }
    
    //Agregar personal al hospital
    //El mismo método sirve para doctores y enfermeros porque ambos son tipos de PersonalHospital 
    void agregarPersonal(PersonalHospital* p){
        personal.push_back(p);
        cout << "Personal agregado correctamente: " << endl;
    }

    //Elimina personal buscandolo por su cédula. No importa si es doctor o enfermero, 
    //porque la cédula se encuentra en la clase base PersonalHospital
    void eliminarPersonal(string cedula){
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

    //Mostrar el personal agrupado por tipo (doctores y enfermeros)
    //Usamos getTipo() para saber que es cada uno
    void mostrarPersonal(){
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
    //Agregar paciente recorre los pisos y los cuartos buscando el primero que esté libre,
    //mete ahí al paciente y le da un ID
    void agregarPaciente(Paciente* p) {
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
    //Busca al paciente con ese ID y libera su cuarto
    void liberarPaciente(int id){
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
    //Buscar al paciente con ese ID
    void buscarPaciente(int id){
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
    //Buscar al paciente con ese nombre
    void buscarPaciente(string nombreBuscado) {
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
    //Muestra los pacientes internados, organizados por pisos y cuartos
    void mostrarPacientes(){
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
    // Cuenta y muestra cuantos cuartos hay ocupados y libres en cada piso.
    void mostrarOcupacion() {
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
 
    string getNombre() {
        return nombre;
    }
};
 #endif