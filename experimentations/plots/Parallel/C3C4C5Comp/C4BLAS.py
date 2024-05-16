import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25']
n = [1005, 4039, 7115, 12008, 22687]
x = [1,2,4,8,16]
y1 = [62.5366, 46.1789, 43.8826, 39.9899, 125.265]
y2 = [2871.46, 1610.09, 1088.49, 1045, 1221.24]
y3 = [14695.8, 8216.53, 5568.41, 5579.78, 5677.92]
y4 = [68528.4, 38238.8, 25577.2, 26040.7, 26257.8]

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
    if i != 4:
        offset3 = 0.2
        offset4 = 0.4
    if i == 3:
        offset3 = 0.25
    if i == 4:
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
plt.title('Counting C4 in parallel using BLAS SSYMM ')
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
plt.savefig(os.path.join(script_dir, 'C4BLAS.png'))

plt.show()
