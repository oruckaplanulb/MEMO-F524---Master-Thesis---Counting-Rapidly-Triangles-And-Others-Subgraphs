import os
import matplotlib.pyplot as plt

counting_times = [130.155, 132.75, 358.744]
counting_min = [124.7, 128.656, 349.066]
counting_max = [154.624, 142.64, 374.998]

inputs = ['General', 'Vertex Local', 'Edge Local']

bar_width = 0.40
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(4, 3), dpi=100)

alg1_bars = ax.bar(index, counting_times, bar_width, color="#fd7f6f", label='Counting')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.errorbar(i, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_ylabel('Average Running Time (ms)')
ax.set_xlabel('Algorithms')
ax.set_xticks([i for i in index])
ax.set_xticklabels(inputs)
ax.legend(loc='upper left')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 10, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max ) * 1.3)

plt.title('For roadNet-PA')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4cycle_roadNet-PA.png'))

plt.show()
