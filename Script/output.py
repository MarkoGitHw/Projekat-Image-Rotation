import cv2 as cv
import numpy as np
k = 0

pixels = []
boundrys =[]

file1 = open("/home/marko/Desktop/Projekat/Projekat-Image-Rotation/Data/Output.txt", "r")
if k == 0:
  text = file1.readline()
  boundrys=text.split(" ")

 
  m =int(boundrys[0])
  n =int(boundrys[1])
  blank_image =np.zeros((m,n,3),np.uint8)
  print (blank_image.shape[0])
  print (blank_image.shape[1])
  k=k+1
if k ==1:
    for i in range (0,m):
        for j in range(0,n):
         

            text = file1.readline()
            pixels=text.split(" ")
            blank_image[i,j,0] = pixels [0]
            blank_image[i,j,1] = pixels [1]
            blank_image[i,j,2] = pixels [2]



cv.imshow("macka",blank_image)
cv.waitKey(0)


