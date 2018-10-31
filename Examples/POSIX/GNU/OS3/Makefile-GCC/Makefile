
include build.cfg

all:$(TARGET)

$(TARGET):$(OBJS) $(CPPOBJS)
	@echo  "\nCFLAGS=$(CFLAGS)\n"
	@echo  "\nLDFLAGS=$(LDFLAGS)\n"
	@echo  "\nCXX -o $(TARGET)\n"
	@$(CXX) -o $(TARGET) $(OBJS) $(CPPOBJS) $(LDFLAGS)


$(OBJS):%.o:%.c
	@echo "CC $@"
	@$(CC)  -c $^ -o $@ $(CFLAGS)

$(CPPOBJS):%.o:%.cpp
	@echo "CXX $@"
	@$(CXX) -c $^ -o $@ $(CFLAGS)

packet:
	./packet.sh  Packet-sh/  VS-1616DN-EM_VS-3232DN-EM_VS-6464DN-EM $(VERSION) 256


clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
	$(RM) $(CPPOBJS)


.PHONY: all clean packet
