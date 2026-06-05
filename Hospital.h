#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Piso.h"
#include "Doctor.h"
#include <vector>
#include <queue>
using namespace std;

class Hospital {
    private:
        string nombre;
        vector<Piso> pisos;
        vector<Doctor*> doctores;
        queue<Paciente*> listaEspera;

    public:
        Hospital() {
            this->nombre = "";
        }

        Hospital(string nombre, int numPisos, int CuartosPorPiso) {
            this->nombre = nombre;
            for (int i = 1; i <= numPisos; i++) {
                pisos.push_back(Piso(i, CuartosPorPiso));
            }
        }
        
        string getNombre() {
            return nombre;
        }

        Cuarto* buscarCuartoDisponible() {
            for (int i=0; i<pisos.size(); i++) {
                Cuarto* cuarto = pisos[i].buscarCuartoDisponible();
                if (cuarto != nullptr) {
                    return cuarto;
                }
            }
            return nullptr;
        }

        void agregarDoctor(Doctor* d) {
            doctores.push_back(d);
            cout << "\nDoctor agregado exitosamente." << endl;
        }

        void eliminarDoctor(string cedula) {
            for (int i=0; i<doctores.size(); i++) {
                if (doctores[i]->getCedula() == cedula) {
                    delete doctores[i];
                    doctores.erase(doctores.begin() + i);
                    cout << "\nDoctor eliminado exitosamente." << endl;
                    return;
                }
            }
            cout << "\nDoctor no encontrado." << endl;
        }

        void mostrarDoctores() {
            if (doctores.empty()) {
                cout << "\nNo hay doctores registrados." << endl;
                return;
            }
            cout << "\nDoctores en el Hospital " << nombre << ":" << endl;
            for (int i=0; i<doctores.size(); i++) {
                doctores[i]->mostrarInfo();
            }
        }

        void mostrarDoctores(string especialidad) {
            bool hayDoctores = false;
            cout << "\nDoctores con especialidad " << especialidad << ":" << endl;
            for (int i=0; i<doctores.size(); i++) {
                if (doctores[i]->getEspecialidad() == especialidad) {
                    cout << "Dr. " << doctores[i]->getNombre() << endl;
                    hayDoctores = true;
                }
            }
            if (!hayDoctores) {
                cout << "\nNo se encontraron doctores con esa especialidad." << endl;
            }
        }

        void agregarPaciente(Paciente* p) {
            Cuarto* cuarto = buscarCuartoDisponible();
            if (cuarto != nullptr) {
                cuarto->asignarPaciente(p);
                cout << "\nPaciente agregado exitosamente al cuarto " << cuarto->getNumeroCuarto() << "." << endl;
            } else {
                listaEspera.push(p);
                cout << "\nNo hay cuartos disponibles. Paciente agregado a la lista de espera." << endl;
            }
        }

        void liberarPaciente(int idPaciente){
            for (int i=0; i<pisos.size(); i++) {
                if (pisos[i].liberarCuarto(idPaciente)) {
                    cout << "\nPaciente liberado exitosamente." << endl;
                    if (!listaEspera.empty()) {
                        Paciente* siguiente = listaEspera.front();
                        listaEspera.pop();
                        Cuarto* cuarto = buscarCuartoDisponible();
                        cuarto-> asignarPaciente(siguiente);
                        cout << "\nPaciente en espera " << siguiente->getNombre() << " asignado al cuarto " << cuarto->getNumeroCuarto() << "." << endl;
                    }
                    return;
                }
            }
            cout << "\nPaciente no encontrado con ese ID." << endl;
        }

        void mostrarPacientes() {
            cout << "\nPacientes en el Hospital " << nombre << ":\n" << endl;
            bool hayPacientes = false;
            for (int i=0; i<pisos.size(); i++) {
                if(pisos[i].getCuartosOcupados() > 0) {
                    pisos[i].mostrarPacientes();
                    hayPacientes = true;
                }
            }
            if (!hayPacientes) {
                cout << "\nNo hay pacientes en el hospital." << endl;
            }
            if (!listaEspera.empty()) {
                cout << "\nPacientes en lista de espera:" << listaEspera.size() << endl;
            }
        }

        void mostrarOcupacion() {
            cout << "\nOcupacion del Hospital " << nombre << ":" << endl;
            int totalCuartos = 0;
            int totalOcupados = 0;
            for (int i=0; i<pisos.size(); i++) {
                pisos[i].mostrarCuartos();
                totalCuartos += pisos[i].getTotalCuartos();
                totalOcupados += pisos[i].getCuartosOcupados();
            }
            cout << "\nTotal: " << totalOcupados << "/" << totalCuartos << " cuartos ocupados. " << endl;
            if (totalOcupados == totalCuartos && !listaEspera.empty()) {
                cout << "\nPacientes en lista de espera:" << listaEspera.size() << endl;
            }
        }
};
#endif