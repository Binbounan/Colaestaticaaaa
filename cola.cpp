#include "cola.h"

alumno::alumno(){
    nombre="";
    carrera="";
    materiasAP=0;
    promedio=0;
}

alumno::alumno(std::string nombre, std::string carrera, int materiasAP, int promedio): nombre(nombre), carrera(carrera), materiasAP(materiasAP), promedio(promedio) {}
void alumno::operator=(alumno& x)
{
    nombre=x.nombre;
    carrera=x.carrera;
    materiasAP=x.materiasAP;
    promedio=x.promedio;
}

std::ostream& operator<<( std::ostream& o, alumno& p)
{
    o<<"nombre: "<<p.nombre<<"\t carrera: "<<p.carrera<<"materias aprobadas: "<<p.materiasAP<<"promedio: "<<p.promedio<<std::endl;
    return o;
}
std::istream& operator>>( std::istream& o, alumno& p)
{
    std::cout<<"\n inserta nombre: ";
    o>>p.nombre;
    std::cout<<"\n inserta carrera: ";
    o>>p.carrera;
    std::cout<<"\n inserta materias aprobadas: ";
    o>>p.materiasAP;
    std::cout<<"\n inserta promedio: ";
    o>>p.promedio;
    return o;
}

bool cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void cola::enqueue(alumno& elem)
{
    inserta(elem,0);
}
alumno& cola::dequeue()
{
    ult--;
    return datos[ult+1];
}
bool cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int cola::inserta(alumno& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
