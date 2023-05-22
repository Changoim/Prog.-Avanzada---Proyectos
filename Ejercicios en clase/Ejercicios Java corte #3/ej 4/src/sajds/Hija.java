package sajds;

public class Hija extends Padre {
    //este metodo sobreescribe el metodo show de la clase padre
    @Override
    void show(){
        System.out.println("clase hija: metodo show()");
    }
}
