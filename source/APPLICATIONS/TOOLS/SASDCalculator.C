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

  // We only consider the first molecule in the file
  // TODO Warning if more molecules are detected
  Molecule* mol = input->read();

  // Determine dimensions of the grid with the minimal and maximal spatial coordinates
  double double_max(std::numeric_limits<double>::max());
  double min_x(double_max);
  double min_y(double_max)
  double min_z(double_max);

  for (AtomConstIterator it = mol->beginAtom(); +it; it++)
  {
	  // We explicitly ignore hydrogen here
	  if (it->getElement().getSymbol() != "H")
  	  {
		 TVector3<double> vec(it->getPosition());
		 cout << "x: " << vec.x << endl;
		 cout << "y: " << vec.y << endl;
		 cout << "z: " << vec.z << endl;
  	  }
  }



  delete mol;
  delete input;
  return 0;
}
