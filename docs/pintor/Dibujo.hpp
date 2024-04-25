#pragma once 
#include <string>
#include <list>
#include <Vector.hpp>

using namespace std;

class Dibujo {
    private:
    list<string> lineas;
    vector posicion;
    vector velocidad;  
    public:
    void AgregarLinea(string linea){
        this->lineas.push_back(linea);
    }
    list<string> ObtenerLineas(){
        return this->lineas; 
    }
};