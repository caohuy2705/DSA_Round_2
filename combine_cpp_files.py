import os

def combine_cpp_files(input_folder, output_file):
    with open(output_file, 'w') as outfile:
        for filename in os.listdir(input_folder):
            if filename.endswith('.cpp'):
                with open(os.path.join(input_folder, filename), 'r') as infile:
                    outfile.write("// Start of {} \n".format(filename))
                    outfile.write(infile.read())
                    outfile.write("\n// End of {} \n\n".format(filename))

if __name__ == "__main__":
    input_folder_path = r"D:\DSA_ROUND_2\ayo"  # Replace with the path to your input folder

    # Modify the output file path to your user's home directory or any other writable location
    output_file_path = r"C:\Users\caohu\combined.cpp"

    combine_cpp_files(input_folder_path, output_file_path)
    print("Successfully combined .cpp files into one big .cpp file.")

#"D:\DSA_ROUND_2\ayo"