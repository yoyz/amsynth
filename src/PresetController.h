/* amSynth
 * (c) 2001-2005 Nick Dowell
 */

#ifndef _PRESETCONTROLLER_H
#define _PRESETCONTROLLER_H

#include <string>

#include "Preset.h"
#include "UpdateListener.h"

class PresetController {
public:
	enum { kNumPresets = 128 };

			PresetController	();
			~PresetController	();
	
	/* Selects a Preset and makes it current, updating averything as neccessary.
	 * If the requested preset does not exist, then the request is ignored, and
	 * an error value is returned. */
	int		selectPreset		(const int preset);
	int		selectPreset		(const string preset);

	// returns the preset currently being edited
	Preset&	getCurrentPreset	() { return currentPreset; }
	
	// access presets in the memory bank
	Preset&	getPreset			(int preset) { return presets[preset]; }
	const Preset & getPreset	(int preset) const { return presets[preset]; }
	Preset&	getPreset			(const string name);

	bool	containsPresetWithName(const string name);
	bool	isCurrentPresetModified() { return !currentPreset.isEqual(presets[currentPresetNo]); }
	
	// Commit the current preset to memory
	void	commitPreset		() { presets[currentPresetNo] = currentPreset; notify(); }

	// Selects a new, unused preset ready for editing.
	int		newPreset			();
	void	deletePreset		();
	
	// Saves the active preset to the filename filename
	int		exportPreset		(const string filename);
	int		importPreset		(const string filename);
	
	// Loading & Saving of bank files
	int		loadPresets			(const char *filename = NULL);
	int		savePresets			(const char *filename = NULL);

    void	setUpdateListener	(UpdateListener & ul) { updateListener = &ul; }

    int		getCurrPresetNumber	() { return currentPresetNo; }

	const std::string & getFilePath() { return bank_file; }
    
protected:
	void	notify				() { if (updateListener) updateListener->update(); }

private:
	string			bank_file;
	UpdateListener*	updateListener;
	Preset*			presets;
	Preset 			currentPreset;
	Preset			blankPreset;
	Preset 			nullpreset;
	int 			currentPresetNo;
	unsigned long 	lastPresetsFileModifiedTime;
};

#endif
