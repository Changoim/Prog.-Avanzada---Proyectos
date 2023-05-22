package pp;

import java.util.ArrayList;

/*
 * La clase AnalizadorDeDatos representa un analizador de conjuntos de datos.
 * Proporciona métodos para añadir, eliminar y describir conjuntos de datos.
 */
class AnalizadorDeDatos {
    private ArrayList<ConjuntoDeDatos> conjuntosDeDatos;

    //Constructor de la clase AnalizadorDeDatos.
    public AnalizadorDeDatos() {
        this.conjuntosDeDatos = new ArrayList<>();
    }

    //Método añadirConjuntoDeDatos. Añade un conjunto de datos a la lista de conjuntos de datos.

    public void añadirConjuntoDeDatos(ConjuntoDeDatos conjuntoDeDatos) {
        conjuntosDeDatos.add(conjuntoDeDatos);
    }

    /*
     * Método eliminarConjuntoDeDatos.
     * Elimina un conjunto de datos de la lista de conjuntos de datos basándose en su nombre.
     */
    public void eliminarConjuntoDeDatos(String nombre) {
        //se crea una variable vacia
        ConjuntoDeDatos conjuntoEliminar = null;
        //for each para buscar
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            if (conjunto.nombre.equals(nombre)) {
                // el elemento encontrado para a estar en la variable de eliminar
                conjuntoEliminar = conjunto;
                break;
            }
        }
        // si la variable a eliminar ya no esta vacia
        if (conjuntoEliminar != null) {
            //se elimina lo que este en esa variable en la lista
            conjuntosDeDatos.remove(conjuntoEliminar);
        }
    }

    /*
     * Método describirConjuntosDeDatos.
     * Devuelve una lista de descripciones de todos los conjuntos de datos en la lista de conjuntos de datos.
     */
    public ArrayList<String> describirConjuntosDeDatos() {
        ArrayList<String> descripciones = new ArrayList<>();
        //for each para mostrar/describir los elementos de conjuntoDeDatos
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {
            descripciones.add(conjunto.describir());
        }
        return descripciones;
    }
}
