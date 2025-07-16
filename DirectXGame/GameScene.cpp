#include "GameScene.h"
#include <KamataEngine.h>

#include <cassert>
#include <fstream>
#include <json.hpp>
#include <string>
#include <vector>

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	//-------------------------------------------------------------------//
	// レベルデータを格納する為の構造体
	//-------------------------------------------------------------------//

	// オブジェクト一個分のデータ
	struct ObjectData {
		std::string type; //"type"
		std::string name; //"name"

		//"transform"
		struct Transform {
			Vector3 translation; //"translation"
			Vector3 rotation;    //"rotation"
			Vector3 scaling;     //"scaling"
		};

		Transform transform; // メンバの準備

		//"file name"
		std::string file_name;
	};

	// レベルデータ
	struct LevelData {
		//"name"
		std::string name;

		//"object"
		std::vector<ObjectData> objects;
	};

	//-------------------------------------------------------------------//
	// Jsonファイルのデシリアライズ化
	//-------------------------------------------------------------------//

	// jsonファイルのパス名
	const std::string fullpath = std::string("Resources/levels/") + "untitled.json";

	// ファイルストリーム
	std::ifstream file;

	// ファイルを開く
	file.open(fullpath);
	// ファイルオープン失敗をチェック
	if (file.fail()) {
		assert(0);
	}

	nlohmann::json deserialized; // deserialized : 逆シリアライズ化
	                             // →1つの文字列をメモリ中のデータ構造化すること
	                             // serialize : 一列に並べる操作のこと
	                             // →１つの文字列で表現する「直列化」のこと

	// ファイルから読み込み、メモリへ格納
	file >> deserialized;

	// 正しいレベルデータファイルかチェック
	assert(deserialized.is_object()); // objectか※json形式にはさまざまな型がある
	                                  // object型はその中でも「キーと値のペアを持つ構造」つまり連想配列が扱えるか聞いている
	assert(deserialized.contains("name"));//"name"が含まれているか
	assert(deserialized["name"].is_string());//["name"]は文字列か？
}

void GameScene::Update() {}

void GameScene::Draw() {}
