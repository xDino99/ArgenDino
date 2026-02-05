# Bienvenido al Repositorio del proyecto ArgenDino

# 🦖 ArgenDino ~ Multi-Game System & Engine

![Platform](https://img.shields.io/badge/Platform-Windows%20x64%20%7C%20ARM64-blue)
![Language](https://img.shields.io/badge/Language-PrimeC%20(C%2B%2B%20Nativo)-orange)
![Year](https://img.shields.io/badge/Year-2026-green)
![Open Source](https://img.shields.io/badge/Open%20Source-%E2%9D%A4-red)
![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)

**ArgenDino** es un ecosistema de desarrollo y ejecución de videojuegos diseñado para Windows. Su núcleo está basado en la filosofía de **máxima legibilidad**, permitiendo crear aplicaciones robustas con una sintaxis simplificada que reduce la fricción entre la lógica del programador y la complejidad del hardware.

---

## 💎 1. El Núcleo: PrimeC Abstraction Layer
La base de todo el proyecto reside en `primec.h`, una biblioteca *header-only* que redefine la experiencia de programar en C++.

* **Sintaxis Natural:** Implementa operadores lógicos humanos como `is`, `and`, `or`, `not` y tipos de datos intuitivos como `str`, `list`, `num` e `integer`.
* **Encapsulamiento de WinAPI:** Gestión simplificada de ventanas, gráficos nativos (GDI) y sonido (`winmm`), eliminando el código repetitivo.
* **Entorno Dual:** Capacidad única para manejar una **Interfaz de Consola** (procesamiento de datos y UI retro) y una **Ventana Gráfica Nativa** simultáneamente.

---

## 🛠️ 2. Componentes del Sistema

### 🦖 Dino Engine
El motor encargado del "corazón" del sistema:
* **Gráficos:** Sistema de herramientas de dibujo de píxeles/rectángulos en la ventana nativa.
* **Audio:** Motor de reproducción asíncrona para efectos de sonido y música ambiente en bucle.
* **Consola:** La tipografía de la terminal (437 IBM Classic) y diferentes estilos de colores para personalizarla.
* **Conhost:** Utiliza una version ligera y optimizada del conhost.exe de Windows incluida en la carpeta contenedora de la build.

### 🚀 ArgenDino Launcher
Un lanzador minimalista con interfaz nativa que te muestra informacion del juego antes de cargarlo.

### 🌐 Dino Web Browser (WebView)
Módulo que simula navegación local (host://home/).

---

## 🧠 3. Filosofía de Desarrollo: "Prime C"
Lo mejor de ArgenDino es que te da toda la potencia de C++ pero con una sintaxis tan clara que parece Python. Es código de C++ aadaptado sin perder el rendimiento.

> **Ecosistema Modular:** No es solo un juego, es una plataforma. Gracias a la simplificación de comandos, se pueden añadir nuevos módulos (`GameType1`, `GameType2`, etc.) de forma rápida y estandarizada.

---

## 📊 4. Estado Actual del Proyecto

| Especificación | Detalle |
| :--- | :--- |
| **Arquitectura** | x64 / ARM64 (traduciendo el x64) |
| **Plataforma** | Windows 10 / Windows 11 |
| **Tecnología** | C++ Nativo v14 (Visual Studio 2026) / Estándar ISO C++ 20 (/std:c++20)|
| **Renderizado** | Dual Mode (Consola 437 IBM + WinAPI GDI) |
| **Abstracción** | 95% del código de usuario basado en PrimeC |
| **Compilador** | Compilador estandar C++ de Visual Studio Community 2026 (en modo nativo) |

---

## 🧰 5. Herramientas utilizadas:

* **Desarrollo:** Visual Studio 2026, VS Code, Python 3.12.9.
* **Recursos:** Resource Hacker (Iconos/Manifests), LibreSprite (Pixel Art).
* **Utilidades:** 7zip, Git.

---

## 👤 6. Desarrollador

Desarrollado por **xDino99**
[Linktree](https://linktr.ee/xDino99)

---
