#all (přeloží projekt - včetně programu pro profiling)
#pack (zabalí projekt tak, aby mohl být odevzdán)
#clean (smaže všechny soubory, co nemají být odevzdány)
#test (spustí testy matematické knihovny)
NumberTest:
	make -f MakeTests.mk NumberTest;./NumberTest
InterpretTest:
	make -f MakeTests.mk InterpretTest;./InterpretTest
LexicalAnalyzerTest:
	make -f MakeTests.mk LexicalAnalyzerTest;./LexicalAnalyzerTest
clean:
	rm -f NumberTest InterpretTest LexicalAnalyzerTest *.o *.a tests/*.o
#doc (spustí generování dokumentace)
#run (spustí program)
