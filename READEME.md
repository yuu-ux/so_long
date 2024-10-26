Mac OS で Ubuntu環境 で動作するアプリケーションを動かす

## Usage
1. Xquartz をインストールする（https://www.xquartz.org/）
2. Settings の 「Allow connections from network clients」をチェック
し、「Authenticate connections」のチェックを外す
3. ユーザー名を取得して Dockerfile の UID を書き換える
```sh
id -u
```
4. ホストのウィンドウに接続できるようにする
```sh
xhost +local:
```
5. Linux ブランチのソースをクローンする
```sh
git clone -b linux https://github.com/yuu-ux/so_long.git
```
6. docker_start.sh に実行権限を付与する
```sh
chmod +x docker_start.sh
```
7. イメージをビルドし、docker コンテナを立ち上げる
```sh
./docker_start.sh
```
8. so_long ディレクトリへ移動する
```sh
cd so_long
```
9. make する
```sh
make re
```
9.1 サブモジュールをアップデートするタイミングでエラーがでたら以下のコマンドを実行する
```sh
git config --global --add safe.directory /so_long
```
10. プログラムを実行する
```sh
./so_long ok_map/minimum_map.ber
```
