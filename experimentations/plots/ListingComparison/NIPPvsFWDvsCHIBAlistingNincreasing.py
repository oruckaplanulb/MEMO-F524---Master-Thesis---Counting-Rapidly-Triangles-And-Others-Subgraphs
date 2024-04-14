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

y1 = [30.2226, 398.933, 241.458, 759.671, 9.87688, 649.267]  # NodeIteratorPlusPlus
y2 = [31.6184, 401.23, 270.975, 760.07, 23.1383, 940.388]  # Forward
y3 = [25.3314, 330.516, 191.689, 640.386, 28.6273, 637.299]  # Chiba

y1_raw_min = [27.9223, 367.018, 233.407, 739.022, 7.9786, 639.321]
y1_raw_max = [35.9332, 468.749, 264.328, 830.812, 12.9547, 693.146]
y2_raw_min = [29.9206, 374.997, 259.309, 746.003, 20.9437, 925.524]
y2_raw_max = [36.9367, 462.766, 331.077, 837.757, 26.9297, 995.338]
y3_raw_min = [22.9389, 306.176, 180.516, 626.325, 26.9265, 619.344]
y3_raw_max = [28.9233, 410.902, 221.374, 709.135, 33.9413, 664.224]

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
bars3 = axs.bar(x + width, y3, width, label='ChibaNishizeki', color='#7eb0d5')
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
plt.savefig(os.path.join(script_dir, 'NIPPvsFWDvsCHIBAlistingNincreasing.png'))

plt.show()
