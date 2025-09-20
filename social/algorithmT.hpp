#pragma once
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class EyeTracker
{
	string m_topSubjectMatter[3];
	string m_recentSubject;
};



class Post
{
	int m_commentCount;
	Comment* m_comments;
	MediaRecognition m_imageDetails;
	Media m_media;

	double getScore();
	Post* loadPosts(int maximum = 30, long delayTimeOut = 1000);
	void sortPosts(Post* items, int sz);
};

class Comment
{
	string m_popularWords[3];
};

class MediaRecognition
{
	Media m_media;
	string m_category;
};

class User
{
	Weighted weight;
};

class Weighted
{
	bool m_isFriends;
	bool m_hasTracked;
	bool m_isSubjectRanked;
	int m_curatedScore = 0;

	double createWeight();
};

class Media
{
	unsigned long m_id;
	int m_score;
	double m_weight;
};

Post* Post::loadPosts(int maximum, long delayTimeOut)
{
	long now;
	_time32(&now);

	if (delayTimeOut < now) {
		Post* posts = new Post[maximum]();
		sortPosts(posts, maximum);
		return posts;
	}
	else {
		return NULL;
	}
}

void Post::sortPosts(Post* items, int sz) {
	
	// TODO: sort based upon post score
	return;
}

double Weighted::createWeight()
{
	double score = 1.5;
	if (m_isFriends) {
		score += 2.0;
	}
	
	if (m_hasTracked) {
		score += 1.5;
	}

	if (m_isSubjectRanked) {
		score += 1.5;
	}

	score += m_curatedScore;

	return score;
}

double Post::getScore()
{
	Comment topComment = this->m_comments[0];
	int score = this->m_commentCount * 10; /*sort by popular words for user*/
	return score;
}