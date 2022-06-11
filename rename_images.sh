#!/usr/bin/bash

a=1

echo "Processing PNG"
for i in *.png; do
	new=$(printf "%04d.png" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let a=a+1
done
echo "Processing JPG"
for i in *.jpg; do
	new=$(printf "%04d.jpg" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let a=a+1
done
echo "Processing WEBP"
for i in *.webp; do
	new=$(printf "%04d.webp" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let a=a+1
done
echo "Processing JPEG"
for i in *.jpeg; do
	new=$(printf "%04d.jpg" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let a=a+1
done
echo "Processing GIF"
for i in *.gif; do
	new=$(printf "%04d.gif" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let a=a+1
done
echo "Cooked $a files"
