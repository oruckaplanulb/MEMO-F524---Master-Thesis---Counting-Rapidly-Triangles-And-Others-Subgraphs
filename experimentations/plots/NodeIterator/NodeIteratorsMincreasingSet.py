import os
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut05', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']

m = [20777, 26013, 31525, 31839, 39994, 54705, 65369, 88328, 147892]  #nb edges

y1 = [26.138, 30.5191, 32.5263, 33.4306, 41.8965, 46.6879, 63.0419, 82.9869, 142.834]  # NodeIteratorAdjList
y2 = [4.90702, 5.99806, 8.28788, 9.77894, 12.5685, 11.7892, 15.9657, 23.6532, 38.4171]  # NodeIteratorPlusPlusAdjList
y3 = [316.271, 503.967, 621.351, 643.692, 966.029, 2842.14, 3904.67, 7390.76, 52220.3]  # NodeIteratorAdjMatrix
y4 = [359.444, 584.758, 685.184, 708.314, 1059.87, 4170.06, 6029.59, 11337.6, 144125]  # NodeIteratorPlusPlusOrderedAdjMatrix

y1_raw_min = [22.9375, 25.9427, 29.9194, 31.944, 39.9297, 40.9299, 57.8345, 77.7907, 141.618]
y1_raw_max = [42.9118, 34.9455, 34.9051, 33.9454, 44.9095, 56.8482, 75.8024, 86.7884, 149.632]
y2_raw_min = [4.0031, 4.9595, 6.9481, 6.0091, 8.983, 7.9985, 13.9959, 21.9394, 35.9427]
y2_raw_max = [6.0039, 7.0234, 11.0085, 12.9655, 15.959, 13.9665, 17.997, 25.9309, 40.9259]
y3_raw_min = [303.185, 480.717, 589.395, 621.339, 938.492, 2721.72, 3797.85, 7208.76, 32255.2]
y3_raw_max = [342.087, 529.62, 656.268, 668.213, 986.397, 2918.2, 4099.04, 7812.14, 85306.9]
y4_raw_min = [342.087, 562.493, 665.221, 685.167, 1043.21, 4115.99, 5913.18, 11183.1, 125071]
y4_raw_max = [384.006, 618.381, 732.032, 742.016, 1115.04, 4237.69, 6167.54, 11683.8, 174352]

#remove the last data from y* and m
#y1 = y1[:-1]
#y2 = y2[:-1]
#y3 = y3[:-1]
#y4 = y4[:-1]
#y1_raw_min = y1_raw_min[:-1]
#y1_raw_max = y1_raw_max[:-1]
#y2_raw_min = y2_raw_min[:-1]
#y2_raw_max = y2_raw_max[:-1]
#y3_raw_min = y3_raw_min[:-1]
#y3_raw_max = y3_raw_max[:-1]
#y4_raw_min = y4_raw_min[:-1]
#y4_raw_max = y4_raw_max[:-1]
#m = m[:-1]


y1_min = [y1[i] - y1_raw_min[i] for i in range(len(y1))]
y1_max = [y1_raw_max[i] - y1[i] for i in range(len(y1))]
y2_min = [y2[i] - y2_raw_min[i] for i in range(len(y2))]
y2_max = [y2_raw_max[i] - y2[i] for i in range(len(y2))]
y3_min = [y3[i] - y3_raw_min[i] for i in range(len(y3))]
y3_max = [y3_raw_max[i] - y3[i] for i in range(len(y3))]
y4_min = [y4[i] - y4_raw_min[i] for i in range(len(y4))]
y4_max = [y4_raw_max[i] - y4[i] for i in range(len(y4))]

y1_min = [round(y1_min[i], 2) for i in range(len(y1_min))]
y1_max = [round(y1_max[i], 2) for i in range(len(y1_max))]
y2_min = [round(y2_min[i], 2) for i in range(len(y2_min))]
y2_max = [round(y2_max[i], 2) for i in range(len(y2_max))]
y3_min = [round(y3_min[i], 2) for i in range(len(y3_min))]
y3_max = [round(y3_max[i], 2) for i in range(len(y3_max))]
y4_min = [round(y4_min[i], 2) for i in range(len(y4_min))]
y4_max = [round(y4_max[i], 2) for i in range(len(y4_max))]

fig, axs = plt.subplots(1, 2, figsize=(14, 6))

# Plotting y1 vs y2 on the left subplot
axs[0].plot(m, y1, marker='o', linestyle='-', color='b', label='NodeIteratorAdj')
axs[0].fill_between(m, np.array(y1) - np.array(y1_min), np.array(y1) + np.array(y1_max), color='blue', alpha=0.2)
axs[0].plot(m, y2, marker='o', linestyle='-', color='r', label='NodeIteratorPlusPlus')
axs[0].fill_between(m, np.array(y2) - np.array(y2_min), np.array(y2) + np.array(y2_max), color='red', alpha=0.2)
axs[0].set_xlabel('Number of edges (m)')
axs[0].set_ylabel('Running Time')
axs[0].set_title('AdjList')
axs[0].legend()

# Plotting y3 vs y4 on the right subplot
axs[1].plot(m, y3, marker='o', linestyle='-', color='g', label='NodeIterator')
axs[1].fill_between(m, np.array(y3) - np.array(y3_min), np.array(y3) + np.array(y3_max), color='green', alpha=0.2)
axs[1].plot(m, y4, marker='o', linestyle='-', color='m', label='NodeIteratorPlusPlusOrdered')
axs[1].fill_between(m, np.array(y4) - np.array(y4_min), np.array(y4) + np.array(y4_max), color='magenta', alpha=0.2)
axs[1].set_xlabel('Number of edges (m)')
axs[1].set_ylabel('Running Time')
axs[1].set_title('AdjMatrix')
axs[1].legend()

plt.tight_layout()
plt.show()
