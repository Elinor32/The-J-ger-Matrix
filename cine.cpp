#include <iostream>

using namespace std;

// Función para mostrar el menú principal
int mostrarMenu();
// Función para comprar los boletos
float comprarBoletos();
// Función para mostrar la cartelera
void mostrarCartelera();
// Función para mostrar futuros estrenos
void mostrarpre();
// Función para mostrar el menú de combos de snack
float menuCombos();

// Variables globales donde se almacena el total de los boletos comprados,combos de snack y la cantidad de cada uno

float totalBoletos = 0;
int totalBoletosCantidad = 0;
float totalCombos = 0;
int totalCombosCantidad = 0;

// Array que representa los asientos de una sala (5 filas x 6 columnas)
const int FILAS = 5;
const int COLUMNAS = 6;
char asientos[FILAS][COLUMNAS];

void Asientos()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            asientos[i][j] = 'O';
        }
    }
}

// Muestra el estado de los asientos
void mostrarAsientos()
{
    cout << "\nEstado actual de la sala de cine (O = Libre, X = Ocupado):\n";
    cout << "  ";
    for (int j = 0; j < COLUMNAS; j++)
    {
        cout << j + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < FILAS; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < COLUMNAS; j++)
        {
            cout << asientos[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para ver la cantidad de asientos libres
int AsientosLibres()
{
    int libres = 0;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (asientos[i][j] == 'O')
            {
                libres++;
            }
        }
    }
    return libres;
}

// Función para Verificar si lo que digito el usuario es un numero
int obtenernum()
{
    int valor;
    while (true)
    {
        cin >> valor;

        // validacion para que el usuario no digite un caracter diferente a numero
        if (cin.fail())
        {                // marca el error que el usuario no digito un numero
            cin.clear(); // Limpia el error
            cin.ignore(10000, '\n');
            cout << "Por favor, ingrese un numero valido: ";
        }
        else
        {
            return valor; // Si lo que digito el usuario es valido retornamos el valor
        }
    }
}

int main()
{
    Asientos(); // llama la funcion de sientos para cuando el usuario compre boletos

    // Logo de nuestro equipo: THE JAGER MATRIX

    cout << "===============================================\n";
    cout << "||                                           ||\n";
    cout << "||            THE JAGER MATRIX               ||\n";
    cout << "||                                           ||\n";
    cout << "||       OOOOOOOOOOOOOOOOOOOOOOOOOOO         ||\n";
    cout << "||      OOO     |||||||||||||||    OOO       ||\n";
    cout << "||     OOO      ||           ||     OOO      ||\n";
    cout << "||    OOO       ||   CINE    ||      OOO     ||\n";
    cout << "||     OOO      ||           ||     OOO      ||\n";
    cout << "||      OOO     |||||||||||||||    OOO       ||\n";
    cout << "||       OOOOOOOOOOOOOOOOOOOOOOOOOOO         ||\n";
    cout << "||                                           ||\n";
    cout << "||       Cazando nuevas experiencias         ||\n";
    cout << "===============================================\n";
    cout << endl;

    int opcion;
    do
    {
        opcion = mostrarMenu();

        switch (opcion)
        {
        case 1:
            totalBoletos += comprarBoletos();
            break;
        case 2:
            mostrarCartelera();
            break;
        case 3:
            mostrarpre();
            break;
        case 4:
            totalCombos += menuCombos();
            break;
        case 5:
            // Muestra la factura junto el total a pagar si el usuario compro boletos, combos de snack o las dos cosas
            cout << "\n======================= FACTURA =======================\n";
            cout << "Boletos comprados: " << totalBoletosCantidad << " boletos " << endl;
            cout << "Total por boletos: $" << totalBoletos << endl;
            cout << "Combos seleccionados: " << totalCombosCantidad << " combos " << endl;
            cout << "Total por combos: $" << totalCombos << endl;
            cout << "=======================================================\n";
            cout << "TOTAL A PAGAR: $" << (totalBoletos + totalCombos) << endl;
            cout << "======= GRACIAS POR LA VISITA A THE JAGUER MATRIX =======\n";
            break;
        default:
            cout << "Opcion invalida " << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}

// muestra el menu y las diferentes opciones que puede elegir el usuario
int mostrarMenu()
{
    int opcion;
    cout << "\n ========  Menu  Cine ==========" << endl;
    cout << " | 1. Comprar boletos          |" << endl;
    cout << " | 2. Mostrar cartelera        |" << endl;
    cout << " | 3. Mostrar futuros estrenos |" << endl;
    cout << " | 4. Combos de comida         |" << endl;
    cout << " | 5. Salir                    |" << endl;
    cout << " ===============================" << endl;

    while (true)
    {
        cout << "Seleccione una opcion: ";
        opcion = obtenernum();

        if (opcion >= 1 && opcion <= 5)
        {
            break;
        }
        else
        {
            cout << "Por favor seleccione una opcion  entre los numeros del 1 al 5" << endl;
        }
    }

    return opcion;
}

float comprarBoletos()
{
    int opcion;

    cout << "\nSeleccione la pelicula para la cual desea comprar boletos:" << endl;
    cout << "1. El Titanic 4" << endl;
    cout << "2. Mi villano favorito 1" << endl;
    cout << "3. El conjuro 6" << endl;
    cout << "4. Bad boys" << endl;

    while (true)
    {
        cout << "Seleccione una opcion: ";
        opcion = obtenernum();

        if (opcion >= 1 && opcion <= 4)
        {
            break;
        }
        else
        {
            cout << "Opcion invalida intentalo de nuevo" << endl;
        }
    }

    // ver los asientos libres y poner un limite de boletos junto asientos
    int asientosLibres = AsientosLibres();
    cout << "\nNumero de asientos disponibles: " << asientosLibres << endl;

    int cantidad;
    cout << "Cuanto boletos deseas comprar (maximo 30): ";
    while (true)
    {
        cantidad = obtenernum();
        if (cantidad > 0 && cantidad <= 30 && cantidad <= asientosLibres)
        {
            break;
        }
        else if (cantidad > 30)
        {
            cout << "No puedes comprar mas de 30 boletos ";
        }
        else if (cantidad > asientosLibres)
        {
            cout << "No hay suficientes asientos disponibles intentalo de nuevo";
        }
        else
        {
            cout << "Por favor ingrese una cantidad valida que sea mayor que 0 : ";
        }
    }

    mostrarAsientos(); // Mostrar lod asientos libres antes de que el usuario seleccione los asientos que quiere
    for (int i = 0; i < cantidad; i++)
    {
        int fila, columna;
        while (true)
        {
            cout << "Seleccione el asiento #" << (i + 1) << " (fila y columna): ";
            cout << "Fila (1-" << FILAS << "): ";
            fila = obtenernum();
            cout << "Columna (1-" << COLUMNAS << "): ";
            columna = obtenernum();

            if (fila >= 1 && fila <= FILAS && columna >= 1 && columna <= COLUMNAS && asientos[fila - 1][columna - 1] == 'O')
            {
                asientos[fila - 1][columna - 1] = 'X';
                // x Marcar asiento como ocupado
                break;
            }
            else
            {
                cout << "Asiento no valido o ya esta ocupado " << endl;
                cout <<  "Intentalo de nuevo " << endl;
            }
        }
    }

    mostrarAsientos(); // Muestra los asientos despues de la seleccion del usuario

    float pagarbole = cantidad * 3.50;
    cout << "\nBoletos comprados con exito" << endl;
    cout << "Has comprado " << cantidad << " boletos" << endl;
    cout << "Precio total: $" << pagarbole << endl;
    // para guardar mas boletos por si el usuario compra despues de la primera vez
    totalBoletosCantidad += cantidad;
    return pagarbole;
}

void mostrarpre()
{
    cout << "\nCartelera futuros estrenos:" << endl;
    cout << "1. Proyecto X - Fecha: 3/2/2025" << endl;
    cout << "2. Matrix 5 - Fecha: 5/5/2025" << endl;
    cout << "3. John Wick 6 - Fecha: 9/8/2025" << endl;
    cout << "4. El secreto de la calabaza magica - Fecha: 23/11/2025" << endl;
}

void mostrarCartelera()
{
    cout << "\nCartelera actual:" << endl;
    cout << "1. El Titanic" << endl;
    cout << "2. Mi villano favorito 1" << endl;
    cout << "3. El conjuro 2" << endl;
    cout << "4. Bad boys" << endl;
}

float menuCombos()
{
    int opcion;
    float precio = 0;

    cout << "\n     Menu de Combos     " << endl;
    cout << "1. Combo 1: Una palomita y dos refrescos - $10" << endl;
    cout << "2. Combo 2: Dos palomitas y dos refrescos - $18" << endl;
    cout << "3. Combo 3: Una palomita, un hotdog y dos refrescos - $16" << endl;
    cout << "4. Combo 4: Un nacho, una palomita y dos refrescos - $15" << endl;
    cout << "5. Combo 5: Una palomita, un nacho, un hotdog, dos refrescos, y una botella de agua - $25" << endl;

    while (true)
    {
        cout << "Seleccione un combo: ";
        opcion = obtenernum();

        if (opcion >= 1 && opcion <= 5)
        {
            break;
        }
        else
        {
            cout << "Opcion invalida, Seleccione un combo de el menu" << endl;
        }
    }

    switch (opcion)
    {
    case 1:
        precio = 10.0;
        cout << "Has seleccionado el Combo 1 por $10" << endl;
        break;
    case 2:
        precio = 18.0;
        cout << "Has seleccionado el Combo 2 por $18" << endl;
        break;
    case 3:
        precio = 16.0;
        cout << "Has seleccionado el Combo 3 por $16" << endl;
        break;
    case 4:
        precio = 15.0;
        cout << "Has seleccionado el Combo 4 por $15" << endl;
        break;
    case 5:
        precio = 25.0;
        cout << "Has seleccionado el Combo 5 por $25" << endl;
        break;
    }
    // para guardar mas combos de snack por si el usuario compra despues de la primera vez
    totalCombosCantidad++;
    return precio;
}
