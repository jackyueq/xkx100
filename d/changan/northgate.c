// /d/changan/northgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "��Զ��");
	set  ("long",  @LONG
������ǳ�������----��Զ�š�����Ϊ�೯�Ŷ�����Ȼ��ͬ���죬
��ǽ��ʯ�ҡ�Ŵ�׺������ɣ�����������һ���ٵ��Ա��������죬��
���Ǿ����ע���Ź������ˡ�
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"road6",
		"south"  :  __DIR__"northroad1",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
