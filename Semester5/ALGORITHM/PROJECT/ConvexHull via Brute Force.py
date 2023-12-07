import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import tkinter as tk
from tkinter import simpledialog
import time

Point = complex
P = Point

# returns x-coordinate of point
def X(point):
    if isinstance(point, P):
        return point.real
    else:
        return 0

# returns y-coordinate of point
def Y(point):
    if isinstance(point, P):
        return point.imag
    else:
        return 0

# To generate random points
def Points(n, width=900, height=600, seed=42):
    random.seed(seed * n)
    return frozenset(P(random.randrange(width), random.randrange(height))
                     for c in range(n))

def convert_points_into_list(points):
    return list(points)

# tells if a specific point is ccw or not
def ccw(p, q, r):
    val = (Y(q) - Y(p)) * (X(r) - X(q)) - (X(q) - X(p)) * (Y(r) - Y(q))
    if val == 0:
        return 0  # Collinear
    elif val > 0:
        return 1  # Clockwise
    else:
        return -1  # Counter Clock Wise

check_counter = 0  # Counter to keep track of the number of checks made

def brute_force(points):
    global check_counter
    n = len(points)
    if n < 3:
        raise ValueError("Convex Hull requires a minimum of 3 points")

    for i in range(n):
        for j in range(n):
            if j != i:
                pi, pj = points[i], points[j]
                valid = True

                for k in range(n):
                    if k != i and k != j:
                        pk = points[k]
                        check_counter += 1
                        if ccw(pi, pj, pk) != -1:
                            valid = False
                            break

                # Always append lines, whether valid or not
                lines.append({
                    'points': [(X(pi), Y(pi)), (X(pj), Y(pj))],
                    'color': 'blue' if valid else 'red',
                    'valid': valid,
                    'checks': check_counter  # Store the number of checks made
                })

                if valid:
                    if pi not in convex_hull:
                        convex_hull.append(pi)
                    if pj not in convex_hull:
                        convex_hull.append(pj)

# Animation function for displaying graph
def update(frame):
    ax.clear()

    # Plots all points
    ax.scatter(*zip(*[(X(p), Y(p)) for p in points_list]), color='black', label='All Points')

    # Plot lines connecting points for each iteration
    for i in range(frame + 1):
        if i < len(lines):
            line = lines[i]
            color = line['color']
            plt.scatter([line['points'][0][0], line['points'][1][0]], [line['points'][0][1], line['points'][1][1]],
                        color=color, s=100)
            plt.plot([line['points'][0][0], line['points'][1][0]], [line['points'][0][1], line['points'][1][1]],
                     color=color, linestyle="--")

    # Display the convex hull only when it's formed
    if frame == len(lines) - 1 and convex_hull:
        successful_lines = [line for line in lines if line['valid']]
        for line in successful_lines:
            plt.plot([line['points'][0][0], line['points'][1][0]], [line['points'][0][1], line['points'][1][1]],
                     color='blue', linestyle="--")

    # Display time complexity information
    if frame < len(lines):
        current_checks = lines[frame]['checks']
        plt.text(0.5, 0.05, f'Checks: {current_checks}', horizontalalignment='center',
                 verticalalignment='center', transform=ax.transAxes)

    plt.legend()
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title(f'Brute Force Convex Hull - Iteration {frame + 1}\nTime Complexity - O(n^3)')
    plt.pause(0.5)

# GUI for taking input
root = tk.Tk()
root.withdraw()

num_points = simpledialog.askinteger("Input", "Enter the number of points:")
points = Points(num_points)
points_list = convert_points_into_list(points)

fig, ax = plt.subplots()
convex_hull = []
lines = []

# Measure the time complexity during runtime
start_time = time.time()
brute_force(points_list)
end_time = time.time()

# Calculate the total time complexity
total_checks = sum(line['checks'] for line in lines)
total_time = end_time - start_time

# Display the calculated time complexity
plt.text(0.5, 0.95, f'Total Checks: {total_checks}', horizontalalignment='center',
         verticalalignment='center', transform=ax.transAxes)
plt.text(0.5, 0.9, f'Total Time: {total_time:.5f} seconds', horizontalalignment='center',
         verticalalignment='center', transform=ax.transAxes)

# To run the animation
ani = animation.FuncAnimation(fig, update, frames=len(lines), repeat=False)
plt.show()
