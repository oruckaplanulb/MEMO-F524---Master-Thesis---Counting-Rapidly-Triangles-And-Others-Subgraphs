import os
import matplotlib.pyplot as plt

nodeIterator = [10026.1, 255027]
nodeIteratorplusplus = [303.213, 933.322]
ni_min = [9943.41, 239451]
ni_max = [10207.7, 281171]
nipp_min = [300.229, 914.55]
nipp_max = [307.211, 966.448]

inputs = [f'web-NotreDame\nccavg: {0.2346}',f'web-Stanford\nccavg: {0.0465}',]

bar_width = 0.22
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(10, 2.2), dpi=100)

alg1_bars = ax.barh(index, nodeIterator, bar_width, color="#fd7f6f", label='Node Iterator')

for i, (v, vmin, vmax) in enumerate(zip(nodeIterator, ni_min, ni_max)):
    ax.errorbar(v, i, xerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

alg2_bars = ax.barh([i + bar_width for i in index], nodeIteratorplusplus, bar_width, color="#7eb0d5", label='Node IteratorPlusPlus')

for i, (v, vmin, vmax) in enumerate(zip(nodeIteratorplusplus, nipp_min, nipp_max)):
    ax.errorbar(v, i + bar_width, xerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_xlabel('Average Running Time (ms)')
ax.set_ylabel('Graphs')
ax.set_yticks([i + bar_width / 2 for i in index])
ax.set_yticklabels(inputs)
ax.invert_yaxis()
ax.legend()

for i, (v, vmin, vmax) in enumerate(zip(nodeIterator, ni_min, ni_max)):
    ax.text(vmax + 50, i, f'-{v-vmin:.2f} | {v:.2f} | +{vmax-v:.2f}', va='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(nodeIteratorplusplus, nipp_min, nipp_max)):
    ax.text(vmax + 50, i + bar_width, f'-{v-vmin:.2f} | {v:.2f} | +{vmax-v:.2f}', va='center', fontsize=8)

ax.set_xlim(right=max(nodeIterator + nodeIteratorplusplus) * 1.3)

plt.subplots_adjust(right=0.9)

plt.title('Comparison with the average clustering coefficient')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NotreDameVsStanford.png'))

plt.show()
