import tkinter as tk
from tkinter import filedialog
import subprocess

# Function to call the C program when the button is clicked
def run_lexer():
    # Open a file dialog to select a file
    file_path = filedialog.askopenfilename(title="Select a file", filetypes=[("Text files", "*.txt"), ("All files", "*.*")])
    
    # Check if the user selected a file (file_path will be an empty string if cancelled)
    if file_path:
        # Run the C program 'lexer' and pass the selected file as an argument
        result = subprocess.run(["wsl", "./lexer", file_path], capture_output=True, text=True)
        
        # Insert the output of the C program into the Text widget
        output_text.delete(1.0, tk.END)  # Clear existing content
        output_text.insert(tk.END, result.stdout)  # Insert new content
    else:
        output_text.delete(1.0, tk.END)
        output_text.insert(tk.END, "No file selected.")

# Create the main window
root = tk.Tk()
root.title("CLite Lexer")

# Create a Frame to hold the Text widget and Scrollbar
frame = tk.Frame(root)
frame.pack(padx=10, pady=10)

# Create a Text widget for displaying multi-line output with a vertical scrollbar
output_text = tk.Text(frame, width=50, height=10, wrap=tk.WORD)
output_text.pack(side=tk.LEFT, fill=tk.Y)

# Create a Scrollbar widget and link it to the Text widget
scrollbar = tk.Scrollbar(frame, command=output_text.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

# Configure the Text widget to use the scrollbar
output_text.config(yscrollcommand=scrollbar.set)

# Insert initial message
output_text.insert(tk.END, "Select file below to run CLite Lexer.")

# Create a button and associate it with the run_lexer function
button = tk.Button(root, text="Select File", command=run_lexer)
button.pack(pady=10)

# Start the Tkinter event loop
root.mainloop()
