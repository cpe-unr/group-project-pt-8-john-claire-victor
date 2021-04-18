/** Merges the user interface, file i/o, and audio processing all together
 */
#include <iostream>
#include <string>
#include "Wav.h"
#include "Limiter.h"
#include "Echo.h"
#include "noiseGate.h"
#include "IfileProcessing.h"

const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string limitfile = "limit.wav";
const std::string noisefile = "noise.wav";
int main() {
    // Uncomment these lines when ready.

    Wav wav;
   
    wav.readFile(testfile);
//    std::cout << wav.getBufferSize() << std::endl;
    Echo *echo = new Echo(30000);
    echo->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("echos.wav");

    delete echo;
//
//    Follow the pattern above to generate the limit and noise files
//    using the filenames provided

    wav.readFile(testfile);
    Limiter *limiter = new Limiter;
    limiter->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("limit.wav");

    delete limiter;

    wav.readFile(testfile);
    Noise *noise = new Noise(3);
    noise->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("noise.wav");

    delete noise;

    return 0;
}
