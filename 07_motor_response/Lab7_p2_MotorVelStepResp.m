% Part 2: Plot motor velocity data
% Lab7_p2_MotorVelStepResp.m

%% Load data from external and serial modes
close all;
clear;
load ext_data_USB_p2;
load serial_data_USB;

%% Obtain motor step response from external mode:
Vel_smooth=smooth(double(Vel), 10);
figure(1);
plot(Vel); hold on;
plot(Vel_smooth,'r'); hold off;
axis([100 350 -10 60]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Raw Data','Smoothed Data');
title('Motor Step Response');grid;

%% Obtain motor step response from serial mode:
figure(2);
plot(Vel_serial,'k');
%axis([400 700 -10 60]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('Data from serial port');
title('Motor Step Response');grid;

%% Align and overlay data from external and serial modes
figure(3);clf;
plot(Vel); hold on;
plot(Vel_smooth,'r'); 
plot([zeros(114,1); Vel_serial],'k');hold off;
axis([100 350 -5 55]);
xlabel('Sample (sampling interval = 0.03 s)');
ylabel('Speed (unit to be determined)');
legend('External Raw Data', ...
       'External Smoothed Data',...
       'Serial Data');
title('Motor Step Responses');grid;
