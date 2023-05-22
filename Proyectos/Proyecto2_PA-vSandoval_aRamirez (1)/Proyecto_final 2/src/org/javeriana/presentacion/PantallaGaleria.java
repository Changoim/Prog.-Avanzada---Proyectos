package org.javeriana.presentacion;

import java.util.InputMismatchException;
import java.util.Scanner;

import org.javeriana.modelo.*;
//Se crea una clase main llamada PantallaGaleria
public class PantallaGaleria {
    public static void main(String[] args) {

        System.out.println("------------------------------------------------------------");
        System.out.println("|        Bienvenido a Galería de Arte Guerrero             |");
        System.out.println("------------------------------------------------------------");


        Scanner sn = new Scanner(System.in);
        boolean salir = false;
        ControlGaleria lista = new ControlGaleria();
        int opcion;
        //Se crean objetos para las clases creadas
        Artista samu = new Artista("Samuel", "25-09-2004", "Colombia", "Estudiante Mecatrónica");
        Artista andres = new Artista("Andres", "17-08-2004", "Colombia", "Trabajador");
        Artista lina = new Artista("Lina", "07-04-2004", "Colombia", "Músico");
        Artista miguel = new Artista("Miguel", "15-06-2004", "Colombia", "Trabajador PUJ");
        Artista vale = new Artista("Valentina", "05-04-2005", "Colombia", "Estudiante de Ingenieria");
        Artista pablo = new Artista("Pablo", "28-09-2004", "Colombia", "Biologo");

        Cliente cata = new Cliente("Catalina", "Carrera 72 # 163", "catalinazarate@gmail.com");
        Cliente saac = new Cliente("Isaac", "Carrera 55 # 26", "isac@gmail.com");
        Cliente nata = new Cliente("Natalia", "Calle 74 # 81", "n_pedraza@gmail.com");

        Obra arquitectura = new Obra("Arquitectura", "Mano alzada", 2019, 500000f, andres);
        Obra puente = new Obra("Puente", "Autocad", 2023, 5000f, samu);
        Obra carros = new Obra("Carros", "Fotografia", 2020, 10000f, miguel);

        Compra a = new Compra("25-07-2023", 200f, cata,puente);
        Compra b = new Compra("26-07-2023", 40000f, saac,carros);
        //Se agregan a la lista creada de ControlGaleria
        lista.registrarCompra(a);
        lista.registrarCompra(b);
        lista.agregarCliente(saac);
        lista.agregarCliente(cata);
        lista.agregarCliente(nata);

        lista.agregarArtista(lina);
        lista.agregarArtista(andres);
        lista.agregarArtista(samu);
        lista.agregarArtista(miguel);
        lista.agregarArtista(vale);
        lista.agregarArtista(pablo);

        lista.agregarObra(arquitectura);
        lista.agregarObra(puente);
        lista.agregarObra(carros);
        //lista.eliminarObra(puente);

        while (!salir) {
            System.out.println("Digite la opción que desea realizar:");
            System.out.println("1. Gestionar Obras");
            System.out.println("2. Gestionar Artistas");
            System.out.println("3. Gestionar Compras");
            System.out.println("4. Gestionar Clientes");
            System.out.println("5. Salir");
            //Se crea una Excepcion para el primer menú
            try {
                System.out.println("Escribe una de las opciones");
                opcion = sn.nextInt();
                 //Se crea el menú principal para la galeria
                switch (opcion) {
                    //Primer caso se dedica a la gestion de obras
                    case 1 -> {
                        System.out.println("Has seleccionado Gestionar Obras");
                        lista.MostrarObra();
                        Scanner sn_obra = new Scanner(System.in);
                        boolean salir2 = false;
                        int opcion_obras;
                        while (!salir2) {
                            System.out.println("Digite la opción que desea realizar en Obras");
                            System.out.println("1. Agregar Obras");
                            System.out.println("2. Eliminar Obras");
                            System.out.println("3. Salir");
                            //Excepcion para
                            try {
                                System.out.println("Escribe una de las opciones");
                                opcion_obras = sn_obra.nextInt();
                                //Menú para la gestión de obras
                                switch (opcion_obras) {
                                    case 1 -> {
                                        Scanner sn_buscar1 = new Scanner(System.in);
                                        System.out.println("Has seleccionado Agregar obra");
                                        System.out.println("Por favor ingrese el título de la obra que desea agregar");
                                        String nombreObra = sn_buscar1.nextLine();
                                        System.out.println("Por favor ingrese la técnica de la obra");
                                        String tecnica = sn_buscar1.nextLine();
                                        System.out.println("Por favor ingrese el año de la obra");
                                        int anio = Integer.parseInt(sn_buscar1.nextLine());
                                        System.out.println("Por favor ingrese el precio");
                                        float precio = Float.parseFloat(sn_buscar1.nextLine());
                                        System.out.println("Por favor ingrese el nombre del artista");
                                        String nomArt = sn_buscar1.nextLine();
                                        Artista artistaExistente = null;
                                        for (Artista artista : lista.getArtistas()) {
                                            if (artista.getNombre().equals(nomArt)) {
                                                artistaExistente = artista;
                                                break;
                                            }
                                        }
                                        Artista art;
                                        if (artistaExistente != null) {
                                            art = artistaExistente;
                                        } else {
                                            System.out.println("por favor ingrese la fecha de nacimiento del artista");
                                            String fech = sn_buscar1.nextLine();
                                            System.out.println("Por favor ingrese la nacionalidad del artista");
                                            String nacionalidad = sn_buscar1.nextLine();
                                            System.out.println("Por favor ingrese la biografía del artista");
                                            String bio1 = sn_buscar1.nextLine();

                                            art = new Artista(nomArt, fech, nacionalidad, bio1);
                                            lista.agregarArtista(art);
                                        }
                                        Obra nuevaObra = new Obra(nombreObra, tecnica, anio, precio, art);
                                        lista.agregarObra(nuevaObra);
                                        System.out.println("---Obra agregada correctamente---");
                                    }
                                    case 2 -> {
                                        //eliminar una obra aquí
                                        Scanner sn_elimObr = new Scanner(System.in);
                                        System.out.println("Has seleccionado Eliminar Obras");
                                        System.out.println("Por favor ingrese el titulo de la obra que desea eliminar");
                                        String nombreObr = sn_elimObr.nextLine();

                                        // Buscar la obra en la lista
                                        Obra obraEliminar = null;
                                        for (Obra obra : lista.getObras()) {
                                            if (obra.getTitulo().equals(nombreObr)) {
                                                obraEliminar = obra;
                                            }
                                        }
                                        if (obraEliminar != null) {
                                            // Eliminar la obra de la lista
                                            lista.eliminarObra(obraEliminar);
                                            System.out.println("Obra eliminada: " + obraEliminar.getTitulo());
                                        } else {
                                            System.out.println("No se encontró ningúna obra con ese titulo.");
                                        }
                                    }
                                    //Salir del menú
                                    case 3 -> salir2 = true;
                                    default -> System.out.println("Solo números entre 1 y 3");
                                }
                            } catch (InputMismatchException e) {
                                System.out.println("Selección incorrecta");
                                System.out.println("Por favor ingresa un número entre 1 y 3");
                                sn_obra.next();
                            }
                        }
                    }
                    //Segundo caso se dedica a la gestion de Artistas
                    case 2 -> {
                        System.out.println("Has seleccionado Gestionar Artistas");
                        lista.MostrarArtista();
                        Scanner sn_artista = new Scanner(System.in);
                        boolean salir3 = false;
                        int opcion_artistas;
                        while (!salir3) {
                            System.out.println("Digite la opción que desea realizar en Artistas");
                            System.out.println("1. Agregar Artista");
                            System.out.println("2. Eliminar Artista");
                            System.out.println("3. Salir");
                            //Excepcion
                            try {
                                System.out.println("Escribe una de las opciones");
                                opcion_artistas = sn_artista.nextInt();
                                //Menú para la gestión de Artistas
                                switch (opcion_artistas) {
                                    case 1 -> {
                                        Scanner sn_buscar = new Scanner(System.in);
                                        System.out.println("Has seleccionado Agregar Artista");
                                        System.out.println("Por favor ingrese el nombre del artista que desea agregar");
                                        String nombreArtista = sn_buscar.nextLine();
                                        System.out.println("Por favor ingrese la fehca de nacimiento del artista");
                                        String fechaNac = sn_buscar.nextLine();
                                        System.out.println("Por favor ingrese la nacionalidad del artista ");
                                        String nacionalidad = sn_buscar.nextLine();
                                        System.out.println("Por favor ingrese la biografia del artista");
                                        String bio = sn_buscar.nextLine();

                                        // Crear un objeto Artista con el nombre ingresado
                                        Artista nuevoArtista = new Artista(nombreArtista, fechaNac, nacionalidad, bio);

                                        // Luego, puedes agregar el artista a la lista
                                        lista.agregarArtista(nuevoArtista);
                                        System.out.println("---Artista agregado correctamente---");
                                    }
                                    case 2 -> {
                                        Scanner sn_elimArt = new Scanner(System.in);
                                        System.out.println("Has seleccionado Eliminar Artista");
                                        System.out.println("Por favor ingrese el nombre del artista que desea eliminar");
                                        String nombreArt = sn_elimArt.nextLine();

                                        // Buscar el artista en la lista
                                        Artista artistaEliminar = null;
                                        for (Artista artista : lista.getArtistas()) {
                                            if (artista.getNombre().equals(nombreArt)) {
                                                artistaEliminar = artista;
                                                break;
                                            }
                                        }
                                        if (artistaEliminar != null) {
                                            // Eliminar el artista de la lista
                                            lista.eliminarArtista(artistaEliminar);
                                            System.out.println("Artista eliminado: " + artistaEliminar.getNombre());
                                        } else {
                                            System.out.println("No se encontró ningún artista con ese nombre.");
                                        }
                                    }
                                    case 3 -> salir3 = true;
                                    default -> System.out.println("Solo números entre 1 y 3");
                                }
                            } catch (InputMismatchException e) {
                                System.out.println("Selección incorrecta");
                                System.out.println("Por favor ingresa un número entre 1 y 3");
                                sn_artista.next();
                            }
                        }
                    }
                    //Tercer caso para gestionar las compras
                    case 3 -> {
                        System.out.println("Has seleccionado Gestionar Compras");
                        System.out.println();
                        System.out.println("A continuacion se muestran las Obras disponibles: ");
                        System.out.println();
                        lista.MostrarObra();
                        Scanner sn_compra = new Scanner(System.in);
                        boolean salir4 = false;
                        int opcion_compras;
                        while (!salir4) {
                            System.out.println("Digite la opción que desea realizar en Compras");
                            System.out.println("1. Realizar Compra");
                            System.out.println("2. Mostrar Compras");
                            System.out.println("3. Salir");
                            //Excepcion para el caso 3
                            try {
                                System.out.println("Escribe una de las opciones");
                                opcion_compras = sn_compra.nextInt();
                                //Menú del caso 3
                                switch (opcion_compras) {
                                    case 1 -> {
                                        //agregar una compra aquí
                                        Scanner sn_buscar4 = new Scanner(System.in);
                                        System.out.println("Has seleccionado Realizar Compra");
                                        System.out.println("Por favor ingrese la fecha de la compra");
                                        String fechaObr = sn_buscar4.nextLine();
                                        System.out.println("Por favor ingrese el valor de la compra");
                                        float precio = Float.parseFloat(sn_buscar4.nextLine());
                                        System.out.println("Por favor ingrese el nombre del cliente");
                                        String nomClient = sn_buscar4.nextLine();
                                        Cliente clienteExistente = null;
                                        for (Cliente cliente : lista.getClientes()) {
                                            if (cliente.getNombre().equals(nomClient)) {
                                                clienteExistente = cliente;
                                                break;
                                            }
                                        }
                                        Cliente clt;
                                        if (clienteExistente != null) {
                                            clt = clienteExistente;
                                        } else {
                                            System.out.println("por favor ingrese el correo");
                                            String correoC = sn_buscar4.nextLine();
                                            System.out.println("Por favor ingrese la direccion");
                                            String dirC = sn_buscar4.nextLine();

                                            clt = new Cliente(nomClient, dirC, correoC);
                                            lista.agregarCliente(clt);
                                        }
                                        System.out.println("Por favor ingrese el titulo de la obra");
                                        String titulo = sn_buscar4.nextLine();
                                        Obra obraExistente = null;
                                        for (Obra obra : lista.getObras()) {
                                            if (obra.getTitulo().equals(titulo)) {
                                                obraExistente = obra;
                                                break;
                                            }
                                        }
                                        Obra obr = obraExistente;
                                        if (obr != null) {
                                            System.out.println("---Compra exitosa---");
                                            Compra nuevaCompra = new Compra(fechaObr, precio, clt, obr);
                                            lista.registrarCompra(nuevaCompra);

                                        } else {
                                            System.out.println("Obra no encontrada");
                                        }

                                    }
                                    case 2 -> {
                                        System.out.println("A continuacion las Compras realizadas: ");
                                        lista.MostrarCompra();
                                    }
                                    //Mostrar compras aquí
                                    case 3 -> salir4 = true;
                                    default -> System.out.println("Solo números entre 1 y 3");
                                }
                            } catch (InputMismatchException e) {
                                System.out.println("Selección incorrecta");
                                System.out.println("Por favor ingresa un número entre 1 y 3");
                                sn_compra.next();
                            }
                        }
                    }
                    case 4 -> {
                        System.out.println("Has seleccionado Gestionar Clientes");
                        lista.MostrarCliente();
                        Scanner sn_cliente = new Scanner(System.in);
                        boolean salir5 = false;
                        int opcion_clientes;
                        while (!salir5) {
                            System.out.println("Digite la opción que desea realizar en Clientes");
                            System.out.println("1. Agregar Cliente");
                            System.out.println("2. Eliminar Cliente");
                            System.out.println("3. Salir");
                            //Se crea una excepción para el caso 5
                            try {
                                System.out.println("Escribe una de las opciones");
                                opcion_clientes = sn_cliente.nextInt();
                                //Se crea menú para la gestion de clientes
                                switch (opcion_clientes) {
                                    case 1 -> {
                                        Scanner sn_buscar3 = new Scanner(System.in);
                                        System.out.println("Has seleccionado Agregar Cliente");
                                        System.out.println("Por favor ingrese el nombre del cliente que desea agregar");
                                        String nomcliente = sn_buscar3.nextLine();
                                        System.out.println("Por favor ingrese la direccion");
                                        String dir = sn_buscar3.nextLine();
                                        System.out.println("Por favor ingrese el correo");
                                        String correo = sn_buscar3.nextLine();


                                        // Crear un objeto cliente con el nombre ingresado
                                        Cliente nuevoCliente = new Cliente(nomcliente, dir, correo);

                                        // Luego, puedes agregar el cliente a la lista
                                        lista.agregarCliente(nuevoCliente);
                                        System.out.println("---Cliente agregado correctamente---");
                                    }
                                    case 2 -> {
                                        Scanner sn_elimCliente = new Scanner(System.in);
                                        System.out.println("Has seleccionado Eliminar Cliente");
                                        System.out.println("Por favor ingrese el nombre del cliente que desea eliminar");
                                        String nombreCliente = sn_elimCliente.nextLine();

                                        // Buscar el cliente en la lista
                                        Cliente clienteEliminar = null;
                                        for (Cliente cliente : lista.getClientes()) {
                                            if (cliente.getNombre().equals(nombreCliente)) {
                                                clienteEliminar = cliente;
                                                break;  //salir del bucle una vez que se encuentra el cliente
                                            }
                                        }
                                        if (clienteEliminar != null) {
                                            // Eliminar el cliente de la lista
                                            lista.eliminarCliente(clienteEliminar);
                                            System.out.println("Cliente eliminado: " + clienteEliminar.getNombre());
                                        } else {
                                            System.out.println("No se encontró ningún cliente con ese nombre.");
                                        }
                                    }
                                    case 3 -> salir5 = true;
                                    default -> System.out.println("Solo números entre 1 y 3");
                                }
                            } catch (InputMismatchException e) {
                                System.out.println("Selección incorrecta");
                                System.out.println("Por favor ingresa un número entre 1 y 3");
                                sn_cliente.next();
                            }
                        }
                    }
                    //Quinto Caso para salir del programa.
                    case 5 -> salir = true;
                    default -> System.out.println("Solo números entre 1 y 5");
                }
            } catch (InputMismatchException e) {
                System.out.println("Selección incorrecta");
                System.out.println("Por favor ingresa un número entre 1 y 5");
                sn.next();
            }
        }
    }
}