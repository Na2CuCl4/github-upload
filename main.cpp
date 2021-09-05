#include <MidiPlayer.h>
using namespace std;

int main(int argc, char** argv)
{
	char path[200];
	MIDIPlayerInit(&argc, argv);
	do
	{
		cout << "Please enter the path of the soundfont (*.sf2): " << endl;
		cin.getline(path, sizeof(path));
	} while (!MIDILoadSoundFont(path));
	do
	{
		cout << "Please enter the path of the music (*.mid): " << endl;
		cin.getline(path, sizeof(path));
	} while (!MIDILoad(path));
	MIDIInitGraph();
	MIDIStart();
	MIDIPlayToEnd();
	MIDIStop();
	MIDICloseGraph();
	return 0;
}