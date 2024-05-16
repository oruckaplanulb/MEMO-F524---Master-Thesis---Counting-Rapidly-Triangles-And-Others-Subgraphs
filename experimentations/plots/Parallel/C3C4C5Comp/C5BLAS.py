import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25']
n = [1005, 4039, 7115, 12008, 22687]
x = [1,2,4,8,16]
y1 = [115.473, 84.2739, 65.8237, 64.0291, 286.434]
y2 = [5631.59, 3131.83, 2192.04, 2233.73, 2512.48]
y3 = [28904.9, 16221.9, 11320.3, 10995.5, 11889.9]
y4 = [134628, 77627.2, 50828.3, 50735.8, 55170.4]

y1_speedup = [y1[0]/y1[i] for i in range(len(y1))]
y2_speedup = [y2[0]/y2[i] for i in range(len(y2))]
y3_speedup = [y3[0]/y3[i] for i in range(len(y3))]
y4_speedup = [y4[0]/y4[i] for i in range(len(y4))]

plt.figure(figsize=(7, 4))

plt.plot(x, y4_speedup, label= 'ca-HepPh (ms)', color='#3366ff')
plt.plot(x, y3_speedup, label='wiki-Vote (ms)', color='#aaaa00')  
plt.plot(x, y2_speedup, label= 'ego-facebook (ms)', color='#ff5733')
plt.plot(x, y1_speedup, label='email-eu-core (ms)', color='#33ffbd')  

plt.scatter(x, y4_speedup, color='#3366ff')
plt.scatter(x, y3_speedup, color='#aaaa00')
plt.scatter(x, y2_speedup, color='#ff5733')
plt.scatter(x, y1_speedup, color='#33ffbd')

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    offset1 = 0
    offset2 = 0
    offset3 = 0
    offset4 = 0
    if (i == 1 or i == 0):
        offset3 = 0.2
        offset4 = 0.4
    if i == 2:
        offset2 = 0.05
        offset3 = 0.25
        offset4 = 0.35
    if i == 3:
        offset2 = 0.1
        offset3 = 0.2
        offset4 = 0.4
    if i == 4:
        offset2 = -0.3
        offset3 = 0.1
        offset4 = 0.3

    text1 = plt.text(x[i], y1_speedup[i]-0.1+offset1, f'{y1[i]:.2f}', ha='center', va='top', fontsize=8, color='#33dd33')
    text1.set_path_effects(add_contour(text1)) 
    
    text2 = plt.text(x[i], y2_speedup[i]+0.1+offset2, f'{y2[i]:.2f}', ha='center', va='bottom', fontsize=8, color='#ff5733')
    text2.set_path_effects(add_contour(text2))

    text3 = plt.text(x[i], y3_speedup[i]+0.1+offset3, f'{y3[i]:.2f}', ha='center', va='bottom', fontsize=8, color='#aaaa00')
    text3.set_path_effects(add_contour(text3))

    text4 = plt.text(x[i], y4_speedup[i]+0.1+offset4, f'{y4[i]:.2f}', ha='center', va='bottom', fontsize=8, color='#3366ff')
    text4.set_path_effects(add_contour(text4))

plt.xlabel('Number of threads')
plt.ylabel('Speedup')
plt.title('Counting C5 in parallel using BLAS SSYMM ')
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
plt.savefig(os.path.join(script_dir, 'C5BLAS.png'))

plt.show()
