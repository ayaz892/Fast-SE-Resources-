from tkinter import *
import time

coordinates = []
solution = []

def create_dot(event):
    x = event.x
    y = event.y
    r = 5
    my_canvas.create_oval(x+r, y+r, x-r, y-r, fill='black')
    coordinates.append((x, y))

def clear(event):
    my_canvas.delete('all')
    coordinates.clear()
    solution.clear()
    update_time_complexity_label("")

def get_coordinate_side(A, B, coordinate):
    x1, y1 = A
    x2, y2 = B
    x, y = coordinate
    a = y2 - y1
    b = x1 - x2
    c = x2*y1 - x1*y2
    f = a*x + b*y + c
    if f < 0:
        return 'right'
    elif f > 0:
        return 'left'
    else:
        return 'on-the-line'

def quick_elimination(points):
    if len(points) < 3:
        return points

    sorted_coordinates = sorted(points, key=lambda k: [k[0], k[1]])

    A = sorted_coordinates[0]
    B = sorted_coordinates[-1]

    ABright = []
    BAright = []
    for coordinate in sorted_coordinates:
        coordinate_side = get_coordinate_side(A, B, coordinate)
        if coordinate_side == 'right':
            ABright.append(coordinate)
        elif coordinate_side == 'left':
            BAright.append(coordinate)
        else:
            pass

    solution.append((A, B))
    solution.append((B, A))

    start_time = time.time()
    find_hull(ABright, A, B)
    find_hull(BAright, B, A)
    end_time = time.time()

    time_complexity = "Time Complexity: O(nh)"
    update_time_complexity_label(time_complexity)

    return solution

def find_hull(partition, A, B):
    if len(partition) == 0:
        return
    else:
        x1, y1 = A
        x2, y2 = B
        a = y2 - y1
        b = x1 - x2
        c = x2*y1 - x1*y2
        farthest_dist = -1
        C = None
        for coordinate in partition:
            x, y = coordinate
            f = abs(a*x + b*y + c)
            if f > farthest_dist:
                farthest_dist = f
                C = coordinate
        x, y = C

        solution.remove((A, B))
        solution.append((A, C))
        solution.append((C, B))

        partition.remove(C)
        ACright = [coordinate for coordinate in partition if get_coordinate_side(A, C, coordinate) == 'right']
        CBright = [coordinate for coordinate in partition if get_coordinate_side(C, B, coordinate) == 'right']

        find_hull(ACright, A, C)
        find_hull(CBright, C, B)

def convex_hull(event):
    global coordinates, solution

    points = coordinates.copy()

    my_canvas.delete('all')
    solution.clear()

    convex_hull_result = quick_elimination(points)

    for line in convex_hull_result:
        (x1, y1), (x2, y2) = line
        my_canvas.create_line(x1, y1, x2, y2, width=5, fill='blue')

    # Draw the points on the canvas
    for point in points:
        x, y = point
        my_canvas.create_oval(x - 2, y - 2, x + 2, y + 2, width=8, fill='black')

def update_time_complexity_label(text):
    time_complexity_label.config(text=text)
    
if __name__ == '__main__':
    my_window = Tk()
    my_window.title("Quick Elimination")
    my_canvas = Canvas(my_window, width=500, height=500, background='white')
    my_canvas.grid(row=0, column=0)

    # LMB to plant the points on the window
    my_canvas.bind('<Button-1>', create_dot)
    # RMB to get the convex hull
    my_canvas.bind('<Button-3>', convex_hull)
    # MWB to reset everything
    my_canvas.bind('<Button-2>', clear)

    # Time Complexity Label
    time_complexity_label = Label(my_window, text="", font=('Arial', 12))
    time_complexity_label.grid(row=0, column=1, padx=10, pady=10, sticky="ne")

    my_window.mainloop()
