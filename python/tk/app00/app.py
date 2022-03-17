# import Tkinter
try:
    from Tkinter import *
except ImportError:
    from tkinter import *
    from tkinter import ttk

# import tkinter as tk
# tk.Tk()

# app = Tkinter.Tk()
app = Tk()
frm = ttk.Frame(app, padding=10)
frm.grid()
ttk.Label(frm, text="Hello App").grid(column=0,row=0)
ttk.Button(frm, text="Quit", command=app.destroy).grid(column=1, row=0)

app.mainloop()
