import numpy as np
import matplotlib.pyplot as plt
import time

ARROW_DEBUG = False

out_dir = None
im_i = 0

def is_left_turn(v0, v1, v2, debug=True, chain=None, convex_hull=None, i=-1):
    if debug:
        visualize_step(chain, convex_hull, i, text='Left Turn Test', wait=False)
        plt.gca().set_prop_cycle(None)
        ax = plt.gca()
        ax.arrow(v0[0], v0[1], 2 * (v1[0] - v0[0]), 2 * (v1[1] - v0[1]), head_width=0.05, head_length=0.1, fc='b', ec='b',
                 linewidth=3)

        plt.scatter(v2[0], v2[1], color='g', s=150)
        plt.scatter(v0[0], v0[1], color='b', s=100)
        plt.scatter(v1[0], v1[1], color='b', s=100)

        plt.pause(0.5)  # Adjust the pause interval
        draw_image()
        plt.waitforbuttonpress(0)

    # Shewchuk predicate:
    orientation = (v0[0] - v2[0]) * (v1[1] - v2[1]) - (v0[1] - v2[1]) * (v1[0] - v2[0])
    return orientation > 0

def visualize_step(points, convex_hull, i, text='', wait=True):
    text += " " + str(convex_hull)
    plt.cla()
    points = np.array(points)
    convex_hull = np.array(convex_hull)

    plt.gca().set_prop_cycle(None)

    plt.scatter(points[:, 0], points[:, 1], color='g')
    plt.plot(points[:, 0], points[:, 1], linewidth=2)

    if -1 < i < len(points):
        plt.scatter(points[i, 0], points[i, 1], color='r', s=300)

    if len(convex_hull):
        plt.scatter(convex_hull[:, 0], convex_hull[:, 1], color='r')
        plt.plot(convex_hull[:, 0], convex_hull[:, 1], color='r')

        plt.scatter(convex_hull[-1, 0], convex_hull[-1, 1], color='r', s=150)

    plt.title(text)
    plt.grid(True)

    if wait:
        plt.pause(0.5)  # Adjust the pause interval
        draw_image()

def draw_image():
    global out_dir
    global im_i

    if out_dir:
        im_name = str(im_i)
        while len(im_name) < 3:
            im_name = str(0) + im_name

        plt.savefig(out_dir + im_name + '.png')
        im_i += 1

def melkman_convex_hull(points):
    if is_left_turn(points[0], points[1], points[2], debug=ARROW_DEBUG, chain=points, convex_hull=[], i=2):
        convex_hull = [points[2], points[0], points[1], points[2]]
    else:
        convex_hull = [points[2], points[1], points[0], points[2]]

    i = 3
    visualize_step(points, convex_hull, 2, 'After Initialization')

    while i < len(points):
        while is_left_turn(convex_hull[-2], convex_hull[-1], points[i], debug=ARROW_DEBUG, chain=points,
                            convex_hull=convex_hull, i=i) \
                and is_left_turn(convex_hull[0], convex_hull[1], points[i], debug=ARROW_DEBUG, chain=points, convex_hull=convex_hull, i=i):
            visualize_step(points, convex_hull, i, 'Skipping')
            i += 1

        visualize_step(points, convex_hull, i, 'After "Skip Nodes Inside"')
        # RESTORE CONVEXITY:
        while not is_left_turn(convex_hull[-2], convex_hull[-1], points[i], debug=ARROW_DEBUG, chain=points,
                                convex_hull=convex_hull, i=i):
            convex_hull.pop()
            visualize_step(points, convex_hull, i, 'Restoring Convexity ...')

        convex_hull.append(points[i])
        visualize_step(points, convex_hull, i, 'Time Complexity of Melkman Algorithm: O(n) ')

        while not is_left_turn(points[i], convex_hull[0], convex_hull[1], debug=ARROW_DEBUG, chain=points,
                                convex_hull=convex_hull, i=i):
            convex_hull.remove(convex_hull[0])
            visualize_step(points, convex_hull, i, 'Restoring Convexity ...')

        convex_hull.insert(0, points[i])
        visualize_step(points, convex_hull, i, 'Time Complexity of Melkman Algorithm: O(n) ')

        i += 1

    # Convex hull is complete, pause animation
    visualize_step(points, convex_hull, i, 'Convex Hull Complete', wait=True)
    plt.waitforbuttonpress(0)

    return convex_hull

if __name__ == '__main__':
    points = np.array([[0, 0], [1, 1], [2, 0], [1, -1], [3, 1], [2, -1]])

    plt.figure(1)
    plt.ion()

    visualize_step(points, [], -1, 'BEFORE INITIALIZATION')
    convex_hull_result = melkman_convex_hull(points)

    visualize_step(points, convex_hull_result, -1, 'RESULT')

    plt.show()
