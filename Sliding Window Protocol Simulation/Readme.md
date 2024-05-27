
## Problem Statement
Write a program to simulate Go-Back-N and Selective Repeat modes of the Sliding Window Protocol in peer-to-peer mode. Capture and demonstrate the packet traces using the Wireshark Packet Analyzer Tool for peer-to-peer mode.

## Concept
The Sliding Window Protocol is a method of flow control for network data transfer. It ensures that data packets are sent and received in a reliable and efficient manner. The two main modes are:
- **Go-Back-N**: The sender can send several frames before needing an acknowledgment for the first one, but must retransmit all frames starting from an error.
- **Selective Repeat**: The sender can send several frames before needing an acknowledgment for the first one, and only the erroneous frames are retransmitted.

## Implementation
### Go-Back-N Mode
1. **Sender**:
   - Send multiple frames within a window size.
   - Wait for acknowledgment of the first frame in the window.
   - On error, retransmit all frames starting from the erroneous frame.
2. **Receiver**:
   - Send acknowledgment for the last correctly received frame.
   - Discard frames received out of order.

### Selective Repeat Mode
1. **Sender**:
   - Send multiple frames within a window size.
   - Wait for acknowledgment of each frame.
   - On error, retransmit only the erroneous frames.
2. **Receiver**:
   - Send acknowledgment for each correctly received frame.
   - Store out-of-order frames and deliver them in order once missing frames are received.

## How to Run
### Go-Back-N Mode
1. **Server**:
   - Compile and run `gobacknServer.java`.
   ```bash
   javac gobacknServer.java
   java gobacknServer
     ```

2. **Client**:
    - Compile and run `gobacknClient.java`.
   ```bash
   javac gobacknClient.java
   java gobacknClient
     ```

### Go-Back-N Mode
1.  **Server**:
   - Compile and run `selectiveServer.java`.
   ```bash
   javac selectiveServer.java
   java selectiveServer
     ```

2.  **Client**:
   - Compile and run `selectiveClient.java`.
   ```bash
   javac selectiveClient.java
   java selectiveClient
     ```

