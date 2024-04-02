import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25', 'cit-HepTh']
n = [1005, 4039, 7115, 12008, 22687, 27770]  #nb vertices
m = [16064, 88234, 100762, 118489, 54705, 352285]  #nb edges
ccavg = [0.3994, 0.6055, 0.1409, 0.6115, 0.0106, 0.3120]  #ccavg
dg = [3.184, 1.082, 0.398, 0.164, 0.021, 0.091] #d(G)
t = [105461, 1612010, 608389, 3358499, 806, 1478735] #nb triangle

#create a new array with names, n, m and ccavg concatenated for xticks labels
xticks = [f'{names[i]}\nn = {n[i]}\nm = {m[i]}\nccavg = {ccavg[i]}\nd(G) = {dg[i]}%\nT = {t[i]}' for i in range(len(names))]

x = np.arange(len(names))
width = 0.35
fig, axs = plt.subplots(1, 2, figsize=(14, 6))

y1 = [77.8946, 431.257, 819.724, 580.832, 42.4882, 2363.49]  # NodeIteratorAdjList
y2 = [12.1763, 99.044, 140.642, 138.552, 10.496, 370.032]  # NodeIteratorPlusPlusAdjList
y3 = [59.4517, 850.139, 1743.45, 2986.42, 2826.36, 20730.7]  # NodeIteratorAdjMatrix
y4 = [38.9076, 440.334, 1053.09, 1856.15, 4218.64, 12564.2]  # NodeIteratorPlusPlusOrderedAdjMatrix

y1_raw_min = [70.8455, 410.884, 795.872, 547.536, 37.9336, 2327.78]
y1_raw_max = [104.721, 482.708, 850.717, 692.176, 54.8555, 2407.56]
y2_raw_min = [11.0039, 90.7396, 136.634, 134.676, 9.0092, 360.072]
y2_raw_max = [12.997, 111.691, 148.638, 146.637, 13.9597, 399.961]
y3_raw_min = [55.8837, 823.783, 1709.43, 2920.19, 2730.66, 20305.7]
y3_raw_max = [65.8714, 910.601, 1767.3, 3033.89, 2932.19, 21493.6]
y4_raw_min = [35.895, 418.878, 1034.22, 1816.15, 4137.94, 12317.1]
y4_raw_max = [43.8503, 498.7, 1092.07, 1898.92, 4298.54, 12806.8]

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

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

# Plotting y1 vs y2 on the left "#bd7ebe", "#ffb55a"
bars1 = axs[0].bar(x - width/2, y1, width, label='NodeIterator', color='#bd7ebe')
bars2 = axs[0].bar(x + width/2, y2, width, label='NodeIteratorPlusPlus', color='#ffb55a')
axs[0].errorbar(x - width/2, y1, yerr=[y1_min, y1_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs[0].errorbar(x + width/2, y2, yerr=[y2_min, y2_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs[0].set_xticks(x)
axs[0].set_xticklabels(xticks)
for tick in axs[0].get_xticklabels():
    tick.set_fontsize(8)
axs[0].set_title('Adjacency List')
axs[0].legend()
axs[0].grid(True)
axs[0].set_ylim(0, 2600)

# Adding number of vertices labels for the bars in the left plot
for bar1, bar2, i in zip(bars1, bars2, x):
    height1 = bar1.get_height()
    height2 = bar2.get_height()
    text1 = axs[0].text(bar1.get_x() + bar1.get_width()/2, height1 + y1_max[i] + 10, f'+{y1_max[i]}\n{y1[i]}\n-{y1_min[i]}', ha='center', va='bottom', fontsize=6)
    text1.set_path_effects(add_contour(text1))
    text2 = axs[0].text(bar2.get_x() + bar2.get_width()/2, height2 + y2_max[i] + 10, f'+{y2_max[i]}\n{y2[i]}\n-{y2_min[i]}', ha='center', va='bottom', fontsize=6)
    text2.set_path_effects(add_contour(text2))

# Plotting y3 vs y4 on the right "#fd7f6f", "#b2e061"
bars3 = axs[1].bar(x - width/2, y3, width, label='NodeIterator', color='#fd7f6f')
bars4 = axs[1].bar(x + width/2, y4, width, label='NodeIteratorPlusPlus', color='#b2e061')
axs[1].errorbar(x - width/2, y3, yerr=[y3_min, y3_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs[1].errorbar(x + width/2, y4, yerr=[y4_min, y4_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs[1].set_xticks(x)
axs[1].set_xticklabels(xticks)
#set xtick labels smaller
for tick in axs[1].get_xticklabels():
    tick.set_fontsize(8)
axs[1].set_title('Adjacency Matrix')
axs[1].legend()
axs[1].grid(True)
axs[1].set_ylim(0, 23400)

for bar3, bar4, i in zip(bars3, bars4, x):
    height3 = bar3.get_height()
    height4 = bar4.get_height()
    text3 = axs[1].text(bar3.get_x() + bar4.get_width()/2, height3 + y3_max[i] + 100, f'+{y3_max[i]}\n{y3[i]}\n-{y3_min[i]}', ha='center', va='bottom', fontsize=6)
    text3.set_path_effects(add_contour(text3))
    text4 = axs[1].text(bar4.get_x() + bar3.get_width()/2, height4 + y4_max[i] + 100, f'+{y4_max[i]}\n{y4[i]}\n-{y4_min[i]}', ha='center', va='bottom', fontsize=6)
    text4.set_path_effects(add_contour(text4))

axs[0].set_ylabel('Time (ms)')


plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NodeIteratosNincreasingSet.png'))

plt.show()
