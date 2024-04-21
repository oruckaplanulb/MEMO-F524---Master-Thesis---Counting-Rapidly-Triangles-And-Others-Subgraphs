import os
import matplotlib.pyplot as plt
import numpy as np

# Data
expeAmazon = [3.55702, 5.31552, 5.26645, 5.20289]
realAmazon = [2.80029, 4.74896, 5.17782, 5.04869]
expeCit = [3.85769, 5.37197]
realCit = [4.76114, 6.48595]
expeCol = [3.28013, 3.71424, 2.62369, 2.64461, 3.14481]
realCol = [5.04734, 4.95257, 4.00686, 3.95001, 2.79636]
expeCom = [7.49747, 56.3554, 75.5944]
realCom = [8.14471, 35.7011, 60.39]
expeNetg = [4.36946, 3.71349, 36.2733, 3.35748]
realNetg = [3.25652, 4.61413, 25.1553, 6.31732]
expeP2Pn = [3.36104, 3.19851, 3.99286, 3.87012, 3.46296, 3.21432, 3.24631, 3.31596]
realP2Pn = [3.45808, 4.99779, 4.19613, 5.4175, 4.21547, 3.57524, 3.99397, 4.05395]
expeRoadn = [2.2576, 2.25922, 2.25096]
realRoadn = [1.91044, 1.90363, 1.93493]
expeSocial = [2.89233, 5.49009, 5.52151, 6.23739, 6.32264, 4.14229]
realSocial = [4.66921, 8.20003, 7.26268, 7.33299, 7.17577, 4.30588]
expeWeb = [218.115, 25.1489, 19.5052, 162.43]
realWeb = [592.095, 28.0725, 32.0197, 277.785]

plt.figure(figsize=(12, 6))

# Scatter plot
plt.subplot(1, 2, 1)
plt.plot([1, 1000], [1, 1000], '--', color='gray', alpha=0.4)
plt.scatter(expeAmazon, realAmazon, label='Co-purchasing', color='blue')
plt.scatter(expeCit, realCit, label='Citation', color='red')
plt.scatter(expeCol, realCol, label='Collaboration', color='green')
plt.scatter(expeCom, realCom, label='Communication', color='orange')
plt.scatter(expeNetg, realNetg, label='Ground-truth', color='purple')
plt.scatter(expeP2Pn, realP2Pn, label='Peer-to-peer', color='brown')
plt.scatter(expeRoadn, realRoadn, label='Road', color='pink')
plt.scatter(expeSocial, realSocial, label='Social', color='cyan')
plt.scatter(expeWeb, realWeb, label='Web', color='magenta')

plt.xlabel('Expected Acceleration')
plt.ylabel('Real Acceleration')
plt.legend()

plt.xscale('log')
plt.yscale('log')
plt.grid(True, which='both', alpha=0.4)
plt.minorticks_on()
plt.xticks([1, 2, 5, 10, 20, 50, 100, 200, 500, 1000], ['1', '2', '5', '10', '20', '50', '100', '200', '500', '1000'])
plt.yticks([1, 2, 5, 10, 20, 50, 100, 200, 500, 1000], ['1', '2', '5', '10', '20', '50', '100', '200', '500', '1000'])

# Plotting the second plot with limited range
plt.subplot(1, 2, 2)
for i in range(len(expeAmazon)):
    if 1.5 <= expeAmazon[i] <= 10 and 1.5 <= realAmazon[i] <= 10:
        plt.scatter(expeAmazon[i], realAmazon[i], color='blue')
for i in range(len(expeCit)):
    if 1.5 <= expeCit[i] <= 10 and 1.5 <= realCit[i] <= 10:
        plt.scatter(expeCit[i], realCit[i], color='red')
for i in range(len(expeCol)):
    if 1.5 <= expeCol[i] <= 10 and 1.5 <= realCol[i] <= 10:
        plt.scatter(expeCol[i], realCol[i], color='green')
for i in range(len(expeCom)):
    if 1.5 <= expeCom[i] <= 10 and 1.5 <= realCom[i] <= 10:
        plt.scatter(expeCom[i], realCom[i], color='orange')
for i in range(len(expeNetg)):
    if 1.5 <= expeNetg[i] <= 10 and 1.5 <= realNetg[i] <= 10:
        plt.scatter(expeNetg[i], realNetg[i], color='purple')
for i in range(len(expeP2Pn)):
    if 1.5 <= expeP2Pn[i] <= 10 and 1.5 <= realP2Pn[i] <= 10:
        plt.scatter(expeP2Pn[i], realP2Pn[i], color='brown')
for i in range(len(expeRoadn)):
    if 1.5 <= expeRoadn[i] <= 10 and 1.5 <= realRoadn[i] <= 10:
        plt.scatter(expeRoadn[i], realRoadn[i], color='pink')
for i in range(len(expeSocial)):
    if 1.5 <= expeSocial[i] <= 10 and 1.5 <= realSocial[i] <= 10:
        plt.scatter(expeSocial[i], realSocial[i], color='cyan')
for i in range(len(expeWeb)):
    if 1.5 <= expeWeb[i] <= 10 and 1.5 <= realWeb[i] <= 10:
        plt.scatter(expeWeb[i], realWeb[i], color='magenta')

plt.xlabel('Expected Acceleration')
plt.ylabel('Real Acceleration')

plt.xscale('log')
plt.yscale('log')
plt.grid(True, which='both', alpha=0.4)
plt.minorticks_on()
plt.xticks([1.5, 2, 3, 4, 5, 6,7, 8, 9, 10], ['1.5', '2','3', '4', '5','6','7','8','9', '10'])
plt.yticks([1.5, 2, 3, 4, 5, 6,7, 8, 9, 10], ['1.5', '2','3', '4' ,'5','6','7','8','9', '10'])

# Plotting diagonal line for the second subplot
plt.plot([1.5, 10], [1.5, 10], '--', color='gray', alpha=0.4)

plt.suptitle('Expected vs Real Acceleration from Node Iterator to NodeIterator++')

plt.tight_layout()

# Saving the plot
script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, 'AccelerationAll.png'), dpi=150)

plt.show()
