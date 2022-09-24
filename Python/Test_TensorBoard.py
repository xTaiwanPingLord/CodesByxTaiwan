from locale import normalize
from torch.utils.tensorboard import SummaryWriter
import numpy as np
import os
import cv2
import torchvision
from torchvision import transforms

writer = SummaryWriter("logs")

img_path = R"D:\_Code\Python\data\hymenoptera_data\train\ants_img\0013035.jpg"
img = cv2.imread(img_path)  # Read the image
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)  # (cv2)BGR -> RGB
tensor_img = transforms.ToTensor()(img)  # Transform to tensor
print(type(img))
print(img.shape)
print(type(tensor_img))
print(tensor_img)

# Normalize
normalize_img = transforms.Normalize([0, 0, 0], [0.5, 0.5, 0.5])(tensor_img)

# Resize
print(img.size)
resize_img = transforms.Resize((128,256))(tensor_img)
print(resize_img)

# Compose (相當於把多個transform疊在一起，寫成一個集合的function. 注意data type: cv2 image跟tensor差異)
comp_img = transforms.Compose([transforms.ToTensor(), transforms.Resize(512)])(img)

# RandomCrop
for i in range(10):
    rand_img = transforms.RandomCrop((128,64))(tensor_img)
    writer.add_image("RandomCrop", rand_img, i)



# Write to tensorboard
writer.add_image("Img read by cv2", img, 0, dataformats="HWC")
writer.add_image("Convert to tensor", tensor_img)
writer.add_image("Normalize", normalize_img)
writer.add_image("Resize", resize_img)
writer.add_image("Resize", comp_img, 1)

for i in range(100):
    writer.add_scalar("y=x", i*2, i,)

writer.close
