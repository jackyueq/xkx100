//  Room:  /d/lanzhou/zhigong.c

inherit  ROOM;

void  create  ()
{
	set("short",  "������");
	set("long",  @LONG
�����Ƿ�Բ������еĹ�Ժ��Ϊ��͢��ԺӦ��֮�������治ʱ����
ѧ��������ٴ�Ķ���������˵��Ժ���ڹ���Ԫ�꣬�����ϡ������á�
������ֻ����¸��ܶ��������������⡣
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"cuiying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -9300);
	set("coor/y", 2680);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}