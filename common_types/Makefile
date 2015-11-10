IDIR = headers
SDIR = src
ODIR = obj
LDIR = lib

CC      = g++
CFLAGS  = -Wall -g -std=c++11 -I$(IDIR)/
AR      = ar rvs

_OBJS = typedef.o
OBJS  = $(patsubst %,$(ODIR)/%,$(_OBJS))

LIBS = 

all: libtypedef.a

libtypedef.a: $(ODIR)/typedef.o
	$(AR) $(LDIR)/$@ $^
	cp $(LDIR)/$@ ../sensors/libs/


$(ODIR)/%.o:  $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean: clean_obj clean_commontypes_lib

clean_obj:
	rm -f $(ODIR)/*.o

clean_commontypes_lib:
	rm -f $(LDIR)/libcommontypes.a
