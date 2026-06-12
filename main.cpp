/*
* Proyecto Sistema Hospitalario
* Diego Gutiérrez García
* A01709722
* 12/06/2026
*/

/* 

* Programa principal (main)
* Maneja el menú del sistema del hospital. Permite agregar y dar de alta pacientes, 
* agregar y eliminar personal del hospital (doctores y enfermeros), buscar pacientes, 
* y mostrar la ocupación del hospital 
*/

#include <iostream>
#include <string>
#include "Hospital.h"
#include "Doctor.h"
#include "Enfermero.h"
#include "Paciente.h"
using namespace std;
 
/**
 * mostrarMenu imprime en pantalla las opciones del menu 
 * 
 * @param 
 * @return void 
 */
void mostrarMenu() {
   cout << endl;
   cout << "===== MENU HOSPITAL =====" << endl;
   cout << "1. Agregar paciente" << endl;
   cout << "2. Mostrar pacientes" << endl;
   cout << "3. Liberar paciente" << endl;
   cout << "4. Buscar paciente" << endl;
   cout << "5. Agregar personal" << endl;
   cout << "6. Eliminar personal" << endl;
   cout << "7. Mostrar personal" << endl;
   cout << "8. Mostrar ocupacion" << endl;
   cout << "0. Salir" << endl;
   cout << "Elige una opcion: ";
}

/** 
 * main es el punto de entrada del programa 
 * 
 * Crea el hospital y repite el menú hasta que el usuario elija salir, 
 * llamando al método correspondiente según la opción seleccionada 
 * 
 * @param 
 * @return int (0 si el programa termina correctamente)
 */
int main() {
   // Se crea el hospital con un numero fijo de pisos y cuartos (no cambia despues).
   Hospital hospital("Hospital General", 2, 3);
 
   int opcion;
 
   // El menu se repite hasta que el usuario elija 0 (o una opcion no válida).
   do {
       mostrarMenu();
       cin >> opcion;
       cout << endl;
 
       // Agergar paciente 
       if (opcion == 1) {
           string nombre, diagnostico, fecha;
           int edad;
           cout << "Nombre: ";
           cin.ignore();                 
           getline(cin, nombre);        
           cout << "Edad: ";
           cin >> edad;
           cout << "Diagnostico: ";
           cin.ignore();
           getline(cin, diagnostico);
           cout << "Fecha de ingreso: ";
           getline(cin, fecha);
           Paciente* p = new Paciente(nombre, edad, diagnostico, fecha); 
           hospital.agregarPaciente(p); 
       }
       // Mostrar pacientes 
       else if (opcion == 2) {
           hospital.mostrarPacientes();
       }
       // Liberar a un paciente por ID
       else if (opcion == 3) {
           int id;
           cout << "ID del paciente a liberar: ";
           cin >> id;
           hospital.liberarPaciente(id);
       }
       // Buscar paciente por ID o por nombre 
       else if (opcion == 4) {
           int subopcion;
           cout << "Buscar por: 1) ID  2) Nombre : ";
           cin >> subopcion;
           if (subopcion == 1) {
               int id;
               cout << "ID: ";
               cin >> id;
               hospital.buscarPaciente(id);       
           }
           else {
               string nombre;
               cout << "Nombre: ";
               cin.ignore();
               getline(cin, nombre);
               hospital.buscarPaciente(nombre);  
           }
       }
       // Agregar personal (doctor o enfermero)
       else if (opcion == 5) {
           int tipo;
           cout << "Tipo: 1) Doctor 2) Enfermero " << endl;
           cin >> tipo;
           // Datos comunes a ambos
           string nombre, cedula;
           int edad;
           cout << "Nombre: ";
           cin.ignore();
           getline(cin, nombre);
           cout << "Edad: ";
           cin >> edad;
           cout << "Cedula: ";
           cin.ignore();
           getline(cin, cedula);
           if (tipo == 1) {
               // Datos propios del doctor
               string especialidad;
               double precio;
               cout << "Especialidad: ";
               getline(cin, especialidad);
               cout << "Precio de consulta: ";
               cin >> precio;
               Doctor* d = new Doctor(nombre, edad, cedula, especialidad, precio);
               hospital.agregarPersonal(d);  
           }
           else {
                // Datos propios del enfermero
               string turno, area;
               cout << "Turno: ";
               getline(cin, turno);
               cout << "Area: ";
               getline(cin, area);
               Enfermero* e = new Enfermero(nombre, edad, cedula, turno, area);
               hospital.agregarPersonal(e);  
           }
       }
       // Eliminar personal por cédula 
       else if (opcion == 6) {
           string cedula;
           cout << "Cedula del personal a eliminar: ";
           cin.ignore();
           getline(cin, cedula);
           hospital.eliminarPersonal(cedula);
       }
       // Mostrar personal agrupado por tipo
       else if (opcion == 7) {
           hospital.mostrarPersonal();
       }
       // Mostrar ocupación de los cuartos por piso 
       else if (opcion == 8) {
           hospital.mostrarOcupacion();
       }
       // Salir del programa 
       else if (opcion == 0) {
           cout << "Saliste del programa" << endl;
       }
       else {
           // Cualquier opcion que no este en el menu termina el programa.
           cout << "Opcion no reconocida. El programa terminara." << endl;
           opcion = 0;
       }
    
    cout << endl;
 
   } while (opcion != 0);
 
   return 0;
}