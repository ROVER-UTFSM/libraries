#!/usr/bin/python
#

__author__="Cristobal Ramirez"

import time
import picamera

if __name__ == "__main__":
	
with picamera.PiCamera() as camera:
    camera.resolution = (640, 480)
    camera.start_preview()
    camera.start_recording('foo.h264')
    camera.wait_recording(60)
    camera.stop_recording()

	