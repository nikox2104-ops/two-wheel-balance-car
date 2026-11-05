% Plot experiment results

%% Step size = 0.03; Proportional Gain = 0.1;
load Lab11_p4_plots_1.mat
plot(tsim, Pos); hold on;
plot(tsim, Error, 'r--')
plot(tsim, Vin, 'g--')
plot(tsim, Ref,'k'); hold off
xlabel('Simulation Time (second)')
ylabel('Motor Postion (degrees)');
title('Closed Loop Feedback Control (Kp = 0.1)');
legend('Motor position','Control error','Control output','Reference');


%% Step size = 0.03; Kp = 0.05; Ki=0.05;
load Lab8_p2_plots_2.mat
plot(tsim, Pos); hold on;
plot(tsim, Error, 'r--')
plot(tsim, Vin, 'g--')
plot(tsim, Ref,'k'); hold off
xlabel('Simulation Time (second)')
ylabel('Motor Postion (counts)');
title('Closed Loop Feedback Control (Kp = 0.05, Ki = 0.05)');
legend('Motor position','Control error','Control output','Reference');

