#!/usr/bin/python3.7
from tkinter import Tk, Canvas, Frame, BOTH, Button, Label, IntVar
import fileinput
import os
import sys

class Example(Frame):
    def __init__(self, parent, a, container):
        Frame.__init__(self, parent) 
        self.canvas = Canvas(self)
        self.container = container  
        self.a = a
        self.parent = parent      
        self.initUI()
        self.next_button = Button(parent, text="Solve", command=self.solve)
        self.next_button.pack()
        self.close_button = Button(parent, text="Close", command=parent.quit)
        self.close_button.pack() 
        
    def initUI(self):
        n = 16
        first = True
        inputPuzzle = []
        for line in fileinput.input(files = sys.argv[1]):
            if(first):
                first = False
                continue
            else:
                x = line.split()
                inputPuzzle.append(x)
        for i in range(n):
            for j in range(n):
                self.a[j][i] = inputPuzzle[j][i]
        self.parent.title("Sudoku Solver")        
        self.pack(fill=BOTH, expand=1)
        self.canvas.pack(fill=BOTH, expand=1)
        itor = 0
        spacerX = 0
        spacerY = 0
        readyX = True
        readyY = True
        for i in range(n):
            spacerY = 0
            if(i == 5 or i == 9 or i == 13):
                readyX = True
            if((i == 4 or i == 8 or i == 12) and readyX):
                spacerX += 20
                readyX = False
            for j in range(n):
                self.cellwidth = 30
                self.cellheight = 30
                if(j == 5 or j == 9 or j == 13):
                     readyY = True
                if((j == 4 or j == 8 or j == 12) and readyY):
                     spacerY += 20
                     readyY = False
                x1 = (i * self.cellwidth) + 10 + spacerX
                y1 = (j * self.cellheight) + 10 + spacerY
                x2 = x1 + self.cellwidth 
                y2 = y1 + self.cellheight
                self.canvas.create_rectangle(x1+2,y1+2,x2,y2)
                if(str(self.a[j][i]) != "0"):
                    self.container[itor] = self.canvas.create_text(x2-12,y2-12, text=str(self.a[j][i]))
                else:
                    self.container[itor] = self.canvas.create_text(x2-12,y2-12, fill="#990099", text=str(self.a[j][i]))
                itor += 1

    def solve(self):
        n = 16
        outputPuzzle = []
        os.system('./run < ' + sys.argv[1])
        for line in fileinput.input(files ='./results.txt'):
            x = line.split()
            outputPuzzle.append(x)
        itor = 0
        for i in range(n):
            for j in range(n):
                self.a[j][i] = outputPuzzle[j][i]
                self.canvas.itemconfig(self.container[itor], text=str(self.a[j][i]))
                itor += 1

def main():
    root = Tk()
    a = [[1] * 16 for i in range(16)]
    container = [0] * 256
    Example(root, a, container)
    root.geometry("400x100+300+300")
    root.mainloop()  

if __name__ == '__main__':
    main()  