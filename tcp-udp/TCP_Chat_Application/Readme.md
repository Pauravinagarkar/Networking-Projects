# TCP Chat Application with Peer-to-Peer and Multiuser Capabilities

## Problem Statement
Develop a TCP socket-based application using Java or Python for a wired network to implement:
1. Peer-to-Peer Chat
2. Multiuser Chat

Capture and demonstrate the packet traces using the Wireshark Packet Analyzer Tool for peer-to-peer mode.

## TCP Explanation
**Transmission Control Protocol (TCP)** is a reliable, connection-oriented protocol used for transmitting data over a network. It ensures the ordered delivery of data packets and provides error-checking mechanisms. TCP establishes a connection between a client and a server before data can be sent, ensuring that the data is received as it was sent.

## How to Implement

### Peer-to-Peer Chat
1. **Server (Peer 1)**:
   - Create a `ServerSocket` to listen for incoming connections.
   - Accept a connection and create a `Socket` for communication.
   - Use input and output streams to receive and send messages.

2. **Client (Peer 2)**:
   - Create a `Socket` to connect to the server.
   - Use input and output streams to send and receive messages.

### Multiuser Chat
1. **Server**:
   - Create a `ServerSocket` to listen for incoming connections.
   - Accept multiple connections and create a `Socket` for each client.
   - Use threads to handle multiple clients simultaneously.
   - Broadcast messages received from one client to all other clients.

2. **Client**:
   - Create a `Socket` to connect to the server.
   - Use input and output streams to send and receive messages.
   - Display messages received from the server.

## How to Run

### Peer-to-Peer Chat
1. **Server**:
   - Compile and run `peertopeerServer.java` (or the Python equivalent).
   ```bash
   javac peertopeerServer.java
   java peertopeerServer

2. ### Client:
- Compile and run `peertopeerClient.java` (or the Python equivalent).
   ```bash
   javac peertopeerClient.java
   java peertopeerClient

### MultiUser Chat
1. **Server**:
   - Compile and run `multichatServer.java` (or the Python equivalent).
   ```bash
   javac multichatServer.java
   java multichatServer

2. ### Client:
- Compile and run `multichatClient.java` (or the Python equivalent).
   ```bash
   javac multichatClient.java
   java multichatClient




