#ifndef REVISTA_H_INCLUDED
#define REVISTA_H_INCLUDED

#include "Publicacion.h"

class Revista : public Publicacion{
    private:
        int numRevista;
    public:
        Revista(){
            this -> numRevista = 0;
        }
        Revista(int id, string t, int aP, int nR) : Publicacion(id, t, aP){
            this -> numRevista = nR;
        }
        int getNumeroRevista(){
            return this -> numRevista;
        }
        int getTipoPublicacion(){
            return revista;
        }
};

#endif // REVISTA_H_INCLUDED
