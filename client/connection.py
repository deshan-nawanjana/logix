import serial.tools.list_ports

vert = None
rate = None
root = None
port = None

def init(ivert, irate, iroot) :
    global vert, rate, root
    vert = ivert
    root = iroot
    rate = irate

def wait() :
    global vert, rate, port, root
    # wait for logix response from any com port
    root.loadWaiting()
    while port == None :
        # check for available port that logix is connected
        for name in serial.tools.list_ports.comports() :
            try :
                # create port object
                number = str(name).split(' ')[0]
                srport = serial.Serial(port = number, baudrate = rate)
                data = srport.readline().decode().rstrip().lstrip()
                if(data == vert) :
                    port = srport
                    root.clearTray()
                    break
                else :
                    srport.close()
            except :
                continue
        root.update()

def read() :
    global port, root
    data = None
    try :
        if port.isOpen() :
            if port.in_waiting :
                data = port.readline().decode().rstrip().lstrip()
        else :
            wait()
    except :
        port = None
        wait()
    return data