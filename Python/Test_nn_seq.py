from turtle import forward
from torch import nn
import torch
import torchvision
from torch.utils.tensorboard import SummaryWriter
writer = SummaryWriter("nn")

# method 1
class NNFunc1(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.conv1 = nn.Conv2d(3, 32, 5, padding=2)
        self.maxpool1 = nn.MaxPool2d(2)
        self.conv2 = nn.Conv2d(32, 32, 5, padding=2)
        self.maxpool2 = nn.MaxPool2d(2)
        self.conv3 = nn.Conv2d(32, 64, 5, padding=2)
        self.maxpool3 = nn.MaxPool2d(2)
        self.flatten = nn.Flatten()
        self.linear1 = nn.Linear(1024, 64)
        self.linear2 = nn.Linear(64, 10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.maxpool1(x)
        x = self.conv2(x)
        x = self.maxpool2(x)
        x = self.conv3(x)
        x = self.maxpool3(x)
        x = self.flatten(x)
        x = self.linear1(x)
        x = self.linear2(x)
        return x

nnFunc1 = NNFunc1()

# method 2 (easier)
nnFunc2 = nn.Sequential(
    nn.Conv2d(3, 32, 5, padding=2),
    nn.MaxPool2d(2),
    nn.Conv2d(32, 32, 5, padding=2),
    nn.MaxPool2d(2),
    nn.Conv2d(32, 64, 5, padding=2),
    nn.MaxPool2d(2),
    nn.Flatten(),
    nn.Linear(1024, 64),
    nn.Linear(64, 10)
)




# 檢查網路的正確性
input = torch.ones([64, 3, 32, 32])
print(nnFunc1(input))
print(nnFunc1(input).shape)

print(nnFunc2(input))
print(nnFunc2(input).shape)

writer.add_graph(nnFunc1, input)
writer.add_graph(nnFunc2, input)
writer.close()