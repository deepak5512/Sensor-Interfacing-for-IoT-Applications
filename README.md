
# Sensor Interfacing for IoT Applications

This project explored the exciting world of sensor interfacing for Internet of Things (IoT) applications. The focus was on connecting various sensors – both analog and digital – with Raspberry Pi and Arduino Uno boards. Through different connection methods, the project aimed to acquire sensor data, process it effectively, and ultimately deliver valuable insights.


## Arduino Uno with DHT11

In the initial phase of the project, an Arduino Uno microcontroller board was employed to explore fundamental sensor interfacing concepts. A DHT11 sensor, capable of measuring both temperature and humidity, was directly connected to the Arduino Uno. We developed code specifically designed for the Arduino platform to interact with the DHT11 sensor. This code facilitated the retrieval of temperature and humidity readings from the sensor, allowing us to verify sensor functionality and gain experience with data acquisition from digital sensors.

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/Arduino_DHT11/Serial%20Plot.png)
## Arduino Uno with MQ2

Building upon the initial exploration with digital sensors, the project investigated interfacing with analog sensors. An MQ2 sensor, known for its ability to detect the presence of combustible gases, was introduced. Code specific to the Arduino platform was developed to communicate with the MQ2 sensor. The MQ-2 sensor reads the data in 10 bits which is further converted to corresponding voltage by simple multiplication taking some assumptions. This setup allowed us to assess the functionality of the MQ2 sensor and gain experience with interfacing analog sensors.

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/Arduino_MQ3/Serail%20Plot.png)
## Arduino Uno with DHT11 via WiFi module

The project progressed towards wireless data transmission by incorporating an ESP8266 Wi-Fi module alongside the Arduino Uno and DHT11 sensor. The ESP8266, equipped with Wi-Fi capabilities, enabled the system to transmit the acquired temperature and humidity data from the DHT11 sensor wirelessly. This involved developing code for the Arduino Uno to not only interact with the DHT11 sensor but also to communicate and collaborate with the ESP8266 module. The ESP8266, programmed with its own firmware, facilitated the connection to a Wi-Fi network and the subsequent transmission of sensor data. This setup demonstrated the capability of sending sensor readings remotely, paving the way for integration with cloud platforms for data storage and visualization.

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/ARDUINO%20TO%20DHT11%20WIFI%20MODULE/ThingSpeak%20Data%20Plot.jpg)

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/ARDUINO%20TO%20DHT11%20WIFI%20MODULE/SetUp.jpg)
## Raspberry Pi with MQ3 via Arduino Uno

This section investigated interfacing an MQ3 sensor, used for detecting combustible gases, directly with the Raspberry Pi. The MQ3 is an analog sensor, and while the Raspberry Pi itself doesn't have a built-in ADC, we employed an external Arduino Uno. This bridges the gap by converting the sensor's analog output into a digital value the Raspberry Pi can understand. A Python script running on the Raspberry Pi reads the serial input given by Arduino at the port it is connected, allowing it to acquire the digital sensor readings. The script then processed the data and generated informative plots to visualize the sensor readings over time using libraries like Matplotlib. Additionally, the script incorporated functionalities to store the collected data in a text file on the Raspberry Pi.
## Raspberry Pi with MQ3 via MCP3008

This section explored interfacing an MQ3 sensor, used for detecting combustible gases, directly with the Raspberry Pi. Since the MQ3 is an analog sensor, the Raspberry Pi itself was utilized for analog-to-digital conversion (ADC) capabilities. We employed an MCP3008 ADC chip to convert the sensor's analog output into a digital value the Raspberry Pi could understand. A Python script running on the Raspberry Pi facilitated communication with the MCP3008, acquiring the digital sensor readings. The script then processed the data (potentially including scaling or filtering), and generated informative plots to visualize the sensor readings over time using libraries like Matplotlib.

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/Raspberry_MCP3008_MQ3/Plot.png)
## Raspberry Pi with multiple sensors

The final task, we were assigned were was the collection of data for array of sensors, which can collect data in real-time and store them in a csv file format. Later on, this data can be shared to a cloud platform for further analysis. Further, we connect the AO (analog pin) of all three sensors to the three channels of the MCP3008, namely pin 1, 2, 3. We connected the VCC of collective sensors to 3V3 on raspberry pi and ground to GND. The data collected on the drive under the name of sample.csv can be viewed as well.

![App Screenshot](https://raw.githubusercontent.com/deepak5512/Sensor-Interfacing-for-IoT-Applications/main/Arduino_MQ3/Serail%20Plot.png)

## Contributors🛩️

- Deepak Bhatter [@DeepakBhatter](https://www.linkedin.com/in/deepak-bhatter5512?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BoCYT3PQmTJKYeWeOME6%2BdA%3D%3D)
- Rahul Sharma [@RahulSharma](https://www.linkedin.com/in/rahul-sharma-8bb270259?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BnrhobKq%2FQQi3eOf8lKuWdQ%3D%3D)