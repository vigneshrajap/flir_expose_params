/**
Software License Agreement (BSD)

\file      camera.h
\authors   Michael Hosmar <mhosmar@clearpathrobotics.com>
\copyright Copyright (c) 2018, Clearpath Robotics, Inc., All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Clearpath Robotics nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WAR-
RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, IN-
DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef SPINNAKER_CAMERA_DRIVER_CAMERA_H
#define SPINNAKER_CAMERA_DRIVER_CAMERA_H

#include <ros/ros.h>

// Header generated by dynamic_reconfigure
#include <spinnaker_camera_driver/SpinnakerConfig.h>
#include "spinnaker_camera_driver/set_property.h"

// Spinnaker SDK
#include "spinnaker/Spinnaker.h"
#include "spinnaker/SpinGenApi/SpinnakerGenApi.h"

//*******************************************
// This Class contains camera control functions.
// This base Class is based on the BlackFly S.
// Different cameras can extend/ override
// this class for any specific differences.
//*******************************************

namespace spinnaker_camera_driver
{
class Camera
{
public:
  explicit Camera(Spinnaker::GenApi::INodeMap* node_map);
  ~Camera()
  {
  }
  virtual void setNewConfiguration(const spinnaker_camera_driver::SpinnakerConfig& config, const uint32_t& level);

  /** Parameters that need a sensor to be stopped completely when changed. */
  static const uint8_t LEVEL_RECONFIGURE_CLOSE = 3;

  /** Parameters that need a sensor to stop streaming when changed. */
  static const uint8_t LEVEL_RECONFIGURE_STOP = 1;

  /** Parameters that can be changed while a sensor is streaming. */
  static const uint8_t LEVEL_RECONFIGURE_RUNNING = 0;

  virtual void setGain(const float& gain);
  int getHeightMax();
  int getWidthMax();

  Spinnaker::GenApi::CNodePtr
  readProperty(const Spinnaker::GenICam::gcstring property_name);

protected:
  Spinnaker::GenApi::INodeMap* node_map_;

  virtual void init();

  int height_max_;
  int width_max_;

  /*!
  * \brief Changes the video mode of the connected camera.
  *
  * This function will change the camera to the desired videomode and allow up the maximum framerate for that mode.
  * \param videoMode string of desired video mode, will be changed if unsupported.
  */
  virtual void setFrameRate(const float frame_rate);
  virtual void setImageControlFormats(const spinnaker_camera_driver::SpinnakerConfig& config);
  /*!
  * \brief Set parameters relative to GigE cameras.
  *
  * \param auto_packet_size Flag stating if packet size should be automatically determined or not.
  * \param packet_size The packet size value to use if auto_packet_size is false.
  */
  // TODO(mhosmar): Implement later
  // void setGigEParameters(bool auto_packet_size, unsigned int packet_size, unsigned int packet_delay);

  /*!
  * \brief Will autoconfigure the packet size of the GigECamera with the given GUID.
  *
  * Note that this is expected only to work for GigE cameras, and only if the camera
  * is not connected.
  *
  * \param guid the camera to autoconfigure
  */
  // TODO(mhosmar): Implement later
  // void setupGigEPacketSize(FlyCapture2::PGRGuid & guid);

  /*!
  * \brief Will configure the packet size of the GigECamera with the given GUID to a given value.
  *
  * Note that this is expected only to work for GigE cameras, and only if the camera
  * is not connected.
  *
  * \param guid the camera to autoconfigure
  * \param packet_size The packet size value to use.
  */
  // TODO(mhosmar): Implement later
  // void setupGigEPacketSize(FlyCapture2::PGRGuid & guid, unsigned int packet_size);

  /*!
  * \brief Will configure the packet delay of the GigECamera with the given GUID to a given value.
  *
  * Note that this is expected only to work for GigE cameras, and only if the camera
  * is not connected.
  *
  * \param guid the camera to autoconfigure
  * \param packet_delay The packet delay value to use.
  */
  // TODO(mhosmar): Implement later
  // void setupGigEPacketDelay(FlyCapture2::PGRGuid & guid, unsigned int packet_delay);

  /*!
  * \brief Gets the current frame rate.
  *
  * Gets the camera's current reported frame rate.
  *
  * \return The reported frame rate.
  */
  // TODO(mhosmar): Implement later
  // float getCameraFrameRate();

  /*!
  * \brief Gets the current operating temperature.
  *
  * Gets the camera's current reported operating temperature.
  *
  * \return The reported temperature in Celsius.
  */
  // TODO(mhosmar): Implement later
  // float getCameraTemperature();

  // TODO(mhosmar): Implement the following methods later
  // void setBRWhiteBalance(bool auto_white_balance, uint16_t &blue, uint16_t &red);

  // uint getGain();

  // uint getShutter();

  // uint getBrightness();

  // uint getExposure();

  // uint getWhiteBalance();

  // uint getROIPosition();
};
}  // namespace spinnaker_camera_driver
#endif  // SPINNAKER_CAMERA_DRIVER_CAMERA_H
