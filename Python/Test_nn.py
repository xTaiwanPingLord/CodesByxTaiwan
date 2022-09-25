import torchvision
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter
from torch import nn
import torch

writer = SummaryWriter("logs")

dataset_transform = torchvision.transforms.Compose([
    torchvision.transforms.ToTensor()
])

test_set = torchvision.datasets.CIFAR10(root="./dataset",
                                        train=False,
                                        transform=dataset_transform,
                                        download=True)
test_loader = DataLoader(dataset=test_set,
                         batch_size=4,
                         shuffle=True,
                         num_workers=0,
                         drop_last=False)


nnFunc1 = nn.Sequential(
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


loss_func = nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(nnFunc1.parameters(), 0.01)
steps = 0

for epoch in range(20):
    steps = 0
    running_loss = 0
    for imgs, targets in test_loader:
        output = nnFunc1(imgs)
        # writer.add_images("input", imgs, steps)
        # writer.add_images("output", output, steps)

        optimizer.zero_grad()                        # 清除梯度
        result_loss = loss_func(output, targets)     # 計算loss
        result_loss.backward()                       # 求出梯度
        optimizer.step()                             # Apply
        steps += 1
        running_loss += result_loss
    print(running_loss)


# save model method 1: 保存參數+結構
# torch.save(model_name, "save_name.pth")
# torch.load("saved_name.pth")

# save model method 2: 保存參數
# torch.save(model_name.state_dict(), "save_name.pth")
# model1 = torchvision.models.vgg16(pretrained = False)
# model1.load_state_dict("saved_name.pth")

