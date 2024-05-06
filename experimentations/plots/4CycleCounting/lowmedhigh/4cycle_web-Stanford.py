import os
import matplotlib.pyplot as plt

counting_times = [528.088, 605.383, 982.775]
counting_min = [515.654, 596.372, 965.418]
counting_max = [572.471, 614.372, 1022.27]

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
ax.set_xticks([i for i in index])
ax.set_xticklabels(inputs)

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 50, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max) * 1.3)

plt.title('For web-Stanford')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4cycle_web-Stanford.png'))

plt.show()
