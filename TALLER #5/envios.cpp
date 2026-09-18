/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: 10
Fecha: 2026/09/12
Taller: 04
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Seguimiento
{
    Fecha fecha;
    char ciudad[40];
    char estado[30];
};

struct Paquete
{
    char codigo[10];
    char descripcion[60];
    char tipoPaquete;
    float peso;

    Seguimiento *seguimientos;
    int cantSeguimientos;
};

struct Envio
{
    char codigo[10];
    char ciudadOrigen[40];
    char ciudadDestino[40];
    Fecha fechaEnvio;
    float costo;

    Paquete *paquetes;
    int cantPaquetes;
};

struct Cliente
{
    char documento[20];
    char nombre[60];
    char telefono[20];

    Envio *envios;
    int cantEnvios;
};

struct Empresa
{
    char nombre[60];

    Cliente *clientes;
    int cantClientes;
};

const float COSTO_DELICADO = 5000.0f;

Fecha convertirFecha(char fecha[]);
void mostrarFecha(Fecha f);

void agregarCliente(Empresa &e, Cliente c);
void agregarEnvio(Cliente &c, Envio e);
void agregarPaquete(Envio &e, Paquete p);
void agregarSeguimiento(Paquete &p, Seguimiento s);

void cargarArchivo(Empresa &e);
int splitCampos(char *linea, char *campos[], int maxCampos);

float calcularEnvio(Envio e);
float calcularCliente(Cliente c);
float calcularEmpresa(Empresa e);

void reporte(Empresa e);
void liberarMemoria(Empresa &e);

int main()
{
    Empresa empresa;
    empresa.clientes = nullptr;
    empresa.cantClientes = 0;
    strcpy(empresa.nombre, "");

    cargarArchivo(empresa);

    reporte(empresa);

    liberarMemoria(empresa);

    return 0;
}

Fecha convertirFecha(char fecha[])
{
    Fecha f;
    sscanf(fecha, "%d-%d-%d", &f.dia, &f.mes, &f.anio);
    return f;
}

void mostrarFecha(Fecha f)
{
    cout << setfill('0') << setw(4) << f.anio << "/"
         << setw(2) << f.mes << "/"
         << setw(2) << f.dia
         << setfill(' ');
}

void agregarCliente(Empresa &e, Cliente c)
{
    Cliente *nuevo = new Cliente[e.cantClientes + 1];
    for (int i = 0; i < e.cantClientes; i++)
        nuevo[i] = e.clientes[i];
    nuevo[e.cantClientes] = c;

    delete[] e.clientes;
    e.clientes = nuevo;
    e.cantClientes++;
}

void agregarEnvio(Cliente &c, Envio e)
{
    Envio *nuevo = new Envio[c.cantEnvios + 1];
    for (int i = 0; i < c.cantEnvios; i++)
        nuevo[i] = c.envios[i];
    nuevo[c.cantEnvios] = e;

    delete[] c.envios;
    c.envios = nuevo;
    c.cantEnvios++;
}

void agregarPaquete(Envio &e, Paquete p)
{
    Paquete *nuevo = new Paquete[e.cantPaquetes + 1];
    for (int i = 0; i < e.cantPaquetes; i++)
        nuevo[i] = e.paquetes[i];
    nuevo[e.cantPaquetes] = p;

    delete[] e.paquetes;
    e.paquetes = nuevo;
    e.cantPaquetes++;
}

void agregarSeguimiento(Paquete &p, Seguimiento s)
{
    Seguimiento *nuevo = new Seguimiento[p.cantSeguimientos + 1];
    for (int i = 0; i < p.cantSeguimientos; i++)
        nuevo[i] = p.seguimientos[i];
    nuevo[p.cantSeguimientos] = s;

    delete[] p.seguimientos;
    p.seguimientos = nuevo;
    p.cantSeguimientos++;
}

int splitCampos(char *linea, char *campos[], int maxCampos)
{
    int n = 0;
    char *token = strtok(linea, ",");
    while (token != nullptr && n < maxCampos)
    {
        campos[n++] = token;
        token = strtok(nullptr, ",");
    }
    return n;
}

void cargarArchivo(Empresa &e)
{
    const char *nombreArchivo = "envios.txt";
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    char linea[300];
    Cliente *clienteActual = nullptr;
    Envio *envioActual = nullptr;
    Paquete *paqueteActual = nullptr;

    while (archivo.getline(linea, 300))
    {
        int len = strlen(linea);
        while (len > 0 && (linea[len - 1] == '\r' || linea[len - 1] == '\n'))
        {
            linea[len - 1] = '\0';
            len--;
        }
        if (len == 0)
            continue;

        char tipo = linea[0];
        char *campos[10];
        int n = splitCampos(linea, campos, 10);
        (void)n;

        switch (tipo)
        {
        case 'E':
        {
            strcpy(e.nombre, campos[1]);
            break;
        }
        case 'C':
        {
            Cliente c;
            strcpy(c.documento, campos[1]);
            strcpy(c.nombre, campos[2]);
            strcpy(c.telefono, campos[3]);
            c.envios = nullptr;
            c.cantEnvios = 0;

            agregarCliente(e, c);
            clienteActual = &e.clientes[e.cantClientes - 1];
            envioActual = nullptr;
            paqueteActual = nullptr;
            break;
        }
        case 'N':
        {
            Envio ev;
            strcpy(ev.codigo, campos[1]);
            strcpy(ev.ciudadOrigen, campos[2]);
            strcpy(ev.ciudadDestino, campos[3]);
            ev.fechaEnvio = convertirFecha(campos[4]);
            ev.costo = atof(campos[5]);
            ev.paquetes = nullptr;
            ev.cantPaquetes = 0;

            agregarEnvio(*clienteActual, ev);
            envioActual = &clienteActual->envios[clienteActual->cantEnvios - 1];
            paqueteActual = nullptr;
            break;
        }
        case 'P':
        {
            Paquete p;
            strcpy(p.codigo, campos[1]);
            strcpy(p.descripcion, campos[2]);
            p.tipoPaquete = campos[3][0];
            p.peso = atof(campos[4]);
            p.seguimientos = nullptr;
            p.cantSeguimientos = 0;

            agregarPaquete(*envioActual, p);
            paqueteActual = &envioActual->paquetes[envioActual->cantPaquetes - 1];
            break;
        }
        case 'S':
        {
            Seguimiento s;
            s.fecha = convertirFecha(campos[1]);
            strcpy(s.ciudad, campos[2]);
            strcpy(s.estado, campos[3]);

            agregarSeguimiento(*paqueteActual, s);
            break;
        }
        default:
            break;
        }
    }

    archivo.close();
}

float calcularEnvio(Envio e)
{
    int delicados = 0;
    for (int i = 0; i < e.cantPaquetes; i++)
    {
        if (e.paquetes[i].tipoPaquete == 'D')
            delicados++;
    }
    return e.costo + delicados * COSTO_DELICADO;
}

float calcularCliente(Cliente c)
{
    float total = 0;
    for (int i = 0; i < c.cantEnvios; i++)
        total += calcularEnvio(c.envios[i]);
    return total;
}

float calcularEmpresa(Empresa e)
{
    float total = 0;
    for (int i = 0; i < e.cantClientes; i++)
        total += calcularCliente(e.clientes[i]);
    return total;
}

void reporte(Empresa e)
{
    int totalEnvios = 0, totalPaquetes = 0, totalSeguimientos = 0;

    cout << "========================================================\n";
    cout << "              EMPRESA: " << e.nombre << "\n";
    cout << "========================================================\n\n";

    for (int i = 0; i < e.cantClientes; i++)
    {
        Cliente &c = e.clientes[i];

        cout << "CLIENTE\n";
        cout << "Documento: " << c.documento << "\n";
        cout << "Nombre: " << c.nombre << "\n";
        cout << "Telefono: " << c.telefono << "\n\n";

        for (int j = 0; j < c.cantEnvios; j++)
        {
            Envio &ev = c.envios[j];
            totalEnvios++;

            cout << "    ENVIO: " << ev.codigo << "\n";
            cout << "    Origen: " << ev.ciudadOrigen << "\n";
            cout << "    Destino: " << ev.ciudadDestino << "\n";
            cout << "    Fecha de envio: ";
            mostrarFecha(ev.fechaEnvio);
            cout << "\n";
            cout << "    Costo base: $" << fixed << setprecision(0) << ev.costo << "\n\n";

            int delicados = 0;
            for (int k = 0; k < ev.cantPaquetes; k++)
            {
                Paquete &p = ev.paquetes[k];
                totalPaquetes++;
                if (p.tipoPaquete == 'D')
                    delicados++;

                cout << "        PAQUETE: " << p.codigo << "\n";
                cout << "        Descripcion: " << p.descripcion << "\n";
                cout << "        Tipo: " << (p.tipoPaquete == 'D' ? "Delicado" : "Normal") << "\n";
                cout << "        Peso: " << fixed << setprecision(2) << p.peso << " kg\n\n";

                for (int m = 0; m < p.cantSeguimientos; m++)
                {
                    Seguimiento &s = p.seguimientos[m];
                    totalSeguimientos++;

                    cout << "            SEGUIMIENTO\n";
                    cout << "            Fecha: ";
                    mostrarFecha(s.fecha);
                    cout << "\n";
                    cout << "            Ciudad: " << s.ciudad << "\n";
                    cout << "            Estado: " << s.estado << "\n\n";
                }
            }

            float incremento = delicados * COSTO_DELICADO;
            cout << "    Paquetes delicados: " << delicados << "\n";
            cout << "    Incremento por delicados: $" << fixed << setprecision(0) << incremento << "\n";
            cout << "    TOTAL ENVIO: $" << fixed << setprecision(0) << calcularEnvio(ev) << "\n\n";
        }

        cout << "TOTAL CLIENTE: $" << fixed << setprecision(0) << calcularCliente(c) << "\n";
        cout << "--------------------------------------------------------\n\n";
    }

    cout << "RESUMEN GENERAL\n\n";
    cout << "Total clientes:        " << e.cantClientes << "\n";
    cout << "Total envios:          " << totalEnvios << "\n";
    cout << "Total paquetes:        " << totalPaquetes << "\n";
    cout << "Total seguimientos:    " << totalSeguimientos << "\n\n";
    cout << "TOTAL GENERAL:         $" << fixed << setprecision(0) << calcularEmpresa(e) << "\n\n";
    cout << "========================================================\n";
}

void liberarMemoria(Empresa &e)
{
    for (int i = 0; i < e.cantClientes; i++)
    {
        Cliente &c = e.clientes[i];
        for (int j = 0; j < c.cantEnvios; j++)
        {
            Envio &ev = c.envios[j];
            for (int k = 0; k < ev.cantPaquetes; k++)
            {
                delete[] ev.paquetes[k].seguimientos;
            }
            delete[] ev.paquetes;
        }
        delete[] c.envios;
    }
    delete[] e.clientes;

    e.clientes = nullptr;
    e.cantClientes = 0;
}
