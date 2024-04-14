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
width = 0.30
fig, axs = plt.subplots(figsize=(14, 6))

y1 = [12.1763, 99.044, 140.642, 138.552, 10.496, 370.032]  # NodeIteratorPlusPlus
y2 = [13.962, 95.5478, 144.716, 121.076, 24.0359, 531.479]  # Forward
y3 = [8.5806, 67.9185, 102.53, 86.173, 34.0115, 394.545]  # Chiba

y1_raw_min = [11.0039, 90.7396, 136.634, 134.676, 9.0092, 360.072]
y1_raw_max = [12.997, 111.691, 148.638, 146.637, 13.9597, 399.961]
y2_raw_min = [11.9667, 89.7934, 136.633, 118.683, 21.9412, 521.606]
y2_raw_max = [16.9829, 106.679, 162.6, 130.652, 27.9254, 569.446]
y3_raw_min = [6.9843, 58.8377, 97.7443, 82.7734, 27.9215, 382.976]
y3_raw_max = [10.0132, 76.7627, 107.712, 98.7732, 72.7975, 433.871]

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
#axs.set_ylim(0, 600)

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
plt.savefig(os.path.join(script_dir, 'NIPPvsFWDvsCHIBAcountingNincreasing.png'))

plt.show()
