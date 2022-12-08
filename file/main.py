from tkinter import *
import tkinter as tk
import os
from PIL import ImageTk, Image
from random import *


#c파일 불러오기

# import ctypes
# dllpath = os.path.join('C:/Users/KooHanSeul/Desktop/room_escape/file/mzzbb.so')


first = 1 # 게임1 깨면 return 값
second = 1 # 게임2 return 값
third = 1 # 게임3 return 값

# 랜덤 숫자 합치기

global num
num = str(first)+str(second)+str(third)

def lock():
    def click_btn(n):
        if input_text.get() == num:
            root.destroy()
            import fin
        else:
            label.configure(text="retry")
    
    window = Tk()
    window.title("lock")
    window.geometry('320x120')
    
    label = Label(window, text="INPUT NUMBER AND ENTER")
    label.grid(column=0, row=0)
    
    input_text = Entry(window, width=30)
    input_text.grid(column=0, row=1)
    
    input_text.bind("<Return>", click_btn)

    window.mainloop()
    



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


# 버튼 생성

buttonpath = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\exclamation_sign.png')

bottom_load = Image.open(buttonpath)
button_img = ImageTk.PhotoImage(bottom_load)

buttonpath2 = os.path.join(r'C:\Users\KooHanSeul\Desktop\room_escape\img\lock.png')

bottom_load2 = Image.open(buttonpath2)
button_img2 = ImageTk.PhotoImage(bottom_load2)


# 1. 테이블 버튼

button = tk.Button(root, command = root.quit , anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(322, 230, window=button)
# ctypes.cdll.LoadLibrary(dllpath)

# 2. 바구니 버튼

button = tk.Button(root, command = root.quit, anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(690, 310, window=button)


# 3. 책장 버튼

button = tk.Button(root, command = root.quit, anchor = 'w', bg='red', image=button_img, bd=0)
button_window = canvas.create_window(110, 340, window=button)


# lock 버튼 만들기

button = tk.Button(root, command = lock, anchor = 'w', bg='black', image=button_img2, bd=0)
button_window = canvas.create_window(223, 245, window=button)

root.mainloop()