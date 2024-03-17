import os
import matplotlib.pyplot as plt

# Example data
num_vertices = [1005, 4039, 7115, 12008, 22687, 27770]  # Number of vertices
memory_scenario1 = [13.372, 198.248, 595.112, 1692.820, 5165.180, 5703.440 ]    # Memory consumption for scenario 1
memory_scenario2 = [17.412, 263.502, 797.605, 2269.588, 7218.538, 7291.115 ]    # Memory consumption for scenario 2

# Plotting
plt.plot(num_vertices, memory_scenario1, label='Scenario 1')
plt.plot(num_vertices, memory_scenario2, label='Scenario 2')

# Adding labels and title
plt.xlabel('Number of Vertices')
plt.ylabel('Memory Consumption (MB)')
plt.title('Comparison of Memory Consumption')

# Adding legend
plt.legend()

# Show plot
plt.grid(True)  # Enable grid for better visualization

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))
# Save the plot in the same directory as the script
plt.savefig(os.path.join(script_dir, 'NaiveNincreasingMemory.png'))

plt.show()
