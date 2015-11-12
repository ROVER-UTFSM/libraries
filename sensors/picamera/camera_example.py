#!/usr/bin/python
#

__author__="Cristobal Ramirez"

import time
import picamera

if __name__ == "__main__":
	import time
import picamera

with picamera.PiCamera() as camera:
    camera.resolution = (1024, 768)
    camera.start_preview()

    time.sleep(1)

    camera.capture('test.jpg')
	