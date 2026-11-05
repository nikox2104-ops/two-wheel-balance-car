% Part 1: Plot motor position and velocity data
% Lab7_p1_MotorPosVel.m

%%
close all;
clear;
load ext_data_USB;
% The above data file is obtained by first running the Simulink model with
% Switch @ 1-position and Switch1 @ 0-position; then change Switch to @ 0-
% position; wait for a while; and then change Switch1 to @ 1-position;
% after running for a while, stop the model.
figure(1); plot(Pos);
xlabel('Sample (sampling interval = 0.03s)');
ylabel('Position (unit not determined)');
title('Motor Position');grid

figure(2); plot(Vel);
xlabel('Sample (sampling interval = 0.03s)');
ylabel('Speed (unit not determined)');
title('Motor Speed');grid;

%% Obtain motor step response:
Vel_smooth=smooth(double(Vel), 10);
figure(3);
plot(Vel); hold on;
plot(Vel_smooth,'r'); hold off;
axis([400 700 -10 60]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Raw Data','Smoothed Data');
title('Motor Step Response');grid;
