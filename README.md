# PLAYFAIR
This project was developed by @lorenzcompagnucci in the winter of 2021 as an exam for the Bachelor's Degree in CS at University of Camerino.
It is a C application that applies the playfair method to encode and decode messages.

## BUILD

To build the app you must:
* be in a Linux environment
* have cmake installed
* open the terminal on the playfair/
* write "cmake build"
* write "make"


## RUN

Open the terminal on the main directory. If you want to run the app write:

./playfair <encode/decode> <key_path> <output_dir> <file1> ... <filen>

If you want to create a key file to use later write:
  
./playfair <createkey> <file_path> <alphabet> <substitute_char> <special_char> <keyword>
