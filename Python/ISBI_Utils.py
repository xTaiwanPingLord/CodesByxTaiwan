from sys import implementation
from tkinter import W
from turtle import forward
from numpy import double
import torch
import torch.nn as nn


class DoubleConv(nn.Module):
    def __init__(self, in_channels, out_channels) -> None:
        super().__init__()
        self.double_Conv = nn.Sequential(
            nn.Conv2d(in_channels, out_channels,
                      kernel_size=3, stride=1, padding=1),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True),
            nn.Conv2d(out_channels, out_channels,
                      kernel_size=3, stride=1, padding=1),
            nn.BatchNorm2d(out_channels),
            nn.ReLU(inplace=True)
        )

    def forward(self, x):
        return self.double_Conv(x)


class Down(nn.Module):
    def __init__(self, in_channels, out_channels) -> None:
        super().__init__()
        self.down = nn.Sequential(
            nn.MaxPool2d(2),
            DoubleConv(in_channels, out_channels)

        )

    def forward(self, x):
        return self.down(x)


class Up(nn.Module):
    def __init__(self, in_channels, out_channels, bilinear=True) -> None:
        super().__init__()
        if bilinear:
            self.up = nn.Upsample(
                scale_factor=2, mode="bilinear", align_corners=True)
        else:
            self.up = nn.ConvTranspose2d(in_channels, torch.floor(
                in_channels/2), kernel_size=2, stride=2, padding=1)
        self.conv = DoubleConv(in_channels, out_channels)

    def forward(self, x1, x2):
        x1 = self.up(x1)

        diffx = torch.tensor(x1.size()[2] - x2.size()[2])
        diffy = torch.tensor(x1.size()[3] - x2.size()[3]) #算x1 x2 高H與寬W的差異

        x1 = nn.functional.pad(x1, [torch.floor(diffx/2),
                                    diffx - torch(diffx/2),
                                    torch.floor(diffy/2),
                                    diffy - torch.floor(diffy/2)]) #左右上下 鋪0
        x = torch.cat([x2, x1], dim=1) #dim代表要接哪一個layer 在此是接channel
        return self.conv(x)