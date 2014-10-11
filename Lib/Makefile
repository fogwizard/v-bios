subdir=arm stdlib
obj   =arm/buildin.o stdlib/buildin.o


all: build_sub $(buildin_obj)

build_sub: 
	@for dir in $(subdir); do make -C $$dir all;done;
$(buildin_obj):$(obj)
	$(LD) $(LDFLAG) -r $^ -o $@
	
