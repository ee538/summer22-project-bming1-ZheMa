#include "gtest/gtest.h"
#include "src/lib/trojanmap.h"

// TEST(TrojanMapStudentTest, Test1) {
//   EXPECT_EQ(true, true);
// }

// Phase 1
// Test Autocomplete function
TEST(TrojanMapTest, Autocomplete)
{
  TrojanMap m;
  // Test the simple case
  auto names = m.Autocomplete("Chi");
  std::unordered_set<std::string> gt = {"Chick-fil-A", "Chipotle", "Chinese Street Food"}; // groundtruth for "Ch"
  int success = 0;
  for (auto &n : names)
  {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0)
    {
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  // Test the lower case
  names = m.Autocomplete("chi");
  success = 0;
  for (auto &n : names)
  {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0)
    {
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  // Test the lower and upper case
  names = m.Autocomplete("cHi");
  success = 0;
  for (auto &n : names)
  {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0)
    {
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  // Test the upper case
  names = m.Autocomplete("CHI");
  success = 0;
  for (auto &n : names)
  {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0)
    {
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());

 // Test the non-exist case
  names = m.Autocomplete("aaa");
  success = 0;
  for (auto &n : names)
  {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0)
    {
      success++;
    }
  }
  EXPECT_EQ(success, 0); 
}


// Test FindPosition function
TEST(TrojanMapTest, FindPosition) {
  TrojanMap m;
  
  // Test Chick-fil-A
  auto position = m.GetPosition("Chick-fil-A");
  std::pair<double, double> gt1(34.0167334, -118.2825307); // groundtruth for "Chick-fil-A"
  EXPECT_EQ(position, gt1);
  // Test Ralphs
  position = m.GetPosition("Ralphs");
  std::pair<double, double> gt2(34.0317653, -118.2908339); // groundtruth for "Ralphs"
  EXPECT_EQ(position, gt2);
  // Test Target
  position = m.GetPosition("Target");
  std::pair<double, double> gt3(34.0257016, -118.2843512); // groundtruth for "Target"
  EXPECT_EQ(position, gt3);
  // Test Unknown
  position = m.GetPosition("XXX");
  std::pair<double, double> gt4(-1, -1);
  EXPECT_EQ(position, gt4);
}

// Phase 2
// Test CalculateEditDistance function
TEST(TrojanMapTest, CalculateEditDistance) {
  TrojanMap m;
  EXPECT_EQ(m.CalculateEditDistance("raphs", "raphs1"), 1);
  EXPECT_EQ(m.CalculateEditDistance("raphs", " "), 5);
  EXPECT_EQ(m.CalculateEditDistance("raaphs", "raphs"), 1);
  EXPECT_EQ(m.CalculateEditDistance("horse", "ros"), 3);
  EXPECT_EQ(m.CalculateEditDistance("intention", "execution"), 5);
  EXPECT_EQ(m.CalculateEditDistance("Raaphs", "raphs"), 2);
}

// Test FindClosestName function
TEST(TrojanMapTest, FindClosestName)
{
  TrojanMap m;
  // EXPECT_EQ(m.FindClosestName("Rolphs"), "Ralphs");
  // EXPECT_EQ(m.FindClosestName("Targeety"), "Target");
  EXPECT_EQ(0,0);
}
