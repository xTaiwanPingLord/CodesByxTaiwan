from time import time
import torch
import torchvision
from torch.utils.data import DataLoader
from torch import nn
from torch.utils.tensorboard import SummaryWriter
writer = SummaryWriter("logs")

# some variabe
learning_rate = 1e-2
total_train_step = 0
total_test_step = 0
total_accuarcy = 0
epoch = 10


# Dataset
train_data = torchvision.datasets.CIFAR10(root="./dataset",
                                          train=True,
                                          transform=torchvision.transforms.ToTensor(),
                                          download=True)

test_data = torchvision.datasets.CIFAR10(root="./dataset",
                                         train=False,
                                         transform=torchvision.transforms.ToTensor(),
                                         download=True)

train_data_size = len(train_data)
test_data_size = len(test_data)

# Dataloader
train_dataloader = DataLoader(train_data, batch_size=64)
test_dataloader = DataLoader(test_data, batch_size=64)


# CIFAR10 model
nnFunc = nn.Sequential(
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

# Loss function
loss_func = nn.CrossEntropyLoss()

# Optimizer
optimizer = torch.optim.SGD(nnFunc.parameters(), lr=learning_rate)

# Train
start_time = time()
for i in range(epoch):
    print(f"-----Epoch: {i} -----".format(i=i))

    for imgs, target in train_dataloader:
        output = nnFunc(imgs)
        loss = loss_func(output, target)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        total_train_step += 1
        if total_train_step % 100 == 0:
            print(time() - start_time)
            print("Train: {}, loss: {}".format(total_train_step, loss.item()))
            writer.add_scalar("train_loss", loss.item(), total_train_step)

    # 測試步驟
    total_test_loss = 0
    total_accuarcy = 0
    with torch.no_grad():
        for imgs, target in test_dataloader:
            output = nnFunc(imgs)
            loss = loss_func(output, target)
            total_test_loss += loss.item()
            total_accuarcy += (output.argmax(1) == target).sum()
    print("Total Loss: {}".format(total_test_loss))
    writer.add_scalar("test_loss", loss.item(), total_test_step)
    
    print("Total Accuracy: {}".format(total_accuarcy/test_data_size))
    writer.add_scalar("test_accuracy", total_accuarcy/test_data_size, total_test_step)
    total_test_step += 1

    torch.save(nnFunc, "nnFunc_{}.pth".format(i))
    print("Model saved")


# if __name__ == '__main__':
#     input = torch.ones((64, 3, 32, 32))
#     output = nnFunc(input)
#     print(output.shape)

writer.close