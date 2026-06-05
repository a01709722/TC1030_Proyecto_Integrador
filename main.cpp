#include <iostream>
#include <string>
#include "Hospital.h"
using namespace std;

int main() {
    cout << "\nBienvenido al sistema de gestion hospitalaria" << endl;
    Hospital hospital("Central QRO", 2, 3);

    int contadorPacientes = 0;
    int opcion;

    do {
        cout << "\n----------------------------------" << endl;
        cout << "Hospital: " << hospital.getNombre() << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Agregar paciente" << endl;
        cout << "2. Liberar paciente" << endl;
        cout << "3. Ver pacientes internados" << endl;
        cout << "4. Agregar doctor" << endl;
        cout << "5. Eliminar doctor" << endl;
        cout << "6. Ver todos los doctores" << endl;
        cout << "7. Buscar doctores por especialidad" << endl;
        cout << "8. Ver cuartos disponibles" << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        if (opcion == 1) {
            string nombre, diagnostico, fechaIngreso;
            int edad;
            cout << "\nAgregar paciente" << endl;
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Diagnostico: ";
            getline(cin, diagnostico);
            cout << "Fecha de ingreso (dd/mm/yyyy): ";
            getline(cin, fechaIngreso);
            contadorPacientes ++;
            Paciente* p = new Paciente(contadorPacientes, nombre, edad, diagnostico, fechaIngreso);
            hospital.agregarPaciente(p);
        }

        else if (opcion == 2){
            int id;
            cout << "\nLiberar paciente" << endl;
            hospital.mostrarPacientes();
            cout << "\nIngrese el ID del paciente a liberar: ";
            cin >> id;
            cin.ignore();
            hospital.liberarPaciente(id);
        }

        else if (opcion == 3){
            hospital.mostrarPacientes();
        }

        else if (opcion == 4) {
            string nombre, cedula, especialidad;
            int edad;
            double precio;
            cout << "\nAgregar doctor" << endl;
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Especialidad: ";
            getline(cin, especialidad);
            cout << "Cedula: ";
            getline(cin, cedula);
            cout << "Precio por consulta: ";
            cin >> precio;
            cin.ignore();
            Doctor* d = new Doctor(nombre, edad, especialidad, cedula, precio);
            hospital.agregarDoctor(d);
        }
        
        else if (opcion == 5) {
            string cedula; 
            cout << "\nEliminar doctor" << endl;
            cout << "Ingrese la cedula del doctor a eliminar: ";
            getline(cin, cedula);
            hospital.eliminarDoctor(cedula);
        }

        else if (opcion == 6) {
            hospital.mostrarDoctores();
        }

        else if (opcion == 7) {
            string especialidad;
            cout << "\nIngrese la especialidad a buscar: ";
            getline(cin, especialidad);
            hospital.mostrarDoctores(especialidad);
        }
        
        else if (opcion == 8) {
            hospital.mostrarOcupacion();
        }
       
        else if (opcion < 0 || opcion > 8) {
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    }
    while (opcion != 0);
    cout << "\nGracias por usar el sistema de gestion hospitalaria." << endl;
    return 0;
}

