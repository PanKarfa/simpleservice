# Simpleservice ROS package
This is a package that demonstrates the service server and client communication in ROS.

# Server
To launch the server node, 
```
rosrun simpleservice server
```
# Client
To run the client node,
```
rosrun simpleservice client 1
```
# Service interface
In ROS we have the rosservice command to manage calls and show relative information. A simple use of the request status service that we have implemented is as follows:
```
rosservice call /request_status 1.0
```
and the response would be
```
result: "ON"
```
## Aurthor
Panagiotis Karfakis

