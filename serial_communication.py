import serial
import csv
import datetime
from time import sleep

def read_and_store_serial_data(arduino_port, csv_filename, baud_rate=9600):

        ser = serial.Serial(arduino_port, baud_rate)
        # Create or open the CSV file for writing
        with open(csv_filename, 'w', newline='') as csvfile:
            csv_writer = csv.writer(csvfile)
            
            # Write a header row to the CSV file
            csv_writer.writerow(['Timestamp', 'Reading'])

            while True:
                # Read data from the Arduino
                serial_data = ser.readline().decode().strip()
                
                # Get the current timestamp
                timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                
                # Print and write the data to the CSV file
                print(f"{timestamp}: {serial_data}")
                csv_writer.writerow([timestamp, serial_data])



if __name__ == "__main__":
    arduino_port = 'COM6'  # Arduino's serial port
    csv_filename = 'scan_data.csv'  # CSV file name
    
    read_and_store_serial_data(arduino_port, csv_filename)
