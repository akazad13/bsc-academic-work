clear all;
clc;

im = imread('coins.png');
[r,c] = size(im);

%% prewitt algorithm
%% apply a mask in x

T = padarray(im,[1 1]);
[r,c] = size(T);
T = double(T);

temp = T;

maskx = [0,-1,0;-1,4,-1;0,-1,0];

for i=2:r-1,
    for j=2:c-1,
        bwsquare = temp(i-1:i+1,j-1:j+1);
        T(i,j) = sum(sum(maskx.*bwsquare));
    end
end

Gx = T(2:r-1,2:c-1);

Gx = uint8(Gx);

figure(); imshowpair(im,Gx,'montage')

a = edge(im,'log'); %gaussian laplace
figure(), imshow(a);

