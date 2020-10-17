#include <iostream>

using namespace std;

int main()
{
    float PosicionO[2]={0.0}, PosicionD[2]={}, VelO=0.0, VelD=0.0, d=0.0, RO=0.0, RD=0.0;
    long unsigned int tiempo;
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
    return 0;
}
