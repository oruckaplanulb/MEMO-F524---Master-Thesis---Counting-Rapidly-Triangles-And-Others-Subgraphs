import os
import matplotlib.pyplot as plt

counting_times = [10.5747,9.17554,6.98508,24.4381,15.163,5.18806,2.99529,5.38807,4.18887]
listing_times = [16.8584,14.7643,17.9552,43.0851,27.9288,19.5476,19.747,24.8366,23.2392]
counting_min = [8.9751,6.9435,6.0223,20.9458,12.9645,4.9538,1.9946,4.9549,3.9536]
counting_max = [11.9684,11.9696,7.9603,27.9285,17.9518,6.0094,4.0098,6.9767,5.0219]
listing_min = [15.9303,13.962,13.9491,39.8597,24.9313,17.9177,17.9517,22.9359,21.9416]
listing_max = [18.9481,15.9582,27.9532,51.8963,31.9254,21.9409,22.9386,28.8919,24.9362]

inputs = [f'p2p-Gnut24\n4Cycles={8794}',
          f'p2p-Gnut25\n4Cycles={13517}',
          f'p2p-Gnut04\n4Cycles={28497}',
          f'p2p-Gnut31\n4Cycles={42466}',
          f'p2p-Gnut30\n4Cycles={46363}',
          f'p2p-Gnut05\n4Cycles={64998}',
          f'p2p-Gnut08\n4Cycles={87885}',
          f'p2p-Gnut06\n4Cycles={90764}',
          f'p2p-Gnut09\n4Cycles={97902}']

bar_width = 0.30
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(12, 5), dpi=100)

alg1_bars = ax.bar(index, counting_times, bar_width, color="#b2e061", label='Normal Counting')

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.errorbar(i, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

alg2_bars = ax.bar([i + bar_width for i in index], listing_times, bar_width, color="#AABB77", label='Listing')

for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.errorbar(i + bar_width, v, yerr=[[v - vmin], [vmax - v]], fmt='', color='black', markersize=5, capsize=5)

ax.set_ylabel('Average Running Time (ms)')
ax.set_xticks([i + bar_width / 2 for i in index])
ax.set_xticklabels(inputs)
ax.legend()

for i, (v, vmin, vmax) in enumerate(zip(counting_times, counting_min, counting_max)):
    ax.text(i, vmax + 1, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)
for i, (v, vmin, vmax) in enumerate(zip(listing_times, listing_min, listing_max)):
    ax.text(i + bar_width, vmax + 1, f'+{vmax-v:.2f}\n{v:.2f}\n-{v-vmin:.2f}', ha='center', fontsize=8)

ax.set_ylim(top=max(counting_max + listing_max) * 1.2)

plt.title('4-Cycles counting vs listing For Peer-to-Peer Networks')
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'countingvslisting4cycles_p2p-Gnutella.png'))

plt.show()
