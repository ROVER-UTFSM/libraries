#! /usr/bin/python

import RPi.GPIO as GPIO
import time

if __name__ == "__main__":
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(12, GPIO.OUT, initial=GPIO.LOW)
	
	time.sleep(2)
	GPIO.output(12, GPIO.HIGH)
	time.sleep(1)
	GPIO.output(12, GPIO.LOW)
	time.sleep(3)
	GPIO.output(12, GPIO.HIGH)
	time.sleep(2)

	GPIO.cleanup(12)
