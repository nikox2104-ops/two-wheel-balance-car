% Part 1: Plot motor position and velocity data
% Lab8_p1_MotorPosVel.m

%% Load data from external and serial modes
close all;
clear;
sim_step_size = 0.03;
load serial_data_USB_1v;
load serial_data_USB_2v;
load serial_data_USB_3v;

%% Obtain motor gain factor K-omega when Vin = 1v:
figure(1);
plot(Vel_serial_1v,'r'); hold on;
plot(Vel_serial_2v,'b');
plot(Vel_serial_3v,'k'); hold off;
axis([0 1000 0 40]);
xlabel('Samples (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Vin = 1v', 'Vin = 2v', 'Vin = 3v');
title('Motor Speed');grid;

%% Convert the speed unit
% Counts per step size to rotations per minute (RPM)
countsPerStep2RPM = (60/sim_step_size)/720;
Vel_per_volts = zeros(3,1);
Vel_per_volts(1) = mean(Vel_serial_1v(101:900)*countsPerStep2RPM);
Vel_per_volts(2) = mean(Vel_serial_2v(101:900)*countsPerStep2RPM);
Vel_per_volts(3) = mean(Vel_serial_3v(101:900)*countsPerStep2RPM);

Volts = (1:3)';
f = fit(Volts, Vel_per_volts,'poly1');
%      Linear model Poly1:
%      f(x) = p1*x + p2
%      Coefficients (with 95% confidence bounds):
%        p1 =       23.85  (-59.92, 107.6)
%        p2 =       2.377  (-178.6, 183.3)

plot(Volts, Vel_per_volts,'*r'); hold on;
Vel_per_volts_fit = f.p1*Volts+f.p2;
plot(Volts, Vel_per_volts_fit); grid; hold off;
xlabel('Input Voltage');
ylabel('Motor Speed (RPM)');
axis([0 4.5 20 80]);

%% Fit to 2nd order polynomial
figure(2);
f = fit(Volts, Vel_per_volts,'poly2');
%      Linear model Poly2:
%     f(x) = p1*x^2 + p2*x + p3
%     Coefficients:
%       p1 =      -11.42
%       p2 =       69.52
%       p3 =      -35.68

plot(Volts, Vel_per_volts,'*r'); hold on;
xv = 1:0.1:3.1;
Vel_per_volts_fit = f.p1*xv.^2+f.p2*xv+f.p3;
plot(xv, Vel_per_volts_fit); grid; hold off;
xlabel('Input Voltage');
ylabel('Motor Speed (RPM)');
axis([0 4.5 20 80]);
