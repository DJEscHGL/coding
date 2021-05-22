import math
import tkinter as tk

R = 5.0  # Радиус шара
V0 = 10.0  # Начальная скорость
K1 = 0.05  # Коэффициент трения скольжения
K2 = 0.04  # Коэффициент трения качения
G = 9.81  # Гравитационная постоянная
T1 = (2 * R * V0) / (5 * G + 2 * R * K1 * G)
X1 = V0 * T1 - (K1 * G * T1 * T1) / 2
V1 = V0 - K1 * G * T1
T2 = (R * V1) / (K2 * G)
X2 = V1 * T2 - (K2 * T2 * T2 * G) / (2 * R)
allX = X1 + X2
allT = T1 + T2

v = V0
deltaT = 1
temp = 0
t = deltaT * 2
x = V0 * t - (K1 * G * deltaT * deltaT) / 2
camX = 0
deltaCamX = 470
deltaX = 0
flag = 0
tempV = 0
w = 0
angle_in_radians = 0
line_length = 25
center_x = 0
center_y = 125
end_x = 150
end_y = 125

root = tk.Tk()
root.resizable(width=False, height=False)
root.geometry('875x240')
root.title('Движение шара после удара с учётом сил трения')

canvas = tk.Canvas(root, bg="white", width=470, height=235)
output = tk.Canvas(root, bg="lightgrey", width=400, height=90)
radius = tk.Entry(root)
radius.insert(0, R)
initialVelocity = tk.Entry(root)
initialVelocity.insert(0, V0)
initialCoefficient1 = tk.Entry(root)
initialCoefficient1.insert(0, K1)
initialCoefficient2 = tk.Entry(root)
initialCoefficient2.insert(0, K2)
radius.place(x=200, y=0)
initialVelocity.place(x=200, y=25)
initialCoefficient1.place(x=200, y=50)
initialCoefficient2.place(x=200, y=75)
canvas.place(x=400, y=0)
output.place(x=0, y=150)
ground = canvas.create_line(-500, 150, 9000, 150)
velocity = output.create_text(100, 10, justify='left')
time = output.create_text(100, 30, justify='left')
coordinate = output.create_text(100, 50, justify='left')
omega = output.create_text(100, 70, justify='left')
circle = canvas.create_oval(100, 100, 150, 150, fill="lightblue")
line = canvas.create_line(125, 125, 150, 125)

print(str("T1 = ") + str(T1) + str("\tX1 = ") + str(X1) + str("\tV1 = ") + str(V1))
print(str("T2 = ") + str(T2) + str("\tX2 = ") + str(X2) + str("\tV2 = ") + str(0))
print(str("T = ") + str(allT) + str("\tX = ") + str(allX) + "\n")


def do_one_frame(self):
    global v, V1, X1, X2, allX, T1, T2, allT, R, K1, K2, t, circle, deltaX, deltaCamX, x, camX, temp, tempV, output, w
    global line, angle_in_radians, center_x, center_y, line_length, end_x, end_y
    if camX - deltaCamX >= -50:
        self.xview_scroll(1, "pages")
        deltaCamX += 470
        temp += 1
    if t < T1:
        deltaX = (V0 * t - (K1 * G * t * t) / 2) - (V0 * (t - deltaT) - (K1 * G * (t - deltaT) * (t - deltaT)) / 2)
        x += deltaX
        self.itemconfig(circle, fill="lightblue")
        v = V0 - K1 * G * t
    else:
        deltaX = (V1 * t - (K2 * t * t * G) / (2 * R)) - (V1 * (t - deltaT) - (K2 * (t - deltaT) * (t - deltaT) * G)
                                                          / (2 * R))
        x += deltaX
        self.itemconfig(circle, fill="yellow")
        v = V1 - (K2 * G * t) / R
    w = v / R
    output.itemconfig(velocity, text=str("v = ") + str(v))
    output.itemconfig(time, text=str("t = ") + str(t))
    output.itemconfig(coordinate, text=str("x = ") + str(x))
    output.itemconfig(omega, text=str("w = ") + str(w))
    self.delete(line)
    self.move(circle, deltaX, 0)
    angle_in_radians = w * t * math.pi / 180
    center_x = self.coords(circle)[0] + 25
    # end_x = center_x + line_length * math.cos(angle_in_radians)
    # end_y = center_y + line_length * math.sin(angle_in_radians)
    end_xx = end_x
    end_x = self.coords(circle)[0] + 25 + (end_x - self.coords(circle)[0] + 25) * math.cos(angle_in_radians)
    - (end_y - 125) * math.sin(angle_in_radians)
    end_y = 125 + (end_y - 125) * math.cos(angle_in_radians)
    + (end_xx - self.coords(circle)[0] + 25) * math.sin(angle_in_radians)
    line = canvas.create_line(self.coords(circle)[0] + 25, 125,  end_x, end_y)
    camX = self.coords(circle)[0]
    t += deltaT
    if v > 0:
        self.after(25, do_one_frame, canvas)
    else:
        output.itemconfig(velocity, text=str("v = ") + str(0))
        output.itemconfig(time, text=str("t = ") + str(allT))
        output.itemconfig(coordinate, text=str("x = ") + str(allX))
        output.itemconfig(omega, text=str("w = ") + str(0))


def _on_mousewheel(event):
    canvas.xview_scroll(int(-1*(event.delta/120)), "units")


def getvalue():
    global R, V0, K1, K2, v, x, T1, X1, V1, T2, X2, allX, allT
    R = float(radius.get())
    V0 = float(initialVelocity.get())
    K1 = float(initialCoefficient1.get())
    K2 = float(initialCoefficient2.get())
    radius.delete(0, 'end')
    radius.insert(0, R)
    initialVelocity.delete(0, 'end')
    initialVelocity.insert(0, V0)
    initialCoefficient1.delete(0, 'end')
    initialCoefficient1.insert(0, K1)
    initialCoefficient2.delete(0, 'end')
    initialCoefficient2.insert(0, K2)
    v = V0
    x = V0 * t - (K1 * G * deltaT * deltaT) / 2
    T1 = (2 * R * V0) / (5 * G + 2 * R * K1 * G)
    X1 = V0 * T1 - (K1 * G * T1 * T1) / 2
    V1 = V0 - K1 * G * T1
    T2 = (R * V1) / (K2 * G)
    X2 = V1 * T2 - (K2 * T2 * T2 * G) / (2 * R)
    allX = X1 + X2
    allT = T1 + T2


def reset(self):
    global v, V0, t, allX, deltaX, deltaCamX, camX, x, line, circle, temp, deltaT, w
    self.delete(circle)
    self.delete(line)
    circle = canvas.create_oval(100, 100, 150, 150, fill="lightblue")
    line = canvas.create_line(125, 125, 150, 125)
    self.xview_scroll(-temp, "pages")
    v = V0
    deltaT = 1
    temp = 0
    t = deltaT * 2
    x = V0 * t - (K1 * G * deltaT * deltaT) / 2
    camX = 0
    deltaCamX = 470
    deltaX = 0
    w = 0


canvas.bind_all("<MouseWheel>", _on_mousewheel)

tk.Label(root, text='Радиус шара').place(x=0, y=0)
tk.Label(root, text='Начальная скорость').place(x=0, y=25)
tk.Label(root, text='Коэф. трения скольжения').place(x=0, y=50)
tk.Label(root, text='Коэф. трения качения').place(x=0, y=75)
tk.Button(root, text='Изменить значения', command=getvalue).place(x=0, y=110)
tk.Button(root, text='Запуск', command=lambda: do_one_frame(canvas)).place(x=151, y=110)
tk.Button(root, text='Сброс', command=lambda: reset(canvas)).place(x=209, y=110)

root.mainloop()

# print(str("dX = ") + str(deltaX) + str("\tx = ") + str(x) + str("\tv = ") + str(v) + str("\tt = ") + str(t) + "\n")
