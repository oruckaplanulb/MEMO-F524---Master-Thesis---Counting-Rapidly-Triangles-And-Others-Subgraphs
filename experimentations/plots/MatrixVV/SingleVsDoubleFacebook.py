import os
import matplotlib.pyplot as plt

singleP_times = [1594.24, 3062.32]
doubleP_times = [2832.51, 5552.86]
singleP_min = [1554.81, 3029.94]
singleP_max = [1751.35, 3118.67]
doubleP_min = [2776.61, 5459.4]
doubleP_max = [2968.09, 5606.03]

inputs = ['by Matrix Squaring', 'by Matrix Cube']

bar_width = 0.35
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(10, 3), dpi=100)

alg1_bars = ax.barh(index, singleP_times, bar_width, color="#fd7f6f", label='Single Precision (SGEMM)')

for i, (v, vmin, vmax) in enumerate(zip(singleP_times, singleP_min, singleP_max)):
    ax.errorbar(v, i, xerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

alg2_bars = ax.barh([i + bar_width for i in index], doubleP_times, bar_width, color="#7eb0d5", label='Double Precision (DGEMM)')

for i, (v, vmin, vmax) in enumerate(zip(doubleP_times, doubleP_min, doubleP_max)):
    ax.errorbar(v, i + bar_width, xerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_xlabel('Average Running Time (ms)')
ax.set_ylabel('Algorithm')
ax.set_yticks([i + bar_width / 2 for i in index])
ax.set_yticklabels(inputs)
ax.invert_yaxis()
ax.legend()

for i, (v, vmin, vmax) in enumerate(zip(singleP_times, singleP_min, singleP_max)):
    ax.text(vmax + 50, i, f'{vmin:.2f}\n{v:.2f}\n{vmax:.2f}', va='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(doubleP_times, doubleP_min, doubleP_max)):
    ax.text(vmax + 50, i + bar_width, f'{vmin:.2f}\n{v:.2f}\n{vmax:.2f}', va='center', fontsize=8)

ax.set_xlim(right=max(singleP_times + doubleP_times) * 1.1)

plt.subplots_adjust(right=0.9)

plt.title('For ego-facebook')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'SingleVsDoubleFacebook.png'))

plt.show()
