#! /usr/bin/python

import RPi.GPIO as GPIO
import time

if __name__ == "__main__":
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(12, GPIO.OUT, initial=GPIO.HIGH)
	pwm = GPIO.PWM(12, 666.666)
	

	pwm.start(1)
	print("0%")
	time.sleep(2)
	pwm.ChangeDutyCycle(10)
	print("10%")
	time.sleep(1)
	pwm.ChangeDutyCycle(35)
	print("35%")
	time.sleep(3)
	pwm.ChangeDutyCycle(70)
	print("70%")
	time.sleep(2)
	pwm.ChangeDutyCycle(100)
	print("100%")
	time.sleep(1)
	pwm.stop()

	GPIO.cleanup(12)
