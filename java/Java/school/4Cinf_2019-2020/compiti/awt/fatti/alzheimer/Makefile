default:	*.java
	javac *.java -source 1.9 -target 1.9 -d out/
	cp -rf resources out/resources
	echo "Manifest-Version: 1.0" > out/manifest.mf
	echo "Main-Class: GUI" >> out/manifest.mf
	cd out; jar cmf manifest.mf ../a.jar .

compress:
	tar cvf memorino.tar *.java Makefile resources


clean:
	rm -rf out
	rm -r a.jar
