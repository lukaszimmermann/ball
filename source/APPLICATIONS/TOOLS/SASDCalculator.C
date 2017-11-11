// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//

#include <BALL/FORMAT/PDBFile.h>
#include <BALL/KERNEL/molecule.h>
#include <BALL/FORMAT/molFileFactory.h>
#include <BALL/FORMAT/commandlineParser.h>
#include <BALL/STRUCTURE/surfaceProcessor.h>
#include "version.h"

using namespace BALL;
using namespace std;

int main(int argc, char* argv[])
{
  // Setup the command line
  const String param_in("i");
  CommandlineParser parpars("SASDCalculator", "Calculates SASD distances of the protein structure", VERSION, String(__DATE__), "Analysis");
  parpars.registerMandatoryInputFile(param_in, "input molecule file");
  parpars.setToolManual("This tool calculates SASD distances by grid search");
  parpars.setSupportedFormats(param_in, "pdb");

  parpars.parse(argc, argv);

  GenericMolFile* input = MolFileFactory::open(parpars.get(param_in));

  // We only consider the first molecule in the file
  // TODO Warning if more molecules are detected
  Molecule* mol = input->read();

  // The SurfaceProcessor is needed to compute a surface representation of the molecule
  SurfaceProcessor surface_processor;



  delete mol;
  delete input;
  return 0;
}
