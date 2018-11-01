# Meeting Notes


## Meeting with Matt and Sebastian Nov 1, 2018

Still using an older version works for CAF problems. Sebastian spoke with Miranda (will put notes in here shortly)
Miranda uses unstandard code, written by her and Jeremy - can spiral away from the base version of CAFAna
Sebastian would prefer to stick with the standard release

Michael Baird has a talk on "Prong base studies in a Slice based world": docdb-31906
* Some capabilities already exist, but Sebastian will have to make his code work with something closer to the header.
* These new functions do not require new CAF files to be made
* Machinery still makes spectra once per slice. To do once per prong takes more hacking - that's what Miranda and Jeremy were using.


Sebastian has also added a simple CAFAna example.


## Meeting with Matt and Sebastian October 12, 2018

There were some problems in CAFana due to changes in the Develop release - going back to a previously frozen version worked to resolved.

Next step is working on plots separating by truth level particles:
* Next week, Matt should learn how a CAF analysis works
* We should talk to Miranda about how to pull out truth-particle information.


## Meeting notes: October 5th, 2018

ND group uses: 
- Own MuonID definition
- ProngCVN for pions or other particles

Questions to research:
- When do muons and pions become more indistinguishable? Select events having 1 muon and 1 pion (true) , where we have exactly two prongs (a true muon and a true pion). Then plot the Prong length, ND MuonID, the ProngCVN MuonID and ProngCVN PionID for all those. Pions and protons should have a different ditribution here. Where to put the cut such that we don't touch the protons.
- How short can we make that prong lenght cut before we start rejecting other particles? Prong length is very transpatent and orthogonal to other vars that may be correlated. So, how low can we get this cut?

Tasks to try:
1) Investigate a prong length cuts (break signal and background distriutions by truth particles). Focus on Pions vs Protons, and Pions vs NeutronActivity
2) Take samples with several (2,3,4...) multiplicities and plot ProngCVN IDs, break then by truth particles. Plot with several cuts on TrackLenghts (from previous file)
3) Plot explicitly 2 prong sample disributions of Pion and muon scores, to figure out how often these are confused (e.g., muon being the short track)

Things to consider:
- Protons are short (few cells), and neutrons gieva a displaced vertex (giveaway) and a short proton track. They might give some pizeros, but we can put a EMID cut
- ProngCVN MuonID =-1 means prong got automatcally labelled as a muon because of its length >5m
- Contamnation of electron neutrino events (so electrons)

