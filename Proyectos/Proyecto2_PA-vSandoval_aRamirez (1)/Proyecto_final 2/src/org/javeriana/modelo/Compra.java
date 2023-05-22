package org.javeriana.modelo;
//Se crea una clase llamada Compra
public class Compra{
    //Atrubutos de la compra
    private String fecha;
    private float precio;
    private Cliente cliente;
    private Obra obra;
//Se crea un Contructor para la clase Compra
public Compra(String fecha, float precio, Cliente cliente, Obra obra) {
    this.fecha = fecha;
    this.precio = precio;
    this.cliente = cliente;
    this.obra = obra;
}
//Se declaran los getters y setters de la clase
public String getFecha() {
    return fecha;
}

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public float getPrecio() {
        return precio;
    }

    public void setPrecio(float precio) {
        this.precio = precio;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Obra getObra() {
        return obra;
    }

    public void setObra(Obra obra) {
        this.obra = obra;
    }
    // Método toString para representar la información de la compra como una cadena de texto
    @Override
    public String toString() {
        return
                "Fecha:" + fecha + '\'' +
                        ", Precio: " + precio + '\'' +
                        ", Cliente: " + cliente + '\'' +
                        ", Obra: " + obra;
    }
}
