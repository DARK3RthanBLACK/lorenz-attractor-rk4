
% Skipping the first row (header)
data = readmatrix('lorenz_data.csv');

% Extract columns
t = data(:, 1);
x = data(:, 2);
y = data(:, 3);
z = data(:, 4);

% Create the 3D Phase Portrait
figure('Name', 'Lorenz Attractor Phase Portrait', 'Color', 'w');
plot3(x, y, z, 'b-', 'LineWidth', 0.5);
grid on;

% Styling and Labels
title('Lorenz Attractor simulated via C++ (RK4)');
xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');

% Adjust the viewing angle for the best presentation
view(45, 30);