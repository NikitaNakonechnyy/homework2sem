import matplotlib.pyplot as plt
import numpy as np

x, y = [], []

with open('ex1.txt', 'r') as file:
    for line in file:
        point = line.strip().split('\t')
        x.append(float(point[0]))
        y.append(float(point[1]))

plt.plot(x, y, 'bo')
plt.show()