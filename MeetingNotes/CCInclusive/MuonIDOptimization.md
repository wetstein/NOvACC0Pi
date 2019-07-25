# Meeting with Shih-Kai, July 24th, 2019

- The MuonID is the main selection criterion for the CCInc. 
- It uses a BDT (TMVA) based on variables obtained from Kalman Tracks
- Formerly, RemID was used to tag muons, but this relied on some very 
  model dependent quantities like the track length. 
  dE/dx-related quantities are among the least model dependent that we know.
    - dE/dx LLR
    - dE/dx in the last 40 cm
    - dE/dx in the last 10 cm
    were obtained from Kalman tracks and used to feed the BDT and get MuonID
 
- The analysis originally inherited the oscillation group's preselection, 
  but after the MuonID was ready, a new Containment Cut, based on MuonID 
  (rather than the old RemID) was reoptimized. Differences were on the 
  order of 3%.
- The MuonID was trained on ~20% of the available MC and then tested for 
  overtraining.

- The MuonID output is a distribution which is substantially flat in the 
  middle region, and highly peaked at +1 (signal, muon track) and -1 
  (background, non-muon track). To choose an appropriate value for cutting, 
  the fractional uncertainty in the global xsection (dS/S) was computed:
  - Given the very flat nature of MuonID output in the middle region, 
    only the biggest systematics were used for MuonID cut optimization
    
 
 

## Some notes on systematics
- The influence of systematics in the dS/S (fractional uncertainty in the
  global xsection) is assessed by running the selection anaylsis with
  different systematics samples and watching how much dS/S changes.

- From previous experience, the flux, cross section and detector calibration
  systematics were know to be the biggest ones.

- A full systematics analysis is due at the latest stage of the analysis,
  then every single possible variation is dealt with. 
  
- How systematics are dealt with in NOvA:
  - Flux and generator (GENIE) are handled with reweighting, tunable knobs
    are moved and weights are computed to apply to the simulated events.
    This is a relatively quick process, usually done on the fly (run 
    interactively at the gpvm nodes)
  - Detector systematics: light level, calibration: These require
    processing the full simutlation chain and are very time consuming. Assuming
    they are independent of the flux, generator and among themselves, their 
    effect is factored: a number of systematic samples have been generated 
    by the Production group, varying one tunable detector parmeter at once. 
    The ccinc selection is tun on these samples to see the effect on dS/S.
  
