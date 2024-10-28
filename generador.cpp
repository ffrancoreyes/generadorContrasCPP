#include <iostream>
#include <random>
#include <string>
using namespace std;

void bienvenida();
string generadorContra(int longitud);

int main() {
    bienvenida();
    return 0;
}

void bienvenida() {
    int longitud;
    cout << "Hola Bienvenido/a a nuestro generador de contraseñas" << endl;
    cout << "Ingrese la longitud de la contraseña que desea generar: ";
    cin >> longitud;

    if (longitud > 0) {
        string contrasena = generadorContra(longitud);
        cout << "Su contraseña generada es: " << contrasena << endl;
    } else {
        cout << "Longitud inválida. Intente nuevamente con un valor positivo." << endl;
    }
}

string generadorContra(int longitud) {
    // Conjunto de caracteres para la generación de contraseñas
    const char caracteres[] = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%&*";
    const int numCaracteres = sizeof(caracteres) - 1;

    // Configuración del generador de números aleatorios
    random_device rd;          // Obtiene un valor único del sistema en cada ejecución
    mt19937 gen(rd());         // Generador de Mersenne Twister inicializado con `rd`
    uniform_int_distribution<> distrib(0, numCaracteres - 1);

    // Genera la contraseña
    string contrasena;
    for (int i = 0; i < longitud; i++) {
        contrasena += caracteres[distrib(gen)];
    }
    return contrasena;
}
