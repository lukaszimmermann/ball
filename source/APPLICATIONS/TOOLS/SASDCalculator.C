// -*- Mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//

#include <BALL/FORMAT/PDBFile.h>
#include <BALL/KERNEL/molecule.h>
#include <BALL/FORMAT/molFileFactory.h>
#include <BALL/KERNEL/PTE.h>
#include <BALL/DOCKING/COMMON/flexibleMolecule.h>

#include <BALL/FORMAT/commandlineParser.h>
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

  int num_mol = 0;
  for (Molecule* mol = input->read(); mol; delete mol, mol = input->read())
  {
	  mol->atp

  }

  delete input;
  return 0;
}
