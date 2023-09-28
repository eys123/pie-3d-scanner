"""
Function for converting spherical coordinates to cartesian.
"""
from ai import cs
import math
import numpy as np
import random


def convert_spherical_to_cartesian(phi, theta, r):
    """
    Converts spherical coordinates to cartesian coordinates.

    Args:
        phi - an integer representing horizontal rotation.
        theta - an integer representing vertical rotation.
        r - a float representing distance from the sensor.
    
    Returns:
        (x, y, z) - Cartesian coordinate equivalent of the
        spherical input.

    """
    theta = np.deg2rad(theta)
    phi = np.deg2rad(phi)
    x = np.sin(theta)*np.cos(phi)*r
    y = np.sin(theta)*np.sin(phi)*r
    z = np.cos(theta)*r
    return (x,y,z)