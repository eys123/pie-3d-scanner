
from callibration_convert import read_data, line_fit
from spherical_to_cart import convert_spherical_to_cartesian
import csv
import numpy as np
import math
import matplotlib.pyplot as plt


#data = read_and_store_serial_data("COM8", "scan_data.csv")

xdata = np.array([20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80,
         85, 90, 95, 100, 105, 115, 125])
ydata = np.array([473, 423, 375, 334, 295, 265, 249, 219, 200, 184, 173, 165, 153,
         148, 140, 132, 124, 120, 112, 108])

dist_convert = line_fit(ydata, xdata)
print(dist_convert)

dist_list, angle_list = read_data("scan_data.csv", dist_convert)
print(dist_list)
coords = []
for i in range(len(dist_list)):
     x, y, z = convert_spherical_to_cartesian(angle_list[i][0], angle_list[i][1], dist_list[i])
     x = round(x, 2)
     y = round(y, 2)
     z = round(z, 2)
     coords.append([x,y,z])

print(coords)

fig = plt.figure()
fig, ax = plt.subplots()
for i in range(len(coords)):
   ax.scatter(coords[i][0], coords[i][2])
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
plt.show()