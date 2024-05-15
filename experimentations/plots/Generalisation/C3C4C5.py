import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25']
x = [1005, 4039, 7115, 12008, 22687]  #X-axis values
y1 = [60.1391, 2788.24, 14125.4, 66958.3, 450139]  #C3
y2 = [69.3145, 2749.45, 15237.3, 67104, 458472]  #C4
y3 = [151.196, 4839.06, 23553.8, 103597, 691129]  #C5NI
y4 = [123.074, 5825.62, 29397.8, 137298, 981716]  #C5

y1_min = [60.1391-57.8439, 2788.24-2718.69, 14125.4-14037.5, 66958.3-66351.5, 450139-443666]
y1_max = [68.8174-60.1391, 2941.1-2788.24, 14300.8-14125.4, 68518.7-66958.3, 453212-450139]
y2_min = [69.3145-63.818, 2749.45-2704.77, 15237.3-14209, 67104-66065.3, 458472-451905]
y2_max = [75.8306-69.3145, 2826.47-2749.45, 19164.7-15237.3, 68777-67104, 489234-458472]
y3_min = [151.196-138.617, 4839.06-4774.24, 23553.8-22815, 103597-102394, 691129-675377]
y3_max = [198.468-151.196, 5017.58-4839.06, 25422-23553.8, 106312-103597, 729661-691129]
y4_min = [123.074-119.68, 5825.62-5647.86, 29397.8-29343.5, 137298-136558, 981716-961222]
y4_max = [131.68-123.074, 6058.79-5825.62, 29634.7-29397.8, 138405-137298, 1002410-981716]

plt.figure(figsize=(10, 6))

plt.plot(x, y4, label='counting C5 passing by A3', color='#3366ff')  #C5
plt.plot(x, y3, label='counting C5 without passing by A3', color='#ff338a')  #C5NI
plt.plot(x, y2, label='counting C4', color='#33ffbd')  #C4
plt.plot(x, y1, label='counting C3', color='#ff5733')  #C3

plt.errorbar(x, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#ff5733', alpha=0.5)  #C3
plt.errorbar(x, y2, yerr=[y2_min, y2_max], capsize=5, label='_error', color='#33ffbd', alpha=0.5)  #C4
plt.errorbar(x, y3, yerr=[y3_min, y3_max], capsize=5, label='_error', color='#ff338a', alpha=0.5)  #C5NI
plt.errorbar(x, y4, yerr=[y4_min, y4_max], capsize=5, label='_error', color='#3366ff', alpha=0.5)  #C5

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    text1 = plt.text(x[i] + 100, y1[i] - 12000, f'+{y1_max[i]:.2f}\n{y1[i]:.2f}\n-{y1_min[i]:.2f}', ha='left', va='top', fontsize=6, color='#ff5733')
    text1.set_path_effects(add_contour(text1)) 
    text2 = plt.text(x[i] + 100, y3[i] + 12000, f'+{y3_max[i]:.2f}\n{y3[i]:.2f}\n-{y3_min[i]:.2f}', ha='left', va='bottom', fontsize=6, color='#ff338a')
    text2.set_path_effects(add_contour(text2))
    
    text3 = plt.text(x[i] - 100, y2[i] - 12000, f'+{y2_max[i]:.2f}\n{y2[i]:.2f}\n-{y2_min[i]:.2f}', ha='right', va='top', fontsize=6, color='#33dd33')
    text3.set_path_effects(add_contour(text3)) 
    text4 = plt.text(x[i] - 100, y4[i] + 12000, f'+{y4_max[i]:.2f}\n{y4[i]:.2f}\n-{y4_min[i]:.2f}', ha='right', va='bottom', fontsize=6, color='#3366ff')
    text4.set_path_effects(add_contour(text4))

    #Graph name
    text5 = plt.text(x[i], y4[i]+y4_max[i]+120000, names[i], ha='center', va='top', fontsize=8, color='black')
    text5.set_path_effects(add_contour(text5))

plt.xlabel('Number of Vertices')
plt.ylabel('Running Time (ms)')
plt.title('C3, C4 and C5 generalisation comparison using BLAS SSYMM ')
plt.legend()

plt.xticks(range(0, 25001, 2500))
plt.yticks(range(-100000, 1000001, 100000))


plt.xlim(-1000, 25001)
plt.ylim(-90000, 1150000)


plt.grid(True)
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'C3C4C5.png'))

plt.show()
