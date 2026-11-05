% motor_simulation_run.m:
% Script to run motor_simulation.slx

clear all; close all;
%% Load motor parameters
motor_parameters;

%% Simulation parameters
Tsim_final = 0.3;
sim_step_size = 0.0001;

%% Invoke (run) the Simulink model
sim('motor_simulation');

%% Plot the simulated motor step responses
figure(1); hold on;
h1 = plot(tsim,step_response_1st*RADSEC2RPM,'r+');
h2 = plot(tsim,step_response_2nd*RADSEC2RPM,'k--');
h1tf = plot(tsim,step_response_Tf*RADSEC2RPM,'g');

%% Invoke (run) the Simulink model with no friction
b = 0; Tf = 0;
sim('motor_simulation');

%% Plot the motor step responses with no friction
h2_nf = plot(tsim,step_response_2nd*RADSEC2RPM,'c+');
h1tf_nf = plot(tsim,step_response_Tf*RADSEC2RPM,'b--');
xlabel('Time (seconds)'); 
ylabel('Angular velocity (RPM) with 4.5v step input');
legend([h2_nf h1tf_nf h1 h2 h1tf],...
       {'2nd order, no viscous',...
        '1st order, no viscous and no friction',...
        '1st order, with viscous only',...
        '2nd order, with viscous only',...
        '1st order, with viscous and friction'});
axis([0 0.3 0 65]); hold off;

%%


