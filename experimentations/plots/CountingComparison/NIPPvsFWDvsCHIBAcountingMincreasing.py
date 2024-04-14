import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut05', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30']
n = [6301, 8114, 8717, 8846, 10876, 22687, 26518, 36682]  #nb vertices
m = [20777, 26013, 31525, 31839, 39994, 54705, 65369, 88328]  #nb edges

ccavg = [0.0109, 0.0095, 0.0067, 0.0072, 0.0062, 0.0053, 0.0055, 0.0063]  #ccavg
dg = [0.105, 0.079, 0.083, 0.081, 0.068, 0.021, 0.019, 0.013] #d(G)
t = [2383, 2354, 1142, 1112, 934, 806, 986, 1590] #nb triangle

#create a new array with names, n, m and ccavg concatenated for xticks labels
xticks = [f'{names[i]}\nn = {n[i]}\nm = {m[i]}\nccavg = {ccavg[i]}\nd(G) = {dg[i]}%\nT = {t[i]}' for i in range(len(names))]

x = np.arange(len(names))
width = 0.30
fig, axs = plt.subplots(figsize=(14, 6))

y1 = [4.90702, 5.99806, 8.28788, 9.77894, 12.5685, 11.7892, 15.9657, 23.6532]  # NodeIteratorPlusPlus
y2 = [8.77364, 11.1736, 15.0601, 14.3621, 28.0281, 28.0252, 35.6051, 50.2689]  # Forward
y3 = [8.37751, 11.0695, 14.7634, 23.1417, 21.7451, 33.8135, 42.3894, 56.8511]  # Chiba

y1_raw_min = [4.0031, 4.9595, 6.9481, 6.0091, 8.983, 7.9985, 13.9959, 21.9394]
y1_raw_max = [6.0039, 7.0234, 11.0085, 12.9655, 15.959, 13.9665, 17.997, 25.9309]
y2_raw_min = [6.9812, 8.9742, 11.9678, 12.9598, 16.9546, 26.9276, 33.9067, 47.8708]
y2_raw_max = [11.941, 13.001, 17.9477, 15.9569, 50.8655, 31.9412, 37.9333, 55.853]
y3_raw_min = [6.9809, 9.9721, 11.9644, 13.9988, 16.9539, 31.9441, 41.8596, 54.8583]
y3_raw_max = [9.9732, 12.9654, 18.9224, 45.8771, 27.9538, 37.869, 42.916, 60.8684]

y1_min = [y1[i] - y1_raw_min[i] for i in range(len(y1))]
y1_max = [y1_raw_max[i] - y1[i] for i in range(len(y1))]
y2_min = [y2[i] - y2_raw_min[i] for i in range(len(y2))]
y2_max = [y2_raw_max[i] - y2[i] for i in range(len(y2))]
y3_min = [y3[i] - y3_raw_min[i] for i in range(len(y3))]
y3_max = [y3_raw_max[i] - y3[i] for i in range(len(y3))]

y1_min = [round(y1_min[i], 2) for i in range(len(y1_min))]
y1_max = [round(y1_max[i], 2) for i in range(len(y1_max))]
y2_min = [round(y2_min[i], 2) for i in range(len(y2_min))]
y2_max = [round(y2_max[i], 2) for i in range(len(y2_max))]
y3_min = [round(y3_min[i], 2) for i in range(len(y3_min))]
y3_max = [round(y3_max[i], 2) for i in range(len(y3_max))]

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

# Plotting y1 vs y2 on the left "#bd7ebe", "#ffb55a"
bars1 = axs.bar(x - width, y1, width, label='NodeIteratorPlusPlus', color='#ffb55a')
bars2 = axs.bar(x, y2, width, label='Forward (adapted for counting)', color='#fd7f6f')
bars3 = axs.bar(x + width, y3, width, label='ChibaNishizeki (adapted for counting)', color='#7eb0d5')
axs.errorbar(x - width, y1, yerr=[y1_min, y1_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.errorbar(x, y2, yerr=[y2_min, y2_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.errorbar(x + width, y3, yerr=[y3_min, y3_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.set_xticks(x)
axs.set_xticklabels(xticks)
for tick in axs.get_xticklabels():
    tick.set_fontsize(9)
axs.set_title('Comparison with NodeIteratorPlusPlus, Forward and ChibaNishizeki adapted for counting')
axs.legend()
axs.grid(True)
#axs.set_ylim(0, 2600)

# Adding number of vertices labels for the bars in the left plot
for bar1, bar2, bar3, i in zip(bars1, bars2, bars3, x):
    height1 = bar1.get_height()
    height2 = bar2.get_height()
    height3 = bar3.get_height()
    text1 = axs.text(bar1.get_x() + bar1.get_width()/2, height1 + y1_max[i] + 1, f'+{y1_max[i]}\n{y1[i]}\n-{y1_min[i]}', ha='center', va='bottom', fontsize=8)
    text1.set_path_effects(add_contour(text1))
    text2 = axs.text(bar2.get_x() + bar2.get_width()/2, height2 + y2_max[i] + 1, f'+{y2_max[i]}\n{y2[i]}\n-{y2_min[i]}', ha='center', va='bottom', fontsize=8)
    text2.set_path_effects(add_contour(text2))
    text3 = axs.text(bar3.get_x() + bar3.get_width()/2, height3 + y3_max[i] + 1, f'+{y3_max[i]}\n{y3[i]}\n-{y3_min[i]}', ha='center', va='bottom', fontsize=8)
    text3.set_path_effects(add_contour(text3))


axs.set_ylabel('Running Time (ms)')

plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NIPPvsFWDvsCHIBAcountingMincreasing.png'))

plt.show()
