#include "FuncionesJuegoGato.h"

int main() {
    // Inicializar semilla aleatoria para la IA
    srand(time(0));
    
    // Inicializar estadísticas
    Estadisticas stats = {0, 0, 0, 0, 0, 0, 0};
    
    int opcionMenu;
    bool salir = false;
    
    while(!salir) {
        system("clear");
        
        // ✅ MENÚ PRINCIPAL COMPLETO
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║     🎮 JUEGO DEL GATO - MENU       ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
        
        cout << "\n1. Iniciar partida (Jugador VS Jugador)" << endl;
        cout << "2. Iniciar partida (Jugador VS Computadora)" << endl;
        cout << "3. Mostrar instrucciones" << endl;
        cout << "4. Configurar dificultad de la computadora" << endl;
        cout << "5. Mostrar estadisticas" << endl;
        cout << "0. Salir del programa" << endl;
        
        cout << "\n Dificultad actual: " << (dificultadGlobal == 1 ? "FACIL" : "DIFICIL") << endl;
        
        cout << "\nSelecciona una opcion: ";
        cin >> opcionMenu;
        
        switch(opcionMenu) {
            case 1:
                modoJugadorVsJugador(stats);
                break;
                
            case 2:
                modoJugadorVsIA(stats);
                break;
                
            case 3:
                menuInstrucciones();
                break;
                
            case 4:
                menuConfigurarDificultad();
                break;
                
            case 5:
                mostrarEstadisticas(stats);
                cout << "\nPresiona Enter para continuar";
                cin.ignore();
                cin.get();
                break;
                
            case 0:
                system("clear");
                cout << "\n╔════════════════════════════════════╗" << endl;
                cout << "║        👋 HASTA PRONTO!            ║" << endl;
                cout << "╚════════════════════════════════════╝" << endl;
                cout << "\n🎮 Cerrando programa..." << endl;
                cout << "\n";
                simularBarraProgreso(4000, 30);
                cout << "\n\n";
                cout << "🎮 Gracias por jugar al Gato" << endl;
                cout << "📚 Proyecto de Programacion" << endl;
                cout << "🏫 Universidad Veracruzana\n" << endl;
                salir = true;
                break;
                
            default:
                cout << "\n Opcion invalida. Intenta de nuevo." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
    }
    
    return 0;
}