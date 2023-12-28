import math

class PathPlanner:
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
        
    def calculate_distance(self, old_x, old_y, new_x, new_y):
        distance = ((old_x-new_x)**2 + (old_y-new_y)**2)**0.5
        return round(self.to_inteager * distance)