default:	*.java
	javac *.java -d out/
	echo "Manifest-Version: 1.0" > out/manifest.mf
	echo "Main-Class: com.mentalabs.Main" >> out/manifest.mf
	cd out; jar cmf manifest.mf ../a.jar .


clean:
	rm -r out
	rm -r a.jar
