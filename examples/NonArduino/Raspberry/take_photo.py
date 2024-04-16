import cv2
import numpy as np
import os

# os.system()
image = cv2.imread("teste.jpg")

if image is None:
    print("Erro ao carregar a imagem.")
    exit()

image = cv2.resize(image, (320, 256))
cv2.imwrite("teste_resized.jpg", image)


img_array = []

for line in range(image.shape[0]):
    line_array = []
    for column in range(image.shape[1]):
        pixel = image[line, column]
        cor_hex = (pixel[0] << 16) | (pixel[1] << 8) | pixel[2]
        cor_hex = ("0x{:06X}".format(cor_hex))
        # cor_hex.strip('')
        line_array.append(cor_hex)
        if column == image.shape[1]-1:
            img_array.append(line_array)
        
        
print(img_array[0])


print(len(img_array))
with open('output.txt', 'w') as f:
    for line in img_array:
        f.write(str(line) + ' ')
        # for value in line:
        f.write('\n')
        
with open('output.txt', 'r') as f:
    content = f.read()

content = content.replace('[', '').replace(']', '').replace('\'', '')

with open('output.txt', 'w') as f:
    f.write(content)