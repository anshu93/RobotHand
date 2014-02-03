# RobotHand
=========

This is a project I worked on with Gift Nykayaramba, Minhaz Islam, Negatu Asmamaw and Fabio Berger for the Duke ECE Student Showcase on January 23rd, 2014.

## VIDEOS

http://www.youtube.com/watch?v=1EKQisgA6HU

http://www.youtube.com/watch?v=67BF7ubbdGc

## OVERVIEW

The goal of the project was to demonstrate remote human-robot interaction using low cost technologies.
We decided to implement a user controlled 3D printed arm which would be controlled by a sleeve worn by the user. This sleeve would track the movements in the user's hand and wirelessly transmit them to the motors in the robotic arm.

## THE HAND

The 3D Printed hand was printed with files from an open source 3d printable robot project (www.inmoov.fr) and is mechanically driven by 5 King High Torque servos (one for each finger). Instructions for assembly can be found on that site.

## THE WIRELESS CONTROL SYSTEM

The wireless system is quite basic and is based on an arduino sensing system and an Xbee wireless module. The Arduino on the user sleeve is wired to 5 flex resistors attached to the glove and detects the voltage change across it as a measure of how bent the user's fingers are.
The arduino then maps these raw values onto a 0-9 scale for easy transmission and then creates a 3 byte information packet for each finger. The 3 bytes are:
1. A capitalised letter showing which finger the packet is destined to (eg. 'T' for thumb) 
2. The value from 0-9 that is converted from an int to a char so as to take only 1 byte rather than 4
3. An end of packet delimiter that we chose to be the char '.'

The Xbee module then buffered these packets and sent them out byte by byte over a 2.4GHz frequency spectrum. The receiving Xbee then receives these bytes of information in whatever order they arrive in and sends it to the attached Arduino for processing. 
The Receiving Arduino begins by popping bytes off the Serial buffer stack and analyses it to see which finger this packet is destined for. To make sure it is the first byte of a valid packet it checks if it is a valid identifying letter and continues only if it is. If not, then it continues popping off the buffer until it finds a valid packet start. 
