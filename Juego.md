# Juego de Tres en Raya

El siguiente código implementa el juego clásico de Tres en Raya, también conocido como Tic-Tac-Toe. El juego se desarrolla en una cuadrícula de 3x3, donde dos jugadores alternan turnos para marcar casillas con sus respectivos símbolos ('X' y 'O'). El objetivo del juego es lograr una línea horizontal, vertical o diagonal de tres símbolos iguales antes que el oponente.

El código está escrito en Java y utiliza la clase `Scanner` para leer la entrada del usuario desde la consola. A continuación, se proporciona una explicación de las diferentes partes del código:

## Clase `TresEnRaya`

### Atributos
- `tablero`: Una matriz bidimensional de caracteres que representa el estado actual del tablero de juego.
- `jugadorActual`: Un carácter ('X' o 'O') que indica el símbolo del jugador actual.

### Constructor
- `TresEnRaya()`: Inicializa el tablero como una matriz de 3x3 y establece el jugador actual como 'X'. Luego, llama al método `inicializarTablero()` para establecer todas las casillas del tablero como vacías ('-').

### Métodos

- `jugar()`: Inicia el juego y contiene el bucle principal del juego. Muestra el tablero, solicita al jugador actual que ingrese la fila y columna para realizar su movimiento, valida el movimiento y actualiza el estado del tablero. Luego, cambia al siguiente jugador y repite el proceso hasta que haya un ganador o empate. Al finalizar el juego, muestra el tablero final y el resultado.

- `inicializarTablero()`: Establece todas las casillas del tablero como vacías ('-').

- `mostrarTablero()`: Muestra el estado actual del tablero en la consola.

- `validarMovimiento(int fila, int columna)`: Verifica si el movimiento realizado por el jugador actual es válido. El movimiento es válido si la casilla está dentro de los límites del tablero y está vacía ('-').

- `hayGanador()`: Comprueba si hay un ganador en el juego. Verifica todas las posibles combinaciones ganadoras en filas, columnas y diagonales.

- `hayEmpate()`: Verifica si el juego ha terminado en empate. Comprueba si todas las casillas del tablero están ocupadas.

- `main(String[] args)`: El punto de entrada del programa. Crea una instancia de la clase `TresEnRaya` y llama al método `jugar()` para iniciar el juego.

El juego de Tres en Raya se ejecuta en un bucle donde los jugadores alternan turnos hasta que haya un ganador o empate. Cada jugador ingresa las coordenadas de la casilla en la que desea marcar ('X' o 'O'). Al finalizar el juego, se muestra el estado final del tablero y el resultado (ganador o empate).

Este código es una implementación básica del juego de Tres en Raya en Java. Puede servir como punto de partida para agregar características adicionales o mejoras al juego.
