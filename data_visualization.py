
import serial
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Setup serial connection (adjust COM port as necessary)
ser = serial.Serial('COM3', 9600) # Change 'COM3' to the correct port

data = [] # List to hold the collected data

try:
    while True:
        if ser.in_waiting:
            line = ser.readline().decode('utf-8').rstrip()
            data.append(float(line)) # Assuming data is a float
except KeyboardInterrupt:
    ser.close()

# Convert the list to a pandas DataFrame
df = pd.DataFrame(data, columns=['Sensor Value'])

# Simple line plot
plt.figure(figsize=(10, 6))
sns.lineplot(data=df, x=df.index, y="Sensor Value")
plt.title('Sensor Data Over Time')
plt.xlabel('Time')
plt.ylabel('Sensor Value')
plt.show()
