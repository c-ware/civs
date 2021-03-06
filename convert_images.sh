#!/bin/sh

index=1

echo "Processing PNG"
for i in *.png; do
	new=$(printf "%04d.apng" "$a")
	echo "$new"
	mv -i -- "$i" "$new"
	let index=a+1
done
echo "Processing JPG"
for i in *.jpg; do
	new=$(printf "%04d.apng" "$a")
	echo "$new"
	magick "$i" "$new"
	rm "$i"
	let index=a+1
done
echo "Processing WEBP"
for i in *.webp; do
	new=$(printf "%04d.apng" "$a")
	echo "$new"
	magick "$i" "$new"
	rm "$i"
	let index=a+1
done
echo "Processing JPEG"
for i in *.jpeg; do
	new=$(printf "%04d.apng" "$a")
	echo "$new"
	magick "$i" "$new"
	rm "$i"
	let index=a+1
done
echo "Processing GIF"
for i in *.gif; do
	new=$(printf "%04d.apng" "$a")
	echo "$new"
	magick "$i" "$new"
	rm "$i"
	let index=a+1
done
echo "Converted $files files"
