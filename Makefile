obj =  allegro audio2
CPPFLAGS += -I/usr/local/include
CPPFLAGS += -g
LDFLAGS += -L/usr/local/lib
LDLIBS += -lallegro
LDLIBS += -lallegro_main
LDLIBS += -lallegro_audio
LDLIBS += -lallegro_acodec

.PHONY: all
all : $(obj)

.PHONE: clean
clean:
	rm -f $(obj)


allegro: allegro.cpp

audio2: audio2.cpp

