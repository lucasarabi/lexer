import tkinter as tk
import subprocess

# Function to call the C program when the button is clicked
def say_hello():
    # Run the C program 'lexer' and capture its output
    result = subprocess.run(["wsl", "./lexer"], capture_output=True, text=True)
    
    # Update the output_label widget with the program's output
    output_label.config(text=result.stdout)

# Create the main window
root = tk.Tk()
root.title("CLite Lexer")

# Create a Label to display the output of the C program
output_label = tk.Label(root, text="Output will appear here", wraplength=400)
output_label.pack(pady=20)

# Create a button and associate it with the say_hello function
button = tk.Button(root, text="Click Me", command=say_hello)
button.pack(pady=10)

# Start the Tkinter event loop
root.mainloop()
