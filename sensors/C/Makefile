

IDIR = headers
SDIR = src
ODIR = obj
BDIR = bin
LDIR = libs

CC     = g++	
CFLAGS = -Wall -g -std=c++11 -I$(IDIR)/
LFLAGS = -L/home/user/Workspace/rover/libraries/sensors/libs/

_OBJS = joystick.o joystick_test.o
OBJS  = $(patsubst %,$(ODIR)/%,$(_OBJS))

LIBS =  -lcommontypes -lrovermisc


all: joystick_test

# Es estrictamente necesario que $(LIBS) este al final (1 hora de webeo hasta encontrar el patrón en los foros :S)
joystick_test: $(ODIR)/joystick.o $(ODIR)/joystick_test.o
	$(CC) $(LFLAGS) -o $(BDIR)/$@ $^ $(LIBS)

$(ODIR)/%.o:  $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean: clean_obj clean_exe

clean_obj:
	rm -f $(ODIR)/*.o

clean_exe:
	rm -f $(BDIR)/*

