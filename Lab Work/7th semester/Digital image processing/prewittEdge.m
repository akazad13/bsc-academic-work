clear all;
clc;

im = imread('circuit.tif');
[r,c] = size(im);

%% prewitt algorithm
%% apply a mask in x

T = padarray(im,[1 1]);
[r,c] = size(T);
T = double(T);

temp = T;

maskx = [-1,-1,-1;0,0,0;1,1,1];

for i=2:r-1,
    for j=2:c-1,
        bwsquare = temp(i-1:i+1,j-1:j+1);
        T(i,j) = sum(sum(maskx.*bwsquare));
    end
end

Gx = T(2:r-1,2:c-1);

%% apply a mask in y

masky = [-1,0,1;-1,0,1;-1,0,1];
T = zeros(r,c);

for i=2:r-1,
    for j=2:c-1,
        bwsquare = temp(i-1:i+1,j-1:j+1);
        T(i,j) = sum(sum(masky.*bwsquare));
    end
end

Gy = T(2:r-1,2:c-1);

%%normalize

G2 = sqrt(Gx.^2+Gy.^2);
G =uint8(G2);

figure(); imshowpair(im,G,'montage')

