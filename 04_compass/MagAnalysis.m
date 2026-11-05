% Mag Data Analysis

%% Acquire and save the raw data
% save Mag_Data mag;

%% Load and plot the raw data
load Mag_Data;
plot(mag); grid on;
legend('x','y','z');
title('Magnetometer Data');
xlabel('Samples');
ylabel('Magnetometer Data');

%% Extract individual components from the raw data
x_mag = mag(:,1);
y_mag = mag(:,2);

figure;
plot(x_mag, y_mag); grid on;
axis('equal');
xlabel('x');
ylabel('y');

%% Extract oval limits
% max and min values of x and y
% Verify these values by hand on the plot.
xmax = max(x_mag);
xmin = min(x_mag);
ymax = max(y_mag);
ymin = min(y_mag);

% Computer the length of the principal axes
dx = double(xmax-xmin);
dy = double(ymax-ymin);

% coordinates of the center
cx = (xmax+xmin)/2;
cy = (ymax+ymin)/2;

%% Normalize and shift the 'circle' to the origin
x_mag_n = double(x_mag-cx)/dx*2;
y_mag_n = double(y_mag-cy)/dy*2;

%% Plot the normalized and shifted circle
figure
plot(x_mag_n, y_mag_n); grid on;
axis('equal');
xlabel('x');
ylabel('y');
title('Normalized and shifted circle');

%% Calculate the moving direction of the compass in degrees
compass_angle = atan2(y_mag_n,x_mag_n)/pi*180+180;
figure;
plot(compass_angle);grid on;
title('Compass moving directions (heading angles)')
xlabel('Samples')
ylabel('Angles (degrees)');

