//Valentina Sandoval A.  27/03/23
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

class pitagoras
{
    private:
        double co;
        double ca;
        double hipotenusa;

    public:
        pitagoras(){};
       void hallar_hipotenusa()
       {
           cout<<"ingrese el cateto opuesto del triangulo"<<endl;
           cin>>co;
           cout<<"ingrese el cateto adyacente del triangulo"<<endl;
           cin>>ca;
           int auxiliar;
           auxiliar = (pow(co,2))+(pow(ca,2));
           hipotenusa = sqrt(auxiliar);

           cout<<"la hipotenusa de este triangulo es:"<<hipotenusa<<endl;
       }
};

class raiz
{
    private:
        float numero;
        float radical;
        float resultado;
    public:
        raiz(){};

       void raiz_nesima()
       {
           cout<<"ingrese el numero al que se le va a sacar la raiz"<<endl;
           cin>>numero;
           cout<<"ingrese el numero de la raiz"<<endl;
           cin>>radical;

           resultado = pow(numero, (1/radical));

           cout<<"el resultado es: "<<resultado<<endl;
       }

};

class piesametros
{
    private:
        float metro;
        float pies;

    public:
        piesametros(){};

       void pies_metros()
       {
           cout<<"ingrese los pies para pasar a metros"<<endl;
           cin>>pies;

           metro = pies/3,281;

           cout<<"el resultado es: "<<metro<<endl;
       }

};

main()
{
    pitagoras triangulo1;
    triangulo1.hallar_hipotenusa();

    raiz resultado;
    resultado.raiz_nesima();

    piesametros metros;
    metros.pies_metros();


}

