import numpy as np
from PIL import Image

# All RGB values not here are "Solid Lines" which is number 0
color_mapping = {
    (37, 37, 0, 255): 1,        # Stop Line
    (255, 110, 255, 255): 2,    # Crosswalk
    (218, 218, 255, 255): 3,    # Dotted Line
    (0, 145, 0, 255): 4,        # Parking Lot
    (0, 109, 109, 255): 5,      # Roundabout
    (255, 146, 146, 255): 6,    # StartLine
    (0, 0, 0, 255): 7,          # Floor
    (26, 60, 94, 255): 8,       # Bus Line
    (172, 161, 63, 255): 9      # Sidewalk
}

def map_colors_to_numbers(image_path, output_file):
    img = Image.open(image_path)
    img_data = np.array(img)

    result = np.zeros(img_data.shape[:2], dtype=int)

    for y in range(img_data.shape[0]):
        for x in range(img_data.shape[1]):
            pixel = tuple(img_data[y, x])
            result[y, x] = color_mapping.get(pixel, 0)

    with open(output_file, 'w') as file:
        for row in result:
            file.write(' '.join(map(str, row)) + '\n')

image_path = "track10.png"
output_file = "map-index.txt"
map_colors_to_numbers(image_path, output_file)

