#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <iostream>
const int TAM=100;

//**********Definicion de la clase alumno********
//****************************
class alumno
{
private:
    std::string nombre;
    std::string carrera;
    int materiasAP;
    int promedio;
public:
    alumno();
    void operator=(alumno& x);
    alumno(std::string nombre, std::string carrera, int materiasAP, int promedio);
    friend std::ostream& operator<<( std::ostream&, alumno&);
    friend std::istream& operator>>( std::istream&, alumno&);
};
//*****************************



//*********Definicion de la clase Pila*********
//*****************************
class cola
{
private:
    alumno datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(alumno& elem, int pos);
public:
    cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, cola& L);
    void enqueue(alumno& elem);
    alumno& dequeue();

};
//*****************************

#endif // COLA_H_INCLUDED
