package org.javeriana.modelo;

import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;
//Se crea una clase llamada GestionObras

public class GestionObras {
    // Lista de obras
    protected List<Obra> obras;
    // Lista de artistas
    protected List<Artista> artistas;
// Método de inicialización de las listas obras y artistas como un ArrayList vacio
    public GestionObras() {
        obras = new ArrayList<>();
        artistas = new ArrayList<>();
    }

    // Método para agregar una obra a la lista
    public void agregarObra(Obra obra) {
        obras.add(obra);
        System.out.println("Obra agregada: " + obra);
    }

    // Método para eliminar una obra de la lista
    public void eliminarObra(Obra obra) {
        boolean eliminado = obras.remove(obra);
        if (eliminado) {
            System.out.println("Obra eliminada: " + obra);
        } else {
            System.out.println("La obra no existe en la lista.");
        }
    }

    // Método para agregar un artista a la lista
    public void agregarArtista(Artista artista) {
        artistas.add(artista);
    }

    // Método para eliminar un artista de la lista
    public void eliminarArtista(Artista artista) {
        artistas.remove(artista);
    }
}
