#!/usr/bin/python3.7
from tkinter import Tk, Canvas, Frame, BOTH, Button, Label, IntVar
import fileinput
import os

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
        for line in fileinput.input(files ='./input/input3.txt'):
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
        for i in range(n):
            for j in range(n):
                self.cellwidth = 20
                self.cellheight = 20
                x1 = (i * self.cellwidth) + 5
                y1 = (j * self.cellheight) + 5
                x2 = x1 + self.cellwidth
                y2 = y1 + self.cellheight
                self.canvas.create_rectangle(x1+2,y1+2,x2,y2, outline="#ff0000")
                if(str(self.a[j][i]) != "0"):
                    self.container[itor] = self.canvas.create_text(x2-6,y2-6, text=str(self.a[j][i]))
                else:
                    self.container[itor] = self.canvas.create_text(x2-6,y2-6, fill="#000fff000", text=str(self.a[j][i]))
                itor += 1

    def solve(self):
        n = 16
        outputPuzzle = []
        os.system('./run < input/input3.txt')
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