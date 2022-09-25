import torchvision
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter

dataset_transform = torchvision.transforms.Compose([
    torchvision.transforms.ToTensor()
])

writer = SummaryWriter("logs")

train_set = torchvision.datasets.CIFAR10(root="./dataset",
                                         train=True,
                                         transform=dataset_transform,
                                         download=True)

test_set = torchvision.datasets.CIFAR10(root="./dataset",
                                        train=False,
                                        transform=dataset_transform,
                                        download=True)
test_loader = DataLoader(dataset=test_set,
                         batch_size=4,
                         shuffle=True,
                         num_workers=0,
                         drop_last=False)


img, target = test_set[0]
print(img.shape)
print(target)

step = 0
for data in test_loader:
    imgs, targets = data
    writer.add_image("test_loader", imgs, step)
    print(imgs.shape)
    print(targets)
    step+=1

writer.close()