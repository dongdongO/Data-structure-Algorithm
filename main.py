import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

import utils
import pathplanner

# Map Setting
width = 10.2
height = 10.3
resolution = 0.01
map = utils.Map(width, height, resolution)

# Obstacle Setting
map.set_obstacle(6.7, 6.7, 1.0, 1.0)
map.set_obstacle(0.5, 6.1, 5.0, 1.0)
map.set_obstacle(1.1, 2.0, 8.0, 2.0)
map.set_obstacle(4.5, 4.5, 1.0, 1.0)

# Start & End point Setting
start_x = 2.5
start_y = 1.5
end_x = 7.0
end_y = 8.7

# Path Planning
# planner = pathplanner.BFS(map, start_x, start_y, end_x, end_y)
# planner = pathplanner.Dijkstra(map, start_x, start_y, end_x, end_y)
planner = pathplanner.A_Star(map, start_x, start_y, end_x, end_y)
planner.path_planning()
planner.calculate_route()

# Matplotlib (Visualization)
print("Drawing Graph")
fig, ax = plt.subplots()
ax.set(xlim=(0, width), ylim=(0, height), xticks=[], yticks=[])

# Obstacles
for obstacle in map.obstacle_list:
    o_x1, o_y1, o_x2, o_y2 = obstacle[0], obstacle[1], obstacle[0] + obstacle[2], obstacle[1] + obstacle[3]
    plt.plot([o_x1, o_x1, o_x2, o_x2, o_x1], [o_y1, o_y2, o_y2, o_y1, o_y1], "k-")
    plt.plot([o_x1, o_x2], [o_y1, o_y2], "k-")
    plt.plot([o_x1, o_x2], [o_y2, o_y1], "k-")

# Map
plt.plot([0, 0, width, width, 0], [0, height, height, 0, 0], "k-")
# Start Point
plt.plot([start_x], [start_y], "ro")
# End Point
plt.plot([end_x], [end_y], "bo")
# Path Planning Line
xdata, ydata = [], []
ln, = ax.plot([], [], 'go')
def init():
    ax.set_xlim(0, width)
    ax.set_ylim(0, height)
    return ln,
def update(frame):
    xdata.append(planner.route_x[frame])
    ydata.append(planner.route_y[frame])
    ln.set_data(xdata, ydata)
    return ln,
ani = FuncAnimation(fig, update, frames=range(0,len(planner.route_x),1), interval=1)
plt.show()