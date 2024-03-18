import os
import matplotlib.pyplot as plt

# Data
x = [1, 2, 3, 4, 5]  # X-axis values
y1 = [5, 7, 9, 11, 13]  # Y-axis values for line 1
y2 = [4, 6, 8, 10, 12]  # Y-axis values for line 2
y3 = [6, 8, 10, 12, 14]  # Y-axis values for line 3
y4 = [3, 5, 7, 9, 11]  # Y-axis values for line 4

# Error rates (minimum and maximum values)
y1_min = [4, 6, 8, 10, 12]  # Minimum values for line 1
y1_max = [6, 8, 10, 12, 14]  # Maximum values for line 1
y2_min = [3, 5, 7, 9, 11]  # Minimum values for line 2
y2_max = [5, 7, 9, 11, 13]  # Maximum values for line 2
y3_min = [5, 7, 9, 11, 13]  # Minimum values for line 3
y3_max = [7, 9, 11, 13, 15]  # Maximum values for line 3
y4_min = [2, 4, 6, 8, 10]  # Minimum values for line 4
y4_max = [4, 6, 8, 10, 12]  # Maximum values for line 4

# Plot lines with error bars representing range
plt.figure(figsize=(10, 6))
plt.plot(x, y1, label='Line 1')
plt.fill_between(x, y1_min, y1_max, alpha=0.2)

plt.plot(x, y2, label='Line 2')
plt.fill_between(x, y2_min, y2_max, alpha=0.2)

plt.plot(x, y3, label='Line 3')
plt.fill_between(x, y3_min, y3_max, alpha=0.2)

plt.plot(x, y4, label='Line 4')
plt.fill_between(x, y4_min, y4_max, alpha=0.2)

# Add labels, title, legend, and grid
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Line Chart with Error Bars')
plt.legend()
plt.grid(True)

# Save the plot
plt.savefig('line_chart_with_error_bars.png')

# Show plot
plt.show()
