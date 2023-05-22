package pp;

/*
 * La clase ConjuntoDeDatosImagen representa un conjunto de datos de tipo imagen, que hereda de ConjuntoDeDatos.
 * Proporciona atributos y métodos específicos para conjuntos de datos de tipo imagen.
 */
class ConjuntoDeDatosImagen extends ConjuntoDeDatos {
    private int ancho;
    private int alto;

    //Constructor
    public ConjuntoDeDatosImagen(String nombre, int tamanio, int ancho, int alto) {
        super(nombre, tamanio);
        this.ancho = ancho;
        this.alto = alto;
    }

    //Método describir. Devuelve una descripción del conjunto de datos de tipo imagen.

    @Override
    public String describir() {
        return "Nombre: " + nombre + "\n" +
                "Tamaño: " + tamanio + "\n" +
                "Tipo: Imagen" + "\n" +
                "Ancho: " + ancho + "\n" +
                "Alto: " + alto;
    }
}
