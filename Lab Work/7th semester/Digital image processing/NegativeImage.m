clear all;
clc;

im = imread('iris2.jpg');
[row, col] = size(im);
im = rgb2gray(im);

figure(), imshow(im);
figure(), imhist(im);

I = 255-im(:,:)+1;

figure(), imshow(I);
