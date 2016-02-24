#include <iostream>

template <typename T>
class Single{

public:
	static T* getInstance(){
		static T sInstance;
		return &sInstance;
	};

protected:
	Single() = default;

private:
	Single(const Single& ob) = delete;
	Single operator=(const Single& ob) = delete;
};


class ScoreMgr : public Single<ScoreMgr>
{
public:
	ScoreMgr():m_nScore(0){
	}

	void addScore(int score){
		m_nScore += score;
	}

	void subScore(int score){
		m_nScore -= score;
	}

	int getScore(){
		return m_nScore;
	}

private:
	int m_nScore;
};
#define sgScoreMgr ScoreMgr::getInstance()

int main(int argc, char* argv[]){

	sgScoreMgr->addScore(10);
	std::cout << "addscore 10, now socres:" << sgScoreMgr->getScore() << std::endl;

	sgScoreMgr->subScore(10);
	std::cout << "subsocre 10, now scores:" << sgScoreMgr->getScore() << std::endl;

	ScoreMgr scoreMgr;

	return 0;
}
