#ifndef BESTSUPPORTSPOTMAKER_H
#define BESTSUPPORTSPOTMAKER_H


#include<utility>
#include<iostream>
#include<QPointF>

using namespace std;

class BestSupportSpotMaker
{
public:
  BestSupportSpotMaker();
  ~BestSupportSpotMaker();


protected:



private:


  struct SupportSpot
  {
    //point
    QPoint m_prPos;
    double m_dScore;
    SupportSpot(QPoint pos,double val):m_prPos(pos),m_dScore(val)
    {}

  };


  QPoint DetermineBestSupportingPosition();


  //1 : 골을 패스 할 잠재성
  void isPassSafeFromAllOpponents();

  //2. 골을 넣을 숭 （（（（수 있는 잠재성
  void CanShooot();

  //3. 팀 동료와의 특정 거리
  void SupportingPlayr();


  // 서포트 점수를 계산





};

#endif // BESTSUPPORTSPOTMAKER_H
