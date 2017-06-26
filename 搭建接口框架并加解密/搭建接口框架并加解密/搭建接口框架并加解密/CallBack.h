#pragma once

int init_data(void ** hand);

int send_data(void * hand, char * sendata, int senlen);

int gain_data(void * hand, char * gaindata, int * gainlen);

int wipe_data(void ** hand);