Mac OS で Ubuntu環境 で動作するアプリケーションを動かす

## Usage
1. Xquartz をインストールする（https://www.xquartz.org/）
2. Settings の 「Allow connections from network clients」をチェック
し、「Authenticate connections」のチェックを外す
3. ユーザー名を取得して Dockerfile の UID を書き換える
```id -u```
4. local からX11 ウィンドウに接続できるようにする
```xhost +local:```
5. Linux ブランチのソースをクローンする
```git clone -b linux https://github.com/yuu-ux/so_long.git```
6. docker_start.sh に実行権限を付与する
```chmod +x docker_start.sh```
7. イメージをビルドし、docker コンテナを立ち上げる
```./docker_start.sh```
8. so_long ディレクトリへ移動する
```cd so_long```
9. make する
```make re```
9.1 サブモジュールをアップデートするタイミングでエラーがでたら以下のコマンドを実行する
```git config --global --add safe.directory /so_long```
10. プログラムを実行する
```./so_long ok_map/minimum_map.ber```