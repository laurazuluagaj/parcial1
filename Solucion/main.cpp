#include <iostream>
#include <cmath>
#include <math.h>

int disparo1(float AngO, float PosicionO[2], float PosicionD[2], float RO);

using namespace std;

int main()
{
    float PosicionO[2]={0.0}, PosicionD[2]={}, d=0.0, RO=0.0, RD=0.0;
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

    cout << "1-> Generar disparos ofensivos que comprometan la integridad del canon defensivo." << endl;
    cout << "2-> Generar disparos defensivos que comprometan la integridad del canon ofensivo." << endl;
    cout << "3-> Dado un disparo ofensivo, generar disparos defensivos que impida que el canon defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido." << endl;
    cout << "4-> Dado un disparo ofensivo, generar disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos." << endl;
    cout << "Ingrese una de las siguientes opciones: ";
    cin >> opcion;
    switch (opcion) {
        case 1:{
            float AngO; //Vel1: Velocidad canon en x,y del enemigo
            int logro, disparos=0;
            cout << "Ingrese el angulo con el que dispara el enemigo: ";
            cin >> AngO;
            while(disparos!=3){
                logro=disparo1(AngO, PosicionO, PosicionD, RO);
                if (logro==1){
                    disparos++;
                    logro=0;
                    AngO++;
                }
            }
            }
        break;
    }
    return 0;
}

int disparo1(float AngO, float PosicionO[2], float PosicionD[2], float RO){
    float V, VelO[2]={0.0,0.0}, PosicionB[2]={0.0, 0.0}, dist;
    bool final=false;
    long unsigned int t;
    int logro=0;
    for (V=1.0; V<=200; V+=1){
        //Calculamos velocidad en x e y
        VelO[0]=V*cos(AngO*(3.1416/180));
        VelO[1]=V*sin(AngO*(3.1416/180));
        for(t=0;t<=2000;t++){
            PosicionB[0]=(PosicionO[0]+(VelO[0]*t));
            PosicionB[1]=(PosicionO[1]+(VelO[1]*t)-((0.5)*9.81*(pow(t,2))));
            dist=sqrt((pow((PosicionD[0]-PosicionB[0]),2))+ (pow((PosicionD[1]-PosicionB[1]),2)));
            if(dist<=RO){
                final=true;
                break;
            }
        }
        if(final) break;
    }
    if (V!=201 || t!=2001){
        cout << "Para comprometer la integridad del canon el enemigo debe: " << endl;
        cout << "Disparar con un angulo " << AngO << " grados y una velocidad de " << V << " metros/segundos" << endl;
        cout << "El cual golpeara el canon en un tiempo de " << t << " segundos." << endl << endl;
        logro=1;
    }
    return logro;
}
