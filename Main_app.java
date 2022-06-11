package com.example.afinal;

import android.content.Context;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;
import android.widget.ToggleButton;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private ToggleButton toggleFlashLightOnOff;
    private CameraManager cameraManager;
    private String getCameraID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Register the ToggleButton with specific ID
        toggleFlashLightOnOff = findViewById(R.id.toggle_flashlight);

        // cameraManager to interact with camera devices
        cameraManager = (CameraManager) getSystemService(Context.CAMERA_SERVICE);

        // Exception is handled, because to check whether
        // the camera resource is being used by another
        // service or not.
        try {
            // O means back camera unit,
            // 1 means front camera unit
            getCameraID = cameraManager.getCameraIdList()[0];
        } catch (CameraAccessException e) {
            e.printStackTrace();
        }
    }

    // RequiresApi is set because, the devices which are
    // below API level 10 don't have the flash unit with
    // camera.
    @RequiresApi(api = Build.VERSION_CODES.M)
    public void toggleFlashLight(View view) {


            String name = "1000101010101010";





        if (toggleFlashLightOnOff.isChecked()) {
            int b=1;
            if (b== '1') {
                if (toggleFlashLightOnOff.isChecked()) {
                    // Exception is handled, because to check
                    // whether the camera resource is being used by
                    // another service or not.
                    try {
                        // true sets the torch in ON mode
                        cameraManager.setTorchMode(getCameraID, true);

                        // Inform the user about the flashlight
                        // status using Toast message
                        Toast.makeText(MainActivity.this, "Flashlight is turned ON", Toast.LENGTH_SHORT).show();
                    } catch (CameraAccessException e) {
                        // prints stack trace on standard error
                        // output error stream
                        e.printStackTrace();
                    }
                }
            }try {
                Thread.sleep(150);
            }catch (InterruptedException ie) {
                Thread.currentThread().interrupt();
            }
            for (int i = 0; i < name.length(); i++) {
                char a = name.charAt(i);


                if (a == '1') {
                    if (toggleFlashLightOnOff.isChecked()) {
                        // Exception is handled, because to check
                        // whether the camera resource is being used by
                        // another service or not.
                        try {
                            // true sets the torch in ON mode
                            cameraManager.setTorchMode(getCameraID, true);

                            // Inform the user about the flashlight
                            // status using Toast message
                            Toast.makeText(MainActivity.this, "Flashlight is turned ON", Toast.LENGTH_SHORT).show();
                        } catch (CameraAccessException e) {
                            // prints stack trace on standard error
                            // output error stream
                            e.printStackTrace();
                        }
                    }
                } else {

                    if (toggleFlashLightOnOff.isChecked()) {
                        // Exception is handled, because to check
                        // whether the camera resource is being used by
                        // another service or not.
                        try {
                            // true sets the torch in OFF mode
                            cameraManager.setTorchMode(getCameraID, false);

                            // Inform the user about the flashlight
                            // status using Toast message
                            Toast.makeText(MainActivity.this, "Flashlight is turned OFF", Toast.LENGTH_SHORT).show();
                        } catch (CameraAccessException e) {
                            // prints stack trace on standard error
                            // output error stream
                            e.printStackTrace();
                        }
                    }

                }
                try {
                    Thread.sleep(100);
                }catch (InterruptedException ie) {
                    Thread.currentThread().interrupt();
                }

            }


        }







    }
    // when you click on button and torch open and
// you do not close the tourch again this code
// will off the tourch automatically
    @RequiresApi(api = Build.VERSION_CODES.M)
    @Override
    public void finish() {
        super.finish();
        try {
            // true sets the torch in OFF mode
            cameraManager.setTorchMode(getCameraID, false);

            // Inform the user about the flashlight
            // status using Toast message
            //Toast.makeText(SlaphScreen.this, "Flashlight is turned OFF", Toast.LENGTH_SHORT).show();
        } catch (CameraAccessException e) {
            // prints stack trace on standard error
            // output error stream
            e.printStackTrace();
        }
    }
}
