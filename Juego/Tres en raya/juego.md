<!--
- Valentina Sandoval A.
- Juego: Tres en Raya
-->

# Juego: Tres en Raya

El código proporcionado implementa el juego clásico de Tres en Raya (también conocido como Tic-Tac-Toe) en Java. Aquí está la descripción de cómo funciona y las mejoras realizadas:

## Funcionamiento del código

1. Al ejecutar el programa, se crea un objeto `TresEnRaya` y se llama al método `jugar()` para iniciar el juego.
2. Se muestra un mensaje de bienvenida y se le pregunta al jugador si desea jugar contra la computadora.
3. Dependiendo de la respuesta del jugador, se establece el modo de juego (`modoJuegoContraComputadora`) como `true` o `false`.
4. El juego se lleva a cabo en un bucle infinito. En cada iteración del bucle, se muestra el tablero actual y se solicita el movimiento al jugador actual.
5. Si el modo de juego es contra la computadora y es el turno del jugador O, se llama al método `hacerMovimientoComputadora()` para realizar un movimiento aleatorio.
6. Si el modo de juego es de dos jugadores o es el turno del jugador X, se solicita al jugador que ingrese la fila y columna del movimiento a realizar.
7. Se verifica si el movimiento es válido y se realiza en el tablero utilizando el método `realizarMovimiento()`.
8. Después de cada movimiento, se verifica si hay un ganador utilizando el método `hayGanador()`. Si hay un ganador, se muestra el tablero y se muestra un mensaje de felicitación.
9. Si no hay ganador, se verifica si hay un empate utilizando el método `hayEmpate()`. Si hay empate, se muestra el tablero y se muestra un mensaje de empate.
10. En cada iteración, se cambia al siguiente jugador utilizando el método `cambiarJugador()`.
11. El juego continúa hasta que haya un ganador o un empate.

## Mejoras realizadas

1. Se han agregado constantes (`VACIO`, `JUGADOR_X`, `JUGADOR_O`) para representar los valores utilizados en el juego. Esto mejora la legibilidad del código y facilita la modificación de los valores en un solo lugar.
2. Se ha agregado la opción de jugar contra la computadora. Al inicio del juego, se le pregunta al jugador si desea jugar contra la computadora. Si selecciona "S" (sí), se activa el modo de juego contra la computadora. Durante el turno del jugador O, la computadora realiza un movimiento aleatorio utilizando el método `hacerMovimientoComputadora()`. Esto brinda la opción de jugar solo o contra la computadora.
