
"""
CSC 134
Travis Cayton
9/10/2025
"""

import turtle as t
import random
screen = t.Screen()


def move_to_mouse(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()

def drag_mouse(x,y):
    t.ondrag(None)
    t.setheading(t.towards(x, y))    
    t.goto(x,y)
    t.ondrag(drag_mouse)
change_pencolor = "white"
t.speed(0)
t.pensize(3)
t.bgcolor("black")
print("")
print("----ENTER COLORS TO BEGIN DRAWING----")
print("")
change_pencolor = input("Pen color: ")
t.pencolor(change_pencolor)

screen.onscreenclick(move_to_mouse)
t.ondrag(drag_mouse)

screen.mainloop()

