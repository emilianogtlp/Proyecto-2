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
    int ID,numPeli, anio, duracion, cantactores,numfuning,sala, respuesta, compsala=0, compcve =0;
    int validarcve = 0, validarid = 0;
    string NombreActor, info_actores, genero, nombrepeli, cvefun;
    Hora horamenu;
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
        while (compcve < e + 1) {
            for (int ns = 0; ns < e + 1; ns++) {
                if (cvefun == matrizFuncion[ns].getCveFuncion()) {
                    cout << "Ha ingresado una clave repetida, ingrese otra porfavor: " << endl;
                    compcve = 0;
                    cin >> cvefun;
                }
                else {
                    compcve++;
                }
            }
        }
        compcve = 0;
        cout << "Ingrese el numero de pelicula para la funcion " << e + 1 << " porfavor: " << endl;
        cin >> numPeli;
        while (validador == 0)
        {
            for (int o = 0; o < l; o++) {
                
                //Habilitar si el numero de pelicula no se puede repetir

                /*for (int j = 0; j < e; j++) {
                    while (numPeli == matrizFuncion[j].getNumPeli()) {
                        cout << "Numero de pelicula repetido: " << endl;
                        cin >> numPeli;
                        validador = 2;
                    }
                }*/
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
        cout << "Hora: ";
        cin >> hora;
        cout << "Minutos: ";
        cin >> min;
        while (hora > 23 || hora < 0 || min > 59 || min < 0) {
            cout << "Se ingreso una hora invalida, porfavor intentelo de nuevo: " << endl;
            cin >> hora;
            cin >> min;
        }
        Hora horafun(hora, min);
        cout << "Porfavor ingrese el numero de sala: " << endl;
        cin >> sala;
        // Verifica que la sala no se repita en el mismo dia
        while (compsala < e+1 ) {
            for (int ns = 0; ns < e + 1; ns++) {
                if (sala == matrizFuncion[ns].getSala()) {
                    cout << "Ha ingresado una sala repetida, ingrese otra porfavor: " << endl;
                        compsala = 0;
                        cin >> sala;
                }
                else {
                    compsala++;
                }
            }
        }
        compsala = 0;
        matrizFuncion[e].setCveFuncion(cvefun);
        matrizFuncion[e].setHora(horafun);
        matrizFuncion[e].setSala(sala);
    }
    while (validador == 0) {
        cout << "            Menu            " << endl;
        cout << "1.- Consulta de actores" << endl;
        cout << "2.- Consulta de peliculas" << endl;
        cout << "3.- Consulta de Funciones disponibles hoy" << endl;
        cout << "4.- Consulta de funciones disponibles por hora " << endl;
        cout << "5.- Consulta de Funcion por clave" << endl;
        cout << "6.- Consulta de pelicuals por ID de actor" << endl;
        cout << "7.- Salir" << endl;
        cin >> respuesta;
        while (respuesta < 1 || respuesta > 7) {
            cout << "La opcion que ha ingresado no es valida, porfavor intentelo de nuevo: " << endl;
            cin >> respuesta;
        }
        switch (respuesta)
        {
        case 1:
            for (int y = 0; y < i; y++) {
                cout << "ID: " << matrizActor[y].getId() << "   Nombre: " << matrizActor[y].getNombre() << endl;
            }
            break;
        case 2:
            for (int e = 0; e < l; e++) {
                cout << "Titulo: " << matrizPelicula[e].getTitulo() << "  Anio: " << matrizPelicula[e].getAnio();
                cout << "  Duracion: " << matrizPelicula[e].getDuracion() << " Genero: " << matrizPelicula[e].getGenero() << endl;
                cout << "Lista actores:" << endl;
                for (int g = 0; g < matrizPelicula[e].getCantActores(); g++) {
                    cout << "ID: " << matrizPelicula[e].getListaActores(g).getId();
                    cout << "   Nombre: " << matrizPelicula[e].getListaActores(g).getNombre() << endl;
                }
            }
            break;
        case 3:
            for (int m = 0; m < numfuning; m++) {
                cout << "Clave: " << matrizFuncion[m].getCveFuncion() << "  Nombre: ";
                for (int np = 0; np < l; np++) {
                    if (matrizFuncion[m].getNumPeli() == matrizPelicula[np].getNumPeli()) {
                        cout << matrizPelicula[np].getTitulo();
                    }
                }
                cout << "  Numero de sala: " << matrizFuncion[m].getSala() << "  Hora: ";
                matrizFuncion[m].getHora().mostrarhora();
            }
            break;
        case 4:
            cout << "Ingrese la hora y despues los minutos: " << endl;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minutos: ";
            cin >> min;
            while (hora > 23 || hora < 0 || min > 59 || min < 0) {
                cout << "Se ingreso una hora invalida, porfavor intentelo de nuevo: " << endl;
                cout << "Hora: ";
                cin >> hora;
                cout << "Minutos: ";
                cin >> min;
            }
            horamenu.setHh(hora); horamenu.setMm(min);
            for (int a = 0; a < numfuning; a++) {
                if (horamenu.getHh() == matrizFuncion[a].getHora().getHh() && horamenu.getMm() == matrizFuncion[a].getHora().getMm()) {
                    for (int np = 0; np < l; np++) {
                        if (matrizFuncion[a].getNumPeli() == matrizPelicula[np].getNumPeli()) {
                            cout << "Titulo: "<<matrizPelicula[np].getTitulo();
                            cout << "  Nuero de sala: " << matrizFuncion[a].getSala() << endl;
                        }
                    }
                }
            }
            break;
        case 5:
            cout << "Ingrese un clave de funcion: " << endl;
            cin >> cvefun;
            while (validarcve == 0) {
                for (int w = 0; w < numfuning; w++) {
                    if (cvefun == matrizFuncion[w].getCveFuncion()) {
                        for (int np = 0; np < l; np++) {
                            if (matrizFuncion[w].getNumPeli() == matrizPelicula[np].getNumPeli()) {
                                cout << "Titulo: " << matrizPelicula[np].getTitulo();
                                cout << "  Numero de sala: " << matrizFuncion[w].getSala();
                                cout << "  Hora: "; matrizFuncion[w].getHora().mostrarhora();
                                cout << "  Duracion: " << matrizPelicula[np].getDuracion();
                                cout << "  Genero:  " << matrizPelicula[np].getGenero() << endl;
                                cout << "  Actores: " << endl;
                                for (int hj = 0; hj < matrizPelicula[np].getCantActores(); hj++) {
                                    cout << matrizPelicula[np].getListaActores(hj).getNombre() << endl;
                                }
                                validarcve = 1;
                            }
                        }
                    }
                }
                if (validarcve == 0) {
                    cout << "Ha ingresado una clave invalida, intentelo de nuevo: " << endl;
                    cin >> cvefun;
                    validarcve = 0;
                }
            }
            validarcve = 0;
            break;
        case 6:
            cout << "Ingrese el ID de un actor: " << endl;
            cin >> ID;
            while (validarid == 0) {
                for (int b = 0; b < l; b++)
                {
                    for (int e = 0; e < matrizPelicula[b].getCantActores() ; e++)
                    {
                        if (ID == matrizPelicula[b].getListaActores(e).getId())
                        {
                            cout << "Titulo: " << matrizPelicula[b].getTitulo() << "  Anio: " << matrizPelicula[b].getAnio() << endl;
                            validarid = 1;
                        }
                    }
                }
                if(validarid == 0) {
                    cout << "Ha ingresado un ID invalido, intentelo de nuevo porfavor: " << endl;
                    cin >> ID;
                }
            }
            validarid = 0;
            break;
        case 7:
            validador = 1;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    }
    archivoActores.close();
    archivoPeliculas.close();
    return 0;
}


