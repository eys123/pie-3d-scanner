"""
Main file for calling functions and graphing data.
"""
from callibration_convert import read_data, line_fit
from spherical_to_cart import convert_spherical_to_cartesian
import csv
import numpy as np
import math
import matplotlib.pyplot as plt


# Data for sensor callibration
xdata = np.array([20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80,
         85, 90, 95, 100, 105, 115, 125])
ydata = np.array([473, 423, 375, 334, 295, 265, 249, 219, 200, 184, 173, 165, 153,
         148, 140, 132, 124, 120, 112, 108])

# Generating the curve of best fit for callibration
dist_convert = line_fit(ydata, xdata)
# Pulling distance and angle readings from a saved csv file
dist_list, angle_list = read_data("one_d_scan.csv", dist_convert)
print(dist_list)
# Callibrating coordinates and converting them from spherical to cartesian
xlist = []
ylist = []
zlist = []
for i in range(len(dist_list)):
      x, y, z = convert_spherical_to_cartesian(angle_list[i][0], angle_list[i][1], dist_list[i])
      x = round(x, 2)
      y = round(y, 2)
      z = round(z, 2)
            #if y <= 40 and z >=-50 and z <=-10:
      xlist.append(x)
      ylist.append(y)
      zlist.append(z)
print(xlist)
# Plotting the point cloud data
plt.scatter(xlist, ylist, s=2)
plt.title("Overhead Point Cloud View")
plt.ylabel("Y Distance (cm)")
plt.xlabel("X Distance (cm)")




fig=plt.figure()
ax = plt.axes(projection='3d')
ax.scatter(xlist, ylist,zlist, s=2)
ax.set_xlabel('X Distance (cm)')
ax.set_ylabel('Y Distance (cm)')
ax.set_zlabel('Z Distance (cm)')
plt.title('Scan Point Cloud')
plt.show()
