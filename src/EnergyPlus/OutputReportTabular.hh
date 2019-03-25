// EnergyPlus, Copyright (c) 1996-2018, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef OutputReportTabular_hh_INCLUDED
#define OutputReportTabular_hh_INCLUDED

// C++ Headers
#include <fstream>
#include <string>

// ObjexxFCL Headers
#include <ObjexxFCL/Array1D.hh>
#include <ObjexxFCL/Array1S.hh>
#include <ObjexxFCL/Array2D.hh>
#include <ObjexxFCL/Array2S.hh>
#include <ObjexxFCL/Array3D.hh>
#include <ObjexxFCL/Optional.hh>

// EnergyPlus Headers
#include <DataGlobals.hh>
#include <EnergyPlus.hh>
#include <OutputProcessor.hh>

namespace EnergyPlus {

namespace OutputReportTabular {

    // Using/Aliasing

    // Data
    // MODULE PARAMETER DEFINITIONS:

    thread_local extern int const MaxHeaderLength;
    thread_local extern int const MaxNoteLength;

    thread_local extern int const aggTypeSumOrAvg;
    thread_local extern int const aggTypeMaximum;
    thread_local extern int const aggTypeMinimum;
    thread_local extern int const aggTypeValueWhenMaxMin;
    thread_local extern int const aggTypeHoursZero;
    thread_local extern int const aggTypeHoursNonZero;
    thread_local extern int const aggTypeHoursPositive;
    thread_local extern int const aggTypeHoursNonPositive;
    thread_local extern int const aggTypeHoursNegative;
    thread_local extern int const aggTypeHoursNonNegative;
    thread_local extern int const aggTypeSumOrAverageHoursShown;
    thread_local extern int const aggTypeMaximumDuringHoursShown;
    thread_local extern int const aggTypeMinimumDuringHoursShown;

    thread_local extern int const tableStyleComma;
    thread_local extern int const tableStyleTab;
    thread_local extern int const tableStyleFixed;
    thread_local extern int const tableStyleHTML;
    thread_local extern int const tableStyleXML;

    thread_local extern int const unitsStyleNone; // no change to any units
    thread_local extern int const unitsStyleJtoKWH;
    thread_local extern int const unitsStyleJtoMJ;
    thread_local extern int const unitsStyleJtoGJ;
    thread_local extern int const unitsStyleInchPound;
    thread_local extern int const unitsStyleNotFound;

    thread_local extern int const stepTypeZone;
    thread_local extern int const stepTypeHVAC;

    thread_local extern int const cSensInst;
    thread_local extern int const cSensDelay;
    thread_local extern int const cSensRA;
    thread_local extern int const cLatent;
    thread_local extern int const cTotal;
    thread_local extern int const cPerc;
    thread_local extern int const cArea;
    thread_local extern int const cPerArea;

    thread_local extern int const rPeople;
    thread_local extern int const rLights;
    thread_local extern int const rEquip;
    thread_local extern int const rRefrig;
    thread_local extern int const rWaterUse;
    thread_local extern int const rHvacLoss;
    thread_local extern int const rPowerGen;
    thread_local extern int const rDOAS;
    thread_local extern int const rInfil;
    thread_local extern int const rZoneVent;
    thread_local extern int const rIntZonMix;
    thread_local extern int const rRoof;
    thread_local extern int const rIntZonCeil;
    thread_local extern int const rOtherRoof;
    thread_local extern int const rExtWall;
    thread_local extern int const rIntZonWall;
    thread_local extern int const rGrdWall;
    thread_local extern int const rOtherWall;
    thread_local extern int const rExtFlr;
    thread_local extern int const rIntZonFlr;
    thread_local extern int const rGrdFlr;
    thread_local extern int const rOtherFlr;
    thread_local extern int const rFeneCond;
    thread_local extern int const rFeneSolr;
    thread_local extern int const rOpqDoor;
    thread_local extern int const rGrdTot;

    // BEPS Report Related Variables
    // From Report:Table:Predefined - BEPS
    thread_local extern int const numResourceTypes;
    thread_local extern int const numSourceTypes;

    // MODULE VARIABLE DECLARATIONS:

    // The Binned table type is different and only references one variable and its structure is very
    // different from the others so it is has its own type.

    // arrays for time binned results

    thread_local extern int OutputTableBinnedCount;
    thread_local extern int BinResultsTableCount;
    thread_local extern int BinResultsIntervalCount;

    thread_local extern int const numNamedMonthly;
    // These reports are detailed/named in routine InitializePredefinedMonthlyTitles

    thread_local extern int MonthlyInputCount;
    thread_local extern int sizeMonthlyInput;
    thread_local extern int MonthlyFieldSetInputCount;
    thread_local extern int sizeMonthlyFieldSetInput;
    thread_local extern int MonthlyTablesCount;
    thread_local extern int MonthlyColumnsCount;
    thread_local extern Array1D_bool IsMonthGathered; // shown as true for any month used

    thread_local extern int TOCEntriesCount;
    thread_local extern int TOCEntriesSize;

    thread_local extern int UnitConvSize;

    thread_local extern bool WriteTabularFiles;

    // Allow up to five output files to be created
    thread_local extern int const maxNumStyles;

    // From Report:Table:Style
    thread_local extern int unitsStyle; // see list of parameters
    thread_local extern int numStyles;
    thread_local extern std::ofstream csv_stream;                   // CSV table stream
    thread_local extern std::ofstream tab_stream;                   // Tab table stream
    thread_local extern std::ofstream fix_stream;                   // Fixed table stream
    thread_local extern std::ofstream htm_stream;                   // HTML table stream
    thread_local extern std::ofstream xml_stream;                   // XML table stream
    thread_local extern Array1D<std::ofstream *> TabularOutputFile; // Table stream array
    thread_local extern Array1D_string del;                         // the delimiter to use
    thread_local extern Array1D_int TableStyle;                     // see list of parameters

    thread_local extern Real64 timeInYear;

    // Flags for predefined tabular reports
    thread_local extern bool displayTabularBEPS;
    thread_local extern bool displayLEEDSummary;
    thread_local extern bool displayTabularCompCosts; // added BTG 5/6/04 for component cost summary
    thread_local extern bool displayTabularVeriSum;   // added JG 2006-06-28 for input verification and summary report
    thread_local extern bool displayComponentSizing;
    thread_local extern bool displaySurfaceShadowing;
    thread_local extern bool displayDemandEndUse;
    thread_local extern bool displayAdaptiveComfort;
    thread_local extern bool displaySourceEnergyEndUseSummary;
    thread_local extern bool displayZoneComponentLoadSummary;
    thread_local extern bool displayAirLoopComponentLoadSummary;
    thread_local extern bool displayFacilityComponentLoadSummary;
    thread_local extern bool displayLifeCycleCostReport;
    thread_local extern bool displayTariffReport;
    thread_local extern bool displayEconomicResultSummary;
    thread_local extern bool displayEioSummary;

    // BEPS Report Related Variables
    // From Report:Table:Predefined - BEPS
    // arrays that hold the meter numbers that are initialized at get input
    thread_local extern Array1D_int meterNumTotalsBEPS;
    thread_local extern Array1D_int meterNumTotalsSource;
    thread_local extern Array1D_bool fuelfactorsused;
    thread_local extern Array1D_bool ffUsed;
    thread_local extern Array1D<Real64> SourceFactors;
    thread_local extern Array1D_bool ffSchedUsed;
    thread_local extern Array1D_int ffSchedIndex;
    thread_local extern Array2D_int meterNumEndUseBEPS;
    thread_local extern Array3D_int meterNumEndUseSubBEPS;
    // arrays that hold the names of the resource and end uses
    thread_local extern Array1D_string resourceTypeNames;
    thread_local extern Array1D_string sourceTypeNames;
    thread_local extern Array1D_string endUseNames;
    // arrays that hold the actual values for the year
    thread_local extern Array1D<Real64> gatherTotalsBEPS;
    thread_local extern Array1D<Real64> gatherTotalsBySourceBEPS;
    thread_local extern Array1D<Real64> gatherTotalsSource;
    thread_local extern Array1D<Real64> gatherTotalsBySource;
    thread_local extern Array2D<Real64> gatherEndUseBEPS;
    thread_local extern Array2D<Real64> gatherEndUseBySourceBEPS;
    thread_local extern Array3D<Real64> gatherEndUseSubBEPS;
    // arrays the hold the demand values
    thread_local extern Array1D<Real64> gatherDemandTotal;
    thread_local extern Array2D<Real64> gatherDemandEndUse;
    thread_local extern Array2D<Real64> gatherDemandIndEndUse;
    thread_local extern Array3D<Real64> gatherDemandEndUseSub;
    thread_local extern Array3D<Real64> gatherDemandIndEndUseSub;
    thread_local extern Array1D_int gatherDemandTimeStamp;
    // to keep track of hours for the BEPS report gathering
    thread_local extern Real64 gatherElapsedTimeBEPS;
    // for normalization of results
    thread_local extern Real64 buildingGrossFloorArea;
    thread_local extern Real64 buildingConditionedFloorArea;
    // keep track if schedules are used in fuel factors
    thread_local extern bool fuelFactorSchedulesUsed;
    // for electic load components on BEPS report
    thread_local extern int meterNumPowerFuelFireGen;
    thread_local extern Real64 gatherPowerFuelFireGen;
    thread_local extern int meterNumPowerPV;
    thread_local extern Real64 gatherPowerPV;
    thread_local extern int meterNumPowerWind;
    thread_local extern Real64 gatherPowerWind;
    thread_local extern Real64 OverallNetEnergyFromStorage;
    thread_local extern int meterNumPowerHTGeothermal;
    thread_local extern Real64 gatherPowerHTGeothermal;
    thread_local extern int meterNumElecProduced;
    thread_local extern Real64 gatherElecProduced;
    thread_local extern int meterNumElecPurchased;
    thread_local extern Real64 gatherElecPurchased;
    thread_local extern int meterNumElecSurplusSold;
    thread_local extern Real64 gatherElecSurplusSold;
    thread_local extern int meterNumElecStorage;
    thread_local extern Real64 gatherElecStorage;
    thread_local extern int meterNumPowerConversion;
    thread_local extern Real64 gatherPowerConversion;
    // for on site thermal source components on BEPS report
    thread_local extern int meterNumWaterHeatRecovery;
    thread_local extern Real64 gatherWaterHeatRecovery;
    thread_local extern int meterNumAirHeatRecoveryCool;
    thread_local extern Real64 gatherAirHeatRecoveryCool;
    thread_local extern int meterNumAirHeatRecoveryHeat;
    thread_local extern Real64 gatherAirHeatRecoveryHeat;
    thread_local extern int meterNumHeatHTGeothermal;
    thread_local extern Real64 gatherHeatHTGeothermal;
    thread_local extern int meterNumHeatSolarWater;
    thread_local extern Real64 gatherHeatSolarWater;
    thread_local extern int meterNumHeatSolarAir;
    thread_local extern Real64 gatherHeatSolarAir;
    // for on site water components on BEPS report
    thread_local extern int meterNumRainWater;
    thread_local extern Real64 gatherRainWater;
    thread_local extern int meterNumCondensate;
    thread_local extern Real64 gatherCondensate;
    thread_local extern int meterNumGroundwater;
    thread_local extern Real64 gatherWellwater;
    thread_local extern int meterNumMains;
    thread_local extern Real64 gatherMains;
    thread_local extern int meterNumWaterEndUseTotal;
    thread_local extern Real64 gatherWaterEndUseTotal;
    // for source energy conversion factors on BEPS report
    thread_local extern Real64 sourceFactorElectric;
    thread_local extern Real64 sourceFactorNaturalGas;
    thread_local extern Real64 efficiencyDistrictCooling;
    thread_local extern Real64 efficiencyDistrictHeating;
    thread_local extern Real64 sourceFactorSteam;
    thread_local extern Real64 sourceFactorGasoline;
    thread_local extern Real64 sourceFactorDiesel;
    thread_local extern Real64 sourceFactorCoal;
    thread_local extern Real64 sourceFactorFuelOil1;
    thread_local extern Real64 sourceFactorFuelOil2;
    thread_local extern Real64 sourceFactorPropane;
    thread_local extern Real64 sourceFactorOtherFuel1;
    thread_local extern Real64 sourceFactorOtherFuel2;

    thread_local extern Array1D_int td;
    //(1)   Current year
    //(2)   Current month
    //(3)   Current day
    //(4)   Time difference with respect to UTC in minutes (0-59)
    //(5)   Hour of the day (0-23)
    //(6)   Minutes (0-59)
    //(7)   Seconds (0-59)
    //(8)   Milliseconds (0-999)

    // Design day name storage
    thread_local extern Array1D_string DesignDayName;
    thread_local extern int DesignDayCount;

    // arrays related to pulse and load component reporting
    thread_local extern Array2D<Real64> radiantPulseUsed;
    thread_local extern Array2D_int radiantPulseTimestep;
    thread_local extern Array2D<Real64> radiantPulseReceived;
    thread_local extern Array3D<Real64> loadConvectedNormal;
    thread_local extern Array3D<Real64> loadConvectedWithPulse;
    thread_local extern Array3D<Real64> netSurfRadSeq;
    thread_local extern Array2D<Real64> decayCurveCool;
    thread_local extern Array2D<Real64> decayCurveHeat;
    thread_local extern Array3D<Real64> ITABSFseq; // used for determining the radiant fraction on each surface
    thread_local extern Array3D<Real64> TMULTseq;  // used for determining the radiant fraction on each surface

    thread_local extern Array3D<Real64> peopleInstantSeq;
    thread_local extern Array3D<Real64> peopleLatentSeq;
    thread_local extern Array3D<Real64> peopleRadSeq;
    thread_local extern Array3D<Real64> peopleDelaySeq;

    thread_local extern Array3D<Real64> lightInstantSeq;
    thread_local extern Array3D<Real64> lightRetAirSeq;
    thread_local extern Array3D<Real64> lightLWRadSeq; // long wave thermal radiation
    thread_local extern Array3D<Real64> lightSWRadSeq; // short wave visible radiation
    thread_local extern Array3D<Real64> lightDelaySeq;

    thread_local extern Array3D<Real64> equipInstantSeq;
    thread_local extern Array3D<Real64> equipLatentSeq;
    thread_local extern Array3D<Real64> equipRadSeq;
    thread_local extern Array3D<Real64> equipDelaySeq;

    thread_local extern Array3D<Real64> refrigInstantSeq;
    thread_local extern Array3D<Real64> refrigRetAirSeq;
    thread_local extern Array3D<Real64> refrigLatentSeq;

    thread_local extern Array3D<Real64> waterUseInstantSeq;
    thread_local extern Array3D<Real64> waterUseLatentSeq;

    thread_local extern Array3D<Real64> hvacLossInstantSeq;
    thread_local extern Array3D<Real64> hvacLossRadSeq;
    thread_local extern Array3D<Real64> hvacLossDelaySeq;

    thread_local extern Array3D<Real64> powerGenInstantSeq;
    thread_local extern Array3D<Real64> powerGenRadSeq;
    thread_local extern Array3D<Real64> powerGenDelaySeq;

    thread_local extern Array3D<Real64> infilInstantSeq;
    thread_local extern Array3D<Real64> infilLatentSeq;

    thread_local extern Array3D<Real64> zoneVentInstantSeq;
    thread_local extern Array3D<Real64> zoneVentLatentSeq;

    thread_local extern Array3D<Real64> interZoneMixInstantSeq;
    thread_local extern Array3D<Real64> interZoneMixLatentSeq;

    thread_local extern Array3D<Real64> feneCondInstantSeq;
    // REAL(r64), DIMENSION(:,:,:),ALLOCATABLE,PUBLIC  :: feneSolarInstantSeq
    thread_local extern Array3D<Real64> feneSolarRadSeq;
    thread_local extern Array3D<Real64> feneSolarDelaySeq;

    thread_local extern Array3D<Real64> surfDelaySeq;

    thread_local extern int maxUniqueKeyCount;

    // for the XML report must keep track fo the active sub-table name and report set by other routines
    thread_local extern std::string activeSubTableName;
    thread_local extern std::string activeReportNameNoSpace;
    thread_local extern std::string activeReportName;
    thread_local extern std::string activeForName;
    thread_local extern std::string prevReportName;

    // SUBROUTINE SPECIFICATIONS FOR MODULE PrimaryPlantLoops
    // PRIVATE      DateToStr

    // Types

    struct OutputTableBinnedType
    {
        // Members
        std::string keyValue;   // the key value (usually an asterisk to indicate all variables
        std::string varOrMeter; // the name of the variable or meter
        Real64 intervalStart;   // The lowest value for the intervals being binned into.
        Real64 intervalSize;    // The size of the bins starting with Interval start.
        int intervalCount;      // The number of bins used. The number of hours below the start of
        // the lowest bin and above the value of the last bin are also shown.
        int resIndex; // result index - pointer to BinResults array
        int numTables;
        int typeOfVar;                     // 0=not found, 1=integer, 2=real, 3=meter
        OutputProcessor::StoreType avgSum; // Variable  is Averaged=1 or Summed=2
        int stepType;                      // Variable time step is Zone=1 or HVAC=2
        OutputProcessor::Unit units;       // the units enumeration
        std::string ScheduleName;          // the name of the schedule
        int scheduleIndex;                 // index to the schedule specified - if no schedule use zero

        // Default Constructor
        OutputTableBinnedType()
            : intervalStart(0.0), intervalSize(0.0), intervalCount(0), resIndex(0), numTables(0), typeOfVar(0),
              avgSum(OutputProcessor::StoreType::Averaged), stepType(0), scheduleIndex(0)
        {
        }
    };

    struct BinResultsType
    {
        // Members
        Array1D<Real64> mnth; // monthly bins
        Array1D<Real64> hrly; // hourly bins

        // Default Constructor
        BinResultsType() : mnth(12, 0.0), hrly(24, 0.0)
        {
        }
    };

    struct BinObjVarIDType
    {
        // Members
        std::string namesOfObj; // name of the object
        int varMeterNum;        // variable or meter number

        // Default Constructor
        BinObjVarIDType() : varMeterNum(0)
        {
        }
    };

    struct BinStatisticsType
    {
        // Members
        Real64 sum;     // sum of the variable
        Real64 sum2;    // sum of the variable squared
        int n;          // number of items in sum
        Real64 minimum; // minimum value
        Real64 maximum; // maximum value

        // Default Constructor
        BinStatisticsType() : sum(0.0), sum2(0.0), n(0), minimum(0.0), maximum(0.0)
        {
        }
    };

    struct NamedMonthlyType
    {
        // Members
        std::string title; // report title
        bool show;         // if report should be shown

        // Default Constructor
        NamedMonthlyType() : show(false)
        {
        }
    };

    struct MonthlyInputType
    {
        // Members
        std::string name;  // identifier
        int numFieldSet;   // number of monthly field sets
        int firstFieldSet; // pointer to the first field set
        int numTables;     // number of tables
        int firstTable;    // pointer to the first table
        int showDigits;    // the number of digits to be shown

        // Default Constructor
        MonthlyInputType() : numFieldSet(0), firstFieldSet(0), numTables(0), firstTable(0), showDigits(0)
        {
        }
    };

    struct MonthlyFieldSetInputType
    {
        // Members
        std::string variMeter;                // the name of the variable or meter
        std::string colHead;                  // the column header to use instead of the variable name (only for predefined)
        int aggregate;                        // the type of aggregation for the variable (see aggType parameters)
        OutputProcessor::Unit varUnits;       // Units enumeration
        std::string variMeterUpper;           // the name of the variable or meter uppercased
        int typeOfVar;                        // 0=not found, 1=integer, 2=real, 3=meter
        int keyCount;                         // noel
        OutputProcessor::StoreType varAvgSum; // Variable  is Averaged=1 or Summed=2
        int varStepType;                      // Variable time step is Zone=1 or HVAC=2
        Array1D_string NamesOfKeys;           // keyNames !noel
        Array1D_int IndexesForKeyVar;         // keyVarIndexes !noel

        // Default Constructor
        MonthlyFieldSetInputType()
            : aggregate(0), varUnits(OutputProcessor::Unit::None), typeOfVar(0), keyCount(0), varAvgSum(OutputProcessor::StoreType::Averaged),
              varStepType(1)
        {
        }
    };

    struct MonthlyTablesType
    {
        // Members
        std::string keyValue; // the key value - the object names that result in the variable
        int firstColumn;      // pointer to the monthly column array for the first item
        int numColumns;       // number of columns for the table

        // Default Constructor
        MonthlyTablesType() : firstColumn(0), numColumns(0)
        {
        }
    };

    struct MonthlyColumnsType
    {
        // Members
        std::string varName;               // name of variable
        std::string colHead;               // column header (not used for user defined monthly)
        int varNum;                        // variable or meter number
        int typeOfVar;                     // 0=not found, 1=integer, 2=real, 3=meter
        OutputProcessor::StoreType avgSum; // Variable  is Averaged=1 or Summed=2
        int stepType;                      // Variable time step is Zone=1 or HVAC=2
        OutputProcessor::Unit units;       // the units string, may be blank
        int aggType;                       // index to the type of aggregation (see list of parameters)
        Array1D<Real64> reslt;             // monthly results
        Array1D<Real64> duration;          // the time during which results are summed for use in averages
        Array1D_int timeStamp;             // encoded timestamp of max or min
        Real64 aggForStep;                 // holds the aggregation for the HVAC time steps when smaller than
        // the zone timestep

        // Default Constructor
        MonthlyColumnsType()
            : varNum(0), typeOfVar(0), avgSum(OutputProcessor::StoreType::Averaged), stepType(0), units(OutputProcessor::Unit::None), aggType(0),
              reslt(12, 0.0), duration(12, 0.0), timeStamp(12, 0), aggForStep(0.0)
        {
        }
    };

    struct TOCEntriesType
    {
        // Members
        std::string reportName;  // the name of the individual report
        std::string sectionName; // the name of the section containing individual reports
        bool isWritten;          // flag if the entry has been written to TOC

        // Default Constructor
        TOCEntriesType() : isWritten(false)
        {
        }
    };

    struct UnitConvType
    {
        // Members
        std::string siName; // the name abbreviation or symbol of the SI units
        std::string ipName; // the name abbreviation or symbol of the IP units
        Real64 mult;        // the multiplier used to convert from SI to IP in IP = (SI * mult) + offset
        Real64 offset;      // the offset used to convert from SI to IP in IP = (SI * mult) + offset
        std::string hint;   // the string used when multiple SI units match
        bool several;       // several different options for the SI unit to be converted into IP
        bool is_default;    // if part of a set of "several" this should be used as default

        // Default Constructor
        UnitConvType() : mult(1.0), offset(0.0), several(false), is_default(false)
        {
        }
    };

    struct CompLoadTablesType
    {
        // members
        int desDayNum;             // design day number
        int timeStepMax;           // times step of the day that the maximum occurs
        Array2D<Real64> cells;     // main component table results (column, row)
        Array2D_bool cellUsed;     // flag if the cell is used for the table of results (column, row)
        std::string peakDateHrMin; // string containing peak timestamp
        Real64 outsideDryBulb;     // outside dry bulb temperature at peak
        Real64 outsideWebBulb;     // outside web bulb temperature at peak
        Real64 outsideHumRatio;    // outside humidity ratio at peak
        Real64 zoneDryBulb;        // zone dry bulb temperature at peak
        Real64 zoneRelHum;         // zone relative humidity at peak
        Real64 zoneHumRatio;       // zone humidity ratio at peak

        Real64 supAirTemp;     // supply air temperature
        Real64 mixAirTemp;     // mixed air temperature
        Real64 mainFanAirFlow; // main fan air flow
        Real64 outsideAirFlow; // outside air flow
        Real64 designPeakLoad; // design peak load
        Real64 diffDesignPeak; // difference between Design and Peak Load

        Real64 peakDesSensLoad;    // peak design sensible load
        Real64 estInstDelSensLoad; // estimated instant plus delayed sensible load
        Real64 diffPeakEst;        // difference between the peak design sensible load and the estimated instant plus delayed sensible load
        Array1D_int zoneIndices;   // the zone numbers covered by the report

        Real64 outsideAirRatio;   // outside Air
        Real64 floorArea;         // floor area
        Real64 airflowPerFlrArea; // airflow per floor area
        Real64 airflowPerTotCap;  // airflow per total capacity
        Real64 areaPerTotCap;     // area per total capacity
        Real64 totCapPerArea;     // total capacity per area
        Real64 chlPumpPerFlow;    // chiller pump power per flow
        Real64 cndPumpPerFlow;    // condenser pump power per flow
        Real64 numPeople;         // number of people

        // default constructor
        CompLoadTablesType()
            : desDayNum(0), timeStepMax(0), outsideDryBulb(0.), outsideWebBulb(0.), outsideHumRatio(0.), zoneDryBulb(0.), zoneRelHum(0.),
              supAirTemp(0.), mixAirTemp(0.), mainFanAirFlow(0.), outsideAirFlow(0.), designPeakLoad(0.), diffDesignPeak(0.), peakDesSensLoad(0.),
              estInstDelSensLoad(0.), diffPeakEst(0.), outsideAirRatio(0.), floorArea(0.), airflowPerFlrArea(0.), airflowPerTotCap(0.),
              areaPerTotCap(0.), totCapPerArea(0.), chlPumpPerFlow(0.), cndPumpPerFlow(0.), numPeople(0.)

        {
        }
    };

    struct ZompComponentAreasType
    {
        // members
        Real64 floor;
        Real64 roof;
        Real64 ceiling;
        Real64 extWall;
        Real64 intZoneWall;
        Real64 grndCntWall;
        Real64 extFloor;
        Real64 intZoneFloor;
        Real64 grndCntFloor;
        Real64 fenestration;
        Real64 door;

        // default constructor
        ZompComponentAreasType()
            : floor(0.), roof(0.), ceiling(0.), extWall(0.), intZoneWall(0.), grndCntWall(0.), extFloor(0.), intZoneFloor(0.), grndCntFloor(0.),
              fenestration(0.), door(0.)
        {
        }
    };

    // Object Data
    thread_local extern Array1D<OutputTableBinnedType> OutputTableBinned;
    thread_local extern Array2D<BinResultsType> BinResults;      // table number, number of intervals
    thread_local extern Array1D<BinResultsType> BinResultsBelow; // time below the lowest defined bin
    thread_local extern Array1D<BinResultsType> BinResultsAbove; // time above the highest defined bin
    thread_local extern Array1D<BinObjVarIDType> BinObjVarID;
    thread_local extern Array1D<BinStatisticsType> BinStatistics;
    thread_local extern Array1D<NamedMonthlyType> namedMonthly; // for predefined monthly report titles
    thread_local extern Array1D<MonthlyFieldSetInputType> MonthlyFieldSetInput;
    thread_local extern Array1D<MonthlyInputType> MonthlyInput;
    thread_local extern Array1D<MonthlyTablesType> MonthlyTables;
    thread_local extern Array1D<MonthlyColumnsType> MonthlyColumns;
    thread_local extern Array1D<TOCEntriesType> TOCEntries;
    thread_local extern Array1D<UnitConvType> UnitConv;

    // Functions
    void clear_state();

    void UpdateTabularReports(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    //======================================================================================================================
    //======================================================================================================================

    //    GET INPUT ROUTINES

    //======================================================================================================================
    //======================================================================================================================

    void GetInputTabularMonthly();

    int AddMonthlyReport(std::string const &inReportName, int const inNumDigitsShown);

    void AddMonthlyFieldSetInput(int const inMonthReport, std::string const &inVariMeter, std::string const &inColHead, int const inAggregate);

    void InitializeTabularMonthly();

    bool isInvalidAggregationOrder();

    void GetInputTabularTimeBins();

    bool warningAboutKeyNotFound(int foundIndex, int inObjIndex, std::string const &moduleName);

    void GetInputTabularStyle();

    int SetUnitsStyleFromString(std::string const &unitStringIn);

    void GetInputOutputTableSummaryReports();

    bool isCompLoadRepReq();

    bool hasSizingPeriodsDays();

    void InitializePredefinedMonthlyTitles();

    void CreatePredefinedMonthlyReports();

    void GetInputFuelAndPollutionFactors();

    //======================================================================================================================
    //======================================================================================================================

    //    OTHER INITIALIZATION ROUTINES

    //======================================================================================================================
    //======================================================================================================================

    void OpenOutputTabularFile();

    void CloseOutputTabularFile();

    void WriteTableOfContents();

    //======================================================================================================================
    //======================================================================================================================

    //    GATHER DATA EACH TIME STEP ROUTINES

    //======================================================================================================================
    //======================================================================================================================

    void GatherBinResultsForTimestep(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    void GatherMonthlyResultsForTimestep(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    void GatherBEPSResultsForTimestep(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    void GatherSourceEnergyEndUseResultsForTimestep(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    void GatherPeakDemandForTimestep(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    void GatherHeatGainReport(int const IndexTypeKey); // What kind of data to update (Zone, HVAC)

    //======================================================================================================================
    //======================================================================================================================

    //    WRITE OUTPUT FILE ROUTINES

    //======================================================================================================================
    //======================================================================================================================

    void WriteTabularReports();

    void FillWeatherPredefinedEntries();

    std::string GetColumnUsingTabs(std::string const &inString, // Input String
                                   int const colNum             // Column number
    );

    void FillRemainingPredefinedEntries();

    void WriteMonthlyTables();

    void WriteTimeBinTables();

    void WriteBEPSTable();

    std::string ResourceWarningMessage(std::string resource);

    Real64 WaterConversionFunct(Real64 WaterTotal, Real64 ConversionFactor);

    void WriteSourceEnergyEndUseSummary();

    void WriteDemandEndUseSummary();

    void WriteCompCostTable();

    void WriteVeriSumTable();

    void WriteAdaptiveComfortTable();

    void WritePredefinedTables();

    void WriteComponentSizing();

    void WriteSurfaceShadowing();

    void WriteEioTables();

    int unitsFromHeading(std::string &heading);

    std::vector<std::string> splitCommaString(std::string const &inputString);

    void AddTOCLoadComponentTableSummaries();

    void AllocateLoadComponentArrays();

    void DeallocateLoadComponentArrays();

    void ComputeLoadComponentDecayCurve();

    void GatherComponentLoadsSurface();

    void GatherComponentLoadsHVAC();

    void WriteLoadComponentSummaryTables();

    void GetDelaySequences(int const &desDaySelected,
                           bool const &isCooling,
                           int const &zoneIndex,
                           Array1D<Real64> &peopleDelaySeq,
                           Array1D<Real64> &equipDelaySeq,
                           Array1D<Real64> &hvacLossDelaySeq,
                           Array1D<Real64> &powerGenDelaySeq,
                           Array1D<Real64> &lightDelaySeq,
                           Array1D<Real64> &feneSolarDelaySeq,
                           Array3D<Real64> &feneCondInstantSeq,
                           Array2D<Real64> &surfDelaySeq);

    Real64 MovingAvgAtMaxTime(Array1S<Real64> const &dataSeq, int const &numTimeSteps, int const &maxTimeStep);

    void ComputeTableBodyUsingMovingAvg(Array2D<Real64> &resultCells,
                                        Array2D_bool &resultCellsUsed,
                                        int const &desDaySelected,
                                        int const &timeOfMax,
                                        int const &zoneIndex,
                                        Array1D<Real64> const &peopleDelaySeq,
                                        Array1D<Real64> const &equipDelaySeq,
                                        Array1D<Real64> const &hvacLossDelaySeq,
                                        Array1D<Real64> const &powerGenDelaySeq,
                                        Array1D<Real64> const &lightDelaySeq,
                                        Array1D<Real64> const &feneSolarDelaySeq,
                                        Array3D<Real64> const &feneCondInstantSeqLoc,
                                        Array2D<Real64> const &surfDelaySeq);

    void CollectPeakZoneConditions(
        CompLoadTablesType &compLoad, int const &desDaySelected, int const &timeOfMax, int const &zoneIndex, bool const &isCooling);

    void ComputeEngineeringChecks(CompLoadTablesType &compLoad);

    void GetZoneComponentAreas(Array1D<ZompComponentAreasType> &areas);

    void AddAreaColumnForZone(int const &zoneNum, Array1D<ZompComponentAreasType> const &compAreas, CompLoadTablesType &compLoadTotal);

    void CombineLoadCompResults(CompLoadTablesType &compLoadTotal, CompLoadTablesType const &compLoadPartial, Real64 const &multiplier);

    void AddTotalRowsForLoadSummary(CompLoadTablesType &compLoadTotal);

    void ComputePeakDifference(CompLoadTablesType &compLoad);

    void LoadSummaryUnitConversion(CompLoadTablesType &compLoadTotal);

    void CreateListOfZonesForAirLoop(CompLoadTablesType &compLoad, Array1D_int const &zoneToAirLoop, int const &curAirLoop);

    void OutputCompLoadSummary(int const &kind, // zone=1, airloop=2, facility=3
                               CompLoadTablesType const &compLoadCool,
                               CompLoadTablesType const &compLoadHeat,
                               int const &zoneOrAirLoopIndex);

    void WriteReportHeaders(std::string const &reportName, std::string const &objectName, OutputProcessor::StoreType const averageOrSum);

    void WriteSubtitle(std::string const &subtitle);

    void WriteTextLine(std::string const &lineOfText, Optional_bool_const isBold = _);

    void WriteTable(Array2S_string const body, // row,column
                    Array1S_string const rowLabels,
                    Array1S_string const columnLabels,
                    Array1S_int widthColumn,
                    Optional_bool_const transposeXML = _,
                    Optional_string_const footnoteText = _);

    std::string MakeAnchorName(std::string const &reportString, std::string const &objectString);

    std::string InsertCurrencySymbol(std::string const &inString, // Input String
                                     bool const isHTML            // True if an HTML string
    );

    std::string ConvertToElementTag(std::string const &inString); // Input String

    std::string ConvertUnicodeToUTF8(unsigned long const codepoint);

    std::string ConvertToEscaped(std::string const &inString); // Input String

    void DetermineBuildingFloorArea();

    //======================================================================================================================
    //======================================================================================================================

    //    ROUTINES TO RESET GATHERED VALUES TO ZERO

    //======================================================================================================================
    //======================================================================================================================

    void ResetTabularReports();

    void ResetMonthlyGathering();

    void ResetBinGathering();

    void ResetBEPSGathering();

    void ResetSourceEnergyEndUseGathering();

    void ResetPeakDemandGathering();

    void ResetHeatGainGathering();

    void ResetRemainingPredefinedEntries();

    void ResetAdaptiveComfort();

    //======================================================================================================================
    //======================================================================================================================

    //    ROUTINES RELATED TO IF VALUE IS IN A RANGE

    //======================================================================================================================
    //======================================================================================================================

    bool isInTriangle(
        Real64 const qx, Real64 const qy, Real64 const x1, Real64 const y1, Real64 const x2, Real64 const y2, Real64 const x3, Real64 const y3);

    bool isInQuadrilateral(Real64 const qx,
                           Real64 const qy,
                           Real64 const ax,
                           Real64 const ay,
                           Real64 const bx,
                           Real64 const by,
                           Real64 const cx,
                           Real64 const cy,
                           Real64 const dx,
                           Real64 const dy);

    //======================================================================================================================
    //======================================================================================================================

    //    SUPPORT ROUTINES

    //======================================================================================================================
    //======================================================================================================================

    std::string RealToStr(Real64 const RealIn, int const numDigits);

    std::string IntToStr(int const intIn);

    Real64 StrToReal(std::string const &stringIn);

    std::string DateToString(int const codedDate); // word containing encoded month, day, hour, minute

    bool isNumber(std::string const &s);

    int digitsAferDecimal(std::string s);

    void AddTOCEntry(std::string const &nameSection, std::string const &nameReport);

    void SetupUnitConversions();

    std::string GetUnitSubString(std::string const &inString); // Input String

    void LookupSItoIP(std::string const &stringInWithSI, int &unitConvIndex, std::string &stringOutWithIP);

    void LookupJtokWH(std::string const &stringInWithJ, int &unitConvIndex, std::string &stringOutWithKWH);

    Real64 ConvertIP(int const unitConvIndex, Real64 const SIvalue);

    Real64 ConvertIPdelta(int const unitConvIndex, Real64 const SIvalue);

    void GetUnitConversion(int const unitConvIndex, Real64 &multiplier, Real64 &offset, std::string &IPunit);

    Real64 getSpecificUnitMultiplier(std::string const &SIunit, std::string const &IPunit);

    Real64 getSpecificUnitDivider(std::string const &SIunit, std::string const &IPunit);

    Real64 getSpecificUnitIndex(std::string const &SIunit, std::string const &IPunit);

} // namespace OutputReportTabular

} // namespace EnergyPlus

#endif
