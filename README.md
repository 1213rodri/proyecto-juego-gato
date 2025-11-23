# proyecto-juego-gato

<img width="354" height="140" alt="image" src="https://github.com/user-attachments/assets/4ae9d1aa-6f10-4968-8714-395b55c6373d"  /> <img width="545" height="140" alt="image" src="https://github.com/user-attachments/assets/4e616884-5618-4010-be83-8b8eed8a4d65" /> <img width="1028" height="140" alt="image" src="https://github.com/user-attachments/assets/a759901a-06eb-4beb-bff7-b11e395f4ab1" />


📋 Descripción
Proyecto académico que implementa el clásico Juego del Gato (Tic-Tac-Toe) en C++ con funcionalidades avanzadas que incluyen:

🤖 Inteligencia Artificial con dos niveles de dificultad
👥 Modo multijugador local
📊 Sistema de estadísticas
✅ Validación robusta de entradas
🎨 Interfaz de menús intuitiva
📚 Guía interactiva web con Firebase

🎯 Objetivos de Aprendizaje

Manejo de matrices bidimensionales
Implementación de estructuras (structs)
Algoritmos de inteligencia artificial básica
Validación de entrada de usuario
Organización de código mediante funciones modulares
Lógica de juegos y toma de decisiones
Trabajo colaborativo con Git y GitHub


🚀 Características Principales
✨ Funcionalidades del Juego

Tablero 3x3: Implementado con matriz de caracteres
Modo PvP: Dos jugadores humanos
Modo PvIA: Jugador contra computadora
IA Fácil: Movimientos aleatorios
IA Difícil: Algoritmo estratégico que puede:

Intentar ganar detectando oportunidades
Bloquear al oponente
Priorizar posiciones estratégicas (centro y esquinas)


Sistema de Estadísticas: Registro de victorias, derrotas y empates
Validaciones: Control de errores en entradas del usuario

📚 Guía Interactiva Web
Incluye una guía HTML interactiva con:

☁️ Sincronización en la nube con Firebase Firestore
✅ Sistema de progreso con 28 tareas
💾 Guardado automático del progreso
🔄 Acceso multi-dispositivo
🎯 Simulador visual del tablero
📖 Ejemplos de código completos
⚠️ Sección de errores comunes y soluciones
📊 Rúbrica de evaluación


🛠️ Tecnologías Utilizadas
C++ (Código Principal)

Lenguaje: C++11 o superior
Compilador: GCC, MinGW, o Visual Studio
Bibliotecas:

<iostream> - Entrada/salida
<cstdlib> - Funciones aleatorias
<ctime> - Semilla para rand()
<string> - Manejo de cadenas



Web (Guía Interactiva)

Frontend: HTML5, CSS3, JavaScript ES6+
Backend: Firebase Firestore (Base de datos NoSQL)
Módulos: Firebase SDK 10.7.1

📂 Estructura del Proyecto

proyecto-juego-gato/
│
├── src/                      # Código fuente C++
│   ├── main.cpp              # Función principal y menús
│   ├── tablero.cpp           # Funciones del tablero
│   ├── ia.cpp                # Inteligencia artificial
│   ├── validaciones.cpp      # Validaciones de entrada
│   └── estadisticas.cpp      # Sistema de estadísticas
│
├── include/                  # Archivos de cabecera
│   ├── tablero.h
│   ├── ia.h
│   ├── validaciones.h
│   └── estadisticas.h
│
├── docs/                     # Documentación
│   └── index.html            # Guía interactiva web
│
├── assets/                   # Recursos adicionales
│   └── diagrama-flujo.png
│
├── .gitignore               # Archivos ignorados por Git
├── README.md                # Este archivo
└── LICENSE                  # Licencia del proyecto

🔧 Requisitos del Sistema
Para C++

Sistema Operativo: Windows, macOS, o Linux
Compilador:

GCC 7.0+ (Linux/macOS)
MinGW (Windows)
Visual Studio 2017+ (Windows)


RAM: 2 GB mínimo
Espacio: 50 MB

Para la Guía Web

Navegador: Chrome, Firefox, Safari, o Edge (versiones recientes)
Conexión a Internet: Para sincronización con Firebase
JavaScript: Habilitado


📥 Instalación y Configuración
1️⃣ Clonar el Repositorio

# HTTPS
git clone https://github.com/TU_USUARIO/proyecto-juego-gato.git

# SSH
git clone git@github.com:TU_USUARIO/proyecto-juego-gato.git

# Entrar al directorio
cd proyecto-juego-gato

2️⃣ Compilar el Proyecto C++
En Linux/macOS:

# Compilar
g++ -std=c++11 src/*.cpp -o juego_gato

# Ejecutar
./juego_gato

En Windows (MinGW):

# Compilar
g++ -std=c++11 src/*.cpp -o juego_gato.exe

# Ejecutar
juego_gato.exe

En Visual Studio:

Abrir Visual Studio
Archivo → Abrir → Carpeta
Seleccionar la carpeta del proyecto
Presionar F5 para compilar y ejecutar

3️⃣ Configurar Firebase (Para la Guía Web)

Ve a Firebase Console
Crea un nuevo proyecto o usa el existente: proyectogato-f8453
Habilita Firestore Database:

Menú lateral → Firestore Database
Clic en "Crear base de datos"
Selecciona "Iniciar en modo de prueba"
Elige ubicación cercana


Configura las reglas de seguridad:

rules_version = '2';
service cloud.firestore {
  match /databases/{database}/documents {
    match /users/{userId} {
      allow read, write: if true;
    }
  }
}

Abre docs/index.html en tu navegador
Ingresa tu nombre para empezar a usar la guía

🎮 Cómo Usar
Ejecutar el Juego C++

./juego_gato  # Linux/macOS
juego_gato.exe  # Windows
```

**Menú Principal:**
```
╔════════════════════════════════════╗
║     🎮 JUEGO DEL GATO 🎮          ║
╚════════════════════════════════════╝

1. Jugador vs Jugador
2. Jugador vs Computadora
3. Ver Instrucciones
4. Ver Estadísticas
5. Salir

Selecciona una opción: _

Usar la Guía Interactiva

Abre docs/index.html en tu navegador
Ingresa tu nombre de usuario
Navega por las secciones:

📋 Inicio
🏗️ Estructura del programa
✅ Checklist de tareas
📦 Structs
🎯 Implementación del tablero
🏆 Verificar ganador
🤖 Inteligencia artificial
📱 Menús
✔️ Validaciones
⚠️ Errores comunes
📊 Rúbrica


Marca las tareas conforme las completes
Tu progreso se sincronizará automáticamente en Firebase


👥 Trabajo en Equipo
Configuración para Colaboradores

Agregar colaborador en GitHub:

Ve a tu repositorio en GitHub
Settings → Collaborators → Add people
Ingresa el usuario de GitHub de tu compañero


Tu compañero clona el repositorio:

git clone https://github.com/TU_USUARIO/proyecto-juego-gato.git
cd proyecto-juego-gato

Flujo de Trabajo Recomendado

# 📥 ANTES de empezar a trabajar
git pull origin main

# 💻 Trabajas en tu código...

# 📤 DESPUÉS de hacer cambios
git add .
git commit -m "Descripción clara de los cambios"
git push origin main

División de Tareas Sugerida
Desarrollador 1:

main.cpp - Función principal y menús
tablero.cpp - Funciones del tablero
Documentación del código

Desarrollador 2:

ia.cpp - Inteligencia artificial
validaciones.cpp - Validaciones
Pruebas y debugging


📊 Rúbrica de Evaluación (20 puntos)

CriterioPuntosDescripciónTablero 3x32Matriz correctamente implementada y mostradaStructs3Jugador y Estadísticas implementadosVerificar Ganador3Detecta filas, columnas y diagonalesModo PvP2Modo jugador vs jugador funcionalIA Fácil2Movimientos aleatorios válidosIA Difícil3Algoritmo estratégico completoValidaciones2Validación de entradas y movimientosMenús y UX2Sistema de menús e instruccionesCódigo Limpio1Organización y comentarios


🐛 Solución de Problemas
Error: "No se reconoce g++ como comando"
Solución: Instala MinGW (Windows) o GCC (Linux/macOS)
Error: "Firebase not configured"
Solución: Verifica que las credenciales en index.html sean correctas
Error: "Permission denied" en Firebase
Solución: Asegúrate de haber configurado las reglas de Firestore en modo de prueba
Conflictos en Git
Solución:


# Descargar cambios
git pull

# Si hay conflicto, edita el archivo manualmente
# Busca las marcas: <<<<<<< HEAD

# Después de resolver
git add .
git commit -m "Conflicto resuelto"
git push

📖 Documentación Adicional

Guía de C++
Documentación de Firebase
Git Tutorial
Markdown Guide


✅ Checklist de Entrega
Antes de entregar el proyecto, verifica:

 El código compila sin errores
 Todos los modos de juego funcionan
 Las validaciones previenen errores
 La IA difícil es competitiva
 El código está comentado
 El README está actualizado
 La guía web funciona con Firebase
 El repositorio está limpio (sin archivos .exe o .o)
 Se incluye el diagrama de flujo
 La documentación está completa


🤝 Contribuciones
Este es un proyecto académico. Las contribuciones están limitadas a los miembros del equipo.
Miembros del Equipo

Desarrollador 1: [Tu Nombre] - [tu.email@ejemplo.com]
Desarrollador 2: [Nombre Compañero] - [email@ejemplo.com]


📄 Licencia
Este proyecto fue desarrollado con fines educativos para el curso de Programación.
Institución: [Nombre de tu Universidad/Escuela]
Curso: Programación / Fundamentos de Programación
Profesor: [Nombre del Profesor]
Semestre: [Semestre/Año]

📞 Contacto
Si tienes preguntas sobre este proyecto:

📧 Email: [tu.email@ejemplo.com]
🐙 GitHub: @TU_USUARIO


🙏 Agradecimientos

Profesor [Nombre] por la guía y enseñanza
Compañeros de clase por el apoyo
Documentación de C++ y Firebase
Comunidad de Stack Overflow


📅 Historial de Versiones
v1.0.0 (Fecha)

✅ Implementación inicial del tablero
✅ Modo jugador vs jugador
✅ Verificación de ganador

v1.1.0 (Fecha)

✅ IA fácil implementada
✅ Sistema de validaciones

v1.2.0 (Fecha)

✅ IA difícil con estrategia
✅ Sistema de estadísticas

v2.0.0 (Fecha)

✅ Guía interactiva web
✅ Integración con Firebase
✅ Documentación completa


<div align="center">
⭐ Si este proyecto te ayudó, considera darle una estrella ⭐
Hecho con ❤️ por [Tu Nombre] y [Nombre Compañero]
</div>



