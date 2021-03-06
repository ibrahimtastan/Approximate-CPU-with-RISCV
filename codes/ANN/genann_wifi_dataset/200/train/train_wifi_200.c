#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "C:/Users/Tutel/Desktop/genann/genann_robot/genann_robot_c_run/genann.h"
#include "genann.c"
/*
 * GENANN - Minimal C Artificial Neural Network
 *
 * Copyright (c) 2015-2018 Lewis Van Winkle
 *
 * http://CodePlea.com
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgement in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

//#include "genann.h"
void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(int argc, char *argv[])
{
    //printf("GENANN example 1.\n");
    //printf("Train a small ANN to the XOR function using backpropagation.\n");

    /* This will make the neural network initialize differently each run. */
    /* If you don't get a good result, try again for a different result. */
    srand(time(0));

    /* Input and expected out data for the XOR function. */
    const double input[200][7] = {
 {	0.128	,	0.112	,	0.122	,	0.132	,	0.142	,	0.164	,	0.162	},
{	0.136	,	0.114	,	0.122	,	0.13	,	0.142	,	0.17	,	0.17	},
{	0.126	,	0.12	,	0.12	,	0.134	,	0.152	,	0.17	,	0.168	},
{	0.122	,	0.12	,	0.136	,	0.124	,	0.154	,	0.18	,	0.16	},
{	0.126	,	0.13	,	0.12	,	0.126	,	0.154	,	0.162	,	0.174	},
{	0.128	,	0.11	,	0.126	,	0.132	,	0.152	,	0.176	,	0.166	},
{	0.13	,	0.122	,	0.13	,	0.134	,	0.138	,	0.174	,	0.168	},
{	0.122	,	0.126	,	0.116	,	0.132	,	0.148	,	0.174	,	0.164	},
{	0.13	,	0.12	,	0.118	,	0.126	,	0.152	,	0.172	,	0.164	},
{	0.12	,	0.116	,	0.12	,	0.122	,	0.146	,	0.168	,	0.176	},
{	0.124	,	0.118	,	0.126	,	0.128	,	0.14	,	0.168	,	0.168	},
{	0.126	,	0.118	,	0.128	,	0.132	,	0.144	,	0.168	,	0.18	},
{	0.13	,	0.118	,	0.132	,	0.13	,	0.136	,	0.164	,	0.17	},
{	0.126	,	0.112	,	0.126	,	0.13	,	0.144	,	0.164	,	0.178	},
{	0.134	,	0.12	,	0.132	,	0.13	,	0.15	,	0.172	,	0.174	},
{	0.126	,	0.114	,	0.134	,	0.132	,	0.158	,	0.172	,	0.178	},
{	0.132	,	0.118	,	0.128	,	0.136	,	0.136	,	0.194	,	0.166	},
{	0.13	,	0.122	,	0.128	,	0.136	,	0.154	,	0.172	,	0.178	},
{	0.132	,	0.114	,	0.13	,	0.138	,	0.156	,	0.17	,	0.17	},
{	0.134	,	0.114	,	0.128	,	0.142	,	0.15	,	0.178	,	0.174	},
{	0.13	,	0.124	,	0.124	,	0.13	,	0.154	,	0.168	,	0.17	},
{	0.122	,	0.108	,	0.12	,	0.122	,	0.148	,	0.174	,	0.166	},
{	0.13	,	0.106	,	0.12	,	0.124	,	0.138	,	0.17	,	0.166	},
{	0.132	,	0.11	,	0.126	,	0.13	,	0.136	,	0.17	,	0.18	},
{	0.126	,	0.114	,	0.118	,	0.134	,	0.142	,	0.164	,	0.186	},
{	0.126	,	0.114	,	0.124	,	0.13	,	0.152	,	0.164	,	0.176	},
{	0.128	,	0.114	,	0.124	,	0.134	,	0.136	,	0.166	,	0.168	},
{	0.136	,	0.126	,	0.136	,	0.128	,	0.148	,	0.172	,	0.168	},
{	0.14	,	0.124	,	0.136	,	0.13	,	0.162	,	0.178	,	0.166	},
{	0.134	,	0.118	,	0.124	,	0.132	,	0.16	,	0.192	,	0.164	},
{	0.132	,	0.118	,	0.128	,	0.134	,	0.154	,	0.174	,	0.17	},
{	0.132	,	0.118	,	0.13	,	0.136	,	0.15	,	0.176	,	0.168	},
{	0.134	,	0.118	,	0.124	,	0.13	,	0.142	,	0.182	,	0.168	},
{	0.138	,	0.122	,	0.124	,	0.124	,	0.15	,	0.17	,	0.168	},
{	0.136	,	0.116	,	0.13	,	0.13	,	0.152	,	0.174	,	0.164	},
{	0.132	,	0.124	,	0.128	,	0.136	,	0.146	,	0.178	,	0.166	},
{	0.136	,	0.116	,	0.13	,	0.134	,	0.166	,	0.178	,	0.172	},
{	0.13	,	0.116	,	0.124	,	0.134	,	0.154	,	0.172	,	0.182	},
{	0.13	,	0.116	,	0.128	,	0.138	,	0.162	,	0.176	,	0.18	},
{	0.13	,	0.112	,	0.126	,	0.142	,	0.154	,	0.178	,	0.17	},
{	0.128	,	0.118	,	0.13	,	0.14	,	0.168	,	0.18	,	0.178	},
{	0.128	,	0.112	,	0.128	,	0.14	,	0.16	,	0.182	,	0.168	},
{	0.136	,	0.114	,	0.128	,	0.136	,	0.154	,	0.176	,	0.17	},
{	0.134	,	0.112	,	0.13	,	0.136	,	0.164	,	0.192	,	0.178	},
{	0.132	,	0.138	,	0.126	,	0.138	,	0.158	,	0.176	,	0.172	},
{	0.136	,	0.114	,	0.124	,	0.136	,	0.154	,	0.182	,	0.172	},
{	0.124	,	0.116	,	0.122	,	0.136	,	0.14	,	0.17	,	0.172	},
{	0.126	,	0.116	,	0.132	,	0.136	,	0.15	,	0.18	,	0.186	},
{	0.124	,	0.116	,	0.114	,	0.13	,	0.14	,	0.164	,	0.182	},
{	0.128	,	0.102	,	0.114	,	0.134	,	0.136	,	0.168	,	0.164	},
{	0.08	,	0.1	,	0.098	,	0.102	,	0.13	,	0.15	,	0.16	},
{	0.076	,	0.104	,	0.112	,	0.088	,	0.13	,	0.142	,	0.15	},
{	0.076	,	0.102	,	0.108	,	0.09	,	0.134	,	0.144	,	0.152	},
{	0.08	,	0.11	,	0.094	,	0.094	,	0.128	,	0.15	,	0.158	},
{	0.078	,	0.112	,	0.106	,	0.08	,	0.138	,	0.15	,	0.144	},
{	0.086	,	0.116	,	0.1	,	0.09	,	0.142	,	0.136	,	0.148	},
{	0.08	,	0.106	,	0.1	,	0.08	,	0.12	,	0.138	,	0.148	},
{	0.076	,	0.116	,	0.118	,	0.074	,	0.132	,	0.148	,	0.134	},
{	0.076	,	0.126	,	0.122	,	0.086	,	0.128	,	0.152	,	0.152	},
{	0.074	,	0.112	,	0.116	,	0.078	,	0.132	,	0.14	,	0.144	},
{	0.04	,	0.126	,	0.122	,	0.07	,	0.14	,	0.146	,	0.142	},
{	0.078	,	0.114	,	0.11	,	0.074	,	0.134	,	0.14	,	0.146	},
{	0.07	,	0.116	,	0.118	,	0.08	,	0.15	,	0.15	,	0.146	},
{	0.038	,	0.118	,	0.11	,	0.074	,	0.146	,	0.144	,	0.132	},
{	0.04	,	0.112	,	0.11	,	0.074	,	0.122	,	0.158	,	0.144	},
{	0.07	,	0.108	,	0.11	,	0.08	,	0.122	,	0.158	,	0.146	},
{	0.038	,	0.12	,	0.112	,	0.072	,	0.126	,	0.14	,	0.15	},
{	0.03	,	0.12	,	0.118	,	0.074	,	0.13	,	0.148	,	0.146	},
{	0.036	,	0.12	,	0.118	,	0.034	,	0.136	,	0.15	,	0.15	},
{	0.038	,	0.126	,	0.132	,	0.04	,	0.158	,	0.146	,	0.144	},
{	0.028	,	0.118	,	0.128	,	0.032	,	0.158	,	0.152	,	0.144	},
{	0.026	,	0.126	,	0.13	,	0.032	,	0.148	,	0.146	,	0.148	},
{	0.026	,	0.12	,	0.126	,	0.036	,	0.14	,	0.146	,	0.146	},
{	0.024	,	0.12	,	0.136	,	0.03	,	0.148	,	0.146	,	0.14	},
{	0.024	,	0.128	,	0.126	,	0.036	,	0.138	,	0.144	,	0.148	},
{	0.034	,	0.126	,	0.13	,	0.054	,	0.172	,	0.144	,	0.148	},
{	0.054	,	0.118	,	0.112	,	0.076	,	0.124	,	0.15	,	0.158	},
{	0.082	,	0.116	,	0.132	,	0.082	,	0.146	,	0.142	,	0.158	},
{	0.078	,	0.108	,	0.11	,	0.074	,	0.142	,	0.128	,	0.134	},
{	0.076	,	0.112	,	0.11	,	0.078	,	0.15	,	0.142	,	0.15	},
{	0.076	,	0.124	,	0.114	,	0.082	,	0.154	,	0.13	,	0.136	},
{	0.082	,	0.114	,	0.128	,	0.084	,	0.148	,	0.138	,	0.14	},
{	0.086	,	0.118	,	0.126	,	0.08	,	0.148	,	0.132	,	0.128	},
{	0.088	,	0.116	,	0.126	,	0.078	,	0.16	,	0.142	,	0.144	},
{	0.09	,	0.116	,	0.126	,	0.09	,	0.16	,	0.152	,	0.13	},
{	0.088	,	0.114	,	0.128	,	0.08	,	0.15	,	0.138	,	0.128	},
{	0.084	,	0.116	,	0.126	,	0.082	,	0.15	,	0.138	,	0.134	},
{	0.088	,	0.114	,	0.124	,	0.082	,	0.15	,	0.13	,	0.136	},
{	0.09	,	0.116	,	0.124	,	0.08	,	0.146	,	0.14	,	0.134	},
{	0.082	,	0.118	,	0.13	,	0.094	,	0.15	,	0.136	,	0.132	},
{	0.08	,	0.126	,	0.134	,	0.08	,	0.15	,	0.14	,	0.14	},
{	0.08	,	0.112	,	0.114	,	0.07	,	0.168	,	0.14	,	0.132	},
{	0.072	,	0.12	,	0.114	,	0.074	,	0.136	,	0.132	,	0.154	},
{	0.072	,	0.118	,	0.114	,	0.038	,	0.14	,	0.138	,	0.15	},
{	0.034	,	0.118	,	0.126	,	0.03	,	0.14	,	0.152	,	0.17	},
{	0.07	,	0.114	,	0.108	,	0.07	,	0.128	,	0.156	,	0.152	},
{	0.078	,	0.108	,	0.11	,	0.074	,	0.122	,	0.154	,	0.158	},
{	0.084	,	0.112	,	0.104	,	0.072	,	0.15	,	0.136	,	0.162	},
{	0.078	,	0.102	,	0.128	,	0.076	,	0.142	,	0.156	,	0.156	},
{	0.086	,	0.106	,	0.106	,	0.076	,	0.126	,	0.152	,	0.146	},
{	0.098	,	0.112	,	0.094	,	0.1	,	0.116	,	0.154	,	0.168	},
{	0.094	,	0.116	,	0.102	,	0.086	,	0.13	,	0.16	,	0.16	},
{	0.094	,	0.108	,	0.112	,	0.094	,	0.124	,	0.156	,	0.166	},
{	0.098	,	0.11	,	0.106	,	0.096	,	0.122	,	0.158	,	0.156	},
{	0.094	,	0.114	,	0.104	,	0.088	,	0.134	,	0.156	,	0.15	},
{	0.1	,	0.124	,	0.114	,	0.09	,	0.124	,	0.162	,	0.156	},
{	0.092	,	0.112	,	0.12	,	0.092	,	0.13	,	0.168	,	0.17	},
{	0.102	,	0.11	,	0.106	,	0.1	,	0.126	,	0.158	,	0.172	},
{	0.092	,	0.096	,	0.106	,	0.098	,	0.118	,	0.16	,	0.156	},
{	0.092	,	0.116	,	0.106	,	0.096	,	0.12	,	0.158	,	0.158	},
{	0.098	,	0.09	,	0.1	,	0.096	,	0.122	,	0.158	,	0.168	},
{	0.098	,	0.098	,	0.094	,	0.1	,	0.118	,	0.158	,	0.176	},
{	0.098	,	0.106	,	0.1	,	0.108	,	0.124	,	0.154	,	0.164	},
{	0.104	,	0.108	,	0.11	,	0.11	,	0.12	,	0.148	,	0.156	},
{	0.096	,	0.112	,	0.098	,	0.104	,	0.12	,	0.164	,	0.146	},
{	0.108	,	0.114	,	0.106	,	0.108	,	0.124	,	0.154	,	0.15	},
{	0.096	,	0.108	,	0.098	,	0.118	,	0.126	,	0.156	,	0.16	},
{	0.104	,	0.106	,	0.1	,	0.104	,	0.126	,	0.168	,	0.176	},
{	0.106	,	0.104	,	0.096	,	0.1	,	0.124	,	0.162	,	0.16	},
{	0.106	,	0.106	,	0.102	,	0.1	,	0.132	,	0.164	,	0.164	},
{	0.092	,	0.112	,	0.108	,	0.102	,	0.124	,	0.16	,	0.158	},
{	0.094	,	0.116	,	0.1	,	0.11	,	0.128	,	0.152	,	0.148	},
{	0.096	,	0.094	,	0.104	,	0.112	,	0.122	,	0.154	,	0.154	},
{	0.098	,	0.1	,	0.1	,	0.09	,	0.128	,	0.158	,	0.154	},
{	0.094	,	0.102	,	0.112	,	0.1	,	0.12	,	0.156	,	0.16	},
{	0.104	,	0.1	,	0.104	,	0.098	,	0.126	,	0.16	,	0.17	},
{	0.096	,	0.094	,	0.102	,	0.104	,	0.12	,	0.148	,	0.158	},
{	0.094	,	0.102	,	0.108	,	0.1	,	0.128	,	0.15	,	0.164	},
{	0.098	,	0.104	,	0.106	,	0.098	,	0.128	,	0.154	,	0.166	},
{	0.09	,	0.112	,	0.11	,	0.092	,	0.136	,	0.158	,	0.156	},
{	0.092	,	0.116	,	0.108	,	0.096	,	0.126	,	0.156	,	0.15	},
{	0.102	,	0.102	,	0.118	,	0.092	,	0.12	,	0.16	,	0.164	},
{	0.106	,	0.112	,	0.108	,	0.106	,	0.124	,	0.176	,	0.17	},
{	0.1	,	0.116	,	0.108	,	0.1	,	0.13	,	0.158	,	0.178	},
{	0.104	,	0.102	,	0.106	,	0.108	,	0.136	,	0.176	,	0.168	},
{	0.102	,	0.124	,	0.106	,	0.102	,	0.128	,	0.172	,	0.158	},
{	0.102	,	0.102	,	0.108	,	0.106	,	0.118	,	0.172	,	0.17	},
{	0.1	,	0.136	,	0.096	,	0.112	,	0.126	,	0.16	,	0.154	},
{	0.096	,	0.104	,	0.108	,	0.104	,	0.126	,	0.16	,	0.154	},
{	0.104	,	0.106	,	0.108	,	0.098	,	0.126	,	0.17	,	0.158	},
{	0.102	,	0.108	,	0.108	,	0.108	,	0.124	,	0.17	,	0.156	},
{	0.108	,	0.108	,	0.11	,	0.104	,	0.122	,	0.172	,	0.156	},
{	0.104	,	0.108	,	0.108	,	0.102	,	0.126	,	0.174	,	0.156	},
{	0.104	,	0.106	,	0.112	,	0.098	,	0.124	,	0.166	,	0.16	},
{	0.094	,	0.112	,	0.108	,	0.102	,	0.126	,	0.162	,	0.172	},
{	0.102	,	0.114	,	0.108	,	0.11	,	0.124	,	0.174	,	0.162	},
{	0.098	,	0.108	,	0.104	,	0.112	,	0.12	,	0.17	,	0.146	},
{	0.098	,	0.108	,	0.1	,	0.102	,	0.132	,	0.156	,	0.164	},
{	0.092	,	0.094	,	0.094	,	0.1	,	0.13	,	0.158	,	0.168	},
{	0.102	,	0.108	,	0.088	,	0.104	,	0.112	,	0.158	,	0.158	},
{	0.118	,	0.104	,	0.114	,	0.12	,	0.098	,	0.172	,	0.176	},
{	0.12	,	0.106	,	0.118	,	0.118	,	0.106	,	0.172	,	0.172	},
{	0.114	,	0.104	,	0.112	,	0.124	,	0.104	,	0.184	,	0.17	},
{	0.112	,	0.102	,	0.086	,	0.118	,	0.094	,	0.166	,	0.178	},
{	0.11	,	0.104	,	0.092	,	0.118	,	0.106	,	0.176	,	0.168	},
{	0.112	,	0.116	,	0.096	,	0.12	,	0.102	,	0.17	,	0.17	},
{	0.126	,	0.116	,	0.104	,	0.118	,	0.102	,	0.176	,	0.188	},
{	0.114	,	0.122	,	0.106	,	0.118	,	0.104	,	0.174	,	0.178	},
{	0.116	,	0.122	,	0.104	,	0.122	,	0.106	,	0.17	,	0.176	},
{	0.114	,	0.114	,	0.102	,	0.12	,	0.106	,	0.17	,	0.178	},
{	0.114	,	0.12	,	0.098	,	0.122	,	0.108	,	0.17	,	0.176	},
{	0.114	,	0.122	,	0.112	,	0.12	,	0.106	,	0.172	,	0.172	},
{	0.116	,	0.108	,	0.104	,	0.122	,	0.106	,	0.17	,	0.178	},
{	0.11	,	0.112	,	0.094	,	0.108	,	0.098	,	0.162	,	0.158	},
{	0.116	,	0.11	,	0.11	,	0.108	,	0.098	,	0.156	,	0.158	},
{	0.126	,	0.108	,	0.1	,	0.11	,	0.1	,	0.17	,	0.158	},
{	0.116	,	0.11	,	0.106	,	0.118	,	0.104	,	0.162	,	0.168	},
{	0.118	,	0.118	,	0.104	,	0.12	,	0.102	,	0.174	,	0.172	},
{	0.114	,	0.11	,	0.114	,	0.118	,	0.096	,	0.17	,	0.168	},
{	0.118	,	0.114	,	0.106	,	0.116	,	0.11	,	0.17	,	0.172	},
{	0.118	,	0.118	,	0.104	,	0.118	,	0.106	,	0.174	,	0.174	},
{	0.118	,	0.112	,	0.106	,	0.12	,	0.098	,	0.17	,	0.168	},
{	0.116	,	0.112	,	0.112	,	0.122	,	0.104	,	0.17	,	0.17	},
{	0.116	,	0.118	,	0.112	,	0.12	,	0.1	,	0.172	,	0.166	},
{	0.114	,	0.114	,	0.108	,	0.116	,	0.112	,	0.168	,	0.174	},
{	0.11	,	0.112	,	0.096	,	0.12	,	0.11	,	0.168	,	0.168	},
{	0.104	,	0.122	,	0.096	,	0.12	,	0.102	,	0.16	,	0.16	},
{	0.108	,	0.114	,	0.1	,	0.122	,	0.106	,	0.166	,	0.164	},
{	0.11	,	0.106	,	0.102	,	0.124	,	0.112	,	0.17	,	0.174	},
{	0.116	,	0.11	,	0.102	,	0.132	,	0.108	,	0.172	,	0.17	},
{	0.116	,	0.106	,	0.098	,	0.12	,	0.096	,	0.172	,	0.182	},
{	0.11	,	0.096	,	0.098	,	0.124	,	0.11	,	0.172	,	0.182	},
{	0.118	,	0.114	,	0.1	,	0.118	,	0.1	,	0.178	,	0.16	},
{	0.128	,	0.11	,	0.104	,	0.148	,	0.106	,	0.178	,	0.16	},
{	0.124	,	0.124	,	0.098	,	0.132	,	0.094	,	0.186	,	0.16	},
{	0.128	,	0.114	,	0.106	,	0.128	,	0.094	,	0.176	,	0.182	},
{	0.128	,	0.118	,	0.102	,	0.124	,	0.102	,	0.176	,	0.182	},
{	0.126	,	0.112	,	0.106	,	0.12	,	0.098	,	0.176	,	0.176	},
{	0.122	,	0.116	,	0.108	,	0.126	,	0.094	,	0.176	,	0.162	},
{	0.126	,	0.114	,	0.104	,	0.128	,	0.104	,	0.176	,	0.186	},
{	0.128	,	0.116	,	0.1	,	0.13	,	0.1	,	0.182	,	0.17	},
{	0.132	,	0.114	,	0.11	,	0.128	,	0.104	,	0.182	,	0.174	},
{	0.122	,	0.11	,	0.108	,	0.138	,	0.106	,	0.168	,	0.178	},
{	0.122	,	0.122	,	0.1	,	0.128	,	0.102	,	0.168	,	0.178	},
{	0.12	,	0.12	,	0.102	,	0.128	,	0.106	,	0.174	,	0.174	},
{	0.124	,	0.126	,	0.104	,	0.14	,	0.096	,	0.174	,	0.174	},
{	0.128	,	0.114	,	0.106	,	0.132	,	0.096	,	0.184	,	0.174	},
{	0.126	,	0.108	,	0.106	,	0.13	,	0.104	,	0.184	,	0.178	},
{	0.126	,	0.114	,	0.114	,	0.14	,	0.1	,	0.184	,	0.174	},
{	0.14	,	0.118	,	0.112	,	0.128	,	0.092	,	0.176	,	0.19	},


    };


   double  output[200][2] =   {	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	};


int array_index [200] = {	0	,
	1	,
	2	,
	3	,
	4	,
	5	,
	6	,
	7	,
	8	,
	9	,
	10	,
	11	,
	12	,
	13	,
	14	,
	15	,
	16	,
	17	,
	18	,
	19	,
	20	,
	21	,
	22	,
	23	,
	24	,
	25	,
	26	,
	27	,
	28	,
	29	,
	30	,
	31	,
	32	,
	33	,
	34	,
	35	,
	36	,
	37	,
	38	,
	39	,
	40	,
	41	,
	42	,
	43	,
	44	,
	45	,
	46	,
	47	,
	48	,
	49	,
	50	,
	51	,
	52	,
	53	,
	54	,
	55	,
	56	,
	57	,
	58	,
	59	,
	60	,
	61	,
	62	,
	63	,
	64	,
	65	,
	66	,
	67	,
	68	,
	69	,
	70	,
	71	,
	72	,
	73	,
	74	,
	75	,
	76	,
	77	,
	78	,
	79	,
	80	,
	81	,
	82	,
	83	,
	84	,
	85	,
	86	,
	87	,
	88	,
	89	,
	90	,
	91	,
	92	,
	93	,
	94	,
	95	,
	96	,
	97	,
	98	,
	99	,
	100	,
	101	,
	102	,
	103	,
	104	,
	105	,
	106	,
	107	,
	108	,
	109	,
	110	,
	111	,
	112	,
	113	,
	114	,
	115	,
	116	,
	117	,
	118	,
	119	,
	120	,
	121	,
	122	,
	123	,
	124	,
	125	,
	126	,
	127	,
	128	,
	129	,
	130	,
	131	,
	132	,
	133	,
	134	,
	135	,
	136	,
	137	,
	138	,
	139	,
	140	,
	141	,
	142	,
	143	,
	144	,
	145	,
	146	,
	147	,
	148	,
	149	,
	150	,
	151	,
	152	,
	153	,
	154	,
	155	,
	156	,
	157	,
	158	,
	159	,
	160	,
	161	,
	162	,
	163	,
	164	,
	165	,
	166	,
	167	,
	168	,
	169	,
	170	,
	171	,
	172	,
	173	,
	174	,
	175	,
	176	,
	177	,
	178	,
	179	,
	180	,
	181	,
	182	,
	183	,
	184	,
	185	,
	186	,
	187	,
	188	,
	189	,
	190	,
	191	,
	192	,
	193	,
	194	,
	195	,
	196	,
	197	,
	198	,
	199	};



    int i;
	int j;
	int k;
    /* New network with 7 inputs,
     * 1 hidden layer of 4 neurons,
     * and 2 output. */
    volatile genann *ann = genann_init(7, 1, 4, 2);

    /* Train on the four labeled data points many times. */


    for (i = 0; i < 300; ++i) {
    shuffle(array_index, 200);

		for (j = 0; j < 200; j++) {
		  //  srand(time(NULL));

                //int v  = rand() % 200;
			genann_train(ann, input[array_index[j]], output[array_index[j]],2);
		}
    }
			//printf(" \n ");

        //	genann_train(ann, input[0], output + 0, 3);
    //  genann_train(ann, input[1], output + 1, 3);
    //  genann_train(ann, input[2], output + 2, 3);
    //  genann_train(ann, input[3], output + 3, 3);

    /* Run the network and see what it predicts. */
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[0][0], input[0][1], *genann_run(ann, input[0]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[1][0], input[1][1], *genann_run(ann, input[1]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[2][0], input[2][1], *genann_run(ann, input[2]));
    //printf("Output for [%1.f, %1.f] is %1.f.\n", input[3][0], input[3][1], *genann_run(ann, input[3]));

	for (int j = 0; j < 200; j++) {
            double * result = genann_run(ann, input[j]);

//
			printf("Output of input [%f,%f,%f,%f] for [%f %f] is %1.f ",input[j][0],input[j][1],input[j][2],input[j][3],output[j][0] , output[j][1],  *result++);
			printf("%1.f\n", *result);
		}

//  *genann_run(ann, input[0];
//	*genann_run(ann, input[1];
//	*genann_run(ann, input[2];
//	*genann_run(ann, input[3];
    FILE *robot_weight = fopen("genann.txt", "w");
    genann_write(ann,robot_weight);
    genann_free(ann);
    fclose(robot_weight);

    return 0;
}
