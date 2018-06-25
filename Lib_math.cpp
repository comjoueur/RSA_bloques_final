#include "Lib_math.h"
ZZ Mcd(ZZ a,ZZ b){
  ZZ tmp,t;
  if(a<b){
  	tmp=a;
	a=b;
	b=tmp;
  }
  while(b>0){
  	tmp=b<<(NumBits(a)-NumBits(b));
	if(tmp>a)
		t=min(a-(tmp>>1),tmp-a);
	else
		t=min(a-tmp,(tmp<<1)-a);
	if(b>t){
		a=b;
		b=t;
	}
	else{
		a=t;
	}
  }
  return a;
}
ZZ InversaMod(ZZ a,ZZ p){
	if(a>p){
		ZZ tmp=a;
		a=p;
		p=tmp;
	}
	ZZ u=p,v=a,r(0),s(1),x;
	long long k=0;
	while(v!=0){
		if((u&ZZ(1))==0){
			if((r&ZZ(1))==0){
				u>>=1;r>>=1;++k;
			}
			else{
				u>>=1;r=(r+p)>>1;++k;
			}
		}
		else if((v&ZZ(1))==0){
			if((s&ZZ(1))==0){
				v>>=1;s>>=1;++k;
			}
			else{
				v>>=1;s=(s+p)>>1;++k;
			}
		}
		else{
			x=u-v;
			if(x>0){
				u=x;r-=s;
				r=(r<0)?r+p:r;
			}
			else{
				v=x*-1;s-=r;
				s=(s<0)?s+p:s;
			}
		}
	}
	r=(r>p)?r-p:r;
	r=(r<0)?r+p:r;
	return r;
}
ZZ PotenciaMod(ZZ r,ZZ p,ZZ m){
	ZZ s(1);
	r=r-(r/m)*m;
	r=(r<0)?r+m:r;
	while(p!=0){
		if((p&ZZ(1))==1){
			s=s*r-((s*r)/m)*m;
			s=(s<0)?s+m:s;
		}
		p>>=1;
		r=r*r-((r*r)/m)*m;
		r=(r<0)?r+m:r;
	}
	return s;
}
