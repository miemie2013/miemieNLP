#!/usr/bin/env python3
# -*- coding:utf-8 -*-
# Copyright (c) 2014-2021 Megvii Inc. All rights reserved.
from ..base_exp import BaseExp


class COCOBaseExp(BaseExp):
    def __init__(self):
        super().__init__()
        # ---------------- dataset ---------------- #
        # COCO2017 dataset
        self.num_classes = 80
        self.data_dir = '../COCO'
        self.cls_names = 'class_names/coco_classes.txt'
        self.ann_folder = "annotations"
        self.train_ann = "instances_train2017.json"
        self.val_ann = "instances_val2017.json"
        self.train_image_folder = "train2017"
        self.val_image_folder = "val2017"

        # COCO2017 dataset。用来调试。
        # self.num_classes = 80
        # self.data_dir = '../COCO'
        # self.cls_names = 'class_names/coco_classes.txt'
        # self.ann_folder = "annotations"
        # self.train_ann = "instances_val2017.json"
        # self.val_ann = "instances_val2017.json"
        # self.train_image_folder = "val2017"
        # self.val_image_folder = "val2017"

        # custom dataset
        # self.num_classes = 20
        # self.data_dir = '../VOCdevkit/VOC2012'
        # self.cls_names = 'class_names/voc_classes.txt'
        # self.ann_folder = "annotations2"
        # self.train_ann = "voc2012_train.json"
        # self.val_ann = "voc2012_val.json"
        # self.train_image_folder = "JPEGImages"
        # self.val_image_folder = "JPEGImages"

        # bh3_letu_dataset
        # self.num_classes = 13
        # self.data_dir = '../bh3_letu_dataset'
        # self.cls_names = 'class_names/bh3_letu_classes.txt'
        # self.ann_folder = "annotations"
        # self.train_ann = "bh3_letu_train.json"
        # self.val_ann = "bh3_letu_val.json"
        # self.train_image_folder = "images"
        # self.val_image_folder = "images"

        # yuanshen_wakuang_dataset
        # self.num_classes = 3
        # self.data_dir = '../yuanshen_wakuang_dataset'
        # self.cls_names = 'class_names/ys_wk_classes.txt'
        # self.ann_folder = "annotations"
        # self.train_ann = "annos_train.json"
        # self.val_ann = "annos_val.json"
        # self.train_image_folder = "images"
        # self.val_image_folder = "images"
