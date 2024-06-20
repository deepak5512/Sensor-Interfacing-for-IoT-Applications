import serial
import pandas as pd
import matplotlib.pyplot as plt

ser = serial.Serial('/dev/ttyACM0', 9600)

# Initialize data list
data = []
while True:
    # Read data from serial port
    line = ser.readline().decode('utf-8').strip()

    # Convert data to float
    sensor_value = float(line)

    # Append data to list
    data.append(sensor_value)

    # Write data to a text file
    with open('sensorValue.txt', 'a') as file:
        file.write(f"{sensor_value}\n")

    # Plot data
    plt.plot(data)
    plt.xlabel('Time')
    plt.ylabel('Sensor Value')
    plt.title('Sensor Data Plot')
    plt.pause(0.01)
    plt.clf()