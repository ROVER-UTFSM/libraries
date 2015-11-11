#!/usr/bin/python

__author__ = 'Cristobal Ramirez'

# Lectura de distancia en PWM

import time
import RPi.GPIO as gpio

class xl_maxsonar_ez2100:
	"""
		Esta clase presume, que se  seteo le modo GPIO.BCM

		El tiempo esta normalizado a segundos [s]. Se usa time.time() como base
	"""

	_medicion		# último valor de medición

	def __inti__(self):
		# constantes
		__pin_number = 31						# RPi 2 !
		__const_distance_factor = 0.000058		# datasheet

		# variable de resultados 
		_medicion = 0

		# seteo de pines
		gpio.setup(__pin_number, gpio.IN, pull_up_down=gpio.PUD_UP)
		gpio.add_event_detect(31, gpio.FALLING, callback=self.actualizar)	# add bounce time ?

		

	def time_to_distance(self, time):
		try:
			return time / __const_distance_factor
		except:
			# TODO : handle error
			pass


	def actualizar(self):
		time0 = time.time()

		gpio.wait_for_edge(31, gpio.RISING)

		deltaT = time.time() - time0
		medicion = deltaT / __const_distance_factor

	def getDistance():
		return _medicion



if __name__ == "__main__":

	gpio.setmode(GPIO.BCM)
	
	sonar = xl_maxsonar_ez2100();

	while 1:
		time.sleep(1)
		print("Medición: " + str(sonar.getDistance()) )
	
	