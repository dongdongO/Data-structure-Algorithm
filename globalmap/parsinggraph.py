import xml.etree.ElementTree as ET

# GraphML 파일을 로드합니다.
tree = ET.parse('Competition_track_graph.graphml')
root = tree.getroot()

# 결과를 저장할 텍스트 파일을 엽니다.
with open('parsinggraphinfo.txt', 'w') as file:
    # 각 노드에 대한 정보를 추출합니다.
    for node in root.findall('.//{http://graphml.graphdrawing.org/xmlns}node'):
        node_id = node.get('id')
        x = float(node.find('./{http://graphml.graphdrawing.org/xmlns}data[@key="d0"]').text)
        y = float(node.find('./{http://graphml.graphdrawing.org/xmlns}data[@key="d1"]').text)
        
        # 계산을 수행합니다.
        x_calculated = int(x * 86.85 + 65)
        y_calculated = int(y * 86.85 + 45)

        # 추출한 정보를 파일에 작성합니다.
        file.write(f'{node_id}, {x_calculated}, {y_calculated}\n')
