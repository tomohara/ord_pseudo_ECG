# ord_pseudo_ECG

Output files include "one", "two", "three", "four", "five",
"voltages", "apd", and "ecg".  "one" through "five" give detailed
output for cells at 5 places along the entire fiber.  "voltages"
contains voltage versus time for each cell in the strand.  "apd" tells
the APD90 for each cell in the fiber at the last simulated beat. "ecg"
gives the pseudo-ECG (Phi), the gradient of the voltage (gradV), and
conduction velocity (CV).

The file " human.cc" is the control panel for the model where the user
can set most parameters for the simulation.  Initial conditions are
loaded from specified txt files in "humandata.cc".

Three inputs are required to avoid seg fault: 1) pacing CL, 2) # of beats to simulate, 3) # of beats to save.  The fourth input is just an "extra" tag.

human::human(char argv1[],char argv2[], char argv3[],char argv4[])
{
CL=atof(argv1);
beats=atoi(argv2);
beatssave=atoi(argv3);
extra=argv4;

In my published figures, I typically show the 10th paced beat.

e.g.

"./exe 1000 10 1 blah"

The result of this simulation is in the output folder
