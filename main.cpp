/*Juego de los pancakes resuelto con el método de búsqueda en Amplitud
Trabajo realizado para la materia de Inteligencia Artificial*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Esta función invierte una subcadena de la cadena de entrada
void flip(string& s, int end) {
    for (int i = 0; i < end / 2; i++) {
        swap(s[i], s[end - i - 1]);
        //Intercambia el caracter en la posicion i con el penultimo
    }
}

// Esta función crea una nueva cadena a partir de la cadena de entrada
// y la subcadena que se va a voltear
string createNewString(string s, int end) {
    string newString = s.substr(0, end);
    flip(newString, end);
    return newString + s.substr(end);
}

// Esta función realiza la búsqueda en amplitud
int bfs(string start, string end) {
    queue<string> q;
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    q.push(start);
    dist[start] = 0;
    parent[start] = "";
    while (!q.empty()) {
        string current = q.front();
        //cout <<current<< endl;
        q.pop();
        cout <<current<< endl;
        if (current == end) {
            return dist[current];
        }
        for (int i = 2; i <= current.length(); i++) {
            string newString = createNewString(current, i);
            if (!dist.count(newString)) {
                q.push(newString);
                dist[newString] = dist[current] + 1;
                parent[newString] = current;
                //cout <<newString<< endl;
            }
        }
    }
    return -1; // No se encontró solución
}

int main() {
    string start = "cdab";
    string end = "abcd";
    int moves = bfs(start, end);
    if (moves == -1) {
        cout << "No se encontró solución." << endl;
    } else {
        cout << "Los movimientos minimos para ordenar los pancakes fueron: " << moves << endl;
    }
    return 0;
}


