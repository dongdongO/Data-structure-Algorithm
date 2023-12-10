import numpy as np
from PIL import Image

color_mapping = {
    (37, 37, 0, 255): 1,     # 정지선
    (255, 110, 255, 255): 2, # 횡단보도
    (218, 218, 255, 255): 3, # 점선
    (0, 145, 0, 255): 4,     # 주차구역
    (0, 109, 109, 255): 5,   # 로터리
    (255, 146, 146, 255): 6, # 출발지역
    (0, 0, 0, 255): 7,       # 바닥
    (26, 60, 94, 255): 8     # 버스구역
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

image_path = "track05.png"
output_file = "map-index.txt"
map_colors_to_numbers(image_path, output_file)

