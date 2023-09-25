from astropy import coordinates


def convert_spherical_to_cartesian(r, lat, long):
    r = r
    lat = lat
    lon = lon
    [x, y, z] = coordinates.spherical_to_cartesian(r, lat, long)
    return [x, y, z]