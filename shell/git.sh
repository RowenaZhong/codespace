#!/bin/bash
ssh -T git@gitee.com
ssh -T git@github.com
git fetch gitee
git fetch github
git config --global user.name "rowena"
git config --global user.email "1374682909@qq.com"
git config --unset commit.gpgsign