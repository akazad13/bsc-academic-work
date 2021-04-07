clear all;
clc

im = imread('rice.png');
[row,col] = size(im);
figure(),imshow(im);

times = 2;
T = zeros(times*row,times*col);

v = [-1,-1,-1,0,0,1,1,1,-2,-2,-2,0,0,2,2,2];
w = [-1,0,1,-1,1,-1,0,1,-2,0,2,-2,2,-2,0,2];

for i=1:row*times
    for j=1:col*times
        for k=1:16
            xx = round(((i+v(k)-1)*(row-1))/(row*times-1) +1);
            yy = round(((j+w(k)-1)*(row-1))/(row*times-1) +1);
            
            if(xx>0 && xx<=row && yy>0 && yy<=col)
                T(i,j) = T(i,j)+ double(im(xx,yy))/16.0;
            end
        end
    end
end

T = uint8(T);
figure(),imshow(T);
figure(),imhist(im);
figure(),imhist(T);

%imresize(im,2,'bicubic');
