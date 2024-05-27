# Error Detection and Correction Using Hamming Codes and CRC with Packet Analysis

## Problem Statement

Develop a program to implement error detection and correction for 7/8-bit ASCII codes using Hamming Codes or Cyclic Redundancy Check (CRC). Capture and demonstrate the packet traces using the Wireshark Packet Analyzer Tool in a peer-to-peer mode.

## Details about Hamming Code

**Hamming Code** is an error-detection and error-correction code that can detect up to two simultaneous bit errors and correct single-bit errors. Hamming codes add redundancy bits to data bits, making it possible to detect and correct errors at the receiver end. The typical Hamming code is of the form (7,4), where 4 bits are data bits and 3 bits are parity bits.

- **Calculation of Parity Bits**: Parity bits are calculated such that each bit covers a certain subset of the original data bits. The positions of these parity bits are powers of 2 (1, 2, 4, 8, etc.).
- **Error Detection and Correction**: By recalculating the parity bits on the received data and comparing them with the received parity bits, the position of a single-bit error can be detected and corrected.

## Details about CRC

**Cyclic Redundancy Check (CRC)** is an error-detection code used to detect accidental changes to raw data. A sequence of redundant bits, known as the CRC or CRC code, is appended to the end of the data unit. 

- **Calculation**: CRC is calculated by performing binary division of the data bits by a predetermined divisor, and the remainder of this division operation is the CRC.
- **Error Detection**: Upon receiving the data, the receiver performs the same division and compares the calculated CRC with the received CRC. If they do not match, an error is detected.

## Wireshark Packet Analysis

**Wireshark** is a network protocol analyzer that captures and displays data packets flowing through a network in real-time. It is used to analyze network problems, detect intrusions, and debug protocol implementations.

- **Capture Packets**: In peer-to-peer mode, Wireshark can capture packets sent and received between two devices.
- **Analyze Packets**: Wireshark displays detailed information about each packet, including source and destination addresses, protocols used, and payload data, which can be used to verify the implementation of Hamming Codes or CRC.

## How to Implement

1. **Implement Hamming Code or CRC in your program**:
   - For Hamming Code: Add parity bits, detect and correct errors.
   - For CRC: Calculate CRC for data, append it, and verify upon receipt.

2. **Set up Peer-to-Peer Connection**:
   - Use socket programming to establish a peer-to-peer connection.

3. **Capture Packets with Wireshark**:
   - Run Wireshark and start capturing packets.
   - Execute your program and let Wireshark capture the transmitted data packets.

4. **Analyze Captured Packets**:
   - Use Wireshark to analyze the captured packets.
   - Verify the correctness of error detection and correction by checking the data before and after transmission.

This approach allows for comprehensive testing and validation of error detection and correction algorithms in a practical network scenario.
