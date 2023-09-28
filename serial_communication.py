"""
Package for pulling serial data from Arduino.
"""
import serial
import csv
import datetime
from time import sleep

def read_and_store_serial_data(arduino_port, csv_filename, baud_rate=9600):
    """
    Reads data from the arduino serial port and stores it in a csv file

    Args:
        arduino_port - string
            The name of the arduino port to be accessed.
        csv_filename - string
            The desired name for the saved csv file.
        baud_rate - int
            The speed of communication between python and the arduino.
    """
    ser = serial.Serial(arduino_port, baud_rate)
        # Create or open the CSV file for writing
    with open(csv_filename, 'w', newline='') as csvfile:
        csv_writer = csv.writer(csvfile)
        while True:
            # Read data from the Arduino
            serial_data = ser.readline().decode().strip()
            print(serial_data)
            csv_writer.writerow([serial_data])

if __name__ == "__main__":
    arduino_port = 'COM9'  # Arduino's serial port
    csv_filename = 'one_d_scan.csv'  # CSV file name
    
    read_and_store_serial_data(arduino_port, csv_filename)

data = read_and_store_serial_data("COM9", "scan_data.csv")