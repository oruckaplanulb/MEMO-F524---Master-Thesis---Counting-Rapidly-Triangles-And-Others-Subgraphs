import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25', 'cit-HepTh']
x = [1005, 4039, 7115, 12008, 22687, 27770]  # X-axis values
y1 = [75.805, 2791.85, 14459.5, 66535.1, 455675, 847219]  #Cube_SSYMM


y1_min = [75.805 - 68.8175, 2791.85 - 2751.64, 14459.5 - 14220, 66535.1 - 65828.9, 455675 - 444666, 847219 - 834184]
y1_max = [98.7342 - 75.805, 2917.2 - 2791.85, 15229.3 - 14459.5, 68202.6 - 66535.1, 472758 - 455675, 873585 - 847219]

plt.figure(figsize=(10, 6))

plt.plot(x, y1, label='', color='#ff5733')  #SSYMM

plt.errorbar(x, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#ff5733', alpha=0.5)  #SSYMM

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    #SSYMM colors
    text1 = plt.text(x[i] + 100, y1[i]+80000, f'+{y1_max[i]:.2f}\n{y1[i]:.2f}\n-{y1_min[i]:.2f}', ha='center', va='top', fontsize=6, color='#ff5733')
    text1.set_path_effects(add_contour(text1))  #Add contour to the text

    #Graph name
    text5 = plt.text(x[i], y1[i] + 110000, names[i], ha='center', va='top', fontsize=8, color='black')
    text5.set_path_effects(add_contour(text5))

plt.xlabel('Number of Vertices')
plt.ylabel('Running Time (ms)')
plt.title('Counting 4 cycles by Matrix Multiplication using SSYMM')

plt.xticks(range(0, 30001, 2500))
plt.yticks(range(-100000, 1000001, 100000))


# Padding at the bottom and right
plt.xlim(-1000, 30000)
plt.ylim(-90000, 990000)

# Show plot
plt.grid(True)
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'SSYLLNincreasing4Cycle.png'))

plt.show()
