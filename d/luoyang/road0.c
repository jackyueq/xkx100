//  Room:  /d/luoyang/road0.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��֬��֮
�������ݣ����������Ǻųơ�����ݡ��Ļ��ι��ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"road11",
		"west" : __DIR__"hulaoguan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
