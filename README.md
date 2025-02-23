
# UART Communication Protocol on STM32F103C6

This project demonstrates a simple UART-based communication protocol implemented on the STM32F103C6 microcontroller. The protocol is designed to facilitate reliable sensor data exchange between a user console and the STM32.


--------------------------------------------------------------
## Protocol Overview

The communication protocol consists of the following steps:

1. **Data Request:**
   - **Command:** The user initiates the communication by typing `!RST#` on the console.
   - **Purpose:** This command requests the current sensor (ADC) data from the STM32.

2. **Data Response:**
   - **Response Format:** Upon receiving `!RST#`, the STM32 reads the ADC value and responds with a message in the format:
     ```
     !ADC=1234#
     ```
   - **Details:** Here, `1234` represents the value of the `ADC_value` variable.

3. **Communication Termination:**
   - **Command:** The user ends the communication by sending `!OK#`.
   - **Purpose:** This indicates that the user has received the required data and no further transmission is needed.

----------------------------------------------------------------------
## Timeout and Retransmission Mechanism

- **Timeout Duration:** The STM32 waits for the `!OK#` command for up to **3 seconds**.
- **Retransmission:** If the termination command is not received within the timeout period, the STM32 automatically retransmits the last ADC data packet.
- **Data Consistency:** The previously sent ADC value is maintained and resent until the `!OK#` command is received.

----------------------------------------------------------------------

## Implementation Details

- **UART Communication:**  
  The protocol leverages UART for asynchronous serial communication, ensuring reliable data exchange between the console and the microcontroller.

- **Data Handling and Formatting:**  
  When a `!RST#` command is received, the STM32:
  - Reads the current ADC value.
  - Formats the ADC value into the string `!ADC=1234#`.
  - Sends the formatted data back to the user.

- **Timeout and Packet Retransmission:**  
  A timer is used to monitor the reception of the `!OK#` command:
  - If the timer exceeds 3 seconds without receiving `!OK#`, the last data packet is retransmitted.
  - This mechanism ensures that the user receives continuous sensor data until the communication is properly terminated.

 --------------------------------------------------------------------------
## Video Demo
Below is a demo video showcasing the implemented UART communication protocol on the STM32F103C6 on Proteus Simulation 8. The video demonstrates the complete command sequence—from initiating the data request to receiving the sensor data and handling timeouts with retransmissions.


<p align="left"> 
  <img src="https://github.com/user-attachments/assets/1ce41ff5-49be-4059-a458-f292261d4c94" alt="Image" style="max-width:500px;"> 
</p>

 
-------------------------------------------------------------------------------
## Summary

This implementation of a UART communication protocol on the STM32F103C6 provides a straightforward and reliable method for sensor data retrieval. The inclusion of a timeout and retransmission mechanism enhances communication robustness, making it well-suited for applications that require precise and timely data monitoring.

For further details or questions, please refer to the full project documentation.


-------------------------------------------------------------------------------
## Author
<div align="center">
<a href="https://github.com/NgqvngVinh" target="_blank">
  <img src="https://github.com/NgqvngVinh.png" alt="Avatar của tôi" width="60" style="border-radius: 50%;">
</a>
</div>
