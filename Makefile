OBJS = main.o ECG.o APD.o save.o stim.o currents.o gates.o dvdt.o human.o humandata.o rates.o revpots.o update.o fluxbuf.o voltage.o concentrations.o

heads = human.h humandata.h 

CC	= g++ 

CCFLAGS = -w


exe: $(OBJS)
	$(CC) $(OBJS) -o exe

main.o: main.cc $(heads)
	$(CC) -c $(CCFLAGS) main.cc
ECG.o: ECG.cc $(heads)
	$(CC) -c $(CCFLAGS) ECG.cc
APD.o: APD.cc $(heads)
	$(CC) -c $(CCFLAGS) APD.cc
save.o: save.cc $(heads)
	$(CC) -c $(CCFLAGS) save.cc
stim.o: stim.cc $(heads)
	$(CC) -c $(CCFLAGS) stim.cc
currents.o: currents.cc $(heads)
	$(CC) -c $(CCFLAGS) currents.cc
gates.o: gates.cc $(heads)
	$(CC) -c $(CCFLAGS) gates.cc
dvdt.o: dvdt.cc $(heads)
	$(CC) -c $(CCFLAGS) dvdt.cc
human.o: human.cc $(heads)
	$(CC) -c $(CCFLAGS) human.cc
humandata.o: humandata.cc $(heads)
	$(CC) -c $(CCFLAGS) humandata.cc
rates.o: rates.cc $(heads)
	$(CC) -c $(CCFLAGS) rates.cc
revpots.o: revpots.cc $(heads)
	$(CC) -c $(CCFLAGS) revpots.cc
update.o: update.cc $(heads)
	$(CC) -c $(CCFLAGS) update.cc
fluxbuf.o: fluxbuf.cc $(heads)
	$(CC) -c $(CCFLAGS) fluxbuf.cc
voltage.o: voltage.cc $(heads)
	$(CC) -c $(CCFLAGS) voltage.cc
concentrations.o: concentrations.cc $(heads)
	$(CC) -c $(CCFLAGS) concentrations.cc
