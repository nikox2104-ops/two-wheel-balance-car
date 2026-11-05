% motor_simulation_run.m:
% Script to run motor_simulation.slx

clear all; close all;
%% Load motor parameters
motor_parameters;

%% Simulation parameters
Tsim_final = 0.5;
TS = 0.03;
sim_step_size = TS;

%% Invoke (run) the Simulink model
sim('motor_sim_impairments');

%% Plot the simulated motor step responses
figure(1);
h1 = plot(tsim,Omega_c*RADSEC2RPM,'r'); hold on;
h2 = plot(tsim,Omega_d*Counts2RAD/TS*RADSEC2RPM,'--');

%% Change the step size
TS = 0.015;
sim_step_size = TS;

%% Invoke (run) the Simulink model
sim('motor_sim_impairments');

%% Plot the motor step responses with no friction
h3 = plot(tsim,Omega_d*Counts2RAD/TS*RADSEC2RPM,'k.-');
xlabel('Time (seconds)'); 
ylabel('Angular velocity (RPM) with 4.5v step input');
legend([h1 h2 h3],...
       {'Continuos time',...
        'Discrete time with step size 0.03',...
        'Discrete time with step size 0.015'});
axis([0 0.5 0 60]); hold off;

%%


