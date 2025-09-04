#include <iostream>

using namespace std;


struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

void llenarInventario(Producto inventario[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Producto #" << i + 1 << endl;
        cout << "Código: ";
        cin >> inventario[i].codigo;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, inventario[i].nombre);
        cout << "Precio: ";
        cin >> inventario[i].precio;
        cout << "Stock: ";
        cin >> inventario[i].stock;
        cout << "------------------------" << endl;
    }
}

void buscarProducto(Producto inventario[], int cantidad, int codigoBuscado) {
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (inventario[i].codigo == codigoBuscado) {
            cout << "Producto encontrado:" << endl;
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            cout << "Stock: " << inventario[i].stock << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado " << endl;
    }
}

float calcularValorTotal(Producto inventario[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += inventario[i].precio * inventario[i].stock;
    }
    return total;
}

int main() {
    Producto inventario[50];
    int cantidad;

    cout << " Cuantos productos deseas ingresar? (máximo 50): ";
    cin >> cantidad;

    if (cantidad <= 0 || cantidad > 50) {
        cout << "Cantidad inválida." << endl;
        return 1;
    }

    llenarInventario(inventario, cantidad);

    int codigoBuscado;
    cout << "\nBuscar producto por código: ";
    cin >> codigoBuscado;
    buscarProducto(inventario, cantidad, codigoBuscado);

    float total = calcularValorTotal(inventario, cantidad);
    cout << "\nValor total del inventario: $" << total << endl;

    return 0;
}