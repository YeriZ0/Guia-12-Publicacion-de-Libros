#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include "Publicacion.h"
#include "iPrestable.h"

class Libro : public Publicacion, public iPrestable{
    private:
        bool estado;
    public:
        Libro(){
            this -> estado = false;
        }
        Libro(int id, string t, int aP) : Publicacion(id, t, aP){
            this -> estado = false;
        }
        bool prestar(){
            bool r = false;
            if(!this -> estado){
                this -> estado = true;
                r = true;
            }
            return r;
        }
        bool devolver(){
            bool r = false;
            if(this -> estado){
                this -> estado = false;
                r = true;
            }
            return r;
        }
        getEstadoPrestamo(){
            return this -> estado;
        }
        int getTipoPublicacion(){
            return libro;
        }
};


#endif // LIBRO_H_INCLUDED
