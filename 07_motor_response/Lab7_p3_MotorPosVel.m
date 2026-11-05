% Part 3: Plot motor position and velocity data
% Lab7_p3_MotorPosVel.m

%% Load data from external and serial modes
close all;
clear;
load ext_data_USB_p3;
load serial_data_USB_p3;

%% Obtain motor position from external mode:
figure(1);
plot(Pos); 
axis([0 800 -500 4000]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Position (unit to be determined)');
legend('Data from external mode');
title('Motor Postion');grid;

%% Obtain motor velocity from external mode:
Vel_smooth=smooth(double(Vel), 10);
figure(2);
plot(Vel); hold on;
plot(Vel_smooth,'r'); hold off;
axis([0 800 -50 50]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Raw Data from external mode','Smoothed Data');
title('Motor Velocity');grid;

%% Obtain motor velocity from serial mode:
figure(3);
plot(Vel_serial,'k');
axis([0 800 -40 40]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Data from serial port');
title('Motor Speed');grid;

