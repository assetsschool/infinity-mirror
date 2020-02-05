import time
import adafruit_dotstar
import board
import math


brightness = .3

num_pixels = 150
pixels = adafruit_dotstar.DotStar(
    board.A1, board.A2, num_pixels, brightness=brightness, auto_write=False)


def wheel(pos):
    # Input a value 0 to 255 to get a color value.
    # The colours are a transition r - g - b - back to r.
    if pos < 0 or pos > 255:
        return (0, 0, 0)
    if pos < 85:
        return (255 - pos * 3, pos * 3, 0)
    if pos < 170:
        pos -= 85
        return (0, 255 - pos * 3, pos * 3)
    pos -= 170
    return (pos * 3, 0, 255 - pos * 3)


def color_fill(color, wait = 0):
    pixels.fill(color)
    pixels.show()
    time.sleep(wait)


def slice_alternating(wait):
    pixels[::2] = [RED] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[1::2] = [ORANGE] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[::2] = [YELLOW] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[1::2] = [GREEN] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[::2] = [TEAL] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[1::2] = [CYAN] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[::2] = [BLUE] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[1::2] = [PURPLE] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[::2] = [MAGENTA] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)
    pixels[1::2] = [WHITE] * (num_pixels // 2)
    pixels.show()
    time.sleep(wait)


def slice_rainbow(wait):
    pixels[::6] = [RED] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)
    pixels[1::6] = [ORANGE] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)
    pixels[2::6] = [YELLOW] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)
    pixels[3::6] = [GREEN] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)
    pixels[4::6] = [BLUE] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)
    pixels[5::6] = [PURPLE] * (num_pixels // 6)
    pixels.show()
    time.sleep(wait)


def rainbow_cycle(wait):
    for j in range(255):
        for i in range(num_pixels):
            rc_index = (i * 256 // num_pixels) + j
            pixels[i] = wheel(rc_index & 255)
        pixels.show()
        time.sleep(wait)


RED = (255, 0, 0)
YELLOW = (255, 150, 0)
ORANGE = (255, 40, 0)
GREEN = (0, 255, 0)
TEAL = (0, 255, 120)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
MAGENTA = (255, 0, 20)
WHITE = (255, 255, 255)

# while True:
#     # Change this number to change how long it stays on each solid color.
#     color_fill(RED, 0.5)
#     color_fill(YELLOW, 0.5)
#     color_fill(ORANGE, 0.5)
#     color_fill(GREEN, 0.5)
#     color_fill(TEAL, 0.5)
#     color_fill(CYAN, 0.5)
#     color_fill(BLUE, 0.5)
#     color_fill(PURPLE, 0.5)
#     color_fill(MAGENTA, 0.5)
#     color_fill(WHITE, 0.5)

#     # Increase or decrease this to speed up or slow down the animation.
#     slice_alternating(0.1)

#     color_fill(WHITE, 0.5)

#     # Increase or decrease this to speed up or slow down the animation.
#     slice_rainbow(0.1)

#     time.sleep(0.5)

#     # Increase this number to slow down the rainbow animation.
#     rainbow_cycle(0)



class vec3:

    def __init__(self, x = 0, y = 0, z = 0):
        self.x = x
        self.y = y
        self.z = z

    def rgb(self):
        return (self.x, self.y, self.z)
    def rgb8(self):
        r = round(self.x * 255)
        g = round(self.y * 255)
        b = round(self.z * 255)
        return (r, g, b)


start_time = time.monotonic()
# life_time = 0.0








def pixel(uv, deltatime):
    theta = math.pi / deltatime

    r = abs(math.sin(theta))

    color = vec3(.5, uv * 10.0 + deltatime, r)

    # color.r = abs(math.sin(deltatime))
    
    return color.rgb8()














def loop():
    # color_fill(WHITE)
    # time.sleep(1.)
    # color_fill(RED)
    # time.sleep(1.)
    # slice_alternating(0)
    # start_time = time.time()

    now = time.monotonic()
    life_time = now - start_time

    for i in range(num_pixels):
        uv = float(i / num_pixels)
        pixels[i] = pixel(uv, life_time * .2 + 10.0)
    pixels.show()



while True:
    loop()





