#include <iostream>
#include <vector>
using namespace std;

void promedioAlumnos(const vector<vector<float>>& notas, int M, int N) {
    for (int i = 0; i < M; i++) {
        float suma = 0;
        for (int j = 0; j < N; j++) suma += notas[i][j];
        cout << "Promedio alumno " << i + 1 << ": " << suma / N << endl;
    }
}

void promedioMaterias(const vector<vector<float>>& notas, int M, int N) {
    for (int j = 0; j < N; j++) {
        float suma = 0;
        for (int i = 0; i < M; i++) suma += notas[i][j];
        cout << "Promedio materia " << j + 1 << ": " << suma / M << endl;
    }
}

int main() {
    int M, N;
    cout << "Cantidad de alumnos: ";
    cin >> M;
    cout << "Cantidad de materias: ";
    cin >> N;

    vector<vector<float>> notas(M, vector<float>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            cout << "Nota alumno " << i + 1 << ", materia " << j + 1 << ": ";
            cin >> notas[i][j];
        }

    promedioAlumnos(notas, M, N);
    promedioMaterias(notas, M, N);

    return 0;
}


