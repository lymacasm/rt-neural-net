# Include compiler-specific information
include macports.mk

CFLAGS+= -g -W -Wall -pedantic -Werror -Wno-unused-parameter

# List all include directories here for the compiler
INCLUDES=\
	-I./Neuron \
	-I./Synapse \
	-I./Common \
	-I./Dendrite

OUTDIR = ../bin
TESTSDIR = ./Tests

# List all the lib source files to compile here
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

# --- Lib targets ---
# Build all libraries
all: $(OUTDIR) $(OUTPUTS)
	$(TIME)

# Reset to clean state
clean:
	-rm -r $(OUTDIR)

$(OUTDIR):
	mkdir -p $(OUTDIR)

# Add the source directories to vpath for % searching
vpath %.cpp $(SRC_DIRECTORIES)

$(OUTDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

# --- Test targets ---
# Mark pattern as precious so make doesn't remove it as an intermediate file
.PRECIOUS: $(OUTDIR)/Test%.exe

$(OUTDIR)/Test%.exe: $(TESTSDIR)/Test%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -I$(TESTSDIR) ./$^ -o $@ $(OUTPUTS)	

# Specify name of .cpp file without cpp extension in Tests folder as target to compile and run test
Test%: $(OUTDIR) $(OUTPUTS) $(OUTDIR)/Test%.exe
	sudo $(lastword $^)
	$(TIME)
