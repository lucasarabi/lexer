import tkinter as tk
from tkinter import filedialog
import subprocess

# gui that runs c program for lexer
def run_lexer():
    # select file
    file_path = filedialog.askopenfilename(title="Select a file", filetypes=[("Text files", "*.txt")]) # , ("All files", "*.*") add back if more than .txt files are used for input
    
    if file_path:
        # run the compiled c program "wsl" is windows subsystem for linux, remove it if you are running on linux
        result = subprocess.run(["wsl", "./lexer", file_path], capture_output=True, text=True)
        
        # takes console output of c program and prints it in gui
        output_text.delete(1.0, tk.END)
        output_text.insert(tk.END, result.stdout)
    else:
        output_text.delete(1.0, tk.END)
        output_text.insert(tk.END, "No file selected. Select file below to run CLite Lexer.")

# initialize gui
root = tk.Tk()
root.title("CLite Lexer")
root.geometry("800x600")

# frame that holds text and scrollbar
frame = tk.Frame(root)
frame.pack(padx=10, pady=10)

# multi line text box
output_text = tk.Text(frame, wrap=tk.WORD)
output_text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

# scrollbar
scrollbar = tk.Scrollbar(frame, command=output_text.yview)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
output_text.config(yscrollcommand=scrollbar.set)

# initial message
output_text.insert(tk.END, "Select file below to run CLite Lexer.")

# button to run the lexer after selecting a file
button = tk.Button(root, text="Select File", command=run_lexer)
button.pack(pady=10)

# loop
root.mainloop()
