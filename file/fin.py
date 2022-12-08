from tkinter import *
import tkinter as tk
from tkinter import messagebox
import os
from PIL import ImageTk, Image


# 창 만들기

root = tk.Tk()
root.title("THE END")
root.geometry('553x363')
root.resizable(width=False, height=False)
root.wm_attributes("-topmost", 1)


# 이미지

imgpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\end.png')
img = Image.open(imgpath)
photo = ImageTk.PhotoImage(img)

pLabel = Label(root, image=photo)
pLabel.pack(expand=1, anchor=CENTER)


root.mainloop()