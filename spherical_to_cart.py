
from ai import cs
import math
import numpy as np
import random


def convert_spherical_to_cartesian(phi, theta, r):
    theta = np.deg2rad(theta)
    phi = np.deg2rad(phi)
    x = np.sin(theta)*np.cos(phi)*r
    y = np.sin(theta)*np.sin(phi)*r
    z = np.cos(theta)*r
    return (x,y,z)