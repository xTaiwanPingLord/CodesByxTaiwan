from pathlib import Path
import torch
import random
import numpy as np
from typing import Any, Callable, Optional, Tuple
import glob
import os
import cv2
import torchvision
import tqdm
import math

config = {'images_path': 'dataset\pictures',
          'output_path': 'dataset\output',
          'transform': 'RandomCropWithPadding',
          'outputs_from_oneimage': 10,
          'image_size': 512,
          'image_resize_scale': 1.5,
          'image_pad_scale': 0.2
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
                cv2.cvtColor(image*255, cv2.COLOR_RGB2BGR))  # to convert float[0,1] to 0,255


def ImageTransforms(image: np.array, transform_name: str, image_size: int, resize_scale: int, pad_scale: int):
    if transform_name not in ['RandomCrop', 'RandomCropWithPadding']:
        raise ValueError(f"Wrong transform name: {transform_name} \n"
                         "supported: 'RandomCrop', 'RandomCropWithPadding'")

    if transform_name == '':
        transform = torchvision.transforms.ToTensor()

    if transform_name == 'RandomCrop':
        resize = math.floor(image_size*random.uniform(1, resize_scale))
        transform = torchvision.transforms.Compose([
            torchvision.transforms.ToTensor(),
            torchvision.transforms.Resize(resize),
            torchvision.transforms.RandomCrop([image_size, image_size])
        ])

    if transform_name == 'RandomCropWithPadding':
        resize = math.floor(image_size*random.uniform(
            1 / resize_scale**(1. / 3), resize_scale))
        padding = math.floor(resize*random.uniform(0, pad_scale))

        transform = torchvision.transforms.Compose([
            torchvision.transforms.ToTensor(),
            torchvision.transforms.Resize(resize),
            torchvision.transforms.Pad(padding, padding_mode='constant'),
            torchvision.transforms.RandomCrop(
                [image_size, image_size], pad_if_needed=True)
        ])

    return transform(image)


if __name__ == '__main__':
    org_images = ReadImages(config['images_path'])

    for main in tqdm.tqdm(range(len(org_images))):
        for sec in range(config['outputs_from_oneimage']):
            image = ImageTransforms(
                org_images[main], config['transform'], config['image_size'], config['image_resize_scale'], config['image_pad_scale'])
            WriteImages(image, main, sec, config['output_path'])

    print('done')
