class PressureBlob {

  PVector pos;
  float r; //describes the pressure
  PVector vel;
  
  PressureBlob(float x, float y) {
    pos = new PVector(x, y);
    vel = new PVector(x, y);
    vel.mult(random(0, 0));
    r = random(10,50);
  }

  void update() {
    pos.add(vel); 
    if (pos.x > width || pos.x < 0) {
      vel.x *= -1;
    }
    if (pos.y > height || pos.y < 0) {
      vel.y *= -1;
    }
  }

  void show() {
    noFill();
    stroke(0);
    strokeWeight(1);
    ellipse(pos.x, pos.y, r*2, r*2);
  }
}
