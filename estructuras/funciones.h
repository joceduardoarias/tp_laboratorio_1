#define TAM 3



typedef struct eFecha
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct eEmpleado // declaro una estructura y ademas creo un nuevo tipo de dato añadiendo typedef

{
    char nombre[TAM];
    int legajo;
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
} eEmpleado;

void mostrarEmpleado(eEmpleado); // declaro funcion con una estructura adentro

eEmpleado cargarEstrutura();// cargar datos en la estructura
