CC = gcc
CXX = g++
CFLAGS = -Wall -O -g
INCLUDE = -I /usr/include/libxml2/ -I .
LIBS = -L/usr/lib/x96_64-linux-gnu -lxml2 -lz -lm
TARGET = ./grcConverter
SOURCES = grc_main.cpp grc_parser.cpp grc_strop.cpp grc_assembler.cpp grc_block.cpp grc_options.cpp \
grc_blocks_add_xx.cpp grc_variable.cpp grc_audio_sink.cpp grc_analog_sig_source_x.cpp
make:
	$(CXX) $(CFLAGS) $(SOURCES) -o $(TARGET) $(INCLUDE) $(LIBS)
clean:
	rm -rf $(TARGET)