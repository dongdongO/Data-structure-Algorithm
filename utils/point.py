import numpy as np

class Point:
    def __init__(self):
        # 각 점의 초기 상태 설정
        self.start_point = False  # 시작점 여부
        self.end_point = False    # 종료점 여부
        self.blocked = False      # 막힌 점 여부
        self.visited = False      # 방문된 점 여부
        self.prev_x = 0           # 이전 x 좌표
        self.prev_y = 0           # 이전 y 좌표
        self.cost = 0             # 해당 점까지의 비용

    def set_prev_point(self, prev_xy):
        # 이전 점의 좌표 설정
        self.prev_x, self.prev_y = prev_xy

    def get_prev_point(self):
        # 이전 점의 좌표를 numpy 배열로 반환
        return np.array([self.prev_x, self.prev_y])
    
    def is_cheaper(self, cost):
        # 주어진 비용이 현재 비용보다 적은지 확인
        return cost < self.cost
