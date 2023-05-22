package pp;

/*
 * La clase ConjuntoDeDatosTabular representa un conjunto de datos tabular, que hereda de ConjuntoDeDatos.
 * Proporciona atributos y métodos específicos para conjuntos de datos tabulares.
 */
class ConjuntoDeDatosTabular extends ConjuntoDeDatos {
    private int numeroDeColumnas;
    private int numeroDeFilas;

    //Constructor
    public ConjuntoDeDatosTabular(String nombre, int tamaño, int numeroDeColumnas, int numeroDeFilas) {
        super(nombre, tamaño);
        this.numeroDeColumnas = numeroDeColumnas;
        this.numeroDeFilas = numeroDeFilas;
    }

    // Método describir. Devuelve una descripción del conjunto de datos tabular.

    @Override
    public String describir() {
        return "Nombre: " + nombre + "\n" +
                "Tamaño: " + tamanio + "\n" +
                "Tipo: Tabular" + "\n" +
                "Filas: " + numeroDeFilas + "\n" +
                "Columnas: " + numeroDeColumnas;
    }
}
