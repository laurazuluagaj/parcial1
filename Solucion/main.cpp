#include <iostream>
#include     <cmath>

using namespace std;

int main()
{
    float PosicionO[2]={0.0}, PosicionD[2]={}, VelO=0.0, VelD=0.0, d=0.0, RO=0.0, RD=0.0;
    long unsigned int tiempo;
    int opcion;
    cout << "Ingrese distancia entre los dos canones: ";
    cin >> d;
    PosicionD[0]=d;
    cout << "Ingrese altura del canon de defensa: ";
    cin >> PosicionD[1];
    cout << "Ingrese altura del canon enemigo: ";
    cin >> PosicionO[1];
    //Calculamos los radios de destruccion de la defensa y el cliente
    RO=0.05*d;
    RD=0.025*d;
    cout << "Ingrese una de las siguientes opciones: ";
    cout << "1-> Generar disparos ofensivos que comprometan la integridad del cañón defensivo." << endl;
    cout << "2-> Generar disparos defensivos que comprometan la integridad del cañón ofensivo." << endl;
    cout << "3-> Dado un disparo ofensivo, generar disparos defensivos que impida que el cañón defensivo sea destruido sin importar si el cañón ofensivo pueda ser destruido." << endl;
    cout << "4-> Dado un disparo ofensivo, generar disparo defensivos que impidan que los cañones defensivo y ofensivo puedan ser destruidos." << endl;
    cin >> opcion;
    switch (opcion) {
        case 1:{
            float AngO, Vel1[2]={}, Vel2[2]={}; //Vel1: Velocidad cañon en x,y del enemigo
            cout << "Ingrese la posicion en x que tiene el canon del enemigo: ";
            cin >> PosicionO[0];
            cout << "Ingrese la velocidad que tiene el enemigo: ";
            cin >> VelO;
            //Calcular cual sera la posicion del enemigo teniendo en cuenta los tiempos de retraso
            PosicionO[0]=(VelO*2.5);
            PosicionD[0]=(VelD*2.5);
            cout << "Ingrese angulo: ";
            cin >> AngO;
            Vel1[0]=VelO*(cos(AngO));
            d-=PosicionO[0];
            }
        break;
    }
    return 0;
}
