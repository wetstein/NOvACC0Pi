Code is located in Miranda's directory:

```/nova/app/users/melkins/MultiNeutronTest/nova-neutron-analysis```

This is the header file which contains most of the prong variables she works with

```Neutrons_CAFAna_shared_multivar.h```

Some ideas on how the plotting works with the variables can be found in the plotting macro:

```Neutron_Prongs_multivar.C```


The rationale behind her code is as follows: Plotting macro plots prongs variables. However, I certain prongs need to be cut out in each interaction for isolating neutron prongs. Jeremy helped by changing a piece of CAFAna only for her so that multivars are only filled with prongs that meet those cuts. CAFAna didn't have a way of doing this elegantly before. If we need to do so to, Jeremy's changes can be found in the 

```prongcut_multivar```

branch of the package of CAFAna or just working within that branch. Though note we will need that same branch of everything else we check out as well.
