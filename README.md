# Increase-Image-Size
This project was created out of necessity due to dumb websites where you need to upload a specific size image. For example where you are asked to upload an image of `50 pixels height and width along with 40-50kb of size`. This is so dumb. If your image size is very low already there's hardly anyway to inrcease the size of the image.

But rest assured this simple program is gonna save your life.

## Options

- Usage: increase-imager [-s] <size> <inputFileName>
- -s flag to increase the size upto that size

### Examples Usage
- increase-imager -s 102456 signature.jpg // Make the new image upto 102KB only from the signature.jpg
- increase-imager -s 40K signature.jpg // Make the new image upto 40KB only from the signature.jpg
- increase-imager 40k signature.jpg // Adds 40KB to the signature.jpg and create a new image
- increase-imager 40M signature.jpg // Adds 40KB to the signature.jpg and create a new image
- increase-imager -s 10G signature.jpg // Make the new image upto 10G only from the signature.jpg

- new file final-increased-image.jpg

## How To Use

### Windows

- Download the file from the releases tab according to your platform (Windows, Linux etc)
- Open up the file explorer and go to where you have downloaded the .exe file
- On the address bar of the file explorer. Click on it and type cmd
- And type the following commands [Options](#Options)
- You can also drag and drop the file into the cmd after inserting desired size
- Eg 
    - increase-imager.exe 40k "C:\cat.jpg"
    - new file called final-increased-image.jpg

### Linux

```
git clone https://github.com/chkg2a/increase-image-size.git
cd increase-image-size && g++ functions.cpp main.cpp -o increase-imager
./increase-imager -s 40k <fileName>
```

## TO DO
- [ ] Turn this into a webapp
- [ ] Feat: Add the power to decrease or compress image
- [ ] Feat: Add the option to increase or bloat the image
- [ ] Feat: Add a feature to convert png to jpg etc