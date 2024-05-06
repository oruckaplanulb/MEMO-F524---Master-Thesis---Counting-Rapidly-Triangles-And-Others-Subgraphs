import os
import matplotlib.pyplot as plt

counting_times = [3.29192, 3.59269, 9.27523]
counting_min = [1.9945, 2.9815, 6.0133]
counting_max = [4.017, 4.9623, 15.9237]

inputs = ['General', 'Vertex Local', 'Edge Local']
colors = ['#b2e061','#bd7ebe','#ff5733']

bar_width = 0.40
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(4, 3), dpi=100)

alg1_bars = ax.bar(index, counting_times, bar_width, color=colors, label='Counting')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.errorbar(i, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_ylabel('Average Running Time (ms)')
ax.set_xlabel('Algorithms')
ax.set_xticks([i  for i in index])
ax.set_xticklabels(inputs)

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 0.5, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max) * 1.3)

plt.title('For p2p-Gnutella08')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4cycle_p2p-Gnutella08.png'))

plt.show()
