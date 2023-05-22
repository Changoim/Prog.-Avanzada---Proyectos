package pp;

import java.util.ArrayList;

/*
* Respuestas de concepto
* 1. a. Verdadero
* 2. a. Verdadero
* 3. b. Falso
* 4. a. Verdadero
* 5. a. Verdadero
* 6. A) La capacidad de una clase de heredar propiedades y métodos de otra clase.
* 7. D) La capacidad de un objeto de ser tratado como uno de varios tipos posibles.
* 8. D) Se utilizan como plantillas para crear subclases concretas.
* 9. A) La capacidad de una subclase de proporcionar una implementación diferente para un método heredado de la clase padre.
* 10. D) Se utilizan para definir un contrato que una clase debe cumplir.
*/

//Main de solucion del parcial
public class Main {
    public static void main(String[] args) {
        AnalizadorDeDatos analizador = new AnalizadorDeDatos();

        ConjuntoDeDatosTabular conjuntoTabular = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 5, 200);
        analizador.añadirConjuntoDeDatos(conjuntoTabular);

        ConjuntoDeDatosImagen conjuntoImagen1 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        analizador.añadirConjuntoDeDatos(conjuntoImagen1);

        ConjuntoDeDatosImagen conjuntoImagen2 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        analizador.añadirConjuntoDeDatos(conjuntoImagen2);

        ArrayList<String> descripciones = analizador.describirConjuntosDeDatos();
        for (String descripcion : descripciones) {
            System.out.println(descripcion);
            System.out.println("------------------------------");
        }
    }
}
