import matplotlib.pyplot as plt
import os

# Data for each graph
graph_data = {
    "roadNet-PA": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                   [908765, 71439, 1974, 99501, 12, 482, 2640, 0, 0, 3279, 0]),
    "p2p-Gnutella08": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                       [6119, 130, 11, 32, 0, 0, 1, 0, 0, 8, 0]),
    "soc-Slashdot0811": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                          [68802, 3044, 1017, 1513, 193, 294, 367, 21, 69, 2040, 0]),
    "web-NotreDame": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                       [210376, 6394, 4309, 20155, 4927, 12830, 13149, 6334, 13843, 33412, 0]),
    "com-youtube": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                    [949360, 53182, 23316, 34687, 5477, 8094, 10643, 313, 1541, 48277, 0]),
    "com-dblp": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1],
                    [55009, 16465, 16514, 19216, 15432, 15920, 13584, 4355, 6627, 153958, 0]),
    "ego-Facebook": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1],
                        [81, 27, 154, 344, 619, 831, 711, 465, 380, 427, 0]),
    "WikiTalk": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                  [2170642, 48448, 20689, 47176, 4528, 7397, 14062, 174, 1135, 80134, 0]),
    "web-BerkStan": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                      [116493, 21632, 23542, 38656, 35155, 48152, 95057, 37648, 70250, 198645, 0]),
    "web-Stanford": ([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1], 
                      [46643, 7124, 7567, 15512, 10482, 28541, 40941, 13533, 39042, 72518, 0]),
}

# Plotting each graph's data
i = 0
for key, (x_values, y_values) in graph_data.items():
    i += 1
    if i in [1, 2, 3]:
        color = '#fd7f6f'
    elif i in [4, 5, 6, 7]:
        color = '#ffb55a'
    else:
        color = '#7eb0d5'

    bar_positions = range(len(x_values))
    plt.figure(figsize=(6, 5))
    plt.bar(bar_positions, y_values, color=color, width=1.0, align='edge', edgecolor='black')
    plt.xlabel('Clustering Coefficient')
    plt.ylabel('Number of Vertices')
    plt.title(f'Distribution of Clustering Coefficient for {key}')
    plt.xticks(bar_positions, x_values)
    plt.xlim(0, 10)
    plt.yscale('log')
    plt.tight_layout()
    script_dir = os.path.dirname(os.path.abspath(__file__))
    plt.savefig(os.path.join(script_dir, f'CCdistributionLOG-{key}.png'))
    plt.show()
