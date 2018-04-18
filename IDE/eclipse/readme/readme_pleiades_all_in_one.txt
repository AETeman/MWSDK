━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Pleiades All in One 4.3 (Eclipse 4.3 Kepler Windows ベース)
──────────────────────────────────────────────────
URL    : http://mergedoc.sourceforge.jp/
MAIL   : kashihara @ me.com
AUTHOR : Shinji Kashihara
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Pleiades All in One は開発対象となる言語によりパッケージを選択できる日本語 Eclipse ディストリビュー
ションです。インストールはダウンロードした zip ファイルを解凍するだけです。


ライセンス
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Pleiades 本体、JStyle は EPL です。その他のプラグイン、ソフトウェアについては、それに含まれるライセ
ンスの記述を参照してください。


履歴
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

4.3.2.v20140321

・Pleiades を最新版に更新 (プロジェクトのプロパティで Resource などが翻訳されない問題を修正)

4.3.2.v20140309

・JD-Eclipse の関連付けが設定されていなかったためデフォルト設定として追加
・同梱の JDK は 7u51 だが java/7/ のバージョンファイル名が jdk-7u45-windows～ になっていたため修正
・Pleiades を最新版に更新

4.3.2.v20140228

・[#70424] RE: antのinputタスクでSecurityException 対応 (4.3.1 では対応できていなかった)
・[#70722] Java 逆コンパイルプラグイン JD-Eclipse を Mchr3k 氏のものから本家に戻した
・java/7/lib/logging.properties でコメントアウトされている 1 行ログ出力フォーマット設定をを有効化
・python27.dll、python33.dll が含まれていなかったため python.exe がある場所に配置
・Pleiades、各種プラグイン、言語処理系を最新版に更新

4.3.1.v20131009

・[#70424] RE: antのinputタスクでSecurityException 対応

4.3.1.v20130926

・Pleiades、各種プラグイン、言語処理系を最新版に更新

4.3.0.v20130626

・Eclipse 4.3 対応、各ランタイム・プラグインのバージョンアップ
・Windows 8 で XP テーマになってしまうため、Windows 7 テーマをコピーして作成 (中身は同じ)
・Java7 Javadoc ホバー表示を日本語にするために、Java7 Javadoc ロケーションに日本語版 Javadoc URL の
　自動設定を追加 (pleiades-config.xml)
