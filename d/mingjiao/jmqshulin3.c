//JMQSHULIN3.C

inherit ROOM;

void create()
{
	set("short", "��ľ������");
	set("long", @LONG
����ǰ��Ȼһ���������У�ֻ������ǰ�󣬵�����������ǵصĲ�
֪���ľ����������ɰأ�������ɼ������һ����ʵ��֦Ҷ��һ�����
ɡ��������գ�������ա����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG );
	set("exits", ([
		"east" :  __DIR__"jmqshulin4",
		"west" :  __DIR__"jmqshulin3",
		"north" : __DIR__"jmqshulin3",
		"south" : __DIR__"jmqshulin3",
	]));
	set("objects", ([
		"/clone/medicine/nostrum/huochan" : random(2),
	]));
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}