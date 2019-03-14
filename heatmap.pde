//Code referenced:
// Daniel Shiffman  (modified slightly for chiprobots alligator test)
// http://codingrainbow.com

//Foot mapping has 4 points
PressureBlob[] pBlobs = new PressureBlob[4];
void setup() {
  size(500, 500);
  colorMode(HSB);
  //for (int i = 0; i < blobs.length; i++) {
  pBlobs[0] = new PressureBlob(275, 400); //heel
  pBlobs[1] = new PressureBlob(235, 235); // mm
  pBlobs[2] = new PressureBlob(250, 150); //mf
  pBlobs[3] = new PressureBlob(320, 200); //ll
  //}
}

void draw() {
  background(51);
  loadPixels();
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int index = x + y * width;
      float sum = 0;
      
      for (PressureBlob pb : pBlobs) {
        float d = dist(x, y, pb.pos.x, pb.pos.y); //distance from pblob
        sum += 30 * pb.r / d; //r is pressure
      }
      pixels[index] = color(sum, 255, 255);
    }
    
  }
  updatePixels();

  //For black circles that outline pressure
  for (PressureBlob pb : pBlobs) {
    pb.update();
    pb.show();
  }
}
