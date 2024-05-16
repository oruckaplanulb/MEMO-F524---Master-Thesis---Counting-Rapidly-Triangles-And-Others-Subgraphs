import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25']
n = [1005, 4039, 7115, 12008, 22687]
x = [1,2,4,8,16]
y1 = [3198.8, 1756.49, 1043.69, 2084.33, 2038.45]
y2 = [906370, 478138, 315787, 252305, 255982]

y1_speedup = [y1[0]/y1[i] for i in range(len(y1))]
y2_speedup = [y2[0]/y2[i] for i in range(len(y2))]

plt.figure(figsize=(7, 4))

plt.plot(x, y2_speedup, label= 'ego-facebook (ms)', color='#ff5733')
plt.plot(x, y1_speedup, label='email-eu-core (ms)', color='#33ffbd')  

plt.scatter(x, y1_speedup, color='#33ffbd')
plt.scatter(x, y2_speedup, color='#ff5733')

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    offset = 0
    if i == 2:
        offset = 0.4
    text1 = plt.text(x[i], y1_speedup[i]-0.1+offset, f'{y1[i]:.2f}', ha='center', va='top', fontsize=8, color='#33dd33')
    text1.set_path_effects(add_contour(text1)) 
    
    text3 = plt.text(x[i], y2_speedup[i]+0.1-offset, f'{y2[i]:.2f}', ha='center', va='bottom', fontsize=8, color='#ff5733')
    text3.set_path_effects(add_contour(text3)) 

plt.xlabel('Number of threads')
plt.ylabel('Speedup')
plt.title('Counting C3 in parallel using Naive Multiplication ')
plt.legend(loc='upper left')
plt.xscale('log', base=2)
plt.xticks(x,x)
plt.yticks([i/2 for i in range(0, 10, 1)])
plt.minorticks_on()

plt.grid(True, zorder=0)
plt.grid(which='minor', linestyle=':', linewidth='1', color='lightgrey', zorder=0)

plt.ylim(0, 4)

plt.tick_params(axis='both', which='major', labelsize=8)

plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'NaiveemailFacebook.png'))

plt.show()
