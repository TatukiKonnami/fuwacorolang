# Fuwa(fuwacorolang)

⚠注意: このプロジェクトは企画段階で仕様すら決まっていません　悲しす(>_<)　(´・ω・`)<文句はふわふわにいってよ
まだ夢物語だぞ♥

ふわふわ言語（Fuwa）をつくり、
これでなんかつくれるようなつーるも作ってふわふわを世界に広めるプロジェクトです。

最初の段階ではコンソールで動くスクリプト言語を想定し、マルチプラットフォーム言語としたい。
最終的にはスマフォなども対象プラットフォームとしてカバーしたい。

# 言語設計
- モダンなプログラミング言語を目指したい。
- LLVMを使用してコンパイラから作る？　
- エラー情報を正確にかつ必要十分な提供
- 型推論くらいは流行り故取り入れたい
- 他にも強そうな機能が欲しい


# 言語構文
まだ
# 予約語

## 型

**int**

**float**

**bool**

**string**

**object**

## 制御

**if**

if式の形で評価したい

**switch**

**for**

Javaでいう拡張for文的な感じで

**while**

**return**


# ライブラリ

まだ全く考えていないが必要ななったら考える感じで

とりあえず標準で入れたいやつ思いつくやつだけ
- console
- 型情報
- コレクション
- ファイル操作
- GUI
- 文字列
- ネットワーク

# Licence

MIT Licence

# Version Rule

format

``` A.BB.CCC ```

### (A)
明らかに非互換仕様変更

### (BB)
機能追加や上位互換と判断できる仕様変更

### (CCC)
ちょっとしたアップデート・仕様変更
