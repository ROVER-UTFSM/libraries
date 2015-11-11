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

	_medicion = 0

	def __inti__(self):
		# constantes
		self.__pin_number = 31						# RPi 2 !
		self.__const_distance_factor = 0.000058		# datasheet

		# variable de resultados 
		self._medicion = 0

		# seteo de pines
		gpio.setup(__pin_number, gpio.IN, pull_up_down=gpio.PUD_UP)
		gpio.add_event_detect(__pin_number, gpio.FALLING, callback=self.actualizar)	# add bounce time ?
		

	def time_to_distance(self, time):
		try:
			return time / __const_distance_factor
		except:
			# TODO : handle error
			pass


	def actualizar(self):
		time0 = time.time()

		gpio.wait_for_edge(__pin_number, gpio.RISING)

		deltaT = time.time() - time0
		self._medicion = time_to_distance(deltaT)

	def getDistance(self):
		return self._medicion

	# calibration methods

	def generate_data(self):
		try:
			cm = int(raw_input("centimetros: "))
			time_stamp = []

			for i in range(1,10):
				time0 = time.time()
				gpio.wait_for_edge(__pin_number, gpio.RISING)
				time_stamp.append(time.time() - time0)

			return [cm, sum(time_stamp) / len(time_stamp)]

		except:
			# int() conversion problem
			pass

	def print_data(self):
		for x in xrange(1,10):
			point = self.generate_data()
			print(str(point[0]) + ", " + str(point[1]))


if __name__ == "__main__":

	gpio.setmode(gpio.BCM)
	
	sonar = xl_maxsonar_ez2100();

	while 1:
		time.sleep(1)
		print("Medicion: " + str(sonar.getDistance()) )
	
	gpio.cleanup()