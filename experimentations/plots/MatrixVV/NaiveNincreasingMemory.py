import os
import matplotlib.pyplot as plt
from matplotlib import patheffects

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25', 'cit-HepTh']
num_vertices = [1005, 4039, 7115, 12008, 22687, 27770]
memory_1 = [9.212, 132.476, 397.072, 1128.804, 4026.228, 6029.328 ] 
memory_2 = [13.2521, 197.730, 599.565, 1705.572, 6085.027, 9114.019 ]
actual_size = [4.040, 65.254, 202.492, 576.768, 2058.799, 3084.691 ]

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

#memory_1 = [13.372, 198.248, 595.112, 1692.820, 6038.800, 9043.372 ] 
#memory_2 = [17.412, 263.502, 797.605, 2269.588, 8097.599, 12128.063 ]

plt.plot(num_vertices, memory_1, color="#7eb0d5", label='by Matrix Squaring')
plt.plot(num_vertices, memory_2, color="#fd7f6f", label='by Matrix Cube')
plt.plot(num_vertices, actual_size, color="#b2e061", label='Actual Graph Size')

plt.scatter(num_vertices, memory_1, color="#7eb0d5",s=15)
plt.scatter(num_vertices, memory_2, color="#fd7f6f",s=15)
plt.scatter(num_vertices, actual_size, color="#b2e061",s=15)

for i in range(len(names)):
    text = plt.text(num_vertices[i], memory_2[i] + 500, names[i], ha='center', va='top', fontsize=7, color='black')
    text.set_path_effects(add_contour(text))

plt.xlabel('Number of Vertices')
plt.ylabel('Memory Consumption (MB)')

plt.xlim(-1350, 30000)
plt.ylim(-200, 10000)

plt.legend()

plt.grid(True)

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NaiveNincreasingMemory.png'))

plt.show()
