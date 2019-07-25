# Meeting with Shih-Kai, July 24th, 2019

- The MuonID is the main selection criterion for the CCInc. 
- It uses a BDT (TMVA) based on variables obtained from Kalman Tracks
- Formerly, RemID was used to tag muons, but this relied on some very model dependent quantities like the track length. 
  dE/dx-related quantities are among the least model dependent that we know.
    - dE/dx LLR
    - dE/dx in the last 40 cm
    - dE/dx in the last 10 cm
    were obtained from Kalman tracks and used to feed the BDT and get MuonID
 
- The analysis originally inherited the oscillation group's preselection, but after the MuonID was ready,
  a new Containment Cut, based on MuonID (rather than the old RemID) was reoptimized. Differences were on the order of 3%.
- The MuonID was trained on ~20% of the available MC and then tested for overtraining.

- The MuonID output is a distribution which is substantially flat in the middle region, and highly peaked at +1 (signal, muon track)
and -1 (background, non-muon track). To choose an appropriate value for cutting, the fractional uncertainty in the global xsection
was computed:
  - Given the very flat nature of MuonID output in the middle region, only the biggest systematics were used 
    for MuonID cut optimization
  
