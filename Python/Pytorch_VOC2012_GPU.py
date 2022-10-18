import torch
import torchvision
from torch.utils.data import DataLoader
from torch import nn

import UNet_Model

from torch.utils.tensorboard import SummaryWriter
writer = SummaryWriter("logs")

# some variabe
learning_rate = 1e-3
total_train_step = 0
total_test_step = 0

total_train_loss = 0
train_accuarcy = 0
total_test_loss = 0
test_accuarcy = 0

epoch = 10

# Trasforms
train_transform = torchvision.transforms.Compose([
    torchvision.transforms.RandomHorizontalFlip(),
    torchvision.transforms.ToTensor(),
    torchvision.transforms.Normalize(
        (0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010)),
])

test_transform = torchvision.transforms.Compose([
    torchvision.transforms.ToTensor(),
    torchvision.transforms.Normalize(
        (0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010)),
])


# Dataset

train_data = torchvision.datasets.VOCDetection(root="./dataset",
                                               year="2012",
                                               image_set="train",
                                               download="True",
                                               transform=train_transform)

test_data = torchvision.datasets.VOCDetection(root="./dataset",
                                              year="2012",
                                              image_set="trainval",
                                              download="True",
                                              transform=train_transform)

train_data_size = len(train_data)
test_data_size = len(test_data)

# Dataloader
train_dataloader = DataLoader(train_data, batch_size=64, shuffle=True)
test_dataloader = DataLoader(test_data, batch_size=64, shuffle=True)




# Loss function
loss_func = nn.CrossEntropyLoss()
loss_func = loss_func.cuda()

# Optimizer
optimizer = torch.optim.Adam(nnFunc.parameters(), lr=learning_rate)

# LR衰減
# scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(optimizer, 'min', 0.2, 2, min_lr=1e-8)     玩不懂==
scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(
    optimizer, epoch, eta_min=0)

# Train
start_time = time()
for i in range(epoch):
    print(f"-----Epoch: {i} -----".format(i=i))

    train_accuarcy = 0
    total_train_loss = 0
    for imgs, target in train_dataloader:
        imgs = imgs.cuda()
        target = target.cuda()

        # nn
        output = nnFunc(imgs)
        loss = loss_func(output, target)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        # 處理一些數據
        total_train_step += 1
        total_train_loss += loss.item()
        train_accuarcy += (output.argmax(1) == target).sum()
        if total_train_step % 100 == 0:
            print(time() - start_time)
            print("Train: {} |  loss: {}, total loss: {} |  LR: {}".format(
                total_train_step, loss.item(), total_train_loss, scheduler.get_last_lr()))
            writer.add_scalar("train_loss", loss.item(), total_train_step)
    scheduler.step()  # 調整LR

    # 紀錄
    writer.add_scalar("train_accuracy",
                      train_accuarcy / train_data_size,
                      total_test_step)
    writer.add_scalar("train_loss", loss.item(), total_test_step)

    # 測試步驟
    total_test_loss = 0
    test_accuarcy = 0
    with torch.no_grad():
        for imgs, target in test_dataloader:
            imgs = imgs.cuda()
            target = target.cuda()
            # nn
            output = nnFunc(imgs)
            loss = loss_func(output, target)

            # 處理一些數據
            total_test_loss += loss.item()
            test_accuarcy += (output.argmax(1) == target).sum()
            # print(target[1])
            # print(torch.argmax(output[1]))

    print("-----------------------------")
    print("Total Test Loss: {}".format(total_test_loss))
    writer.add_scalar("test_loss", loss.item(), total_test_step)

    print("Test Accuracy: {}".format(test_accuarcy/test_data_size))
    writer.add_scalar("test_accuracy",
                      test_accuarcy / test_data_size,
                      total_test_step)
    total_test_step += 1

    # torch.save(nnFunc, "nnFunc_{}.pth".format(i))
    # print("Model saved")


writer.close()


