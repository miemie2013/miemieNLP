English | [简体中文](README_PPYOLO.md)

# PPYOLO & PPYOLOv2 & PPYOLOE


|          algorithm            | GPU num | Image num per GPU  |  Backbone  | test_size | Box AP<sup>val</sup> | Box AP<sup>test</sup> | inference time(ms) |
|:------------------------:|:-------:|:-------------:|:----------:| :-------:| :------------------: | :-------------------: |:------------------:|
| PP-YOLO_2x               |     8      |     24     | ResNet50vd |     608     |         45.3         |         45.9          |       34.49        |
| PP-YOLO_2x               |     8      |     24     | ResNet50vd |     320     |         39.5         |         40.1          |       10.69        |
| PP-YOLO               |     4      |     32     | ResNet18vd |     416     |         28.6         |         28.9          |        5.40        |
| PP-YOLOv2               |     8      |     12     | ResNet50vd |     640     |         49.1         |         49.5          |       42.58        |
| PP-YOLOv2               |     8      |     12     | ResNet101vd |     640     |         49.7         |         50.3          |       56.81        |
| PP-YOLOE-s               |     8      |     32     | cspresnet-s |     640     |         42.7         |         43.1          |       -        |
| PP-YOLOE-m               |     8      |     28     | cspresnet-m |     640     |         48.6         |         48.9          |       -        |
| PP-YOLOE-l               |     8      |     20     | cspresnet-l |     640     |         50.9         |         51.4          |       -        |
| PP-YOLOE-x               |     8      |     16     | cspresnet-x |     640     |         51.9         |         52.2          |       -        |

**Note:**

- inference time is tested by tools/eval.py, using Ubuntu20.04、GTX 1660TI、torch==1.9.1+cu102。


## Get Pretrained Weights

You can download *.pth files:

链接：https://pan.baidu.com/s/1ehEqnNYKb9Nz0XNeqAcwDw 
提取码：qe3i

Or get them by：

Firstly
```
wget https://paddledet.bj.bcebos.com/models/ppyolo_r50vd_dcn_2x_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyolo_r18vd_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyolov2_r50vd_dcn_365e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyolov2_r101vd_dcn_365e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/ResNet50_vd_ssld_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/ResNet18_vd_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/ResNet101_vd_ssld_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyoloe_crn_s_300e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyoloe_crn_m_300e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyoloe_crn_l_300e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/ppyoloe_crn_x_300e_coco.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/CSPResNetb_s_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/CSPResNetb_m_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/CSPResNetb_l_pretrained.pdparams
wget https://paddledet.bj.bcebos.com/models/pretrained/CSPResNetb_x_pretrained.pdparams
```

Input these commands:
```
python tools/convert_weights.py -f exps/ppyolo/ppyolo_r50vd_2x.py -c ppyolo_r50vd_dcn_2x_coco.pdparams -oc ppyolo_r50vd_2x.pth -nc 80
python tools/convert_weights.py -f exps/ppyolo/ppyolo_r18vd.py -c ppyolo_r18vd_coco.pdparams -oc ppyolo_r18vd.pth -nc 80
python tools/convert_weights.py -f exps/ppyolo/ppyolov2_r50vd_365e.py -c ppyolov2_r50vd_dcn_365e_coco.pdparams -oc ppyolov2_r50vd_365e.pth -nc 80
python tools/convert_weights.py -f exps/ppyolo/ppyolov2_r101vd_365e.py -c ppyolov2_r101vd_dcn_365e_coco.pdparams -oc ppyolov2_r101vd_365e.pth -nc 80
python tools/convert_weights.py -f exps/ppyolo/ppyolo_r18vd.py -c ResNet18_vd_pretrained.pdparams -oc ResNet18_vd_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyolo/ppyolov2_r50vd_365e.py -c ResNet50_vd_ssld_pretrained.pdparams -oc ResNet50_vd_ssld_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyolo/ppyolov2_r101vd_365e.py -c ResNet101_vd_ssld_pretrained.pdparams -oc ResNet101_vd_ssld_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_s_300e_coco.py -c ppyoloe_crn_s_300e_coco.pdparams -oc ppyoloe_crn_s_300e_coco.pth -nc 80
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_m_300e_coco.py -c ppyoloe_crn_m_300e_coco.pdparams -oc ppyoloe_crn_m_300e_coco.pth -nc 80
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_l_300e_coco.py -c ppyoloe_crn_l_300e_coco.pdparams -oc ppyoloe_crn_l_300e_coco.pth -nc 80
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_x_300e_coco.py -c ppyoloe_crn_x_300e_coco.pdparams -oc ppyoloe_crn_x_300e_coco.pth -nc 80
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_s_300e_coco.py -c CSPResNetb_s_pretrained.pdparams -oc CSPResNetb_s_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_m_300e_coco.py -c CSPResNetb_m_pretrained.pdparams -oc CSPResNetb_m_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_l_300e_coco.py -c CSPResNetb_l_pretrained.pdparams -oc CSPResNetb_l_pretrained.pth -nc 80 --only_backbone True
python tools/convert_weights.py -f exps/ppyoloe/ppyoloe_crn_x_300e_coco.py -c CSPResNetb_x_pretrained.pdparams -oc CSPResNetb_x_pretrained.pth -nc 80 --only_backbone True
```

Finaly, you can delete *.pdparams
```
rm -rf *.pdparams
```


**Note:**

- -f means the exp file path.
- -c means the paddle weight path to be loaded.
- -oc means the pytorch weight path to be saved.
- -nc means the num_classes.
- --only_backbone means only convert backbone weights when only_backbone == True.

After execution, the converted *.pth weight files Will be obtained in the project root directory.


## About Config File

在下面的命令中，大部分都会使用模型的配置文件，所以一开始就有必要先详细解释配置文件。

（1）mmdet.exp.base_exp.BaseExp为配置文件基类，是一个抽象类，声明了一堆抽象方法，如get_model()表示如何获取模型，get_data_loader()表示如何获取训练的dataloader，get_optimizer()表示如何获取优化器等等。


（2）mmdet.exp.datasets.coco_base.COCOBaseExp是数据集的配置，继承了BaseExp，它只给出数据集的配置。本仓库只支持COCO标注格式的数据集的训练！其它标注格式的数据集，需要先转换成COCO标注格式，才能训练（支持太多标注格式的话，工作量太大）。如何把自定义数据集转换成COCO标注格式，可以看[miemieLabels](https://github.com/miemie2013/miemieLabels) 。所有的检测算法配置类都会继承COCOBaseExp，表示所有的检测算法共用同样的数据集的配置。

COCOBaseExp的配置项有：
```
        self.num_classes = 80
        self.data_dir = '../COCO'
        self.cls_names = 'class_names/coco_classes.txt'
        self.ann_folder = "annotations"
        self.train_ann = "instances_train2017.json"
        self.val_ann = "instances_val2017.json"
        self.train_image_folder = "train2017"
        self.val_image_folder = "val2017"
```

- self.num_classes表示的是数据集的类别数；
- self.data_dir表示的是数据集的根目录；
- self.cls_names表示的是数据集的类别名文件路径，是一个txt文件，一行表示一个类别名。如果是自定义数据集，需要新建一个txt文件并编辑好类别名，再修改self.cls_names指向它；
- self.ann_folder表示的是数据集的注解文件根目录，需要位于self.data_dir目录下；
- self.train_ann表示的是数据集的训练集的注解文件名，需要位于self.ann_folder目录下；
- self.val_ann表示的是数据集的验证集的注解文件名，需要位于self.ann_folder目录下；
- self.train_image_folder表示的是数据集的训练集的图片文件夹名，需要位于self.data_dir目录下；
- self.val_image_folder表示的是数据集的验证集的图片文件夹名，需要位于self.data_dir目录下；


另外，自带有一个VOC2012数据集的配置，把
```
        # self.num_classes = 20
        # self.data_dir = '../VOCdevkit/VOC2012'
        # self.cls_names = 'class_names/voc_classes.txt'
        # self.ann_folder = "annotations2"
        # self.train_ann = "voc2012_train.json"
        # self.val_ann = "voc2012_val.json"
        # self.train_image_folder = "JPEGImages"
        # self.val_image_folder = "JPEGImages"
```
解除注释，注释掉COCO数据集的配置，就是使用VOC2012数据集了。

另外，你也可以像exps/ppyoloe/ppyoloe_crn_l_voc2012.py中一样，在子类中修改self.num_classes、self.data_dir这些数据集的配置，这样COCOBaseExp的配置就被覆盖掉（无效）了。


voc2012_train.json、voc2012_val.json是我个人转换好的COCO标注格式的注解文件，可以到这个链接下载：

链接：https://pan.baidu.com/s/1ehEqnNYKb9Nz0XNeqAcwDw 
提取码：qe3i

下载好后，在VOC2012数据集的self.data_dir目录下新建一个文件夹annotations2，把voc2012_train.json、voc2012_val.json放进这个文件夹。


所以，COCO数据集、VOC2012数据集、本项目的放置位置应该是这样：
```
D://GitHub
     |------COCO
     |        |------annotations
     |        |------test2017
     |        |------train2017
     |        |------val2017
     |
     |------VOCdevkit
     |        |------VOC2007
     |        |        |------Annotations
     |        |        |------ImageSets
     |        |        |------JPEGImages
     |        |        |------SegmentationClass
     |        |        |------SegmentationObject
     |        |
     |        |------VOC2012
     |                 |------Annotations
     |                 |------annotations2
     |                 |         |----------voc2012_train.json
     |                 |         |----------voc2012_val.json
     |                 |------ImageSets
     |                 |------JPEGImages
     |                 |------SegmentationClass
     |                 |------SegmentationObject
     |
     |------miemiedetection-master
              |------assets
              |------class_names
              |------mmdet
              |------tools
              |------...
```

数据集根目录和miemiedetection-master是同一级目录。我个人非常不建议把数据集放在miemiedetection-master里，那样的话PyCharm打开会巨卡无比；而且，多个项目（如mmdetection、PaddleDetection、AdelaiDet）共用数据集时，可以做到数据集路径和项目名无关。


（3）mmdet.exp.ppyolo.ppyolo_method_base.PPYOLO_Method_Exp是实现具体算法所有抽象方法的类，继承了COCOBaseExp，它实现了所有抽象方法。


（4）exp.ppyolo.ppyolo_r50vd_2x.Exp是PPYOLO算法的Resnet50Vd模型的最终配置类，继承了PPYOLO_Method_Exp；

PPYOLOE的配置文件也是类似这样的结构。


## Infer

（1）Infer one image
```
python tools/demo.py image -f exps/ppyolo/ppyolo_r50vd_2x.py -c ppyolo_r50vd_2x.pth --path assets/000000000019.jpg --conf 0.15 --tsize 608 --save_result --device gpu
```

```
python tools/demo.py image -f exps/ppyolo/ppyolo_r18vd.py -c ppyolo_r18vd.pth --path assets/000000000019.jpg --conf 0.15 --tsize 416 --save_result --device gpu
```

```
python tools/demo.py image -f exps/ppyolo/ppyolov2_r50vd_365e.py -c ppyolov2_r50vd_365e.pth --path assets/000000000019.jpg --conf 0.15 --tsize 640 --save_result --device gpu
```

```
python tools/demo.py image -f exps/ppyoloe/ppyoloe_crn_s_300e_coco.py -c ppyoloe_crn_s_300e_coco.pth --path assets/000000000019.jpg --conf 0.15 --tsize 640 --save_result --device gpu
```

```
python tools/demo.py image -f exps/ppyoloe/ppyoloe_crn_l_300e_coco.py -c ppyoloe_crn_l_300e_coco.pth --path assets/000000000019.jpg --conf 0.15 --tsize 640 --save_result --device gpu
```


**Note:**

- -f means the exp file path.
- -c means the weight path to be loaded.
- --path means the image path.
- --conf means the score_threshold.
- --tsize means test_size.

After the prediction is completed, the console will print the saving path of the result picture, which can be opened and viewed by the user.

**Other optional args:**

- --fp16 means using automatic mixed precision.

If you use the model saved in train.py for prediction, modify -c to the path of your saved weight.


（2）Infer image dir
```
python tools/demo.py image -f exps/ppyolo/ppyolo_r50vd_2x.py -c ppyolo_r50vd_2x.pth --path assets --conf 0.15 --tsize 608 --save_result --device gpu
```

```
python tools/demo.py image -f exps/ppyolo/ppyolo_r18vd.py -c ppyolo_r18vd.pth --path assets --conf 0.15 --tsize 416 --save_result --device gpu
```

modify --path as the image dir.


**Note:**

- -f means the exp file path.
- -d means the device(gpu) num.
- -b means the total eval batchsize(all gpus).
- -c means the weight path to be loaded.
- --conf means the score_threshold.
- --tsize means the test_size.

**Other optional args:**

- --fp16 means using automatic mixed precision.


## Train COCO2017 Dataset

Input these commands:

(1)ppyolo_r50vd_2x
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyolo/ppyolo_r50vd_2x.py -d 8 -b 192 -eb 16 -c ResNet50_vd_ssld_pretrained.pth
```

(2)ppyolo_r18vd
```
CUDA_VISIBLE_DEVICES=0,1,2,3
python tools/train.py -f exps/ppyolo/ppyolo_r18vd.py -d 4 -b 128 -eb 16 -c ResNet18_vd_pretrained.pth
```

(3)ppyolov2_r50vd_365e
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyolo/ppyolov2_r50vd_365e.py -d 8 -b 96 -eb 16 -c ResNet50_vd_ssld_pretrained.pth
```

(4)ppyolov2_r101vd_365e
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyolo/ppyolov2_r101vd_365e.py -d 8 -b 96 -eb 16 -c ResNet101_vd_ssld_pretrained.pth
```

(5)ppyoloe_crn_s_300e_coco
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_s_300e_coco.py -d 8 -b 256 -eb 16 -c CSPResNetb_s_pretrained.pth --fp16
```

(6)ppyoloe_crn_m_300e_coco
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_m_300e_coco.py -d 8 -b 224 -eb 16 -c CSPResNetb_m_pretrained.pth --fp16
```

(7)ppyoloe_crn_l_300e_coco
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_l_300e_coco.py -d 8 -b 160 -eb 16 -c CSPResNetb_l_pretrained.pth --fp16
```

(8)ppyoloe_crn_x_300e_coco
```
CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_x_300e_coco.py -d 8 -b 128 -eb 16 -c CSPResNetb_x_pretrained.pth --fp16
```

you need a super computer. Money is all you need!


**Note:**

- -f means the exp file path.
- -d means the device(gpu) num.
- -b means the total batchsize(all gpus).
- -eb means the total eval batchsize(all gpus).
- -c means the weight path to be loaded.

**Other optional args:**

- --fp16 means using automatic mixed precision.
- --num_machines means machine num.
- --resume means resume trainning from the -c weight.




## Train Custom Dataset

It's a good idea to load COCO pretrained weights to train custom dataset.
Taking the above voc2012 dataset as an example,

一、ppyolo_r50vd

（1）when 1 machine 1 gpu, input this command
```
python tools/train.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py -d 1 -b 8 -eb 4 -c ppyolo_r50vd_2x.pth
```

If the training is interrupted for some reason and you want to load the previously saved model to resume the training, just modify -c and add --resume like this
```
python tools/train.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py -d 1 -b 8 -eb 4 -c PPYOLO_outputs/ppyolo_r50vd_voc2012/13.pth --resume
```
modift -c for yourself.


（2）when 2 machine 2 gpu, 
machine 0 input this command
```
CUDA_VISIBLE_DEVICES=0
python tools/train.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py --dist-url tcp://192.168.0.107:12312 --num_machines 2 --machine_rank 0 -b 8 -eb 4 -c ppyolo_r50vd_2x.pth
```

machine 1 input this command
```
CUDA_VISIBLE_DEVICES=0
python tools/train.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py --dist-url tcp://192.168.0.107:12312 --num_machines 2 --machine_rank 1 -b 8 -eb 4 -c ppyolo_r50vd_2x.pth
```

You need to change 192.168.0.107 of the above two commands to the LAN IP of machine 0.


（3）when 1 machine 2 gpu, input this command
```
CUDA_VISIBLE_DEVICES=0,1
nohup python tools/train.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py -d 2 -b 8 -eb 2 -c ppyolo_r50vd_2x.pth     > ppyolo.log 2>&1 &
```

When transfer learning voc2012 dataset, ppyolo_r50vd's AP (0.50:0.95) can reach 0.59+, AP (0.50) can reach 0.82+, and AP (small) can reach 0.18+. Whether single gpu or multi gpus, you can get this result. You can get the same accuracy and convergence speed like PaddeDetection, and their training logs are located in the train_ppyolo_in_voc2012 folder.


Here I give examples of commands for multiple machines and multiple gpus and single machine and multiple gpus. The rest of the models are changed as follows. I only show the commands for single machine and single card below. If you want to copy and paste the commands for multiple gpus, you can check readme_yolo.txt.


二、ppyolo_r18vd模型

输入命令开始训练：
```
python tools/train.py -f exps/ppyolo/ppyolo_r18vd_voc2012.py -d 1 -b 8 -eb 4 -c ppyolo_r18vd.pth
```

迁移学习VOC2012数据集，实测ppyolo_r18vd的AP(0.50:0.95)可以到达0.39+、AP(0.50)可以到达0.65+、AP(small)可以到达0.06+。


三、ppyolov2_r50vd模型

输入命令开始训练：
```
python tools/train.py -f exps/ppyolo/ppyolov2_r50vd_voc2012.py -d 1 -b 8 -eb 2 -c ppyolov2_r50vd_365e.pth
```

迁移学习VOC2012数据集，实测ppyolov2_r50vd的AP(0.50:0.95)可以到达0.63+、AP(0.50)可以到达0.84+、AP(small)可以到达0.25+。


四、ppyoloe_s模型

输入命令开始训练（不冻结骨干网络）：
```
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_s_voc2012.py -d 1 -b 4 -eb 2 -c ppyoloe_crn_s_300e_coco.pth --fp16
```

迁移学习VOC2012数据集，实测ppyoloe_s的AP(0.50:0.95)可以到达0.48+、AP(0.50)可以到达0.68+、AP(small)可以到达0.15+。


五、ppyoloe_l模型

（1）如果是1机1卡，输入命令开始训练（冻结了骨干网络）：
```
python tools/train.py -f exps/ppyoloe/ppyoloe_crn_l_voc2012.py -d 1 -b 8 -eb 2 -c ppyoloe_crn_l_300e_coco.pth --fp16
```

（2）如果是1机2卡，输入命令开始训练（冻结了骨干网络）：
```
CUDA_VISIBLE_DEVICES=0,1
nohup python tools/train.py -f exps/ppyoloe/ppyoloe_crn_l_voc2012.py -d 2 -b 8 -eb 2 -c ppyoloe_crn_l_300e_coco.pth --fp16     > ppyoloe_l.log 2>&1 &
```


迁移学习VOC2012数据集，实测ppyoloe_l的AP(0.50:0.95)可以到达0.66+、AP(0.50)可以到达0.85+、AP(small)可以到达0.28+。不管是单卡还是多卡，都能得到这个结果。迁移学习时和PaddleDetection获得了一样的精度、一样的收敛速度，二者的训练日志位于train_ppyolo_in_voc2012文件夹下。


## Eval

The overall command format is
```
python tools/eval.py -f {path/to/exp} -d 1 -b 4 -c {path/to/pth} --conf {score_threshold} --tsize {test_size}
```


For example, input this command
```
python tools/eval.py -f exps/ppyolo/ppyolo_r50vd_2x.py -d 1 -b 4 -c ppyolo_r50vd_2x.pth --conf 0.01 --tsize 608
```

and you will get
```
Average forward time: 36.18 ms, Average NMS time: 0.00 ms, Average inference time: 36.18 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.453
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.654
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.498
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.300
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.485
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.593
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.345
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.578
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.631
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.450
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.666
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.780
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolo_r50vd_2x.py -d 1 -b 8 -c ppyolo_r50vd_2x.pth --conf 0.01 --tsize 320
```

and you will get
```
Average forward time: 10.69 ms, Average NMS time: 0.00 ms, Average inference time: 10.69 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.395
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.593
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.428
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.173
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.432
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.590
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.314
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.515
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.559
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.305
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.614
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.761
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolo_r18vd.py -d 1 -b 8 -c ppyolo_r18vd.pth --conf 0.01 --tsize 416
```

and you will get
```
Average forward time: 5.40 ms, Average NMS time: 0.00 ms, Average inference time: 5.40 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.286
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.470
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.303
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.125
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.307
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.428
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.255
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.421
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.449
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.222
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.482
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.649
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolov2_r50vd_365e.py -d 1 -b 4 -c ppyolov2_r50vd_365e.pth --conf 0.01 --tsize 640
```

and you will get
```
Average forward time: 42.58 ms, Average NMS time: 0.00 ms, Average inference time: 42.58 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.491
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.677
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.538
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.315
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.534
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.622
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.363
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.612
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.665
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.464
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.711
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.801
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolov2_r50vd_365e.py -d 1 -b 8 -c ppyolov2_r50vd_365e.pth --conf 0.01 --tsize 320
```

and you will get
```
Average forward time: 12.62 ms, Average NMS time: 0.00 ms, Average inference time: 12.62 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.424
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.608
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.457
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.207
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.469
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.631
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.330
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.542
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.588
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.331
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.655
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.800
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolov2_r101vd_365e.py -d 1 -b 4 -c ppyolov2_r101vd_365e.pth --conf 0.01 --tsize 640
```

and you will get
```
Average forward time: 56.81 ms, Average NMS time: 0.00 ms, Average inference time: 56.81 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.497
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.683
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.545
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.336
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.543
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.633
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.366
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.616
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.668
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.490
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.713
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.812
```

input this command
```
python tools/eval.py -f exps/ppyolo/ppyolov2_r101vd_365e.py -d 1 -b 8 -c ppyolov2_r101vd_365e.pth --conf 0.01 --tsize 320
```

and you will get
```
Average forward time: 16.42 ms, Average NMS time: 0.00 ms, Average inference time: 16.42 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.431
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.614
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.466
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.214
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.477
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.640
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.333
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.545
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.589
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.338
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.653
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.807
```

input this command
```
python tools/eval.py -f exps/ppyoloe/ppyoloe_crn_s_300e_coco.py -d 1 -b 8 -c ppyoloe_crn_s_300e_coco.pth --conf 0.01 --tsize 640
```

and you will get
```
 Average forward time: 21.56 ms, Average NMS time: 0.00 ms, Average inference time: 21.56 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.423
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.593
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.458
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.237
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.464
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.582
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.336
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.546
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.583
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.356
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.640
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.756
```

input this command
```
python tools/eval.py -f exps/ppyoloe/ppyoloe_crn_m_300e_coco.py -d 1 -b 8 -c ppyoloe_crn_m_300e_coco.pth --conf 0.01 --tsize 640
```

and you will get
```
Average forward time: 35.90 ms, Average NMS time: 0.00 ms, Average inference time: 35.90 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.482
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.654
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.523
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.294
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.527
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.645
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.365
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.597
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.635
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.427
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.687
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.803
```

input this command
```
python tools/eval.py -f exps/ppyoloe/ppyoloe_crn_l_300e_coco.py -d 1 -b 4 -c ppyoloe_crn_l_300e_coco.pth --conf 0.01 --tsize 640
```

and you will get
```
Average forward time: 49.45 ms, Average NMS time: 0.00 ms, Average inference time: 49.45 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.505
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.681
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.547
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.335
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.552
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.671
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.377
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.617
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.657
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.461
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.709
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.819
```

input this command
```
python tools/eval.py -f exps/ppyoloe/ppyoloe_crn_x_300e_coco.py -d 1 -b 2 -c ppyoloe_crn_x_300e_coco.pth --conf 0.01 --tsize 640
```

and you will get
```
Average forward time: 79.69 ms, Average NMS time: 0.00 ms, Average inference time: 79.70 ms
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.515
 Average Precision  (AP) @[ IoU=0.50      | area=   all | maxDets=100 ] = 0.690
 Average Precision  (AP) @[ IoU=0.75      | area=   all | maxDets=100 ] = 0.555
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.338
 Average Precision  (AP) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.562
 Average Precision  (AP) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.682
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=  1 ] = 0.383
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets= 10 ] = 0.628
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=   all | maxDets=100 ] = 0.669
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= small | maxDets=100 ] = 0.484
 Average Recall     (AR) @[ IoU=0.50:0.95 | area=medium | maxDets=100 ] = 0.718
 Average Recall     (AR) @[ IoU=0.50:0.95 | area= large | maxDets=100 ] = 0.823
```

You can also eval your custom dataset using your weight saved by train.py, just modify the -c arg. For example,
```
python tools/eval.py -f exps/ppyolo/ppyolo_r50vd_voc2012.py -d 1 -b 4 -c PPYOLO_outputs/ppyolo_r50vd_voc2012/16.pth --conf 0.01 --tsize 608
```

One thing I need to tell you is, PPYOLO and PPYOLOv2 use matrix_nms for post_process, which is include in yolo_head, thus the eval code cant't catch the NMS time, so it prints "Average NMS time: 0.00 ms". PPYOLOE use multiclass_nms for post_process, which is also include in yolo_head, thus the eval code cant't catch the NMS time, so it prints "Average NMS time: 0.00 ms".



## ONNX

I'm not going to impl it.
```

```


## NCNN

coming soon...
```

```


## TensorRT

coming soon...
```

```


## Citation

[PaddleDetection](https://github.com/PaddlePaddle/PaddleDetection)

[PPYOLOE paper](https://arxiv.org/pdf/2203.16250.pdf)

```
@article{huang2021pp,
  title={PP-YOLOv2: A Practical Object Detector},
  author={Huang, Xin and Wang, Xinxin and Lv, Wenyu and Bai, Xiaying and Long, Xiang and Deng, Kaipeng and Dang, Qingqing and Han, Shumin and Liu, Qiwen and Hu, Xiaoguang and others},
  journal={arXiv preprint arXiv:2104.10419},
  year={2021}
}
@misc{long2020ppyolo,
title={PP-YOLO: An Effective and Efficient Implementation of Object Detector},
author={Xiang Long and Kaipeng Deng and Guanzhong Wang and Yang Zhang and Qingqing Dang and Yuan Gao and Hui Shen and Jianguo Ren and Shumin Han and Errui Ding and Shilei Wen},
year={2020},
eprint={2007.12099},
archivePrefix={arXiv},
primaryClass={cs.CV}
}
@misc{ppdet2019,
title={PaddleDetection, Object detection and instance segmentation toolkit based on PaddlePaddle.},
author={PaddlePaddle Authors},
howpublished = {\url{https://github.com/PaddlePaddle/PaddleDetection}},
year={2019}
}
```

