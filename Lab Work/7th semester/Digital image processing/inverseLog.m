clear all;
clc;

im = imread('cameraman.tif');
%figure(), imshow(im);
%figure(), imhist(im);

[row,col] = size(im);
g = im2double(im);
c = 3;

for i=1:row
    for j=1:col
        I(i,j) = uint8(c*exp(g(i,j)));
    end
end

im1 = im2uint8(I);

imshowpair(im,im1,'montage');
figure(), plot(im,im1,'b');