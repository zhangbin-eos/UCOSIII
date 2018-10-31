
include build.cfg

all:$(TARGET) install

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

install:
	cp -rf $(TARGET) $(RELEASE)

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
	$(RM) $(CPPOBJS)


.PHONY: all clean packet
