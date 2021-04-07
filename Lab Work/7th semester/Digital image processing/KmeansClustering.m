clear all;
clc;

im = imread('trees.tif');
k = 4;
indx = kmeans(im(:), k);
newIm =reshape(indx, size(im));
imshowpair(im,newIm,'montage');
clc;