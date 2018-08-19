/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author Maxim Serebrennik
*/

#include <trMPEG/EncodingCallback.h>

#include <trUtil/Logging/Log.h>

namespace trMPEG
{
    //////////////////////////////////////////////////////////////////////////
    EncodingCallback::EncodingCallback(osg::Texture* texture, GLenum pixelFormat, int pboSize)
        : BaseClass(texture->getTextureWidth(), texture->getTextureHeight(), pixelFormat, pboSize)
    {
        // Saves a pointer to the source texture
        mTexturePtr = texture;
    }
    
    //////////////////////////////////////////////////////////////////////////
    EncodingCallback::~EncodingCallback()
    {
        //Shutdown the mpeg stream
        mStream.ShutDown();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::Init()
    {
        if (!mSilent)
        {
            LOG_I("Initializing the MPEG Streamer...")
            std::cout << "Initializing the MPEG Streamer..." << std::endl;
        }
        
        //Setup the MPEG Streamer     
        if (mPixelFormat == GL_RGB)
        {
            mStream.SetInputPixelFormat(Streamer::PixelFormat::RGB);
            LOG_D("Setting MPEG Stream to RGB format")
        }
        else if (mPixelFormat == GL_RGBA)
        {
            mStream.SetInputPixelFormat(Streamer::PixelFormat::RGBA);
            LOG_D("Setting MPEG Stream to RGBA format")
        }        
        mStream.SetFlipImageVertically(true);
        mStream.Init();
    }

    //////////////////////////////////////////////////////////////////////////
    bool EncodingCallback::IsInit()
    {
        return mStream.IsInit();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetSilent(bool silent)
    {
        BaseClass::SetSilent(silent);
        mStream.SetSilent(mSilent);
    }

    //////////////////////////////////////////////////////////////////////////
    bool EncodingCallback::IsSilent()
    {
        return mStream.IsSilent();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetEnabled(bool enabled)
    {
        mEnabled = enabled;
    }

    //////////////////////////////////////////////////////////////////////////
    bool EncodingCallback::GetEnabled()
    {
        return mEnabled;
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetFileName(std::string fileName)
    {
        mStream.SetFileName(fileName);
    }

    //////////////////////////////////////////////////////////////////////////
    std::string EncodingCallback::GetFileName()
    {
        return mStream.GetFileName();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetBroadcast(bool isBroadcast)
    {
        mStream.SetBroadcast(isBroadcast);
    }

    //////////////////////////////////////////////////////////////////////////
    bool EncodingCallback::IsBroadcast()
    {
        return mStream.IsBroadcast();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetUDPAddress(std::string address)
    {
        mStream.SetUDPAddress(address);
    }

    //////////////////////////////////////////////////////////////////////////
    std::string EncodingCallback::GetUDPAddress()
    {
        return mStream.GetUDPAddress();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetMpegType(trMPEG::CodecBase *type)
    {
        mStream.SetMpegType(type);
    }

    //////////////////////////////////////////////////////////////////////////
    const trMPEG::CodecBase* EncodingCallback::GetMpegType()
    {
        return mStream.GetMpegType();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetStreamType(Streamer::StreamType type)
    {
        mStream.SetStreamType(type);
    }

    //////////////////////////////////////////////////////////////////////////
    Streamer::StreamType EncodingCallback::GetStreamType()
    {
        return mStream.GetStreamType();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetResolution(int width, int height)
    {
        mStream.SetResolution(width, height);
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::GetResolution(int& width, int& height)
    {
        mStream.GetResolution(width, height);
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetWidth(int width)
    {
        mStream.SetWidth(width);
    }

    //////////////////////////////////////////////////////////////////////////
    int EncodingCallback::GetWidth()
    {
        return mStream.GetWidth();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetHeight(int height)
    {
        mStream.SetHeight(height);
    }

    //////////////////////////////////////////////////////////////////////////
    int EncodingCallback::GetHeight()
    {
        return mStream.GetWidth();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetBitRate(int bitRate)
    {
        mStream.SetBitRate(bitRate);
    }

    //////////////////////////////////////////////////////////////////////////
    int EncodingCallback::GetBitRate()
    {
        return mStream.GetBitRate();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::SetFrameRate(int fps)
    {
        mStream.SetFrameRate(fps);
    }

    //////////////////////////////////////////////////////////////////////////
    int EncodingCallback::GetFrameRate()
    {
        return mStream.GetFrameRate();
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::operator () (osg::RenderInfo& renderInfo) const
    {
        if (mEnabled)
        {
            if (mTexturePtr)
            {
                renderInfo.getState()->applyTextureAttribute(0, mTexturePtr);
                BaseClass::operator() (renderInfo);
            }

            if (mStream.IsInit())
            {
                //Encode a frame
                mStream.Encode(mFrameData);
            }
            else
            {
                LOG_E("Error: MPEG Stream not initialized. ")
            }
        }                
    }

    //////////////////////////////////////////////////////////////////////////
    void EncodingCallback::ReadPixels() const
    {
        glGetTexImage(GL_TEXTURE_2D, 0, mPixelFormat, mType, 0);
    }
}