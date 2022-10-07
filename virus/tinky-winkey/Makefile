all: svc


obj\\svc.obj:
	cl /Iinc /EHsc /Wall /WX /Wv:12 /std:c++17 /c src\\svc.cpp /Foobj\\svc.obj

svc: obj\\svc.obj
	link obj\\svc.obj /DEFAULTLIB:advapi32.lib /OUT:build\\svc.exe

clean:
	del obj\\svc.obj

fclean: clean
	del build\\svc.exe

re: fclean all
