# High-Performance Differential Equation Solver

This project simulates the Lorenz Attractor (a chaotic system) by solving non-linear ordinary differential equations using a custom C++ engine.

### Architecture
* **C++ Engine (`rk4_lorenz.cpp`):** Implements the Runge-Kutta 4th Order (RK4) numerical integration method to calculate the system's trajectory over time, optimizing for computational speed. Outputs time-step data to a CSV.
* **Visualization (`plot_lorenz.m`):** A MATLAB/Octave script that ingests the C++ data pipeline to render a 3D phase portrait of the chaotic system.

### How to Run
1. Compile the engine: `g++ rk4_lorenz.cpp -o rk4_lorenz -O3`
2. Run the simulation: `./rk4_lorenz`
3. Execute `plot_lorenz.m` to view the 3D phase portrait.
