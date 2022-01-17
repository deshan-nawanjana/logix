import serial

serialPort = serial.Serial(port = "COM4", baudrate = 9600, timeout = 2)

while 1:
    val = serialPort.readline()
    if(len(val) > 0) :
        print(val)
        

x = input()
