# OpenALを使った録音＆再生プログラム
## 1.概要

C++とOpenALを用いてrecとソレの再生を行うプログラムです．

現状はmonoでしか録音できないです．


## 2.環境

VS community 2017のVC++とOpenAL最新版を用いています．

## 3.動作

ビルドして、マイクなりなんなりを接続し、実行ファイルを回してください．

### 3.1 録音

先に録音します．

- コマンドウィンド起動後、任意のキー入力により録音を開始します．

- 録音を止める場合は、Spaceキーを押下して下さい．

- 録音が止まると『Stop Rec』と表示され、波形データをtxtに吐き出します．

	- wavの出力を出来る様に今後変更するのが目標です．

### 3.2 再生

- 再生は『何かキーを押すと録音したものを再生します．』の後に任意のキーを入力すると再生されます．

- 再生が終わると『Fin』と表示され、プログラムが終了します．



## 4.参考文献

OpenAL 1.1 Specification and Reference —仕様書およびリファレンス—, 2019.05.16 閲覧  
<http://www.memorize-being.net/releases/oal11spec-ja/index.html)>
チュートリアル形式で始めるOpenAL, 西山信行, 2014<https://www.amazon.co.jp/dp/B00IKMYWCM/ref=cm_sw_r_tw_dp_U_x_HEr3CbGJ2TK7V>
