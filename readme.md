# 2D Game Engine with Launcher

## Overview

This project is the early stage of developing a 2D game engine using **C++** with a focus on **Data-Oriented Design (DOD)**. The project aims to create a simple game that implements a **Zelda 2D-style dungeon**, putting into practice the concepts learned about **game engine architecture** and **DOD**.

The game engine is being developed with **Visual Studio Community 2022**, and the current build system is managed through a `build.bat` script that compiles the launcher using the Visual Studio `cl` compiler. The launcher will eventually handle dynamic DLL compilation and hot-reloading for rapid iteration.

## Features

- **Data-Oriented Design (DOD)**: Efficient handling of game entities and systems for performance.
- **Launcher**: Compiles the engine into a DLL and dynamically loads it to run the game.
- **Zelda-Style Dungeon**: The game will feature a simple dungeon inspired by classic 2D Zelda games, allowing for real-time exploration and interaction.
- **Hot Reloading (Planned)**: Allows rapid iteration by recompiling the DLL on file changes and reloading it without restarting the engine.

## Requirements

- **Visual Studio Community 2022** (or higher)
- **C++17** (or higher)
- **Windows 10/11**

## Current Project Structure

At the moment, the project is in its early stages, and the folder structure has not yet been fully defined. The project consists of:

```plaintext
/2DEngine
├── build.bat         # Batch script to build the launcher
└── src
    └── /launcher
        └── launcher.cpp   # Source code for the launcher
```

- `build.bat` is responsible for compiling the launcher using the Visual Studio `cl` compiler.
- `launcher.cpp` contains the logic for building and eventually loading the game engine DLL (currently in development).

## How to Build and Run

### Step 1: Install Visual Studio Community 2022

Make sure **Visual Studio Community 2022** is installed with the **Desktop development with C++** workload.

### Step 2: Ensure `cl` Compiler is Configured

The `build.bat` script currently assumes that the `cl` compiler is located at the following path:

```plaintext
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64\cl.exe
```

If your Visual Studio installation is located in a different path or uses a different version, you should modify the `build.bat` script to point to the correct path where `cl.exe` is installed on your system. Alternatively, you can update the script to use Visual Studio's environment setup script (`vcvars64.bat`) to configure the build environment dynamically.

### Step 3: Build the Launcher

1. Open a command prompt.
2. Navigate to the project root directory.
3. Run the `build.bat` script:

```bash
build.bat
```

This will:
- Compile the launcher using the `cl` compiler.
- Run the `launcher.exe` once it is built.

#### `build.bat` contents:

```batch
@echo off
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64\cl.exe" src\launcher\launcher.cpp /Fe:bin\launcher.exe
launcher.exe
```

The `build.bat` script compiles the `launcher.cpp` file and places the resulting executable in the `bin` directory, then runs it.

### Step 4: Future Development

As development progresses, the launcher will be expanded to dynamically compile and load the game engine DLL. Future updates will include implementing the Zelda-style dungeon, expanding the folder structure, and integrating the DLL hot-reloading system.
