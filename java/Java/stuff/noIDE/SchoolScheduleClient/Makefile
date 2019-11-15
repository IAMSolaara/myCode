TARGETS := Main.java

CLASSPATH := ".;"

default:	$(TARGETS)
	javac *.java -d out/
clean:
	rm -r out
	rm -r a.jar
tojar:
	javac *.java -d out/
	echo "Manifest-Version: 1.0" > out/manifest.mf
	echo "Main-Class: Main" >> out/manifest.mf
	cd out; jar cmf manifest.mf ../a.jar .
