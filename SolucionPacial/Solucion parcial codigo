/*
 * Solucion del parcial
 * Valentina Sandoval A.
 */

import java.util.ArrayList;

// Clase abstracta base
abstract class ConjuntoDeDatos {
    protected String nombre; // Nombre del conjunto de datos
    protected int tamaño; // Tamaño del conjunto de datos

    public ConjuntoDeDatos(String nombre, int tamaño) { // Constructor de la clase
        this.nombre = nombre;
        this.tamaño = tamaño;
    }

    public abstract String describir(); // Método abstracto para describir el conjunto de datos
}

// Clase derivada para conjuntos de datos tabulares
class ConjuntoDeDatosTabular extends ConjuntoDeDatos {
    private int numeroDeColumnas; // Número de columnas del conjunto de datos tabular
    private int numeroDeFilas; // Número de filas del conjunto de datos tabular

    public ConjuntoDeDatosTabular(String nombre, int tamaño, int numeroDeColumnas, int numeroDeFilas) { // Constructor de la clase
        super(nombre, tamaño); // Llama al constructor de la clase base
        this.numeroDeColumnas = numeroDeColumnas;
        this.numeroDeFilas = numeroDeFilas;
    }

    @Override
    public String describir() { // Implementación del método describir() de la clase base
        return "Nombre: " + nombre + "\n" + // Devuelve una cadena con la descripción del conjunto de datos tabular
                "Tamaño: " + tamaño + "\n" +
                "Tipo: Tabular" + "\n" +
                "Filas: " + numeroDeFilas + "\n" +
                "Columnas: " + numeroDeColumnas;
    }
}

// Clase derivada para conjuntos de datos de imágenes
class ConjuntoDeDatosImagen extends ConjuntoDeDatos {
    private int ancho; // Ancho de la imagen del conjunto de datos de imágenes
    private int alto; // Alto de la imagen del conjunto de datos de imágenes

    public ConjuntoDeDatosImagen(String nombre, int tamaño, int ancho, int alto) { // Constructor de la clase
        super(nombre, tamaño); // Llama al constructor de la clase base
        this.ancho = ancho;
        this.alto = alto;
    }

    @Override
    public String describir() { // Implementación del método describir() de la clase base
        return "Nombre: " + nombre + "\n" + // Devuelve una cadena con la descripción del conjunto de datos de imágenes
                "Tamaño: " + tamaño + "\n" +
                "Tipo: Imagen" + "\n" +
                "Ancho: " + ancho + "\n" +
                "Alto: " + alto;
    }
}

// Clase para analizar conjuntos de datos
class AnalizadorDeDatos {
    private ArrayList<ConjuntoDeDatos> conjuntosDeDatos; // Lista de conjuntos de datos

    public AnalizadorDeDatos() { // Constructor de la clase
        this.conjuntosDeDatos = new ArrayList<>(); // Inicializa la lista de conjuntos de datos
    }

    public void añadirConjuntoDeDatos(ConjuntoDeDatos conjuntoDeDatos) { // Añade un conjunto de datos a la lista
        conjuntosDeDatos.add(conjuntoDeDatos);
    }

    public void eliminarConjuntoDeDatos(String nombre) { // Elimina un conjunto de datos de la lista por nombre
        ConjuntoDeDatos conjuntoEliminar = null;
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            if (conjunto.nombre.equals(nombre)) {
                conjuntoEliminar = conjunto;
                break;
            }
        }
        if (conjuntoEliminar != null) {
            conjuntosDeDatos.remove(conjuntoEliminar);
        }
    }

    public ArrayList<String> describirConjuntosDeDatos() { // Devuelve una lista de descripciones de los conjuntos de datos
        ArrayList<String> descripciones = new ArrayList<>();
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            descripciones.add(conjunto.describir());
        }
        return descripciones;
    }
}

public class Main {
    public static void main(String[] args) {
        AnalizadorDeDatos analizador = new AnalizadorDeDatos(); // Crea un objeto analizador de datos

        // Crea conjuntos de datos y los añade al analizador
        ConjuntoDeDatosTabular conjuntoTabular = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 5, 200);
        analizador.añadirConjuntoDeDatos(conjuntoTabular);

        ConjuntoDeDatosImagen conjuntoImagen1 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        analizador.añadirConjuntoDeDatos(conjuntoImagen1);

        ConjuntoDeDatosImagen conjuntoImagen2 = new ConjuntoDeDatosImagen("Imágenes de satélite", 2000, 1080, 720);
        analizador.añadirConjuntoDeDatos(conjuntoImagen2);

        ArrayList<String> descripciones = analizador.describirConjuntosDeDatos(); // Obtiene las descripciones de los conjuntos de datos

        // Imprime las descripciones de los conjuntos de datos
        for (String descripcion : descripciones) {
            System.out.println(descripcion);
            System.out.println("------------------------------");
        }
    }
}


