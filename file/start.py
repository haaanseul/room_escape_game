from tkinter import *
import tkinter as tk
from tkinter import messagebox
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


def explanation():
    tk.messagebox.showinfo("Hint", "Achieve the game goals and get the numbers")
    root.destroy()
    import main # 이래도 되나? 문제 있을지도


# 버튼 생성
buttonpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\start_button.png')

bottom_load = Image.open(buttonpath)
button_img = ImageTk.PhotoImage(bottom_load)

button = tk.Button(root, command = explanation, anchor = 'w', bg='black', image=button_img, bd=0)
button_window = canvas.create_window(420, 335, window=button)

# lambda:tk.messagebox.showinfo(title='hello', message='hello'), anchor = 'w', bg='black', image=button_img, bd=0
root.mainloop()