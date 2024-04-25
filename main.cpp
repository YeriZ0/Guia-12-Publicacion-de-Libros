#include <iostream>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "Libro.h"
#include "Revista.h"

#define LISTA 5

using namespace std;

char menu(){
    char op;

    cout << "Menú de opciones\n" << endl;
    cout << "1. Agregar publicación al inventario" << endl;
    cout << "2. Prestar libros" << endl;
    cout << "3. Devolver libros" << endl;
    cout << "4. Ver lista de publicaciones" << endl;
    cout << "5. Cerrar el progroma \n" << endl;
    cout << " -> "; cin >> op;

    return op;
}

Publicacion *agregarPublicacion(){
    int id, aP, tipo, nR;
    string titulo;
    Publicacion *pub;

    cout << "\nDigite el tipo de publicacion ('Revista = 1' 'Libro = 2')\n" << endl;
    cout << " -> "; cin >> tipo;

    if(tipo == revista){
        cout << "\nDigite el código de la revista: "; cin >> id;
        cout << "Digite el nombre de la revista: "; cin >> titulo;
        cout << "Digite el año de la revista: "; cin >> aP;
        cout << "Digite el número de la revista: "; cin >> nR;
        pub = new Revista(id, titulo, aP, nR);
    }else if(tipo == libro){
        cout << "\nDigite el código del libro: "; cin >> id;
        cout << "Digite el nombre del libro: "; cin >> titulo;
        cout << "Digite el año del libro: "; cin >> aP;
        pub = new Libro(id, titulo, aP);
    }

    return pub;
}

Libro *buscarLibro(Publicacion *lst[], int contador, int cod){
    bool encontrado = false;
    int c = 0;
    Libro *lb = NULL;
    while(c < contador && !encontrado){
        if(lst[c] -> getTipoPublicacion() == libro){
            if(lst[c] -> getIdPublicacion() == cod){
                encontrado = true;
                lb = (Libro*) lst[c];
            }else{
                c++;
            }
        }else{
            c++;
        }
    }

    return lb;
}

Publicacion *mostrarPublicaciones(Publicacion *lst[], int cont){
    if(cont == 0){
        cout << "La lista está vacía. " << endl;
    }else{
        cout << "ID \tTítulo \tAp \tTipo" << endl;
        for(int i = 0; i < cont; i++){
            cout << lst[i] -> getIdPublicacion() << " \t";
            cout << lst[i] -> getTitulo() << " \t";
            cout << lst[i] -> getAnioPublicacion() << " \t";
            (lst[i] -> getTipoPublicacion() == revista) ? cout << "Revista \n" : cout << "Libro \n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, ""); //permite imprimir caracteres espaciales en la consola

    Publicacion *inventario[LISTA];
    int contador = 0, codigo = 0;
    char opcion;
    Libro *p = NULL;
    do{
        system("cls");
        opcion = menu();

        switch(opcion){
            case '1':
                if(contador < LISTA){
                    inventario[contador] = agregarPublicacion();
                    contador++;
                    cout << "La publicación se agregó con éxito!" << endl;
                }else{
                    cout << "La lista está llena." << endl;
                }
                break;
            case '2':
                cout << "Digite el código del libro a prestar: "; cin >> codigo;
                p = buscarLibro(inventario, contador, codigo);
                if(p){
                    if(p -> prestar()){
                        cout << "El libro se prestó con éxito. " << endl;
                    }else{
                        cout << "El libro está prestado, no quedan existencias. " << endl;
                    }
                }else{
                    cout << "El libro no se encontró. " << endl;
                }
                break;
            case '3':
                cout << "Digite el código del libro a devolver: "; cin >> codigo;
                p = buscarLibro(inventario, contador, codigo);
                if(p){
                    if(p -> devolver()){
                        cout << "El libro se devolvió con éxito. " << endl;
                    }else{
                        cout << "El libro no se ha prestado." << endl;
                    }
                }else{
                    cout << "El libro no se encontró. " << endl;
                }
                break;
            case '4':
                mostrarPublicaciones(inventario, contador);
                break;
            case '5':
                break;
            default:
                cout << "Error, no es una opción existente. " << endl;
                break;
        }
        system("pause");

    }while(opcion != '5');

    return 0;
}
