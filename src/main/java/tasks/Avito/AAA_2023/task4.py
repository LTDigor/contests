import math


def bisection_method(function, a, b, tolerance):
    while abs(b - a) > tolerance:
        c = (a + b) / 2
        if function(c) == 0:
            return c
        elif function(c) * function(a) < 0:
            b = c
        else:
            a = c

    return (a + b) / 2


def find_collision_time(twin_planet_index, K):
    return bisection_method(lambda x: twin_planet_index*math.sin(x) - math.cos(x), 0, 2*math.pi, K)


def find_twin_planet(planets):
    res = -1
    base_radius, base_mass, base_temperature = planets[0]
    for i in range(1, len(planets)):
        radius, mass, temperature = planets[i]

        diff_radius_percents = abs(base_radius - radius) / base_radius
        diff_mass_percents = abs(base_mass - mass) / base_mass
        diff_temp_percents = abs(base_temperature - temperature) / base_temperature
        if diff_radius_percents <= 0.1 and diff_mass_percents <= 0.05 and diff_temp_percents <= 0.02:
            res = i
            break

    return res


def solution():
    coeff = input().split()
    K, n = float(coeff[0]), int(coeff[1])

    planets = []
    for _ in range(n):
        radius, mass, temperature = map(float, input().split())
        planets.append([radius, mass, temperature])

    # Поиск планеты-близнеца
    twin_planet_index = find_twin_planet(planets)

    # Вычисление времени столкновения
    if twin_planet_index != -1:
        collision_time = find_collision_time(twin_planet_index, K)
        print(collision_time)
    else:
        print(-1)


solution()
