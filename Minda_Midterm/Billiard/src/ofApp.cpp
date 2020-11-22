#include "ofApp.h"
#include <math.h>
#include "Ball.h"
int st_num[10100000];
float c_r=ofMap(57,0,3000,0,1280);
float kai=ofMap(2832,0,3569,0,1280);
float ww=1280-kai+100;
float kx[6] ={0,640,1280,0,640,1280};
float ky[6] ={0,0,0,900-c_r,900-c_r,900-c_r};
float q_posx[16]={kai,ww,ww-c_r*2,ww-c_r*2,ww-c_r*4,ww-c_r*4,ww-c_r*4,ww-c_r*6,ww-c_r*3*2,ww-c_r*3*2,ww-c_r*3*2,ww-c_r*4*2,ww-c_r*4*2,ww-c_r*4*2,ww-c_r*4*2,ww-c_r*4*2};
float q_posy[16]={450,450,450-c_r,450+c_r,450-c_r*2,450,450+c_r*2,450-c_r*3,450-c_r,450+c_r,450+c_r*3,450-c_r*4,450-c_r*2,450,450+c_r*4,450+c_r*2};

float start,endd;

bool b=true;



//--------------------------------------------------------------
int f[1010][1010];
void ofApp::setup() {
	ofSetFrameRate(8000);
	ofSetCircleResolution(100);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofBackground(61,145,64);
	ofFill();
    mover QwQ;
    QwQ.setup(c_r, q_posx[0], q_posy[0],255);
    QwQ.col=glm::vec3(255,255,255);
    movers.push_back(QwQ);
	for (int i = 1; i < 16; i++) {
        mover cur;
        cur.setup(c_r, q_posx[i], q_posy[i],ofRandom(70,255));
        movers.push_back(cur);
	}
    
    /*
    ofSetColor(0);
    myImage.load("timg.jpeg");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);*/
}

void ofApp::frame_start()
{
    glm::vec2 pos= glm::vec2(ofRandom(ofGetWidth() * 0.5-120,ofGetWidth() * 0.5+120), ofGetHeight()*0.5);
    ParticleSystem particleSystem = ParticleSystem(pos);
    particleSystems.push_back(particleSystem);
    particleSystems[particleSystems.size()-1].st.pos=glm::vec2(pos.x,ofGetHeight());
    st_num[0]=5;
    gravity = glm::vec2(0, .95);
}


//--------------------------------------------------------------
void ofApp::update() {

    /*
	ofPoint wind1(0.9, 0.9);
	ofPoint wind2(-0.9, -0.9);
	ofPoint wind3(-0.9, 0.9);
	ofPoint wind4(0.9, -0.9);*/


/*	for (int i = 0; i < NUM_MOVER; i++) {
		if (movers[i].location.x > movers[i].location.y + 240 && movers[i].location.x < movers[i].location.y + 360) {
			movers[i].applyForce(wind1);
		}
		if (movers[i].location.x < movers[i].location.y - 240 && movers[i].location.x > movers[i].location.y - 360) {
			movers[i].applyForce(wind2);
		}
		if (movers[i].location.x + movers[i].location.y > 720 && movers[i].location.x + movers[i].location.y < 840) {
			movers[i].applyForce(wind3);
		}
		if (movers[i].location.x + movers[i].location.y > 240 && movers[i].location.x + movers[i].location.y < 480) {
			movers[i].applyForce(wind4);
		}

		movers[i].update();
		movers[i].checkEdges();
	}*/

	float Xdistance, Ydistance, distance;
	float Xvgap, Yvgap;
    for (int i=0;i<movers.size();i++)
    {
        movers[i].update();
        movers[i].checkEdges();
        for (int j=0;j<6;j++)
        {
            int Xdistance = movers[i].location.x - kx[j];
            int Ydistance = movers[i].location.y - ky[j];
            distance = pow(pow(Xdistance, 2) + pow(Ydistance, 2), 0.5);
            if (distance <= movers[i].mass)
            {
                if (i==0)
                {
                    mover QwQ;
                    QwQ.setup(c_r, q_posx[0], q_posy[0],255);
                    QwQ.col=glm::vec3(255,255,255);
                    movers[0]=QwQ;
                    break;
                }
                auto iter = movers.erase(std::begin(movers)+i);
                break;
            }
        }
    }
	
	for (int i = 0; i < movers.size(); i++) {
		for (int j = i; j < movers.size(); j++) {
			Xdistance = movers[i].location.x - movers[j].location.x;
			Ydistance = movers[i].location.y - movers[j].location.y;
			distance = pow(pow(Xdistance, 2) + pow(Ydistance, 2), 0.5);
			if (distance <= (movers[i].mass + movers[j].mass)) {
                if (!f[i][j])
                {
				Xvgap = movers[i].velocity.x - movers[j].velocity.x;
				Yvgap = movers[i].velocity.y - movers[j].velocity.y;
				movers[i].velocity.x -= Xvgap*1.105;
				movers[j].velocity.x += Xvgap*1.105;
				movers[i].velocity.y -= Yvgap*1.105;
				movers[j].velocity.y += Yvgap*1.105;
                    f[i][j]=1;
                }
             /*   if (movers[j].Lastpos.x-movers[i].Lastpos.x<=0)
                {
                    movers[j].location.x=movers[i].location.x-movers[i].mass-movers[j].mass;
                }
                else
                    movers[j].location.x=movers[i].location.x+movers[i].mass+movers[j].mass;
                if (movers[j].Lastpos.y-movers[i].Lastpos.y<=0)
                {
                    movers[j].location.y=movers[i].location.y-movers[i].mass-movers[j].mass;
                }
                else
                    movers[j].location.y=movers[i].location.y+movers[j].mass+movers[i].mass;*/
			}
            else
                f[i][j]=0;
		}
	}
    if (movers.size()==1&&movers[0].col==glm::vec3(255,255,255))
    {
        if (b) frame_start(),b=false;
        for (int i=0; i<particleSystems.size(); i++)
        {
            if (ofGetFrameNum() % 3 == 0 && st_num[i])
            {
                st_num[i]--;
                glm::vec2 pos2 = glm::vec2(ofRandom(particleSystems[i].pos.x-120,particleSystems[i].pos.x+120), particleSystems[i].pos.y);
                particleSystems.push_back( ParticleSystem(pos2) );
                particleSystems[particleSystems.size()-1].st.pos=glm::vec2(pos2.x, ofGetHeight());
                
            }
            if (particleSystems[i].st.pos.y>=particleSystems[i].pos.y)
            {
                glm::vec2 cur = glm::vec2(0,-15);
                particleSystems[i].st.pos+=cur;
                if (particleSystems[i].st.pos.y<=particleSystems[i].pos.y)
                    particleSystems[i].borntime=ofGetElapsedTimef();
                continue;
            }
            if (ofGetElapsedTimef()-particleSystems[i].borntime>5)
            {
                st_num[i]=0;
                particleSystems.erase(particleSystems.begin());
                continue;
            }
            particleSystems[i].applyForce(gravity);
            particleSystems[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255);
    ofDrawLine(kai, 0, kai, 900);
    ofDrawCircle(kai, 450, 16);
    ofSetColor(0);
    for (int i=0;i<6;i++)
        ofDrawCircle(kx[i],ky[i],c_r);
    ofNoFill();
    ofSetColor(255);
    ofDrawCircle(kai,450,200);
    ofSetColor(61,145,64);
    ofFill();
    ofDrawRectangle(700,0,kai-700-1,900);
    ofSetColor(255);
    ofDrawCircle(kai, 450, 16);
    
    

	for (int i = 0; i < movers.size(); i++) {
		movers[i].display();
	}
	ofDrawRectRounded(240, 240, 84, 160, 84, 0.7854);
    if (movers.size()==1&&(movers[0].col==glm::vec3(255,255,255)))
    {
        ofSetColor(0, 0, 0, 20);
        ofDrawRectangle(0,0, ofGetWidth(),ofGetHeight());
        for (int i=0; i<particleSystems.size(); i++)
        if (particleSystems[i].st.pos.y<=particleSystems[i].pos.y)
            particleSystems[i].draw();
        else
            particleSystems[i].st.draw();
    }
   // int imgWidth = myImage.getWidth();
   // int imgHeight = myImage.getHeight();
    //myImage.draw(0,0, imgWidth, imgHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key=='r')
    {
        movers.clear();
        setup();
        b=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    //start=ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    //endd=ofGetElapsedTimef();
    float how_big=ofMap(endd-start,0,10,0,3);
    float dx=ofGetMouseX()-movers[0].location.x,dy=ofGetMouseY()-movers[0].location.y;
    float length=sqrt(dx*dx+dy*dy);
    ofPoint f;
    f.set(dx*5,dy*5);
    movers[0].applyForce(f);
    

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
