import os
import matplotlib.pyplot as plt

#["#fd7f6f", "#7eb0d5", "#b2e061", "#bd7ebe", "#ffb55a", "#ffee65", "#beb9db", "#fdcce5", "#8bd3c7"]
alg1_times = [3.45, 905.99, 5096.93]
alg2_times = [1.73, 456.47, 2418.44]

inputs = ['email-eu-core', 'ego-facebook', 'wiki-Vote']

bar_width = 0.35
index = range(len(inputs))

fig, ax = plt.subplots(figsize=(10, 3), dpi=100)
alg1_bars = ax.barh(index, alg1_times, bar_width, color="#fd7f6f", label='Matrix Cube')
alg2_bars = ax.barh([i + bar_width for i in index], alg2_times, bar_width, color="#7eb0d5", label='Matrix Squaring')

for i, v in enumerate(alg1_times):
    ax.text(v, i, str(v), va='center', ha='left', fontsize=9) 
for i, v in enumerate(alg2_times):
    ax.text(v, i + bar_width, str(v), va='center', ha='left', fontsize=9) 

ax.set_xlabel('Running Time (seconds)')
ax.set_ylabel('Graphs')
ax.set_yticks([i + bar_width / 2 for i in index])
ax.set_yticklabels(inputs)
ax.invert_yaxis()
ax.legend()

ax.set_xlim(right=max(alg1_times + alg2_times) * 1.1)

plt.tight_layout()

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
# Save the plot in the same directory as the script
plt.savefig(os.path.join(script_dir, 'NaiveNincreasing.png'))

plt.show()
