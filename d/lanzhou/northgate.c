//  Room:  /d/lanzhou/northgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
����������ݱ��š�����������ڼӹ̳�ǽ������Ե���Щ���ҡ�
��ǽ���¶�������ʯ���ϰ���������������������ȳ�ǽ�޽��ã�����
�ǲ��Ὺ�ŵ��ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"road4",
		"south" : __DIR__"road3",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 2,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9290);
	set("coor/y", 2720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}