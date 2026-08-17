from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BpxBlur(1))
after.save("out.bmp")
