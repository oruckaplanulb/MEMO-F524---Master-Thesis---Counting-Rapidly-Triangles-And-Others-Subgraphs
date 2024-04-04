import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut05', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']

n = [6301, 8114, 8717, 8846, 10876, 22687, 26518, 36682, 62586]  #nb vertices
m = [20777, 26013, 31525, 31839, 39994, 54705, 65369, 88328, 147892]  #nb edges
density = [round((m[i] / ((n[i] * (n[i] - 1))/2))*100, 3) for i in range(len(n))]


y1 = [17.3137, 19.9421, 22.8682, 22.3005, 28.6134, 32.3338, 46.2363, 68.6566, 128.228]  # NodeIteratorAdjList
y2 = [4.90702, 5.99806, 8.28788, 9.77894, 12.5685, 11.7892, 15.9657, 23.6532, 38.4171]  # NodeIteratorPlusPlusAdjList
y3 = [316.271, 503.967, 621.351, 643.692, 966.029, 2842.14, 3904.67, 7390.76, 52220.3]  # NodeIteratorAdjMatrix
y4 = [359.444, 584.758, 685.184, 708.314, 1059.87, 4170.06, 6029.59, 11337.6, 144125]  # NodeIteratorPlusPlusOrderedAdjMatrix

y1_raw_min = [15.9572, 19.9421, 20.9107, 20.9437, 25.9304, 30.913, 43.8807, 65.8178, 124.666]
y1_raw_max = [22.9372, 28.9249, 25.8821, 30.9652, 35.8601, 41.9071, 48.8357, 78.8255, 166.587]
y2_raw_min = [4.0031, 4.9595, 6.9481, 6.0091, 8.983, 7.9985, 13.9959, 21.9394, 35.9427]
y2_raw_max = [6.0039, 7.0234, 11.0085, 12.9655, 15.959, 13.9665, 17.997, 25.9309, 40.9259]
y3_raw_min = [303.185, 480.717, 589.395, 621.339, 938.492, 2721.72, 3797.85, 7208.76, 32255.2]
y3_raw_max = [342.087, 529.62, 656.268, 668.213, 986.397, 2918.2, 4099.04, 7812.14, 85306.9]
y4_raw_min = [342.087, 562.493, 665.221, 685.167, 1043.21, 4115.99, 5913.18, 11183.1, 125071]
y4_raw_max = [384.006, 618.381, 732.032, 742.016, 1115.04, 4237.69, 6167.54, 11683.8, 174352]

#remove the last data from y* and m
y1 = y1[:-1]
y2 = y2[:-1]
y3 = y3[:-1]
y4 = y4[:-1]
y1_raw_min = y1_raw_min[:-1]
y1_raw_max = y1_raw_max[:-1]
y2_raw_min = y2_raw_min[:-1]
y2_raw_max = y2_raw_max[:-1]
y3_raw_min = y3_raw_min[:-1]
y3_raw_max = y3_raw_max[:-1]
y4_raw_min = y4_raw_min[:-1]
y4_raw_max = y4_raw_max[:-1]
m = m[:-1]


y1_min = [y1[i] - y1_raw_min[i] for i in range(len(y1))]
y1_max = [y1_raw_max[i] - y1[i] for i in range(len(y1))]
y2_min = [y2[i] - y2_raw_min[i] for i in range(len(y2))]
y2_max = [y2_raw_max[i] - y2[i] for i in range(len(y2))]
y3_min = [y3[i] - y3_raw_min[i] for i in range(len(y3))]
y3_max = [y3_raw_max[i] - y3[i] for i in range(len(y3))]
y4_min = [y4[i] - y4_raw_min[i] for i in range(len(y4))]
y4_max = [y4_raw_max[i] - y4[i] for i in range(len(y4))]

y1_min = [round(y1_min[i], 2) for i in range(len(y1_min))]
y1_max = [round(y1_max[i], 2) for i in range(len(y1_max))]
y2_min = [round(y2_min[i], 2) for i in range(len(y2_min))]
y2_max = [round(y2_max[i], 2) for i in range(len(y2_max))]
y3_min = [round(y3_min[i], 2) for i in range(len(y3_min))]
y3_max = [round(y3_max[i], 2) for i in range(len(y3_max))]
y4_min = [round(y4_min[i], 2) for i in range(len(y4_min))]
y4_max = [round(y4_max[i], 2) for i in range(len(y4_max))]

fig, axs = plt.subplots(1, 2, figsize=(14, 6))

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

# Plotting y1 vs y2 on the left subplot
axs[1].plot(m, y1, marker='o',markersize=1, linestyle='-', color='#bd7ebe', label='NodeIterator')
axs[1].errorbar(m, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#bd7ebe', alpha=0.5)
axs[1].plot(m, y2, marker='o',markersize=1, linestyle='-', color='#ffb55a', label='NodeIteratorPlusPlus')
axs[1].errorbar(m, y2, yerr=[y2_min, y2_max], capsize=5, label='_error', color='#ffb55a', alpha=0.5)

for i in range(len(m)):
    if(i!=3):
        if(i==1):
            text1 = axs[1].text(m[i], y1_raw_max[i]+6,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
        elif(i==2):
            text1 = axs[1].text(m[i], y1_raw_max[i-1]+2,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
        else:
            text1 = axs[1].text(m[i], y1_raw_max[i]+2,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
    else:
        text1 = axs[1].text(m[i], y1_raw_min[i]-2,f'{names[i]}\nn:{n[i]}', ha='center', va='top',fontsize = 7)
    text1.set_path_effects(add_contour(text1)) 

axs[1].set_xlabel('Number of edges (m)')
axs[1].set_title('Adjacency List')
axs[1].grid(True)
axs[1].set_xlim(16000, 93000)
axs[1].set_ylim(-1, 86)
axs[1].legend()
#set legent top left
axs[1].legend(loc='upper left')

# Plotting y3 vs y4 on the right subplot
axs[0].plot(m, y3, marker='o',markersize=1, linestyle='-', color='#fd7f6f', label='NodeIterator')
axs[0].errorbar(m, y3, yerr=[y3_min, y3_max], capsize=5, label='_error', color='#fd7f6f', alpha=0.5)
axs[0].plot(m, y4, marker='o',markersize=1, linestyle='-', color='#b2e061', label='NodeIteratorPlusPlus')
axs[0].errorbar(m, y4, yerr=[y4_min, y4_max], capsize=5, label='_error', color='#b2e061', alpha=0.5)

for i in range(len(m)):
    if(i!=3):
        if(i==1):
            text1 = axs[0].text(m[i], y4_raw_max[i]+600,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
        elif(i==2):
            text1 = axs[0].text(m[i], y4_raw_max[i-1]+200,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
        else:
            text1 = axs[0].text(m[i], y4_raw_max[i]+200,f'{names[i]}\nn:{n[i]}', ha='center', va='bottom',fontsize = 7)
    else:
        text1 = axs[0].text(m[i], y4_raw_min[i]-200,f'{names[i]}\nn:{n[i]}', ha='center', va='top',fontsize = 7)
    text1.set_path_effects(add_contour(text1)) 

axs[0].set_xlabel('Number of edges (m)')
axs[0].set_ylabel('Average Running Time (ms)')
axs[0].set_title('Adjacency Matrix')
axs[0].set_xlim(16000, 93000)
axs[0].set_ylim(-200, 12700)
axs[0].grid(True)
axs[0].legend()
axs[0].legend(loc='upper left')

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NodeIteratosMincreasingSet.png'))

plt.tight_layout()
plt.show()
