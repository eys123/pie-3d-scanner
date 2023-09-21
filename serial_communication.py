import serial
import time

arduino = serial.Serial(port='COM6', baudrate=9600, timeout=0.1)
arduino_port = "COM6"
fileName = "analog-data.csv"
samples = 10
print_labels = False

print("Connected to Arduino port" + arduino_port)
file = open(fileName, "a")
print("created file")
line = 0

while line <= samples:
    if print_labels:
        if line == 0:
            print("Printing Column Headers")
        else:
            print("Line" + str(line) + ": writing...")
    getData = str(arduino.readline())
    data = getData[0:]
    print(data)

#def write_read(x):
  #  arduino.write(bytes(x, 'utf-8'))
  #  time.sleep(0.05)
  #  data = arduino.readline()
   # return data

#while True:
 #   num = input("Enter a number: ")
  #  value = write_read(num)
  #  print(value)