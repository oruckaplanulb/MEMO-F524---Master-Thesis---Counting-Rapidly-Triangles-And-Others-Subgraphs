y1 = [77.8946, 431.257, 819.724, 580.832, 42.4882, 2363.49]  # NodeIteratorAdjList
y2 = [12.1763, 99.044, 140.642, 138.552, 10.496, 370.032]  # NodeIteratorPlusPlusAdjList
y3 = [59.4517, 850.139, 1743.45, 2986.42, 2826.36, 20730.7]  # NodeIteratorAdjMatrix
y4 = [38.9076, 440.334, 1053.09, 1856.15, 4218.64, 12564.2]  # NodeIteratorPlusPlusOrderedAdjMatrix

y1_raw_min = [70.8455, 410.884, 795.872, 547.536, 37.9336, 2327.78]
y1_raw_max = [104.721, 482.708, 850.717, 692.176, 54.8555, 2407.56]
y2_raw_min = [11.0039, 90.7396, 136.634, 134.676, 9.0092, 360.072]
y2_raw_max = [12.997, 111.691, 148.638, 146.637, 13.9597, 399.961]
y3_raw_min = [55.8837, 823.783, 1709.43, 2920.19, 2730.66, 20305.7]
y3_raw_max = [65.8714, 910.601, 1767.3, 3033.89, 2932.19, 21493.6]
y4_raw_min = [35.895, 418.878, 1034.22, 1816.15, 4137.94, 12317.1]
y4_raw_max = [43.8503, 498.7, 1092.07, 1898.92, 4298.54, 12806.8]

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