from tkinter import *
import tkinter as tk
import os
from PIL import ImageTk, Image


root = tk.Tk()
root.title("ESCAPE THE ROOM")
root.geometry('780x542')
root.resizable(width=False, height=False)
root.wm_attributes("-topmost", 1)

imgpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\main.png')
img = Image.open(imgpath)
photo = ImageTk.PhotoImage(img)

canvas = tk.Canvas(root, bd=0, width=780, height=542, highlightthickness=0)
canvas.pack()
canvas.create_image(390, 270, image=photo)


# 버튼 생성

buttonpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\exclamation_sign.png')

bottom_load = Image.open(buttonpath)
button_img = ImageTk.PhotoImage(bottom_load)

# 1. 테이블 버튼

button = tk.Button(root, command = root.quit, anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(322, 230, window=button)

# 2. 바구니 버튼

button = tk.Button(root, command = root.quit, anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(690, 310, window=button)

# 3. 책장 버튼

button = tk.Button(root, command = root.quit, anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(110, 340, window=button)

root.mainloop()