IDIR = headers
SDIR = src
ODIR = obj
LDIR = lib

CC      = g++
CFLAGS  = -Wall -g -std=c++11 -I$(IDIR)/
AR      = ar rvs

_OBJS = rovermisc.o
OBJS  = $(patsubst %,$(ODIR)/%,$(_OBJS))

LIBS = 

all : librovermisc.a

librovermisc.a : $(ODIR)/rovermisc.o
	$(AR) $(LDIR)/$@ $^
	cp $(LDIR)/$@ ../sensors/libs/


$(ODIR)/%.o:  $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean: clean_obj clean_rovermisc_lib

clean_obj:
	rm -f $(ODIR)/*.o

clean_rovermisc_lib:
	rm -f $(LDIR)/librovermisc.a
