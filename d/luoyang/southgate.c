//  Room:  /d/luoyang/southgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
�ɴ����������ų�ȥ���Ϳ���ͨ��������������ʤ�ż������ֺ���
��ʯ�ߣ�������һЩ�Ϳ��Ե�����������·Ӣ�ۺ����������ǡ�����
��ͨ�����������ĵ���Ҫ�ɵ��������ǳ��ǵ�С·��
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"luopu",
		"north" :  __DIR__"southroad",
		"south" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
