import os
import matplotlib.pyplot as plt

counting_times = [3171.38, 4111.9, 5258.2]
listing_times = [15444, 20527.7, 19023.1]
counting_min = [3134.62, 4039.23, 4849.03]
counting_max = [3232.95, 4177.83, 5672.83]
listing_min = [15149.5, 19018.8, 17743.1]
listing_max = [15733.9, 21566, 19748.8]

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
    ax.text(i, vmax + 500, f'+{vmax-v:.2f}\n{v:.1f}\n-{v-vmin:.2f}', ha='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.text(i + bar_width, vmax + 500, f'+{vmax-v:.1f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max + listing_max) * 1.2)

plt.title('For web-BerkStan')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4cycle_web-BerkStan.png'))

plt.show()
