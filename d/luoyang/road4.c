//  Room:  /d/luoyang/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�Ͻ�С·");
	set("long",  @LONG
���������ǽ���һ��С·��������ȥ������ΰ�����ţ�����������
�ǣ�����������һ�羰�㣺���ֺ�����ʯ�ߡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"guanlin",
		"south" :  __DIR__"longmen1",
		"north" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/wudang/npc/tufei1" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
