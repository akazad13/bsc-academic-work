clear all;
clc;

im = imread('lighthouse.png');
im = rgb2gray(im);
figure(),imshow(im);
figure(),imhist(im);

[row,col] = size(im)
Res = zeros(row,col);


for i=1:row
    for j=1:col
        if(im(i,j)<=55)
            Res(i,j)=0;
        elseif(im(i,j)<=200 && im(i,j)>105)
            Res(i,j)=127;
           
        else
            Res(i,j)=255;
            
        end
    end
end

R = uint8(Res);

figure(),imshow(R);
figure(), imhist(R);