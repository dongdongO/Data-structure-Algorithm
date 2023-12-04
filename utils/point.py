import numpy as np

class Point:
    def __init__(self):
        self.start_point = False
        self.end_point = False
        self.blocked = False
        self.visited = False
        self.prev_x = 0
        self.prev_y = 0
        self.cost = 0

    def set_prev_point(self, prev_xy):
        self.prev_x, self.prev_y = prev_xy

    def get_prev_point(self):
        return np.array([self.prev_x, self.prev_y])
    
    def is_cheaper(self, cost):
        return cost < self.cost
