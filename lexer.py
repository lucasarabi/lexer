import tkinter as tk
from tkinter import filedialog
import subprocess
import tkinter.font as tkfont
import os

# gui that runs c program for lexer
def run_lexer():
    output_text.config(state=tk.NORMAL)
    
    # select file
    file_path = filedialog.askopenfilename(title="Select a file", filetypes=[("Text files", "*.txt")]) 
    
    if file_path:
        # get the current working directory
        cwd = os.getcwd()
        
        # Convert the absolute file path to a relative file path based on the current working directory
        relative_path = os.path.relpath(file_path, cwd)
        
        # Print the relative path to the console for debugging (optional)
        print(f"Relative file path: {relative_path}")
        
        # Run the compiled C program, passing the relative file path, works on linux with folders, not on windows
        result = subprocess.run(["wsl", "./lexer", relative_path], capture_output=True, text=True)
        
        # takes console output of c program and prints it in the GUI
        output_text.delete(1.0, tk.END)
        output_text.insert(tk.END, result.stdout)
    else:
        output_text.delete(1.0, tk.END)
        output_text.insert(tk.END, "No file selected. Select file below to run CLite Lexer.")
        
    output_text.config(state=tk.DISABLED)

# initialize gui
root = tk.Tk()
root.title("CLite Lexer")
root.geometry("800x800")
font_style = tkfont.Font(family="System", size=18)

# frame that holds text and scrollbar
frame = tk.Frame(root)
frame.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

# multi line text box
output_text = tk.Text(frame, wrap=tk.WORD, state=tk.DISABLED, font=font_style, height=0) # height=0 is possibly not the best fix
output_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

# scrollbar
scrollbar = tk.Scrollbar(frame, command=output_text.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
output_text.config(yscrollcommand=scrollbar.set)

# initial message
output_text.config(state=tk.NORMAL)
output_text.insert(tk.END, "Select file below to run CLite Lexer.")
output_text.config(state=tk.DISABLED)

# button to run the lexer after selecting a file
button_frame = tk.Frame(root)
button_frame.pack(side=tk.BOTTOM, fill=tk.X, pady=10)
button = tk.Button(button_frame, text="Select File", command=run_lexer)
button.pack(pady=10)

# loop
root.mainloop()
