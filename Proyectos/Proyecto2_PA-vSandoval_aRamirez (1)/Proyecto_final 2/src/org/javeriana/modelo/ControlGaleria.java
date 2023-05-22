package org.javeriana.modelo;

import java.util.ArrayList;
import java.util.List;
//Se crea la clase ControlGaleria que extiende de GestionObras
public class ControlGaleria extends GestionObras {
    // Lista de clientes de la galería
    private List<Cliente> clientes;
    // Lista de compras realizadas en la galería
    private List<Compra> compras;

    public ControlGaleria() {
        //Se llama al constructor de la clase padre GestionObras
        super();
        clientes = new ArrayList<>();
        compras = new ArrayList<>();
    }

    // Métodos para agregar y eliminar artistas, clientes, obras y compras
    public void agregarArtista(Artista artista, GestionObras controlGaleria) {
        controlGaleria.agregarArtista(artista);
    }

    public void eliminarArtista(Artista artista, GestionObras controlGaleria) {
        controlGaleria.eliminarArtista(artista);
    }

    public void agregarArtista(Artista artista){
        artistas.add(artista);
    }

    public void eliminarArtista(Artista artista){
        artistas.remove(artista);
    }

    public void agregarCliente(Cliente cliente){
        clientes.add(cliente);
    }

    public void eliminarCliente(Cliente cliente){
        clientes.remove(cliente);
    }

    public void agregarObra(Obra obra){
        obras.add(obra);
    }

    public void eliminarObra(Obra obra){
        obras.remove(obra);
    }

    public void registrarCompra (Compra compra){
        compras.add(compra);
    }

    // Metodo de getters y setters para obtener y establecer las listas de artistas, clientes, obras y compras
    public List<Artista> getArtistas() {
        return artistas;
    }

    public void setArtistas(List<Artista> artistas) {
        this.artistas = artistas;
    }

    public List<Cliente> getClientes() {
        return clientes;
    }

    public void setClientes(List<Cliente> clientes) {
        this.clientes = clientes;
    }

    public List<Obra> getObras() {
        return obras;
    }

    public void setObras(List<Obra> obras) {
        this.obras = obras;
    }

    public List<Compra> getCompras() {
        return compras;
    }

    public void setCompras(List<Compra> compras) {
        this.compras = compras;
    }

    // Método para mostrar los artistas
    public void MostrarArtista() {
        int i = 1;
        for (Artista ver : artistas) {
            System.out.println(i + " - Artista");
            System.out.println(ver);
            i++;
        }
    }

    // Método para mostrar los clientes
    public void MostrarCliente() {
        int a = 1;
        for (Cliente ver : clientes) {
            System.out.println(a + " - Clientes");
            System.out.println(ver);
            a++;
        }
    }

    // Método para mostrar las obras
    public void MostrarObra() {
        int b = 1;
        for (Obra ver : obras) {
            System.out.println(b + " - Obra");
            System.out.println(ver);
            b++;
        }
    }

    // Método para mostrar las compras
    public void MostrarCompra(){
        int c = 1;
        for(Compra ver : compras){
            System.out.println(c + "- Compra");
            System.out.println(ver);
            c++;
        }
    }
}
