import matplotlib.pyplot as plt
import os

alg_names = ['General Counting with Unordered set', 'Vertex-Local with Unordered set','General Counting with Vector', 'Vertex-Local with Vector', 'Edge-Local with Vector']
alg_times = [166.447, 185.059, 59.9568, 68.0686, 86.167]
alg_min_times = [155.692, 164.353, 57.9197, 65.6713, 78.3333]
alg_max_times = [190.367, 223.051, 69.5866, 73.843, 91.5604]

bar_width = 0.35
index = range(len(alg_names))

colors = ["#fd7f6f", "#7eb0d5", "#b2e061", "#bd7ebe", "#ffb55a"]

fig, ax = plt.subplots(figsize=(10, 5), dpi=100)

bars = ax.barh(index, alg_times, xerr=[[alg_times[i] - alg_min_times[i] for i in range(len(alg_times))], 
                                         [alg_max_times[i] - alg_times[i] for i in range(len(alg_times))]], 
               color=colors, alpha=0.6, capsize=3)

for i, (v, vmin, vmax) in enumerate(zip(alg_times, alg_min_times, alg_max_times)):
    ax.text(vmax + 1.5, i, f'{vmin:.2f}\n{v:.2f}\n{vmax:.2f}', va='center', fontsize=8)

ax.set_xlabel('Average Running Time (ms)')
ax.set_ylabel('Cases')
ax.set_yticks(index)
ax.set_yticklabels([])  # Remove y-axis labels
ax.invert_yaxis()
ax.legend(bars, alg_names, loc='lower right', handlelength=3)  # Add algorithm names to the legend
#set title
ax.set_title('4-Cycles counting comparison for ego-facebook')

plt.xlim(0, 250)
plt.tight_layout()

# Saving the plot
script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4CycleCountingFacebook.png'))

plt.show()
