// Room: /d/5lt/center.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��㳡");
	set  ("long",  @LONG
�����������ͷ��������ģ�һ���ܿ����Ĺ㳡����������������
ʯ·�����ڴˡ�һЩ���ֺ��е������������������������������
���ݡ�
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"nroad1",
		"south" :  __DIR__"sroad1",
		"west"  :  __DIR__"wroad1",
		"east"  :  __DIR__"eroad1",
	]));
        set("objects", ([
		__DIR__"npc/hehehehe": 1,
	]));
	set("outdoors",  "5lt");
	set("coor/x", -150);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
