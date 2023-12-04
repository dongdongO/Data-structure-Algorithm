import numpy as np
import math
import utils

class Map:
    def __init__(self, width, height, resolution):
        # 맵의 너비, 높이, 해상도 초기화
        self.width = width
        self.height = height
        self.resolution = resolution

        # 해상도에 따른 소수점 계산
        self.decimal_point = round(math.log(self.resolution, 0.1))
        self.to_integer = 10 ** (self.decimal_point)

        # 맵의 크기 계산 (셀 단위)
        self.x_size = round(width / resolution)
        self.y_size = round(height / resolution)

        # 그리드 맵 초기화 (utils.Point 객체를 사용)
        self.grid_map = np.array([[utils.Point() for _ in range(self.y_size)] for _ in range(self.x_size)], dtype=object)
        print(f"XY Size :  {self.x_size} x {self.y_size}\n")

        # 장애물 목록 초기화
        self.obstacle_list = []

    def set_obstacle(self, x, y, width, height):
        # 장애물 설정
        for i in range(round(x / self.resolution), round((x + width) / self.resolution) + 1):
            for j in range(round(y / self.resolution), round((y + height) / self.resolution) + 1):
                self.grid_map[i, j].blocked = True
        obstacle_info = [x, y, width, height]
        self.obstacle_list.append(obstacle_info)

    def set_prev_point(self, old_x, old_y, new_x, new_y):
        # 이전 점 설정
        self.grid_map[new_x, new_y].set_prev_point([old_x, old_y])

    def get_prev_point(self, x, y):
        # 이전 점 가져오기
        return self.grid_map[x, y].get_prev_point()

    def set_start(self, x, y):
        # 시작점 설정
        self.grid_map[x, y].start_point = True

    def set_end(self, x, y):
        # 종료점 설정
        self.grid_map[x, y].end_point = True

    def set_blocked(self, x, y):
        # 점을 막힌 상태로 설정
        self.grid_map[x, y].blocked = True

    def set_visited(self, x, y):
        # 점을 방문한 상태로 설정
        self.grid_map[x, y].visited = True

    def set_visited_and_prev_point(self, old_x, old_y, new_x, new_y):
        # 점을 방문한 상태로 설정하고 이전 점을 설정
        self.grid_map[new_x, new_y].visited = True
        self.grid_map[new_x, new_y].set_prev_point([old_x, old_y])

    def is_start(self, x, y):
        # 시작점 여부 확인
        return self.grid_map[x, y].start_point

    def is_end(self, x, y):
        # 종료점 여부 확인
        return self.grid_map[x, y].end_point

    def is_blocked(self, x, y):
        # 점이 막혀있는지 확인
        return self.grid_map[x, y].blocked

    def is_visited(self, x, y):
        # 점이 방문되었는지 확인
        return self.grid_map[x, y].visited

    def is_blocked_or_visited(self, x, y):
        # 점이 막히거나 방문되었는지 확인
        return self.grid_map[x, y].blocked or self.grid_map[x, y].visited

    def is_outside(self, x, y):
        # 점이 맵 바깥에 있는지 확인
        if not (0 <= x < self.x_size):
            return True
        elif not (0 <= y < self.y_size):
            return True
        return False

    def set_cost(self, x, y, cost):
        # 점의 비용 설정
        self.grid_map[x, y].cost = cost

    def get_cost(self, x, y):
        # 점의 비용 가져오기
        return self.grid_map[x, y].cost

    def calculate_distance(self, old_x, old_y, new_x, new_y):
        # 두 점 사이의 거리 계산
        distance = ((old_x - new_x) ** 2 + (old_y - new_y) ** 2) ** 0.5
        return round(self.to_integer * distance)
