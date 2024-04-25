#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

#include <string.h>

using namespace std;

enum tipoPublicacion{
    revista = 1,
    libro = 2
};

class Publicacion{
    protected:
        int idPublicacion;
        string titulo;
        int anioPublicacion;
    public:
        Publicacion(){
            this -> idPublicacion = 0;
            this -> anioPublicacion = 0;
        }
        Publicacion(int iP, string t, int aP){
            this -> idPublicacion = iP;
            this -> titulo = t;
            this -> anioPublicacion = aP;
        }
        int getIdPublicacion(){
            return this -> idPublicacion;
        }
        string getTitulo(){
            return this -> titulo;
        }
        int getAnioPublicacion(){
            return this -> anioPublicacion;
        }
        //metodo virtual puro porque lo inicializamos en cero
        virtual int getTipoPublicacion() = 0;
};

#endif // PUBLICACION_H_INCLUDED
