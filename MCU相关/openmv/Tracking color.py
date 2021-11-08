# Single Color RGB565 Blob Tracking Example
#
# This example shows off single color RGB565 tracking using the OpenMV Cam.

import sensor, image, time, math
from pyb import LED
threshold_index = 0 # 0 for red, 1 for green, 2 for blue

# Color Tracking Thresholds (L Min, L Max, A Min, A Max, B Min, B Max)
# The below thresholds track in general red/green/blue things. You may wish to tune them...
#thresholds = [(30, 100, 15, 127, 15, 127), # generic_red_thresholds
              #(30, 100, -64, -8, -32, 32), # generic_green_thresholds
              #(0, 30, 0, 64, -128, 0),# generic_blue_thresholds
              #(8,13,-5,-1,2,7),     #black
              #(67,71,-3,-1,0,7)]    #white

thresholds = [(0, 25, -63, 127, -128, 127),#black
                (47, 85, 1, -15, -17, -62)]#white

sensor.reset()

sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.set_vflip(True)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking

clock = time.clock()

LED(1).on()
LED(2).on()
LED(3).on()

while(True):
    clock.tick() # 追踪两个snapshots()之间经过的毫秒数.
    img = sensor.snapshot() # 拍一张照片并返回图像。
    blobs = img.find_blobs(thresholds,merge=True,area_threshold=200,pixels_threshold=100)
    #area_threshold 面积阈值，如果色块被框起来的面积小于这个值，会被过滤掉
    #pixels_threshold 像素个数阈值，如果色块像素数量小于这个值，会被过滤掉


    for b in blobs:
    #迭代找到的目标颜色区域
        # Draw a rect around the blob.
        img.draw_rectangle(b[0:4]) # rect
        #用矩形标记出目标颜色区域
        img.draw_cross(b[5], b[6]) # cx, cy
        #在目标颜色区域的中心画十字形标记

