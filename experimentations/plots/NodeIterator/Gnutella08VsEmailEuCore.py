import os
import matplotlib.pyplot as plt

nodeIterator = [19.2519, 70.5131]
nodeIteratorplusplus = [4.19233, 11.4716]
ni_min = [16.9545, 62.8328]
ni_max = [24.9378, 87.8006]
nipp_min = [2.9886, 9.9733]
nipp_max = [5.9856, 12.9889]

inputs = [f'p2p-Gnutella08\nccavg: {0.0411}', f'email-Eu-core\nccavg: {0.3994}']

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
    ax.text(vmax + 1, i, f'-{v-vmin:.2f} | {v:.2f} | +{vmax-v:.2f}', va='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(nodeIteratorplusplus, nipp_min, nipp_max)):
    ax.text(vmax + 1, i + bar_width, f'-{v-vmin:.2f} | {v:.2f} | +{vmax-v:.2f}', va='center', fontsize=8)

ax.set_xlim(right=max(nodeIterator + nodeIteratorplusplus) * 1.3)

plt.subplots_adjust(right=0.9)

plt.title('Comparison with the average clustering coefficient')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'Gnutella08VsEmailEuCore.png'))

plt.show()
