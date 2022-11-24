from tkinter import *
import tkinter as tk
from tkinter import messagebox
import os
from PIL import ImageTk, Image


# 창 만들기

root = tk.Tk()
root.title("ESCAPE THE ROOM")
root.geometry('780x542')
root.resizable(width=False, height=False)
root.wm_attributes("-topmost", 1)


# 배경 이미지

imgpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\main.png')
img = Image.open(imgpath)
photo = ImageTk.PhotoImage(img)

canvas = tk.Canvas(root, bd=0, width=780, height=542, highlightthickness=0)
canvas.pack()
canvas.create_image(390, 270, image=photo)