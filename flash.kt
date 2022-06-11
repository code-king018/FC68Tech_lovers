package com.example.blinkit3

import android.hardware.camera2.CameraAccessException
import android.hardware.camera2.CameraManager
import android.os.Build
import android.os.Bundle
import android.view.View
import android.widget.Toast
import android.widget.ToggleButton
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity


class MainActivity : AppCompatActivity() {
    private var toggleFlashLightOnOff: ToggleButton? = null
    private var cameraManager: CameraManager? = null
    private var getCameraID: String? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        toggleFlashLightOnOff = findViewById(R.id.toggle_flashlight)


        cameraManager = getSystemService(CAMERA_SERVICE) as CameraManager


        try {

            getCameraID = cameraManager!!.cameraIdList[0]
        } catch (e: CameraAccessException) {
            e.printStackTrace()
        }
    }


    @RequiresApi(api = Build.VERSION_CODES.M)
    fun toggleFlashLight(view: View?) {

        var s="1000111111000111";






        if (toggleFlashLightOnOff!!.isChecked) {

            try {

                cameraManager!!.setTorchMode(getCameraID!!, true)


                Toast.makeText(this@MainActivity, "Flashlight is turned ON", Toast.LENGTH_SHORT)
                    .show()
            } catch (e: CameraAccessException) {

                e.printStackTrace()
            }
        }






        else {

            try {

                cameraManager!!.setTorchMode(getCameraID!!, false)


                Toast.makeText(this@MainActivity, "Flashlight is turned OFF", Toast.LENGTH_SHORT)
                    .show()
            } catch (e: CameraAccessException) {

                e.printStackTrace()
            }
        }







    }


    @RequiresApi(api = Build.VERSION_CODES.M)
    override fun finish() {
        super.finish()
        try {
            cameraManager!!.setTorchMode(getCameraID!!, false)

        } catch (e: CameraAccessException) {

            e.printStackTrace()
        }
    }
}
