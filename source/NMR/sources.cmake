### the directory name ###
SET(DIRECTORY source/NMR)

### list all filenames of the directory here ###
SET(SOURCES_LIST
	anisotropyShiftProcessor.C
	assignShiftProcessor.C
	clearShiftProcessor.C
	EFShiftProcessor.C
	experiment.C
	HBondShiftProcessor.C
	haighMallionShiftProcessor.C
	createSpectrumProcessor.C
	peak.C
	peakList.C
	shiftModel.C
	shiftModule.C
	spectrum.C
	johnsonBoveyShiftProcessor.C
	randomCoilShiftProcessor.C
)	

ADD_BALL_SOURCES("NMR" "${SOURCES_LIST}")