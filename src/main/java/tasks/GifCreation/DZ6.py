import os
import shutil

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from PIL import Image

# задаем параметры системы
lx = 1
ly = 1
Nx = 100
Ny = 100
t_max = 0.01
a = 1
t_current = 0
tau = 2.5e-05

# это вот не трогаем

hx = lx / Nx
hy = ly / Ny


# тут задаются начальные условия

def u0(x, y):
    return 1


# тут граничные условия

# x = 0
def u_x_left(y):
    return 0


# x = lx
def u_x_right(y):
    return 0


# y = 0
def u_y_left(x):
    return 0


# y = ly
def u_y_right(x):
    return 0


# заполняем функцию значениями при t = 0

u = np.zeros((Nx + 1, Ny + 1))
for j in range(Ny + 1):
    u[0][j] = u_x_left(j * hy)
    u[Nx][j] = u_x_right(j * hy)

for i in range(Nx + 1):
    u[i][0] = u_y_left(i * hx)
    u[i][Ny] = u_y_right(i * hx)

for i in range(1, Nx):
    for j in range(1, Ny):
        u[i][j] = u0(i * hx, j * hy)

        # тут формулка, по которой считаются значения функции в новом временном слое


def Shema(u, Nx, Ny, hx, hy, tau, a):
    u_new = np.zeros((Nx + 1, Ny + 1))
    for i in range(Nx + 1):
        for j in range(Ny + 1):
            u_new[0][j] = u[0][j]
            u_new[Nx][j] = u[Nx][j]
            u_new[i][0] = u[i][0]
            u_new[i][Ny] = u[i][Ny]
    for i in range(1, Nx):
        for j in range(1, Ny):
            u_new[i][j] = u[i][j] + tau * a ** 2 * ((u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]) / hx ** 2
                                                    + (u[i][j + 1] - 2 * u[i][j] + u[i][j - 1]) / hy ** 2)
    return u_new


def Out(u, t, Nx, Ny, hx, hy):
    u_l = []
    x_l = []
    y_l = []
    for i in range(Nx + 1):
        for j in range(Ny + 1):
            u_l.append(u[i][j])
            x_l.append(i * hx)
            y_l.append(j * hy)
    d = {'u': u_l, 'x': x_l, 'y': y_l}
    df = pd.DataFrame(d)
    df.to_csv(f'csv/for_pic_u[{t:.6f}].csv', sep=',')


def make_pic(t):
    for adres in os.listdir('./csv/'):
        if f'for_pic_u[{t:.6f}]' not in adres:
            continue
        df = pd.read_csv('./csv/' + adres, sep=',')
        U = np.zeros((Nx + 1, Ny + 1))
        l = 0
        for i in range(Nx + 1):
            for j in range(Ny + 1):
                U[i][j] = df['u'][l]
                l += 1

        X = sorted(list(set(df['x'])))
        Y = sorted(list(set(df['y'])))
        X, Y = np.meshgrid(np.array(X), np.array(Y))

        plt.figure(figsize=(8, 7))
        plt.contourf(X, Y, U)
        plt.title(f'time {t:.6f}')

        plt.colorbar()
        plt.savefig(f'pic/pic_{t:.6f}_.png')
        plt.close()


# тут сохраняем в файлы значения функции во всех временных слоях

if os.path.isdir('csv'):
    shutil.rmtree('csv')
os.mkdir('csv')

t_current = 0
while t_current < t_max:
    Out(u, t_current, Nx, Ny, hx, hy)
    u = Shema(u, Nx, Ny, hx, hy, tau, a)
    t_current += tau

# тут делаем картиночки

if os.path.isdir('pic'):
    shutil.rmtree('pic')
os.mkdir('pic')

t_current = 0
while t_current < t_max:
    print(t_current)
    make_pic(t_current)
    t_current += tau

# тут создаем гифку

time_pic = {}
for adres in os.listdir('./pic/'):
    if f'pic' not in adres:
        continue
    time_pic[float(adres.split('_')[1])] = adres
time_pic = dict(sorted(time_pic.items(), key=lambda x: x[0]))

times = list(time_pic.keys())
dtimes = np.array(times[1:]) - np.array(times[:-1])
dtimes = dtimes.tolist()
dtimes.append(dtimes[0])

frames = []
t_current = 0
for t_current in times:
    with Image.open('pic/' + time_pic[t_current]) as frame:
        frame.load()
    frames.append(frame)

frames[0].save('gifka.gif', save_all=True, append_images=frames[1:], duration=dtimes)
