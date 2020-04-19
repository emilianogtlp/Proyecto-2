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
    int ID,numPeli, anio, duracion, cantactores,numfuning,sala;
    string NombreActor, info_actores, genero, nombrepeli, cvefun;
    int hora,min, validador=0;
    archivoActores.open("actores.txt");
    archivoPeliculas.open("peliculas.txt");
    while (getline(archivoActores, info_actores)) {
        ID = stoi(info_actores);
        //pedir explicacion de esta funcion...
        // Usar metedo while y despues getline 
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
                    matrizPelicula[l].addListaActores(matrizActor[p]);
                }
            }
        }
        getline(archivoPeliculas, nombrepeli);
        //cout << nombrepeli << endl;
        matrizPelicula[l].setTitulo(nombrepeli);
        l++;
    }
    cout << "Cuantas funciones desea igresar (Maximo 20): " << endl;
    cin >> numfuning;
    while (numfuning>20)
    {
        cout << "El numero de funciones no debe superar el 20, porfavor ingrese otro valor: " << endl;
        cin >> numfuning;
    }
    for (int e = 0; e < numfuning; e++) {
        cout << "Ingrese la clave para la funcion " << e + 1 << " porfavor: " << endl;
        cin >> cvefun;
        cout << "Ingrese el numero de pelicula para la funcion " << e + 1 << " porfavor: " << endl;
        cin >> numPeli;
        while (validador == 0)
        {
            for (int o = 0; o < l; o++) {
                for (int j = 0; j < e; j++) {
                    while (numPeli == matrizFuncion[j].getNumPeli()) {
                        cout << "Numero de pelicula repetido: " << endl;
                        cin >> numPeli;
                        validador = 2;
                    }
                }
                if (numPeli == matrizPelicula[o].getNumPeli()) {
                    validador = 1;
                   // cout << "Numero de pelicula valido..." << endl;
                    matrizFuncion[e].setNumPeli(numPeli);
                }
            }
            if (validador < 1) {
                cout << "El numero de pelicula es invalido, intente ingresar uno distinto: " << endl;
                cin >> numPeli;
            }
            
        }
        validador = 0;
        cout << "Ingrese la hora (formato 24hrs) y minuto de la funcion " << e + 1 << " porfavor: " << endl;
        cin >> hora;
        cin >> min;
        while (hora > 23 || hora < 0 || min > 59 || min < 0) {
            cout << "Se ingreso una hora invalida, porfavor intentelo de nuevo: " << endl;
            cin >> hora;
            cin >> min;
        }
        Hora horafun(hora, min);
        cout << "Porfavor ingrese el numero de sala: " << endl;
        cin >> sala;
        matrizFuncion[e].setCveFuncion(cvefun);
        matrizFuncion[e].setHora(horafun);
        matrizFuncion[e].setSala(sala);
    }
    matrizFuncion[0].getHora().mostrarhora();


    archivoActores.close();
    archivoPeliculas.close();
    return 0;
}


