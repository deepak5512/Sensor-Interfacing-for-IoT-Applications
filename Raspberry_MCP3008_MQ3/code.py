import time
import Adafruit_GPIO.SPI as SPI
import Adafruit_MCP3008
import matplotlib.pyplot as plt

# Hardware SPI configuration:
SPI_PORT   = 0
SPI_DEVICE = 0
mcp = Adafruit_MCP3008.MCP3008(spi=SPI.SpiDev(SPI_PORT, SPI_DEVICE))
data = []

while True:
    sensor_value = mcp.read_adc(0)
    data.append(sensor.value)

    plt.plot(data)
    plt.xlabel('Time')
    plt.ylabel('Sensor Value')
    plt.title('Sensor Data Plot')
    plt.pause(0.01)
    plt.clf()

    if value > 0:
        print("Gas Detected", end = ' ')
        last_touch = time.time()

    time.sleep(1)