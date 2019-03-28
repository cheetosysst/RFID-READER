import serial
import io
ser = serial.serial_for_url('/dev/ttyACM0', 115200, timeout=1)

if not ser.isOpen():
	ser.open()

print("===Connection Start===\n", "Port: " ,ser.name)

ser.flushInput()
ser.flushOutput()

try:
	while True:
		if not ser.isOpen():
			exit
		data_raw = ser.readline()
		if str(data_raw) != str("b\'\'"):
			data_raw = data_raw.decode('utf-8')
			print("CardByte: ", data_raw)
except:
	print("\n===Connection Closed===")
	ser.close()

