FOURIERGEN
==========

This is the start of a simple synthesizer. It arose from the tone generator
in my audiosniff project. It produces Fourier transforms using the naive slow
method. Please excuse the mess; the whole point of this project is to let me
experiment with DSP programming. Someday I'd like to add keyboard control and
throw it in the default runlevel of a RaspberryPi installation, then run it
through a tube amp.

To compile, try

	sh < compile_command_octave

The [portaudio](www.portaudio.com) library is required.

####TODO:

Floating point frequencies. Keyboard control. Maybe fast Fourier once
everything else is stabilized

Copyright 2013 Coydog Software
