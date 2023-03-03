#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Esta funci�n invierte una subcadena de la cadena de entrada
void flip(string& s, int end) {
    for (int i = 0; i < end / 2; i++) {
        swap(s[i], s[end - i - 1]);
    }
}

// Esta funci�n crea una nueva cadena a partir de la cadena de entrada
// y la subcadena que se va a voltear
string createNewString(string s, int end) {
    string newString = s.substr(0, end);
    flip(newString, end);
    return newString + s.substr(end);
}

// Esta funci�n realiza la b�squeda en amplitud
int bfs(string start, string end) {
    queue<string> q;
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    q.push(start);
    dist[start] = 0;
    parent[start] = "";
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        if (current == end) {
            return dist[current];
        }
        for (int i = 2; i <= current.length(); i++) {
            string newString = createNewString(current, i);
            if (!dist.count(newString)) {
                q.push(newString);
                dist[newString] = dist[current] + 1;
                parent[newString] = current;
            }
        }
    }
    return -1; // No se encontr� soluci�n
}

int main() {
    string start = "badc";
    string end = "abcd";
    int moves = bfs(start, end);
    if (moves == -1) {
        cout << "No se encontr� soluci�n." << endl;
    } else {
        cout << "Se necesitaron " << moves << " movimientos para ordenar los pancakes." << endl;
    }
    return 0;
}


