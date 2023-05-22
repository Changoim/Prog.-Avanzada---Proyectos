package org.javeriana.modelo;
//se crea una clase publica llmaada Obra
public class Obra{
    //Atributos de la Obra
    private String titulo;
    private String tecnica;
    private int anio;
    private float precio;
    private Artista artista;
//constructor de la clase Obra
public Obra(String titulo, String tecnica, int anio, float precio, Artista artista) {
    this.titulo = titulo;
    this.tecnica = tecnica;
    this.anio = anio;
    this.precio = precio;
    this.artista = artista;
}
//Se declaran los getters y setters
public String getTitulo() {
    return titulo;
}

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getTecnica() {
        return tecnica;
    }

    public void setTecnica(String tecnica) {
        this.tecnica = tecnica;
    }

    public int getAnio() {
        return anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }

    public float getPrecio() {
        return precio;
    }

    public void setPrecio(float precio) {
        this.precio = precio;
    }

// Método toString para representar la información de la obra como una cadena de texto

    @Override
    public String toString() {
        return
                "Titulo: " + titulo + '\'' +
                        ", Tecnica: " + tecnica + '\'' +
                        ", Anio: " + anio +
                        ", Precio: " + precio +
                        ", Artista: " + artista +
                        '}';
    }
}
