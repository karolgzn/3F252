#include <iostream>
#include <string>
using namespace std;

class Humano{
    private:
        string nombre;
        int edad;
    public:
        string LeerNombre();
        int LeerEdad();
};

class Alumno : public Humano{
    private:
        int registro;
    public:
    int LeerRegistro();
};

class Empleado : public Humano{
    private:
        long noEmpleado;
    public:
        int LeerNumeroEmpleado();
};

int main(int argc, char const *argv[])
{
    Humano* humano = NULL;
    Alumno* alumno new Alumno)();
    Empleado* empleado = Empleado();

    humano = alumno;
    humano->LeerEdad();

    humano = empleado;
    humano->LeerEdad();

    list<Humano*> listaHumanos;
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    
    for (auto &&humano : listaHumanos)
    {
        cout << humano->LeerNombre() << endl;
    }; 

    return 0;
}

//Completar constructores y definir métodos