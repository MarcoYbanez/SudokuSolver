#!/usr/bin/python3.7
print("ggg")


from tkinter import Tk, Canvas, Frame, BOTH, Button, Label, IntVar
import random
import fileinput


class Example(Frame):
  
    def __init__(self, parent, a, container):
        Frame.__init__(self, parent) 
        self.canvas = Canvas(self)
        self.container = container  
        self.a = a
        self.parent = parent      
        self.initUI()
        self.next_button = Button(parent, text="Next", command=self.nextDay)
        self.next_button.pack()
        self.curDay = 1
        self.label = Label(parent, text="Current Day: ")
        self.label.pack()
        self.total_label_text = IntVar()
        self.total_label_text.set(self.curDay)
        self.total_label = Label(parent, textvariable=self.total_label_text)
        self.total_label.pack()
        self.close_button = Button(parent, text="Close", command=parent.quit)
        self.close_button.pack() 
        
    def initUI(self):
        n = 16
        first = True
        inputPuzzle = []
        for line in fileinput.input(files ='./input/input1.txt'):
            if(first):
                first = False
                continue
            else:
                x = line.split()
                inputPuzzle.append(x)
        for i in range(n):
            for j in range(n):
                self.a[i][j] = inputPuzzle[i][j]
        self.parent.title("Colours")        
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
                self.container[itor] = self.canvas.create_rectangle(x1+2,y1+2,x2,y2, outline="#ff0000")
                self.container[itor] = self.canvas.create_text(x2-6,y2-6, text=str(self.a[i][j]))
                itor += 1

    def makeGrid(self):
        n = 16
        itor = 0
        for i in range(n):
            for j in range(n):   
                if self.a[i][j] == 0:
                    self.canvas.itemconfig(self.container[itor], outline="#ff0000", fill="#ff0000")
                    itor += 1
                elif self.a[i][j] == 1:
                    self.canvas.itemconfig(self.container[itor],  outline="#006400", fill="#006400")
                    itor += 1
                elif self.a[i][j] == 2:
                    self.canvas.itemconfig(self.container[itor], outline="#00cc00", fill="#00cc00")
                    itor += 1
                elif self.a[i][j] == 3:
                    self.canvas.itemconfig(self.container[itor], outline="#99ff99", fill="#99ff99")
                    itor += 1
                elif self.a[i][j] == 5:
                    self.canvas.itemconfig(self.container[itor], outline="#000000", fill="#000000")
                    itor += 1
      
    def nextDay(self):
        self.makeGrid()

def main():
  
    root = Tk()
    a = [[1] * 23 for i in range(23)]
    container = [0] * 529
    ex = Example(root, a, container)
    root.geometry("400x100+300+300")
    root.mainloop()  


if __name__ == '__main__':
    main()  


print("hello")
