import numpy as np
import math
from collections import deque

import utils

class BFS:
    def __init__(self, map, start_x, start_y, end_x, end_y):
        self.map = map
        self.resolution = self.map.resolution
        self.decimal_point = round(math.log(self.resolution, 0.1))
        self.to_inteager = 10**(self.decimal_point)


        self.start_x = round(start_x / self.resolution)
        self.start_y = round(start_y / self.resolution)
        self.end_x = round(end_x / self.resolution)
        self.end_y = round(end_y / self.resolution)
        self.map.set_start(self.start_x, self.start_y)
        self.map.set_end(self.end_x, self.end_y)

        self.route_x = []
        self.route_y = []


    @utils.exe_time
    def path_planning(self, max_iter=10**6):
        if self.map.is_blocked(self.start_x, self.start_y):
            return False
        elif self.map.is_blocked(self.end_x, self.end_y):
            return False

        count = 0

        visit_deque = deque()
        visit_deque.append([self.start_x, self.start_y])
        self.map.set_visited(self.start_x, self.start_y)
        self.map.set_cost(self.start_x, self.start_y, 0)
        
        while visit_deque:
            old_x, old_y = visit_deque.popleft()
            old_cost = self.map.get_cost(old_x, old_y)
            new_xs = [old_x, old_x, old_x-1, old_x+1]
            new_ys = [old_y+1, old_y-1, old_y, old_y]
            for new_x in new_xs:
                for new_y in new_ys:
                    if self.map.is_outside(new_x, new_y):
                        continue
                    if not self.map.is_blocked(new_x, new_y):
                        add_cost = self.map.calculate_distance(old_x, old_y, new_x, new_y)
                        new_cost = old_cost + add_cost
                        if not self.map.is_visited(new_x, new_y):
                            self.map.set_visited_and_prev_point(old_x, old_y, new_x, new_y)
                            self.map.set_cost(new_x, new_y, new_cost)
                            visit_deque.append([new_x, new_y])
                        elif (new_cost < self.map.get_cost(new_x, new_y)):
                            self.map.set_prev_point(old_x, old_y, new_x, new_y)
                            self.map.set_cost(new_x, new_y, new_cost)
                            visit_deque.append([new_x, new_y])
                    if self.map.is_end(new_x, new_y):
                        return True
            # count += 1
            # if count < max_iter:
            #     print("Maximum Iteration:", count)
            #     return False
        return False

    def calculate_route(self):
        now_x, now_y = self.end_x, self.end_y

        while not self.map.is_start(now_x, now_y):
            next_xy = self.map.get_prev_point(now_x, now_y)
            self.route_x.append(round(next_xy[0] * self.resolution, self.decimal_point))
            self.route_y.append(round(next_xy[1] * self.resolution, self.decimal_point))
            now_x, now_y = next_xy[0], next_xy[1]
            # print("new_x:", now_x, "\t", "new_y:", now_y)
        self.route_x = self.route_x[::-1]
        self.route_y = self.route_y[::-1]