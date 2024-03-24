import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['email-eu-core', 'ego-facebook', 'wiki-Vote', 'ca-HepPh', 'p2p-Gnutella25', 'cit-HepTh']
x = [1005, 4039, 7115, 12008, 22687, 27770]  # X-axis values
y1 = [50.272, 1594.24, 7884.23, 36253.2, 258631, 423290.0]  # SQUARE_SGEMM
y2 = [47.5808, 1637.14, 7848.04, 35590.6, 253533.0, 430125.0]  # SQUARE_SSYMM
y3 = [84.2148, 3062.32, 15432.5, 72320.1, 520383.0, 857926.0]  # CUBE_SGEMM
y4 = [82.4794, 3053.64, 15153.0, 70376.5, 502324.0, 850689.0]  # CUBE_SSYMM

y1_min = [50.272 - 43.9203, 1594.24 - 1554.81, 7884.23 - 7794.17, 36253.2 - 35727.5, 258631 - 254947.0, 423290.0 - 416294.0]
y1_max = [79.7560 - 50.272, 1751.35 - 1594.24, 8078.43 - 7884.23, 37430.9 - 36253.2, 265854.0 - 258631, 429604.0 - 423290.0]
y2_min = [47.5808 - 46.8652, 1637.14 - 1514.95, 7848.04 - 7660.52, 35590.6 - 35222.9, 253533.0 - 243195.0, 430125.0 - 417737.0]
y2_max = [50.8998 - 47.5808, 1869.01 - 1637.14, 8389.61 - 7848.04, 36342.9 - 35590.6, 264079.0 - 253533.0, 454766.0 - 430125.0]
y3_min = [84.2148 - 79.7903, 3062.32 - 3029.94, 15432.5 - 15302.1, 72320.1 - 71031.1, 520383.0 - 512115.0, 857926.0 - 848623.0]
y3_max = [105.967 - 84.2148, 3118.67 - 3062.32, 15607.3 - 15432.5, 74949.7 - 72320.1, 527861.0 - 520383.0, 865712.0 - 857926.0]
y4_min = [82.4794 - 77.7922, 3053.64 - 2989.09, 15153.0 - 15071.7, 70376.5 - 69612.1, 502324.0 - 491920.0, 850689.0 - 845556.0]
y4_max = [88.7619 - 82.4794, 3488.67 - 3053.64, 15640.2 - 15153.0, 74573.3 - 70376.5, 511877.0 - 502324.0, 860742.0 - 850689.0]

plt.figure(figsize=(10, 6))

plt.plot(x, y1, label='by Matrix Squaring using SGEMM', color='#ff5733')  # SGEMM
plt.plot(x, y2, label='by Matrix Squaring using SSYMM', color='#33ffbd')  # SSYMM
plt.plot(x, y3, label='by Matrix Cube using SGEMM', color='#ff338a')  # SGEMM
plt.plot(x, y4, label='by Matrix Cube using SSYMM', color='#3366ff')  # SSYMM

plt.errorbar(x, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#ff5733', alpha=0.5)  # SGEMM
plt.errorbar(x, y2, yerr=[y2_min, y2_max], capsize=5, label='_error', color='#33ffbd', alpha=0.5)  # SSYMM
plt.errorbar(x, y3, yerr=[y3_min, y3_max], capsize=5, label='_error', color='#ff338a', alpha=0.5)  # SGEMM
plt.errorbar(x, y4, yerr=[y4_min, y4_max], capsize=5, label='_error', color='#3366ff', alpha=0.5)  # SSYMM

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    #SGEMM colors
    text1 = plt.text(x[i] + 100, y1[i] - 12000, f'+{y1_max[i]:.2f}\n{y1[i]:.2f}\n-{y1_min[i]:.2f}', ha='left', va='top', fontsize=6, color='#ff5733')
    text1.set_path_effects(add_contour(text1))  # Add contour to the text
    text2 = plt.text(x[i] + 100, y3[i] + 12000, f'+{y3_max[i]:.2f}\n{y3[i]:.2f}\n-{y3_min[i]:.2f}', ha='left', va='bottom', fontsize=6, color='#ff338a')
    text2.set_path_effects(add_contour(text2))  # Add contour to the text
    
    #SSYMM colors
    text3 = plt.text(x[i] - 100, y2[i] - 12000, f'+{y2_max[i]:.2f}\n{y2[i]:.2f}\n-{y2_min[i]:.2f}', ha='right', va='top', fontsize=6, color='#33dd33')
    text3.set_path_effects(add_contour(text3))  # Add contour to the text
    text4 = plt.text(x[i] - 100, y4[i] + 12000, f'+{y4_max[i]:.2f}\n{y4[i]:.2f}\n-{y4_min[i]:.2f}', ha='right', va='bottom', fontsize=6, color='#3366ff')
    text4.set_path_effects(add_contour(text4))  # Add contour to the text

    #Graph name
    text5 = plt.text(x[i], y3[i] + 110000, names[i], ha='center', va='top', fontsize=8, color='black')
    text5.set_path_effects(add_contour(text5))

plt.xlabel('Number of Vertices')
plt.ylabel('Running Time (ms)')
plt.title('BLAS functions comparison over n')
plt.legend()

plt.xticks(range(0, 30001, 2500))
plt.yticks(range(-100000, 1000001, 100000))


# Padding at the bottom and right
plt.xlim(-1000, 30000)
plt.ylim(-90000, 990000)

# Show plot
plt.grid(True)
plt.tight_layout()

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'SGEMMvsSSYMMNincreasing.png'))

plt.show()
