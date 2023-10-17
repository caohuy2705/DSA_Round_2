import os

def merge_cpp_files(output_filename, input_folder):
    with open(output_filename, 'w') as output_file:
        for filename in sorted(os.listdir(input_folder)):
            if filename.endswith('.cpp'):
                output_file.write(f"// File: {filename}\n")
                with open(os.path.join(input_folder, filename), 'r') as input_file:
                    output_file.write(input_file.read() + "\n")

if __name__ == "__main__":
    output_file = "combined.cpp"
    input_folder = "D:\DSA_ROUND_2\huh\DSA"  # Change this to your folder's path
    merge_cpp_files(output_file, input_folder)
