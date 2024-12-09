// =========================================================
// File: main.cpp
// Author: Carlos Galicia - A01709890
// Date: 10/11/2023
// =========================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef tuple <int, int, int> Tuple;
bool compare(const Tuple &left, const Tuple &right){
    if (get<1>(left) == get<1>(right)){ // Si coincide en numero resueltos, desempata en tiempo penalizado 
        if (get<2>(left) == get<2>(right)){ // Si coincide en tiempo, desempata en numero de equipo
            return get<0>(left) < get<0>(right);// Retorna el menor equipo
        }
        else{// Si no coincide, retorna el menor tiempo
            return get<2>(left) < get<2>(right);
        }
    }
    else{// Si no coincide, retorna el mayor numero
        return get<1>(left) > get<1>(right); 
    }
}

int main(int argc, char *argv[]) {
    tuple <int, int, int, char> evaluacion;
    vector<tuple <int, int, int, char>> vect;
    map<int, set<int>> Resueltos;
    map<int, vector<int>> Incorrectos;
    map<int, int> NumResueltos;
    map<int, int> Penalizacion;

    std::ifstream archivo(argv[1]);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) { // Lee las lineas del archivo, complexity O(n)
            std::stringstream ss(linea);
            int equipo, problema, tiempo;
            char resultado;
            ss >> equipo >> problema >> tiempo >> resultado; // Lee los valores de la linea
            evaluacion = make_tuple(equipo, problema, tiempo, resultado); // crea un tuple con los 4 valores inputs de cada linea
            vect.push_back(evaluacion); // crea un vector de tuples
        }
        archivo.close();
    }

    for (int i = 0; i < vect.size(); i++) {//Registra equipos, problemas y tiempos, complexity O(n^2)
        if(Resueltos.find(get<0>(vect[i])) == Resueltos.end()) { // Si el equipo no existe los registra en el mapa..., complexity O(nlog(n))
            Resueltos[get<0>(vect[i])]; // Añade el equipo nuevo al mapa resueltos
            Incorrectos[get<0>(vect[i])]; // Añade el equipo nuevo al mapa incorrectos
            Penalizacion[get<0>(vect[i])] = 0; // El equipo nuevo inicia con tiempo = 0
            NumResueltos[get<0>(vect[i])] = 0; // El equipo nuevo inicia con 0 problemas resueltos
        }
        if(get<3>(vect[i]) == 'C'){ // Si el equipo resuelve un problema correctamente...
            if(Resueltos[get<0>(vect[i])].count(get<1>(vect[i])) <= 0 ){ // Si el problema resuelto es nuevo..., complexity O(log(n))
                Resueltos[get<0>(vect[i])].insert(get<1>(vect[i])); //Inserta el problema en el set de l mapa Resueltos
                // Se elimina del vector del mapa Incorrectos el problema resuelto, complexity O(n)
                auto nuevoiter = remove(Incorrectos[get<0>(vect[i])].begin(), Incorrectos[get<0>(vect[i])].end(), get<1>(vect[i]));
                Incorrectos[get<0>(vect[i])].erase(nuevoiter, Incorrectos[get<0>(vect[i])].end());
                Penalizacion[get<0>(vect[i])] += get<2>(vect[i]); // Añade el tiempo de finalizacion del problema
                NumResueltos[get<0>(vect[i])]++; // Aumenta en 1 el numero de problemas resueltos
            }

        }
        else if(get<3>(vect[i]) == 'I'){ // Si el equipo resuelve un problema incorrectamente
            Incorrectos[get<0>(vect[i])].push_back(get<1>(vect[i])); // Añade el problema al vector del mapa Incorrectos
            Penalizacion[get<0>(vect[i])] += 20; // Se suma 20 al tiempo de penalizacion del equipo
        }
    }

    // Por cada problema que no se pudo resolver al final, se quita tiempo de penalizacion, complexity O(n)
    for (const auto& par : Incorrectos) { 
        Penalizacion[par.first] -= 20*par.second.size(); // Resta 20 al tiempo de penalizacion del equipo
    }

    tuple <int, int, int> posicion;
    vector<tuple <int, int, int>> marcador;
     //Crea un vector de tuplas con la puntuacion de los equipos para ordenarlas, complexity O(n)
    for(auto it_m1 = NumResueltos.cbegin(), end_m1 = NumResueltos.cend(),
        it_m2 = Penalizacion.cbegin();
        it_m1 != end_m1; it_m1++, it_m2++)
    {
        posicion = make_tuple(it_m1->first, it_m1->second, it_m2->second); 
        marcador.push_back(posicion);
    }

    // Ordena los equipo por problemas resueltos, tiempo de penalización y numero de equipo
    sort(marcador.begin(), marcador.end(), compare);

    // Imprime vector ordenado (marcador), complexity O(n)
    for (int i = 0; i < marcador.size(); i++) { 
        cout << get<0>(marcador[i]) << " " << get<1>(marcador[i]) << " " << get<2>(marcador[i]) << endl;   
    }

    return 0;
}
