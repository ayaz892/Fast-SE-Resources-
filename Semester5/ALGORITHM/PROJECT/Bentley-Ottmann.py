import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
from sortedcontainers import SortedDict

class BentleyOttmann:
    def __init__(self, master):
        self.master = master
        self.master.title("Bentley-Ottmann Algorithm")
        
        self.figure, self.ax = Figure(figsize=(6, 6)), None
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.master)
        self.canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)

        self.points = []
        self.lines = []
        
        self.instructions = tk.Label(self.master, text="Enter values for two lines:")
        self.instructions.pack()
        
        self.line1_label = tk.Label(self.master, text="Line 1 (x1 y1 x2 y2):")
        self.line1_label.pack()
        self.line1_entry = tk.Entry(self.master)
        self.line1_entry.pack()
        
        self.line2_label = tk.Label(self.master, text="Line 2 (x1 y1 x2 y2):")
        self.line2_label.pack()
        self.line2_entry = tk.Entry(self.master)
        self.line2_entry.pack()
        
        self.run_button = tk.Button(self.master, text="Run", command=self.run_algorithm)
        self.run_button.pack()

    def run_algorithm(self):
        self.points = []
        self.lines = []
        
        line1_values = list(map(int, self.line1_entry.get().split()))
        line2_values = list(map(int, self.line2_entry.get().split()))
        
        self.lines.append(line1_values)
        self.lines.append(line2_values)

        self.draw_lines()

        intersection_result = self.bentley_ottmann_algorithm()

        result_label = tk.Label(self.master, text=intersection_result)
        result_label.pack()

    def draw_lines(self):
        if self.ax is not None:
            self.ax.clear()
        else:
            self.ax = self.figure.add_subplot(111)

        for line in self.lines:
            x1, y1, x2, y2 = line
            self.ax.plot([x1, x2], [y1, y2], marker='o', label=f'Line {len(self.lines)}')

        self.ax.legend()
        self.canvas.draw()

    def orientation(self, p, q, r):
        val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
        if val == 0:
            return 0  # colinear
        return 1 if val > 0 else 2  # clock or counterclockwise

    def on_segment(self, p, q, r):
        return q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and q[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1])

    def do_intersect(self, p1, q1, p2, q2):
        o1 = self.orientation(p1, q1, p2)
        o2 = self.orientation(p1, q1, q2)
        o3 = self.orientation(p2, q2, p1)
        o4 = self.orientation(p2, q2, q1)

        if o1 != o2 and o3 != o4:
            return True

        if o1 == 0 and self.on_segment(p1, p2, q1):
            return True
        if o2 == 0 and self.on_segment(p1, q2, q1):
            return True
        if o3 == 0 and self.on_segment(p2, p1, q2):
            return True
        if o4 == 0 and self.on_segment(p2, q1, q2):
            return True

        return False

    def bentley_ottmann_algorithm(self):
        events = []
        for idx, line in enumerate(self.lines):
            x1, y1, x2, y2 = line
            events.append((x1, y1, idx, 'start'))
            events.append((x2, y2, idx, 'end'))

        events.sort(key=lambda event: (event[0], event[3]))

        status_line = SortedDict()
        for event in events:
            x, y, line_idx, event_type = event

            if event_type == 'start':
                status_line[y] = line_idx

                above_line = status_line.bisect_left(y)
                below_line = status_line.bisect_right(y)

                if above_line != len(status_line) and below_line != 0:
                    # Check for actual intersection
                    line1 = self.lines[line_idx]
                    line2 = self.lines[status_line[above_line]]
                    if self.do_intersect((line1[0], line1[1]), (line1[2], line1[3]), (line2[0], line2[1]), (line2[2], line2[3])):
                        return "Lines are intersecting!"

            else:  # event_type == 'end'
                del status_line[y]

        return "Lines are not intersecting!"

if __name__ == "__main__":
    root = tk.Tk()
    app = BentleyOttmann(root)
    root.mainloop()
