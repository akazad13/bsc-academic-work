clear all;
clc;

im  = imread('toyobjects.png');

im  = imresize(im,[256,256]);

figure(),imshow(im);

[row,col] = size(im);

im  = double(im);

k = 1;
mm=2;
A(1,1)=1;
A(1,2)=1;

Seed = zeros(256*256, 2);
cc =1;
for i=1:256
    for j=1:256
        Seed(cc,1)=i;
        Seed(cc,2)=j;
        cc = cc+1;
    end
end



v = [-1,1,0,0];
w = [0,0,1,-1];

color = 1;

b = zeros(row,col);
Map = zeros(row,col);
T = 5;
tot = 256*256;
ii = 1;
while( ii<=k)
    x = A(ii,1);
    y = A(ii,2);
    
    ii = ii+1;
    
    b(x,y)=color;
    Map(x,y)=1;
    
    for l=1:4
            xx = x+v(l);
            yy = y+w(l);
            
           if(xx>0 && xx<=row && yy>0 && yy<=col)
               if(Map(xx,yy)==0 && abs(im(x,y)-im(xx,yy))<=T)
                 k= k+1;
                 A(k,1)=xx;
                 A(k,2)=yy;
                 Map(xx,yy)=1;
               end
           end
    end
     
    if(ii>k && mm<=tot)
      
        while(mm<=tot && Map(Seed(mm,1),Seed(mm,2))==1)
            mm = mm+1;
        end
        
        if(mm<=tot)
            k= k+1;
            A(k,1)=Seed(mm,1);
            A(k,2)=Seed(mm,2);
            mm = mm+1;
            color = color+1;
        end
    end
           
end

fre = zeros(1000,1);

for i=1:row
    for j=1:col
        fre(b(i,j)) = fre(b(i,j))+1;
    end
end



color = 0;

for i=1:length(fre)
    if(fre(i)>50)
       for j=1:row
          for k=1:col
              if(b(j,k)==i)
                  b(j,k)=color;
              end
           end
       end
       color = color+1;
    end
end
rate = 255/(color);

for i=1:row
    for j=1:col
        output(i,j)=rate*b(i,j);
    end
end

figure(),imshow(uint8(output));