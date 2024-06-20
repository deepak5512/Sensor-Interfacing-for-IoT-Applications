import serial
import matplotlib.pyplot as plt

ser = serial.Serial('/dev/ttyACM0', 9600)  # Check your serial port

# Initialize data list
data = []

try:
    while True:
        # Read data from serial port
        line = ser.readline().decode('utf-8').strip()

        # Convert data to integer
        sensor_value = float(line)

        # Append data to list
        data.append(sensor_value)

        # Plot data
        plt.plot(data)
        plt.xlabel('Time')
        plt.ylabel('Sensor Value')
        plt.title('Sensor Data Plot')
        plt.pause(0.01)
        plt.clf()  # Clear the plot for the next iteration

except KeyboardInterrupt:
    # Close serial connection
    ser.close()
    print("Serial connection closed.")