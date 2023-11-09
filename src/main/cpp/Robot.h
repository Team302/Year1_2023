// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

using ctre::phoenix::motorcontrol::can::TalonFX;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  ctre::phoenix::motorcontrol::can::TalonFX* m_motor1;
  double m_speed = 0.0;
  int m_counter = 0;

  ctre::phoenix::motorcontrol::can::TalonFX* m_motor3;

  ctre::phoenix::motorcontrol::can::TalonFX* m_motor13;

  ctre::phoenix::motorcontrol::can::TalonFX* m_motor15;

};
