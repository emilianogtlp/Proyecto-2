#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "Funcion.h"
#include "Pelicula.h"
using namespace std;
int main()
{
    int i = 0;
    int l = 0;
    Actor matrizActor[20];
    Funcion matrizFuncion[20];
    Pelicula matrizPelicula[20];
    ifstream archivoActores;
    ifstream archivoPeliculas;
    int ID,numPeli, anio, duracion,actordeid=0, cantactores;
    string NombreActor, info_actores, genero, nombrepeli;
    archivoActores.open("actores.txt");
    archivoPeliculas.open("peliculas.txt");
    while (getline(archivoActores, info_actores)) {
        ID = stoi(info_actores);
        //pedir explicacion de esta funcion...
        info_actores.erase(remove_if(begin(info_actores), end(info_actores), 
            [](auto ch) {return isdigit(ch); }), info_actores.end());
        matrizActor[i].setId(ID);
        matrizActor[i].setNombre(info_actores);
        i++;
    }
    while (archivoPeliculas >> numPeli) {
        //cout << numPeli << endl;
        matrizPelicula[l].setNumPeli(numPeli);
        archivoPeliculas >> anio;
        //cout << anio << endl;
        matrizPelicula[l].setAnio(anio);
        archivoPeliculas >> duracion;
        matrizPelicula[l].setDuracion(duracion);
        archivoPeliculas >> genero;
        matrizPelicula[l].setGenero(genero);
        archivoPeliculas >> cantactores;
        for (int j = 0; j < cantactores; j++){
            archivoPeliculas >> ID;
            for (int p = 0; p < i; p++) {
                if (ID == matrizActor[p].getId()) {
                    actordeid = p;
                    matrizPelicula[l].addListaActores(matrizActor[actordeid]);
                }
            }
        }
        getline(archivoPeliculas, nombrepeli);
        //cout << nombrepeli << endl;
        matrizPelicula[l].setTitulo(nombrepeli);
        l++;
    }
    cout << matrizPelicula[1].getListaActores(1).getNombre();


    archivoActores.close();
    archivoPeliculas.close();
    return 0;
}


