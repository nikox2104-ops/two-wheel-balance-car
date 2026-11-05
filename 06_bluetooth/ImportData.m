% Read in binary data from a file
fid = fopen('c:\Temp\capture.bin');
dat = fread(fid);
d = 0.03;  % sample interval;
T = 800*d; % plot 800 sampled data points
t = 0:d:T-d;
plot(t, dat(1:800));
xlabel('Time');
ylabel('Magnitude');
title('Received data from Arduino');