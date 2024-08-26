# gcodeGenerator.py - Combined script for generating G-code from BMPs and other sources.

import os
import sys
from PIL import Image

# Utility function to initialize G-code settings
def init_gcode_file(filename):
    with open(filename, 'w') as f:
        f.write("; G-code initialization\n")
        f.write("G21 ; Set units to millimeters\n")
        f.write("G90 ; Absolute positioning\n")
        f.write("G28 ; Home all axes\n")

# Function to generate G-code for drawing a line
def generate_line_gcode(x_start, y_start, x_end, y_end, feedrate=1500):
    return f"G1 X{x_end:.2f} Y{y_end:.2f} F{feedrate}\n"

# Function to process a BMP file and convert it to G-code
def bmp_to_gcode(bmp_file, output_file):
    img = Image.open(bmp_file)
    img = img.convert("L")  # Convert to grayscale
    width, height = img.size
    pixel_data = img.load()

    init_gcode_file(output_file)

    with open(output_file, 'a') as f:
        for y in range(height):
            for x in range(width):
                if pixel_data[x, y] < 128:  # Assuming a threshold for binary conversion
                    f.write(generate_line_gcode(x, y, x + 1, y))
            f.write("\n")
        f.write("G28 ; Home all axes at the end\n")

# Command-line interface for generating G-code from BMPs
def main():
    if len(sys.argv) != 3:
        print("Usage: python gcodeGenerator.py <input_bmp> <output_gcode>")
        return

    input_bmp = sys.argv[1]
    output_gcode = sys.argv[2]

    if not os.path.exists(input_bmp):
        print(f"Error: {input_bmp} does not exist.")
        return

    bmp_to_gcode(input_bmp, output_gcode)
    print(f"G-code generated and saved to {output_gcode}")

# Additional utility functions for other G-code generation purposes

def generate_circle_gcode(x_center, y_center, radius, segments=100):
    gcode = []
    for i in range(segments + 1):
        angle = 2 * 3.14159 * i / segments
        x = x_center + radius * cos(angle)
        y = y_center + radius * sin(angle)
        gcode.append(f"G1 X{x:.2f} Y{y:.2f}\n")
    return "".join(gcode)

def save_circle_gcode(filename, x_center, y_center, radius):
    with open(filename, 'a') as f:
        f.write("; Circle drawing G-code\n")
        f.write(generate_circle_gcode(x_center, y_center, radius))
        f.write("G28 ; Home all axes at the end\n")

# Entry point for running as a script
if __name__ == "__main__":
    main()
