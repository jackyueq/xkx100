//  Room:  /d/luoyang/zuoshe1.c
#include <ansi.h>;
inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�߽�С�ᣬ�����μ�齣���һ�������ƣ�һֻ��֦�����񴰣�����
���룬���ɷ����á��������ڽ���һ��ϸ������������һ����ɴ��
��ֻ����ԼԼ�ļ����и���Ӱ�������òȴһ��Ҳ�޷�������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"southeast"  :  __DIR__"lvzhuxiaoyuan",
		"west"       :  __DIR__"zuoshe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -381);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}