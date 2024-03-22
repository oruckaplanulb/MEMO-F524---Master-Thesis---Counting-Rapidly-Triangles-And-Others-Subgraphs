import matplotlib.pyplot as plt
import os

alg_names = ['NodeIterator with AdjMatrix', 'NodeIteratorPlusPlus with AdjMatrix','NodeIteratorPlusPlusOrdered with AdjMatrix', 'NodeIterator with AdjList', 'NodeIteratorPlusPlus with AdjList']
alg_times = [887.135, 6368.27, 443.727, 425.964, 96.556]
alg_min_times = [849.731, 6215.38, 427.824, 417.878, 92.7837]
alg_max_times = [945.467, 6737.02, 482.74, 450.794, 107.744]

bar_width = 0.35
index = range(len(alg_names))

colors = ["#fd7f6f", "#7eb0d5", "#b2e061", "#bd7ebe", "#ffb55a"]

fig, ax = plt.subplots(figsize=(10, 5), dpi=100)

bars = ax.barh(index, alg_times, xerr=[[alg_times[i] - alg_min_times[i] for i in range(len(alg_times))], 
                                         [alg_max_times[i] - alg_times[i] for i in range(len(alg_times))]], 
               color=colors, alpha=0.6, capsize=3)

for i, (v, vmin, vmax) in enumerate(zip(alg_times, alg_min_times, alg_max_times)):
    ax.text(vmax + 50, i, f'{vmin:.2f}\n{v:.2f}\n{vmax:.2f}', va='center', fontsize=8)

ax.set_xlabel('Average Running Time (ms)')
ax.set_ylabel('Cases')
ax.set_yticks(index)
ax.set_yticklabels([])  # Remove y-axis labels
ax.invert_yaxis()
ax.legend(bars, alg_names, loc='lower right', handlelength=3)  # Add algorithm names to the legend
#set title
ax.set_title('NodeIterators comparaison for ego-facebook')

plt.xlim(0, 7250)
plt.tight_layout()

# Saving the plot
script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NodeIteratorsFacebook.png'))

plt.show()
