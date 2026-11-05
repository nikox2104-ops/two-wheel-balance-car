clear all

%% Open the file: 'r' means read, 'b' 
% meands it is big-endian
fid = fopen('capture2chans.bin','r','b')

%% read all the lines of data 'int16' lets the command 
% fread know that the data to expect is int16
% and it will properly combine the separate bytes
 dat = fread(fid, 600, 'int16')
 
%% parse the data vector into separate channels:
 cnt=1;
 for i=1:2:length(dat)-1
   dat_1(cnt)=dat(i);
   dat_2(cnt)=dat(i+1);
   cnt=cnt+1;
 end

%% look at each channel side by side:
[dat_1' dat_2']
 
