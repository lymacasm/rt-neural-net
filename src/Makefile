include macports.mk

CFLAGS+= -g -W -Wall -pedantic -Werror -Wno-unused-parameter

INCLUDES=\
	-I./Neuron \
	-I./Synapse \
	-I./Common \
	-I./Dendrite

OUTDIR = ../bin
TESTSDIR = ./Tests

SRCS=\
	./Neuron/NeuronBase.cpp \
	./Synapse/SynapseBase.cpp \
	./Common/Common.cpp

# Get the directory or each source file, and remove duplicates
SRC_DIRECTORIES=$(sort $(dir $(SRCS)))

# Get the file name of each source file
SRC_FILES=$(notdir $(SRCS))

# Get the output .o files
OUTPUTS=$(addprefix $(OUTDIR)/, $(SRC_FILES:.cpp=.o))

all: $(OUTDIR) $(OUTPUTS)
	$(TIME)

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	-rm -r $(OUTDIR)

# Add the source directories to vpath for % searching
vpath %.cpp $(SRC_DIRECTORIES)

$(OUTDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@


$(OUTDIR)/Test%.exe: $(TESTSDIR)/Test%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -I$(TESTSDIR) ./$^ -o $@ $(OUTPUTS)	

.PRECIOUS: $(OUTDIR)/Test%.exe

Test%: $(OUTDIR) $(OUTPUTS) $(OUTDIR)/Test%.exe
	sudo $(lastword $^)