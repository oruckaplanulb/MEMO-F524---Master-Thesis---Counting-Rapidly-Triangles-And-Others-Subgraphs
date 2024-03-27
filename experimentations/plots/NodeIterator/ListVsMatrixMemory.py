import os
import matplotlib.pyplot as plt
from matplotlib import patheffects

names1 = ['p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']
num_vertices = [10876, 22687, 26518, 36682, 62586]
adjMatrix = [463.960, 2014.512, 2751.068, 5262.000, 15658.000]
adjMatrixBool = [463.960/4, 2014.512/4, 2751.068/4, 5262.000/4, 15658.000/4]
names2 = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24']
num_edges = [20777, 26013, 31525, 39994, 54705, 65369]
adjList = [3.508, 4.532, 4.640, 5.596, 9.012, 10.460 ] 

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

plt.figure(figsize=(10, 5))

plt.plot(num_vertices, adjMatrix, color="#fd7f6f", label='Adjacency Matrix (int)')
plt.plot(num_vertices, adjMatrixBool, color="#ffb55a", label='Adjacency Matrix (bool)')
plt.plot(num_edges, adjList, color="#7eb0d5", label='Adjacency List (int)')

plt.scatter(num_vertices, adjMatrix, color="#fd7f6f",s=15)
plt.scatter(num_vertices, adjMatrixBool, color="#ffb55a",s=15)
plt.scatter(num_edges, adjList, color="#7eb0d5",s=15)

for i in range(len(names1)):
    text = plt.text(num_vertices[i], adjMatrix[i] + 350, f"{names1[i]}\n{adjMatrix[i]} MB\nn={num_vertices[i]}", ha='center', va='top', fontsize=6, color='black')
    text.set_path_effects(add_contour(text))

for i in range(len(names1)):
    text = plt.text(num_vertices[i], adjMatrixBool[i] + 350, f"{names1[i]}\n{adjMatrixBool[i]} MB\nn={num_vertices[i]}", ha='center', va='top', fontsize=6, color='black')
    text.set_path_effects(add_contour(text))

for i in range(len(names2)):
    text = plt.text(num_edges[i], adjList[i] + 350, f"{names2[i]}\n{adjList[i]} MB\nm={num_edges[i]}", ha='center', va='top', fontsize=6, color='black')
    text.set_path_effects(add_contour(text))


#set title
plt.title('Adjacency Matrix vs Adjacency List Memory Consumption')
plt.xlabel('Number of Vertices (n) / Number of Edges (m)')
plt.ylabel('Memory Consumption (MB)')

plt.xlim(5000, 70000)
plt.ylim(-100, 4000)

plt.legend(loc='upper left')

plt.grid(True)

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'ListVsMatrixMemory.png'))

plt.show()
