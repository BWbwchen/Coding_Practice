import numpy as np
import random
import matplotlib.image as img
import matplotlib.pyplot as plt

"""
cmap :
    gray : from black to white (0 ~ 1)
    Greys: from white to black (0 ~ 1)
"""

MIN_NUM = 1
MAX_NUM = 4

f = plt.figure()
im = img.imread("lena_gray.png")
pix = np.copy(im)
pix_random_dither = np.copy(pix)

f.add_subplot(MIN_NUM,MAX_NUM,1)
plt.imshow(pix, cmap='gray')

# -------------------------- random dither --------------------------#
for row in range(pix.shape[0]):
    for pixel in range(pix.shape[1]):
        # this range is determine by grayscale value
        standard = random.randrange(30, 70)
        if standard/100 < pix[row][pixel] :
            # white
            pix_random_dither[row][pixel] = 1
        else :
            # black
            pix_random_dither[row][pixel] = 0

f.add_subplot(MIN_NUM,MAX_NUM,2)
plt.imshow(pix_random_dither, cmap='gray')

pix_random_dither = np.copy(pix)

# ------------------------- ordered dither --------------------------#

#D = np.array([[1, 2],[3, 0]])
D = np.array([[3, 1],[0, 2]])
D = 0.25*D
# ordered dither
for row in range(pix.shape[0]):
    for pixel in range(pix.shape[1]):
        i = row % D.shape[0]
        j = pixel % D.shape[1]
        if pix[row][pixel] < D[i][j]:
            pix_random_dither[row][pixel] = 0
        else :
            pix_random_dither[row][pixel] = 1

f.add_subplot(MIN_NUM,MAX_NUM,3)
plt.imshow(pix_random_dither, cmap='gray')

pix_random_dither = np.copy(pix)


# ---------------------- floyd steinberg dither ---------------------#

def valid (x, y) :
    height = pix.shape[0]
    width = pix.shape[1]
    if x < height and width < y :
        return True
    else :
        return False

def new_pixel (pixel) :
    # this range is determine by grayscale value
    standard = random.randrange(30, 75)
    if standard/100 < pixel :
        # white
        new_pixel = 1
    else :
        # black
        new_pixel = 0
    return new_pixel

for row in range(pix.shape[0]):
    for pixel in range(pix.shape[1]):
        pix_random_dither[row][pixel] = new_pixel(pix_random_dither[row][pixel])
        error = pix[row][pixel] - pix_random_dither[row][pixel]
        if valid(row, pixel+1) :
            pix_random_dither[row][pixel+1] += error * 7 / 16
        if valid(row+1, pixel-1) :
            pix_random_dither[row+1][pixel-1] += error * 3 / 16
        if valid(row+1, pixel) :
            pix_random_dither[row+1][pixel] += error * 5 / 16
        if valid(row+1, pixel+1) :
            pix_random_dither[row+1][pixel+1] += error * 1 / 16

f.add_subplot(MIN_NUM,MAX_NUM,4)
plt.imshow(pix_random_dither, cmap='gray')

# -------------------------- draw all picture ----------------------#
plt.show()
