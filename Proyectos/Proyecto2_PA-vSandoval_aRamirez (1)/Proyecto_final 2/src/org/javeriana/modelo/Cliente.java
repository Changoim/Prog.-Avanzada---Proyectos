package org.javeriana.modelo;
//se declara la clase llamada Cliente
public class Cliente {
    //Atributos del Cliente
    private String nombre;
    private String direccion;
    private String correo;
    //Constructor de la clase Cliente
    public Cliente(String nombre, String direccion, String correo) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.correo = correo;
    }
    //se declaran los getters y setters de la clase
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }
    // Método toString para representar la información del cliente como una cadena de texto
    @Override
    public String toString() {
        return
                "Nombre: " + nombre + '\'' +
                        ", Direccion: " + direccion + '\'' +
                        ", Correo: " + correo + '\'' +
                        '}';
    }
}
