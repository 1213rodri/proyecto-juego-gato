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

void gotoxy(int row, int col) {
    cout << "\x1b[" << row << ";" << col << "H";
}

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
    cout << "   • Virginia " << endl;
    
    cout << "\n📅 Fecha: " << __DATE__ << endl;
    cout << "\n🎮 Version: 1.0.0" << endl;
    
    cout << "\n¡Gracias por jugar!" << endl;
}

#define BLOQUE_GRUESO "\u2588"
#define ESPACIO_VACIO " "

void simularBarraProgreso(int duracionMs, int longitudBarra) {
    const int PASOS_TOTALES = 100;
    
    std::cout << "";
    int tiempoPorPaso = duracionMs / PASOS_TOTALES;

    for (int progreso = 0; progreso <= PASOS_TOTALES; ++progreso) {
        double porcentaje = (double)progreso / PASOS_TOTALES;
        int bloquesLlenos = (int)(porcentaje * longitudBarra);
        int bloquesVacios = longitudBarra - bloquesLlenos;
        int porcentajeVisual = (int)(porcentaje * 100);
        gotoxy(19, 3);
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

// ============================================
// ESTRUCTURAS
// ============================================

struct Jugador {
    string nombre;
    char simbolo;
    bool esHumano;
};

struct Estadisticas {
    int victorias;
    int derrotas;
    int empates;
    int partidasJugadas;
};

// Variable global para la dificultad
int dificultadGlobal = 1;

// ============================================
// FUNCIONES DEL TABLERO
// ============================================

void inicializarTablero(char tablero[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(char tablero[3][3]) {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << "  ";
        for(int j = 0; j < 3; j++) {
            cout << " " << tablero[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "  ---|---|---" << endl;
    }
    cout << "\n";
}

bool tableroLleno(char tablero[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// ============================================
// FUNCIONES DE VERIFICACIÓN
// ============================================

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

bool verificarGanador(char tablero[3][3], char simbolo) {
    return verificarFilas(tablero, simbolo) || 
           verificarColumnas(tablero, simbolo) || 
           verificarDiagonales(tablero, simbolo);
}

// ============================================
// FUNCIONES DE VALIDACIÓN
// ============================================

bool validarEntradaNumerica(int& valor) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\n❌ Error: Debes ingresar un numero." << endl;
        return false;
    }
    return true;
}

bool validarRango(int valor, int min, int max) {
    if(valor < min || valor > max) {
        cout << "\n❌ Error: Debe estar entre " << min << " y " << max << "." << endl;
        return false;
    }
    return true;
}

bool movimientoValido(char tablero[3][3], int fila, int columna) {
    if(fila < 0 || fila > 2 || columna < 0 || columna > 2) {
        cout << "\n❌ Posicion fuera del tablero." << endl;
        return false;
    }
    
    if(tablero[fila][columna] != ' ') {
        cout << "\n❌ Esa casilla ya esta ocupada." << endl;
        return false;
    }
    
    return true;
}

// ============================================
// FUNCIONES DE IA
// ============================================

void movimientoIAFacil(char tablero[3][3], char simbolo) {
    int fila, columna;
    
    do {
        fila = rand() % 3;
        columna = rand() % 3;
    } while(tablero[fila][columna] != ' ');
    
    tablero[fila][columna] = simbolo;
    cout << "\n🤖 IA juega en: (" << (fila + 1) << ", " << (columna + 1) << ")" << endl;
}

bool intentarGanar(char tablero[3][3], char simbolo) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                tablero[i][j] = simbolo;
                
                if(verificarGanador(tablero, simbolo)) {
                    cout << "\n🧠 IA juega en: (" << (i + 1) << ", " << (j + 1) << ")" << endl;
                    return true;
                }
                
                tablero[i][j] = ' ';
            }
        }
    }
    return false;
}

bool bloquearOponente(char tablero[3][3], char simboloIA, char simboloOponente) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                tablero[i][j] = simboloOponente;
                
                if(verificarGanador(tablero, simboloOponente)) {
                    tablero[i][j] = simboloIA;
                    cout << "\n🛡️  IA bloquea en: (" << (i + 1) << ", " << (j + 1) << ")" << endl;
                    return true;
                }
                
                tablero[i][j] = ' ';
            }
        }
    }
    return false;
}

void movimientoIADificil(char tablero[3][3], char simboloIA, char simboloOponente) {
    if(intentarGanar(tablero, simboloIA)) return;
    
    if(bloquearOponente(tablero, simboloIA, simboloOponente)) return;
    
    if(tablero[1][1] == ' ') {
        tablero[1][1] = simboloIA;
        cout << "\n🎯 IA toma el centro: (2, 2)" << endl;
        return;
    }
    
    int esquinas[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for(int i = 0; i < 4; i++) {
        int fila = esquinas[i][0];
        int col = esquinas[i][1];
        if(tablero[fila][col] == ' ') {
            tablero[fila][col] = simboloIA;
            cout << "\n📐 IA toma esquina: (" << (fila + 1) << ", " << (col + 1) << ")" << endl;
            return;
        }
    }
    
    movimientoIAFacil(tablero, simboloIA);
}

// ============================================
// FUNCIÓN PRINCIPAL DE JUEGO
// ============================================

void jugarPartida(char tablero[3][3], Jugador& j1, Jugador& j2, Estadisticas& stats) {
    inicializarTablero(tablero);
    bool juegoTerminado = false;
    int turnoActual = 0;
    
    while(!juegoTerminado) {
        system("clear");
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║          🎮 JUEGO DEL GATO         ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        mostrarTablero(tablero);
        
        Jugador& actual = (turnoActual == 0) ? j1 : j2;
        
        cout << "\n🎲 Turno de: " << actual.nombre << " (" << actual.simbolo << ")" << endl;
        
        if(actual.esHumano) {
            int fila, columna;
            bool movimientoExitoso = false;
            
            while(!movimientoExitoso) {
                cout << "\nIngresa fila (1-3): ";
                cin >> fila;
                
                if(!validarEntradaNumerica(fila)) continue;
                if(!validarRango(fila, 1, 3)) continue;
                
                cout << "Ingresa columna (1-3): ";
                cin >> columna;
                
                if(!validarEntradaNumerica(columna)) continue;
                if(!validarRango(columna, 1, 3)) continue;
                
                fila--;
                columna--;
                
                if(movimientoValido(tablero, fila, columna)) {
                    tablero[fila][columna] = actual.simbolo;
                    movimientoExitoso = true;
                }
            }
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
        
        if(verificarGanador(tablero, actual.simbolo)) {
            system("clear");
            cout << "\n╔════════════════════════════════════╗" << endl;
            cout << "║          🏆 ¡VICTORIA!             ║" << endl;
            cout << "╚════════════════════════════════════╝" << endl;
            
            mostrarTablero(tablero);
            
            cout << "\n🎉 ¡" << actual.nombre << " ha ganado!" << endl;
            
            if(turnoActual == 0) {
                stats.victorias++;
            } else {
                stats.derrotas++;
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
            juegoTerminado = true;
        }
        
        turnoActual = 1 - turnoActual;
    }
    
    stats.partidasJugadas++;
}

// ============================================
// MODOS DE JUEGO
// ============================================

void modoJugadorVsJugador(Estadisticas& stats) {
    char tablero[3][3];
    Jugador j1, j2;
    
    j1.esHumano = true;
    j2.esHumano = true;
    
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
    
    jugarPartida(tablero, j1, j2, stats);
}

void modoJugadorVsIA(Estadisticas& stats, int dificultad) {
    char tablero[3][3];
    Jugador j1, j2;
    
    dificultadGlobal = dificultad;
    
    j1.esHumano = true;
    j2.esHumano = false;
    
    system("clear");
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║      🤖 JUGADOR VS IA              ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\nTu nombre: ";
    cin >> j1.nombre;
    
    j2.nombre = (dificultad == 1) ? "IA Facil" : "IA Dificil";
    
    j1.simbolo = 'X';
    j2.simbolo = 'O';
    
    jugarPartida(tablero, j1, j2, stats);
}

// ============================================
// ESTADÍSTICAS
// ============================================

void mostrarEstadisticas(Estadisticas stats) {
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║        📊 ESTADISTICAS             ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    
    cout << "\n📈 Partidas jugadas: " << stats.partidasJugadas << endl;
    cout << "🏆 Victorias: " << stats.victorias << endl;
    cout << "💀 Derrotas: " << stats.derrotas << endl;
    cout << "🤝 Empates: " << stats.empates << endl;
    
    if(stats.partidasJugadas > 0) {
        float porcentaje = ((float)stats.victorias / stats.partidasJugadas) * 100;
        cout << "\n✨ Porcentaje de victorias: " << fixed << setprecision(1) << porcentaje << "%" << endl;
    }
}

void reiniciarEstadisticas(Estadisticas& stats) {
    char confirmar;
    
    cout << "\n⚠️  ¿Estas seguro de reiniciar las estadisticas? (S/N): ";
    cin >> confirmar;
    
    if(confirmar == 'S' || confirmar == 's') {
        stats.victorias = 0;
        stats.derrotas = 0;
        stats.empates = 0;
        stats.partidasJugadas = 0;
        
        cout << "\n✅ Estadisticas reiniciadas con exito." << endl;
    } else {
        cout << "\n❌ Operacion cancelada." << endl;
    }
}

// ============================================
// INSTRUCCIONES
// ============================================

void mostrarInstrucciones() {
    system("clear");
    
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║        📖 INSTRUCCIONES            ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║        🎮 CÓMO JUGAR               ║" << endl;
    cout << "║                                    ║" << endl;
    cout << "║  - OBJETIVO: Formar 3 en línea     ║" << endl;
    cout << "║  - CÓMO JUGAR:                     ║" << endl;
    cout << "║    Turnos alternados, ingresar fila║" << endl;
    cout << "║    y columna (1-3)                 ║" << endl;
    cout << "║  - CONDICIONES DE VICTORIA:        ║" << endl;
    cout << "║    3 horizontales, verticales o    ║" << endl;
    cout << "║    diagonales                      ║" << endl;
    cout << "║  - EMPATE: Tablero lleno sin       ║" << endl;
    cout << "║    ganador                         ║" << endl;
    cout << "║  - MODOS DE JUEGO:                 ║" << endl;
    cout << "║    PvP, IA Fácil, IA Difícil       ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;
}

// ============================================
// MENÚ PRINCIPAL
// ============================================

void menuPrincipal() {
    int op;
    
    Estadisticas stats;
    stats.victorias = 0;
    stats.derrotas = 0;
    stats.empates = 0;
    stats.partidasJugadas = 0;
    
    srand(time(0));
    
    do {  
        system("clear");
        cout << "\n";
        cout << "  ╔═══════════════════════════════════╗\n";  
        cout << "  ║      🎮 JUEGO DEL GATO 🎮         ║\n";  
        cout << "  ╠═══════════════════════════════════╣\n";  
        cout << "  ║                                   ║\n";  
        cout << "  ║  👥 1. Jugador vs Jugador         ║\n";  
        cout << "  ║  🤖 2. Jugador vs IA (Facil)      ║\n";  
        cout << "  ║  🧠 3. Jugador vs IA (Dificil)    ║\n";  
        cout << "  ║  📖 4. Instrucciones              ║\n";
        cout << "  ║  📊 5. Estadisticas               ║\n";
        cout << "  ║  🔄 6. Reiniciar Stats            ║\n";
        cout << "  ║  ℹ️  7. Creditos                   ║\n";
        cout << "  ║  🚪 8. Salir                      ║\n";
        cout << "  ║                                   ║\n";  
        cout << "  ╠═══════════════════════════════════╣\n";  
        cout << "  ║ Opcion:                           ║\n"; 
        gotoxy(17, 1);
        cout << "  ╚═══════════════════════════════════╝\n\n"; 
        gotoxy(16, 13);
        cin >> op;
        
        switch(op) {
            case 1:
                modoJugadorVsJugador(stats);
                break;
            case 2:
                modoJugadorVsIA(stats, 1);
                break;
            case 3:
                modoJugadorVsIA(stats, 2);
                break;
            case 4:
                mostrarInstrucciones();
                break;
            case 5:
                mostrarEstadisticas(stats);
                break;
            case 6:
                reiniciarEstadisticas(stats);
                break;
            case 7:
                mostrarCreditos();
                break;
            case 8:
                simularBarraProgreso(1000, 30);
                cout << endl;
                cout << "\n  ¡Gracias por jugar! Hasta pronto." << endl;
                break;
            default:
                cout << "\n❌ Opcion invalida. Intenta de nuevo." << endl;
        }
        
        if(op != 8) {
            cout << "\nPresiona Enter para continuar";
            cin.ignore();
            cin.get();
        }
    } while(op != 8);
}

#endif