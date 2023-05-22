package org.javeriana.modelo;
// Se crea una clase llamada Artista
public class Artista {
//Atributos para la clase
    private String nombre;
    private String fecha_nacimiento;
    private String nacionalidad;
    private String Biografia;
// Constructor de la clase
    public Artista(String nombre, String fecha_nacimiento, String nacionalidad, String biografia) {
        this.nombre = nombre;
        this.fecha_nacimiento = fecha_nacimiento;
        this.nacionalidad = nacionalidad;
        Biografia = biografia;
    }
//getters y setters de los atributos
public String getNombre() {
    return nombre;
}

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getFecha_nacimiento() {
        return fecha_nacimiento;
    }

    public void setFecha_nacimiento(String fecha_nacimiento) {
        this.fecha_nacimiento = fecha_nacimiento;
    }

    public String getNacionalidad() {
        return nacionalidad;
    }

    public void setNacionalidad(String nacionalidad) {
        this.nacionalidad = nacionalidad;
    }

    public String getBiografia() {
        return Biografia;
    }

    public void setBiografia(String biografia) {
        Biografia = biografia;
    }
// Método toString para representar la información del artista como una cadena de texto

    @Override
    public String toString() {
        return
                "Nombre:" + nombre + '\'' +
                        ", Fecha nacimiento: " + fecha_nacimiento + '\'' +
                        ", Nacionalidad: " + nacionalidad + '\'' +
                        ", Biografia: " + Biografia;
    }
}

