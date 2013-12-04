#!/bin/bash

CMD=./octave
A4=440
B4=494
C5=523
Csharp4=554
D5=587
E5=659
F5=698
Fsharp5=740
A5=880
B5=988
G5=784
Gsharp5=831
C6=1046
Csharp6=1109
E6=1319
Fsharp6=1480


WHOL=800
QUAR=400
EIGH=200
TRIL=100
#WHOL=1600
#QUAR=800
#EIGH=400
#TRIL=200


function I_() {

	$CMD $B4 $EIGH 			\
	&& $CMD $Csharp4 $EIGH 		\
	&& $CMD $D5 $EIGH 			\
	&& $CMD $E5 $EIGH 			\
	&& $CMD $Fsharp5 $EIGH 		\
	&& $CMD $D5 $EIGH 			\
	&& $CMD $Fsharp5 $QUAR 		\
								\
	&& $CMD $F5 $EIGH 			\
	&& $CMD $Csharp4 $EIGH 		\
	&& $CMD $F5 $QUAR 			\
								\
	&& $CMD $E5 $EIGH			\
	&& $CMD $C5 $EIGH			\
	&& $CMD $E5 $QUAR			\
								\
								\
	&& $CMD $B4 $EIGH 			\
	&& $CMD $Csharp4 $EIGH 		\
	&& $CMD $D5 $EIGH 			\
	&& $CMD $E5 $EIGH 			\
	&& $CMD $Fsharp5 $EIGH 		\
	&& $CMD $D5 $EIGH 			\
	&& $CMD $Fsharp5 $EIGH 		\
								\
	&& $CMD $B5 $EIGH			\
	&& $CMD $A5 $EIGH			\
	&& $CMD $Fsharp5 $EIGH 		\
	&& $CMD $D5 $EIGH 			\
	&& $CMD $Fsharp5 $EIGH 		
}
#end I_()
function I_end_hold {
	$CMD $A5 $WHOL
}
function  I_end_trill() {

	$CMD $A5 $TRIL				\
	&& $CMD $Gsharp5 $TRIL		\
	&& $CMD $A5 $TRIL			\
	&& $CMD $Gsharp5 $TRIL		\
	&& $CMD $A5 $QUAR			
}
# end I_end_trill()

function II_ {
	$CMD $Fsharp5 $EIGH			\
	&& $CMD $Gsharp5 $EIGH		\
	&& $CMD $A5 $EIGH			\
	&& $CMD $B5 $EIGH			\
	&& $CMD $Csharp6 $EIGH		\
	&& $CMD $A5 $EIGH			\
	&& $CMD $Csharp6 $QUAR		\
	&& $CMD $C6 $EIGH			\
	&& $CMD $Gsharp5 $EIGH		\
	&& $CMD $C6 $QUAR			\
	&& $CMD $B5 $EIGH			\
	&& $CMD $G5 $EIGH			\
	&& $CMD $B5 $QUAR			


	$CMD $Fsharp5 $EIGH			\
	&& $CMD $Gsharp5 $EIGH		\
	&& $CMD $A5 $EIGH			\
	&& $CMD $B5 $EIGH			\
	&& $CMD $Csharp6 $EIGH		\
	&& $CMD $A5 $EIGH			\
	&& $CMD $Csharp6 $EIGH		\
	&& $CMD $Fsharp6 $EIGH		\
	&& $CMD $E6 $EIGH			\
	&& $CMD $Csharp6 $EIGH		\
	&& $CMD $A5 $EIGH			\
	&& $CMD $Csharp6 $EIGH		\
	&& $CMD $E6 $WHOL		
}
#end II_


while true
do \
I_ && I_end_hold
I_ && I_end_trill
II_
II_
done;
