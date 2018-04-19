/**
 * @file     TestContants.h
 * @encoding UTF-8
 * @date     15.4.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_TESTCONTANTS_H
#define FIT_IVS_PROJECT2_TESTCONTANTS_H

#include "gtest/gtest.h"

// uvažujeme přesnost na 10 des míst
#define DELTA 0.00000000005
// pro faktoriál komplexních čísel přesnost na 7 des míst
#define DELTA_CF 0.00000005

#define inf  std::numeric_limits<double>::infinity()

#define qNaN  std::numeric_limits<double>::quiet_NaN()

#define doNotCare  std::numeric_limits<double>::quiet_NaN()

#define sNaN  std::numeric_limits<double>::signaling_NaN()

#define T22_EXPECT_NEAR(actual, expect, delta)\
    if((expect) == inf || (expect) == -inf){\
        EXPECT_EQ((actual),(expect));\
    } else { \
        EXPECT_NEAR((actual),(expect),(delta));\
    }\


#define T22_NUMBER_EXPECT_NEAR(actual, expect, delta)\
     T22_EXPECT_NEAR((actual).getReal(), (expect).getReal(), (delta));\
     T22_EXPECT_NEAR((actual).getImaginary(), (expect).getImaginary(), (delta));\

#endif //FIT_IVS_PROJECT2_TESTCONTANTS_H
