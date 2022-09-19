from tensorboardX import SummaryWriter
import numpy as np
import os
import cv2
import torchvision

writer = SummaryWriter("logs")
img = cv2.imread(R"D:\_Code\Python\data\hymenoptera_data\train\ants_img\0013035.jpg")
print(type(img))
print(img.shape)
writer.add_image("this is a tag", img, dataformats="HWC")

for i in range(100):
    writer.add_scalar("y=x", i*2, i,)

writer.close
