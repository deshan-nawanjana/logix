from ctypes import alignment
from itertools import tee
from msilib.schema import TextStyle
from operator import iconcat
from textwrap import fill
from tkinter import *
import tkinter
from tkinter import font
from turtle import left

root = Tk()

root.geometry("650x650")
root.resizable = False
root.iconbitmap("icon.ico")
root.title('LOGIX IC Tester')

tray = PanedWindow(root, bg = '#AAA')
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
    code = line[0]
    info = line[1]
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
    wait = Label(
        tray,
        bg = '#AAA',
        foreground = '#444',
        text = 'Waiting for connection...',
        font = "Consolas 18 bold",
        
    )
    wait.pack(fill=BOTH, expand=1)