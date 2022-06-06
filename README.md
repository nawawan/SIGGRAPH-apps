# SIGGRAPH-apps

# Usage

LeapMotionを繋いだPCでsrcディレクトリにLeapMotionの起動に必要なファイル(Leap.hなど)を入れてoscSendExampleをbuildする。
(LeapMotionがarmアーキテクチャに対応していないので注意)

この際、ofApp.h内のHOSTを送信先に変更する。

現在はLeapMotionでScreen Tapのジェスチャーをしたらジェスチャーの3次元座標が送信される。
