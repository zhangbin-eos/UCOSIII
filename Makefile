
SUBDIR= Examples/POSIX/GNU/OS3/Makefile-GCC


all:
	@for n in $(SUBDIR); do $(MAKE) -C $$n ; done
clean:
	@for n in $(SUBDIR); do $(MAKE) -C $$n clean; done


.PHONY: clean
