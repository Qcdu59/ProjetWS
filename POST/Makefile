LIBS=-lcppcms -lbooster -lmysqlclient

all: clean hello 

hello: hello.cpp view.cpp content.h
	$(CXX) -Wall hello.cpp view.cpp -o hello $(LIBS)

view.cpp: view.tmpl content.h
	cppcms_tmpl_cc view.tmpl -o view.cpp

clean:
	rm -fr *.exe *.so view.cpp cppcms_rundir hello
