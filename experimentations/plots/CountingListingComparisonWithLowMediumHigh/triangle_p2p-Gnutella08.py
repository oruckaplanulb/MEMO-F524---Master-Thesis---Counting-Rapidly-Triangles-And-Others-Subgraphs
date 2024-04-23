import os
import matplotlib.pyplot as plt

counting_times = [3.99276, 7.87685, 10.0768]
listing_times = [5.08596, 8.77981, 13.0678]
counting_min = [2.9877, 5.9531, 7.9742]
counting_max = [5.0155, 9.9815, 12.0006]
listing_min = [2.9918, 6.979, 6.981]
listing_max = [6.997, 11.9947, 41.852]

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
ax.legend()

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 1, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.text(i + bar_width, vmax + 1, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max + listing_max) * 1.2)

plt.title('For p2p-Gnutella08')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'triangle_p2p-Gnutella08.png'))

plt.show()
