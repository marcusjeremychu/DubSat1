/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CDR_autocode_data.c
 *
 * Code generated for Simulink model 'CDR_autocode'.
 *
 * Model version                  : 1.217
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Oct 31 19:47:41 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->MSP430
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "CDR_autocode.h"

/* Invariant block signals (auto storage) */
const ConstB rtConstB = {
  { 1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9, 0.0, 0.0, 0.0,
    1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9, 0.0, 0.0, 0.0,
    1.0033333333333333E-7, 0.0, 0.0, 5.0000000000000009E-9,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
    5.0000000000000009E-9, 0.0, 0.0, 1.0E-7 }/* '<S5>/Product1' */
};

/* Constant parameters (auto storage) */
const ConstP rtConstP = {
  /* Pooled Parameter (Expression: k)
   * Referenced by:
   *   '<S85>/k[13][13]'
   *   '<S76>/k[13][13]'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33333333333333331,
    0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.26666666666666666, 0.2, 0.0, -0.33333333333333331, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.25714285714285712, 0.22857142857142856,
    0.14285714285714285, 0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25396825396825395, 0.23809523809523808, 0.19047619047619047,
    0.1111111111111111, 0.0, -0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25252525252525254, 0.24242424242424243, 0.21212121212121213,
    0.16161616161616163, 0.090909090909090912, 0.0, -0.1111111111111111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.25174825174825177, 0.24475524475524477,
    0.22377622377622378, 0.1888111888111888, 0.13986013986013987,
    0.076923076923076927, 0.0, -0.090909090909090912, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25128205128205128, 0.24615384615384617, 0.23076923076923078,
    0.20512820512820512, 0.16923076923076924, 0.12307692307692308,
    0.066666666666666666, 0.0, -0.076923076923076927, 0.0, 0.0, 0.0, 0.0,
    0.25098039215686274, 0.24705882352941178, 0.23529411764705882,
    0.21568627450980393, 0.18823529411764706, 0.15294117647058825,
    0.10980392156862745, 0.058823529411764705, 0.0, -0.066666666666666666, 0.0,
    0.0, 0.0, 0.25077399380804954, 0.24767801857585139, 0.23839009287925697,
    0.22291021671826625, 0.20123839009287925, 0.17337461300309598,
    0.13931888544891641, 0.099071207430340563, 0.052631578947368418, 0.0,
    -0.058823529411764705, 0.0, 0.0, 0.25062656641604009, 0.24812030075187969,
    0.24060150375939848, 0.22807017543859648, 0.21052631578947367,
    0.18796992481203006, 0.16040100250626566, 0.12781954887218044,
    0.090225563909774431, 0.047619047619047616, 0.0, -0.052631578947368418, 0.0,
    0.25051759834368531, 0.2484472049689441, 0.24223602484472051,
    0.2318840579710145, 0.21739130434782608, 0.19875776397515527,
    0.17598343685300208, 0.14906832298136646, 0.11801242236024845,
    0.082815734989648032, 0.043478260869565216, 0.0, -0.047619047619047616 },

  /* Pooled Parameter (Expression: snorm)
   * Referenced by:
   *   '<S69>/snorm[169]'
   *   '<S69>/Unit Delay1'
   */
  { 1.0, 1.0, 1.5, 2.5, 4.375, 7.875, 14.4375, 26.8125, 50.2734375, 94.9609375,
    180.42578125, 344.44921875, 660.1943359375, 0.0, 1.0, 1.7320508075688772,
    3.0618621784789726, 5.5339859052946636, 10.16658128379447,
    18.903124741692839, 35.469603513959669, 67.03125, 127.40346687426536,
    243.28607380714598, 466.38644692864216, 897.027461585248, 0.0, 0.0,
    0.8660254037844386, 1.9364916731037085, 3.9131189606246322,
    7.685213074469698, 14.944232269507859, 28.960809996010127,
    56.082367403612253, 108.65004161512664, 210.69192030396434,
    409.04797337487776, 795.12986069746626, 0.0, 0.0, 0.0, 0.79056941504209488,
    2.0916500663351889, 4.7062126492541738, 9.9628215130052382,
    20.478385136833914, 41.41957332816817, 82.982839993569982,
    165.28034045942309, 327.9680080977904, 649.22081265302029, 0.0, 0.0, 0.0,
    0.0, 0.739509972887452, 2.2185299186623553, 5.4568620790707172,
    12.348930874776167, 26.736219617835371, 56.375738371688975,
    116.87084953567937, 239.5139682335957, 486.91560948976519, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7015607600201138, 2.3268138086232852, 6.1744654373880836,
    14.830586268334102, 33.69094768709671, 73.915615322315773,
    158.42359886807964, 334.02135244518831, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.671693289381396, 2.4218245962496963, 6.8652274293172546, 17.39793057467611,
    41.320085114855779, 94.117642301250768, 208.29891011946015, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6472598492877496, 2.5068266169601756,
    7.5335249254737544, 20.043185339772048, 49.604352946160631,
    117.05388227149012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6267066542400439, 2.5839777317091466, 8.1825961504123, 22.760038068635609,
    58.526941135745062, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.60904939217552367, 2.65478475211798, 8.8149248398872544,
    25.543251233216804, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.59362791713657326, 2.72034486491732, 9.4324706362690076, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.579979473934679,
    2.7814838439702596, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.56776801212685635 },

  /* Expression: c
   * Referenced by: '<S70>/c[maxdef][maxdef]'
   */
  { 0.0, 4796.2, -4928.7237780179967, -353.03270917862551, 1568.3316055605076,
    481.89595285185783, -391.29468215304178, -1918.905550105218, 683.71875,
    -2751.914884484132, 802.84404356358175, -46.638644692864219,
    -897.027461585248, -29438.5, -1501.1, -555.98830922960963,
    474.44045991040861, -738.01423597380563, 1513.2184543630835,
    496.148511347661, -561.83971392259639, -1015.0908500053819,
    1173.4204494433677, -63.207576091189296, 859.00074408724333,
    397.56493034873313, -3667.9500000000003, 5217.8030578012422,
    1451.9781919849897, -425.56351611715962, 378.37949700003571,
    -561.92179032094839, 585.813904964708, 114.67895676626991,
    546.73836793181977, 970.89922792476875, 760.28956611334615,
    -229.57760566845326, 1168.5974627754365, 3377.75, -7202.4184024360875,
    2373.3641945559048, 460.03234261299497, -243.66853606641544,
    35.71833169046392, -362.8813282582027, 301.31391334453849,
    -390.34880642039639, -383.35502092748504, 514.23173795698926,
    -263.46536505695531, -1071.2143408774834, 3969.0, 4503.0043311382678,
    470.74821096314326, -700.70277222228833, 51.987551093987875,
    70.226232078013382, 16.98574080294998, 20.375735943380676,
    240.25549754701245, -232.4675390409673, -583.93336104629464,
    110.89651920765574, 100.20640573355649, -1831.725, 3660.9859202943885,
    1478.63499552797, -663.57598354483855, -349.19660919745473,
    3.0167112680864894, 41.980830586337255, -66.600176396866644,
    39.131796347108356, 135.70385848247366, -24.792051068913466,
    -18.823528460250156, 145.80923708362209, 1003.40625, 1274.0706075900976,
    1087.9401092201722, -1293.17423238808, -158.24900029305081,
    30.713942273827364, -47.623054217140982, -1.4886976533618239,
    -22.8121222143376, 7.5335249254737544, -82.17705989306539,
    -104.16914118693732, -11.705388227149014, 2187.8999999999996,
    -2699.2368274123305, -196.93350797286885, 1062.82818860168,
    185.23396312164252, 57.422528567709179, -6.7811088694991488,
    4.3366409902279228, 1.3787546393280967, -10.077513153665672,
    -22.911269221154438, -34.140057102953413, 17.558082340723519, 1206.5625,
    576.46875, -947.792009121047, -132.54263465013815, -550.76612412740872,
    197.24679736884357, 80.323160923011869, -40.10922587136281,
    -1.2534133084800878, 5.1769198334919508, -2.9202632273297784,
    -22.037312099718136, 5.1086502466433608, 512.7890625, 1121.1505084935352,
    336.81512900689262, -257.24680398006694, 33.825443023013385,
    -448.08960423838624, -1.739793057467611, 65.541666851621656,
    -23.514197358553233, -6.3950186178429984, -5.1645628790881872,
    -5.44068972983464, -8.489223572642107, -342.80898437499997,
    -1581.3594797464489, 42.138384060792873, 99.168204275653849,
    -70.122509721407624, 125.65654604793681, -28.924059580399042,
    42.0906892135213, 18.819971145948287, -4.7786125538123647,
    -2.1370605016916637, -1.3339527900497614, -0.556296768794052, 1067.792578125,
    -699.57967039296318, -940.81033876221875, 688.73281700535983,
    -215.56257141023613, 95.054159320847774, -65.882349610875536,
    9.9208705892321269, 38.692064716680534, -1.762984967977451,
    1.088137945966928, 2.0299281587713764, 0.39743760848879944, -1320.388671875,
    -269.10823847557441, 318.05194427898653, 843.98705644892641,
    -438.22404854078866, 300.61921720066948, 20.829891011946017,
    58.526941135745062, -23.410776454298027, -10.217300493286722,
    1.8864941272538016, -2.5033354595732336, 0.0 },

  /* Expression: cd
   * Referenced by: '<S70>/cd[maxdef][maxdef]'
   */
  { 0.0, -26.8, -46.938576885116575, 25.71964229922337, -3.3203915431767981,
    4.0666325135177877, 0.0, 24.828722459771768, -20.109375, -25.480693374853075,
    24.3286073807146, 0.0, 0.0, 10.7, 17.9, -11.518137870333033,
    -0.7745966692414834, 20.73953049131055, 12.296340919151518,
    -32.877310992917295, 14.480404998005064, 16.824710221083674,
    -10.865004161512665, -21.069192030396437, 40.904797337487778, 0.0,
    -12.899999999999999, -5.7157676649772942, 2.0784609690826525,
    1.818309654596818, 6.2749501990055663, -5.1768339141795918,
    -6.9739750591036662, -4.0956770273667829, 12.42587199845045,
    -16.596567998713997, 0.0, 0.0, -64.922081265302026, 7.75, -18.98354550656963,
    -0.7745966692414834, -8.2219219164377879, -3.9194028563034955,
    7.3211487315857724, 0.54568620790707179, -1.2348930874776167,
    16.041731770701222, 5.6375738371688975, 0.0, 23.951396823359573, 0.0, -1.75,
    4.4271887242357311, -36.00069443774661, 8.3666002653407556,
    -3.1059418861272987, 0.070156076002011389, 2.3268138086232852,
    -4.3221258061716581, -1.4830586268334103, 3.3690947687096711,
    -14.783123064463155, 0.0, 0.0, -1.5750000000000002, 1.0166581283794469,
    -10.759298304257577, 0.0, 2.8840888942610619, 2.6659308880764323,
    0.87320127619581489, 0.24218245962496965, -1.3730454858634511, 0.0,
    4.1320085114855782, 0.0, 0.0, -7.21875, -3.7806249483385681,
    -8.9665393617047151, 23.910771631212572, -6.0025482869777891,
    0.69804414258698555, 1.0075399340720941, 0.06472598492877496,
    0.75204798508805271, -1.5067049850947509, -2.0043185339772047,
    4.9604352946160635, 0.0, 5.3625000000000007, -7.0939207027919338,
    -11.584323998404052, 26.621900677884089, 2.4697861749552334,
    -2.4697861749552334, -2.1796421366247265, 0.19417795478632488, 0.0,
    1.0335910926836587, -1.63651923008246, 0.0, 0.0, 0.0, 6.703125,
    -28.041183701806126, 20.709786664084085, -5.3472439235670741,
    5.9322345073336411, 1.3730454858634511, -1.0027306467840702,
    0.18801199627201318, 0.1827148176526571, 0.265478475211798,
    -0.88149248398872548, 0.0, 0.0, -12.740346687426538, -10.865004161512665,
    33.193135997427994, -28.187869185844487, -6.7381895374193421,
    1.739793057467611, 0.0, -0.51679554634182934, -0.06090493921755237,
    -0.059362791713657326, 0.0, 0.0, 0.0, 0.0, -21.069192030396437,
    49.584102137826925, -11.687084953567938, -7.3915615322315773,
    -4.1320085114855782, 0.0, -1.63651923008246, -0.265478475211798,
    -0.11872558342731465, -0.0579979473934679, 0.0, 0.0, 0.0,
    -40.904797337487778, 32.796800809779043, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.272034486491732, -0.0579979473934679, 0.0, 66.019433593750009, 0.0, 0.0,
    64.922081265302026, -48.691560948976523, 0.0, 20.829891011946017, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  /* Expression: fm
   * Referenced by: '<S68>/fm'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 },

  /* Expression: fn
   * Referenced by: '<S68>/fn'
   */
  { 0.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S108>/sp[11]'
   *   '<S108>/cp[11]'
   *   '<S108>/Constant'
   *   '<S108>/Constant1'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  /* Expression: [0 0 (1:(maxdef-1))]
   * Referenced by: '<S61>/sp[13]'
   */
  { 0.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  /* Expression: [1 1 (1:(maxdef-1))]
   * Referenced by: '<S61>/cp[13]'
   */
  { 1.0, 1.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  /* Expression: fsw_params.estimation.ic.error_cov
   * Referenced by: '<S2>/Unit Delay2'
   */
  { 0.0027415567780803771, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0027415567780803771,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0027415567780803771, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 2.7415567780803768E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.7415567780803768E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.7415567780803768E-5 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
