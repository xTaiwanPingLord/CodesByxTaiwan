from torch.utils import data as data
from pathlib import Path
import torch
import random
import numpy as np
from typing import Any, Callable, Optional, Tuple
import glob
import os
import cv2
import torchvision
from torch.utils.data import DataLoader, Dataset
import tqdm

config = {'images_path': 'dataset\pictures',
          'output_path': 'dataset\output',
          'transform': 'RandomCrop',
          'outputs_from_oneimage': 5,
          'image_size': 512
          }


def ReadImages(images_path: str):
    """
    Read images from specified path. Returns a list of RGB CV2 image.
    """
    image_seqence = []
    images_path = glob.glob(os.path.join(images_path, '*.jpg')) + \
        glob.glob(os.path.join(images_path, '*.png'))
    for image_path in images_path:
        image_seqence.append(cv2.cvtColor(
            cv2.imread(image_path), cv2.COLOR_BGR2RGB))

    return image_seqence


def WriteImages(image, main: int, sec: int, output_path: str):
    """
    Write images to specified path.
    """
    image = image.numpy().transpose((1, 2, 0))
    cv2.imwrite(os.path.join(output_path, f'output_{main}-{sec}.png'),
                        cv2.cvtColor(image*255, cv2.COLOR_RGB2BGR)) # to convert float[0,1] to 0,255

def ImageTransforms(image: np.array, transform_name: str, image_size: int):
    if transform_name not in ['', 'RandomCrop', 'RandomCropWithPadding']:
        raise ValueError(f"Wrong transform name: {transform_name}"
                         "supported:'', 'RandomCrop', 'RandomCropWithPadding'")

    if transform_name == '':
        transform = torchvision.transforms.ToTensor()

    if transform_name == 'RandomCrop':
        transform = torchvision.transforms.Compose([
            torchvision.transforms.ToTensor(),
            torchvision.transforms.Resize([image_size*2, image_size*2]),
            torchvision.transforms.RandomCrop([image_size, image_size])
        ])

    if transform_name == 'RandomCropWithPadding':
        transform = torchvision.transforms.Compose([
            torchvision.transforms.ToTensor(),
            torchvision.transforms.RandomCrop([image_size, image_size])
        ])

    return transform(image)


if __name__ == '__main__':
    org_images = ReadImages(config['images_path'])

    for main in tqdm.tqdm(range(len(org_images))):
        for sec in range(config['outputs_from_oneimage']):
            image = ImageTransforms(
                org_images[main], config['transform'], config['image_size'])
            WriteImages(image, main, sec, config['output_path'])

    print('done')
