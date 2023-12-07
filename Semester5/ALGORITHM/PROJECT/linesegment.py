import tkinter as tk

def find_intersection_point(x1, y1, x2, y2, x3, y3, x4, y4):
   
    denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)

    if denominator == 0:
        return None  

    intersection_x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator
    intersection_y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator

    if (min(x1, x2) <= intersection_x <= max(x1, x2) and
            min(y1, y2) <= intersection_y <= max(y1, y2) and
            min(x3, x4) <= intersection_x <= max(x3, x4) and
            min(y3, y4) <= intersection_y <= max(y3, y4)):
        return intersection_x, intersection_y
    else:
        return None

def check_sides(x1, y1, x2, y2, x3, y3, x4, y4):
   
    def orientation(p, q, r):
        val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
        if val == 0:
            return 0  
        return 1 if val > 0 else 2  

    o1 = orientation((x1, y1), (x2, y2), (x3, y3))
    o2 = orientation((x1, y1), (x2, y2), (x4, y4))
    o3 = orientation((x3, y3), (x4, y4), (x1, y1))
    o4 = orientation((x3, y3), (x4, y4), (x2, y2))

    if o1 != o2 and o3 != o4:
        return True

    if o1 == 0 and on_segment((x1, y1), (x3, y3), (x2, y2)):
        return True
    if o2 == 0 and on_segment((x1, y1), (x4, y4), (x2, y2)):
        return True
    if o3 == 0 and on_segment((x3, y3), (x1, y1), (x4, y4)):
        return True
    if o4 == 0 and on_segment((x3, y3), (x2, y2), (x4, y4)):
        return True

    return False

def on_segment(p, q, r):
    return q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and \
           q[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1])

def draw_lines(method):
    canvas.delete("all")  

    x1, y1 = float(entry_x1.get()), float(entry_y1.get())
    x2, y2 = float(entry_x2.get()), float(entry_y2.get())
    x3, y3 = float(entry_x3.get()), float(entry_y3.get())
    x4, y4 = float(entry_x4.get()), float(entry_y4.get())

    scale = 10

    canvas.create_line(50, 350, 350, 350, width=2)  
    canvas.create_line(50, 350, 50, 50, width=2)     

    canvas.create_line(50 + x1 * scale, 350 - y1 * scale, 50 + x2 * scale, 350 - y2 * scale, fill="blue", width=2)

    canvas.create_line(50 + x3 * scale, 350 - y3 * scale, 50 + x4 * scale, 350 - y4 * scale, fill="red", width=2)

    intersection_point = None
    sides_intersect = False

    if method == "Algebraic":
        intersection_point = find_intersection_point(x1, y1, x2, y2, x3, y3, x4, y4)
        if intersection_point is not None:
            result_label1.config(text=f"Intersection Point: {intersection_point}")
            result_label2.config(text="Lines Do Not Intersect" if intersection_point is None else "")
        else:
            result_label1.config(text="No Intersection Point")
            result_label2.config(text="Lines Do Not Intersect")

    elif method == "Check Sides":
        sides_intersect = check_sides(x1, y1, x2, y2, x3, y3, x4, y4)
        result_label2.config(text="Line Intersect" if sides_intersect else "")

window = tk.Tk()
window.title("Line Segment Intersection Checker")

label_x1 = tk.Label(window, text="Line 1, x1:")
entry_x1 = tk.Entry(window)
label_y1 = tk.Label(window, text="Line 1, y1:")
entry_y1 = tk.Entry(window)

label_x2 = tk.Label(window, text="Line 1, x2:")
entry_x2 = tk.Entry(window)
label_y2 = tk.Label(window, text="Line 1, y2:")
entry_y2 = tk.Entry(window)

label_x3 = tk.Label(window, text="Line 2, x1:")
entry_x3 = tk.Entry(window)
label_y3 = tk.Label(window, text="Line 2, y1:")
entry_y3 = tk.Entry(window)

label_x4 = tk.Label(window, text="Line 2, x2:")
entry_x4 = tk.Entry(window)
label_y4 = tk.Label(window, text="Line 2, y2:")
entry_y4 = tk.Entry(window)

draw_button = tk.Button(window, text="Draw Lines", command=lambda: draw_lines(method_var.get()))

canvas = tk.Canvas(window, width=400, height=400, bg="white")

result_label1 = tk.Label(window, text="")
result_label2 = tk.Label(window, text="")

method_var = tk.StringVar()
method_var.set("Algebraic")

radio_algebraic = tk.Radiobutton(window, text="Algebraic Method", variable=method_var, value="Algebraic")
radio_check_sides = tk.Radiobutton(window, text="Check Sides Method", variable=method_var, value="Check Sides")

label_x1.grid(row=0, column=0)
entry_x1.grid(row=0, column=1)
label_y1.grid(row=1, column=0)
entry_y1.grid(row=1, column=1)

label_x2.grid(row=2, column=0)
entry_x2.grid(row=2, column=1)
label_y2.grid(row=3, column=0)
entry_y2.grid(row=3, column=1)

label_x3.grid(row=4, column=0)
entry_x3.grid(row=4, column=1)
label_y3.grid(row=5, column=0)
entry_y3.grid(row=5, column=1)

label_x4.grid(row=6, column=0)
entry_x4.grid(row=6, column=1)
label_y4.grid(row=7, column=0)
entry_y4.grid(row=7, column=1)

draw_button.grid(row=8, columnspan=2, pady=10)

canvas.grid(row=9, columnspan=2)

result_label1.grid(row=10, columnspan=2)
result_label2.grid(row=11, columnspan=2)

radio_algebraic.grid(row=12, column=0, columnspan=2)
radio_check_sides.grid(row=13, column=0, columnspan=2)

window.mainloop()
