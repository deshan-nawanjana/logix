from tkinter import *
import serial.tools.list_ports

vert = "LOGIX-1.0" # logix device version name
port = None # serial object
rate = 9600 # serial port baudrate
name = None # arduino board name

root = Tk()
root.geometry("650x400")

def updateRoot() :
    global root
    try :
        root.update()
    except :
        exit()

def waitForConnection() :
    global port
    global rate
    global name
    global root
    global vert
    # wait for logix response from any com port
    root.title('Waiting for connection...')
    while port == None :
        # check for available port that logix is connected
        for srname in serial.tools.list_ports.comports() :
            try :
                # create port object
                number = str(srname).split(' ')[0]
                srport = serial.Serial(port = number, baudrate = rate)
                data = srport.readline().decode().rstrip().lstrip()
                if(data == vert) :
                    port = srport
                    name = srname
                    root.title("LOGIX 1.0 Found")
                    break
                else :
                    srport.close()
            except :
                continue
        updateRoot()

def waitForNextMessage() :
    global port
    try :
        if port.isOpen() :
            if port.in_waiting :
                line = port.readline().decode().rstrip().lstrip()
                root.title(line)
        else :
            waitForConnection()
    except :
        port = None
        waitForConnection()
    updateRoot()

updateRoot()
waitForConnection()
while True : waitForNextMessage()