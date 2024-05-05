import os
import matplotlib.pyplot as plt
from matplotlib import patheffects 

names = ['p2p-Gnut08', 'p2p-Gnut09', 'p2p-Gnut06', 'p2p-Gnut05', 'p2p-Gnut04', 'p2p-Gnut25', 'p2p-Gnut24', 'p2p-Gnut30', 'p2p-Gnut31']
x = [6301, 8114, 8717, 8846, 10876, 22687, 26518, 36682, 62586]  #nb vertices
m = [20777, 26013, 31525, 31839, 39994, 54705, 65369, 88328, 147892]  #nb edges
y1 = [7.48316, 9.27758, 15.0598, 11.5723, 16.7539, 20.4448, 23.9394, 31.6192, 52.8619] # Edge Local Counting
y2 = [3.69294, 4.68913, 6.18354, 6.0863, 8.37769, 9.17862, 13.3629, 15.5619, 28.4277]  # Vertex Local Counting
y3 = [2.99529, 4.18887, 5.38807, 5.18806, 6.98508, 9.17554, 10.5747, 15.163, 24.4381]  # Counting

y1_min = [7.48316-6.9455, 9.27758-7.9756, 15.0598-10.9263, 11.5723-9.9716, 16.7539-13.9254, 20.4448-16.9547, 23.9394-20.9412, 31.6192-27.9242, 52.8619-48.8691]
y1_max = [8.0138-7.48316, 10.0021-9.27758, 31.9146-15.0598, 12.9629-11.5723, 21.9135-16.7539, 24.9054-20.4448, 31.9154-23.9394, 38.8917-31.6192, 66.822-52.8619]
y2_min = [3.69294-2.9876, 4.68913-3.9838, 6.18354-4.9852, 6.0863-4.9865, 8.37769-6.9779, 9.17862-7.9791, 13.3629-11.9413, 15.5619-13.9462, 28.4277-25.9329] 
y2_max = [4.0193-3.69294, 5.99-4.68913, 7.9655-6.18354, 7.0146-6.0863, 10.0059-8.37769, 9.9919-9.17862, 15.9611-13.3629, 17.9519-15.5619, 32.9096-28.4277] 
y3_min = [2.99529-1.9946, 4.18887-3.9536, 5.38807-4.9549, 5.18806-4.9538, 6.98508-6.0223, 9.17554-6.9435, 10.5747-8.9751, 15.163-12.9645, 24.4381-20.9458]
y3_max = [4.0098-2.99529, 5.0219-4.18887, 6.9767-5.38807, 6.0094-5.18806, 7.9603-6.98508, 11.9696-9.17554, 11.9684-10.5747, 17.9518-15.163, 27.9285-24.4381]

plt.figure(figsize=(10, 6))

plt.plot(x, y1, label='Edge Local Counting', color='#ff5733')  # Edge Local Counting
plt.plot(x, y2, label='Vertex Local Counting', color="#bd7ebe")  # Vertex Local Counting
plt.plot(x, y3, label='Normal Counting', color="#b2e061")  # Counting

plt.errorbar(x, y1, yerr=[y1_min, y1_max], capsize=5, label='_error', color='#ff5733', alpha=0.5)
plt.errorbar(x, y2, yerr=[y2_min, y2_max], capsize=5, label='_error', color="#bd7ebe", alpha=0.5)
plt.errorbar(x, y3, yerr=[y3_min, y3_max], capsize=5, label='_error', color="#b2e061", alpha=0.5)

def add_contour(text):
    return [patheffects.withStroke(linewidth=3, foreground='white'), patheffects.Normal()]

for i in range(4,len(x)):
    offsetx = 0
    offsety = 0
    y1offset = 0

    if i == 4:
        offsetx = 0
        offsety = 0
        y1offset = 2.5


    #SGEMM colors
    text1 = plt.text(x[i]+offsetx, y1_max[i]+y1[i]+2+offsety+y1offset , f'+{y1_max[i]:.2f}\n{y1[i]:.2f}\n-{y1_min[i]:.2f}', ha='center', va='bottom', fontsize=6, color='#ff5733')
    text1.set_path_effects(add_contour(text1))  # Add contour to the text
    text2 = plt.text(x[i]+offsetx, y2_max[i]+y2[i]+1+offsety, f'+{y2_max[i]:.2f}\n{y2[i]:.2f}\n-{y2_min[i]:.2f}', ha='center', va='bottom', fontsize=6, color="#bd7ebe")
    text2.set_path_effects(add_contour(text2))  # Add contour to the text
    text3 = plt.text(x[i]+offsetx, y3[i]-2+offsety, f'+{y3_max[i]:.2f}\n{y3[i]:.2f}\n-{y3_min[i]:.2f}', ha='center', va='top', fontsize=6, color="#b2e061")
    text3.set_path_effects(add_contour(text3))  # Add contour to the text

    #Graph name
    text5 = plt.text(x[i]+offsetx, y1_max[i]+y1[i]+10+offsety+y1offset, names[i], ha='center', va='top', fontsize=8, color='black')
    text5.set_path_effects(add_contour(text5))

plt.xlabel('Number of Vertices')
plt.ylabel('Running Time (ms)')
plt.title('4-Cycles counting for Peer-to-Peer Networks')

##set x and y limits
plt.xlim(-1000, max(x) + 5000)
plt.ylim(-3, max(y1) + 30)

#plot legend left
plt.legend(loc='upper left')


# Show plot
plt.grid(True)

script_dir = os.path.dirname(os.path.abspath(__file__))
plt.savefig(os.path.join(script_dir, '4CycleCountingComparaison.png'))

plt.show()
