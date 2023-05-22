package pp;

/*
 * La clase abstracta ConjuntoDeDatos representa un conjunto de datos genérico.
 * Proporciona atributos y métodos básicos para la manipulación y descripción de conjuntos de datos.
 */
abstract class ConjuntoDeDatos {
    protected String nombre;
    protected int tamanio;

    /*
     * Constructor de la clase ConjuntoDeDatos.
     * Inicializa el nombre y tamaño del conjunto de datos.
     */
    public ConjuntoDeDatos(String nombre, int tamaño) {
        this.nombre = nombre;
        this.tamanio = tamaño;
    }

    //Método abstracto describir. Devuelve una descripción del conjunto de datos.

    public abstract String describir();
}
