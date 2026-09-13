/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: 10
Fecha: 2026/09/12
Taller: 04
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Parte
{
    char codigo[10];
    char nombre[40];
    float valor;
};

struct Trabajo
{
    char codigo[10];
    char descripcion[60];

    Parte *partes;
    int cantPartes;
};

struct Carro
{
    char placa[10];
    char marca[30];
    char modelo[20];

    Trabajo *trabajos;
    int cantTrabajos;
};

struct Cliente
{
    char cedula[20];
    char nombre[60];

    Carro *carros;
    int cantCarros;
};

struct Taller
{
    char nombre[60];

    Cliente *clientes;
    int cantClientes;
};

void copiarTexto(char *destino, int tamDestino, const string &origen)
{
    strncpy(destino, origen.c_str(), tamDestino - 1);
    destino[tamDestino - 1] = '\0';
}

void agregarParte(Trabajo &t, Parte p)
{
    Parte *nuevoArreglo = new Parte[t.cantPartes + 1];

    for (int i = 0; i < t.cantPartes; i++)
        nuevoArreglo[i] = t.partes[i];

    nuevoArreglo[t.cantPartes] = p;

    if (t.partes != nullptr)
        delete[] t.partes;

    t.partes = nuevoArreglo;
    t.cantPartes++;
}

void agregarTrabajo(Carro &a, Trabajo t)
{
    Trabajo *nuevoArreglo = new Trabajo[a.cantTrabajos + 1];

    for (int i = 0; i < a.cantTrabajos; i++)
        nuevoArreglo[i] = a.trabajos[i];

    nuevoArreglo[a.cantTrabajos] = t;

    if (a.trabajos != nullptr)
        delete[] a.trabajos;

    a.trabajos = nuevoArreglo;
    a.cantTrabajos++;
}

void agregarCarro(Cliente &c, Carro a)
{
    Carro *nuevoArreglo = new Carro[c.cantCarros + 1];

    for (int i = 0; i < c.cantCarros; i++)
        nuevoArreglo[i] = c.carros[i];

    nuevoArreglo[c.cantCarros] = a;

    if (c.carros != nullptr)
        delete[] c.carros;

    c.carros = nuevoArreglo;
    c.cantCarros++;
}

void agregarCliente(Taller &t, Cliente c)
{
    Cliente *nuevoArreglo = new Cliente[t.cantClientes + 1];

    for (int i = 0; i < t.cantClientes; i++)
        nuevoArreglo[i] = t.clientes[i];

    nuevoArreglo[t.cantClientes] = c;

    if (t.clientes != nullptr)
        delete[] t.clientes;

    t.clientes = nuevoArreglo;
    t.cantClientes++;
}

Parte crearParte(const string &codigo, const string &nombre, float valor)
{
    Parte p;
    copiarTexto(p.codigo, sizeof(p.codigo), codigo);
    copiarTexto(p.nombre, sizeof(p.nombre), nombre);
    p.valor = valor;
    return p;
}

Trabajo crearTrabajo(const string &codigo, const string &descripcion)
{
    Trabajo t;
    copiarTexto(t.codigo, sizeof(t.codigo), codigo);
    copiarTexto(t.descripcion, sizeof(t.descripcion), descripcion);
    t.partes = nullptr;
    t.cantPartes = 0;
    return t;
}

Carro crearCarro(const string &placa, const string &marca, const string &modelo)
{
    Carro a;
    copiarTexto(a.placa, sizeof(a.placa), placa);
    copiarTexto(a.marca, sizeof(a.marca), marca);
    copiarTexto(a.modelo, sizeof(a.modelo), modelo);
    a.trabajos = nullptr;
    a.cantTrabajos = 0;
    return a;
}

Cliente crearCliente(const string &cedula, const string &nombre)
{
    Cliente c;
    copiarTexto(c.cedula, sizeof(c.cedula), cedula);
    copiarTexto(c.nombre, sizeof(c.nombre), nombre);
    c.carros = nullptr;
    c.cantCarros = 0;
    return c;
}

int separarPorComas(const string &linea, string campos[], int maxCampos)
{
    int cantidad = 0;
    stringstream ss(linea);
    string campo;

    while (cantidad < maxCampos && getline(ss, campo, ','))
    {
        campos[cantidad] = campo;
        cantidad++;
    }
    return cantidad;
}

void cargarArchivo(Taller &t)
{
    const string rutaArchivo = "taller.txt";
    ifstream archivo(rutaArchivo.c_str());

    if (!archivo.is_open())
    {
        cout << "ERROR: no se pudo abrir el archivo " << rutaArchivo << endl;
        return;
    }

    string linea;

    int idxClienteActual = -1;
    int idxCarroActual = -1;
    int idxTrabajoActual = -1;

    while (getline(archivo, linea))
    {
        if (linea.empty())
            continue;

        const int MAX_CAMPOS = 5;
        string campos[MAX_CAMPOS];
        int n = separarPorComas(linea, campos, MAX_CAMPOS);

        if (n == 0)
            continue;

        char tipo = campos[0][0];

        if (tipo == 'T' && n >= 2)
        {
            copiarTexto(t.nombre, sizeof(t.nombre), campos[1]);
        }
        else if (tipo == 'C' && n >= 3)
        {
            Cliente nuevoCliente = crearCliente(campos[1], campos[2]);
            agregarCliente(t, nuevoCliente);

            idxClienteActual = t.cantClientes - 1;
            idxCarroActual = -1;
            idxTrabajoActual = -1;
        }
        else if (tipo == 'A' && n >= 2)
        {
            if (idxClienteActual < 0)
            {
                cout << "Advertencia: se encontro un carro sin cliente asociado. Linea ignorada: "
                     << linea << endl;
                continue;
            }

            string marca = (n >= 3) ? campos[2] : "";
            string modelo = (n >= 4) ? campos[3] : "";

            Carro nuevoCarro = crearCarro(campos[1], marca, modelo);
            Cliente &clienteActual = t.clientes[idxClienteActual];
            agregarCarro(clienteActual, nuevoCarro);

            idxCarroActual = clienteActual.cantCarros - 1;
            idxTrabajoActual = -1;
        }
        else if (tipo == 'R' && n >= 3)
        {
            if (idxClienteActual < 0 || idxCarroActual < 0)
            {
                cout << "Advertencia: se encontro un trabajo sin carro asociado. Linea ignorada: "
                     << linea << endl;
                continue;
            }

            Trabajo nuevoTrabajo = crearTrabajo(campos[1], campos[2]);
            Carro &carroActual = t.clientes[idxClienteActual].carros[idxCarroActual];
            agregarTrabajo(carroActual, nuevoTrabajo);

            idxTrabajoActual = carroActual.cantTrabajos - 1;
        }
        else if (tipo == 'P' && n >= 3)
        {
            if (idxClienteActual < 0 || idxCarroActual < 0 || idxTrabajoActual < 0)
            {
                cout << "Advertencia: se encontro una parte sin trabajo asociado. Linea ignorada: "
                     << linea << endl;
                continue;
            }

            Trabajo &trabajoParaCodigo =
                t.clientes[idxClienteActual].carros[idxCarroActual].trabajos[idxTrabajoActual];

            string codigoAuto = "P-" + to_string(trabajoParaCodigo.cantPartes + 1);
            float valor = static_cast<float>(atof(campos[2].c_str()));
            Parte nuevaParte = crearParte(codigoAuto, campos[1], valor);

            Trabajo &trabajoActual =
                t.clientes[idxClienteActual].carros[idxCarroActual].trabajos[idxTrabajoActual];
            agregarParte(trabajoActual, nuevaParte);
        }
        else
        {
            cout << "Advertencia: linea con formato desconocido, se ignora: " << linea << endl;
        }
    }

    archivo.close();
}

float calcularTrabajo(Trabajo t)
{
    float sumaPartes = 0.0f;

    for (int i = 0; i < t.cantPartes; i++)
        sumaPartes += t.partes[i].valor;

    return sumaPartes * 1.19f;
}

float calcularCarro(Carro c)
{
    float total = 0.0f;

    for (int i = 0; i < c.cantTrabajos; i++)
        total += calcularTrabajo(c.trabajos[i]);

    return total;
}

float calcularCliente(Cliente c)
{
    float total = 0.0f;

    for (int i = 0; i < c.cantCarros; i++)
        total += calcularCarro(c.carros[i]);

    return total;
}

string formatoMoneda(float valor)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << valor;
    return oss.str();
}

void reporte(Taller t)
{
    float totalTaller = 0.0f;

    cout << "==================================================" << endl;
    cout << " TALLER: " << t.nombre << endl;
    cout << "==================================================" << endl;

    for (int i = 0; i < t.cantClientes; i++)
    {
        Cliente &cliente = t.clientes[i];

        cout << "\nCliente: " << cliente.nombre << " (Cedula: " << cliente.cedula << ")" << endl;

        for (int j = 0; j < cliente.cantCarros; j++)
        {
            Carro &carro = cliente.carros[j];

            cout << "  Carro: " << carro.placa;
            if (strlen(carro.marca) > 0 || strlen(carro.modelo) > 0)
                cout << " - " << carro.marca << " " << carro.modelo;
            cout << endl;

            for (int k = 0; k < carro.cantTrabajos; k++)
            {
                Trabajo &trabajo = carro.trabajos[k];

                cout << "    Trabajo [" << trabajo.codigo << "]: " << trabajo.descripcion << endl;

                for (int m = 0; m < trabajo.cantPartes; m++)
                {
                    Parte &parte = trabajo.partes[m];
                    cout << "        Parte [" << parte.codigo << "] " << parte.nombre
                         << " - $" << formatoMoneda(parte.valor) << endl;
                }

                float totalTrabajo = calcularTrabajo(trabajo);
                cout << "      Total trabajo (incluye 19%): $"
                     << formatoMoneda(totalTrabajo) << endl;
            }

            float totalCarro = calcularCarro(carro);
            cout << "  >> Total carro " << carro.placa << ": $"
                 << formatoMoneda(totalCarro) << endl;
        }

        float totalCliente = calcularCliente(cliente);
        cout << ">> Total cliente " << cliente.nombre << ": $"
             << formatoMoneda(totalCliente) << endl;

        totalTaller += totalCliente;
    }

    cout << "\n==================================================" << endl;
    cout << "TOTAL GENERAL DEL TALLER: $" << formatoMoneda(totalTaller) << endl;
    cout << "==================================================" << endl;
}

void liberarMemoria(Taller &t)
{
    for (int i = 0; i < t.cantClientes; i++)
    {
        Cliente &cliente = t.clientes[i];

        for (int j = 0; j < cliente.cantCarros; j++)
        {
            Carro &carro = cliente.carros[j];

            for (int k = 0; k < carro.cantTrabajos; k++)
            {
                Trabajo &trabajo = carro.trabajos[k];

                if (trabajo.partes != nullptr)
                {
                    delete[] trabajo.partes;
                    trabajo.partes = nullptr;
                }
                trabajo.cantPartes = 0;
            }

            if (carro.trabajos != nullptr)
            {
                delete[] carro.trabajos;
                carro.trabajos = nullptr;
            }
            carro.cantTrabajos = 0;
        }

        if (cliente.carros != nullptr)
        {
            delete[] cliente.carros;
            cliente.carros = nullptr;
        }
        cliente.cantCarros = 0;
    }

    if (t.clientes != nullptr)
    {
        delete[] t.clientes;
        t.clientes = nullptr;
    }
    t.cantClientes = 0;
}

int main()
{
    Taller taller;
    strcpy(taller.nombre, "");
    taller.clientes = nullptr;
    taller.cantClientes = 0;

    cargarArchivo(taller);
    reporte(taller);
    liberarMemoria(taller);

    return 0;
}
