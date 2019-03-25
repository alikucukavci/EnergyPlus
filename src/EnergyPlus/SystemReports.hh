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

#ifndef SystemReports_hh_INCLUDED
#define SystemReports_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/Array1D.hh>

// EnergyPlus Headers
#include <EnergyPlus.hh>

namespace EnergyPlus {

namespace SystemReports {

    // Data
    // MODULE PARAMETER DEFINITIONS:
    thread_local extern int const NoHeatNoCool;
    thread_local extern int const CoolingOnly;
    thread_local extern int const HeatingOnly;
    thread_local extern int const HeatAndCool;
    thread_local extern int const MaxSetBackCount;

    // DERIVED TYPE DEFINITIONS:

    // MODULE VARIABLE DECLARATIONS:
    // Ventilation Report Variables
    thread_local extern Array1D<Real64> MaxCoolingLoadMetByVent;
    thread_local extern Array1D<Real64> MaxCoolingLoadAddedByVent;
    thread_local extern Array1D<Real64> MaxOvercoolingByVent;
    thread_local extern Array1D<Real64> MaxHeatingLoadMetByVent;
    thread_local extern Array1D<Real64> MaxHeatingLoadAddedByVent;
    thread_local extern Array1D<Real64> MaxOverheatingByVent;
    thread_local extern Array1D<Real64> MaxNoLoadHeatingByVent;
    thread_local extern Array1D<Real64> MaxNoLoadCoolingByVent;

    thread_local extern Array1D<Real64> RemMaxCoolingLoadMetByVent;
    thread_local extern Array1D<Real64> RemMaxCoolingLoadAddedByVent;
    thread_local extern Array1D<Real64> RemMaxOvercoolingByVent;
    thread_local extern Array1D<Real64> RemMaxHeatingLoadMetByVent;
    thread_local extern Array1D<Real64> RemMaxHeatingLoadAddedByVent;
    thread_local extern Array1D<Real64> RemMaxOverheatingByVent;
    thread_local extern Array1D<Real64> RemMaxNoLoadHeatingByVent;
    thread_local extern Array1D<Real64> RemMaxNoLoadCoolingByVent;

    thread_local extern Array1D<Real64> LastMaxCoolingLoadMetByVent;
    thread_local extern Array1D<Real64> LastMaxCoolingLoadAddedByVent;
    thread_local extern Array1D<Real64> LastMaxOvercoolingByVent;
    thread_local extern Array1D<Real64> LastMaxHeatingLoadMetByVent;
    thread_local extern Array1D<Real64> LastMaxHeatingLoadAddedByVent;
    thread_local extern Array1D<Real64> LastMaxOverheatingByVent;
    thread_local extern Array1D<Real64> LastMaxNoLoadHeatingByVent;
    thread_local extern Array1D<Real64> LastMaxNoLoadCoolingByVent;

    thread_local extern Array1D<Real64> SysTotZoneLoadHTNG;
    thread_local extern Array1D<Real64> SysTotZoneLoadCLNG;
    thread_local extern Array1D<Real64> SysOALoadHTNG;
    thread_local extern Array1D<Real64> SysOALoadCLNG;
    thread_local extern Array1D<Real64> SysTotHTNG;
    thread_local extern Array1D<Real64> SysTotCLNG;

    thread_local extern Array1D<Real64> SysTotH2OHOT;
    thread_local extern Array1D<Real64> SysTotH2OCOLD;
    thread_local extern Array1D<Real64> SysTotElec;
    thread_local extern Array1D<Real64> SysTotGas;
    thread_local extern Array1D<Real64> SysTotSteam;

    thread_local extern Array1D<Real64> SysHumidHTNG;
    thread_local extern Array1D<Real64> SysHumidElec;
    thread_local extern Array1D<Real64> SysHumidGas;
    thread_local extern Array1D<Real64> SysEvapCLNG;
    thread_local extern Array1D<Real64> SysEvapElec;
    thread_local extern Array1D<Real64> SysHeatExHTNG;
    thread_local extern Array1D<Real64> SysHeatExCLNG;
    thread_local extern Array1D<Real64> DesDehumidCLNG;
    thread_local extern Array1D<Real64> DesDehumidElec;
    thread_local extern Array1D<Real64> SysSolarCollectHeating;
    thread_local extern Array1D<Real64> SysSolarCollectCooling;
    thread_local extern Array1D<Real64> SysUserDefinedTerminalHeating;
    thread_local extern Array1D<Real64> SysUserDefinedTerminalCooling;

    thread_local extern Array1D<Real64> SysFANCompHTNG;
    thread_local extern Array1D<Real64> SysFANCompElec;
    thread_local extern Array1D<Real64> SysCCCompCLNG;
    thread_local extern Array1D<Real64> SysCCCompH2OCOLD;
    thread_local extern Array1D<Real64> SysCCCompElec;
    thread_local extern Array1D<Real64> SysHCCompH2OHOT;
    thread_local extern Array1D<Real64> SysHCCompElec;
    thread_local extern Array1D<Real64> SysHCCompElecRes;
    thread_local extern Array1D<Real64> SysHCCompHTNG;
    thread_local extern Array1D<Real64> SysHCCompGas;
    thread_local extern Array1D<Real64> SysHCCompSteam;
    thread_local extern Array1D<Real64> SysDomesticH20;

    thread_local extern Array1D<Real64> ZoneOAMassFlow;       // zone mech vent mass flow rate {kg/s}
    thread_local extern Array1D<Real64> ZoneOAMass;           // zone mech vent total mass for time {kg}
    thread_local extern Array1D<Real64> ZoneOAVolFlowStdRho;  // zone mech vent volume flow rate at standard density {m3/s}
    thread_local extern Array1D<Real64> ZoneOAVolStdRho;      // zone mech vent total volume OA at standard density {m3/s}
    thread_local extern Array1D<Real64> ZoneOAVolFlowCrntRho; // zone mech vent volume flow rate at current density {m3/s}
    thread_local extern Array1D<Real64> ZoneOAVolCrntRho;     // zone mech vent total volume OA at current density {m3/s}
    thread_local extern Array1D<Real64> ZoneMechACH;          // zone mech vent air changes per hour {ACH}

    thread_local extern bool AirLoopLoadsReportEnabled;
    thread_local extern bool VentLoadsReportEnabled;
    thread_local extern bool VentEnergyReportEnabled;
    thread_local extern bool VentReportStructureCreated;
    thread_local extern int TotalLoopConnects; // Total number of loop connections
    thread_local extern int MaxLoopArraySize;
    thread_local extern int MaxCompArraySize;
    thread_local extern int DBFlag;

    thread_local extern Array1D_int SetBackCounter;
    thread_local extern Array1D_int HeatCoolFlag;
    thread_local extern Array1D_int FirstHeatCoolFlag;
    thread_local extern Array1D_int FirstHeatCoolHour;
    thread_local extern Array1D_int LastHeatCoolFlag;
    thread_local extern Array1D_int LastHeatCoolHour;
    thread_local extern Array1D_bool AirLoopCalcDone;
    thread_local extern Array1D_bool NoLoadFlag;
    thread_local extern Array1D_bool UnmetLoadFlag;

    // SUBROUTINE SPECIFICATIONS FOR MODULE SystemReports

    // Reporting Initialization

    // Reporting routines for module

    // Types

    struct Energy
    {
        // Members
        Real64 TotDemand;
        Real64 Elec;
        Real64 Gas;
        Real64 Purch;
        Real64 Other;

        // Default Constructor
        Energy() : TotDemand(0.0), Elec(0.0), Gas(0.0), Purch(0.0), Other(0.0)
        {
        }
    };

    struct CoilType
    {
        // Members
        Energy DecreasedCC; // LoadMetByVent
        Energy DecreasedHC; // LoadMetByVent
        Energy IncreasedCC; // LoadIncreasedVent
        Energy IncreasedHC; // LoadAddedByVent
        Energy ReducedByCC; // LoadAddedByVent
        Energy ReducedByHC; // LoadAddedByVent

        // Default Constructor
        CoilType()
        {
        }
    };

    struct SummarizeLoads
    {
        // Members
        CoilType Load;             // LoadMetByVent
        CoilType NoLoad;           // LoadMetByVentNoLoad
        CoilType ExcessLoad;       // LoadAddedByVentOvercool
        CoilType PotentialSavings; // LoadAddedByVentCoolLost
        CoilType PotentialCost;    // LoadAddedByVentHeatLost

        // Default Constructor
        SummarizeLoads()
        {
        }
    };

    // Object Data
    thread_local extern Array1D<SummarizeLoads> Vent;

    // Functions

    void InitEnergyReports();

    void FindFirstLastPtr(int &LoopType, int &LoopNum, int &ArrayCount, int &LoopCount, bool &ConnectionFlag);

    void UpdateZoneCompPtrArray(int &Idx,
                                int const ListNum,
                                int const AirDistUnitNum,
                                int const PlantLoopType,
                                int const PlantLoop,
                                int const PlantBranch,
                                int const PlantComp);

    void UpdateZoneSubCompPtrArray(int &Idx,
                                   int const ListNum,
                                   int const AirDistUnitNum,
                                   int const SubCompNum,
                                   int const PlantLoopType,
                                   int const PlantLoop,
                                   int const PlantBranch,
                                   int const PlantComp);

    void UpdateZoneSubSubCompPtrArray(int &Idx,
                                      int const ListNum,
                                      int const AirDistUnitNum,
                                      int const SubCompNum,
                                      int const SubSubCompNum,
                                      int const PlantLoopType,
                                      int const PlantLoop,
                                      int const PlantBranch,
                                      int const PlantComp);

    void UpdateAirSysCompPtrArray(int &Idx,
                                  int const AirLoopNum,
                                  int const BranchNum,
                                  int const CompNum,
                                  int const PlantLoopType,
                                  int const PlantLoop,
                                  int const PlantBranch,
                                  int const PlantComp);

    void UpdateAirSysSubCompPtrArray(int &Idx,
                                     int const AirLoopNum,
                                     int const BranchNum,
                                     int const CompNum,
                                     int const SubCompNum,
                                     int const PlantLoopType,
                                     int const PlantLoop,
                                     int const PlantBranch,
                                     int const PlantComp);

    void UpdateAirSysSubSubCompPtrArray(int &Idx,
                                        int const AirLoopNum,
                                        int const BranchNum,
                                        int const CompNum,
                                        int const SubCompNum,
                                        int const SubSubCompNum,
                                        int const PlantLoopType,
                                        int const PlantLoop,
                                        int const PlantBranch,
                                        int const PlantComp);

    void AllocateAndSetUpVentReports();

    void CreateEnergyReportStructure();

    // End Initialization Section of the Module
    //******************************************************************************

    // Beginning of Reporting subroutines for the SimAir Module
    // *****************************************************************************

    void ReportSystemEnergyUse();

    void CalcSystemEnergyUse(bool const CompLoadFlag,
                             int const AirLoopNum,
                             std::string const &CompType,
                             int const EnergyType,
                             Real64 const CompLoad,
                             Real64 const CompEnergy);

    void ReportMaxVentilationLoads();

    void MatchPlantSys(int const AirLoopNum, // counter for zone air distribution inlets
                       int const BranchNum   // counter for zone air distribution inlets
    );

    void FindDemandSideMatch(std::string const &CompType, // Inlet node of the component to find the match of
                             std::string const &CompName, // Outlet node of the component to find the match of
                             bool &MatchFound,            // Set to .TRUE. when a match is found
                             int &MatchLoopType,          // Loop number of the match
                             int &MatchLoop,              // Loop number of the match
                             int &MatchBranch,            // Branch number of the match
                             int &MatchComp               // Component number of the match
    );

    void ReportAirLoopConnections();

    //        End of Reporting subroutines for the SimAir Module
    // *****************************************************************************

} // namespace SystemReports

} // namespace EnergyPlus

#endif
