from tkinter import *
import tkinter
from PIL import Image, ImageTk
from os.path import exists

root = Tk()

root.geometry("650x650")
root.resizable = False
root.iconbitmap("icon.ico")
root.title('LOGIX IC Tester')

tray = PanedWindow(root, bg = '#FFF')
tray.pack(fill = BOTH, expand = 1)

cons = Label(
    root,
    text = '',
    bg = '#222',
    foreground = '#999',
    font = "Consolas 8",
    anchor = tkinter.NW,
    height = 10,
    padx = 10,
    pady = 10,
    justify = tkinter.LEFT
)

cons.pack(fill = tkinter.BOTH, side = tkinter.BOTTOM)

def update() :
    global root
    try :
        root.update()
    except :
        exit()

def setTitle(text) :
    global root
    root.title(text)

def load(line) :
    # update console
    loadConsole(line)
    # split for code and info
    line.split(" ", 1)
    selectUIState(line)
    return

def loadConsole(line) :
    global cons
    # create cons line array and append
    arry = cons.cget('text').split('\n')
    # remove empty line
    if(arry[0] == '') : arry.remove('')
    arry.append(line)
    # slice for last five lines
    leng = len(arry)
    if(leng > 10) :
        arry = arry[leng - 10 :]
    # generate cons text
    leng = len(arry)
    text = ''
    for i in range(0, leng) :
        text += arry[i].rstrip().lstrip()
        if(i < leng - 1) : text += '\n'
    # update cons
    cons.config(text = text)

def clearTray() :
    global tray
    for child in tray.winfo_children() :
        child.destroy()

def loadWaiting() :
    global tray
    clearTray()
    wait = Label(
        tray,
        bg = '#AAA',
        foreground = '#444',
        text = 'Waiting for connection...',
        font = "Consolas 18 bold"
    )
    wait.pack(fill = BOTH, expand = 1)

def selectUIState(line) :
    print(line)
    cmd = line[0:15]
    dat = line[16:]
    if(cmd == 'STATE.HOME_TEXT') : state_home_text()
    if(cmd == 'STATE.MAIN_MENU' or cmd == 'INPUT.LAST_CODE' or cmd == 'INPUT.NEXT_CODE' or cmd == 'INPUT.NEXT_TYPE') :
        state_main_menu(dat)
    if(cmd == 'STATE.SCAN_PINS' or cmd == 'INPUT.SCAN_AUTO') : state_scan_start(dat)

def state_home_text() :
    global tray
    clearTray()
    home = Label(
        tray,
        bg = '#AAA',
        foreground = '#444',
        text = 'LOGIX\nIC TESTER',
        font = "Consolas 35 bold"
    )
    home.pack(fill = BOTH, expand = 1)

def state_main_menu(dat) :
    global tray
    clearTray()
    arr = dat.split(" ", 1)
    home = Label(
        tray,
        bg = '#FFF',
        foreground = '#444',
        text = '\n< ' + dat + ' >',
        font = "Consolas 22 bold",
        height=2
    )
    home.pack()
    file = "images/menu/"+ arr[1] +".gif"
    snap = ImageTk.PhotoImage(
        Image.open(file)
    )
    imag = Label(
        tray,
        height = 350,
        width = 500,
        image = snap
    )
    imag.image = snap
    imag.pack()

def state_scan_start(dat) :
    global tray
    clearTray()
    wait = Label(
        tray,
        bg = '#AAA',
        foreground = '#444',
        text = 'Scanning...',
        font = "Consolas 18 bold"
    )
    wait.pack(fill = BOTH, expand = 1)