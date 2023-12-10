import numpy as np
from PIL import Image

def draw_map_from_txt(input_file, output_image):
    with open(input_file, 'r') as file:
        data = [list(map(int, line.split())) for line in file]

    map_data = np.array(data)

    # 이미지 데이터 생성 (바닥은 검정, 나머지는 흰색)
    img_data = np.zeros((map_data.shape[0], map_data.shape[1], 3), dtype=np.uint8)
    img_data[map_data != 7] = 255  # 흰색으로 설정

    img = Image.fromarray(img_data, 'RGB')
    img.save(output_image)

input_file = 'map-index.txt'
output_image = "test-map.png"
draw_map_from_txt(input_file, output_image)

