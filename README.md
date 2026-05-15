# TC1030_Proyecto_Integrador
Este es un sistema desarrollado en C++ que modela la operación básica de un hospital. Organiza pacientes, doctores, cuartos y pisos aplicando los principios básicos de programación orientada a objetos. 
# Funcionalidad
El hospital cuenta con tres pisos especializados(emergencia, observación y consulta), cada uno con 5 cuartos numerados automáticamente. Al ingresar un paciente, el sistema lo asigna al piso correspondiente según su estatus médico y busca el primer cuarto disponible. Los doctores se asignan al piso que coincide con su área. 
# Arquitectura
La arquitectura usa herencia: Piso de Emergencia, Piso de Observación y Piso de Consulta heredan de la clase base Piso, cada una con comportamiento propio. Las relaciones entre las clases combinan composición (Hospital-Piso, Piso-Cuarto) y agregación (Cuarto-Paciente, Piso-Doctor). 
