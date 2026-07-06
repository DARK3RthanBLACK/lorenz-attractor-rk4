#include <iostream>
#include <fstream>
#include <vector>

// Structure to hold our 3D state variables
struct State {
    double x, y, z;
};

// The Lorenz system of differential equations
State lorenz(double t, const State& s) {
    const double sigma = 10.0;
    const double rho = 28.0;
    const double beta = 8.0 / 3.0;

    return {
        sigma * (s.y - s.x),
        s.x * (rho - s.z) - s.y,
        s.x * s.y - beta * s.z
    };
}

// Overload operations to make RK4 math cleaner
State operator+(const State& a, const State& b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
State operator*(double scalar, const State& s) { return {scalar * s.x, scalar * s.y, scalar * s.z}; }

int main() {
    // Simulation parameters
    double dt = 0.01;      // Time step
    int steps = 10000;     // Number of iterations
    double t = 0.0;        // Initial time

    // Initial conditions (slightly off origin to trigger chaos)
    State current_state = {1.0, 1.0, 1.0}; 

    // Open CSV file for MATLAB to read
    std::ofstream outfile("lorenz_data.csv");
    outfile << "t,x,y,z\n"; // CSV Header

    // Runge-Kutta 4th Order Integration Loop
    for (int i = 0; i < steps; ++i) {
        // Log current state
        outfile << t << "," << current_state.x << "," << current_state.y << "," << current_state.z << "\n";

        // RK4 Step calculations
        State k1 = lorenz(t, current_state);
        State k2 = lorenz(t + 0.5 * dt, current_state + (0.5 * dt) * k1);
        State k3 = lorenz(t + 0.5 * dt, current_state + (0.5 * dt) * k2);
        State k4 = lorenz(t + dt, current_state + dt * k3);

        // Update state
        current_state = current_state + (dt / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        t += dt;
    }

    outfile.close();
    std::cout << "Simulation complete. Data written to lorenz_data.csv" << std::endl;
    return 0;
}