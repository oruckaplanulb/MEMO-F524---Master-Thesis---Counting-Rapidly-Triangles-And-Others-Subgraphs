import os
import matplotlib.pyplot as plt
from matplotlib import patheffects

names1 = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06','p2p-Gnut05','p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']
num_vertices = [6302,8114,8717,8846,10876, 22687, 26518, 36682, 62586]
EdgeLocal = [1.584,1.756,1.976,1.996,2.200,3.116,3.420,4.332,6.780]
VertexLocal = [1.468, 1.620, 1.748, 1.752, 2.004, 2.744, 3.052, 3.880, 5.832]
General = [1.384, 1.560, 1.652, 1.636, 1.860, 2.424, 2.768, 3.432, 5.196] 

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

plt.figure(figsize=(10, 5))

plt.plot(num_vertices, EdgeLocal, color="#ff5733", label='Edge Local Counting')
plt.plot(num_vertices, VertexLocal, color="#bd7ebe", label='Vertex Local Counting')
plt.plot(num_vertices, General, color="#b2e061", label='Normal Counting')

plt.scatter(num_vertices, EdgeLocal, color="#ff5733",s=15)
plt.scatter(num_vertices, VertexLocal, color="#bd7ebe",s=15)
plt.scatter(num_vertices, General, color="#b2e061",s=15)

for i in range(4,len(names1)):
    text = plt.text(num_vertices[i], EdgeLocal[i]+1, f"{names1[i]}\nn={num_vertices[i]}", ha='center', va='top', fontsize=6, color='black')
    text.set_path_effects(add_contour(text))

for i in range(4,len(names1)):
    text = plt.text(num_vertices[i], EdgeLocal[i]+0.2, f"{EdgeLocal[i]} KB", ha='center', va='bottom', fontsize=6, color='#ff5733')
    text.set_path_effects(add_contour(text))

for i in range(4,len(names1)):
    text = plt.text(num_vertices[i]+0.1, VertexLocal[i]+0.1, f"{VertexLocal[i]} KB", ha='left', va='bottom', fontsize=6, color='#bd7ebe')
    text.set_path_effects(add_contour(text))

for i in range(4,len(names1)):
    text = plt.text(num_vertices[i], General[i]-0.2, f"{General[i]} KB", ha='center', va='top', fontsize=6, color='#b2e061')
    text.set_path_effects(add_contour(text))


#set title
plt.title('4-Cycles counting memory consumption comparison')
plt.xlabel('Number of Vertices (n)')
plt.ylabel('Memory Consumption (KB)')

plt.xlim(5000, 70000)
plt.ylim(0, 8)

plt.legend(loc='upper left')

plt.grid(True)

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'GeneralVsVectorVsEdgeMemory.png'))

plt.show()
