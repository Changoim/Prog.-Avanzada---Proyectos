#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

//declaracion de clases
class circulo
{
private:

    //declaracion de variables
    float radio;
    float area;
    float perimetro;
    float diametro;

public:
    //constructor en parte publica
    circulo() {};

    //funcion para pedir radio del circulo
    void pedirdatos()
    {
        cout<<"ingrese el radio del circulo para calcular area, perimetro y diametro"<<endl;
        cin>>radio;
    }

    //funcion para calcular area a partir del radio
    void calcular_area()
    {
        area = PI*(pow(radio,2));
        cout<<"area: "<<area<<endl;
    }

    //funcion para calcular perimetro a partir del radio
    void calcular_perimetro()
    {
        perimetro = 2*PI*radio;
        cout<<"perimetro: "<<perimetro<<endl;
    }

    //funcion para calcular diametro a partir del radio
    void calcular_diametro()
    {
        diametro = 2*radio;
        cout<<"diametro: "<<diametro<<endl;
    }
};

//clase
class triangulo_rectangulo
{
private:
    //declaracion de variables
    double co;
    double ca;
    double hipotenusa;
    double perimetro;
    double altura;

public:
    //constructor
    triangulo_rectangulo() {};

    void pedir_datos()
    {
        cout<<"ingrese el cateto opuesto"<<endl;
        cin>>co;
        cout<<"ingrese el cateto adyacente"<<endl;
        cin>>ca;

    }

    void sacar_hipotenusa()
    {
        int auxiliar;
        auxiliar = (pow(co,2))+(pow(ca,2));
        hipotenusa = sqrt(auxiliar);

        cout<<"la hipotenusa de este triangulo es:"<<hipotenusa<<endl;

    }
    void sacar_perimetro()
    {
        perimetro = co+ca+hipotenusa;
        cout<<"el perimetro es: "<<perimetro<<endl;
    }

    void sacar_altura()
    {
        int auxiliar2;
        auxiliar2 = (pow(hipotenusa,2))-(pow(ca,2));
        altura = sqrt(auxiliar2);

        cout<<"la altura de este triangulo es:"<<altura<<endl;
    }
};

//clase persona
class persona
{
public:
    //varibles publicas
    string nombre;
    string apellido;
    int edad;
    string ciudad;

    //constructor
    persona() {};

    void ingreso_datos()
    {
        cout<<"ingrese el nombre de la persona: ";
        cin>>nombre;
        cout<<"ingrese el apellido de la persona: ";
        cin>>apellido;
        cout<<"ingrese la edad de la persona: ";
        cin>>edad;
        cout<<"ingrese la ciudad donde reside de la persona: ";
        cin>>ciudad;
    }
    void presentarse()
    {
        cout<<"Hola ¿como estas?, me llamo "<<nombre<<" "<<apellido<<", tengo "<<edad<<" años y vivo en "<<ciudad<<". Espero que nos podamos llevar bien, hasta luego!"<<endl;
    }
};

//clase con extension o herencia de la parte publica de persona
class profesor: public persona
{
private:
    string asignatura;

public:
    //constructor
    profesor() {};
    void ingreso_datos()
    {
        cout<<"ingrese el nombre del profesor: ";
        cin>>nombre;
        cout<<"ingrese el apellido del profesor: ";
        cin>>apellido;
        cout<<"ingrese la edad del profesor: ";
        cin>>edad;
        cout<<"ingrese la asignatura que dara el profesor: ";
        cin>>asignatura;
    }

    //presentacion con los datos ingresados
    void presentarse()
    {
        cout<<"Hola, me llamo "<<nombre<<" "<<apellido<<", tengo "<<edad<<" años y desde el dia de hoy sere su profesor de "<<asignatura<<". Espero que nos podamos entender y trabajar de la mejor manera!"<<endl;
    }
};

//estudiante con herencia de la parte publica de persona
class estudiante: public persona
{
private:
    //variables (ademas de las que ya tiene por persona)
    int grado;
    int ID;

public:
    //constructor
    estudiante() {};
    void ingreso_datos()
    {
        cout<<"ingrese el nombre del estudiante: ";
        cin>>nombre;
        cout<<"ingrese el apellido del estudiante: ";
        cin>>apellido;
        cout<<"ingrese la edad del estudiante: ";
        cin>>edad;
        cout<<"ingrese el grado en el que se encuentra el estudiante: ";
        cin>>grado;
        cout<<"ingrese el ID del estudiante: ";
        cin>>ID;

    }
    void presentarse()
    {
        cout<<"Hola, me llamo "<<nombre<<" "<<apellido<<", tengo "<<edad<<" años y estoy en "<<grado<<" grado. espero que nos llevemos bien!"<<endl;
    }

    //se valida si esta en noveno o grado superior para poder hacer el curso de programacion
    void curso_prog()
    {
        bool entra;
        if (grado>=9)
        {
            entra = 1;
        }
        else
        {
            entra = 0;
        }

        if(entra==1)
        {
            cout<<"\n--- el estudiante "<<nombre<<" "<<apellido<<" con ID "<<ID<<" puede inscribirse al curso de programacion ---\n"<<endl;
        }
        else
            cout<<"\n--- el estudiante "<<nombre<<" "<<apellido<<" con ID "<<ID<<" no se puede inscribir al curso de programacion ---\n"<<endl;
    }

};

main()
{
    int op;
    char op2;
    cout<<"Taller #3 - Programacion avanzada"<<endl;
    cout<<"\n----------BIENVENIDO----------\n"<<endl;

    //ciclo para poder volver y revisar otras soluciones
    do
    {
        //menu principal
        cout<<"-> Circulo (1)"<<endl;
        cout<<"-> Triangulo rectangulo (2)"<<endl;
        cout<<"-> clase persona, profesor y estudiante (3)"<<endl;
        cin>>op;

        if (op==1||op==2||op==3)
        {
            switch (op)
            {
            case 1:
            {
                //creacion de objeto y llamada de funciones
                circulo resultado1;
                resultado1.pedirdatos();
                resultado1.calcular_area();
                resultado1.calcular_perimetro();
                resultado1.calcular_diametro();

                break;
            }
            case 2:
            {
                //creacion de objeto y llamada de funciones
                triangulo_rectangulo resultado2;
                resultado2.pedir_datos();
                resultado2.sacar_hipotenusa();
                resultado2.sacar_perimetro();
                resultado2.sacar_altura();

                break;
            }

            case 3:
            {
                char op5;
                do
                {
                    //sub menu de tercer punto
                    int op4;
                    cout<<"para ver la presentación de:"<<endl;
                    cout<<"(1) persona"<<endl;
                    cout<<"(2) profesor"<<endl;
                    cout<<"(3) estudiante"<<endl;
                    cin>>op4;

                    switch (op4)
                    {
                    case 1:
                    {
                        //creacion de objeto y llamada de funciones
                        persona pepe;
                        pepe.ingreso_datos();
                        pepe.presentarse();
                        break;
                    }

                    case 2:
                    {
                        //creacion de objeto y llamada de funciones
                        profesor juan;
                        juan.ingreso_datos();
                        juan.presentarse();
                        break;
                    }

                    case 3:
                    {
                        //creacion de objeto y llamada de funciones
                        estudiante random;
                        random.ingreso_datos();
                        random.presentarse();
                        random.curso_prog();
                        break;
                    }
                    }
                    cout<<"desea volver al menu de presentaciones?"<<endl;
                    cin>>op5;
                }
                while(op5=='s');

                break;
            }
            }
            cout<<"desea volver al menu principal?"<<endl;
            cin>>op2;
        }
        else
            cout<<"el numero ingresado no esta en el rango"<<endl;
    }
    while (op2=='s');
    cout<<"\n Hasta luego!!! \n";
}
