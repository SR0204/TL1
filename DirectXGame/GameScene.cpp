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
}

void GameScene::Update() {}

void GameScene::Draw() {}
