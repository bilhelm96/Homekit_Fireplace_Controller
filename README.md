# Homekit Fireplace Controller

HomeKit enabled controller for a gas fireplace with a wall switch.  The system operates such that either the wall switch or Home App can turn the fireplace on and off no matter which one sent the command first.  For example you can turn the fireplace on with the wall switch and off via Siri.  

The project uses the [HomeSpan](https://github.com/HomeSpan) library, an I2C relay, and a momentary decorator switch.  Wiring the momentary switch to the ESP 32 allows both wall and Home app control of the fireplace.  

Most gas fireplaces have a 110v outlet underneath which can provide power for the controller.  You should verify before installing.

## Parts List
* [SparkFun ESP32S2 Thing Plus](https://www.sparkfun.com/products/17743)
* [SparkFun Qwiic Single Relay](https://www.sparkfun.com/products/15093)
* [Qwiic Cable](https://www.sparkfun.com/products/14426)
* [Momentary Wall Switch](https://www.amazon.com/dp/B07828MYZJ?psc=1&ref=ppx_yo2ov_dt_b_product_details)
* [USB-C Power Supply](https://www.amazon.com/Replacement-Raspberry-Pi-4-Supply-Charger-Adapter/dp/B094J8TK61/ref=sr_1_2_sspa?keywords=usb+c+power+supply+raspberry+pi+4&qid=1671193745&sprefix=usb+c+power+supply+ras%2Caps%2C69&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyTEMxODIxMEc0M0tSJmVuY3J5cHRlZElkPUEwNDYyNDE0MkRRVTAwVVJWOVY3WiZlbmNyeXB0ZWRBZElkPUEwODE5NjY1Q1E4QlNKUjZOUTNCJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
* [Low Voltage Wire](https://www.amazon.com/Southwire-64267101-White-Bell-Wire/dp/B075TSZRSL/ref=sr_1_31?keywords=low+voltage+wire&qid=1671193217&sprefix=low+volta%2Caps%2C79&sr=8-31)

## Assembly

* Replace the existing wall switch with the momentary switch
* Under the fireplace, disconnect the wires that run from the wall switch to the on/off switch from the on/off switch and connect them to the 3.3V Pin  and Pin 17 on the ESP Board
* Connect the relay via the to the ESP Board with the Qwiic cable
* Connect new wires from the Common and NO ports on the relay to the on/off switch where you removed the wires running from the wall switch
* Plug in the power supply to the outlet under the fireplace and connect to the USC-C port on the ESP Board