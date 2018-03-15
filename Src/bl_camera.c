#include "bl_camera.h"
#include "debug.h"

bl_Camera *CreateCamera(bl_CameraPosition CameraPosition, int mode){
	bl_Camera* camera;

	//Allocate memory for camera
	camera = (bl_Camera*) malloc(sizeof(bl_Camera));
	if(camera == NULL){
		perror("Allocating memory for camera failed!");
		exit(10);
	}

	camera->Position = CameraPosition;

	//Set Mode, Topview is default
	switch(mode){
		case 0: camera->Mode = BL_CAM_TOP; break;
		case 1: camera->Mode = BL_CAM_FPP; break;
		default: printf("Unsupported camera mode %d!\n", mode);
				 camera->Mode = BL_CAM_TOP;
				 break;
	}

	//Set LookAt depending on mode
	camera->LookAt = camera->Position;

	switch(camera->Mode){
		case BL_CAM_TOP: camera->LookAt.X += 1; break;
		case BL_CAM_FPP: camera->LookAt.X += 1; break;
	}

	//camera->LookAt = CreateCameraPosition(0,4,-5);

	return camera;
}

//Creates a bl_CameraPosition struct with X Y Z
bl_CameraPosition CreateCameraPosition(float x, float y, float z){
	bl_CameraPosition tmp;
	tmp.X = x; tmp.Y = y; tmp.Z = z;
	return tmp;
}


void bl_CameraInfo(bl_Camera *camera){
	printf("Camera Info:\n");
	printf("Mode: %d\n", camera->Mode);
	printf("Position: %f %f %f\n", camera->Position.X, camera->Position.Y, camera->Position.Z);
	printf("LookAt: %f %f %f\n", camera->LookAt.X, camera->LookAt.Y, camera->LookAt.Z);
}