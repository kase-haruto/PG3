#include <iostream>
#include <type_traits>
#include <vector>
#include <memory>

/////////////////////////////////////////////////////////////////////////////////////////
//                  インターフェース
/////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 家電製品のインターフェースクラス
/// </summary>
class IConsumerElectronics{
public:
	IConsumerElectronics() = default;
	virtual ~IConsumerElectronics() = default;

	virtual void Update() = 0;

private:

};

/////////////////////////////////////////////////////////////////////////////////////////
//                  派生クラス
/////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// 冷蔵庫クラス
/// </summary>
class Refrigerator:
	public IConsumerElectronics{
public:
	Refrigerator() = default;
	~Refrigerator()override = default;


	void Update()override;
};


/// <summary>
/// 電子レンジクラス
/// </summary>
class Microwave:
public IConsumerElectronics{
public:
	Microwave() = default;
	~Microwave()override = default;

	void Update()override;
};


/////////////////////////////////////////////////////////////////////////////////////////
//                  main
/////////////////////////////////////////////////////////////////////////////////////////

int main(){
	std::vector<std::unique_ptr<IConsumerElectronics>> electronics;
	//冷蔵庫
	electronics.emplace_back(std::make_unique<Refrigerator>());
	//電子レンジ
	electronics.emplace_back(std::make_unique<Microwave>());

	for (size_t i = 0; i < 2; i++){
		electronics[i]->Update();
	}

    // プログラムの終了前に一時停止
    std::cin.get();
	return 0;
}

void Refrigerator::Update(){
	std::cout << "冷やしています。" << std::endl;
}

void Microwave::Update(){
	std::cout << "温めています。" << std::endl;
}
