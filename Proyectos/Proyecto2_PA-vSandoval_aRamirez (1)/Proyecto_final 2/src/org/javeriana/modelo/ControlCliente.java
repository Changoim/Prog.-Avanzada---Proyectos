package org.javeriana.modelo;

import java.util.ArrayList;
import java.util.List;
//Se crea la clase ControlCliente que extiende de ControlGaleria
public class ControlCliente extends ControlGaleria {
    private List<Cliente> clientes;
//Constructor de ControlCliente
    public ControlCliente() {
        super();
        clientes = new ArrayList<>();
    }

    @Override
    public void agregarCliente(Cliente cliente) {
        clientes.add(cliente);
    }

    @Override
    public void eliminarCliente(Cliente cliente) {
        clientes.remove(cliente);
    }
}
