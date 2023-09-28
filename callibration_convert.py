"""
Functions for callibrating and processing Arduino data.
"""
from scipy import optimize
import csv
import math
import numpy as np


def line_fit(xdata, ydata):
    """
    Fits a polynomial line to sensor callibration measurements.
    When given x and y data, will create a polynomial line of
    best fit.

    Args:
        xdata - A list of values on the x-axis.
        ydata - A list of values on the y-axis.

    Returns:
        dist_true - A 1D Numpy Polynomial.
            A polynomial for callibrating sensor
            data.
    """
    dist_true = np.poly1d((np.polyfit(xdata,ydata,3)))
    return dist_true

def read_data(csv_file, calib_dist):
    """
    Reads a csv_file storing sensor and servo data from
    the arduino. The data is processed and split into two
    seperate lists.

    Args:
        csv_file - The file path to a given csv file.
        calib_dist - A Numpy 1D Polynomial used to callibrate
        distance readings.

    Returns:
        dist_list - python list of floats
            A list storing all callibrated distance readings
            from the csv file.
        angle_list - a python list of ints
            A list storing all angle readings from the arduino.
            The readings are stored in a [x, y] format.
    """
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