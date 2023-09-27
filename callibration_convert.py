from scipy import optimize
import csv
import math
import numpy as np


def line_fit(xdata, ydata):

    

    dist_true = np.poly1d((np.polyfit(xdata,ydata,2)))
    return dist_true

def read_data(csv_file, calib_dist):
    file=open(csv_file, "r")
    reader = csv.reader(file)
    angle_list = []
    dist_list = []
    data_list = []
    for line in reader:
        data_split = line[0].split(",")
        data_list.append(data_split)
    for data in data_list:
        dist_list.append(calib_dist(int(data[0])))
        data[1] = data[1].replace(' [', '')
        data[2] = data[2].replace(']', '')
        angle_list.append((int(data[1]), int(data[2])))
    return dist_list, angle_list