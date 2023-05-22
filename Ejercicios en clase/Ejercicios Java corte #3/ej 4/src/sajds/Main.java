package sajds;

public class Main {
        public static void Main(String[] args){
            //se instancia un objero del tipo padre
            Padre objeto1 = new Padre();
            objeto1.show();
            //se hace una referencia al objeto tipo hija
            Padre objeto2= new Hija();
            objeto2.show();
        }
}