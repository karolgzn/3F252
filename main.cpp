#include <iostream>
#include <Foco.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
cout<<"Hola Mundo"<<endl;
Foco foco;
foco.Encender();
cout<<"EstadoFoco:"
<<foco.LeerEstado()
<<endl;
    return 0;
}