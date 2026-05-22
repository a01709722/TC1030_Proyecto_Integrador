#include <iostream>
#include "Paciente.h"
#include "Doctor.h"
#include "Hospital.h"
using namespace std;

int main() {

    Hospital hospital("Hospital General");

    Paciente paciente1("Pedro Luis", 20, "emergencia");

    Doctor doctor1("Dr. Vito", "Emergencias");

    hospital.asignarDoctor(1, doctor1);

    hospital.ingresarPaciente(paciente1);

    cout << endl;

    hospital.mostrarInfo();

    return 0;
}