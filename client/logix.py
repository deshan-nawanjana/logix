import connection
import interface

vert = "LOGIX-1.0" # logix device version name
rate = 9600 # serial port baudrate

# config connection with settings
connection.init(vert, rate, interface)

# wait for logix response from any com port
connection.wait()

# main loop of the program
while True :
    # read line
    line = connection.read()
    # do chnages if available
    if(line != None) :
        interface.load(line)
    # interface frame update
    interface.update()