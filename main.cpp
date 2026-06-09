#include <iostream>
#include <string>
#include "Hospital.h"
#include "Doctor.h"
#include "Enfermero.h"
#include "Paciente.h"
using namespace std;
 
// Funcion que solo imprime el menu en pantalla.
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
 
int main() {
   // Se crea el hospital con un numero fijo de pisos y cuartos (no cambia despues).
   Hospital hospital("Hospital General", 2, 3);
 
   int opcion;
 
   // El menu se repite hasta que el usuario elija 0 (o una opcion no válida).
   do {
       mostrarMenu();
       cin >> opcion;
 
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
       else if (opcion == 2) {
           hospital.mostrarPacientes();
       }
       else if (opcion == 3) {
           int id;
           cout << "ID del paciente a liberar: ";
           cin >> id;
           hospital.liberarPaciente(id);
       }
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
       else if (opcion == 5) {
           int tipo;
           cout << "Tipo: 1) Doctor  2) Enfermero : ";
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
               // Datos propios del doctor:
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
               string turno, area;
               cout << "Turno: ";
               getline(cin, turno);
               cout << "Area: ";
               getline(cin, area);
               Enfermero* e = new Enfermero(nombre, edad, cedula, turno, area);
               hospital.agregarPersonal(e);  
           }
       }
       else if (opcion == 6) {
           string cedula;
           cout << "Cedula del personal a eliminar: ";
           cin.ignore();
           getline(cin, cedula);
           hospital.eliminarPersonal(cedula);
       }
       else if (opcion == 7) {
           hospital.mostrarPersonal();
       }
       else if (opcion == 8) {
           hospital.mostrarOcupacion();
       }
       else if (opcion == 0) {
           cout << "Saliste del programa" << endl;
       }
       else {
           // Cualquier opcion que no este en el menu termina el programa.
           cout << "Opcion no reconocida. El programa terminara." << endl;
           opcion = 0;
       }
 
   } while (opcion != 0);
 
   return 0;
}