///////////////////////////////////////////////////////////////////////////////
//
//  CAFAna Simple example analysis
//
//  Run with cafe (CAF Executor)
//  $ cafe -ss -l 1 test.C
//
//  -ss   is for snapshot, for cafe to try to locate the requested datafiles
//        in faster access disks, if available (always use).
//  -l N  is for limiting to loop over N files
//  -s M  is for skipping, i.e. running only over every other M file
//  -o K  is for offset, can be used with -s to get a different sample of files
//
///////////////////////////////////////////////////////////////////////////////


//More CAFAna includes...
#include "CAFAna/Core/Binning.h"
#include "CAFAna/Cuts/Cuts.h"
#include "CAFAna/Cuts/SpillCuts.h"
#include "CAFAna/Vars/GenieWeights.h"
#include "CAFAna/Vars/PPFXWeights.h"
#include "CAFAna/Core/Spectrum.h"
#include "CAFAna/Core/SpectrumLoader.h"
#include "CAFAna/Vars/HistAxes.h"
#include "CAFAna/Vars/Vars.h"
#include "CAFAna/Vars/NumuVars.h"
#include "CAFAna/Cuts/NumuCuts2018.h"
#include "CAFAna/Vars/WrongSignBDTVars.h"
#include "CAFAna/Vars/CVNFinalStates.h"
#include "CAFAna/Vars/PngCVNVars.h"
#include "CAFAna/Vars/CVNProngVars.h"
#include "CAFAna/Vars/BPFVars.h"
#include "CAFAna/Vars/BPFEnergyVars.h"
#include "Utilities/rootlogon.C"
#include "CAFAna/Cuts/QuantileCuts.h"

//Numu CC Inclusive headers
#include "NDAna/numucc_inc/NumuCCIncBins.h"
#include "NDAna/numucc_inc/NumuCCIncCuts.h"
#include "NDAna/numucc_inc/NumuCCIncVars.h"

//The Leo's header
#include "./LeoDefs.h"

using namespace ana;

void test(void)
{

  //------------------------------------------------------------------
  // OUTPUT FILE
  //------------------------------------------------------------------
  std::string OutName = "./test.root";
  TFile *outFile = new TFile( OutName.c_str(), "RECREATE" );

  //------------------------------------------------------------------
  // DATASET DEFINITIONS
  //------------------------------------------------------------------
  std::string MyDef = "prod_caf_R17-11-14-prod4reco.remid-hotfix.b_nd_genie_nonswap_fhc_nova_v08_full_v1";


  //------------------------------------------------------------------
  // SPECTRUM DEFINITIONS
  //------------------------------------------------------------------

  //Binning: Can also use predefined ones from includes
  const Binning kFineLowEnergyBin = Binning::Simple(300,0,3);

  //Cuts: most common ones are taken from includes
  const Cut kPresel =      kMuonIDCut           // PID cut
                        && kIsFiducial          // fiducial cut
                        && kNumuMyQuality       // ensures reconstruction
                        && kNumuTightContainND  // containment
                        ;

  //Loader object (does the loop over slices automatically)
  SpectrumLoader* loader = new SpectrumLoader(MyDef);
  loader->SetSpillCut(kStandardDQCuts && kTightBeamQualityCuts);

  //Spectrum of True Neutrino Energy
  Spectrum* sTrueNuE = new Spectrum("True Neutrino Energy [GeV]", //name
      kFineLowEnergyBin,            //binning
      *loader,                      //loader
      kTrueNuE,                     //Var object
      kPresel,                      //Cuts
      kNoShift,                     //Systematics Shift
      yweight2018);                 //Weight

  //------------------------------------------------------------------
  // CALL THE SLICE LEVEL LOOP
  //------------------------------------------------------------------
  loader->Go();


  //------------------------------------------------------------------
  // SAVE THE RESULTS
  //------------------------------------------------------------------
  sTrueNuE->SaveTo(outFile->mkdir("TrueNuE"));

  outFile->Close();

  return;

}
