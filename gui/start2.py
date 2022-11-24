from tkinter import *
import tkinter as tk
import os
from PIL import ImageTk, Image


root = tk.Tk()
root.title("ESCAPE THE ROOM")
root.geometry('545x355')
root.resizable(width=False, height=False)
root.wm_attributes("-topmost", 1)

imgpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\start.png')
img = Image.open(imgpath)
photo = ImageTk.PhotoImage(img)

canvas = tk.Canvas(root, bd=0, width=545, height=355, highlightthickness=0)
canvas.pack()
canvas.create_image(273, 184, image=photo)

canvas.create_text(440, 150, text = "ESCAPE\nTHE\nROOM", font = ("Chiller", 20), fill = "white")


# 버튼 생성
buttonpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\start_button.png')

bottom_load = Image.open(buttonpath)
button_img = ImageTk.PhotoImage(bottom_load)

button = tk.Button(root, command = root.quit, anchor = 'w', bg='black', image=button_img, bd=0)
button_window = canvas.create_window(420, 335, window=button)


root.mainloop()