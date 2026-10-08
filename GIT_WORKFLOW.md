# 本仓库的 Git 使用方式

## 两个远端的职责

- `origin`：个人 fork，用于保存自己的作业、代码和整理设置。
- `upstream`：老师的课程仓库，只用于获取课程更新。

本地 `main` 跟踪 `origin/main`。老师发布更新后，使用下面的命令同步：

```bash
git fetch upstream
git merge upstream/main
git push origin main
```

同步前应先提交自己的修改，避免未完成的作业与课程更新混在一起。

## 精简本机显示内容

仓库中的 `.sparse-checkout` 会隐藏以下不常用目录，但不会从 Git 历史或远端删除它们：

- `2026spring-cs201/`
- `courseware/pptx_builder/`

在新的电脑或新克隆的仓库中启用：

```bash
./tools/apply_sparse_checkout.sh
```

需要临时查看完整仓库时，可恢复全部文件：

```bash
git sparse-checkout disable
```
