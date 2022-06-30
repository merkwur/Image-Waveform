import os
import numpy as np
import matplotlib.pyplot as plt
import cv2 
from scipy.ndimage import histogram
plt.style.use('dark_background')

# input and output paths
PATH = 'path/to/your/image/folder'
output = "path/to/your/output/folder"

# if you dealing with video sort the folder
folder = sorted(os.listdir(PATH))

for file in folder[:1]:
    image = cv2.imread(PATH + str(file), 0)
    image = cv2.resize(image, (1440, 1440), interpolation=cv2.INTER_CUBIC)

    scope = np.zeros((256, 1440))
    for i in range(len(image[1])):
        hist = histogram(image[:,i], 0, 256, 256)
        scope[:, i] = np.flip(hist)
    
    scope = np.log10(scope+.001)  # this line makes matplotlib imshow decent. 
    scope = (scope / scope.max()).round(7) * 255
    
    #cv2.imwrite(f"{out}{file}", scope)

    
fig, ax = plt.subplots(figsize=(12, 8))
ax.axis("off")
plt.imshow(scope)
#cv2.imshow("flag", scope)
#cv2.waitKey(0)
#cv2.destroyAllWindows()


