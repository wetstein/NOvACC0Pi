# Meeting Notes

## Meeting with Matt and Sebastian Feb 26th, 2018

Brief talk around the pion efficiency

Tasks to do:
- Add angle w.r.t. detector axis
- Change Pion Momentum -> Kinetic Energy. This var is closer to what we actually measure (?)
- Complete analogous proton efficiency study
- Assemble structure of the Latex document
    - Do a section of selection cuts

Questions for the scrum meeting:
- Cutoff on the pion kinetic energy? What does this exactly mean?


## Meeting with Matt and Sebastian Nov 15th, 2018

We discussed the two plots Sebastian had made of sample compisition.

The graphs start out with the effects of the preselection cut. Then, everything above assumes that the preselection has been made. The other cuts are (from bottom to top):

* preselection + 1 reco prong + any other true stuff that didn't make a prong
* preselection + 1 reco prong + 1 true pion + any other true stuff that didn't make a prong
* preselection + 1 reco prong + 1 true proton + any other true stuff that didn't make a prong
* preselection + 2 reco prongs + any other true stuff that didn't make a prong
* preselection + 2 reco prongs + 1 true pion + any other true stuff that didn't make a prong
* preselection + 2 reco prongs + 1 true proton + any other true stuff that didn't make a prong
* preselection + 3 reco prongs + any other true stuff that didn't make a prong
* preselection + 3 reco prongs + 1 true proton + 1 true pion + any other true stuff that didn't make a prong
* preselection + 4 or more reco prongs + any other true stuff that didn't make a prong
* preselection + all of these selection + 1 good muon ID

Observations:
* preselection + 1 reco prong + 1 true proton + 1 good muon ID seems to give the least contamination of nonCC or even nonCC0Pi events
* preselection + 2 reco prongs + 1 true proton + 1 good muon ID, unexpectedly seems to have more contamination.


We should focus more on observables like prong length and prongCVN scores, and avoid mixing true and reco information in the selection cuts. Even before worrying about efficiencies and purities, we'd like to see the distributions of prong variables (length, CVN scores, number) for different true samples and THEN find cuts that optimize efficiency/purity.

Tasks to do:
* Make plots clearer (location of zero in horizontal axis, transparency, grid)
* Remove selections that mix reco and true information, e.g. MuID and one true pronton
* Do the prong variables (number, length, CVN scores) plots on the following TRUE samples
    -CCOpi & nonCC0Pi
    -!1Mu!1Pr (the exclamation !n meaining exactly n )
    -!1Mu!1Pi
    -!1Mu!1Pr!1Pi
   
* Check what are exactly primaries in NOvA (nu->prim); GENIE makes a distinguishes between particles coming from hard scattering, paticles after FSI and even decays some short lived particles. How is this set up in NOvA?


## Meeting with Matt and Sebastian Nov 8th, 2018

Matt created a new [overleaf document](https://www.overleaf.com/6747429828nrqyjkkgzdzb) linked to this github repo to have everythign available in a single place. The references .bib file is [here](../WorkingPaper/bibl.bib) and compiles to a pdf with clickable links overleaf

Tasks:
1) Rerun analysis without Muon presselection cut. See how many true CC0Pi were rejected
2) Look to see if any NC events with pions passed the cuts (i.e. the purity)
3) Make a slide deck with plots from today
4) Make variables for events with 1Mu1Pr, to compare with 1Mu1Pi

Observations:
- Pion ID: Good for rejecting muons, not great for selecting pions
- Muon ID: Good for rejecting pions and selecting muons. 
- Prong Length: Above ~4m, pretty sure it's a muon. Below 4m, could be either...


## Meeting with Matt and Sebastian Nov 1, 2018

Still using an older version works for CAF problems. Sebastian spoke with Miranda (notes [here](./OnMiranda'sCode.md))
Miranda uses unstandard code, written by her and Jeremy - can spiral away from the base version of CAFAna
Sebastian would prefer to stick with the standard release

Michael Baird has a talk on "Prong base studies in a Slice based world": [docdb-31906](https://nova-docdb.fnal.gov/cgi-bin/private/RetrieveFile?docid=31906&filename=18-08-24_BPF_summary_4_ND_group.pdf&version=1)
* Some capabilities already exist, but Sebastian will have to make his code work with something closer to the header.
* These new functions do not require new CAF files to be made
* Machinery still makes spectra once per slice. To do once per prong takes more hacking - that's what Miranda and Jeremy were using.

After discussing the complexities of the issue, we decided that it would be best to work on using CAF in more standard ways while we pursue more prong-based functionality at a later time.

Most immediately, we plan to move ahead with making some instant gratification plots using a sample of events with exactly 
two prongs, where one is definitely a muon at the truth-level and the other is definitely a pion, and samples with exactly one muon prong and no pions at truth level. We would the make plots:
1) Comparing track length distributions of the pion and muon prongs in the two-prong sample to the muon track in the single muon sample.
2) Comparing muon id (CVN-prong) "  "  "
3) Comparing muon id (ND-group) "  "  "
4) Comparing pion id (CVN-prong) "  "  "
5) Comparing proton id (CVN-prong) " " "
6) Comparing EM id (CVN-prong) " " "

The idea is to identify a first set of cuts that provides maximum purity without reducing efficiency. 

Side note: Sebastian has also added a [simple CAFAna example](../CAFAna/example/test.C
) for Matt's reference/learning.


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
- When do muons and pions become more indistinguishable? Select events having 1 muon and 1 pion (true) , where we have exactly two prongs (a true muon and a true pion). Then plot the Prong length, ND MuonID, the ProngCVN MuonID and ProngCVN PionID for all those. Pions and protons should have a different distribution here. Where to put the cut such that we don't touch the protons.
- How short can we make that prong length cut before we start rejecting other particles? Prong length is very transparent and orthogonal to other vars that may be correlated. So, how low can we get this cut?

Tasks to try:
1) Investigate prong length cuts (break signal and background distributions by truth particles). Focus on Pions vs Protons, and Pions vs NeutronActivity
2) Take samples with several (2,3,4...) multiplicities and plot ProngCVN IDs, break then by truth particles. Plot with several cuts on TrackLenghts (from previous file)
3) Plot explicitly 2 prong sample distributions of Pion and muon scores, to figure out how often these are confused (e.g., muon being the short track)

Things to consider:
- Protons are short (few cells), and neutrons give a displaced vertex (giveaway) and a short proton track. They might give some pizeros, but we can then put a EMID cut
- ProngCVN MuonID =-1 means prong got automatically labeled as a muon because of its length being greater than 5m.
- Contamination of electron neutrino events (i.e. electrons)
