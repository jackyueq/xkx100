//  Room:  /d/luoyang/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ԶԶ���Կ���
���ݵĳ�ԫ�ˣ���������ͨ����ԭ�Ĵ����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : "/d/city/ximen",
		"west" : __DIR__"road8",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -120);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
