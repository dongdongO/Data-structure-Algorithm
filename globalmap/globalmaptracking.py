import networkx as nx
import matplotlib.pyplot as plt
from PIL import Image
from matplotlib.animation import FuncAnimation

# .graphml 파일과 이미지 로드
graph = nx.read_graphml('Competition_track_graph.graphml') 
image_path = 'track06.png'
img = Image.open(image_path)

fig, ax = plt.subplots()  # fig 객체 추가
plt.imshow(img)

for node_id in graph.nodes:
    node_data = graph.nodes[node_id]
    x = node_data.get("x", 0)*87.3
    y = node_data.get("y", 0)*87.3

    ax.scatter(x, y, color="blue")
    ax.text(x, y, node_id, color="white", fontsize=5)

# nodetest.txt 파일에서 노드 리스트 읽기
with open('waypoints.txt', 'r') as file:
    node_list = [line.strip() for line in file]


# 초기 빨간 점과 경로 선 설정
red_dot, = ax.plot([], [], 'ro')
path_line, = ax.plot([], [], 'r-')

# 애니메이션 업데이트 함수
def update(frame):
    node_id = node_list[frame]
    x, y = graph.nodes[node_id]['x']*87.3, graph.nodes[node_id]['y']*87.3

    red_dot.set_data(x, y)
    if frame > 0:
        prev_x, prev_y = path_line.get_data()
        new_x, new_y = list(prev_x) + [x], list(prev_y) + [y]
        path_line.set_data(new_x, new_y)

    return red_dot, path_line

# 애니메이션 생성
ani = FuncAnimation(fig, update, frames=len(node_list))

# 축 숨기기
plt.axis('off')

# 애니메이션 보여주기
plt.show()

