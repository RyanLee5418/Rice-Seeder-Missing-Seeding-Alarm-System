import sensor, image, time, math, json, pyb, sys
from pyb import UART
from pyb import Pin

pin0 = Pin('P1', Pin.IN, Pin.PULL_DOWN)
uart = UART(3, 9600, timeout_char=1000)    #串口3 波特率9600 超时时间1s
uart.init(9600, bits=8, parity=None, stop=1)

#(100, 85, -33, 18, 61, -32)
L_min=100
L_max=85
A_min=-33
A_max=18
B_min=61
B_max=-32

lmin=1
lmax=1
amin=1
amax=1
bmin=1
bmax=1

threshold =( L_min, L_max, A_min, A_max, B_min, B_max)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)          #320*240 Dpi
sensor.skip_frames(time = 2000)            #跳过几帧 初始化
sensor.set_auto_gain(False)                #关闭自动增益
sensor.set_auto_whitebal(False)            #关闭白平衡
clock = time.clock()
ROI = (157, 125, 7, 8)
sroi = (0, 42, 320, 146)
k=0

def find_max(blobs):
    max_size=0
    for blob in blobs:
        if blob.pixels() > max_size:
            max_blob = blob
            max_size = blob.pixels()
    return max_blob


while(True):
    clock.tick()
    img = sensor.snapshot()

    statistics=img.get_statistics(roi=ROI)
    color_l=statistics.l_mode()
    color_a=statistics.a_mode()
    color_b=statistics.b_mode()
    #print(color_l,color_a,color_b)
    img.draw_rectangle((ROI), color=(0,0,255))
    lmin = color_l - 20
    lmax = color_l + 20
    amin = color_a - 20
    amax = color_a + 20
    bmin = color_b - 20
    bmax = color_b + 20

    key0 = pin0.value()
    #print(key0,key0)
    if key0 == 1:
        #LED(3).on()
        #LED(1).off()
        k=1
        L_min = lmin
        L_max = lmax
        A_min = amin
        A_max = amax
        B_min = bmin
        B_max = bmax
       # print( L_min, L_max, A_min, A_max, B_min, B_max)
        threshold = ( L_min, L_max, A_min, A_max, B_min, B_max)
  #  if key0 == 0:
        #LED(1).on()
        #LED(3).on()
        #print( L_min, L_max, A_min, A_max, B_min, B_max)


    blobs = img.find_blobs( [threshold], roi = sroi,  pixels_threshold=30, area_threshold=30, merge=True, margin=500)

    if blobs:
       for b in blobs:
         img.draw_rectangle(b[0:4]) # rect
         img.draw_cross(b[5], b[6]) # cx, cy
         data = b.count()
         data = str(data)
         uart.write(data)
         uart.write('\r\n')
         print(data)



    elif k==1:
       #data = bytearray(hex(0))
       uart.write(str(0))
       uart.write('\r\n')
       print("0")

