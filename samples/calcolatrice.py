import tkinter as tk

def createButton(buttonText):
	button = tk.Button(text=buttonText, width=5, height=5)
	button.pack()
	return button

window = tk.Tk()
buttonOne = createButton("1")
buttonTwo = createButton("2")
buttonThree = createButton("3")
buttonFour = createButton("4")
# buttonOne = tk.Button(
# 	text="1",
# 	width=5,
# 	height=5
# )
# buttonTwo = tk.Button(
# 	text="3",
# 	width=5,
# 	height=5
# )
# buttonThree = tk.Button(
# 	text="3",
# 	width=5,
# 	height=5
# )
# buttonOne.pack()
# buttonTwo.pack()
# buttonThree.pack()
# label = tk.Label(text="Hello, Tkinter")
# label.pack()

window.mainloop()