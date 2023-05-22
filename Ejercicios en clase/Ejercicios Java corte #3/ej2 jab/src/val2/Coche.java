package val2;

class Coche extends Vehiculo {
    private String marca;
    public Coche(String marca, int numeroRuedas) {
        super (numeroRuedas);
        this.marca = marca;
    }
    public void abrirPuerta(){
        System.out.println("Abriendo puerta...");
    }
}
