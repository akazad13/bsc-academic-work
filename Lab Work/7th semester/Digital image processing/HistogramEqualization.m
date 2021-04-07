clear all;
clc;

im = imread('tire.tif');
[row,col] = size(im);
figure(), imshow(im);
figure(), imhist(im);

%% variables

Hist = uint8(zeros(row,col));
freq = zeros(256,1);
prob = zeros(256,1);
cumProb = zeros(256,1);
res = zeros(256,1);
L = 255;

%% total pixel
total = double(row*col);

%% frequency counting

for i=1:row
    for j=1:col
        freq(im(i,j)+1) = freq(im(i,j)+1)+1;
    end
end

%% pdf

for i=1:length(freq)
    prob(i) = freq(i)/total;
end

cumProb(1) = prob(1);
res(1) = round(cumProb(1)*L);

for i=2:length(freq)
    cumProb(i) = cumProb(i-1)+prob(i);
    res(i) = round(cumProb(i)*L);
end

for i=1:row
    for j=1:col
        Hist(i,j) = res( im(i,j)+1);
    end
    
end

figure(), imshow(Hist);
figure(), imhist(Hist);
       


