/*
-------------------------------------------------------------------------------
  Autor: Valentina Sandoval A.
  Fecha: 14/04/23
  Tema: Clases comparator, collectios y Arrays

  Taller:
  Subir un fichero (.java), el cual pueda manipular una lista de Jugadores de Ajedrez que han participado en un evento.
  Los datos son: Nombre, ELO, edad, valorPremio. El ELO representa un valor del tipo entero al igual que el valorPremio.
  Se requiere una aplicaciC3n que se pueda ordenar los jugadores en funciC3n de el ELO, de la edad y del valor del premio. 
  Inicialmente, la aplicaciC3n deberC! presentar la lista de almenos 7 jugadores de forma desordenada. Crear las Clases 
  correspondientes en el fichero (.java).

-------------------------------------------------------------------------------
*/

//importar las librerias correspondientes
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

// Se crea una clase Jugador: la cual facilitara el tratamiento de datos.
class Jugador
{
  // Atributos
  private String Nombre;
  private int Edad;
  private int ELO;
  private int ValorPremio;
//Se necesita un constructor para reconocer datos inicales
  public Jugador (String nombre, int edad, int elo, int valorPremio)
  {
    this.Nombre = nombre;
    this.Edad = edad;
    this.ELO = elo;
    this.ValorPremio = valorPremio;
  }
// Se necesita capturar el nombre
  public String getNombre ()
  {
    return Nombre;
  }
// Se necesita capturar la edad
  public int getEdad ()
  {
    return Edad;
  }
// Se necesita capturar el elo
  public int getElo ()
  {
    return ELO;
  }
// Se necesita capturar el valorPremio
  public int getValorPremio ()
  {
    return ValorPremio;
  }
// Se necesita Ingresar el nombre
  public void setNombre (String nombre)
  {
    this.Nombre = nombre;
  }
// Se necesita Ingresar la edad
  public void setEdad (int edad)
  {
    this.Edad = edad;
  }
// Se necesita Ingresar el elo
  public void setElo (int elo)
  {
    this.ELO = elo;
  }
// Se necesita Ingresar el valorPremio
  public void setValorPremio (int valorPremio)
  {
    this.ValorPremio = valorPremio;
  }
// Se quiere imprimir los datos contenidos en el objeto
  public String presentarDatos ()
  {
    return "[" + getNombre () + ", " + getEdad () + ", " + getElo () + ", " +
      getValorPremio () + "]";
  }

}				//Fin de la clase Jugador

/*Se requiere crear una clase para COMPARAR la edad del Jugador
 *Se implementa usando la clase "Comparator"
 */

//La idea principal es ordenar los objetos de acuerdo a la edad
class CompararEdad implements Comparator < Jugador >
{
  //Se implementa el metodo que devuelva el orden de acuerdo a la edad
  public int compare (Jugador player01, Jugador player02)
  {
    return player01.getEdad () - player02.getEdad ();
  }
}
class CompararElo implements Comparator < Jugador >
{
  //Se implementa el metodo que devuelva el orden de acuerdo al ELO
  public int compare (Jugador player01, Jugador player02)
  {
    return player01.getElo () - player02.getElo ();
  }
}
class CompararValorPremio implements Comparator < Jugador >
{
  //Se implementa el metodo que devuelva el orden de acuerdo al valor del premio
  public int compare (Jugador player01, Jugador player02)
  {
    return player01.getValorPremio () - player02.getValorPremio ();
  }
}

 // Se hace la clase principal, que tendrC! listas de Jugadores (Arrays)
public class Registro
{
  public static void main (String[]args)
  {
    //Se crean unos empleados para jugar (arreglo)
    ArrayList < Jugador > listaJugadores = new ArrayList < Jugador > ();
    // Se llena la lista con jugadores
    listaJugadores.add (new Jugador ("Daniel", 15, 24, 300));
    listaJugadores.add (new Jugador ("Gabriela", 34, 56, 19));
    listaJugadores.add (new Jugador ("Laura", 23, 66, 154));
    listaJugadores.add (new Jugador ("Cristian", 50, 43, 93));
    listaJugadores.add (new Jugador ("Juan", 16, 55, 156));
    listaJugadores.add (new Jugador ("Jose)", 18, 5, 555));
    listaJugadores.add (new Jugador ("Julian", 19, 78, 150));
    System.out.println ("[Nombre, Edad, ELO, Premio]");
    System.out.println ("Lista de Jugadores sin ordenar");

    for (Jugador jugador:listaJugadores)
      {
	System.out.println (jugador.presentarDatos ());
      }
    System.out.println ();
    // se presenta la lista ordenada segC:n la edad usando comparator 
    Collections.sort (listaJugadores, new CompararEdad ());
    System.out.println ("Lista de jugadores ordenada segun Edad");
  for (Jugador jugador:listaJugadores)
      {
	System.out.println (jugador.presentarDatos ());
      }
    System.out.println ();
    // se presenta la lista ordenada segC:n el ELO usando comparator 
    Collections.sort (listaJugadores, new CompararElo ());
    System.out.println ("Lista de empleados ordenada segun ELO");
  for (Jugador jugador:listaJugadores)
      {
	System.out.println (jugador.presentarDatos ());
      }
    System.out.println ();
    // se presenta la lista ordenada segun el valor del premio usando comparator 
    Collections.sort (listaJugadores, new CompararValorPremio ());
    System.out.
      println ("Lista de empleados ordenada segun valor del Premio");
  for (Jugador jugador:listaJugadores)
      {
	System.out.println (jugador.presentarDatos ());
      }
  }
}//Fin clase principal Regitro
