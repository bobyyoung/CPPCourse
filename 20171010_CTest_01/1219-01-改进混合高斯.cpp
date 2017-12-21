//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2\opencv.hpp>
//#include <vector>
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	CvCapture *capture = cvCreateFileCapture("bike.avi");
//	IplImage *img, *img_gray, *img_cny, *back, *fore;//ԭͼ�񡢻Ҷ�ͼ�񡢱�Ե���õ���ͼ�񡢱���ͼ��ǰ��ͼ��
//	int width, height;//ͼ��ĳ�����
//	int cnt = 0; //��Ƶ֡��
//	img = cvQueryFrame(capture);
//	cnt++;
//	width = img->width; height = img->height;
//	vector< vector<double> > mean(width*height), sd(width*height), w(width*height);
//	img_gray = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
//	img_cny = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
//	back = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
//	fore = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
//	cvCvtColor(img, img_gray, CV_BGR2GRAY);
//	cvCopy(img_gray, back);
//	//��ʼ����ϸ�˹����ģ��
//	int K = 5, sd_init = 16, T = 100, match = 0;//��˹�ֲ��ĸ�������׼��ĳ�ʼֵ ֡����ֵ ƥ�����
//	double w_init = 0.05, D = 2.5, alph, p, threold = 0.7;;//Ȩ�صĳ�ʼֵ�����Ų�����ѧϰ���ʡ������������ʡ�Ԥ����ֵ������ѡȡ����ģ�ͣ�
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			mean[i*width + j].push_back((uchar)img_gray->imageData[i*width + j]);
//			sd[i*width + j].push_back(sd_init);
//			w[i*width + j].push_back(1);
//		}
//	}
//	while (1)
//	{
//		img = cvQueryFrame(capture);
//		if (!img) break;
//		cvCvtColor(img, img_gray, CV_BGR2GRAY);
//		cnt++;
//
//		//����ѧϰ����
//		if (cnt < T) alph = (double)1 / (2 * cnt);
//		else alph = (double)1 / (2 * T);
//
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//				match = 0;
//				int len = mean[i*width + j].size();
//				for (int k = 0; k < len; k++)
//				{
//					//�ж�һ�������Ƿ��뱳��ģ��ƥ��
//					if (fabs((uchar)img_gray->imageData[i*width + j] - mean[i*width + j][k]) < D*sd[i*width + j][k])
//					{
//						match = 1;
//						//����Ȩ�ء���ֵ����׼��
//						w[i*width + j][k] = (1 - alph)*w[i*width + j][k] + alph;
//						p = alph / w[i*width + j][k];
//						mean[i*width + j][k] = (1 - p)*mean[i*width + j][k] + p*(uchar)img_gray->imageData[i*width + j];
//						sd[i*width + j][k] = sqrt((1 - p)*sd[i*width + j][k] * sd[i*width + j][k] + p*pow((uchar)img_gray->imageData[i*width + j] - mean[i*width + j][k], 2));
//					}
//					else
//					{
//						w[i*width + j][k] = (1 - alph)*w[i*width + j][k];
//					}
//				}
//				if (match == 0)
//				{
//					//�����µı���ģ��
//					if (len < K)
//					{
//						mean[i*width + j].push_back((uchar)img_gray->imageData[i*width + j]);
//						sd[i*width + j].push_back(sd_init);
//						w[i*width + j].push_back(w_init);
//					}
//					//����Ȩ����С�ı���ģ��
//					else
//					{
//						int min = 0;
//						double tmp = w[i*width + j][0];
//						for (int k = 1; k < len; k++)
//						{
//							if (tmp >  w[i*width + j][k])
//							{
//								min = k;
//								tmp = w[i*width + j][k];
//							}
//						}
//						mean[i*width + j][min] = (uchar)img_gray->imageData[i*width + j];
//						sd[i*width + j][min] = sd_init;
//						w[i*width + j][min] = w_init;
//					}
//				}
//				//ÿ��50֡ ɾ��Ȩ����С�ĸ�˹�ֲ�	
//				if (cnt % 50 == 0)
//				{
//					vector<double>::iterator it_w, it_sd, it_mean;
//					it_w = w[i*width + j].begin();
//					it_sd = sd[i*width + j].begin();
//					it_mean = mean[i*width + j].begin();
//					for (; it_w != w[i*width + j].end() && it_sd != sd[i*width + j].end() && it_mean != mean[i*width + j].end();)
//					{
//						if (*it_w < w_init && (*it_w / *it_sd) < (w_init / sd_init))
//						{
//							it_w = w[i*width + j].erase(it_w);
//							it_sd = sd[i*width + j].erase(it_sd);
//							it_mean = mean[i*width + j].erase(it_mean);
//						}
//						else
//						{
//							it_w++;
//							it_sd++;
//							it_mean++;
//						}
//					}
//				}
//				//Ȩ�ع�һ��
//				len = mean[i*width + j].size();
//				double tmp = 0;
//				for (int k = 0; k < len; k++)
//				{
//					tmp += w[i*width + j][k];
//				}
//				for (int k = 0; k < len; k++)
//				{
//					w[i*width + j][k] /= tmp;
//				}
//				//���������ģ�͵����ȼ������ԴӴ�С��˳������
//				double *rand;//���ȼ�
//				int *rand_ind;//���������ȼ�����
//				rand = (double *)malloc(sizeof(double)*len);
//				rand_ind = (int *)malloc(sizeof(int)*len);
//				for (int k = 0; k < len; k++)
//				{
//					rand[k] = w[i*width + j][k] / sd[i*width + j][k];
//					rand_ind[k] = k;
//				}
//				for (int k = 1; k< len; k++)
//				{
//					for (int l = 0; l < k; l++)
//					{
//						if (rand[k] > rand[l])
//						{
//							double rand_tmp = rand[k];
//							rand[k] = rand[l];
//							rand[l] = rand_tmp;
//
//							double rand_ind_tmp = rand_ind[k];
//							rand_ind[k] = rand_ind[l];
//							rand_ind[l] = rand_ind_tmp;
//
//						}
//					}
//				}
//				double sum = 0;
//				int B;
//				for (int k = 0; k < len; k++)
//				{
//					int temp = rand_ind[k];
//					sum += w[i*width + j][temp];
//					if (sum>threold)
//					{
//						B = k;
//						break;
//					}
//				}
//				match = 0;
//				back->imageData[i*width + j] = 0;
//				//�󱳾�ģ��
//				for (int k = 0; k <= B; k++)
//				{
//					int temp = rand_ind[k];
//					back->imageData[i*width + j] += w[i*width + j][temp] * mean[i*width + j][temp];
//				}
//				/*
//				//��ǰ��ͼ��
//				for (int k = 0; k <= B; k++)
//				{
//				int temp = rand_ind[k];
//				if (fabs((uchar)img_gray->imageData[i*width + j] - mean[i*width + j][temp]) < D*sd[i*width + j][temp])
//				{
//				match = 1;
//				break;
//				}
//				}
//				if (match == 1) fore->imageData[i*width + j] = 0;
//				else fore->imageData[i*width + j] = (uchar)img_gray->imageData[i*width + j];
//				*/
//				free(rand);
//				free(rand_ind);
//			}
//		}
//
//		cvAbsDiff(img_gray, back, fore);
//		cvCanny(img_gray, img_cny, 1, 100);
//		cvShowImage("canny", img_cny);
//		cvAnd(img_cny, fore, fore);
//		cvShowImage("fore", fore);
//		cvShowImage("back", back);
//		cvShowImage("src", img);
//		char s = cvWaitKey(33);
//		if (s == 27) break;
//	}
//	cvDestroyAllWindows();
//	cvReleaseCapture(&capture);
//	cvReleaseImage(&img_gray);
//	cvReleaseImage(&fore);
//	cvReleaseImage(&back);
//	cvReleaseImage(&img_cny);
//	return 0;
//}