clear all;
clc;

im  = imread('saturn.png');
im = rgb2gray(im);
im = imresize(im,[256,256]);

figure(),imshow(im);
figure(),imhist(im);

I = [im(:,:)>=50];
figure(),imshow(I);
figure(),imhist(I);