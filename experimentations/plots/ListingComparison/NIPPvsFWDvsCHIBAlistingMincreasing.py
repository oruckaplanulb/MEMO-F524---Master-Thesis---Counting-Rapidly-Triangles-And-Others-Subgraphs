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

y1 = [4.5875, 5.8875, 7.18653, 6.58273, 8.87649, 10.073, 12.5667, 18.6537]  # NodeIteratorPlusPlus
y2 = [7.88158, 10.5691, 13.3675, 12.7664, 20.4483, 26.7303, 34.9102, 48.5732]  # Forward
y3 = [8.58029, 11.4695, 16.0572, 16.8578, 22.2405, 32.4135, 41.0904, 56.8483]  # Chiba

y1_raw_min = [2.9868, 3.9938, 4.9866, 4.9823, 6.9822, 7.9784, 10.9705, 16.9528]
y1_raw_max = [5.9978, 6.932, 10.9717, 8.0093, 10.9747, 12.9981, 14.9607, 22.9429]
y2_raw_min = [6.9743, 8.9759, 11.9678, 10.9697, 17.9446, 23.9363, 33.9054, 45.8746]
y2_raw_max = [8.9761, 12.9659, 15.9914, 16.925, 24.9347, 29.9397, 37.9024, 54.8522]
y3_raw_min = [7.0146, 9.9733, 12.9649, 13.9953, 19.9446, 30.9167, 39.8931, 54.8529]
y3_raw_max = [9.9701, 13.9645, 26.8971, 23.936, 25.9286, 34.9057, 43.8863, 60.8373]

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
bars1 = axs.bar(x - width, y1, width, label='NodeIteratorPlusPlus (adapted for listing)', color='#ffb55a')
bars2 = axs.bar(x, y2, width, label='Forward', color='#fd7f6f')
bars3 = axs.bar(x + width, y3, width, label='ChibaNishizeki ', color='#7eb0d5')
axs.errorbar(x - width, y1, yerr=[y1_min, y1_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.errorbar(x, y2, yerr=[y2_min, y2_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.errorbar(x + width, y3, yerr=[y3_min, y3_max], fmt='none', capsize=5, color='black', alpha=0.5)
axs.set_xticks(x)
axs.set_xticklabels(xticks)
for tick in axs.get_xticklabels():
    tick.set_fontsize(9)
axs.set_title('Comparison of Forward, ChibaNishizeki and NodeIteratorPlusPlus adapted for listing')
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
plt.savefig(os.path.join(script_dir, 'NIPPvsFWDvsCHIBAlistingMincreasing.png'))

plt.show()
