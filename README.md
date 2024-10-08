# DF-Tank-Version1
GUI DF Tank Algorithm Report

Overview
The GUI DF Tank is an interactive application designed to control and visualize data from a Raspberry Pi. It features two primary operational buttons: Start and Stop, along with control buttons for directional movement and a digital compass interface.
 

Functionality of the Start Button
When the user clicks the Start button, the UDP receiver activates, establishing a connection to the Raspberry Pi. It begins receiving data and plotting it within a frequency range of 400 MHz to 5.9 GHz. 

Data Processing Algorithm
The UDP packets received contain a total of 49 values. These include:
9 header values: The last of which indicates the angle of the motor (antenna).
40 data values: These comprise 20 dB values and 20 corresponding indices.
This structure allows the GUI to identify the top 20 peaks, providing essential information regarding their dB levels, indices, and the antenna angle.
Scanner Plotting
The GUI algorithm generates the center frequency (ranging from 400 MHz to 5.9 GHz) based on the index numbers of the received peaks. To enhance realism, random noise is added to the data. After processing, the cleaned data is sent for visualization on the scanner interface.


Polar Plotting
The polar chart displays the top peak along with the angle received from the UDP packet. This point serves as a reference for generating a lobe at that angle, reflecting the corresponding dB value. This visualization aids in understanding the directionality of the signals detected.


Functionality of the Stop Button
Clicking the Stop button pauses the GUI's operations and terminates all UDP connections, ensuring a controlled shutdown of the system.

Control Buttons
The GUI also includes four directional control buttons: Up, Down, Left, and Right. When pressed, each button sends directional information to the Raspberry Pi, enabling precise movement of the tank.
 

Digital Compass Interface
In addition to the control buttons, the GUI features a digital compass that indicates the tank's current direction. This interface enhances situational awareness, allowing users to navigate effectively.


Target Information Table
Within the GUI, there is a Target Information Table that displays critical data for the top 8 peaks. This table includes:
Peak Number, Start Frequency, End Frequency, Center Frequency, dB Value, Angle
This table provides a quick reference for users to analyze the most significant peaks detected by the system
 
