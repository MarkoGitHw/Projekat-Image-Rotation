import cv2 as cv
import numpy
print('hello world!')
img=cv.imread('macka.jpg')
cv.imshow('cat',img)
height = img.shape[0]
width = img.shape[1]
file = open ("DimenzijeMacka.txt" , "w")
file.write (str(height) + ' ' + str(width) )
file.close()  
file = open ("mackica.txt" , "w")

for i in range (0,height):
	for j in range (0,width):
	
		array1 =img[i,j,0]
		array2 =img[i,j,1]
		array3 =img[i,j,2]
		content=str(array1);
		file.write(content + ' ')
		content=str(array2);
		file.write(content + ' ')
		content=str(array3);
		file.write(content + ' '+ '\n')
		
file.close()
cv.waitKey(0)
