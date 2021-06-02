import math
import tkinter as tk

R = 0.05  # Радиус шара
V0 = 5.0  # Начальная скорость
K1 = 0.17  # Коэффициент трения скольжения
K2 = 0.00051  # Коэффициент трения качения
G = 9.81  # Гравитационная постоянная
T1 = (2 * V0) / (7 * K1 * G)  # Время движения с коэффициентом скольжения
X1 = (V0 * T1) - ((K1 * G * T1 * T1) / 2)  # Перемещение за время T1
V1 = V0 - K1 * G * T1  # Скорость в момент T1
T2 = (R * V1) / (K2 * G)  # Время движения с коэффициентом качения
X2 = V1 * T2 - (K2 * T2 * T2 * G) / (2 * R)  # Перемещение за время T2
allX = X1 + X2  # Общее перемещение
allT = T1 + T2  # Общее время

v = V0  # Скорость в момент t
deltaT = 0.1  # Скорость изменения t
temp = 0  # Счётчик перемещений камеры на 1 page
t = deltaT * 2  # Текущее время
x = V0 * t - (K1 * G * deltaT * deltaT) / 2  # Положение в момент t
camX = 0  # Положение камеры
deltaCamX = 470  # Перемещение камеры
deltaX = 0  # Перемещение шара за t
flag = 0  # Переключатель для Пауза
w = 0  # Угловая скорость
angle_in_radians = 0  # Угол поворота
line_length = 25  # Длина радиуса
center_x = 0  # Центр шара по X
center_y = 125  # Центр шара по Y
end_x = 150  # Конец радиуса по X
end_y = 125  # Конец радиуса по Y

print(str("T1 = ") + str(T1) + str("\tX1 = ") + str(X1) + str("\tV1 = ") + str(V1))
print(str("T2 = ") + str(T2) + str("\tX2 = ") + str(X2) + str("\tV2 = ") + str(0))
print(str("T = ") + str(allT) + str("\tX = ") + str(allX) + "\n")

# Создание окна и установка параметров
root = tk.Tk()
root.resizable(width=False, height=False)
root.geometry('875x240')
root.title('Моделирование движения шара после удара по негладкой горизонтальной поверхности')

# Расположение элементов окна и canvas
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
for i in range(5, 9000, 10):
    if i == 125:
        canvas.create_line(i, 150, i, 170, fill="red")
    else:
        canvas.create_line(i, 150, i, 170)


def do_one_frame(self):  # функция моделирования движения при нажатии кнопки Запуск
    global v, V1, X1, X2, allX, T1, T2, allT, R, K1, K2, t, circle, deltaX, deltaCamX, x, camX, temp, output, w
    global line, angle_in_radians, center_x, center_y, line_length, end_x, end_y, flag
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
    center_x = self.coords(circle)[0] + 25
    center_y = 125
    self.move(circle, deltaX * 10, 0)
    angle_in_radians = w * t * math.pi / 180
    end_xx = end_x
    end_x = center_x + (end_x - center_x) * math.cos(angle_in_radians) - (end_y - center_y) * math.sin(angle_in_radians)
    end_y = center_y + (end_y - center_y) * math.cos(angle_in_radians) + (end_xx - center_x) * math.sin(
        angle_in_radians)
    end_x += (deltaX * 10)
    line = canvas.create_line(center_x + (deltaX * 10), 125, end_x, end_y)
    camX = center_x
    t += deltaT
    if v > 0:
        if flag == 1:
            flag = 0
        else:
            self.after(30, do_one_frame, canvas)
    else:
        output.itemconfig(velocity, text=str("v = ") + str(0))
        output.itemconfig(time, text=str("t = ") + str(allT))
        output.itemconfig(coordinate, text=str("x = ") + str(allX))
        output.itemconfig(omega, text=str("w = ") + str(0))


def _on_mousewheel(event):  # функция для скроллинга canvas вдоль оси X
    canvas.xview_scroll(int(-1 * (event.delta / 120)), "units")


def getvalue():  # Функция для кнопки Изменить значения
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


def pause():  # функция для кнопки Пауза
    global flag
    flag = 1


def reset(self):  # функция для кнопки Сброс
    global v, V0, t, allX, deltaX, deltaCamX, camX, x, line, circle, temp, deltaT, w, center_x, center_y, end_x, end_y
    global flag
    pause()
    self.delete(circle)
    self.delete(line)
    circle = canvas.create_oval(100, 100, 150, 150, fill="lightblue")
    line = canvas.create_line(125, 125, 150, 125)
    self.xview_scroll(-temp, "pages")
    v = V0
    deltaT = 0.1
    temp = 0
    t = deltaT * 2
    x = V0 * t - (K1 * G * deltaT * deltaT) / 2
    camX = 0
    deltaCamX = 470
    deltaX = 0
    w = 0
    center_x = 0
    center_y = 125
    end_x = 150
    end_y = 125
    flag = 0
    output.itemconfig(velocity, text=str("v = ") + str(v))
    output.itemconfig(time, text=str("t = ") + str(0))
    output.itemconfig(coordinate, text=str("x = ") + str(0))
    output.itemconfig(omega, text=str("w = ") + str(w))


canvas.bind_all("<MouseWheel>", _on_mousewheel)
# Расположение кнопок и label
tk.Label(root, text='Радиус шара, м').place(x=0, y=0)
tk.Label(root, text='Начальная скорость, м/с').place(x=0, y=25)
tk.Label(root, text='Коэф. трения скольжения').place(x=0, y=50)
tk.Label(root, text='Коэф. трения качения, м').place(x=0, y=75)
tk.Button(root, text='Изменить значения', command=getvalue).place(x=0, y=110)
tk.Button(root, text='Запуск', command=lambda: do_one_frame(canvas)).place(x=151, y=110)
tk.Button(root, text='Сброс', command=lambda: reset(canvas)).place(x=209, y=110)
tk.Button(root, text='Пауза', command=pause).place(x=264, y=110)

root.mainloop()
