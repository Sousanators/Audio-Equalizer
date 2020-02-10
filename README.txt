 Audio Equalizer Project Readme
 
 This repository is for tracking and maintaining the 4th year Electrical Engineering Capstone project developed by Connor Sousa and Nicholas Pieprzak.
 
 The project is named "Audio Equalizer and Amplification System". The project is defined as a complete embedded solution which will accept various forms
 of stereo audio input (2.1V RMS line-in analog input, Bluetooth Audio, .WAV files from a SD card or USB), perform algorithms on the samples to equalize the 
 audio spectrum to the user's liking, and provide an analog output for headphones.
 
 This repository will contain the files used to program the Digital Signal Processor (DSP) which will be controlling the data flow and processing of the audio.
 
 To start, we will be using a DSPIC33FJ128GP802; a 16-bit DSP from Microchip which has integrated analog peripherals for A/D and D/A conversion.
 
 We chose this chip because it comes in a 28-DIP package which will allow for an easier development of the equalization algorithms. At a later date, 
 when the algorithms are developed or at least understood completely, we will move to a DSP which has the correct serial communication peripherals
 to communicate with the A/D and D/A converters that we would like to use in the final solution. These A/D and D/A converters are:
 
 
 A/D: Texas Instruments PCM1864DBTR 2/4 Channel, 16-24bit, 8-192KHz A/D Converter 
			(requires 1 I2S/DCI port)
 D/A: Texas Instruments PCM5102APWR 2.1V RMS Audio Stereo DAC with PLL and 16-32-bit, 8-384 kHz PCM Interface
			(requires 1 I2S/DCI port)

To start, the system will only receive the audio in a 2.1VRMS Line-in analog format, using the A/D converter in the signal chain. Once a user interface
has been developed (character LCD screen, pushbuttons, rotary encoders etc.) so the user can adjust the frequency bands of the equalization filters, more 
advanced audio input formats (as mentioned previously) will be developed.

Ideally, once enough audio input formats are supported, we will convert the user interface to use a PIC32 32-bit microcontroller with a large
internal SRAM needed to drive a graphic LCD screen. This 32-bit MCU will be able to handle a lot of the system overhead that is not included
in the equalization process, such as bluetooth, pulling audio data from a FAT filesystem (sd card, USB audio etc). 

After a nice user interface is developed with plenty of functionality, we plan to design a power amplifier for driving loudspeakers.