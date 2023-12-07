import tkinter as tk
from tkinter import ttk, messagebox
import subprocess
from PIL import Image, ImageTk

class App:
    def __init__(self, root):
        self.root = root
        self.root.title("ALGORITHMS EXECUTOR")

        # Set window size and position
        window_width = root.winfo_screenwidth() // 2
        window_height = root.winfo_screenheight() // 2
        x_position = (root.winfo_screenwidth() - window_width) // 2
        y_position = (root.winfo_screenheight() - window_height) // 2
        root.geometry(f"{window_width}x{window_height}+{x_position}+{y_position}")

        # Set window background image using Canvas
        canvas = tk.Canvas(root, width=window_width, height=window_height)
        canvas.pack()

        bg_image = Image.open("OIP.jpg")  # Replace with your image file
        bg_image = bg_image.resize((window_width, window_height), Image.LANCZOS)
        self.bg_photo = ImageTk.PhotoImage(bg_image)
        canvas.create_image(0, 0, anchor=tk.NW, image=self.bg_photo)

        # Create frame
        frame = ttk.Frame(root)
        frame.place(relx=0.5, rely=0.5, anchor="center")

        # Create title label
        title_label = ttk.Label(frame, text="ALGORITHMS EXECUTOR", font=("Helvetica", 24))
        title_label.grid(row=0, column=0, columnspan=2, pady=(20, 10))

        # Add options for each Python file as colorful buttons
        file_names = ["Bentley-Ottmann.py", "ConvexHull via Brute Force.py", "ConvexHull via Graham Scan.py", "ConvexHull via Jarvis March.py", "ConvexHull via MelkMan's Algorithm.py", "ConvexHull via Quick Elimination.py", "linesegment.py"]
        for i, file_name in enumerate(file_names):
            button = ttk.Button(frame, text=f"Execute {file_name}", command=lambda name=file_name: self.execute_file(name))
            button.grid(row=i + 1, column=0, columnspan=2, pady=5, padx=20, sticky="nsew")

        # Configure row and column weights to make the buttons expandable
        for i in range(len(file_names) + 1):
            frame.grid_rowconfigure(i, weight=1)
        frame.grid_columnconfigure(0, weight=1)
        frame.grid_columnconfigure(1, weight=1)

    def execute_file(self, file_name):
        try:
            subprocess.run(["python", file_name], check=True)
        except subprocess.CalledProcessError:
            messagebox.showerror("Error", f"Failed to execute {file_name}")

if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()
