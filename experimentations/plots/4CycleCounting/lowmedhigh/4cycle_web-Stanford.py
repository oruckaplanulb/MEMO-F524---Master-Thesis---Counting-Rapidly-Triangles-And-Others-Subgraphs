import os
import matplotlib.pyplot as plt

counting_times = [885.535, 1377.32, 1559.23]
listing_times = [3034.29, 4101.19, 3662.31]
counting_min = [873.663, 1357.37, 1479.04]
counting_max = [902.62, 1422.23, 1770.3]
listing_min = [2915.2, 4028.19, 3582.45]
listing_max = [3205.46, 4234.7, 3897.61]

inputs = ['NodeIteratorPlusPlus', 'Forward', 'ChibaNishizeki']

bar_width = 0.30
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(5, 4), dpi=100)

alg1_bars = ax.bar(index, counting_times, bar_width, color="#fd7f6f", label='Counting')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.errorbar(i, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

alg2_bars = ax.bar([i + bar_width for i in index], listing_times, bar_width, color="#7eb0d5", label='Listing')

for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.errorbar(i + bar_width, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_ylabel('Average Running Time (ms)')
ax.set_xlabel('Algorithms')
ax.set_xticks([i + bar_width / 2 for i in index])
ax.set_xticklabels(inputs)
#set legend to the upper left
ax.legend(loc='upper left')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 100, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.text(i + bar_width, vmax + 100, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max + listing_max) * 1.2)

plt.title('For web-Stanford')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4cycle_web-Stanford.png'))

plt.show()
