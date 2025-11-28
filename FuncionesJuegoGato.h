#ifndef FUNCIONESJUEGOGATO_H
#define FUNCIONESJUEGOGATO_H
#include <cstdlib>
#include <string>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <ctime>
using namespace std;

/*
 * Función: gotoxy
 * Descripción: Mueve el cursor a una posición específica en la terminal
 * Parámetros: row (fila), col (columna)
 */
void gotoxy(int row, int col) {
    cout << "\x1b[" << row << ";" << col << "H";
}

/*
 * Función: mostrarCreditos
 * Descripción: Muestra información del proyecto y desarrolladores
 */
void mostrarCreditos() {
    system("clear");
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║          ℹ️  CREDITOS               ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    cout << "\n📚 Proyecto Academico" << endl;
    cout << "   Curso: Programacion" << endl;
    cout << "   Institucion: Universidad Veracruzana" << endl;
    
    cout << "\n👨‍💻 Desarrolladores:" << endl;
    cout << "   • Rodrigo Nuñez Garcia" << endl;
    
    cout << "\n👨‍🏫 Profesor:" << endl;
    cout << "   • LAGUNES BARRADAS VIRGINIA" << endl;
    
    cout << "\n📅 Fecha: " << __DATE__ << endl;
    cout << "\n🎮 Version: 2.0.0 - Final" << endl;
    
    cout << "\n¡Gracias por jugar!" << endl;
}

#define BLOQUE_GRUESO "\u2588"
#define ESPACIO_VACIO " "

/*
 * Función: simularBarraProgreso
 * Descripción: Muestra una barra de progreso animada en la terminal
 * Parámetros: duracionMs (duración en milisegundos), longitudBarra (longitud de la barra)
 */
void simularBarraProgreso(int duracionMs, int longitudBarra) {
    const int PASOS_TOTALES = 100;
    
    std::cout << "";
    int tiempoPorPaso = duracionMs / PASOS_TOTALES;

    for (int progreso = 0; progreso <= PASOS_TOTALES; ++progreso) {
        double porcentaje = (double)progreso / PASOS_TOTALES;
        int bloquesLlenos = (int)(porcentaje * longitudBarra);
        int bloquesVacios = longitudBarra - bloquesLlenos;
        int porcentajeVisual = (int)(porcentaje * 100);
        gotoxy(8, 1);
        std::cout <<""<<"["; 
        for (int i = 0; i < bloquesLlenos; ++i) {
            std::cout << BLOQUE_GRUESO;
        }

        for (int i = 0; i < bloquesVacios; ++i) {
            std::cout << ESPACIO_VACIO;
        }

        std::cout << "]" << " " << std::setw(1) << porcentajeVisual << "%" << std::flush;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(tiempoPorPaso));
    }
}

/*
 * Estructura: Jugador
 * Descripción: Almacena la información de cada jugador
 * Campos: nombre, simbolo (X u O), esHumano (verdadero si es jugador humano)
 */
struct Jugador {
    string nombre;
    char simbolo;
    bool esHumano;
};

/*
 * Estructura: Estadisticas
 * Descripción: Almacena los 7 contadores de estadísticas del juego
 * Campos: partidasJ1vsJ2, partidasJ1vsCOM, victoriasJ1, victoriasJ2, 
 *         victoriasCOM, empates, canceladas
 */
struct Estadisticas {
    int partidasJ1vsJ2;
    int partidasJ1vsCOM;
    int victoriasJ1;
    int victoriasJ2;
    int victoriasCOM;
    int empates;
    int canceladas;
};

int dificultadGlobal = 1;

/*
 * Función: inicializarTablero
 * Descripción: Inicializa el tablero con números del 1 al 9
 * Parámetros: tablero (matriz 3x3 de caracteres)
 */
void inicializarTablero(char tablero[3][3]) {
    char numero = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tablero[i][j] = numero++;
        }
    }
}

/*
 * Función: mostrarTablero
 * Descripción: Muestra el tablero de juego en pantalla
 * Parámetros: tablero (matriz 3x3 de caracteres)
 */
void mostrarTablero(char tablero[3][3]) {
    cout << "\n╔═══════════════════════════════════╗" << endl;
    cout << "║          TABLERO DE JUEGO         ║" << endl;
    cout << "╚═══════════════════════════════════╝" << endl;
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << "        ";
        for(int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "        ---|---|---" << endl;
    }
    cout << "\n";
}

/*
 * Función: tableroLleno
 * Descripción: Verifica si todas las casillas del tablero están ocupadas
 * Parámetros: tablero (matriz 3x3 de caracteres)
 * Retorna: true si el tablero está lleno, false en caso contrario
 */
bool tableroLleno(char tablero[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] >= '1' && tablero[i][j] <= '9') {
                return false;
            }
        }
    }
    return true;
}

/*
 * Función: verificarFilas
 * Descripción: Verifica si hay tres símbolos iguales en alguna fila
 * Parámetros: tablero (matriz 3x3), simbolo (X u O)
 * Retorna: true si hay tres en línea horizontal, false en caso contrario
 */
bool verificarFilas(char tablero[3][3], char simbolo) {
    for(int i = 0; i < 3; i++) {
        if(tablero[i][0] == simbolo && 
           tablero[i][1] == simbolo && 
           tablero[i][2] == simbolo) {
            return true;
        }
    }
    return false;
}

/*
 * Función: verificarColumnas
 * Descripción: Verifica si hay tres símbolos iguales en alguna columna
 * Parámetros: tablero (matriz 3x3), simbolo (X u O)
 * Retorna: true si hay tres en línea vertical, false en caso contrario
 */
bool verificarColumnas(char tablero[3][3], char simbolo) {
    for(int j = 0; j < 3; j++) {
        if(tablero[0][j] == simbolo && 
           tablero[1][j] == simbolo && 
           tablero[2][j] == simbolo) {
            return true;
        }
    }
    return false;
}

/*
 * Función: verificarDiagonales
 * Descripción: Verifica si hay tres símbolos iguales en alguna diagonal
 * Parámetros: tablero (matriz 3x3), simbolo (X u O)
 * Retorna: true si hay tres en línea diagonal, false en caso contrario
 */
bool verificarDiagonales(char tablero[3][3], char simbolo) {
    if(tablero[0][0] == simbolo && 
       tablero[1][1] == simbolo && 
       tablero[2][2] == simbolo) {
        return true;
    }
    
    if(tablero[0][2] == simbolo && 
       tablero[1][1] == simbolo && 
       tablero[2][0] == simbolo) {
        return true;
    }
    
    return false;
}

/*
 * Función: verificarGanador
 * Descripción: Verifica si un jugador ha ganado (fila, columna o diagonal)
 * Parámetros: tablero (matriz 3x3), simbolo (X u O)
 * Retorna: true si el jugador ganó, false en caso contrario
 */
bool verificarGanador(char tablero[3][3], char simbolo) {
    return verificarFilas(tablero, simbolo) || 
           verificarColumnas(tablero, simbolo) || 
           verificarDiagonales(tablero, simbolo);
}

/*
 * Función: validarEntradaNumerica
 * Descripción: Valida que la entrada del usuario sea numérica
 * Parámetros: valor (referencia al entero a validar)
 * Retorna: true si es válida, false en caso contrario
 */
bool validarEntradaNumerica(int& valor) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n❌ Error: Debes ingresar un numero." << endl;
        return false;
    }
    return true;
}

/*
 * Función: validarRango
 * Descripción: Valida que un valor esté dentro de un rango específico
 * Parámetros: valor (número a validar), min (mínimo), max (máximo)
 * Retorna: true si está en rango, false en caso contrario
 */
bool validarRango(int valor, int min, int max) {
    if(valor < min || valor > max) {
        cout << "\n❌ Error: Debe estar entre " << min << " y " << max << "." << endl;
        return false;
    }
    return true;
}

/*
 * Función: movimientoValido
 * Descripción: Verifica si una posición del tablero está disponible
 * Parámetros: tablero (matriz 3x3), posicion (número 1-9)
 * Retorna: true si la casilla está libre, false si está ocupada
 */
bool movimientoValido(char tablero[3][3], int posicion) {
    int fila = (posicion - 1) / 3;
    int col = (posicion - 1) % 3;
    
    if(tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "\n❌ Esa casilla ya esta ocupada." << endl;
        return false;
    }
    
    return true;
}

/*
 * Función: movimientoIAFacil
 * Descripción: Realiza un movimiento aleatorio para la IA en modo fácil
 * Parámetros: tablero (matriz 3x3), simbolo (X u O)
 */
void movimientoIAFacil(char tablero[3][3], char simbolo) {
    int posicion;
    
    do {
        posicion = (rand() % 9) + 1;
    } while(!movimientoValido(tablero, posicion));
    
    int fila = (posicion - 1) / 3;
    int col = (posicion - 1) % 3;
    
    tablero[fila][col] = simbolo;
    cout << "\n🤖 IA juega en la casilla: " << posicion << endl;
}

/*
 * Función: intentarGanar
 * Descripción: Intenta encontrar una jugada ganadora para la IA
 * Parámetros: tablero (matriz 3x3), simbolo (símbolo de la IA)
 * Retorna: true si encontró jugada ganadora, false en caso contrario
 */
bool intentarGanar(char tablero[3][3], char simbolo) {
    for(int pos = 1; pos <= 9; pos++) {
        if(movimientoValido(tablero, pos)) {
            int fila = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            
            char temp = tablero[fila][col];
            tablero[fila][col] = simbolo;
            
            if(verificarGanador(tablero, simbolo)) {
                cout << "\n🧠 IA juega en la casilla: " << pos << endl;
                return true;
            }
            
            tablero[fila][col] = temp;
        }
    }
    return false;
}

/*
 * Función: bloquearOponente
 * Descripción: Intenta bloquear una jugada ganadora del oponente
 * Parámetros: tablero (matriz 3x3), simboloIA (símbolo de IA), simboloOponente
 * Retorna: true si bloqueó exitosamente, false en caso contrario
 */
bool bloquearOponente(char tablero[3][3], char simboloIA, char simboloOponente) {
    for(int pos = 1; pos <= 9; pos++) {
        if(movimientoValido(tablero, pos)) {
            int fila = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            
            char temp = tablero[fila][col];
            tablero[fila][col] = simboloOponente;
            
            if(verificarGanador(tablero, simboloOponente)) {
                tablero[fila][col] = simboloIA;
                cout << "\n🛡️  IA bloquea en la casilla: " << pos << endl;
                return true;
            }
            
            tablero[fila][col] = temp;
        }
    }
    return false;
}

/*
 * Función: movimientoIADificil
 * Descripción: Realiza movimiento estratégico de la IA en modo difícil
 *              Prioridad: Ganar > Bloquear > Centro > Esquinas > Aleatorio
 * Parámetros: tablero (matriz 3x3), simboloIA, simboloOponente
 */
void movimientoIADificil(char tablero[3][3], char simboloIA, char simboloOponente) {
    if(intentarGanar(tablero, simboloIA)) return;
    
    if(bloquearOponente(tablero, simboloIA, simboloOponente)) return;
    
    if(movimientoValido(tablero, 5)) {
        tablero[1][1] = simboloIA;
        cout << "\n🎯 IA toma el centro: 5" << endl;
        return;
    }
    
    int esquinas[4] = {1, 3, 7, 9};
    for(int i = 0; i < 4; i++) {
        if(movimientoValido(tablero, esquinas[i])) {
            int fila = (esquinas[i] - 1) / 3;
            int col = (esquinas[i] - 1) % 3;
            tablero[fila][col] = simboloIA;
            cout << "\n📐 IA toma esquina: " << esquinas[i] << endl;
            return;
        }
    }
    
    movimientoIAFacil(tablero, simboloIA);
}

/*
 * Función: jugarPartida
 * Descripción: Controla el flujo de una partida completa del juego
 * Parámetros: tablero (matriz 3x3), j1 (jugador 1), j2 (jugador 2),
 *             stats (estadísticas), esVsIA (indica si juega contra IA)
 */
void jugarPartida(char tablero[3][3], Jugador& j1, Jugador& j2, Estadisticas& stats, bool esVsIA) {
    inicializarTablero(tablero);
    bool juegoTerminado = false;
    int turnoActual = 0;
    bool partidaCancelada = false;
    
    while(!juegoTerminado) {
        system("clear");
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║          🎮 JUEGO DEL GATO         ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarTablero(tablero);
        
        Jugador& actual = (turnoActual == 0) ? j1 : j2;
        
        cout << "\n🎲 Turno de: " << actual.nombre << " (" << actual.simbolo << ")" << endl;
        
        if(actual.esHumano) {
            int posicion;
            bool movimientoExitoso = false;
            
            while(!movimientoExitoso) {
                cout << "\nIngresa la posicion (1-9) o 0 para cancelar: ";
                cin >> posicion;
                
                if(!validarEntradaNumerica(posicion)) continue;
                
                if(posicion == 0) {
                    cout << "\n⚠️  Partida cancelada por el jugador." << endl;
                    partidaCancelada = true;
                    juegoTerminado = true;
                    stats.canceladas++;
                    break;
                }
                
                if(!validarRango(posicion, 1, 9)) continue;
                
                if(movimientoValido(tablero, posicion)) {
                    int fila = (posicion - 1) / 3;
                    int col = (posicion - 1) % 3;
                    tablero[fila][col] = actual.simbolo;
                    movimientoExitoso = true;
                }
            }
            
            if(partidaCancelada) break;
            
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            
            if(dificultadGlobal == 1) {
                movimientoIAFacil(tablero, actual.simbolo);
            } else {
                char simboloOponente = (actual.simbolo == 'X') ? 'O' : 'X';
                movimientoIADificil(tablero, actual.simbolo, simboloOponente);
            }
            
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        
        if(partidaCancelada) break;
        
        if(verificarGanador(tablero, actual.simbolo)) {
            system("clear");
            cout << "\n╔════════════════════════════════════╗" << endl;
            cout << "║          🏆 ¡VICTORIA!             ║" << endl;
            cout << "╚════════════════════════════════════╝" << endl;
            
            mostrarTablero(tablero);
            
            cout << "\n🎉 ¡" << actual.nombre << " ha ganado!" << endl;
            
            if(esVsIA) {
                stats.partidasJ1vsCOM++;
                if(turnoActual == 0) {
                    stats.victoriasJ1++;
                } else {
                    stats.victoriasCOM++;
                }
            } else {
                stats.partidasJ1vsJ2++;
                if(turnoActual == 0) {
                    stats.victoriasJ1++;
                } else {
                    stats.victoriasJ2++;
                }
            }
            
            juegoTerminado = true;
            
        } else if(tableroLleno(tablero)) {
            system("clear");
            cout << "\n╔════════════════════════════════════╗" << endl;
            cout << "║          🤝 EMPATE                 ║" << endl;
            cout << "╚════════════════════════════════════╝" << endl;
            
            mostrarTablero(tablero);
            
            cout << "\n😐 ¡Empate! Nadie ha ganado." << endl;
            stats.empates++;
            
            if(esVsIA) {
                stats.partidasJ1vsCOM++;
            } else {
                stats.partidasJ1vsJ2++;
            }
            
            juegoTerminado = true;
        }
        
        turnoActual = 1 - turnoActual;
    }
}

/*
 * Función: modoJugadorVsJugador
 * Descripción: Inicia el modo de juego entre dos jugadores humanos
 * Parámetros: stats (referencia a las estadísticas del juego)
 */
void modoJugadorVsJugador(Estadisticas& stats) {
    char tablero[3][3];
    Jugador j1, j2;
    char jugarOtra;
    
    j1.esHumano = true;
    j2.esHumano = true;
    
    do {
        system("clear");
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║      👥 JUGADOR VS JUGADOR         ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        cout << "\nNombre del Jugador 1 (X): ";
        cin >> j1.nombre;
        cout << "Nombre del Jugador 2 (O): ";
        cin >> j2.nombre;
        
        j1.simbolo = 'X';
        j2.simbolo = 'O';
        
        jugarPartida(tablero, j1, j2, stats, false);
        
        cout << "\n¿Desea jugar otra partida? (S/N): ";
        cin >> jugarOtra;
        
    } while(jugarOtra == 'S' || jugarOtra == 's');
}

/*
 * Función: modoJugadorVsIA
 * Descripción: Inicia el modo de juego entre jugador humano y computadora
 * Parámetros: stats (referencia a las estadísticas del juego)
 */
void modoJugadorVsIA(Estadisticas& stats) {
    char tablero[3][3];
    Jugador j1, j2;
    char jugarOtra;
    int quienEmpieza;
    
    j1.esHumano = true;
    j2.esHumano = false;
    
    do {
        system("clear");
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║      🤖 JUGADOR VS IA              ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        cout << "\nTu nombre: ";
        cin >> j1.nombre;
        
        j2.nombre = (dificultadGlobal == 1) ? "IA Facil" : "IA Dificil";
        
        cout << "\n¿Quien desea que tire primero?" << endl;
        cout << "1. " << j1.nombre << " (Jugador)" << endl;
        cout << "2. " << j2.nombre << " (Computadora)" << endl;
        cout << "Opcion: ";
        cin >> quienEmpieza;
        
        while(quienEmpieza != 1 && quienEmpieza != 2) {
            cout << "❌ Opcion invalida. Ingresa 1 o 2: ";
            cin >> quienEmpieza;
        }
        
        if(quienEmpieza == 1) {
            j1.simbolo = 'X';
            j2.simbolo = 'O';
            jugarPartida(tablero, j1, j2, stats, true);
        } else {
            j2.simbolo = 'X';
            j1.simbolo = 'O';
            jugarPartida(tablero, j2, j1, stats, true);
        }
        
        cout << "\n¿Desea jugar otra partida? (S/N): ";
        cin >> jugarOtra;
        
    } while(jugarOtra == 'S' || jugarOtra == 's');
}

/*
 * Función: mostrarEstadisticas
 * Descripción: Muestra todas las estadísticas del juego en pantalla
 * Parámetros: stats (estructura con las estadísticas)
 */
void mostrarEstadisticas(Estadisticas stats) {
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║        📊 ESTADISTICAS             ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\n📈 Partidas jugadas J1 VS J2: " << stats.partidasJ1vsJ2 << endl;
    cout << "📈 Partidas jugadas J1 VS COM: " << stats.partidasJ1vsCOM << endl;
    cout << "🏆 Partidas ganadas por J1: " << stats.victoriasJ1 << endl;
    cout << "🏆 Partidas ganadas por J2: " << stats.victoriasJ2 << endl;
    cout << "🏆 Partidas ganadas por COM: " << stats.victoriasCOM << endl;
    cout << "🤝 Partidas empatadas: " << stats.empates << endl;
    cout << "⚠️  Partidas canceladas: " << stats.canceladas << endl;
    
    int totalPartidas = stats.partidasJ1vsJ2 + stats.partidasJ1vsCOM;
    
    if(totalPartidas > 0) {
        float porcentajeJ1 = ((float)stats.victoriasJ1 / totalPartidas) * 100;
        cout << "\n✨ Porcentaje de victorias J1: " << fixed << setprecision(1) << porcentajeJ1 << "%" << endl;
    }
}

/*
 * Función: reiniciarEstadisticas
 * Descripción: Reinicia todos los contadores de estadísticas a cero
 * Parámetros: stats (referencia a las estadísticas del juego)
 */
void reiniciarEstadisticas(Estadisticas& stats) {
    char confirmar;
    
    cout << "\n⚠️  ¿Estas seguro de reiniciar las estadisticas? (S/N): ";
    cin >> confirmar;
    
    if(confirmar == 'S' || confirmar == 's') {
        stats.partidasJ1vsJ2 = 0;
        stats.partidasJ1vsCOM = 0;
        stats.victoriasJ1 = 0;
        stats.victoriasJ2 = 0;
        stats.victoriasCOM = 0;
        stats.empates = 0;
        stats.canceladas = 0;
        
        cout << "\n✅ Estadisticas reiniciadas con exito." << endl;
    } else {
        cout << "\n❌ Operacion cancelada." << endl;
    }
}

/*
 * Función: mostrarInstruccionesJuego
 * Descripción: Muestra las instrucciones de cómo se juega el gato
 */
void mostrarInstruccionesJuego() {
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║    📖 INSTRUCCIONES DEL JUEGO      ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\n🎯 OBJETIVO:" << endl;
    cout << "   Ser el primero en formar una linea de 3" << endl;
    cout << "   simbolos iguales (horizontal, vertical" << endl;
    cout << "   o diagonal)" << endl;
    
    cout << "\n📋 COMO SE JUEGA:" << endl;
    cout << "   1. El tablero tiene 9 casillas numeradas" << endl;
    cout << "      del 1 al 9" << endl;
    cout << "   2. El Jugador 1 marca con 'X'" << endl;
    cout << "   3. El Jugador 2 (o IA) marca con 'O'" << endl;
    cout << "   4. Se turnan para elegir una casilla" << endl;
    cout << "   5. Gana quien complete 3 en linea primero" << endl;
    cout << "   6. Si se llena sin ganador: EMPATE" << endl;
    
    cout << "\n⚠️  CONDICIONES:" << endl;
    cout << "   • Puedes cancelar ingresando 0" << endl;
    cout << "   • Las casillas ocupadas no se pueden usar" << endl;
}

/*
 * Función: mostrarInstruccionesPrograma
 * Descripción: Muestra las instrucciones de cómo utilizar el programa
 */
void mostrarInstruccionesPrograma() {
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║   💻 INSTRUCCIONES DEL PROGRAMA    ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\n🎮 MODOS DE JUEGO:" << endl;
    cout << "   • Jugador vs Jugador: Dos humanos" << endl;
    cout << "   • Jugador vs IA: Contra computadora" << endl;
    
    cout << "\n🤖 DIFICULTADES DE LA IA:" << endl;
    cout << "   • Facil: Movimientos aleatorios" << endl;
    cout << "   • Dificil: Estrategia avanzada" << endl;
    cout << "   (bloqueo, ataque, centro, esquinas)" << endl;
    
    cout << "\n📊 ESTADISTICAS:" << endl;
    cout << "   El programa guarda:" << endl;
    cout << "   - Partidas J1 vs J2" << endl;
    cout << "   - Partidas J1 vs COM" << endl;
    cout << "   - Victorias de cada jugador" << endl;
    cout << "   - Empates y canceladas" << endl;
    
    cout << "\n🎯 COMO USAR:" << endl;
    cout << "   1. Selecciona modo desde el menu" << endl;
    cout << "   2. Ingresa los nombres" << endl;
    cout << "   3. Elige casilla (1-9) o 0 para cancelar" << endl;
    cout << "   4. Puedes configurar la dificultad" << endl;
    cout << "   5. Ver estadisticas en cualquier momento" << endl;
}

/*
 * Función: menuInstrucciones
 * Descripción: Muestra el submenú de instrucciones con sus opciones
 */
void menuInstrucciones() {
    int opcion;
    
    do {
        system("clear");
        
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║        📖 INSTRUCCIONES            ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        cout << "\n1. Instrucciones del juego (como se juega)" << endl;
        cout << "2. Instrucciones del programa (como utilizarlo)" << endl;
        cout << "3. Regresar al menu principal" << endl;
        
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                mostrarInstruccionesJuego();
                cout << "\nPresiona Enter para continuar";
                cin.ignore();
                cin.get();
                break;
            case 2:
                mostrarInstruccionesPrograma();
                cout << "\nPresiona Enter para continuar";
                cin.ignore();
                cin.get();
                break;
            case 3:
                break;
            default:
                cout << "\n❌ Opcion invalida." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        
    } while(opcion != 3);
}

/*
 * Función: menuConfigurarDificultad
 * Descripción: Permite al usuario configurar la dificultad de la IA
 */
void menuConfigurarDificultad() {
    int opcion;
    
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║    ⚙️  CONFIGURAR DIFICULTAD        ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\nDificultad actual: " << (dificultadGlobal == 1 ? "Facil" : "Dificil") << endl;
    
    cout << "\nSelecciona la dificultad:" << endl;
    cout << "1. Facil (Movimientos aleatorios)" << endl;
    cout << "2. Dificil (Estrategia avanzada)" << endl;
    
    cout << "\nOpcion: ";
    cin >> opcion;
    
    if(opcion == 1) {
        dificultadGlobal = 1;
        cout << "\n✅ Dificultad establecida en: FACIL" << endl;
    } else if(opcion == 2) {
        dificultadGlobal = 2;
        cout << "\n✅ Dificultad establecida en: DIFICIL" << endl;
    } else {
        cout << "\n❌ Opcion invalida. Dificultad sin cambios." << endl;
    }
    
    cout << "\nPresiona Enter para continuar";
    cin.ignore();
    cin.get();
}

#endif