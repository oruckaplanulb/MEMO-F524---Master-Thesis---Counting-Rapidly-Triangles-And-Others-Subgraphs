import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut05', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']
x = [6301, 8114, 8717, 8846, 10876, 22687, 26518, 36682, 62586]  #nb vertices
m = [20777, 26013, 31525, 31839, 39994, 54705, 65369, 88328, 147892]  #nb edges
y1 = [21.3461, 33.6098, 39.6938, 41.3887, 55.6506, 207.548, 279.057, 527.988, 1492.53] # Edge Local Counting
y2 = [6.18349, 8.17791, 13.1646, 10.2747, 14.4648, 21.6449, 29.2253, 35.7078, 61.8343]  # Vertex Local Counting
y3 = [5.98682, 7.58308, 10.0766, 11.7712, 15.6578, 14.0658, 18.9513, 27.7293, 57.6493]  # Counting

y1_min = [21.3461-19.9465, 33.6098-31.9132, 39.6938-35.9039, 41.3887-37.8985, 55.6506-52.8572, 207.548-197.471, 279.057-275.264, 527.988-514.623, 1492.53-1451.12]
y1_max = [23.9366-21.3461, 37.8657-33.6098, 43.9128-39.6938, 45.8992-41.3887, 63.8597-55.6506, 239.395-207.548, 289.261-279.057, 564.457-527.988, 1605.74-1492.53]
y2_min = [6.18349-4.9553, 8.17791-6.9454, 13.1646-10.9709, 10.2747-7.9784, 14.4648-10.971, 21.6449-17.9235, 29.2253-18.952, 35.7078-27.9252, 61.8343-57.8397]
y2_max = [7.0104-6.18349, 10.9763-8.17791, 14.9603-13.1646, 12.9641-10.2747, 17.9789-14.4648, 26.9281-21.6449, 64.8266-29.2253, 43.89-35.7078, 72.8348-61.8343]
y3_min = [5.98682-4.9864, 7.58308-5.9812, 10.0766-7.9838, 11.7712-9.9727, 15.6578-11.9681, 14.0658-11.9666, 18.9513-15.9605, 27.7293-24.931, 57.6493-54.8503]
y3_max = [7.9792-5.98682, 8.9781-7.58308, 11.9658-10.0766, 16.9552-11.7712, 18.9749-15.6578, 16.9518-14.0658, 21.977-18.9513, 34.9425-27.7293, 68.8191-57.6493]

plt.figure(figsize=(10, 6))

plt.plot(x, y1, label='Edge Local Counting', color='#ff5733')  # Edge Local Counting
plt.plot(x, y2, label='Vertex Local Counting', color='#33ffbd')  # Vertex Local Counting
plt.plot(x, y3, label='Counting', color='#ff338a')  # Counting

plt.errorbar(x, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#ff5733', alpha=0.5)
plt.errorbar(x, y2, yerr=[y2_min, y2_max], capsize=5, label='_error', color='#33ffbd', alpha=0.5)
plt.errorbar(x, y3, yerr=[y3_min, y3_max], capsize=5, label='_error', color='#ff338a', alpha=0.5)

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(len(x)):
    #SGEMM colors
    text1 = plt.text(x[i], y1[i] , f'+{y1_max[i]:.2f}\n{y1[i]:.2f}\n-{y1_min[i]:.2f}', ha='left', va='top', fontsize=6, color='#ff5733')
    text1.set_path_effects(add_contour(text1))  # Add contour to the text
    text2 = plt.text(x[i], y2[i], f'+{y2_max[i]:.2f}\n{y3[i]:.2f}\n-{y3_min[i]:.2f}', ha='center', va='bottom', fontsize=6, color='#ff338a')
    text2.set_path_effects(add_contour(text2))  # Add contour to the text
    text3 = plt.text(x[i], y3[i], f'+{y3_max[i]:.2f}\n{y2[i]:.2f}\n-{y2_min[i]:.2f}', ha='center', va='top', fontsize=6, color='#33dd33')
    text3.set_path_effects(add_contour(text3))  # Add contour to the text

    #Graph name
    text5 = plt.text(x[i], y1[i]+200, names[i], ha='center', va='top', fontsize=8, color='black')
    text5.set_path_effects(add_contour(text5))

plt.xlabel('Number of Vertices')
plt.ylabel('Running Time (ms)')
plt.title('BlaBlaBla')
plt.legend()


# Show plot
plt.grid(True)

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4CycleCountingComparaison.png'))

plt.show()
